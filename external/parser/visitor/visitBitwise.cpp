#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitBitwise(MavkaParser::BitwiseContext* context) {
    const auto операція_асд_дані = new ОпераціяАСДДані();
    операція_асд_дані->ліво = AAV(visitContext(context->b_left));
    операція_асд_дані->право = AAV(visitContext(context->b_right));
    const auto op = context->b_operation->getText();
    if (op == "&") {
      операція_асд_дані->операція = ОпераціяДвійковеІ;
    } else if (op == "|") {
      операція_асд_дані->операція = ОпераціяДвійковеАбо;
    } else if (op == "^") {
      операція_асд_дані->операція = ОпераціяДвійковеВиключнеАбо;
    } else if (op == "<<") {
      операція_асд_дані->операція = ОпераціяДвійковийЗсувВліво;
    } else if (op == ">>") {
      операція_асд_дані->операція = ОпераціяДвійковийЗсувВправо;
    } else if (op == ">>>") {
      операція_асд_дані->операція = ОпераціяДвійковийЗсувВправоЗЗаповненням;
    } else {
      throw std::runtime_error("Unknown operation: " + op);
    }
    return AV(this, context, АСДВидОперація, операція_асд_дані);
  }
} // namespace mavka::parser