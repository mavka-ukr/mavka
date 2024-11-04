#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitLogical(MavkaParser::LogicalContext* context) {
    const auto операція_асд_дані = new ОпераціяАСДДані();
    операція_асд_дані->ліво = AAV(visitContext(context->t_left));
    операція_асд_дані->право = AAV(visitContext(context->t_right));
    const auto op = context->t_operation->getText();
    if (op == "&&" || op == "і") {
      операція_асд_дані->операція = ОпераціяПеревіритиЧиОбоєТак;
    } else if (op == "||" || op == "або") {
      операція_асд_дані->операція = ОпераціяПеревіритиЧиЯкийсьТак;
    } else {
      throw std::runtime_error("Unknown operation: " + op);
    }
    return AV(this, context, АСДВидОперація, операція_асд_дані);
  }
} // namespace mavka::parser