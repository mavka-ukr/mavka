#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitBitwise_not(
      MavkaParser::Bitwise_notContext* context) {
    const auto само_операція_асд_дані = new СамоОпераціяАСДДані();
    само_операція_асд_дані->операція = СамоОпераціяДвійковеНі;
    само_операція_асд_дані->значення = AAV(visitContext(context->bn_value));
    return AV(this, context, АСДВидСамоОперація, само_операція_асд_дані);
  }
} // namespace mavka::parser