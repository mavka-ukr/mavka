#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitTry(MavkaParser::TryContext* context) {
    const auto спробувати_асд_дані = new СпробуватиАСДДані();
    if (context->t_body) {
      спробувати_асд_дані->тіло =
          AAVecToList(AAVec(visitBody(context->t_body)));
    } else {
      спробувати_асд_дані->тіло = AAVecToList({});
    }
    if (context->t_name) {
      спробувати_асд_дані->ідентифікатор_зловити =
          AAV(visitIdentifier(context->t_name));
    } else {
      спробувати_асд_дані->ідентифікатор_зловити = nullptr;
    }
    if (context->t_catch_body) {
      спробувати_асд_дані->тіло_зловити =
          AAVecToList(AAVec(visitBody(context->t_catch_body)));
    } else {
      спробувати_асд_дані->тіло_зловити = AAVecToList({});
    }
    return AV(this, context, АСДВидСпробувати, спробувати_асд_дані);
  }

  std::any MavkaASTVisitor::visitThrow(MavkaParser::ThrowContext* context) {
    const auto впасти_асд_дані = new ВпастиАСДДані();
    впасти_асд_дані->значення = AAV(visitContext(context->t_value));
    return AV(this, context, АСДВидВпасти, впасти_асд_дані);
  }
} // namespace mavka::parser