#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitGive(MavkaParser::GiveContext* context) {
    const auto дати_асд_дані = new ДатиАСДДані();
    std::vector<АСДЗначення*> elements;
    for (auto give_element : context->give_element()) {
      const auto елемент_дати_асд_дані = new ЕлементДатиАСДДані();
      елемент_дати_асд_дані->субʼєкт =
          AAV(visitIdentifierAsSubject(give_element->ge_name));
      if (give_element->ge_as) {
        елемент_дати_асд_дані->ідентифікатор =
            AAV(visitIdentifier(give_element->ge_as));
      } else {
        елемент_дати_асд_дані->ідентифікатор =
            AAV(visitIdentifier(give_element->ge_name));
      }
      elements.push_back(
          AV(this, give_element, АСДВидЕлементДати, елемент_дати_асд_дані));
    }
    дати_асд_дані->елементи = AAVecToList(elements);
    return AV(this, context, АСДВидДати, дати_асд_дані);
  }
} // namespace mavka::parser