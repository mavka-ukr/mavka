#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitIf(MavkaParser::IfContext* context) {
    const auto якщо_асд_дані = new ЯкщоАСДДані();
    якщо_асд_дані->умова = AAV(visitContext(context->i_value));
    if (context->i_body) {
      якщо_асд_дані->тіло = AAVecToList(AAVec(visitBody(context->i_body)));
    } else {
      якщо_асд_дані->тіло = AAVecToList({});
    }
    if (context->i_else_body) {
      якщо_асд_дані->тіло_інакше =
          AAVecToList(AAVec(visitBody(context->i_else_body)));
    } else {
      if (context->i_else_if) {
        std::vector<АСДЗначення*> else_ifs;
        else_ifs.push_back(AAV(visitIf(context->i_else_if)));
        якщо_асд_дані->тіло_інакше = AAVecToList(else_ifs);
      } else {
        якщо_асд_дані->тіло_інакше = AAVecToList({});
      }
    }
    return AV(this, context, АСДВидЯкщо, якщо_асд_дані);
  }

  std::any MavkaASTVisitor::visitTernary(MavkaParser::TernaryContext* context) {
    const auto значення_якщо_асд_дані = new ЗначенняЯкщоАСДДані();
    значення_якщо_асд_дані->умова = AAV(visitContext(context->t_value));
    значення_якщо_асд_дані->якщо_так = AAV(visitContext(context->t_positive));
    значення_якщо_асд_дані->якщо_ні = AAV(visitContext(context->t_negative));
    return AV(this, context, АСДВидЗначенняЯкщо, значення_якщо_асд_дані);
  }
} // namespace mavka::parser