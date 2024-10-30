#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitAs(MavkaParser::AsContext* context) {
    const auto як_асд_дані = new ЯкАСДДані();
    як_асд_дані->ліво = AAV(visitContext(context->a_left));
    як_асд_дані->право = AAV(visitContext(context->a_type));
    return AV(this, context, АСДВидЯк, як_асд_дані);
  }

  std::any MavkaASTVisitor::visitGod(MavkaParser::GodContext* context) {
    const auto створити_бога_асд_дані = new СтворитиБогаАСДДані();
    std::vector<АСДЗначення*> elements;
    for (auto element : context->operation()) {
      elements.push_back(AAV(visitContext(element)));
    }
    створити_бога_асд_дані->елементи = AAVecToList(elements);
    return AV(this, context, АСДВидСтворитиБога, створити_бога_асд_дані);
  }
} // namespace mavka::parser