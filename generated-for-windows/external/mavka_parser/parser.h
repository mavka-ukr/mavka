#pragma once

#ifndef MAVKA_PARSER_H
#define MAVKA_PARSER_H

#include <string>
#include <vector>

#include "syntax/antlr4-cpp-runtime/src/antlr4-runtime.h"
#include "syntax/generated/MavkaLexer.h"
#include "syntax/generated/MavkaParser.h"
#include "syntax/generated/MavkaParserBaseVisitor.h"
#include "tools.h"
#include "розбирач.h"

#define AAV(any) std::any_cast<АСДЗначення*>(any)
#define AAVec(any) (std::any_cast<std::vector<АСДЗначення*>>(any))

namespace mavka::parser {
  class MavkaASTVisitor;

  Місцезнаходження* LOC(MavkaASTVisitor* visitor,
                        antlr4::ParserRuleContext* context);
  Місцезнаходження* LOC(MavkaASTVisitor* visitor, antlr4::Token* token);

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

  СписокАСДЗначень* AAVecToList(std::vector<АСДЗначення*> vec);

  Ідентифікатор* ІД(MavkaASTVisitor* visitor,
                    antlr4::ParserRuleContext* context,
                    const std::string& значення);
  Ідентифікатор* ІД(MavkaASTVisitor* visitor,
                    antlr4::Token* token,
                    const std::string& значення);

  std::string АСДЗначенняВString(АСДЗначення* асд_значення, size_t глибина = 0);

  template <typename T>
  T* VecToArr(std::vector<T> vec) {
    T* arr = new T[vec.size()];
    for (size_t i = 0; i < vec.size(); i++) {
      arr[i] = vec[i];
    }
    return arr;
  }

  class MavkaASTVisitor final : public MavkaParserBaseVisitor {
   public:
    antlr4::CommonTokenStream* tokens = nullptr;
    ТекстКоду* текст_коду = nullptr;

    std::any visitContext(antlr4::ParserRuleContext* ctx);

    std::any visitFile(MavkaParser::FileContext* ctx) override;

    std::any visitProgram(MavkaParser::ProgramContext* ctx) override;

    std::any visitAtom_nested(MavkaParser::Atom_nestedContext* ctx) override;

    std::any visitAtom_subject(MavkaParser::Atom_subjectContext* ctx) override;

    std::any visitAtom_get(MavkaParser::Atom_getContext* ctx) override;

    std::any visitAtom_position_get(
        MavkaParser::Atom_position_getContext* ctx) override;

    std::any visitAtom_call(MavkaParser::Atom_callContext* ctx) override;

    std::any visitOperation_number(
        MavkaParser::Operation_numberContext* ctx) override;

    std::any visitOperation_string(
        MavkaParser::Operation_stringContext* ctx) override;

    std::any visitOperation_string_multiline(
        MavkaParser::Operation_string_multilineContext* ctx) override;

    std::any visitOperation_symbol(
        MavkaParser::Operation_symbolContext* ctx) override;

    std::any visitOperation_atom(
        MavkaParser::Operation_atomContext* ctx) override;

    std::any visitOperation_pre_not(
        MavkaParser::Operation_pre_notContext* ctx) override;

    std::any visitOperation_pre_bw_not(
        MavkaParser::Operation_pre_bw_notContext* ctx) override;

    std::any visitOperation_pre_plus(
        MavkaParser::Operation_pre_plusContext* ctx) override;

    std::any visitOperation_pre_minus(
        MavkaParser::Operation_pre_minusContext* ctx) override;

    std::any visitOperation_delete_id(
        MavkaParser::Operation_delete_idContext* ctx) override;

    std::any visitOperation_wait(
        MavkaParser::Operation_waitContext* ctx) override;

    std::any visitOperation_delete_prop(
        MavkaParser::Operation_delete_propContext* ctx) override;

    std::any visitOperation_delete_element(
        MavkaParser::Operation_delete_elementContext* ctx) override;

    std::any visitOperation_pow(
        MavkaParser::Operation_powContext* ctx) override;

    std::any visitOperation_mul(
        MavkaParser::Operation_mulContext* ctx) override;

    std::any visitOperation_div_div(
        MavkaParser::Operation_div_divContext* ctx) override;

    std::any visitOperation_div(
        MavkaParser::Operation_divContext* ctx) override;

    std::any visitOperation_mod(
        MavkaParser::Operation_modContext* ctx) override;

    std::any visitOperation_add(
        MavkaParser::Operation_addContext* ctx) override;

    std::any visitOperation_sub(
        MavkaParser::Operation_subContext* ctx) override;

    std::any visitOperation_lshift(
        MavkaParser::Operation_lshiftContext* ctx) override;

    std::any visitOperation_rshift(
        MavkaParser::Operation_rshiftContext* ctx) override;

    std::any visitOperation_urshift(
        MavkaParser::Operation_urshiftContext* ctx) override;

    std::any visitOperation_lt(MavkaParser::Operation_ltContext* ctx) override;

    std::any visitOperation_lte(
        MavkaParser::Operation_lteContext* ctx) override;

    std::any visitOperation_gt(MavkaParser::Operation_gtContext* ctx) override;

    std::any visitOperation_gte(
        MavkaParser::Operation_gteContext* ctx) override;

    std::any visitOperation_contains(
        MavkaParser::Operation_containsContext* ctx) override;

    std::any visitOperation_not_contains(
        MavkaParser::Operation_not_containsContext* ctx) override;

    std::any visitOperation_is(MavkaParser::Operation_isContext* ctx) override;

    std::any visitOperation_not_is(
        MavkaParser::Operation_not_isContext* ctx) override;

    std::any visitOperation_eq(MavkaParser::Operation_eqContext* ctx) override;

    std::any visitOperation_neq(
        MavkaParser::Operation_neqContext* ctx) override;

    std::any visitOperation_and(
        MavkaParser::Operation_andContext* ctx) override;

    std::any visitOperation_xor(
        MavkaParser::Operation_xorContext* ctx) override;

    std::any visitOperation_or(MavkaParser::Operation_orContext* ctx) override;

    std::any visitOperation_land(
        MavkaParser::Operation_landContext* ctx) override;

    std::any visitOperation_lor(
        MavkaParser::Operation_lorContext* ctx) override;

    std::any visitOperation_ternary(
        MavkaParser::Operation_ternaryContext* ctx) override;

    std::any visitExpr_operation(
        MavkaParser::Expr_operationContext* ctx) override;

    std::any visitExpr_diia(MavkaParser::Expr_diiaContext* ctx) override;

    std::any visitExpr_structure(
        MavkaParser::Expr_structureContext* ctx) override;

    std::any visitFunction(MavkaParser::FunctionContext* ctx) override;

    std::any visitStructure_define(
        MavkaParser::Structure_defineContext* ctx) override;

    std::any visitDiia_define(MavkaParser::Diia_defineContext* ctx) override;

    std::any visitAssign(MavkaParser::AssignContext* ctx) override;

    std::any visitSet(MavkaParser::SetContext* ctx) override;

    std::any visitPosition_set(MavkaParser::Position_setContext* ctx) override;

    std::any visitIf(MavkaParser::IfContext* ctx) override;

    std::any visitWhile(MavkaParser::WhileContext* ctx) override;

    std::any visitEach(MavkaParser::EachContext* ctx) override;

    std::any visitLoop(MavkaParser::LoopContext* ctx) override;

    std::any visitLoop_part(MavkaParser::Loop_partContext* ctx) override;

    std::any visitBody(MavkaParser::BodyContext* ctx) override;

    std::any visitBody_element(MavkaParser::Body_elementContext* ctx) override;

    std::any visitReturn(MavkaParser::ReturnContext* ctx) override;

    std::any visitParam(MavkaParser::ParamContext* ctx) override;

    std::any visitTake(MavkaParser::TakeContext* ctx) override;

    std::any visitTry(MavkaParser::TryContext* ctx) override;

    std::any visitThrow(MavkaParser::ThrowContext* ctx) override;

    std::any visitGive(MavkaParser::GiveContext* ctx) override;

    std::any visitModule(MavkaParser::ModuleContext* ctx) override;

    std::any visitOperation_array(
        MavkaParser::Operation_arrayContext* ctx) override;

    std::any visitOperation_dict(
        MavkaParser::Operation_dictContext* ctx) override;

    std::any visitOperation_dict_empty(
        MavkaParser::Operation_dict_emptyContext* ctx) override;
  };

  class MavkaParserErrorListener final : public antlr4::BaseErrorListener {
   public:
    std::vector<ПомилкаРозборуМавки*> errors;
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

struct РезультатРозборуТекстуМавки {
  size_t успіх;
  АСДЗначення* значення;
  ПомилкаРозборуМавки* помилка;
};

extern "C" РезультатРозборуТекстуМавки* розібрати_текст_мавки(
    ТекстКоду* текст_коду,
    Ідентифікатор* ідентифікатор,
    char* value,
    size_t startLine,
    size_t startColumn);
#endif // MAVKA_PARSER_H
