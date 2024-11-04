#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitNot(MavkaParser::NotContext* context) {
    const auto само_операція_асд_дані = new СамоОпераціяАСДДані();
    само_операція_асд_дані->операція = СамоОпераціяЗаперечити;
    само_операція_асд_дані->значення = AAV(visitContext(context->n_value));
    return AV(this, context, АСДВидСамоОперація, само_операція_асд_дані);
  }
} // namespace mavka::parser