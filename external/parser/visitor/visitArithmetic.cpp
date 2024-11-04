#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitMul(MavkaParser::MulContext* context) {
    const auto операція_асд_дані = new ОпераціяАСДДані();
    операція_асд_дані->ліво = AAV(visitContext(context->a_left));
    операція_асд_дані->право = AAV(visitContext(context->a_right));
    const auto op = context->a_operation->getText();
    if (op == "*") {
      операція_асд_дані->операція = ОпераціяПомножити;
    } else if (op == "/") {
      операція_асд_дані->операція = ОпераціяПоділити;
    } else if (op == "%") {
      операція_асд_дані->операція = ОпераціяПоділитиЗаМодулем;
    } else if (op == "//") {
      операція_асд_дані->операція = ОпераціяПоділитиНаціло;
    } else if (op == "**") {
      операція_асд_дані->операція = ОпераціяПіднестиДоСтепеня;
    } else {
      throw std::runtime_error("Unknown operation: " + op);
    }
    return AV(this, context, АСДВидОперація, операція_асд_дані);
  }

  std::any MavkaASTVisitor::visitAdd(MavkaParser::AddContext* context) {
    const auto операція_асд_дані = new ОпераціяАСДДані();
    операція_асд_дані->ліво = AAV(visitContext(context->a_left));
    операція_асд_дані->право = AAV(visitContext(context->a_right));
    const auto op = context->a_operation->getText();
    if (op == "+") {
      операція_асд_дані->операція = ОпераціяДодати;
    } else if (op == "-") {
      операція_асд_дані->операція = ОпераціяВідняти;
    } else {
      throw std::runtime_error("Unknown operation: " + op);
    }
    return AV(this, context, АСДВидОперація, операція_асд_дані);
  }
} // namespace mavka::parser