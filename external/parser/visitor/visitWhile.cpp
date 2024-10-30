#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitWhile(MavkaParser::WhileContext* context) {
    const auto поки_асд_дані = new ПокиАСДДані();
    if (context->w_value) {
      поки_асд_дані->умова = AAV(visitContext(context->w_value));
    } else {
      поки_асд_дані->умова = nullptr;
    }
    if (context->w_body) {
      поки_асд_дані->тіло = AAVecToList(AAVec(visitBody(context->w_body)));
    }
    return AV(this, context, АСДВидПоки, поки_асд_дані);
  }

  std::any MavkaASTVisitor::visitInterval(
      MavkaParser::IntervalContext* context) {
    if (context->i_right) {
      const auto перебрати_діапазон_асд_дані = new ПеребратиДіапазонАСДДані();
      перебрати_діапазон_асд_дані->від = AAV(visitContext(context->i_left));
      перебрати_діапазон_асд_дані->до = AAV(visitContext(context->i_right));
      перебрати_діапазон_асд_дані->ідентифікатор = AAV(visitContext(context->i_id));
      if (context->e_body) {
        перебрати_діапазон_асд_дані->тіло =
            AAVecToList(AAVec(visitBody(context->e_body)));
      } else {
        перебрати_діапазон_асд_дані->тіло = AAVecToList({});
      }
      return AV(this, context, АСДВидПеребратиДіапазон,
                перебрати_діапазон_асд_дані);
    } else {
      const auto перебрати_асд_дані = new ПеребратиАСДДані();
      перебрати_асд_дані->значення = AAV(visitContext(context->i_left));
      перебрати_асд_дані->ідентифікатор = AAV(visitContext(context->i_id));
      if (context->e_body) {
        перебрати_асд_дані->тіло =
            AAVecToList(AAVec(visitBody(context->e_body)));
      } else {
        перебрати_асд_дані->тіло = AAVecToList({});
      }
      return AV(this, context, АСДВидПеребрати, перебрати_асд_дані);
    }
  }

  std::any MavkaASTVisitor::visitCycle(MavkaParser::CycleContext* context) {
    std::vector<АСДЗначення*> elements;
    if (context->c_a) {
      if (context->c_a->assign()) {
        elements.push_back(AAV(visitAssign(context->c_a->assign())));
      } else if (context->c_a->set()) {
        elements.push_back(AAV(visitSet(context->c_a->set())));
      } else if (context->c_a->operation()) {
        elements.push_back(AAV(visitContext(context->c_a->operation())));
      }
    }
    const auto поки_асд_дані = new ПокиАСДДані();
    if (context->c_b) {
      if (context->c_b->assign()) {
        поки_асд_дані->умова = AAV(visitAssign(context->c_b->assign()));
      } else if (context->c_b->set()) {
        поки_асд_дані->умова = AAV(visitSet(context->c_b->set()));
      } else if (context->c_b->operation()) {
        поки_асд_дані->умова = AAV(visitContext(context->c_b->operation()));
      }
    } else {
      поки_асд_дані->умова = nullptr;
    }
    std::vector<АСДЗначення*> body_vec;
    if (context->c_body) {
      body_vec = AAVec(visitBody(context->c_body));
    }
    if (context->c_c) {
      if (context->c_c->assign()) {
        body_vec.push_back(AAV(visitAssign(context->c_c->assign())));
      } else if (context->c_c->set()) {
        body_vec.push_back(AAV(visitSet(context->c_c->set())));
      } else if (context->c_c->operation()) {
        body_vec.push_back(AAV(visitContext(context->c_c->operation())));
      }
    }
    поки_асд_дані->тіло = AAVecToList(body_vec);
    elements.push_back(AV(this, context, АСДВидПоки, поки_асд_дані));
    return elements;
  }
} // namespace mavka::parser