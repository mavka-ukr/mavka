#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitFile(MavkaParser::FileContext* ctx) {
    return visitBody(ctx->body());
  }
} // namespace mavka::parser