#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitDict(MavkaParser::DictContext* context) {
    const auto створити_словник_асд_дані = new СтворитиСловникАСДДані();
    std::vector<АСДЗначення*> elements;
    if (context->dict_elements()) {
      for (auto element : context->dict_elements()->dict_element()) {
        АСДЗначення* key = nullptr;
        if (element->de_string) {
          key = AAV(visitString(element->de_string));
        }
        if (element->de_number) {
          key = AAV(visitNumber(element->de_number));
        }
        if (element->de_character) {
          key = AAV(visitCharacter(element->de_character));
        }
        const auto value = AAV(visitContext(element->de_value));
        const auto елемент_словника_асд_дані = new ЕлементСловникаАСДДані();
        елемент_словника_асд_дані->ключ = key;
        елемент_словника_асд_дані->значення = value;
        elements.push_back(AV(this, element, АСДВидЕлементСловника,
                              елемент_словника_асд_дані));
      }
    }
    створити_словник_асд_дані->елементи = AAVecToList(elements);
    return AV(this, context, АСДВидСтворитиСловник, створити_словник_асд_дані);
  }
} // namespace mavka::parser