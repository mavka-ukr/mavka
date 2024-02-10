#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_each_node(MaMa* M,
                                        mavka::ast::EachNode* each_node) {
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
          step_op_i = MaInstruction{OP_SUB};
        } else if (toSymbol == ">") {
          check_i = MaInstruction{OP_LE};
          step_op_i = MaInstruction{OP_SUB};
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
            compile_node(M, each_node->value->FromToSimpleNode->from);
        if (from_result.error) {
          return from_result;
        }
      } else if (each_node->value->FromToComplexNode) {
        const auto from_result =
            compile_node(M, each_node->value->FromToComplexNode->from);
        if (from_result.error) {
          return from_result;
        }
      }
      M->code.push_back(MaInstruction{
          OP_STORE, {.store = new MaStoreInstructionArgs(each_node->name)}});

      const auto start_index = M->code.size();

      M->code.push_back(MaInstruction{
          OP_LOAD, {.load = new MaLoadInstructionArgs(each_node->name)}});
      if (each_node->value->FromToSimpleNode) {
        const auto to_result =
            compile_node(M, each_node->value->FromToSimpleNode->to);
        if (to_result.error) {
          return to_result;
        }
      } else if (each_node->value->FromToComplexNode) {
        const auto to_result =
            compile_node(M, each_node->value->FromToComplexNode->to);
        if (to_result.error) {
          return to_result;
        }
      }
      M->code.push_back(check_i);
      M->code.push_back(MaInstruction{OP_JUMP_IF_TRUE});
      const auto jump_out_instruction_index = M->code.size() - 1;

      const auto result = compile_body(M, each_node->body);
      if (result.error) {
        return result;
      }

      M->code.push_back(MaInstruction{
          OP_LOAD, {.load = new MaLoadInstructionArgs(each_node->name)}});
      if (each_node->value->FromToSimpleNode) {
        M->code.push_back(MaInstruction{OP_NUMBER, {.number = 1}});
      } else if (each_node->value->FromToComplexNode) {
        const auto step_result =
            compile_node(M, each_node->value->FromToComplexNode->step);
        if (step_result.error) {
          return step_result;
        }
      }
      M->code.push_back(step_op_i);
      M->code.push_back(MaInstruction{
          OP_STORE, {.store = new MaStoreInstructionArgs(each_node->name)}});

      M->code.push_back(MaInstruction{OP_JUMP, {.jump = start_index}});

      M->code[jump_out_instruction_index].args.jumpiftrue = M->code.size();

      M->code.push_back(
          MaInstruction{OP_LOAD, {.load = new MaLoadInstructionArgs("пусто")}});
      M->code.push_back(MaInstruction{
          OP_STORE, {.store = new MaStoreInstructionArgs(each_node->name)}});

      return success();
    } else {
      if (each_node->keyName.empty()) {
        M->iterator_count += 1;
        const auto iterator_name = std::to_string(M->iterator_count) + "_п";
        const auto result = compile_node(M, each_node->value);
        if (result.error) {
          return result;
        }
        M->code.push_back(MaInstruction{
            OP_GET, {.get = new MaGetInstructionArgs(MAG_ITERATOR)}});
        M->code.push_back(MaInstruction{
            OP_INITCALL, {.initcall = new MaInitCallInstructionArgs()}});
        const auto initcall_instruction_index = M->code.size() - 1;
        M->code[initcall_instruction_index].args.initcall->index =
            M->code.size() + 1;
        M->code.push_back(MaInstruction{OP_CALL});
        M->code.push_back(MaInstruction{
            OP_STORE, {.store = new MaStoreInstructionArgs(iterator_name)}});

        const auto start_index = M->code.size();

        M->code.push_back(MaInstruction{
            OP_LOAD, {.load = new MaLoadInstructionArgs(iterator_name)}});
        M->code.push_back(MaInstruction{
            OP_GET, {.get = new MaGetInstructionArgs("завершено")}});
        M->code.push_back(MaInstruction{OP_JUMP_IF_TRUE});
        const auto jump_out_instruction_index = M->code.size() - 1;

        M->code.push_back(MaInstruction{
            OP_LOAD, {.load = new MaLoadInstructionArgs(iterator_name)}});
        M->code.push_back(MaInstruction{
            OP_GET, {.get = new MaGetInstructionArgs("значення")}});
        M->code.push_back(MaInstruction{
            OP_STORE, {.store = new MaStoreInstructionArgs(each_node->name)}});

        const auto body_result = compile_body(M, each_node->body);
        if (body_result.error) {
          return body_result;
        }

        M->code.push_back(MaInstruction{
            OP_LOAD, {.load = new MaLoadInstructionArgs(iterator_name)}});
        M->code.push_back(
            MaInstruction{OP_GET, {.get = new MaGetInstructionArgs("далі")}});
        M->code.push_back(MaInstruction{
            OP_INITCALL,
            {.initcall = new MaInitCallInstructionArgs(M->code.size() + 2)}});
        M->code.push_back(MaInstruction{OP_CALL});

        M->code.push_back(MaInstruction{OP_JUMP, {.jump = start_index}});

        M->code[jump_out_instruction_index].args.jumpiftrue = M->code.size();

        M->code.push_back(MaInstruction{
            OP_LOAD, {.load = new MaLoadInstructionArgs("пусто")}});
        M->code.push_back(MaInstruction{
            OP_STORE, {.store = new MaStoreInstructionArgs(each_node->name)}});
        M->code.push_back(MaInstruction{
            OP_LOAD, {.load = new MaLoadInstructionArgs("пусто")}});
        M->code.push_back(MaInstruction{
            OP_STORE, {.store = new MaStoreInstructionArgs(iterator_name)}});

        return success();
      }
    }

    return error(mavka::ast::make_ast_some(each_node), "Not implemented");
  }
} // namespace mavka::mama