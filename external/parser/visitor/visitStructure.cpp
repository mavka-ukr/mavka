#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitStructure(
      MavkaParser::StructureContext* context) {
    const auto створити_структуру_асд_дані = new СтворитиСтруктуруАСДДані();
    if (context->s_name) {
      створити_структуру_асд_дані->ідентифікатор =
          AAV(visitIdentifier(context->s_name));
    } else {
      створити_структуру_асд_дані->ідентифікатор = nullptr;
    }
    if (context->s_parent) {
      створити_структуру_асд_дані->предок =
          AAV(visitIdentifierAsSubject(context->s_parent));
    } else {
      створити_структуру_асд_дані->предок = nullptr;
    }
    if (context->s_elements) {
      std::vector<АСДЗначення*> elements;
      for (const auto& structure_element :
           context->s_elements->structure_element()) {
        const auto structure_param = structure_element->structure_param();
        if (structure_param) {
          const auto параметр_структури_асд_дані =
              new ПараметрСтруктуриАСДДані();
          параметр_структури_асд_дані->ідентифікатор =
              AAV(visitIdentifier(structure_param->sp_name));
          if (structure_param->sp_type) {
            параметр_структури_асд_дані->тип =
                AAV(visitContext(structure_param->sp_type));
          } else {
            параметр_структури_асд_дані->тип = nullptr;
          }
          if (structure_param->sp_value) {
            параметр_структури_асд_дані->значення =
                AAV(visitContext(structure_param->sp_value));
          } else {
            параметр_структури_асд_дані->значення = nullptr;
          }
          elements.push_back(AV(this, structure_param, АСДВидПараметрСтруктури,
                                параметр_структури_асд_дані));
        }
      }
      створити_структуру_асд_дані->елементи = AAVecToList(elements);
    } else {
      створити_структуру_асд_дані->елементи = AAVecToList({});
    }
    return AV(this, context, АСДВидСтворитиСтруктуру,
              створити_структуру_асд_дані);
  }
} // namespace mavka::parser