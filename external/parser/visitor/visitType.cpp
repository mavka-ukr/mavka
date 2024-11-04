#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitType(MavkaParser::TypeContext* context) {
    const auto тип_асд_дані = new ТипАСДДані();
    if (context->t_nullable) {
      тип_асд_дані->може_бути_пусто = 1;
    } else {
      тип_асд_дані->може_бути_пусто = 0;
    }
    if (context->subject_out()) {
      тип_асд_дані->значення = AAV(visitContext(context->subject_out()));
    } else if (context->get_out()) {
      тип_асд_дані->значення = AAV(visitContext(context->get_out()));
    } else if (context->generic_out()) {
      тип_асд_дані->значення = AAV(visitContext(context->generic_out()));
    } else {
      throw std::runtime_error("Unknown type context");
    }
    return AV(this, context, АСДВидТип, тип_асд_дані);
  }
} // namespace mavka::parser