#include "parser.h"

namespace mavka::parser {
  void FILL(MavkaASTVisitor* visitor,
            АСДЗначення* асд_значення,
            antlr4::ParserRuleContext* context) {
    асд_значення->місцезнаходження = new Місцезнаходження();
    асд_значення->місцезнаходження->текст_коду = visitor->текст_коду;
    асд_значення->місцезнаходження->рядок = context->getStart()->getLine();
    асд_значення->місцезнаходження->стовпець =
        context->getStart()->getCharPositionInLine() + 1;
  }

  void FILL(MavkaASTVisitor* visitor,
            АСДЗначення* асд_значення,
            antlr4::Token* token) {
    асд_значення->місцезнаходження = new Місцезнаходження();
    асд_значення->місцезнаходження->текст_коду = visitor->текст_коду;
    асд_значення->місцезнаходження->рядок = token->getLine();
    асд_значення->місцезнаходження->стовпець =
        token->getCharPositionInLine() + 1;
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

  СписокАСДЗначень AAVecToList(std::vector<АСДЗначення*> vec) {
    const auto elements = new АСДЗначення*[vec.size()];
    for (size_t i = 0; i < vec.size(); i++) {
      elements[i] = vec[i];
    }
    return СписокАСДЗначень{.розмір = vec.size(), .елементи = elements};
  }

  std::any MavkaASTVisitor::visitContext(antlr4::ParserRuleContext* context) {
    if (const auto number_context =
            dynamic_cast<MavkaParser::NumberContext*>(context)) {
      return visitNumber(number_context);
    }
    if (const auto string_context =
            dynamic_cast<MavkaParser::StringContext*>(context)) {
      return visitString(string_context);
    }
    if (const auto character_context =
            dynamic_cast<MavkaParser::CharacterContext*>(context)) {
      return visitCharacter(character_context);
    }
    if (const auto identifier_context =
            dynamic_cast<MavkaParser::IdentifierContext*>(context)) {
      return visitIdentifier(identifier_context);
    }
    if (const auto type_context =
            dynamic_cast<MavkaParser::TypeContext*>(context)) {
      return visitType(type_context);
    }
    if (const auto file_context =
            dynamic_cast<MavkaParser::FileContext*>(context)) {
      return visitFile(file_context);
    }
    if (const auto assign_context =
            dynamic_cast<MavkaParser::AssignContext*>(context)) {
      return visitAssign(assign_context);
    }
    if (const auto set_context =
            dynamic_cast<MavkaParser::SetContext*>(context)) {
      return visitSet(set_context);
    }
    if (const auto set_by_access_context =
            dynamic_cast<MavkaParser::Set_by_accessContext*>(context)) {
      return visitSet_by_access(set_by_access_context);
    }
    if (const auto structure_context =
            dynamic_cast<MavkaParser::StructureContext*>(context)) {
      return visitStructure(structure_context);
    }
    if (const auto diia_context =
            dynamic_cast<MavkaParser::DiiaContext*>(context)) {
      return visitDiia(diia_context);
    }
    if (const auto if_context =
            dynamic_cast<MavkaParser::IfContext*>(context)) {
      return visitIf(if_context);
    }
    if (const auto while_context =
            dynamic_cast<MavkaParser::WhileContext*>(context)) {
      return visitWhile(while_context);
    }
    if (const auto interval_context =
            dynamic_cast<MavkaParser::IntervalContext*>(context)) {
      return visitInterval(interval_context);
    }
    if (const auto cycle_context =
            dynamic_cast<MavkaParser::CycleContext*>(context)) {
      return visitCycle(cycle_context);
    }
    if (const auto try_context =
            dynamic_cast<MavkaParser::TryContext*>(context)) {
      return visitTry(try_context);
    }
    if (const auto throw_context =
            dynamic_cast<MavkaParser::ThrowContext*>(context)) {
      return visitThrow(throw_context);
    }
    if (const auto subject_context =
            dynamic_cast<MavkaParser::SubjectContext*>(context)) {
      return visitSubject(subject_context);
    }
    if (const auto subject_out_context =
            dynamic_cast<MavkaParser::Subject_outContext*>(context)) {
      return visitSubject_out(subject_out_context);
    }
    if (const auto get_context =
            dynamic_cast<MavkaParser::GetContext*>(context)) {
      return visitGet(get_context);
    }
    if (const auto get_out_context =
            dynamic_cast<MavkaParser::Get_outContext*>(context)) {
      return visitGet_out(get_out_context);
    }
    if (const auto generic_context =
            dynamic_cast<MavkaParser::GenericContext*>(context)) {
      return visitGeneric(generic_context);
    }
    if (const auto generic_out_context =
            dynamic_cast<MavkaParser::Generic_outContext*>(context)) {
      return visitGeneric_out(generic_out_context);
    }
    if (const auto access_context =
            dynamic_cast<MavkaParser::AccessContext*>(context)) {
      return visitAccess(access_context);
    }
    if (const auto call_context =
            dynamic_cast<MavkaParser::CallContext*>(context)) {
      return visitCall(call_context);
    }
    if (const auto nested_context =
            dynamic_cast<MavkaParser::NestedContext*>(context)) {
      return visitNested(nested_context);
    }
    if (const auto atom_particle_context =
            dynamic_cast<MavkaParser::Atom_particleContext*>(context)) {
      return visitContext(atom_particle_context->particle());
    }
    if (const auto atom_number_context =
            dynamic_cast<MavkaParser::Atom_numberContext*>(context)) {
      return visitContext(atom_number_context->number());
    }
    if (const auto atom_string_context =
            dynamic_cast<MavkaParser::Atom_stringContext*>(context)) {
      return visitContext(atom_string_context->string());
    }
    if (const auto atom_character_context =
            dynamic_cast<MavkaParser::Atom_characterContext*>(context)) {
      return visitContext(atom_character_context->character());
    }
    if (const auto molecule_atom_context =
            dynamic_cast<MavkaParser::Molecule_atomContext*>(context)) {
      return visitContext(molecule_atom_context->atom());
    }
    if (const auto not_context =
            dynamic_cast<MavkaParser::NotContext*>(context)) {
      return visitNot(not_context);
    }
    if (const auto negative_context =
            dynamic_cast<MavkaParser::NegativeContext*>(context)) {
      return visitNegative(negative_context);
    }
    if (const auto bitwise_not_context =
            dynamic_cast<MavkaParser::Bitwise_notContext*>(context)) {
      return visitBitwise_not(bitwise_not_context);
    }
    if (const auto operation_molecule_context =
            dynamic_cast<MavkaParser::Operation_moleculeContext*>(context)) {
      return visitContext(operation_molecule_context->molecule());
    }
    if (const auto array_context =
            dynamic_cast<MavkaParser::ArrayContext*>(context)) {
      return visitArray(array_context);
    }
    if (const auto dict_context =
            dynamic_cast<MavkaParser::DictContext*>(context)) {
      return visitDict(dict_context);
    }
    if (const auto mul_context =
            dynamic_cast<MavkaParser::MulContext*>(context)) {
      return visitMul(mul_context);
    }
    if (const auto add_context =
            dynamic_cast<MavkaParser::AddContext*>(context)) {
      return visitAdd(add_context);
    }
    if (const auto bitwise_context =
            dynamic_cast<MavkaParser::BitwiseContext*>(context)) {
      return visitBitwise(bitwise_context);
    }
    if (const auto comparison_context =
            dynamic_cast<MavkaParser::ComparisonContext*>(context)) {
      return visitComparison(comparison_context);
    }
    if (const auto logical_context =
            dynamic_cast<MavkaParser::LogicalContext*>(context)) {
      return visitLogical(logical_context);
    }
    if (const auto wait_context =
            dynamic_cast<MavkaParser::WaitContext*>(context)) {
      return visitWait(wait_context);
    }
    if (const auto as_context =
            dynamic_cast<MavkaParser::AsContext*>(context)) {
      return visitAs(as_context);
    }
    if (const auto god_context =
            dynamic_cast<MavkaParser::GodContext*>(context)) {
      return visitGod(god_context);
    }
    if (const auto expr_structure_context =
            dynamic_cast<MavkaParser::Expr_structureContext*>(context)) {
      return visitStructure(expr_structure_context->structure());
    }
    if (const auto expr_diia_context =
            dynamic_cast<MavkaParser::Expr_diiaContext*>(context)) {
      return visitDiia(expr_diia_context->diia());
    }
    if (const auto expr_module_context =
            dynamic_cast<MavkaParser::Expr_moduleContext*>(context)) {
      return visitModule(expr_module_context->module());
    }
    if (const auto expr_operation_context =
            dynamic_cast<MavkaParser::Expr_operationContext*>(context)) {
      return visitContext(expr_operation_context->operation());
    }
    if (const auto function_context =
            dynamic_cast<MavkaParser::FunctionContext*>(context)) {
      return visitFunction(function_context);
    }
    if (const auto ternary_context =
            dynamic_cast<MavkaParser::TernaryContext*>(context)) {
      return visitTernary(ternary_context);
    }
    if (const auto give_context =
            dynamic_cast<MavkaParser::GiveContext*>(context)) {
      return visitGive(give_context);
    }
    if (const auto body_context =
            dynamic_cast<MavkaParser::BodyContext*>(context)) {
      return visitBody(body_context);
    }
    return nullptr;
  }

  void MavkaParserErrorListener::syntaxError(antlr4::Recognizer* recognizer,
                                             antlr4::Token* offendingSymbol,
                                             size_t line,
                                             size_t charPositionInLine,
                                             const std::string& msg,
                                             std::exception_ptr e) {
    ПомилкаРозборуМавки error{};
    error.місцезнаходження = new Місцезнаходження();
    error.місцезнаходження->текст_коду = this->текст_коду;
    error.місцезнаходження->рядок = line;
    error.місцезнаходження->стовпець = charPositionInLine;
    error.повідомлення = strdup(msg.c_str());
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

extern "C" РезультатРозборуМавки розібрати_мавку(ТекстКоду* текст_коду) {
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
    return РезультатРозборуМавки{false, {}, error};
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
    return РезультатРозборуМавки{false, {}, error};
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

  return РезультатРозборуМавки{
      true, {.розмір = body.size(), .елементи = elements}, {}};
}

extern "C" РезультатРозборуТекстуМавки розібрати_текст_мавки(
    ТекстКоду* текст_коду,
    char* value,
    size_t startLine,
    size_t startColumn) {
  std::string string_value = value;
  const auto місцезнаходження = new Місцезнаходження();
  місцезнаходження->текст_коду = текст_коду;
  місцезнаходження->рядок = startLine;
  місцезнаходження->стовпець = startColumn;
  const std::string INTERPOL_START = "%(";
  const std::string INTERPOL_END = ")";
  enum TValueType {
    TValueTypeText,
    TValueTypeInterpol,
  };
  struct TValue {
    TValueType type;
    std::string value;
  };
  std::vector<АСДЗначення*> elements;
  std::string current_part;
  bool interpolation = false;
  for (int i = 0; i < string_value.length(); ++i) {
    if (!interpolation &&
        mavka::parser::tools::safe_substr(value, i, 1) == "%" &&
        mavka::parser::tools::safe_substr(value, i + 1, 1) == "(") {
      interpolation = true;
      if (!current_part.empty()) {
        const auto створити_текст_асд_дані = new СтворитиТекстАСДДані();
        створити_текст_асд_дані->значення = strdup(current_part.c_str());
        створити_текст_асд_дані->інтерпольовано = true;
        const auto асд_значення = new АСДЗначення();
        асд_значення->місцезнаходження = місцезнаходження;
        асд_значення->вид = АСДВидСтворитиТекст;
        асд_значення->дані = створити_текст_асд_дані;
        elements.push_back(асд_значення);
        current_part = "";
      }
      i += 1;
      continue;
    }
    if (interpolation &&
        mavka::parser::tools::safe_substr(value, i, 1) == ")") {
      interpolation = false;
      auto temp_текст_коду = ТекстКоду{};
      temp_текст_коду.шлях = текст_коду->шлях;
      temp_текст_коду.значення = strdup(current_part.c_str());
      auto parse_result = розібрати_мавку(&temp_текст_коду);
      if (parse_result.успіх == false) {
        parse_result.помилка.місцезнаходження = місцезнаходження;
        return РезультатРозборуТекстуМавки{false, {}, parse_result.помилка};
      }
      const auto текст_ідентифікатор_асд_дані = new ІдентифікаторАСДДані();
      текст_ідентифікатор_асд_дані->назва = "текст";
      const auto текст_ідентифікатор_асд_значення = new АСДЗначення();
      текст_ідентифікатор_асд_значення->вид = АСДВидІдентифікатор;
      текст_ідентифікатор_асд_значення->дані = текст_ідентифікатор_асд_дані;
      текст_ідентифікатор_асд_значення->місцезнаходження = місцезнаходження;
      const auto звернутись_до_субʼєкта_асд_дані =
          new ЗвернутисьДоСубʼєктаАСДДані();
      звернутись_до_субʼєкта_асд_дані->ідентифікатор =
          текст_ідентифікатор_асд_значення;
      const auto звернутись_до_субʼєкта_асд_значення = new АСДЗначення();
      звернутись_до_субʼєкта_асд_значення->вид = АСДВидЗвернутисьДоСубʼєкта;
      звернутись_до_субʼєкта_асд_значення->дані =
          звернутись_до_субʼєкта_асд_дані;
      звернутись_до_субʼєкта_асд_значення->місцезнаходження = місцезнаходження;
      const auto виконати_дію_асд_дані = new ВиконатиДіюАСДДані();
      виконати_дію_асд_дані->субʼєкт = звернутись_до_субʼєкта_асд_значення;
      виконати_дію_асд_дані->аргументи =
          mavka::parser::AAVecToList({parse_result.тіло.елементи[0]});
      const auto виконати_дію_асд_значення = new АСДЗначення();
      виконати_дію_асд_значення->вид = АСДВидВиконатиДію;
      виконати_дію_асд_значення->дані = виконати_дію_асд_дані;
      виконати_дію_асд_значення->місцезнаходження = місцезнаходження;
      elements.push_back(виконати_дію_асд_значення);
      current_part = "";
      continue;
    }
    current_part += mavka::parser::tools::safe_substr(value, i, 1);
  }
  if (!current_part.empty()) {
    const auto створити_текст_асд_дані = new СтворитиТекстАСДДані();
    створити_текст_асд_дані->значення = strdup(current_part.c_str());
    створити_текст_асд_дані->інтерпольовано = true;
    const auto створити_текст_асд_значення = new АСДЗначення();
    створити_текст_асд_значення->місцезнаходження = місцезнаходження;
    створити_текст_асд_значення->вид = АСДВидСтворитиТекст;
    створити_текст_асд_значення->дані = створити_текст_асд_дані;
    elements.push_back(створити_текст_асд_значення);
  }
  if (elements.empty()) {
    const auto створити_текст_асд_дані = new СтворитиТекстАСДДані();
    створити_текст_асд_дані->значення = "";
    створити_текст_асд_дані->інтерпольовано = true;
    const auto створити_текст_асд_значення = new АСДЗначення();
    створити_текст_асд_значення->місцезнаходження = місцезнаходження;
    створити_текст_асд_значення->вид = АСДВидСтворитиТекст;
    створити_текст_асд_значення->дані = створити_текст_асд_дані;
    return РезультатРозборуТекстуМавки{true, створити_текст_асд_значення, {}};
  }
  АСДЗначення* left = elements[0];
  for (int i = 1; i < elements.size(); ++i) {
    left = new АСДЗначення{
        .вид = АСДВидОперація,
        .дані =
            new ОпераціяАСДДані{
                .ліво = left,
                .операція = ОпераціяДодати,
                .право = elements[i],
            },
        .місцезнаходження = місцезнаходження,
    };
  }
  return РезультатРозборуТекстуМавки{true, left, {}};
}
