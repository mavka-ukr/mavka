#pragma once

#ifndef MAVKA_PARSER_H
#define MAVKA_PARSER_H

#include <string>
#include <vector>

#include "ast.h"
#include "syntax/MavkaLexer.h"
#include "syntax/MavkaParser.h"
#include "syntax/MavkaParserBaseVisitor.h"
#include "syntax/antlr4-cpp-runtime/src/antlr4-runtime.h"
#include "tools.h"

#define AAV(any) std::any_cast<АСДЗначення*>(any)
#define AAVec(any) (std::any_cast<std::vector<АСДЗначення*>>(any))

namespace mavka::parser {
  class MavkaASTVisitor;

  void FILL(MavkaASTVisitor* visitor,
            АСДЗначення* асд_значення,
            antlr4::ParserRuleContext* context);
  void FILL(MavkaASTVisitor* visitor,
            АСДЗначення* асд_значення,
            antlr4::Token* token);

  АСДЗначення* AV(MavkaASTVisitor* visitor, size_t kind, void* data);
  АСДЗначення* AV(MavkaASTVisitor* visitor,
                  antlr4::ParserRuleContext* context,
                  size_t kind,
                  void* data);
  АСДЗначення* AV(MavkaASTVisitor* visitor,
                  antlr4::Token* token,
                  size_t kind,
                  void* data);
  СписокАСДЗначень AAVecToList(std::vector<АСДЗначення*> vec);

  class MavkaASTVisitor final : public MavkaParserBaseVisitor {
   public:
    antlr4::CommonTokenStream* tokens = nullptr;
    ТекстКоду* текст_коду = nullptr;

    std::any visitContext(antlr4::ParserRuleContext* ctx);

    std::any visitNumber(MavkaParser::NumberContext* ctx) override;

    std::any visitString(MavkaParser::StringContext* ctx) override;

    std::any visitCharacter(MavkaParser::CharacterContext* ctx) override;

    std::any visitIdentifier(MavkaParser::IdentifierContext* ctx) override;

    std::any visitType(MavkaParser::TypeContext* ctx) override;

    std::any visitFile(MavkaParser::FileContext* ctx) override;

    std::any visitAssign(MavkaParser::AssignContext* ctx) override;

    std::any visitSet(MavkaParser::SetContext* ctx) override;

    std::any visitSet_by_access(
        MavkaParser::Set_by_accessContext* context) override;

    std::any visitStructure(MavkaParser::StructureContext* ctx) override;

    std::any visitDiia(MavkaParser::DiiaContext* ctx) override;

    std::any visitModule(MavkaParser::ModuleContext* ctx) override;

    std::any visitIf(MavkaParser::IfContext* ctx) override;

    std::any visitWhile(MavkaParser::WhileContext* ctx) override;

    std::any visitInterval(MavkaParser::IntervalContext* ctx) override;

    std::any visitCycle(MavkaParser::CycleContext* ctx) override;

    std::any visitTry(MavkaParser::TryContext* ctx) override;

    std::any visitThrow(MavkaParser::ThrowContext* ctx) override;

    std::any visitChain(MavkaParser::ChainContext* ctx) override;

    std::any visitTake(MavkaParser::TakeContext* ctx) override;

    std::any visitSubject(MavkaParser::SubjectContext* ctx) override;

    std::any visitIdentifierAsSubject(MavkaParser::IdentifierContext* ctx);

    std::any visitSubject_out(MavkaParser::Subject_outContext* ctx) override;

    std::any visitGet(MavkaParser::GetContext* ctx) override;

    std::any visitGet_out(MavkaParser::Get_outContext* ctx) override;

    std::any visitGeneric(MavkaParser::GenericContext* ctx) override;

    std::any visitGeneric_out(MavkaParser::Generic_outContext* ctx) override;

    std::any visitAccess(MavkaParser::AccessContext* ctx) override;

    std::any visitCall(MavkaParser::CallContext* ctx) override;

    std::any visitNested(MavkaParser::NestedContext* ctx) override;

    std::any visitNot(MavkaParser::NotContext* ctx) override;

    std::any visitNegative(MavkaParser::NegativeContext* ctx) override;

    std::any visitBitwise_not(MavkaParser::Bitwise_notContext* ctx) override;

    std::any visitArray(MavkaParser::ArrayContext* ctx) override;

    std::any visitDict(MavkaParser::DictContext* ctx) override;

    std::any visitMul(MavkaParser::MulContext* ctx) override;

    std::any visitAdd(MavkaParser::AddContext* ctx) override;

    std::any visitBitwise(MavkaParser::BitwiseContext* ctx) override;

    std::any visitComparison(MavkaParser::ComparisonContext* ctx) override;

    std::any visitLogical(MavkaParser::LogicalContext* ctx) override;

    std::any visitWait(MavkaParser::WaitContext* ctx) override;

    std::any visitAs(MavkaParser::AsContext* ctx) override;

    std::any visitGod(MavkaParser::GodContext* ctx) override;

    std::any visitFunction(MavkaParser::FunctionContext* ctx) override;

    std::any visitTernary(MavkaParser::TernaryContext* ctx) override;

    std::any visitGive(MavkaParser::GiveContext* ctx) override;

    std::any visitBody(MavkaParser::BodyContext* ctx) override;
  };

  class MavkaParserErrorListener final : public antlr4::BaseErrorListener {
   public:
    std::vector<ПомилкаРозборуМавки> errors;
    ТекстКоду* текст_коду = nullptr;

    void syntaxError(antlr4::Recognizer* recognizer,
                     antlr4::Token* offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string& msg,
                     std::exception_ptr e) override;

    void reportAmbiguity(antlr4::Parser* recognizer,
                         const antlr4::dfa::DFA& dfa,
                         size_t startIndex,
                         size_t stopIndex,
                         bool exact,
                         const antlrcpp::BitSet& ambigAlts,
                         antlr4::atn::ATNConfigSet* configs) override;

    void reportAttemptingFullContext(
        antlr4::Parser* recognizer,
        const antlr4::dfa::DFA& dfa,
        size_t startIndex,
        size_t stopIndex,
        const antlrcpp::BitSet& conflictingAlts,
        antlr4::atn::ATNConfigSet* configs) override;

    void reportContextSensitivity(antlr4::Parser* recognizer,
                                  const antlr4::dfa::DFA& dfa,
                                  size_t startIndex,
                                  size_t stopIndex,
                                  size_t prediction,
                                  antlr4::atn::ATNConfigSet* configs) override;
  };
} // namespace mavka::parser
#endif // MAVKA_PARSER_H
