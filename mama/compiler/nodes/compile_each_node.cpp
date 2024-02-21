#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_each_node(MaMa* M,
                                        MaCode* code,
                                        mavka::ast::EachNode* each_node) {
    std::vector<EachNodeJumps> jumps;
    find_each_node_jumps(M, code, each_node->body, jumps);

    if (each_node->value->FromToSimpleNode ||
        each_node->value->FromToComplexNode) {
      if (!each_node->keyName.empty()) {
        return error(mavka::ast::make_ast_some(each_node),
                     "Перебір з ключем недоступний для діапазону.");
      }

      MaInstruction check_i{};
      MaInstruction step_op_i{};

      if (each_node->value->FromToSimpleNode) {
        const auto toSymbol = each_node->value->FromToSimpleNode->toSymbol;
        if (toSymbol == "<=") {
          check_i = MaInstruction::gt();
          step_op_i = MaInstruction::add();
        } else if (toSymbol == "<") {
          check_i = MaInstruction::ge();
          step_op_i = MaInstruction::add();
        } else if (toSymbol == ">=") {
          check_i = MaInstruction::lt();
          step_op_i = MaInstruction::add();
        } else if (toSymbol == ">") {
          check_i = MaInstruction::le();
          step_op_i = MaInstruction::add();
        } else {
          return error(mavka::ast::make_ast_some(each_node),
                       "Невідомий символ: " + toSymbol);
        }
      } else if (each_node->value->FromToComplexNode) {
        const auto toSymbol = each_node->value->FromToComplexNode->toSymbol;
        if (toSymbol == "<=") {
          check_i = MaInstruction::gt();
        } else if (toSymbol == "<") {
          check_i = MaInstruction::ge();
        } else if (toSymbol == ">=") {
          check_i = MaInstruction::lt();
        } else if (toSymbol == ">") {
          check_i = MaInstruction::le();
        } else {
          return error(mavka::ast::make_ast_some(each_node),
                       "Невідомий символ: " + toSymbol);
        }
        const auto stepSymbol = each_node->value->FromToComplexNode->stepSymbol;
        if (stepSymbol == "+") {
          step_op_i = MaInstruction::add();
        } else if (stepSymbol == "-") {
          step_op_i = MaInstruction::sub();
        } else if (stepSymbol == "*") {
          step_op_i = MaInstruction::mul();
        } else if (stepSymbol == "/") {
          step_op_i = MaInstruction::div();
        } else if (stepSymbol == "%") {
          step_op_i = MaInstruction::mod();
        } else if (stepSymbol == "//") {
          step_op_i = MaInstruction::divdiv();
        } else if (stepSymbol == "**") {
          step_op_i = MaInstruction::pow();
        } else {
          return error(mavka::ast::make_ast_some(each_node),
                       "Невідомий символ: " + stepSymbol);
        }
      }

      if (each_node->value->FromToSimpleNode) {
        const auto from_result =
            compile_node(M, code, each_node->value->FromToSimpleNode->from);
        if (from_result.error) {
          return from_result;
        }
      } else if (each_node->value->FromToComplexNode) {
        const auto from_result =
            compile_node(M, code, each_node->value->FromToComplexNode->from);
        if (from_result.error) {
          return from_result;
        }
      }
      code->instructions.push_back(
          MaInstruction::store(new MaStoreInstructionArgs(each_node->name)));

      const auto start_index = code->instructions.size();

      code->instructions.push_back(
          MaInstruction::load(new MaLoadInstructionArgs(each_node->name)));
      if (each_node->value->FromToSimpleNode) {
        const auto to_result =
            compile_node(M, code, each_node->value->FromToSimpleNode->to);
        if (to_result.error) {
          return to_result;
        }
      } else if (each_node->value->FromToComplexNode) {
        const auto to_result =
            compile_node(M, code, each_node->value->FromToComplexNode->to);
        if (to_result.error) {
          return to_result;
        }
      }
      code->instructions.push_back(check_i);
      code->instructions.push_back(MaInstruction::jumpiftrue(0));
      const auto jump_out_instruction_index = code->instructions.size() - 1;

      const auto result = compile_body(M, code, each_node->body);
      if (result.error) {
        return result;
      }

      const auto continue_index = code->instructions.size();

      code->instructions.push_back(
          MaInstruction::load(new MaLoadInstructionArgs(each_node->name)));
      if (each_node->value->FromToSimpleNode) {
        code->instructions.push_back(MaInstruction::number(1));
      } else if (each_node->value->FromToComplexNode) {
        const auto step_result =
            compile_node(M, code, each_node->value->FromToComplexNode->step);
        if (step_result.error) {
          return step_result;
        }
      }
      code->instructions.push_back(step_op_i);
      code->instructions.push_back(
          MaInstruction::store(new MaStoreInstructionArgs(each_node->name)));

      code->instructions.push_back(MaInstruction::jump(start_index));

      const auto break_index = code->instructions.size();
      code->instructions[jump_out_instruction_index].args.jumpiftrue =
          break_index;

      code->instructions.push_back(MaInstruction::empty());
      code->instructions.push_back(
          MaInstruction::store(new MaStoreInstructionArgs(each_node->name)));

      for (const auto& jump : jumps) {
        if (jump.continue_node) {
          code->instructions[jump.continue_node->code_index].args.jump =
              continue_index;
        } else if (jump.break_node) {
          code->instructions[jump.break_node->code_index].args.jump =
              break_index;
        }
      }

      return success();
    } else {
      if (each_node->keyName.empty()) {
        M->iterator_count += 1;
        const auto iterator_name = std::to_string(M->iterator_count) + "_п";
        const auto result = compile_node(M, code, each_node->value);
        if (result.error) {
          return result;
        }
        code->instructions.push_back(
            MaInstruction::get(new MaGetInstructionArgs(MAG_ITERATOR)));
        code->instructions.push_back(MaInstruction::initcall(
            new MaInitCallInstructionArgs(MA_ARGS_POSITIONED)));
        code->instructions.push_back(MaInstruction::call());
        code->instructions.push_back(
            MaInstruction::store(new MaStoreInstructionArgs(iterator_name)));

        const auto start_index = code->instructions.size();

        code->instructions.push_back(
            MaInstruction::load(new MaLoadInstructionArgs(iterator_name)));
        code->instructions.push_back(
            MaInstruction::get(new MaGetInstructionArgs("завершено")));
        code->instructions.push_back(MaInstruction::jumpiftrue(0));
        const auto jump_out_instruction_index = code->instructions.size() - 1;

        code->instructions.push_back(
            MaInstruction::load(new MaLoadInstructionArgs(iterator_name)));
        code->instructions.push_back(
            MaInstruction::get(new MaGetInstructionArgs("значення")));
        code->instructions.push_back(
            MaInstruction::store(new MaStoreInstructionArgs(each_node->name)));

        const auto body_result = compile_body(M, code, each_node->body);
        if (body_result.error) {
          return body_result;
        }

        const auto continue_index = code->instructions.size();

        code->instructions.push_back(
            MaInstruction::load(new MaLoadInstructionArgs(iterator_name)));
        code->instructions.push_back(
            MaInstruction::get(new MaGetInstructionArgs("далі")));
        code->instructions.push_back(MaInstruction::initcall(
            new MaInitCallInstructionArgs(MA_ARGS_POSITIONED)));
        code->instructions.push_back(MaInstruction::call());

        code->instructions.push_back(MaInstruction::jump(start_index));

        const auto break_index = code->instructions.size();
        code->instructions[jump_out_instruction_index].args.jumpiftrue =
            break_index;

        code->instructions.push_back(MaInstruction::empty());
        code->instructions.push_back(
            MaInstruction::store(new MaStoreInstructionArgs(each_node->name)));
        code->instructions.push_back(MaInstruction::empty());
        code->instructions.push_back(
            MaInstruction::store(new MaStoreInstructionArgs(iterator_name)));

        for (const auto& jump : jumps) {
          if (jump.continue_node) {
            code->instructions[jump.continue_node->code_index].args.jump =
                continue_index;
          } else if (jump.break_node) {
            code->instructions[jump.break_node->code_index].args.jump =
                break_index;
          }
        }

        return success();
      }
    }

    return error(mavka::ast::make_ast_some(each_node),
                 "Перебір з ключем тимчасово недоступний.");
  }
} // namespace mavka::mama