#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "mama/mama.h"

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
    M->stack.push(MA_MAKE_EMPTY());
    return;
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

MaObject* find_nearest_file_module(MaMa* M) {
  auto frames_copy = M->frames;
  while (!frames_copy.empty()) {
    auto frame = frames_copy.top();
    frames_copy.pop();
    if (frame->type == FRAME_TYPE_MODULE) {
      if (frame->data.module->module->d.module->is_file_module) {
        return frame->data.module->module;
      }
    }
  }
  return nullptr;
}

size_t try_run(MaMa* M, MaCode* code, size_t start_index = 0) {
  try {
    mavka::mama::run(M, code, start_index);
    return 0;
  } catch (const MaException& e) {
    std::vector<std::string> trace;
    while (M->frames.size() > 2) {
      POP_FRAME(trace_frame);
      if (trace_frame->type == FRAME_TYPE_CALL) {
        std::string path;
        if (trace_frame->data.call->type == FRAME_CALL_TYPE_DIIA) {
          const auto nearest_module = find_nearest_file_module(M);
          path = nearest_module->d.module->code->path;
        } else {
          path = "[невідомо]";
        }
        const auto line =
            trace_frame->data.call->location
                ? std::to_string(trace_frame->data.call->location->line)
                : "0";
        const auto column =
            trace_frame->data.call->location
                ? std::to_string(trace_frame->data.call->location->column)
                : "0";
        auto diia_name = trace_frame->data.call->o.diia->d.diia->name.empty()
                             ? "[дія]"
                             : trace_frame->data.call->o.diia->d.diia->name;
        if (trace_frame->data.call->o.diia->d.diia->me != nullptr) {
          diia_name = trace_frame->data.call->o.diia->d.diia->me->structure->d
                          .structure->name +
                      "." + diia_name;
        }
        trace.push_back(diia_name + " " + path + ":" + line + ":" + column);
      }
    }
    if (!trace.empty()) {
      std::cout << "Слід:" << std::endl;
      std::reverse(trace.begin(), trace.end());
      for (const auto& line : trace) {
        std::cout << "  " << line << std::endl;
      }
    }
    std::cout << cell_to_string(M->stack.top()) << std::endl;
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

  const auto frame = new MaFrame(FRAME_TYPE_ROOT);
  frame->scope = S;
  FRAME_PUSH(frame);
  init_print(M, S);

  if (args.size() == 1) {
    std::cout << "Експериментальна Мавка " << MAVKA_VERSION << std::endl;
    std::string line;
    const auto main_module_cell = create_module(M, "старт");
    const auto main_module_code = new MaCode();
    main_module_code->path = "[консоль]";
    main_module_cell.v.object->d.module->code = main_module_code;
    main_module_cell.v.object->d.module->is_file_module = true;
    M->main_module = main_module_cell.v.object;
    FRAME_PUSH(MaFrame::module(
        new MaScope(S), new MaFrameModuleData(main_module_cell.v.object)));
    do {
      std::cout << "› ";
      std::getline(std::cin, line);
      if (line == "вийти") {
        return 0;
      }
      const auto parser_result = mavka::parser::parse(line, "[консоль]");
      if (!parser_result.errors.empty()) {
        const auto error = parser_result.errors[0];
        std::cout << error.path + ":" + std::to_string(error.line) + ":" +
                         std::to_string(error.column) + ": " + error.message
                  << std::endl;
        continue;
      }
      const auto start_index = main_module_code->instructions.size();
      const auto body_compilation_result = compile_body(
          M, main_module_code, parser_result.program_node->body, true);
      if (body_compilation_result.error) {
        std::cout << "[консоль]:" +
                         std::to_string(body_compilation_result.error->line) +
                         ":" +
                         std::to_string(body_compilation_result.error->column) +
                         ": " + body_compilation_result.error->message
                  << std::endl;
        continue;
      }
      const auto restore_stack_size = M->stack.size();
      if (!try_run(M, main_module_code, start_index)) {
        if (!M->stack.empty()) {
          const auto result = TOP();
          mavka::mama::restore_stack(M, restore_stack_size);
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

    return try_run(
        M, new MaCode(
               {.instructions = {MaInstruction{
                    OP_TAKE,
                    {.take = new MaTakeInstructionArgs(INT64_MAX, path)}}}}));
  } else {
    print_help();
    return 1;
  }

  return 0;
}