#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitIdentifier(
      MavkaParser::IdentifierContext* context) {
    const auto identifier_node = new ІдентифікаторАСДДані();
    identifier_node->назва = strdup(context->getText().c_str());
    return AV(this, context, АСДВидІдентифікатор, identifier_node);
  }
} // namespace mavka::parser