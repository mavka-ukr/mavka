#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitChain(MavkaParser::ChainContext* ctx) {
    std::vector<АСДЗначення*> chain;
    for (auto* identifier : ctx->identifier()) {
      chain.push_back(AAV(visitIdentifier(identifier)));
    }
    return chain;
  }

  std::any MavkaASTVisitor::visitTake(MavkaParser::TakeContext* context) {
    const auto взяти_асд_дані = new ВзятиАСДДані();
    if (context->t_repo) {
      взяти_асд_дані->ідентифікатор_репозиторія =
          AAV(visitIdentifier(context->t_repo));
    } else {
      взяти_асд_дані->ідентифікатор_репозиторія = nullptr;
    }
    взяти_асд_дані->шлях = AAVecToList(AAVec(visitChain(context->t_chain)));
    if (context->t_as) {
      взяти_асд_дані->ідентифікатор_назви = AAV(visitIdentifier(context->t_as));
    } else {
      взяти_асд_дані->ідентифікатор_назви =
          взяти_асд_дані->шлях.елементи[взяти_асд_дані->шлях.розмір - 1];
    }
    if (context->t_elements) {
      std::vector<АСДЗначення*> елементи;
      for (auto* element : context->t_elements->take_element()) {
        const auto елемент_взяти_асд_дані = new ЕлементВзятиАСДДані();
        елемент_взяти_асд_дані->ідентифікатор_властивості =
            AAV(visitIdentifier(element->te_name));
        if (element->te_as) {
          елемент_взяти_асд_дані->ідентифікатор_назви =
              AAV(visitIdentifier(element->te_as));
        } else {
          елемент_взяти_асд_дані->ідентифікатор_назви =
              елемент_взяти_асд_дані->ідентифікатор_властивості;
        }
        елементи.push_back(
            AV(this, element, АСДВидЕлементВзяти, елемент_взяти_асд_дані));
      }
      взяти_асд_дані->елементи = AAVecToList(елементи);
    } else {
      взяти_асд_дані->елементи = AAVecToList({});
    }
    return AV(this, context, АСДВидВзяти, взяти_асд_дані);
  }
} // namespace mavka::parser
