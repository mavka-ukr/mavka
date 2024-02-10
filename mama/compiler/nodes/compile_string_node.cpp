#include "../../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_string_node(
      MaMa* M,
      const mavka::ast::StringNode* string_node) {
    const auto ma_object = new MaObject();
    ma_object->type = MA_OBJECT_STRING;
    const auto ma_string = new MaString();
    ma_string->data = string_node->value;
    ma_object->d.string = ma_string;
    M->constants.push_back(MaCell{MA_CELL_OBJECT, {.object = ma_object}});
    M->code.push_back(
        MaInstruction{OP_CONSTANT, {.constant = M->constants.size() - 1}});
    return success();
  }
} // namespace mavka::mama