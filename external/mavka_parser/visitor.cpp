#include "parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitContext(antlr4::ParserRuleContext* context) {
    if (const auto ctx = dynamic_cast<MavkaParser::FileContext*>(context)) {
      return visitFile(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::ProgramContext*>(context)) {
      return visitProgram(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Atom_nestedContext*>(context)) {
      return visitAtom_nested(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Atom_subjectContext*>(context)) {
      return visitAtom_subject(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::Atom_getContext*>(context)) {
      return visitAtom_get(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Atom_position_getContext*>(context)) {
      return visitAtom_position_get(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Atom_callContext*>(context)) {
      return visitAtom_call(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_numberContext*>(context)) {
      return visitOperation_number(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_stringContext*>(context)) {
      return visitOperation_string(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_string_multilineContext*>(
                context)) {
      return visitOperation_string_multiline(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_symbolContext*>(context)) {
      return visitOperation_symbol(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_atomContext*>(context)) {
      return visitOperation_atom(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_pre_notContext*>(context)) {
      return visitOperation_pre_not(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_pre_bw_notContext*>(context)) {
      return visitOperation_pre_bw_not(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_pre_plusContext*>(context)) {
      return visitOperation_pre_plus(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_pre_minusContext*>(context)) {
      return visitOperation_pre_minus(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_delete_idContext*>(context)) {
      return visitOperation_delete_id(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_delete_propContext*>(context)) {
      return visitOperation_delete_prop(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_delete_elementContext*>(
                context)) {
      return visitOperation_delete_element(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_waitContext*>(context)) {
      return visitOperation_wait(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_powContext*>(context)) {
      return visitOperation_pow(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_mulContext*>(context)) {
      return visitOperation_mul(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_div_divContext*>(context)) {
      return visitOperation_div_div(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_divContext*>(context)) {
      return visitOperation_div(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_modContext*>(context)) {
      return visitOperation_mod(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_addContext*>(context)) {
      return visitOperation_add(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_subContext*>(context)) {
      return visitOperation_sub(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_lshiftContext*>(context)) {
      return visitOperation_lshift(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_rshiftContext*>(context)) {
      return visitOperation_rshift(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_urshiftContext*>(context)) {
      return visitOperation_urshift(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_ltContext*>(context)) {
      return visitOperation_lt(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_lteContext*>(context)) {
      return visitOperation_lte(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_gtContext*>(context)) {
      return visitOperation_gt(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_gteContext*>(context)) {
      return visitOperation_gte(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_containsContext*>(context)) {
      return visitOperation_contains(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_not_containsContext*>(
                context)) {
      return visitOperation_not_contains(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_isContext*>(context)) {
      return visitOperation_is(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_not_isContext*>(context)) {
      return visitOperation_not_is(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_eqContext*>(context)) {
      return visitOperation_eq(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_neqContext*>(context)) {
      return visitOperation_neq(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_andContext*>(context)) {
      return visitOperation_and(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_xorContext*>(context)) {
      return visitOperation_xor(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_orContext*>(context)) {
      return visitOperation_or(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_landContext*>(context)) {
      return visitOperation_land(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_lorContext*>(context)) {
      return visitOperation_lor(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_ternaryContext*>(context)) {
      return visitOperation_ternary(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Expr_operationContext*>(context)) {
      return visitExpr_operation(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Expr_diiaContext*>(context)) {
      return visitExpr_diia(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Expr_structureContext*>(context)) {
      return visitExpr_structure(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::FunctionContext*>(context)) {
      return visitFunction(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Structure_defineContext*>(context)) {
      return visitStructure_define(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Diia_defineContext*>(context)) {
      return visitDiia_define(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::AssignContext*>(context)) {
      return visitAssign(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::SetContext*>(context)) {
      return visitSet(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Position_setContext*>(context)) {
      return visitPosition_set(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::IfContext*>(context)) {
      return visitIf(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::WhileContext*>(context)) {
      return visitWhile(ctx);
    }
    if (const auto body_context =
            dynamic_cast<MavkaParser::Body_elementContext*>(context)) {
      return visitBody_element(body_context);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::ReturnContext*>(context)) {
      return visitReturn(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::TypeContext*>(context)) {
      if (const auto ctx1 =
              dynamic_cast<MavkaParser::Type_nestedContext*>(ctx)) {
        return visitContext(ctx1->expr());
      }
      if (const auto ctx1 =
              dynamic_cast<MavkaParser::Type_subjectContext*>(ctx)) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx1->id, ctx1->id->getText());
        return AV(this, ctx1, АСДВидЗвернутись, асд_дані_звернутись);
      }
      if (const auto ctx1 = dynamic_cast<MavkaParser::Type_getContext*>(ctx)) {
        const auto асд_дані_отримати = new АСДДаніОтримати();
        асд_дані_отримати->предмет = AAV(visitContext(ctx1->object));
        асд_дані_отримати->ідентифікатор =
            ІД(this, ctx1->id, ctx1->id->getText());
        return AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      }
      return nullptr;
    }
    if (const auto ctx = dynamic_cast<MavkaParser::ParamContext*>(context)) {
      return visitParam(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::TakeContext*>(context)) {
      return visitTake(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::TryContext*>(context)) {
      return visitTry(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::ThrowContext*>(context)) {
      return visitThrow(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::GiveContext*>(context)) {
      return visitGive(ctx);
    }
    if (const auto ctx = dynamic_cast<MavkaParser::ModuleContext*>(context)) {
      return visitModule(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_arrayContext*>(context)) {
      return visitOperation_array(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_dictContext*>(context)) {
      return visitOperation_dict(ctx);
    }
    if (const auto ctx =
            dynamic_cast<MavkaParser::Operation_dict_emptyContext*>(context)) {
      return visitOperation_dict_empty(ctx);
    }
    std::cout << "[PARSER] Unknown context: " << context->getText()
              << std::endl;
    return nullptr;
  }

  std::any MavkaASTVisitor::visitFile(MavkaParser::FileContext* ctx) {
    return visitProgram(ctx->program());
  }

  std::any MavkaASTVisitor::visitProgram(MavkaParser::ProgramContext* ctx) {
    std::vector<АСДЗначення*> elements;
    for (const auto& element : ctx->body_element()) {
      elements.push_back(AAV(visitBody_element(element)));
    }
    return elements;
  }

  std::any MavkaASTVisitor::visitAtom_nested(
      MavkaParser::Atom_nestedContext* ctx) {
    return visitContext(ctx->expr());
  }

  std::any MavkaASTVisitor::visitAtom_subject(
      MavkaParser::Atom_subjectContext* ctx) {
    const auto асд_дані_звернутись = new АСДДаніЗвернутись();
    асд_дані_звернутись->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
  }

  std::any MavkaASTVisitor::visitAtom_get(MavkaParser::Atom_getContext* ctx) {
    const auto асд_дані_отримати = new АСДДаніОтримати();
    асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
    асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
  }

  std::any MavkaASTVisitor::visitAtom_position_get(
      MavkaParser::Atom_position_getContext* ctx) {
    const auto асд_дані_отримати_за_позицією = new АСДДаніОтриматиЗаПозицією();
    асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
    асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->position));
    return AV(this, ctx, АСДВидОтриматиЗаПозицією,
              асд_дані_отримати_за_позицією);
  }

  std::any MavkaASTVisitor::visitAtom_call(MavkaParser::Atom_callContext* ctx) {
    const auto асд_дані_виконати = new АСДДаніВиконати();
    асд_дані_виконати->предмет = AAV(visitContext(ctx->object));
    std::vector<Аргумент*> arguments;
    for (const auto& argument : ctx->call_arg()) {
      auto arg = new Аргумент();
      if (argument->id) {
        arg->ідентифікатор = ІД(this, argument->id, argument->id->getText());
      } else {
        arg->ідентифікатор = nullptr;
      }
      arg->значення = AAV(visitContext(argument->expr()));
      arg->місцезнаходження = LOC(this, argument);
      arguments.push_back(arg);
    }
    асд_дані_виконати->кількість_аргументів = arguments.size();
    асд_дані_виконати->аргументи = VecToArr(arguments);
    return AV(this, ctx, АСДВидВиконати, асд_дані_виконати);
  }

  std::any visitNumberText(MavkaASTVisitor* visitor, antlr4::Token* token) {
    const auto асд_дані_число = new АСДДаніЧисло();
    auto value = token->getText();
    асд_дані_число->база = 0;
    асд_дані_число->значення = nullptr;
    асд_дані_число->дробове = false;
    if (value.starts_with("0ш") || value.starts_with("0Ш")) {
      value = value.substr(3);
      асд_дані_число->база = 16;
    } else if (value.starts_with("0д") || value.starts_with("0Д")) {
      value = value.substr(3);
      асд_дані_число->база = 2;
    } else {
      асд_дані_число->база = 10;
    }
    if (value.find('.') != std::string::npos) {
      асд_дані_число->дробове = true;
    }
    асд_дані_число->значення = strdup(value.c_str());
    return AV(visitor, token, АСДВидЧисло, асд_дані_число);
  }

  std::any MavkaASTVisitor::visitOperation_number(
      MavkaParser::Operation_numberContext* ctx) {
    return visitNumberText(this, ctx->NUMBER()->getSymbol());
  }

  void replaceAll(std::string& value,
                  const std::string& from,
                  const std::string& to) {
    if (from.empty()) {
      return;
    }
    size_t start_pos = 0;
    while ((start_pos = value.find(from, start_pos)) != std::string::npos) {
      value.replace(start_pos, from.length(), to);
      start_pos += to.length();
    }
  }

  inline std::string replaceBackslashes(std::string value) {
    replaceAll(value, "\\n", "\n");
    replaceAll(value, "\\н", "\n");
    replaceAll(value, "\\\\", "\\");
    replaceAll(value, "\\t", "\t");
    replaceAll(value, "\\?", "?");
    replaceAll(value, "\\v", "\v");
    replaceAll(value, "\\\'", "'");
    replaceAll(value, "\\b", "\b");
    replaceAll(value, "\\\"", "\"");
    replaceAll(value, "\\r", "\r");
    replaceAll(value, "\\0", "\0");
    replaceAll(value, "\\f", "\f");
    replaceAll(value, "\\a", "\a");
    return value;
  }

  std::any visitStringText(MavkaASTVisitor* visitor,
                           Ідентифікатор* ідентифікатор,
                           antlr4::Token* token) {
    const auto асд_дані_текст = new АСДДаніТекст();
    асд_дані_текст->ідентифікатор = ідентифікатор;
    асд_дані_текст->значення =
        strdup(replaceBackslashes(
                   token->getText().substr(1, token->getText().size() - 2))
                   .c_str());
    асд_дані_текст->інтерпольовано = false;
    return AV(visitor, token, АСДВидТекст, асд_дані_текст);
  }

  std::any MavkaASTVisitor::visitOperation_string(
      MavkaParser::Operation_stringContext* ctx) {
    if (ctx->tt != nullptr) {
      return visitStringText(this, ІД(this, ctx->tt, ctx->tt->getText()),
                             ctx->STRING()->getSymbol());
    } else {
      return visitStringText(this, nullptr, ctx->STRING()->getSymbol());
    }
  }

  std::any visitStringMultilineText(MavkaASTVisitor* visitor,
                                    Ідентифікатор* ідентифікатор,
                                    antlr4::Token* token) {
    const auto асд_дані_текст = new АСДДаніТекст();
    асд_дані_текст->ідентифікатор = ідентифікатор;
    асд_дані_текст->значення =
        strdup(replaceBackslashes(
                   token->getText().substr(3, token->getText().size() - 6))
                   .c_str());
    асд_дані_текст->інтерпольовано = false;
    return AV(visitor, token, АСДВидТекст, асд_дані_текст);
  }

  std::any MavkaASTVisitor::visitOperation_string_multiline(
      MavkaParser::Operation_string_multilineContext* ctx) {
    if (ctx->tt != nullptr) {
      return visitStringMultilineText(this,
                                      ІД(this, ctx->tt, ctx->tt->getText()),
                                      ctx->STRING_MULTILINE()->getSymbol());
    } else {
      return visitStringMultilineText(this, nullptr,
                                      ctx->STRING_MULTILINE()->getSymbol());
    }
  }

  std::any visitSymbolText(MavkaASTVisitor* visitor,
                           Ідентифікатор* ідентифікатор,
                           antlr4::Token* token) {
    const auto асд_дані_текст = new АСДДаніСимвол();
    асд_дані_текст->ідентифікатор = ідентифікатор;
    асд_дані_текст->значення =
        strdup(replaceBackslashes(
                   token->getText().substr(1, token->getText().size() - 2))
                   .c_str());
    return AV(visitor, token, АСДВидСимвол, асд_дані_текст);
  }

  std::any MavkaASTVisitor::visitOperation_symbol(
      MavkaParser::Operation_symbolContext* ctx) {
    if (ctx->tt != nullptr) {
      return visitSymbolText(this, ІД(this, ctx->tt, ctx->tt->getText()),
                             ctx->CHARACTER()->getSymbol());
    } else {
      return visitSymbolText(this, nullptr, ctx->CHARACTER()->getSymbol());
    }
  }

  std::any MavkaASTVisitor::visitOperation_atom(
      MavkaParser::Operation_atomContext* ctx) {
    return visitContext(ctx->atom());
  }

  std::any MavkaASTVisitor::visitOperation_pre_not(
      MavkaParser::Operation_pre_notContext* ctx) {
    const auto асд_дані_само_операція = new АСДДаніСамоОперація();
    асд_дані_само_операція->операція = АСДСамоОпераціяЛогічнеНі;
    асд_дані_само_операція->предмет = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидСамоОперація, асд_дані_само_операція);
  }

  std::any MavkaASTVisitor::visitOperation_pre_bw_not(
      MavkaParser::Operation_pre_bw_notContext* ctx) {
    const auto асд_дані_само_операція = new АСДДаніСамоОперація();
    асд_дані_само_операція->операція = АСДСамоОпераціяДвійковеНі;
    асд_дані_само_операція->предмет = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидСамоОперація, асд_дані_само_операція);
  }

  std::any MavkaASTVisitor::visitOperation_pre_plus(
      MavkaParser::Operation_pre_plusContext* ctx) {
    const auto асд_дані_само_операція = new АСДДаніСамоОперація();
    асд_дані_само_операція->операція = АСДСамоОпераціяПлюс;
    асд_дані_само_операція->предмет = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидСамоОперація, асд_дані_само_операція);
  }

  std::any MavkaASTVisitor::visitOperation_pre_minus(
      MavkaParser::Operation_pre_minusContext* ctx) {
    const auto асд_дані_само_операція = new АСДДаніСамоОперація();
    асд_дані_само_операція->операція = АСДСамоОпераціяМінус;
    асд_дані_само_операція->предмет = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидСамоОперація, асд_дані_само_операція);
  }

  std::any MavkaASTVisitor::visitOperation_delete_id(
      MavkaParser::Operation_delete_idContext* ctx) {
    const auto асд_дані_видалити = new АСДДаніВидалити();
    асд_дані_видалити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВидалити, асд_дані_видалити);
  }

  std::any MavkaASTVisitor::visitOperation_delete_prop(
      MavkaParser::Operation_delete_propContext* ctx) {
    const auto асд_дані_видалити_властивість = new АСДДаніВидалитиВластивість();
    асд_дані_видалити_властивість->предмет = AAV(visitContext(ctx->object));
    асд_дані_видалити_властивість->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВидалитиВластивість,
              асд_дані_видалити_властивість);
  }

  std::any MavkaASTVisitor::visitOperation_delete_element(
      MavkaParser::Operation_delete_elementContext* ctx) {
    const auto асд_дані_видалити_елемент = new АСДДаніВидалитиЕлемент();
    асд_дані_видалити_елемент->предмет = AAV(visitContext(ctx->object));
    асд_дані_видалити_елемент->позиція = AAV(visitContext(ctx->position));
    return AV(this, ctx, АСДВидВидалитиЕлемент, асд_дані_видалити_елемент);
  }

  std::any MavkaASTVisitor::visitOperation_wait(
      MavkaParser::Operation_waitContext* ctx) {
    const auto асд_дані_чекати = new АСДДаніЧекати();
    асд_дані_чекати->значення = AAV(visitContext(ctx->object));
    return AV(this, ctx, АСДВидЧекати, асд_дані_чекати);
  }

  std::any MavkaASTVisitor::visitOperation_pow(
      MavkaParser::Operation_powContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяПіднесенняДоСтепеня;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_mul(
      MavkaParser::Operation_mulContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяМноження;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_div_div(
      MavkaParser::Operation_div_divContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяДіленняНаціло;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_div(
      MavkaParser::Operation_divContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяДілення;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_mod(
      MavkaParser::Operation_modContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяМодуль;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_add(
      MavkaParser::Operation_addContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяДодавання;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_sub(
      MavkaParser::Operation_subContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяВіднімання;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_lshift(
      MavkaParser::Operation_lshiftContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяЗсувВліво;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_rshift(
      MavkaParser::Operation_rshiftContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяЗсувВправо;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_urshift(
      MavkaParser::Operation_urshiftContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяЗсувВправоЗнаковий;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_lt(
      MavkaParser::Operation_ltContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяМенше;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_lte(
      MavkaParser::Operation_lteContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяМеншеРівне;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_gt(
      MavkaParser::Operation_gtContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяБільше;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_gte(
      MavkaParser::Operation_gteContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяБільшеРівне;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_contains(
      MavkaParser::Operation_containsContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяМістить;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_not_contains(
      MavkaParser::Operation_not_containsContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяНеМістить;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_is(
      MavkaParser::Operation_isContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяЄ;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_not_is(
      MavkaParser::Operation_not_isContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяНеЄ;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_eq(
      MavkaParser::Operation_eqContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяРівне;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_neq(
      MavkaParser::Operation_neqContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяНерівне;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_and(
      MavkaParser::Operation_andContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяДІ;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_xor(
      MavkaParser::Operation_xorContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяВАБО;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_or(
      MavkaParser::Operation_orContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяДАБО;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_land(
      MavkaParser::Operation_landContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяІ;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_lor(
      MavkaParser::Operation_lorContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяАБО;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any MavkaASTVisitor::visitOperation_ternary(
      MavkaParser::Operation_ternaryContext* ctx) {
    const auto асд_дані_значення_якщо = new АСДДаніЗначенняЯкщо();
    асд_дані_значення_якщо->умова = AAV(visitContext(ctx->cond));
    асд_дані_значення_якщо->значення_так = AAV(visitContext(ctx->ifok));
    асд_дані_значення_якщо->значення_ні = AAV(visitContext(ctx->ifnot));
    return AV(this, ctx, АСДВидЗначенняЯкщо, асд_дані_значення_якщо);
  }

  std::any MavkaASTVisitor::visitExpr_operation(
      MavkaParser::Expr_operationContext* ctx) {
    return visitContext(ctx->operation());
  }

  std::any MavkaASTVisitor::visitExpr_diia(MavkaParser::Expr_diiaContext* ctx) {
    return visitContext(ctx->diia_define());
  }

  std::any MavkaASTVisitor::visitExpr_structure(
      MavkaParser::Expr_structureContext* ctx) {
    return visitContext(ctx->structure_define());
  }

  std::any MavkaASTVisitor::visitFunction(MavkaParser::FunctionContext* ctx) {
    const auto асд_дані_дія = new АСДДаніДія();
    асд_дані_дія->тривала = false;
    асд_дані_дія->модифікатор = 0;
    асд_дані_дія->структура_ = nullptr;
    асд_дані_дія->ідентифікатор = nullptr;
    std::vector<Параметр*> params;
    for (const auto& param : ctx->diia_param()) {
      const auto any_param = visitParam(param->param());
      params.push_back(std::any_cast<Параметр*>(any_param));
    }
    асд_дані_дія->кількість_параметрів = params.size();
    асд_дані_дія->параметри = VecToArr(params);
    std::vector<АСДЗначення*> types;
    if (ctx->d_type) {
      for (const auto& type : ctx->d_type->type()) {
        types.push_back(AAV(visitContext(type)));
      }
    }
    асд_дані_дія->кількість_типів_результату = types.size();
    асд_дані_дія->типи_результату = VecToArr(types);
    std::vector<АСДЗначення*> body;
    const auto вернути_асд_дані = new АСДДаніВернути();
    вернути_асд_дані->значення = AAV(visitContext(ctx->d_body));
    body.push_back(AV(this, ctx, АСДВидВернути, вернути_асд_дані));
    асд_дані_дія->тіло = AAVecToList(body);
    const auto асд_значення_дія = AV(this, ctx, АСДВидДія, асд_дані_дія);
    return асд_значення_дія;
  }

  std::any MavkaASTVisitor::visitStructure_define(
      MavkaParser::Structure_defineContext* ctx) {
    const auto асд_дані_структура = new АСДДаніСтруктура();
    if (ctx->id) {
      асд_дані_структура->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    } else {
      асд_дані_структура->ідентифікатор = nullptr;
    }
    if (ctx->s_parent) {
      асд_дані_структура->предок = AAV(visitContext(ctx->s_parent));
    } else {
      асд_дані_структура->предок = nullptr;
    }
    std::vector<Параметр*> params;
    for (const auto& structureElement : ctx->structure_element()) {
      const auto any_param = visitParam(structureElement->param());
      params.push_back(std::any_cast<Параметр*>(any_param));
    }
    асд_дані_структура->кількість_параметрів = params.size();
    асд_дані_структура->параметри = VecToArr(params);
    const auto асд_значення_структура =
        AV(this, ctx, АСДВидСтруктура, асд_дані_структура);
    return асд_значення_структура;
  }

  std::any MavkaASTVisitor::visitDiia_define(
      MavkaParser::Diia_defineContext* ctx) {
    const auto асд_дані_дія = new АСДДаніДія();
    асд_дані_дія->тривала = ctx->d_async != nullptr;
    if (ctx->d_spec) {
      асд_дані_дія->модифікатор = 1;
    } else if (ctx->d_own) {
      асд_дані_дія->модифікатор = 2;
    } else {
      асд_дані_дія->модифікатор = 0;
    }
    if (ctx->d_structure) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->d_structure, ctx->d_structure->getText());
      асд_дані_дія->структура_ =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
    } else {
      асд_дані_дія->структура_ = nullptr;
    }
    if (ctx->d_name) {
      асд_дані_дія->ідентифікатор =
          ІД(this, ctx->d_name, ctx->d_name->getText());
    } else {
      асд_дані_дія->ідентифікатор = nullptr;
    }
    std::vector<Параметр*> params;
    for (const auto& param : ctx->diia_param()) {
      const auto any_param = visitParam(param->param());
      params.push_back(std::any_cast<Параметр*>(any_param));
    }
    асд_дані_дія->кількість_параметрів = params.size();
    асд_дані_дія->параметри = VecToArr(params);
    std::vector<АСДЗначення*> types;
    if (ctx->d_type) {
      for (const auto& type : ctx->d_type->type()) {
        types.push_back(AAV(visitContext(type)));
      }
    }
    асд_дані_дія->кількість_типів_результату = types.size();
    асд_дані_дія->типи_результату = VecToArr(types);
    if (ctx->body()) {
      асд_дані_дія->тіло = AAVecToList(AAVec(visitBody(ctx->body())));
    } else {
      асд_дані_дія->тіло = AAVecToList({});
    }
    const auto асд_значення_дія = AV(this, ctx, АСДВидДія, асд_дані_дія);
    return асд_значення_дія;
  }

  std::any MavkaASTVisitor::visitAssign(MavkaParser::AssignContext* ctx) {
    if (ctx->parentas) {
      const auto асд_дані_визначити_ззовні = new АСДДаніВизначитиЗзовні();
      асд_дані_визначити_ззовні->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      асд_дані_визначити_ззовні->значення = AAV(visitContext(ctx->value_expr));
      return AV(this, ctx, АСДВидВизначитиЗзовні, асд_дані_визначити_ззовні);
    } else if (ctx->assign_op()) {
      const auto асд_дані_визначити = new АСДДаніВизначити();
      асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      if (ctx->assign_op()->aop_mul) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяМноження;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->aop_div) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяДілення;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->aop_div_div) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяДіленняНаціло;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->aop_pow) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяПіднесенняДоСтепеня;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->aop_mod) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяМодуль;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->aop_plus) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяДодавання;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->aop_minus) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяВіднімання;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->op_lshift()) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяЗсувВліво;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->op_rshift()) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяЗсувВправо;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->op_urshift()) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяЗсувВправоЗнаковий;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->aop_and) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяДІ;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->aop_xor) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяВАБО;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else if (ctx->assign_op()->aop_or) {
        const auto асд_дані_звернутись = new АСДДаніЗвернутись();
        асд_дані_звернутись->ідентифікатор =
            ІД(this, ctx->id, ctx->id->getText());
        const auto асд_дані_операція = new АСДДаніОперація();
        асд_дані_операція->ліво =
            AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
        асд_дані_операція->операція = АСДОпераціяДАБО;
        асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
        асд_дані_визначити->значення =
            AV(this, ctx, АСДВидОперація, асд_дані_операція);
      } else {
        асд_дані_визначити->значення = AAV(visitContext(ctx->value_expr));
      }
      return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
    } else {
      const auto асд_дані_визначити = new АСДДаніВизначити();
      асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      асд_дані_визначити->значення = AAV(visitContext(ctx->value_expr));
      return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
    }
  }

  std::any MavkaASTVisitor::visitSet(MavkaParser::SetContext* ctx) {
    const auto асд_дані_змінити = new АСДДаніЗмінити();
    асд_дані_змінити->предмет = AAV(visitContext(ctx->object));
    асд_дані_змінити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    if (ctx->assign_op()->aop_mul) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяМноження;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_div) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяДілення;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_div_div) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяДіленняНаціло;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_pow) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяПіднесенняДоСтепеня;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_mod) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяМодуль;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_plus) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяДодавання;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_minus) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяВіднімання;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_lshift()) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяЗсувВліво;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_rshift()) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяЗсувВправо;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_urshift()) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяЗсувВправоЗнаковий;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_and) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяДІ;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_xor) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяВАБО;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_or) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      асд_дані_операція->операція = АСДОпераціяДАБО;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else {
      асд_дані_змінити->значення = AAV(visitContext(ctx->value_expr));
    }
    return AV(this, ctx, АСДВидЗмінити, асд_дані_змінити);
  }

  std::any MavkaASTVisitor::visitPosition_set(
      MavkaParser::Position_setContext* ctx) {
    const auto асд_дані_змінити_за_позицією = new АСДДаніЗмінитиЗаПозицією();
    асд_дані_змінити_за_позицією->предмет = AAV(visitContext(ctx->object));
    асд_дані_змінити_за_позицією->позиція = AAV(visitContext(ctx->idx));
    if (ctx->assign_op()->aop_mul) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяМноження;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_div) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяДілення;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_div_div) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяДіленняНаціло;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_pow) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяПіднесенняДоСтепеня;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_mod) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяМодуль;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_plus) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяДодавання;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_minus) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяВіднімання;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_lshift()) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяЗсувВліво;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_rshift()) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяЗсувВправо;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_urshift()) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяЗсувВправоЗнаковий;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_and) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяДІ;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_xor) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяВАБО;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_or) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->предмет = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = AV(this, ctx, АСДВидОтриматиЗаПозицією,
                                   асд_дані_отримати_за_позицією);
      асд_дані_операція->операція = АСДОпераціяДАБО;
      асд_дані_операція->право = AAV(visitContext(ctx->value_expr));
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else {
      асд_дані_змінити_за_позицією->значення =
          AAV(visitContext(ctx->value_expr));
    }
    return AV(this, ctx, АСДВидЗмінитиЗаПозицією, асд_дані_змінити_за_позицією);
  }

  std::any MavkaASTVisitor::visitIf(MavkaParser::IfContext* ctx) {
    const auto асд_дані_якщо = new АСДДаніЯкщо();
    асд_дані_якщо->умова = AAV(visitContext(ctx->cond));
    if (ctx->ifok != nullptr) {
      асд_дані_якщо->тіло = AAVecToList(AAVec(visitBody(ctx->ifok)));
    } else {
      асд_дані_якщо->тіло = AAVecToList({});
    }
    if (ctx->ifnot != nullptr) {
      асд_дані_якщо->тіло_інакше = AAVecToList(AAVec(visitBody(ctx->ifnot)));
    } else if (ctx->ifnotif != nullptr) {
      асд_дані_якщо->тіло_інакше = AAVecToList({AAV(visitIf(ctx->ifnotif))});
    } else {
      асд_дані_якщо->тіло_інакше = AAVecToList({});
    }
    return AV(this, ctx, АСДВидЯкщо, асд_дані_якщо);
  }

  std::any MavkaASTVisitor::visitWhile(MavkaParser::WhileContext* ctx) {
    const auto асд_дані_поки = new АСДДаніПоки();
    асд_дані_поки->умова = AAV(visitContext(ctx->cond));
    if (ctx->body()) {
      асд_дані_поки->тіло = AAVecToList(AAVec(visitBody(ctx->body())));
    } else {
      асд_дані_поки->тіло = AAVecToList({});
    }
    return AV(this, ctx, АСДВидПоки, асд_дані_поки);
  }

  std::any MavkaASTVisitor::visitEach(MavkaParser::EachContext* ctx) {
    if (ctx->each_range()) {
      const auto асд_дані_перебрати_діапазон = new АСДДаніПеребратиДіапазон();
      if (ctx->each_range()->from->erv_atom) {
        асд_дані_перебрати_діапазон->від =
            AAV(visitContext(ctx->each_range()->from->erv_atom));
      } else if (ctx->each_range()->from->erv_number) {
        const auto асд_дані_число = new АСДДаніЧисло();
        асд_дані_число->значення =
            strdup(ctx->each_range()->from->erv_number->getText().c_str());
        асд_дані_перебрати_діапазон->від =
            AV(this, ctx, АСДВидЧисло, асд_дані_число);
      } else {
        std::cout << "Unknown each range from" << std::endl;
      }
      if (ctx->each_range()->incl) {
        асд_дані_перебрати_діапазон->включно = true;
      } else {
        асд_дані_перебрати_діапазон->включно = false;
      }
      if (ctx->each_range()->to->erv_atom) {
        асд_дані_перебрати_діапазон->до =
            AAV(visitContext(ctx->each_range()->to->erv_atom));
      } else if (ctx->each_range()->to->erv_number) {
        const auto асд_дані_число = new АСДДаніЧисло();
        асд_дані_число->значення =
            strdup(ctx->each_range()->to->erv_number->getText().c_str());
        асд_дані_перебрати_діапазон->до =
            AV(this, ctx, АСДВидЧисло, асд_дані_число);
      } else {
        std::cout << "Unknown each range to" << std::endl;
      }
      асд_дані_перебрати_діапазон->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      if (ctx->body()) {
        асд_дані_перебрати_діапазон->тіло =
            AAVecToList(AAVec(visitBody(ctx->body())));
      } else {
        асд_дані_перебрати_діапазон->тіло = AAVecToList({});
      }
      return AV(this, ctx, АСДВидПеребратиДіапазон,
                асд_дані_перебрати_діапазон);
    } else {
      const auto асд_дані_перебрати = new АСДДаніПеребрати();
      асд_дані_перебрати->предмет = AAV(visitContext(ctx->object));
      асд_дані_перебрати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      if (ctx->body()) {
        асд_дані_перебрати->тіло = AAVecToList(AAVec(visitBody(ctx->body())));
      } else {
        асд_дані_перебрати->тіло = AAVecToList({});
      }
      return AV(this, ctx, АСДВидПеребрати, асд_дані_перебрати);
    }
  }

  std::any MavkaASTVisitor::visitLoop(MavkaParser::LoopContext* ctx) {
    if (ctx->start) {
      const auto асд_дані_цикл = new АСДДаніЦикл();
      std::vector<АСДЗначення*> start;
      start.push_back(AAV(visitLoop_part(ctx->start)));
      асд_дані_цикл->старт = AAVecToList(start);
      асд_дані_цикл->умова = AAV(visitContext(ctx->cond));
      std::vector<АСДЗначення*> iter;
      iter.push_back(AAV(visitLoop_part(ctx->iter)));
      асд_дані_цикл->ітерація = AAVecToList(iter);
      if (ctx->body()) {
        асд_дані_цикл->тіло = AAVecToList(AAVec(visitBody(ctx->body())));
      } else {
        асд_дані_цикл->тіло = AAVecToList({});
      }
      return AV(this, ctx, АСДВидЦикл, асд_дані_цикл);
    } else {
      const auto асд_дані_вічний_цикл = new АСДДаніВічнийЦикл();
      if (ctx->body()) {
        асд_дані_вічний_цикл->тіло = AAVecToList(AAVec(visitBody(ctx->body())));
      } else {
        асд_дані_вічний_цикл->тіло = AAVecToList({});
      }
      return AV(this, ctx, АСДВидВічнийЦикл, асд_дані_вічний_цикл);
    }
  }

  std::any MavkaASTVisitor::visitLoop_part(MavkaParser::Loop_partContext* ctx) {
    if (ctx->assign() != nullptr) {
      return visitAssign(ctx->assign());
    }
    if (ctx->set() != nullptr) {
      return visitSet(ctx->set());
    }
    if (ctx->position_set() != nullptr) {
      return visitPosition_set(ctx->position_set());
    }
    if (ctx->expr() != nullptr) {
      return visitContext(ctx->expr());
    }
    std::cout << "Unknown loop part" << std::endl;
    return nullptr;
  }

  std::any MavkaASTVisitor::visitBody(MavkaParser::BodyContext* ctx) {
    std::vector<АСДЗначення*> elements;
    for (const auto& bodyElement : ctx->body_element()) {
      const auto any_асд = visitBody_element(bodyElement);
      elements.push_back(AAV(any_асд));
    }
    return elements;
  }

  std::any MavkaASTVisitor::visitBody_element(
      MavkaParser::Body_elementContext* ctx) {
    if (ctx->structure_define() != nullptr) {
      return visitStructure_define(ctx->structure_define());
    }
    if (ctx->diia_define() != nullptr) {
      return visitDiia_define(ctx->diia_define());
    }
    if (ctx->assign() != nullptr) {
      return visitAssign(ctx->assign());
    }
    if (ctx->set() != nullptr) {
      return visitSet(ctx->set());
    }
    if (ctx->position_set() != nullptr) {
      return visitPosition_set(ctx->position_set());
    }
    if (ctx->if_() != nullptr) {
      return visitIf(ctx->if_());
    }
    if (ctx->while_() != nullptr) {
      return visitWhile(ctx->while_());
    }
    if (ctx->each() != nullptr) {
      return visitEach(ctx->each());
    }
    if (ctx->loop() != nullptr) {
      return visitLoop(ctx->loop());
    }
    if (ctx->expr() != nullptr) {
      return visitContext(ctx->expr());
    }
    if (ctx->return_() != nullptr) {
      return visitReturn(ctx->return_());
    }
    if (ctx->take() != nullptr) {
      return visitTake(ctx->take());
    }
    if (ctx->try_() != nullptr) {
      return visitTry(ctx->try_());
    }
    if (ctx->throw_() != nullptr) {
      return visitThrow(ctx->throw_());
    }
    if (ctx->give() != nullptr) {
      return visitGive(ctx->give());
    }
    if (ctx->module() != nullptr) {
      return visitModule(ctx->module());
    }
    std::cout << "Unknown body element" << std::endl;
    return nullptr;
  }

  std::any MavkaASTVisitor::visitReturn(MavkaParser::ReturnContext* ctx) {
    const auto асд_дані_вернути = new АСДДаніВернути();
    if (ctx->value_expr) {
      асд_дані_вернути->значення = AAV(visitContext(ctx->value_expr));
    } else {
      асд_дані_вернути->значення = nullptr;
    }
    return AV(this, ctx, АСДВидВернути, асд_дані_вернути);
  }

  std::any MavkaASTVisitor::visitParam(MavkaParser::ParamContext* ctx) {
    const auto параметр = new Параметр();
    if (ctx->id) {
      параметр->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    } else {
      параметр->ідентифікатор = nullptr;
    }
    std::vector<АСДЗначення*> types;
    if (ctx->types()) {
      for (const auto& type : ctx->types()->type()) {
        types.push_back(AAV(visitContext(type)));
      }
    }
    параметр->кількість_типів = types.size();
    параметр->типи = VecToArr(types);
    if (ctx->expr()) {
      параметр->значення = AAV(visitContext(ctx->expr()));
    } else {
      параметр->значення = nullptr;
    }
    return параметр;
  }

  std::any MavkaASTVisitor::visitTake(MavkaParser::TakeContext* ctx) {
    const auto асд_дані_взяти = new АСДДаніВзяти();
    if (ctx->type_id) {
      асд_дані_взяти->тип = ІД(this, ctx->type_id, ctx->type_id->getText());
    } else {
      асд_дані_взяти->тип = nullptr;
    }
    std::vector<Ідентифікатор*> шлях;
    for (const auto& take_part : ctx->take_part()) {
      шлях.push_back(ІД(this, take_part, take_part->getText()));
    }
    асд_дані_взяти->довжина_шляху = шлях.size();
    асд_дані_взяти->шлях = VecToArr(шлях);
    if (ctx->as) {
      асд_дані_взяти->ідентифікатор_як = ІД(this, ctx->as, ctx->as->getText());
    } else {
      асд_дані_взяти->ідентифікатор_як = nullptr;
    }
    std::vector<ЕлементВзяти*> elements;
    for (const auto& element : ctx->take_element()) {
      const auto елемент_взяти = new ЕлементВзяти();
      елемент_взяти->ідентифікатор =
          ІД(this, element->id, element->id->getText());
      if (element->as) {
        елемент_взяти->ідентифікатор_як =
            ІД(this, element->as, element->as->getText());
      } else {
        елемент_взяти->ідентифікатор_як = nullptr;
      }
      елемент_взяти->місцезнаходження = LOC(this, element);
      elements.push_back(елемент_взяти);
    }
    асд_дані_взяти->кількість_елементів = elements.size();
    асд_дані_взяти->елементи = VecToArr(elements);
    return AV(this, ctx, АСДВидВзяти, асд_дані_взяти);
  }

  std::any MavkaASTVisitor::visitTry(MavkaParser::TryContext* ctx) {
    const auto асд_дані_спробувати = new АСДДаніСпробувати();
    if (ctx->t_body) {
      асд_дані_спробувати->тіло = AAVecToList(AAVec(visitBody(ctx->t_body)));
    } else {
      асд_дані_спробувати->тіло = AAVecToList({});
    }
    if (ctx->t_name) {
      асд_дані_спробувати->ідентифікатор_зловити =
          ІД(this, ctx->t_name, ctx->t_name->getText());
    } else {
      асд_дані_спробувати->ідентифікатор_зловити = nullptr;
    }
    if (ctx->t_catch_body) {
      асд_дані_спробувати->тіло_зловити =
          AAVecToList(AAVec(visitBody(ctx->t_catch_body)));
    } else {
      асд_дані_спробувати->тіло_зловити = AAVecToList({});
    }
    return AV(this, ctx, АСДВидСпробувати, асд_дані_спробувати);
  }

  std::any MavkaASTVisitor::visitThrow(MavkaParser::ThrowContext* ctx) {
    const auto асд_дані_впасти = new АСДДаніВпасти();
    if (ctx->t_value) {
      асд_дані_впасти->значення = AAV(visitContext(ctx->t_value));
    } else {
      асд_дані_впасти->значення = nullptr;
    }
    return AV(this, ctx, АСДВидВпасти, асд_дані_впасти);
  }

  std::any MavkaASTVisitor::visitGive(MavkaParser::GiveContext* ctx) {
    const auto асд_дані_дати = new АСДДаніДати();
    std::vector<ЕлементДати*> elements;
    for (const auto& element : ctx->give_element()) {
      const auto елемент_дати = new ЕлементДати();
      елемент_дати->ідентифікатор =
          ІД(this, element->id, element->id->getText());
      if (element->as) {
        елемент_дати->ідентифікатор_як =
            ІД(this, element->as, element->as->getText());
      } else {
        елемент_дати->ідентифікатор_як = nullptr;
      }
      елемент_дати->місцезнаходження = LOC(this, element);
      elements.push_back(елемент_дати);
    }
    асд_дані_дати->кількість_елементів = elements.size();
    асд_дані_дати->елементи = VecToArr(elements);
    return AV(this, ctx, АСДВидДати, асд_дані_дати);
  }

  std::any MavkaASTVisitor::visitModule(MavkaParser::ModuleContext* ctx) {
    const auto асд_дані_модуль = new АСДДаніМодуль();
    if (ctx->id) {
      асд_дані_модуль->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    } else {
      асд_дані_модуль->ідентифікатор = nullptr;
    }
    if (ctx->body_) {
      асд_дані_модуль->тіло = AAVecToList(AAVec(visitBody(ctx->body_)));
    } else {
      асд_дані_модуль->тіло = AAVecToList({});
    }
    return AV(this, ctx, АСДВидМодуль, асд_дані_модуль);
  }

  std::any MavkaASTVisitor::visitOperation_array(
      MavkaParser::Operation_arrayContext* ctx) {
    const auto асд_дані_список = new АСДДаніСписок();
    std::vector<АСДЗначення*> elements;
    for (const auto& element : ctx->expr()) {
      elements.push_back(AAV(visitContext(element)));
    }
    асд_дані_список->кількість_елементів = elements.size();
    асд_дані_список->елементи = VecToArr(elements);
    return AV(this, ctx, АСДВидСписок, асд_дані_список);
  }

  std::any MavkaASTVisitor::visitOperation_dict(
      MavkaParser::Operation_dictContext* ctx) {
    const auto асд_дані_словник = new АСДДаніСловник();
    std::vector<ЕлементСловника*> elements;
    for (const auto& element : ctx->dict_arg()) {
      const auto елемент_словника = new ЕлементСловника();
      if (element->key_number) {
        елемент_словника->ключ =
            AAV(visitNumberText(this, element->key_number));
      } else if (element->key_string) {
        if (element->key_string_tt != nullptr) {
          елемент_словника->ключ =
              AAV(visitStringText(this,
                                  ІД(this, element->key_string_tt,
                                     element->key_string_tt->getText()),
                                  element->key_string));
        } else {
          елемент_словника->ключ =
              AAV(visitStringText(this, nullptr, element->key_string));
        }
      } else {
        елемент_словника->ключ = nullptr;
      }
      елемент_словника->значення = AAV(visitContext(element->value));
      елемент_словника->місцезнаходження = LOC(this, element);
      elements.push_back(елемент_словника);
    }
    асд_дані_словник->кількість_елементів = elements.size();
    асд_дані_словник->елементи = VecToArr(elements);
    return AV(this, ctx, АСДВидСловник, асд_дані_словник);
  }

  std::any MavkaASTVisitor::visitOperation_dict_empty(
      MavkaParser::Operation_dict_emptyContext* ctx) {
    const auto асд_дані_словник = new АСДДаніСловник();
    асд_дані_словник->кількість_елементів = 0;
    std::vector<ЕлементСловника*> elements;
    асд_дані_словник->елементи = VecToArr(elements);
    return AV(this, ctx, АСДВидСловник, асд_дані_словник);
  }
} // namespace mavka::parser