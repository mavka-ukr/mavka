#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitDiia(MavkaParser::DiiaContext* context) {
    const auto створити_дію_асд_дані = new СтворитиДіюАСДДані();
    if (context->d_async) {
      створити_дію_асд_дані->чи_тривала = 1;
    } else {
      створити_дію_асд_дані->чи_тривала = 0;
    }
    if (context->d_name) {
      створити_дію_асд_дані->ідентифікатор =
          AAV(visitIdentifier(context->d_name));
    } else {
      створити_дію_асд_дані->ідентифікатор = nullptr;
    }
    if (context->d_params) {
      std::vector<АСДЗначення*> params;
      for (const auto& diia_param : context->d_params->diia_param()) {
        const auto параметр_дії_асд_дані = new ПараметрДіїАСДДані();
        параметр_дії_асд_дані->ідентифікатор =
            AAV(visitIdentifier(diia_param->p_name));
        if (diia_param->p_type) {
          параметр_дії_асд_дані->тип = AAV(visitContext(diia_param->p_type));
        } else {
          параметр_дії_асд_дані->тип = nullptr;
        }
        if (diia_param->p_value) {
          параметр_дії_асд_дані->значення =
              AAV(visitContext(diia_param->p_value));
        } else {
          параметр_дії_асд_дані->значення = nullptr;
        }
        params.push_back(
            AV(this, diia_param, АСДВидПараметрДії, параметр_дії_асд_дані));
      }
      створити_дію_асд_дані->параметри = AAVecToList(params);
    } else {
      створити_дію_асд_дані->параметри = AAVecToList({});
    }
    if (context->d_type) {
      створити_дію_асд_дані->тип_повернення =
          AAV(visitContext(context->d_type));
    } else {
      створити_дію_асд_дані->тип_повернення = nullptr;
    }
    if (context->d_body) {
      створити_дію_асд_дані->тіло =
          AAVecToList(AAVec(visitBody(context->d_body)));
    } else {
      створити_дію_асд_дані->тіло = AAVecToList({});
    }
    if (context->d_structure) {
      const auto створити_дію_для_структури_асд_дані =
          new СтворитиДіюДляСтруктуриАСДДані();
      створити_дію_для_структури_асд_дані->для_структури =
          AAV(visitIdentifierAsSubject(context->d_structure));
      створити_дію_для_структури_асд_дані->значення_дії =
          AV(this, context, АСДВидСтворитиДію, створити_дію_асд_дані);
      return AV(this, context, АСДВидСтворитиДіюДляСтруктури,
                створити_дію_для_структури_асд_дані);
    }
    return AV(this, context, АСДВидСтворитиДію, створити_дію_асд_дані);
  }
} // namespace mavka::parser