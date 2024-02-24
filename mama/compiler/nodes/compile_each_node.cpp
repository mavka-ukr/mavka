#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_each_node(MaMa* M,
                                        MaCode* code,
                                        mavka::ast::ASTValue* ast_value) {
    const auto each_node = ast_value->data.EachNode;
    std::vector<EachNodeJumps> jumps;
    find_each_node_jumps(M, code, each_node->body, jumps);

    if (each_node->keyName.empty()) {
      const auto instruction_location = new MaInstructionLocation(
          ast_value->start_line, ast_value->start_column);
      M->iterator_count += 1;
      const auto iterator_name = std::to_string(M->iterator_count) + "_п";
      const auto result = compile_node(M, code, each_node->value);
      if (result.error) {
        return result;
      }
      code->instructions.push_back(
          MaInstruction::get(new MaGetInstructionArgs(MAG_ITERATOR)));
      code->instructions.push_back(MaInstruction::initargs(
          new MaInitArgsInstructionArgs(MA_ARGS_POSITIONED)));
      code->instructions.push_back(MaInstruction::call(instruction_location));
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
      code->instructions.push_back(MaInstruction::initargs(
          new MaInitArgsInstructionArgs(MA_ARGS_POSITIONED)));
      code->instructions.push_back(MaInstruction::call(instruction_location));

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

    return error(ast_value, "Перебір з ключем тимчасово недоступний.");
  }
} // namespace mavka::mama