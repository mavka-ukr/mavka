#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitArray(MavkaParser::ArrayContext* context) {
    const auto створити_список_асд_дані = new СтворитиСписокАСДДані();
    std::vector<АСДЗначення*> elements;
    if (context->array_elements()) {
      for (auto element : context->array_elements()->expr()) {
        elements.push_back(AAV(visitContext(element)));
      }
    }
    створити_список_асд_дані->елементи = AAVecToList(elements);
    return AV(this, context, АСДВидСтворитиСписок, створити_список_асд_дані);
  }
} // namespace mavka::parser