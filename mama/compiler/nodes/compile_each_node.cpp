#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_each_node(MaMa* M,
                                        MaCode* code,
                                        mavka::ast::EachNode* each_node) {
    std::vector<EachNodeJumps> jumps;
    find_each_node_jumps(M, each_node->body, jumps);

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
          check_i = MaInstruction{OP_GT};
          step_op_i = MaInstruction{OP_ADD};
        } else if (toSymbol == "<") {
          check_i = MaInstruction{OP_GE};
          step_op_i = MaInstruction{OP_ADD};
        } else if (toSymbol == ">=") {
          check_i = MaInstruction{OP_LT};
          step_op_i = MaInstruction{OP_ADD};
        } else if (toSymbol == ">") {
          check_i = MaInstruction{OP_LE};
          step_op_i = MaInstruction{OP_ADD};
        } else {
          return error(mavka::ast::make_ast_some(each_node),
                       "Невідомий символ: " + toSymbol);
        }
      } else if (each_node->value->FromToComplexNode) {
        const auto toSymbol = each_node->value->FromToComplexNode->toSymbol;
        if (toSymbol == "<=") {
          check_i = MaInstruction{OP_GT};
        } else if (toSymbol == "<") {
          check_i = MaInstruction{OP_GE};
        } else if (toSymbol == ">=") {
          check_i = MaInstruction{OP_LT};
        } else if (toSymbol == ">") {
          check_i = MaInstruction{OP_LE};
        } else {
          return error(mavka::ast::make_ast_some(each_node),
                       "Невідомий символ: " + toSymbol);
        }
        const auto stepSymbol = each_node->value->FromToComplexNode->stepSymbol;
        if (stepSymbol == "+") {
          step_op_i = MaInstruction{OP_ADD};
        } else if (stepSymbol == "-") {
          step_op_i = MaInstruction{OP_SUB};
        } else if (stepSymbol == "*") {
          step_op_i = MaInstruction{OP_MUL};
        } else if (stepSymbol == "/") {
          step_op_i = MaInstruction{OP_DIV};
        } else if (stepSymbol == "%") {
          step_op_i = MaInstruction{OP_MOD};
        } else if (stepSymbol == "//") {
          step_op_i = MaInstruction{OP_DIVDIV};
        } else if (stepSymbol == "**") {
          step_op_i = MaInstruction{OP_POW};
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
      code->instructions.push_back(MaInstruction{
          OP_STORE, {.store = new MaStoreInstructionArgs(each_node->name)}});

      const auto start_index = code->instructions.size();

      code->instructions.push_back(MaInstruction{
          OP_LOAD, {.load = new MaLoadInstructionArgs(each_node->name)}});
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
      code->instructions.push_back(MaInstruction{OP_JUMP_IF_TRUE});
      const auto jump_out_instruction_index = code->instructions.size() - 1;

      const auto result = compile_body(M, code, each_node->body);
      if (result.error) {
        return result;
      }

      const auto continue_index = code->instructions.size();

      code->instructions.push_back(MaInstruction{
          OP_LOAD, {.load = new MaLoadInstructionArgs(each_node->name)}});
      if (each_node->value->FromToSimpleNode) {
        code->instructions.push_back(MaInstruction{OP_NUMBER, {.number = 1}});
      } else if (each_node->value->FromToComplexNode) {
        const auto step_result =
            compile_node(M, code, each_node->value->FromToComplexNode->step);
        if (step_result.error) {
          return step_result;
        }
      }
      code->instructions.push_back(step_op_i);
      code->instructions.push_back(MaInstruction{
          OP_STORE, {.store = new MaStoreInstructionArgs(each_node->name)}});

      code->instructions.push_back(
          MaInstruction{OP_JUMP, {.jump = start_index}});

      const auto break_index = code->instructions.size();
      code->instructions[jump_out_instruction_index].args.jumpiftrue =
          break_index;

      code->instructions.push_back(MaInstruction{OP_EMPTY});
      code->instructions.push_back(MaInstruction{
          OP_STORE, {.store = new MaStoreInstructionArgs(each_node->name)}});

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
        code->instructions.push_back(MaInstruction{
            OP_GET, {.get = new MaGetInstructionArgs(MAG_ITERATOR)}});
        code->instructions.push_back(MaInstruction{
            OP_INITCALL, {.initcall = new MaInitCallInstructionArgs()}});
        const auto initcall_instruction_index = code->instructions.size() - 1;
        code->instructions[initcall_instruction_index].args.initcall->index =
            code->instructions.size() + 1;
        code->instructions.push_back(MaInstruction{OP_CALL});
        code->instructions.push_back(MaInstruction{
            OP_STORE, {.store = new MaStoreInstructionArgs(iterator_name)}});

        const auto start_index = code->instructions.size();

        code->instructions.push_back(MaInstruction{
            OP_LOAD, {.load = new MaLoadInstructionArgs(iterator_name)}});
        code->instructions.push_back(MaInstruction{
            OP_GET, {.get = new MaGetInstructionArgs("завершено")}});
        code->instructions.push_back(MaInstruction{OP_JUMP_IF_TRUE});
        const auto jump_out_instruction_index = code->instructions.size() - 1;

        code->instructions.push_back(MaInstruction{
            OP_LOAD, {.load = new MaLoadInstructionArgs(iterator_name)}});
        code->instructions.push_back(MaInstruction{
            OP_GET, {.get = new MaGetInstructionArgs("значення")}});
        code->instructions.push_back(MaInstruction{
            OP_STORE, {.store = new MaStoreInstructionArgs(each_node->name)}});

        const auto body_result = compile_body(M, code, each_node->body);
        if (body_result.error) {
          return body_result;
        }

        const auto continue_index = code->instructions.size();

        code->instructions.push_back(MaInstruction{
            OP_LOAD, {.load = new MaLoadInstructionArgs(iterator_name)}});
        code->instructions.push_back(
            MaInstruction{OP_GET, {.get = new MaGetInstructionArgs("далі")}});
        code->instructions.push_back(
            MaInstruction{OP_INITCALL,
                          {.initcall = new MaInitCallInstructionArgs(
                               code->instructions.size() + 2)}});
        code->instructions.push_back(MaInstruction{OP_CALL});

        code->instructions.push_back(
            MaInstruction{OP_JUMP, {.jump = start_index}});

        const auto break_index = code->instructions.size();
        code->instructions[jump_out_instruction_index].args.jumpiftrue =
            break_index;

        code->instructions.push_back(MaInstruction{OP_EMPTY});
        code->instructions.push_back(MaInstruction{
            OP_STORE, {.store = new MaStoreInstructionArgs(each_node->name)}});
        code->instructions.push_back(MaInstruction{OP_EMPTY});
        code->instructions.push_back(MaInstruction{
            OP_STORE, {.store = new MaStoreInstructionArgs(iterator_name)}});

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

    return error(mavka::ast::make_ast_some(each_node), "Перебір з ключем тимчасово недоступний.");
  }
} // namespace mavka::mama