#include "parser.h"

namespace mavka::parser {
  Місцезнаходження* LOC(MavkaASTVisitor* visitor,
                        antlr4::ParserRuleContext* context) {
    const auto місцезнаходження = new Місцезнаходження();
    місцезнаходження->текст_коду = visitor->текст_коду;
    місцезнаходження->рядок = context->getStart()->getLine();
    місцезнаходження->стовпець =
        context->getStart()->getCharPositionInLine() + 1;
    return місцезнаходження;
  }

  Місцезнаходження* LOC(MavkaASTVisitor* visitor, antlr4::Token* token) {
    const auto місцезнаходження = new Місцезнаходження();
    місцезнаходження->текст_коду = visitor->текст_коду;
    місцезнаходження->рядок = token->getLine();
    місцезнаходження->стовпець = token->getCharPositionInLine() + 1;
    return місцезнаходження;
  }

  void FILL(MavkaASTVisitor* visitor,
            АСДЗначення* асд_значення,
            antlr4::ParserRuleContext* context) {
    асд_значення->місцезнаходження = LOC(visitor, context);
  }

  void FILL(MavkaASTVisitor* visitor,
            АСДЗначення* асд_значення,
            antlr4::Token* token) {
    асд_значення->місцезнаходження = LOC(visitor, token);
  }

  АСДЗначення* AV(MavkaASTVisitor* visitor, size_t kind, void* data) {
    const auto асд_значення = new АСДЗначення();
    асд_значення->вид = kind;
    асд_значення->дані = data;
    return асд_значення;
  }

  АСДЗначення* AV(MavkaASTVisitor* visitor,
                  antlr4::ParserRuleContext* context,
                  size_t kind,
                  void* data) {
    const auto асд_значення = new АСДЗначення();
    FILL(visitor, асд_значення, context);
    асд_значення->вид = kind;
    асд_значення->дані = data;
    return асд_значення;
  }

  АСДЗначення* AV(MavkaASTVisitor* visitor,
                  antlr4::Token* token,
                  size_t kind,
                  void* data) {
    const auto асд_значення = new АСДЗначення();
    FILL(visitor, асд_значення, token);
    асд_значення->вид = kind;
    асд_значення->дані = data;
    return асд_значення;
  }

  СписокАСДЗначень* AAVecToList(std::vector<АСДЗначення*> vec) {
    const auto elements = new АСДЗначення*[vec.size()];
    for (size_t i = 0; i < vec.size(); i++) {
      elements[i] = vec[i];
    }
    return new СписокАСДЗначень{.довжина = vec.size(), .елементи = elements};
  }

  Ідентифікатор* ІД(MavkaASTVisitor* visitor,
                    antlr4::ParserRuleContext* context,
                    const std::string& значення) {
    const auto ідентифікатор = new Ідентифікатор();
    ідентифікатор->значення = strdup(значення.c_str());
    ідентифікатор->місцезнаходження = LOC(visitor, context);
    return ідентифікатор;
  }

  Ідентифікатор* ІД(MavkaASTVisitor* visitor,
                    antlr4::Token* token,
                    const std::string& значення) {
    const auto ідентифікатор = new Ідентифікатор();
    ідентифікатор->значення = strdup(значення.c_str());
    ідентифікатор->місцезнаходження = LOC(visitor, token);
    return ідентифікатор;
  }

  std::string повторити_пробіл(size_t кількість) {
    std::string r;
    for (size_t i = 0; i < кількість; ++i) {
      r += " ";
    }
    return r;
  }

  std::string АСДЗначенняВString(АСДЗначення* асд_значення, size_t глибина) {
    return "Невідомо";
  }

  void MavkaParserErrorListener::syntaxError(antlr4::Recognizer* recognizer,
                                            antlr4::Token* offendingSymbol,
                                            size_t line,
                                            size_t charPositionInLine,
                                            const std::string& msg,
                                            std::exception_ptr e) {
    const auto error = new ПомилкаРозборуМавки();
    error->місцезнаходження = new Місцезнаходження();
    error->місцезнаходження->текст_коду = this->текст_коду;
    error->місцезнаходження->рядок = line;
    error->місцезнаходження->стовпець = charPositionInLine;
    error->повідомлення = strdup(msg.c_str());
    this->errors.push_back(error);
  }

  void MavkaParserErrorListener::reportAmbiguity(
      antlr4::Parser* recognizer,
      const antlr4::dfa::DFA& dfa,
      size_t startIndex,
      size_t stopIndex,
      bool exact,
      const antlrcpp::BitSet& ambigAlts,
      antlr4::atn::ATNConfigSet* configs) {}

  void MavkaParserErrorListener::reportAttemptingFullContext(
      antlr4::Parser* recognizer,
      const antlr4::dfa::DFA& dfa,
      size_t startIndex,
      size_t stopIndex,
      const antlrcpp::BitSet& conflictingAlts,
      antlr4::atn::ATNConfigSet* configs) {}

  void MavkaParserErrorListener::reportContextSensitivity(
      antlr4::Parser* recognizer,
      const antlr4::dfa::DFA& dfa,
      size_t startIndex,
      size_t stopIndex,
      size_t prediction,
      antlr4::atn::ATNConfigSet* configs) {}
} // namespace mavka::parser

extern "C" РезультатРозборуМавки* розібрати_мавку(ТекстКоду* текст_коду) {
  antlr4::ANTLRInputStream input(текст_коду->значення);

  const auto lexer_error_listener =
      new mavka::parser::MavkaParserErrorListener();
  lexer_error_listener->текст_коду = текст_коду;
  MavkaLexer lexer(&input);
  lexer.removeErrorListeners();
  lexer.addErrorListener(lexer_error_listener);

  antlr4::CommonTokenStream tokens(&lexer);

  if (!lexer_error_listener->errors.empty()) {
    const auto error = lexer_error_listener->errors[0];
    delete lexer_error_listener;
    return new РезультатРозборуМавки{false, {}, error};
  }

  const auto parser_error_listener =
      new mavka::parser::MavkaParserErrorListener();
  parser_error_listener->текст_коду = текст_коду;
  MavkaParser parser(&tokens);
  parser.removeParseListeners();
  parser.removeErrorListeners();
  parser.addErrorListener(parser_error_listener);

  MavkaParser::FileContext* tree = parser.file();

  if (!parser_error_listener->errors.empty()) {
    const auto error = parser_error_listener->errors[0];
    delete lexer_error_listener;
    delete parser_error_listener;
    return new РезультатРозборуМавки{false, {}, error};
  }

  const auto visitor = new mavka::parser::MavkaASTVisitor();
  visitor->tokens = &tokens;
  visitor->текст_коду = текст_коду;

  const auto body = AAVec(visitor->visitFile(tree));
  const auto elements = new АСДЗначення*[body.size()];
  for (size_t i = 0; i < body.size(); i++) {
    elements[i] = body[i];
  }

  delete lexer_error_listener;
  delete parser_error_listener;
  delete visitor;

  return new РезультатРозборуМавки{
      true, new СписокАСДЗначень{.довжина = body.size(), .елементи = elements},
      nullptr};

} // namespace mavka::parser

extern "C" char* код_операції_в_юнікод(size_t операція) {
  if (операція == АСДОпераціяМноження) {
    return "*";
  }
  if (операція == АСДОпераціяДілення) {
    return "/";
  }
  if (операція == АСДОпераціяМодуль) {
    return "%";
  }
  if (операція == АСДОпераціяДодавання) {
    return "+";
  }
  if (операція == АСДОпераціяВіднімання) {
    return "-";
  }
  if (операція == АСДОпераціяЗсувВліво) {
    return "<<";
  }
  if (операція == АСДОпераціяЗсувВправо) {
    return ">>";
  }
  if (операція == АСДОпераціяЗсувВправоЗнаковий) {
    return ">>>";
  }
  if (операція == АСДОпераціяМенше) {
    return "<";
  }
  if (операція == АСДОпераціяБільше) {
    return ">";
  }
  if (операція == АСДОпераціяМеншеРівне) {
    return "<=";
  }
  if (операція == АСДОпераціяБільшеРівне) {
    return ">=";
  }
  if (операція == АСДОпераціяРівне) {
    return "==";
  }
  if (операція == АСДОпераціяНерівне) {
    return "!=";
  }
  if (операція == АСДОпераціяДІ) {
    return "&";
  }
  if (операція == АСДОпераціяВАБО) {
    return "^";
  }
  if (операція == АСДОпераціяДАБО) {
    return "|";
  }
  if (операція == АСДОпераціяІ) {
    return "&&";
  }
  if (операція == АСДОпераціяАБО) {
    return "||";
  }
  return "НЕВІДОМА_ОПЕРАЦІЯ";
}