#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "mama/src/mama.h"

using namespace mavka::mama;

void init_print(MaMa* M, MaScope* S) {
  const auto diia_native_fn = [](MaMa* M, MaObject* me, MaArgs* args) {
    if (args->type == MA_ARGS_POSITIONED) {
      for (const auto& arg : args->positioned) {
        std::cout << cell_to_string(arg) << std::endl;
      }
    } else {
      for (const auto& [key, value] : args->named) {
        std::cout << key << ": " << cell_to_string(value) << std::endl;
      }
    }
    RETURN_EMPTY();
  };
  const auto diia_cell = create_diia_native(M, "друк", diia_native_fn, nullptr);
  S->set_variable("друк", diia_cell);
}

void print_help() {
  std::cout << R"(Використання:
  мавка [...опції] <модуль.м> [...аргументи]
  мавка [...опції] <команда> [...аргументи]

Доступні команди:
  <модуль.м> — виконати модуль
    Опції: немає

  версія — показати версію Мавки
    Опції: немає

  допомога — показати це повідолення
    Опції: немає)"
            << std::endl;
}

void print_version() {
  std::cout << MAVKA_VERSION << std::endl;
}

size_t try_run(MaMa* M, std::function<void()> fn) {
  try {
    fn();
    return 0;
  } catch (const MaException& e) {
    std::vector<std::string> trace;
    while (M->frame_stack.size() > 2) {
      POP_FRAME(trace_frame);
      std::string path;
      std::string line;
      std::string column;
      std::string name;
      if (trace_frame->object->type == MA_OBJECT_DIIA) {
        path = trace_frame->object->d.diia->module->d.module->code->path;
        line = std::to_string(trace_frame->location.line);
        column = std::to_string(trace_frame->location.column);
        name = trace_frame->object->d.diia->name.empty()
                   ? "[дія]"
                   : trace_frame->object->d.diia->name;
        if (trace_frame->object->d.diia->me != nullptr) {
          name = trace_frame->object->d.diia->me->structure->d.structure->name +
                 "." + name;
        }
      } else if (trace_frame->object->type == MA_OBJECT_DIIA_NATIVE) {
        path = "[невідомо]";
        line = std::to_string(trace_frame->location.line);
        column = std::to_string(trace_frame->location.column);
        name = "[дія]";
        if (trace_frame->object->d.diia_native->me != nullptr) {
          name = trace_frame->object->d.diia_native->me->structure->d.structure
                     ->name +
                 "." + name;
        }
      } else if (trace_frame->object->type == MA_OBJECT_STRUCTURE) {
        path = "[невідомо]";
        line = std::to_string(trace_frame->location.line);
        column = std::to_string(trace_frame->location.column);
        name = "[дія]";
        if (trace_frame->object->d.diia_native->me != nullptr) {
          name = trace_frame->object->d.diia_native->me->structure->d.structure
                     ->name +
                 "." + name;
        }
      } else {
        path = "[невідомо]";
      }
      trace.push_back(name + " " + path + ":" + line + ":" + column);
    }
    if (!trace.empty()) {
      std::cout << "Слід:" << std::endl;
      std::reverse(trace.begin(), trace.end());
      for (const auto& line : trace) {
        std::cout << "  " << line << std::endl;
      }
    }
    std::cout << cell_to_string(M->throw_cell) << std::endl;
    return 1;
  }
}

int main(int argc, char** argv) {
  const auto args = std::vector<std::string>(argv, argv + argc);
  const auto cwd = std::filesystem::current_path();

  const auto M = new MaMa();
  M->cwd = cwd;
  const auto S = new MaScope(nullptr);
  M->global_scope = S;

  init_structure(M);
  init_object(M);
  init_diia(M);
  init_module(M);
  init_number(M);
  init_logical(M);
  init_text(M);
  init_list(M);
  init_dict(M);
  init_structure_2(M);

  const auto main_frame = new MaFrame();
  main_frame->scope = S;
  FRAME_PUSH(main_frame);
  init_print(M, S);

  if (args.size() == 1) {
    std::cout << "Експериментальна Мавка " << MAVKA_VERSION << std::endl;
    const auto main_module_cell = create_module(M, "старт");
    const auto main_module_code = new MaCode();
    main_module_code->path = "[консоль]";
    main_module_cell.v.object->d.module->code = main_module_code;
    main_module_cell.v.object->d.module->is_file_module = true;
    M->main_module = main_module_cell.v.object;
    const auto frame = new MaFrame(new MaScope(S), main_module_cell.v.object,
                                   main_module_cell.v.object);
    FRAME_PUSH(frame);
    std::string line;
    do {
      if (line.empty()) {
        std::cout << "› ";
      } else {
        std::cout << "  ";
      }
      std::string currline;
      std::getline(std::cin, currline);
      if (currline == "вийти") {
        return 0;
      }
      if (currline.empty()) {
        continue;
      }
      if (currline[currline.size() - 1] == '\\') {
        line += ("\n" + currline.substr(0, currline.size() - 1));
        continue;
      } else {
        if (line.empty()) {
          line = currline;
        } else {
          line += ("\n" + currline);
        }
      }
      const auto parser_result = mavka::parser::parse(line, "[консоль]");
      line = "";
      if (!parser_result.errors.empty()) {
        const auto error = parser_result.errors[0];
        std::cout << error.path + ":" + std::to_string(error.line) + ":" +
                         std::to_string(error.column) + ": " + error.message
                  << std::endl;
        continue;
      }
      const auto code = new MaCode();
      const auto body_compilation_result =
          compile_body(M, code, parser_result.module_node->body);
      if (body_compilation_result.error) {
        std::cout << "[консоль]:" +
                         std::to_string(body_compilation_result.error->line) +
                         ":" +
                         std::to_string(body_compilation_result.error->column) +
                         ": " + body_compilation_result.error->message
                  << std::endl;
        continue;
      }
      if (!try_run(M, [&M, &code]() { mavka::mama::run(M, code); })) {
        if (!frame->stack.empty()) {
          const auto result = TOP();
          POP();
          std::cout << cell_to_string(result) << std::endl;
        }
      }
    } while (true);
    return 1;
  } else if (args.size() == 2) {
    const auto& command = args[1];
    if (command == "допомога") {
      print_help();
      return 0;
    }
    if (command == "версія") {
      print_version();
      return 0;
    }

    const auto& path = args[1];

    try_run(M, [&path, &M]() { ma_take(M, path); });
  } else {
    print_help();
    return 1;
  }

  return 0;
}