#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_try_node(MaMa* M,
                                       MaCode* code,
                                       mavka::ast::ASTValue* ast_value) {
    const auto try_node = ast_value->data.TryNode;
    const auto try_code = new MaCode();
    try_code->path = code->path;
    const auto result = compile_body(M, try_code, try_node->body);
    if (result.error) {
      return result;
    }
    const auto catch_code = new MaCode();
    catch_code->path = code->path;
    catch_code->instructions.push_back(
        MaInstruction::store(new MaStoreInstructionArgs(try_node->name)));
    const auto catch_result = compile_body(M, catch_code, try_node->catch_body);
    if (catch_result.error) {
      return catch_result;
    }
    code->instructions.push_back(
        MaInstruction::try_(new MaTryInstructionArgs(try_code, catch_code)));
    return success();
  }
} // namespace mavka::mama