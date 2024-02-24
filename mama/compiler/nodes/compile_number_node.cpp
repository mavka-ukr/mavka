#include "../../mama.h"

namespace mavka::mama {
  std::string process_number(std::string number) {
    // todo: remove this shit
    auto number_copy = std::string(number);
    if (number_copy.find("ш") != std::string::npos) {
      mavka::internal::tools::replace_all(number_copy, "ш", "x");
      mavka::internal::tools::replace_all(number_copy, "Ш", "X");
      mavka::internal::tools::replace_all(number_copy, "а", "а");
      mavka::internal::tools::replace_all(number_copy, "А", "A");
      mavka::internal::tools::replace_all(number_copy, "б", "b");
      mavka::internal::tools::replace_all(number_copy, "Б", "B");
      mavka::internal::tools::replace_all(number_copy, "в", "c");
      mavka::internal::tools::replace_all(number_copy, "В", "C");
      mavka::internal::tools::replace_all(number_copy, "г", "d");
      mavka::internal::tools::replace_all(number_copy, "Г", "D");
      mavka::internal::tools::replace_all(number_copy, "ґ", "e");
      mavka::internal::tools::replace_all(number_copy, "Ґ", "E");
      mavka::internal::tools::replace_all(number_copy, "д", "f");
      mavka::internal::tools::replace_all(number_copy, "Д", "F");
    } else {
      mavka::internal::tools::replace_all(number_copy, "д", "b");
    }
    return number_copy;
  }

  MaCompilationResult compile_number_node(
      MaMa* M,
      MaCode* code,
      mavka::ast::ASTValue* ast_value) {
    const auto number_node = ast_value->data.NumberNode;
    code->instructions.push_back(
        MaInstruction::number(std::stod(process_number(number_node->value))));
    return success();
  }
} // namespace mavka::mama