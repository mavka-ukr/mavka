#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitCall(MavkaParser::CallContext* context) {
    const auto виконати_дію_асд_дані = new ВиконатиДіюАСДДані();
    виконати_дію_асд_дані->субʼєкт = AAV(visitContext(context->c_value));
    if (context->c_args) {
      std::vector<АСДЗначення*> args;
      for (const auto& arg : context->c_args->call_arg()) {
        if (arg->ca_id) {
          const auto named_arg = new АргументВиконанняДіїЗНазвоюАСДДані();
          named_arg->ідентифікатор = AAV(visitIdentifier(arg->ca_id));
          named_arg->значення = AAV(visitContext(arg->ca_expr));
          args.push_back(
              AV(this, arg, АСДВидАргументВиконанняДіїЗНазвою, named_arg));
        } else {
          args.push_back(AAV(visitContext(arg->ca_expr)));
        }
      }
      const auto elements = new АСДЗначення*[args.size()];
      for (size_t i = 0; i < args.size(); i++) {
        elements[i] = args[i];
      }
      СписокАСДЗначень списокАсдЗначень = {
          args.size(),
          elements,
      };
      виконати_дію_асд_дані->аргументи = списокАсдЗначень;
    } else {
      виконати_дію_асд_дані->аргументи = AAVecToList({});
    }
    return AV(this, context, АСДВидВиконатиДію, виконати_дію_асд_дані);
  }

  std::any MavkaASTVisitor::visitWait(MavkaParser::WaitContext* context) {
    const auto чекати_асд_дані = new ЧекатиАСДДані();
    чекати_асд_дані->значення = AAV(visitContext(context->operation()));
    return AV(this, context, АСДВидЧекати, чекати_асд_дані);
  }
} // namespace mavka::parser