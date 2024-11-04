#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitSubject(MavkaParser::SubjectContext* context) {
    return visitIdentifierAsSubject(context->identifier());
  }

  std::any MavkaASTVisitor::visitIdentifierAsSubject(
      MavkaParser::IdentifierContext* context) {
    if (context->ID()->getText() == "пусто") {
      const auto створити_пусто_асд_дані = new СтворитиПустоАСДДані();
      return AV(this, context, АСДВидСтворитиПусто, створити_пусто_асд_дані);
    }
    if (context->ID()->getText() == "так") {
      const auto створити_так_асд_дані = new СтворитиТакАСДДані();
      return AV(this, context, АСДВидСтворитиТак, створити_так_асд_дані);
    }
    if (context->ID()->getText() == "ні") {
      const auto створити_ні_асд_дані = new СтворитиНіАСДДані();
      return AV(this, context, АСДВидСтворитиНі, створити_ні_асд_дані);
    }
    const auto звернутись_до_субʼєкта_асд_дані =
        new ЗвернутисьДоСубʼєктаАСДДані();
    звернутись_до_субʼєкта_асд_дані->ідентифікатор =
        AAV(visitIdentifier(context));
    return AV(this, context, АСДВидЗвернутисьДоСубʼєкта,
              звернутись_до_субʼєкта_асд_дані);
  }

  std::any MavkaASTVisitor::visitSubject_out(
      MavkaParser::Subject_outContext* context) {
    return visitIdentifierAsSubject(context->identifier());
  }

  std::any MavkaASTVisitor::visitGet(MavkaParser::GetContext* context) {
    const auto отримати_властивість_асд_дані = new ОтриматиВластивістьАСДДані();
    отримати_властивість_асд_дані->субʼєкт = AAV(visitContext(context->g_left));
    отримати_властивість_асд_дані->ідентифікатор =
        AAV(visitIdentifier(context->g_id));
    return AV(this, context, АСДВидОтриматиВластивість,
              отримати_властивість_асд_дані);
  }

  std::any MavkaASTVisitor::visitGet_out(MavkaParser::Get_outContext* context) {
    const auto отримати_властивість_асд_дані = new ОтриматиВластивістьАСДДані();
    отримати_властивість_асд_дані->субʼєкт = AAV(visitContext(context->g_left));
    отримати_властивість_асд_дані->ідентифікатор =
        AAV(visitIdentifier(context->g_id));
    return AV(this, context, АСДВидОтриматиВластивість,
              отримати_властивість_асд_дані);
  }

  std::any MavkaASTVisitor::visitGeneric(MavkaParser::GenericContext* context) {
    const auto виконати_шаблон_асд_дані = new ВиконатиШаблонАСДДані();
    виконати_шаблон_асд_дані->субʼєкт = AAV(visitContext(context->g_left));
    std::vector<АСДЗначення*> args;
    for (auto* type : context->type()) {
      args.push_back(AAV(visitType(type)));
    }
    виконати_шаблон_асд_дані->аргументи = AAVecToList(args);
    return AV(this, context, АСДВидВиконатиШаблон, виконати_шаблон_асд_дані);
  }

  std::any MavkaASTVisitor::visitGeneric_out(
      MavkaParser::Generic_outContext* context) {
    const auto виконати_шаблон_асд_дані = new ВиконатиШаблонАСДДані();
    виконати_шаблон_асд_дані->субʼєкт = AAV(visitContext(context->g_left));
    std::vector<АСДЗначення*> args;
    for (auto* type : context->type()) {
      args.push_back(AAV(visitType(type)));
    }
    виконати_шаблон_асд_дані->аргументи = AAVecToList(args);
    return AV(this, context, АСДВидВиконатиШаблон, виконати_шаблон_асд_дані);
  }

  std::any MavkaASTVisitor::visitAccess(MavkaParser::AccessContext* ctx) {
    const auto отримати_елемент_асд_дані = new ОтриматиЕлементАСДДані();
    отримати_елемент_асд_дані->субʼєкт = AAV(visitContext(ctx->a_left));
    отримати_елемент_асд_дані->ключ = AAV(visitContext(ctx->expr()));
    return AV(this, ctx, АСДВидОтриматиЕлемент, отримати_елемент_асд_дані);
  }
} // namespace mavka::parser