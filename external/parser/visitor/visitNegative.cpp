#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitNegative(
      MavkaParser::NegativeContext* context) {
    const auto само_операція_асд_дані = new СамоОпераціяАСДДані();
    само_операція_асд_дані->операція = СамоОпераціяЗробитиВідʼємним;
    само_операція_асд_дані->значення = AAV(visitContext(context->n_value));
    return AV(this, context, АСДВидСамоОперація, само_операція_асд_дані);
  }
} // namespace mavka::parser