
// Generated from MavkaParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MavkaParserVisitor.h"


/**
 * This class provides an empty implementation of MavkaParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MavkaParserBaseVisitor : public MavkaParserVisitor {
public:

  virtual std::any visitFile(MavkaParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram(MavkaParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_nested(MavkaParser::Atom_nestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_array(MavkaParser::Operation_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_string(MavkaParser::Operation_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_dict_empty(MavkaParser::Operation_dict_emptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_dict(MavkaParser::Operation_dictContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_get(MavkaParser::Atom_getContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_string_multiline(MavkaParser::Operation_string_multilineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_subject(MavkaParser::Atom_subjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_position_get(MavkaParser::Atom_position_getContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_symbol(MavkaParser::Operation_symbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_call(MavkaParser::Atom_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObject_arg(MavkaParser::Object_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDict_arg(MavkaParser::Dict_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_arg(MavkaParser::Call_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_pow(MavkaParser::Operation_powContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_gte(MavkaParser::Operation_gteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_neq(MavkaParser::Operation_neqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_xor(MavkaParser::Operation_xorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_lte(MavkaParser::Operation_lteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_pre_plus(MavkaParser::Operation_pre_plusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_add(MavkaParser::Operation_addContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_lt(MavkaParser::Operation_ltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_pre_minus(MavkaParser::Operation_pre_minusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_land(MavkaParser::Operation_landContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_or(MavkaParser::Operation_orContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_pre_not(MavkaParser::Operation_pre_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_contains(MavkaParser::Operation_containsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_delete_element(MavkaParser::Operation_delete_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_delete_prop(MavkaParser::Operation_delete_propContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_wait(MavkaParser::Operation_waitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_div_div(MavkaParser::Operation_div_divContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_not_is(MavkaParser::Operation_not_isContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_atom(MavkaParser::Operation_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_sub(MavkaParser::Operation_subContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_mod(MavkaParser::Operation_modContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_is(MavkaParser::Operation_isContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_mul(MavkaParser::Operation_mulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_gt(MavkaParser::Operation_gtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_eq(MavkaParser::Operation_eqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_delete_id(MavkaParser::Operation_delete_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_pre_bw_not(MavkaParser::Operation_pre_bw_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_lor(MavkaParser::Operation_lorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_ternary(MavkaParser::Operation_ternaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_urshift(MavkaParser::Operation_urshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_not_contains(MavkaParser::Operation_not_containsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_div(MavkaParser::Operation_divContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_rshift(MavkaParser::Operation_rshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_lshift(MavkaParser::Operation_lshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_number(MavkaParser::Operation_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation_and(MavkaParser::Operation_andContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_pow(MavkaParser::Op_powContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_div_div(MavkaParser::Op_div_divContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_lshift(MavkaParser::Op_lshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_rshift(MavkaParser::Op_rshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_urshift(MavkaParser::Op_urshiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_lt(MavkaParser::Op_ltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_lte(MavkaParser::Op_lteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_gt(MavkaParser::Op_gtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_gte(MavkaParser::Op_gteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_eq(MavkaParser::Op_eqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_neq(MavkaParser::Op_neqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_land(MavkaParser::Op_landContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_lor(MavkaParser::Op_lorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_not_contains(MavkaParser::Op_not_containsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_not_is(MavkaParser::Op_not_isContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGendef(MavkaParser::GendefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_operation(MavkaParser::Expr_operationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_diia(MavkaParser::Expr_diiaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_structure(MavkaParser::Expr_structureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(MavkaParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_define(MavkaParser::Structure_defineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_element(MavkaParser::Structure_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia_define(MavkaParser::Diia_defineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia_param(MavkaParser::Diia_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(MavkaParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_op(MavkaParser::Assign_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSet(MavkaParser::SetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPosition_set(MavkaParser::Position_setContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf(MavkaParser::IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile(MavkaParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEach(MavkaParser::EachContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEach_range_value(MavkaParser::Each_range_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEach_range(MavkaParser::Each_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoop_part(MavkaParser::Loop_partContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoop(MavkaParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody(MavkaParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody_element(MavkaParser::Body_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn(MavkaParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule(MavkaParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_get(MavkaParser::Type_getContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_nested(MavkaParser::Type_nestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_subject(MavkaParser::Type_subjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypes(MavkaParser::TypesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(MavkaParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTake(MavkaParser::TakeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTake_part(MavkaParser::Take_partContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTake_element(MavkaParser::Take_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGive(MavkaParser::GiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGive_element(MavkaParser::Give_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTry(MavkaParser::TryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThrow(MavkaParser::ThrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNl(MavkaParser::NlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNls(MavkaParser::NlsContext *ctx) override {
    return visitChildren(ctx);
  }


};

