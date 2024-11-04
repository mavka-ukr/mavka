#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitModule(MavkaParser::ModuleContext* context) {
    const auto створити_модуль_асд_дані = new СтворитиМодульАСДДані();
    if (context->m_name) {
      створити_модуль_асд_дані->ідентифікатор =
          AAV(visitIdentifier(context->m_name));
    }
    if (context->m_body) {
      створити_модуль_асд_дані->тіло =
          AAVecToList(AAVec(visitBody(context->m_body)));
    }
    return AV(this, context, АСДВидСтворитиМодуль, створити_модуль_асд_дані);
  }
} // namespace mavka::parser