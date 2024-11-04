#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitBody(MavkaParser::BodyContext* context) {
    std::vector<АСДЗначення*> body;
    for (const auto body_element : context->body_element()) {
      if (body_element->if_()) {
        body.push_back(AAV(visitIf(body_element->if_())));
      }
      if (body_element->while_()) {
        body.push_back(AAV(visitWhile(body_element->while_())));
      }
      if (body_element->interval()) {
        body.push_back(AAV(visitInterval(body_element->interval())));
      }
      if (body_element->cycle()) {
        const auto elements = AAVec(visitCycle(body_element->cycle()));
        for (const auto& element : elements) {
          body.push_back(element);
        }
      }
      if (body_element->try_()) {
        body.push_back(AAV(visitTry(body_element->try_())));
      }
      if (body_element->throw_()) {
        body.push_back(AAV(visitThrow(body_element->throw_())));
      }
      if (body_element->assign()) {
        body.push_back(AAV(visitAssign(body_element->assign())));
      }
      if (body_element->set()) {
        body.push_back(AAV(visitSet(body_element->set())));
      }
      if (body_element->set_by_access()) {
        body.push_back(AAV(visitSet_by_access(body_element->set_by_access())));
      }
      if (body_element->expr()) {
        const auto expr_result = AAV(visitContext(body_element->expr()));
        if (expr_result->вид == АСДВидСтворитиДію) {
          const auto data = static_cast<СтворитиДіюАСДДані*>(expr_result->дані);
          if (data->ідентифікатор) {
            const auto визначити_субʼєкт_асд_дані =
                new ВизначитиСубʼєктАСДДані();
            визначити_субʼєкт_асд_дані->ідентифікатор = data->ідентифікатор;
            визначити_субʼєкт_асд_дані->значення = expr_result;
            body.push_back(AV(this, context, АСДВидВизначитиСубʼєкт,
                              визначити_субʼєкт_асд_дані));
          } else {
            body.push_back(expr_result);
          }
        } else if (expr_result->вид == АСДВидСтворитиСтруктуру) {
          const auto data =
              static_cast<СтворитиСтруктуруАСДДані*>(expr_result->дані);
          if (data->ідентифікатор) {
            const auto визначити_субʼєкт_асд_дані =
                new ВизначитиСубʼєктАСДДані();
            визначити_субʼєкт_асд_дані->ідентифікатор = data->ідентифікатор;
            визначити_субʼєкт_асд_дані->значення = expr_result;
            body.push_back(AV(this, context, АСДВидВизначитиСубʼєкт,
                              визначити_субʼєкт_асд_дані));
          } else {
            body.push_back(expr_result);
          }
        } else if (expr_result->вид == АСДВидСтворитиМодуль) {
          const auto data =
              static_cast<СтворитиМодульАСДДані*>(expr_result->дані);
          if (data->ідентифікатор) {
            const auto визначити_субʼєкт_асд_дані =
                new ВизначитиСубʼєктАСДДані();
            визначити_субʼєкт_асд_дані->ідентифікатор = data->ідентифікатор;
            визначити_субʼєкт_асд_дані->значення = expr_result;
            body.push_back(AV(this, context, АСДВидВизначитиСубʼєкт,
                              визначити_субʼєкт_асд_дані));
          } else {
            body.push_back(expr_result);
          }
        } else if (expr_result->вид == АСДВидЗвернутисьДоСубʼєкта) {
          const auto data =
              static_cast<ЗвернутисьДоСубʼєктаАСДДані*>(expr_result->дані);
          const auto identifier_data =
              static_cast<ІдентифікаторАСДДані*>(data->ідентифікатор->дані);
          if (std::string(identifier_data->назва) == "пропустити") {
            const auto пропустити_асд_дані = new ПропуститиАСДДані();
            body.push_back(
                AV(this, context, АСДВидПропустити, пропустити_асд_дані));
          } else if (std::string(identifier_data->назва) == "перервати") {
            const auto перервати_асд_дані = new ПерерватиАСДДані();
            body.push_back(
                AV(this, context, АСДВидПерервати, перервати_асд_дані));
          } else {
            body.push_back(expr_result);
          }
        } else {
          body.push_back(expr_result);
        }
      }
      if (body_element->give()) {
        body.push_back(AAV(visitGive(body_element->give())));
      }
      if (body_element->take()) {
        body.push_back(AAV(visitTake(body_element->take())));
      }
      if (body_element->return_body_element()) {
        const auto вернути_асд_дані = new ВернутиАСДДані();
        if (body_element->return_body_element()->rbl_value) {
          вернути_асд_дані->значення =
              AAV(visitContext(body_element->return_body_element()->rbl_value));
        } else {
          вернути_асд_дані->значення = nullptr;
        }
        body.push_back(AV(this, body_element->return_body_element(),
                          АСДВидВернути, вернути_асд_дані));
      }
    }
    return body;
  }

  std::any MavkaASTVisitor::visitFunction(
      MavkaParser::FunctionContext* context) {
    const auto створити_дію_асд_дані = new СтворитиДіюАСДДані();
    створити_дію_асд_дані->чи_тривала = 0;
    if (context->f_params) {
      std::vector<АСДЗначення*> params;
      for (const auto& param : context->f_params->diia_param()) {
        const auto param_node = new ПараметрДіїАСДДані();
        param_node->ідентифікатор = AAV(visitIdentifier(param->p_name));
        if (param->p_type) {
          param_node->тип = AAV(visitContext(param->p_type));
        } else {
          param_node->тип = nullptr;
        }
        params.push_back(AV(this, param, АСДВидПараметрДії, param_node));
      }
      створити_дію_асд_дані->параметри = AAVecToList(params);
    } else {
      створити_дію_асд_дані->параметри = AAVecToList({});
    }
    if (context->f_type) {
      створити_дію_асд_дані->тип_повернення =
          AAV(visitContext(context->f_type));
    } else {
      створити_дію_асд_дані->тип_повернення = nullptr;
    }
    if (context->f_body) {
      std::vector<АСДЗначення*> body;
      const auto вернути_асд_дані = new ВернутиАСДДані();
      вернути_асд_дані->значення = AAV(visitContext(context->f_body));
      body.push_back(AV(this, context, АСДВидВернути, вернути_асд_дані));
      створити_дію_асд_дані->тіло = AAVecToList(body);
    } else {
      створити_дію_асд_дані->тіло = AAVecToList({});
    }
    return AV(this, context, АСДВидСтворитиДію, створити_дію_асд_дані);
  }
} // namespace mavka::parser