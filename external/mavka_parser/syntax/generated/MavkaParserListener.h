
// Generated from MavkaParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MavkaParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MavkaParser.
 */
class  MavkaParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(MavkaParser::FileContext *ctx) = 0;
  virtual void exitFile(MavkaParser::FileContext *ctx) = 0;

  virtual void enterProgram(MavkaParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(MavkaParser::ProgramContext *ctx) = 0;

  virtual void enterAtom_nested(MavkaParser::Atom_nestedContext *ctx) = 0;
  virtual void exitAtom_nested(MavkaParser::Atom_nestedContext *ctx) = 0;

  virtual void enterOperation_array(MavkaParser::Operation_arrayContext *ctx) = 0;
  virtual void exitOperation_array(MavkaParser::Operation_arrayContext *ctx) = 0;

  virtual void enterOperation_string(MavkaParser::Operation_stringContext *ctx) = 0;
  virtual void exitOperation_string(MavkaParser::Operation_stringContext *ctx) = 0;

  virtual void enterOperation_dict_empty(MavkaParser::Operation_dict_emptyContext *ctx) = 0;
  virtual void exitOperation_dict_empty(MavkaParser::Operation_dict_emptyContext *ctx) = 0;

  virtual void enterOperation_dict(MavkaParser::Operation_dictContext *ctx) = 0;
  virtual void exitOperation_dict(MavkaParser::Operation_dictContext *ctx) = 0;

  virtual void enterAtom_get(MavkaParser::Atom_getContext *ctx) = 0;
  virtual void exitAtom_get(MavkaParser::Atom_getContext *ctx) = 0;

  virtual void enterOperation_string_multiline(MavkaParser::Operation_string_multilineContext *ctx) = 0;
  virtual void exitOperation_string_multiline(MavkaParser::Operation_string_multilineContext *ctx) = 0;

  virtual void enterAtom_subject(MavkaParser::Atom_subjectContext *ctx) = 0;
  virtual void exitAtom_subject(MavkaParser::Atom_subjectContext *ctx) = 0;

  virtual void enterAtom_position_get(MavkaParser::Atom_position_getContext *ctx) = 0;
  virtual void exitAtom_position_get(MavkaParser::Atom_position_getContext *ctx) = 0;

  virtual void enterOperation_symbol(MavkaParser::Operation_symbolContext *ctx) = 0;
  virtual void exitOperation_symbol(MavkaParser::Operation_symbolContext *ctx) = 0;

  virtual void enterAtom_call(MavkaParser::Atom_callContext *ctx) = 0;
  virtual void exitAtom_call(MavkaParser::Atom_callContext *ctx) = 0;

  virtual void enterObject_arg(MavkaParser::Object_argContext *ctx) = 0;
  virtual void exitObject_arg(MavkaParser::Object_argContext *ctx) = 0;

  virtual void enterDict_arg(MavkaParser::Dict_argContext *ctx) = 0;
  virtual void exitDict_arg(MavkaParser::Dict_argContext *ctx) = 0;

  virtual void enterCall_arg(MavkaParser::Call_argContext *ctx) = 0;
  virtual void exitCall_arg(MavkaParser::Call_argContext *ctx) = 0;

  virtual void enterOperation_pow(MavkaParser::Operation_powContext *ctx) = 0;
  virtual void exitOperation_pow(MavkaParser::Operation_powContext *ctx) = 0;

  virtual void enterOperation_gte(MavkaParser::Operation_gteContext *ctx) = 0;
  virtual void exitOperation_gte(MavkaParser::Operation_gteContext *ctx) = 0;

  virtual void enterOperation_neq(MavkaParser::Operation_neqContext *ctx) = 0;
  virtual void exitOperation_neq(MavkaParser::Operation_neqContext *ctx) = 0;

  virtual void enterOperation_xor(MavkaParser::Operation_xorContext *ctx) = 0;
  virtual void exitOperation_xor(MavkaParser::Operation_xorContext *ctx) = 0;

  virtual void enterOperation_lte(MavkaParser::Operation_lteContext *ctx) = 0;
  virtual void exitOperation_lte(MavkaParser::Operation_lteContext *ctx) = 0;

  virtual void enterOperation_pre_plus(MavkaParser::Operation_pre_plusContext *ctx) = 0;
  virtual void exitOperation_pre_plus(MavkaParser::Operation_pre_plusContext *ctx) = 0;

  virtual void enterOperation_add(MavkaParser::Operation_addContext *ctx) = 0;
  virtual void exitOperation_add(MavkaParser::Operation_addContext *ctx) = 0;

  virtual void enterOperation_lt(MavkaParser::Operation_ltContext *ctx) = 0;
  virtual void exitOperation_lt(MavkaParser::Operation_ltContext *ctx) = 0;

  virtual void enterOperation_pre_minus(MavkaParser::Operation_pre_minusContext *ctx) = 0;
  virtual void exitOperation_pre_minus(MavkaParser::Operation_pre_minusContext *ctx) = 0;

  virtual void enterOperation_land(MavkaParser::Operation_landContext *ctx) = 0;
  virtual void exitOperation_land(MavkaParser::Operation_landContext *ctx) = 0;

  virtual void enterOperation_or(MavkaParser::Operation_orContext *ctx) = 0;
  virtual void exitOperation_or(MavkaParser::Operation_orContext *ctx) = 0;

  virtual void enterOperation_pre_not(MavkaParser::Operation_pre_notContext *ctx) = 0;
  virtual void exitOperation_pre_not(MavkaParser::Operation_pre_notContext *ctx) = 0;

  virtual void enterOperation_contains(MavkaParser::Operation_containsContext *ctx) = 0;
  virtual void exitOperation_contains(MavkaParser::Operation_containsContext *ctx) = 0;

  virtual void enterOperation_delete_element(MavkaParser::Operation_delete_elementContext *ctx) = 0;
  virtual void exitOperation_delete_element(MavkaParser::Operation_delete_elementContext *ctx) = 0;

  virtual void enterOperation_delete_prop(MavkaParser::Operation_delete_propContext *ctx) = 0;
  virtual void exitOperation_delete_prop(MavkaParser::Operation_delete_propContext *ctx) = 0;

  virtual void enterOperation_wait(MavkaParser::Operation_waitContext *ctx) = 0;
  virtual void exitOperation_wait(MavkaParser::Operation_waitContext *ctx) = 0;

  virtual void enterOperation_div_div(MavkaParser::Operation_div_divContext *ctx) = 0;
  virtual void exitOperation_div_div(MavkaParser::Operation_div_divContext *ctx) = 0;

  virtual void enterOperation_not_is(MavkaParser::Operation_not_isContext *ctx) = 0;
  virtual void exitOperation_not_is(MavkaParser::Operation_not_isContext *ctx) = 0;

  virtual void enterOperation_atom(MavkaParser::Operation_atomContext *ctx) = 0;
  virtual void exitOperation_atom(MavkaParser::Operation_atomContext *ctx) = 0;

  virtual void enterOperation_sub(MavkaParser::Operation_subContext *ctx) = 0;
  virtual void exitOperation_sub(MavkaParser::Operation_subContext *ctx) = 0;

  virtual void enterOperation_mod(MavkaParser::Operation_modContext *ctx) = 0;
  virtual void exitOperation_mod(MavkaParser::Operation_modContext *ctx) = 0;

  virtual void enterOperation_is(MavkaParser::Operation_isContext *ctx) = 0;
  virtual void exitOperation_is(MavkaParser::Operation_isContext *ctx) = 0;

  virtual void enterOperation_mul(MavkaParser::Operation_mulContext *ctx) = 0;
  virtual void exitOperation_mul(MavkaParser::Operation_mulContext *ctx) = 0;

  virtual void enterOperation_gt(MavkaParser::Operation_gtContext *ctx) = 0;
  virtual void exitOperation_gt(MavkaParser::Operation_gtContext *ctx) = 0;

  virtual void enterOperation_eq(MavkaParser::Operation_eqContext *ctx) = 0;
  virtual void exitOperation_eq(MavkaParser::Operation_eqContext *ctx) = 0;

  virtual void enterOperation_delete_id(MavkaParser::Operation_delete_idContext *ctx) = 0;
  virtual void exitOperation_delete_id(MavkaParser::Operation_delete_idContext *ctx) = 0;

  virtual void enterOperation_pre_bw_not(MavkaParser::Operation_pre_bw_notContext *ctx) = 0;
  virtual void exitOperation_pre_bw_not(MavkaParser::Operation_pre_bw_notContext *ctx) = 0;

  virtual void enterOperation_lor(MavkaParser::Operation_lorContext *ctx) = 0;
  virtual void exitOperation_lor(MavkaParser::Operation_lorContext *ctx) = 0;

  virtual void enterOperation_ternary(MavkaParser::Operation_ternaryContext *ctx) = 0;
  virtual void exitOperation_ternary(MavkaParser::Operation_ternaryContext *ctx) = 0;

  virtual void enterOperation_urshift(MavkaParser::Operation_urshiftContext *ctx) = 0;
  virtual void exitOperation_urshift(MavkaParser::Operation_urshiftContext *ctx) = 0;

  virtual void enterOperation_not_contains(MavkaParser::Operation_not_containsContext *ctx) = 0;
  virtual void exitOperation_not_contains(MavkaParser::Operation_not_containsContext *ctx) = 0;

  virtual void enterOperation_div(MavkaParser::Operation_divContext *ctx) = 0;
  virtual void exitOperation_div(MavkaParser::Operation_divContext *ctx) = 0;

  virtual void enterOperation_rshift(MavkaParser::Operation_rshiftContext *ctx) = 0;
  virtual void exitOperation_rshift(MavkaParser::Operation_rshiftContext *ctx) = 0;

  virtual void enterOperation_lshift(MavkaParser::Operation_lshiftContext *ctx) = 0;
  virtual void exitOperation_lshift(MavkaParser::Operation_lshiftContext *ctx) = 0;

  virtual void enterOperation_number(MavkaParser::Operation_numberContext *ctx) = 0;
  virtual void exitOperation_number(MavkaParser::Operation_numberContext *ctx) = 0;

  virtual void enterOperation_and(MavkaParser::Operation_andContext *ctx) = 0;
  virtual void exitOperation_and(MavkaParser::Operation_andContext *ctx) = 0;

  virtual void enterOp_pow(MavkaParser::Op_powContext *ctx) = 0;
  virtual void exitOp_pow(MavkaParser::Op_powContext *ctx) = 0;

  virtual void enterOp_div_div(MavkaParser::Op_div_divContext *ctx) = 0;
  virtual void exitOp_div_div(MavkaParser::Op_div_divContext *ctx) = 0;

  virtual void enterOp_lshift(MavkaParser::Op_lshiftContext *ctx) = 0;
  virtual void exitOp_lshift(MavkaParser::Op_lshiftContext *ctx) = 0;

  virtual void enterOp_rshift(MavkaParser::Op_rshiftContext *ctx) = 0;
  virtual void exitOp_rshift(MavkaParser::Op_rshiftContext *ctx) = 0;

  virtual void enterOp_urshift(MavkaParser::Op_urshiftContext *ctx) = 0;
  virtual void exitOp_urshift(MavkaParser::Op_urshiftContext *ctx) = 0;

  virtual void enterOp_lt(MavkaParser::Op_ltContext *ctx) = 0;
  virtual void exitOp_lt(MavkaParser::Op_ltContext *ctx) = 0;

  virtual void enterOp_lte(MavkaParser::Op_lteContext *ctx) = 0;
  virtual void exitOp_lte(MavkaParser::Op_lteContext *ctx) = 0;

  virtual void enterOp_gt(MavkaParser::Op_gtContext *ctx) = 0;
  virtual void exitOp_gt(MavkaParser::Op_gtContext *ctx) = 0;

  virtual void enterOp_gte(MavkaParser::Op_gteContext *ctx) = 0;
  virtual void exitOp_gte(MavkaParser::Op_gteContext *ctx) = 0;

  virtual void enterOp_eq(MavkaParser::Op_eqContext *ctx) = 0;
  virtual void exitOp_eq(MavkaParser::Op_eqContext *ctx) = 0;

  virtual void enterOp_neq(MavkaParser::Op_neqContext *ctx) = 0;
  virtual void exitOp_neq(MavkaParser::Op_neqContext *ctx) = 0;

  virtual void enterOp_land(MavkaParser::Op_landContext *ctx) = 0;
  virtual void exitOp_land(MavkaParser::Op_landContext *ctx) = 0;

  virtual void enterOp_lor(MavkaParser::Op_lorContext *ctx) = 0;
  virtual void exitOp_lor(MavkaParser::Op_lorContext *ctx) = 0;

  virtual void enterOp_not_contains(MavkaParser::Op_not_containsContext *ctx) = 0;
  virtual void exitOp_not_contains(MavkaParser::Op_not_containsContext *ctx) = 0;

  virtual void enterOp_not_is(MavkaParser::Op_not_isContext *ctx) = 0;
  virtual void exitOp_not_is(MavkaParser::Op_not_isContext *ctx) = 0;

  virtual void enterGendef(MavkaParser::GendefContext *ctx) = 0;
  virtual void exitGendef(MavkaParser::GendefContext *ctx) = 0;

  virtual void enterExpr_operation(MavkaParser::Expr_operationContext *ctx) = 0;
  virtual void exitExpr_operation(MavkaParser::Expr_operationContext *ctx) = 0;

  virtual void enterExpr_diia(MavkaParser::Expr_diiaContext *ctx) = 0;
  virtual void exitExpr_diia(MavkaParser::Expr_diiaContext *ctx) = 0;

  virtual void enterExpr_structure(MavkaParser::Expr_structureContext *ctx) = 0;
  virtual void exitExpr_structure(MavkaParser::Expr_structureContext *ctx) = 0;

  virtual void enterFunction(MavkaParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(MavkaParser::FunctionContext *ctx) = 0;

  virtual void enterStructure_define(MavkaParser::Structure_defineContext *ctx) = 0;
  virtual void exitStructure_define(MavkaParser::Structure_defineContext *ctx) = 0;

  virtual void enterStructure_element(MavkaParser::Structure_elementContext *ctx) = 0;
  virtual void exitStructure_element(MavkaParser::Structure_elementContext *ctx) = 0;

  virtual void enterDiia_define(MavkaParser::Diia_defineContext *ctx) = 0;
  virtual void exitDiia_define(MavkaParser::Diia_defineContext *ctx) = 0;

  virtual void enterDiia_param(MavkaParser::Diia_paramContext *ctx) = 0;
  virtual void exitDiia_param(MavkaParser::Diia_paramContext *ctx) = 0;

  virtual void enterAssign(MavkaParser::AssignContext *ctx) = 0;
  virtual void exitAssign(MavkaParser::AssignContext *ctx) = 0;

  virtual void enterAssign_op(MavkaParser::Assign_opContext *ctx) = 0;
  virtual void exitAssign_op(MavkaParser::Assign_opContext *ctx) = 0;

  virtual void enterSet(MavkaParser::SetContext *ctx) = 0;
  virtual void exitSet(MavkaParser::SetContext *ctx) = 0;

  virtual void enterPosition_set(MavkaParser::Position_setContext *ctx) = 0;
  virtual void exitPosition_set(MavkaParser::Position_setContext *ctx) = 0;

  virtual void enterIf(MavkaParser::IfContext *ctx) = 0;
  virtual void exitIf(MavkaParser::IfContext *ctx) = 0;

  virtual void enterWhile(MavkaParser::WhileContext *ctx) = 0;
  virtual void exitWhile(MavkaParser::WhileContext *ctx) = 0;

  virtual void enterEach(MavkaParser::EachContext *ctx) = 0;
  virtual void exitEach(MavkaParser::EachContext *ctx) = 0;

  virtual void enterEach_range_value(MavkaParser::Each_range_valueContext *ctx) = 0;
  virtual void exitEach_range_value(MavkaParser::Each_range_valueContext *ctx) = 0;

  virtual void enterEach_range(MavkaParser::Each_rangeContext *ctx) = 0;
  virtual void exitEach_range(MavkaParser::Each_rangeContext *ctx) = 0;

  virtual void enterLoop_part(MavkaParser::Loop_partContext *ctx) = 0;
  virtual void exitLoop_part(MavkaParser::Loop_partContext *ctx) = 0;

  virtual void enterLoop(MavkaParser::LoopContext *ctx) = 0;
  virtual void exitLoop(MavkaParser::LoopContext *ctx) = 0;

  virtual void enterBody(MavkaParser::BodyContext *ctx) = 0;
  virtual void exitBody(MavkaParser::BodyContext *ctx) = 0;

  virtual void enterBody_element(MavkaParser::Body_elementContext *ctx) = 0;
  virtual void exitBody_element(MavkaParser::Body_elementContext *ctx) = 0;

  virtual void enterReturn(MavkaParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(MavkaParser::ReturnContext *ctx) = 0;

  virtual void enterModule(MavkaParser::ModuleContext *ctx) = 0;
  virtual void exitModule(MavkaParser::ModuleContext *ctx) = 0;

  virtual void enterType_get(MavkaParser::Type_getContext *ctx) = 0;
  virtual void exitType_get(MavkaParser::Type_getContext *ctx) = 0;

  virtual void enterType_nested(MavkaParser::Type_nestedContext *ctx) = 0;
  virtual void exitType_nested(MavkaParser::Type_nestedContext *ctx) = 0;

  virtual void enterType_subject(MavkaParser::Type_subjectContext *ctx) = 0;
  virtual void exitType_subject(MavkaParser::Type_subjectContext *ctx) = 0;

  virtual void enterTypes(MavkaParser::TypesContext *ctx) = 0;
  virtual void exitTypes(MavkaParser::TypesContext *ctx) = 0;

  virtual void enterParam(MavkaParser::ParamContext *ctx) = 0;
  virtual void exitParam(MavkaParser::ParamContext *ctx) = 0;

  virtual void enterTake(MavkaParser::TakeContext *ctx) = 0;
  virtual void exitTake(MavkaParser::TakeContext *ctx) = 0;

  virtual void enterTake_part(MavkaParser::Take_partContext *ctx) = 0;
  virtual void exitTake_part(MavkaParser::Take_partContext *ctx) = 0;

  virtual void enterTake_element(MavkaParser::Take_elementContext *ctx) = 0;
  virtual void exitTake_element(MavkaParser::Take_elementContext *ctx) = 0;

  virtual void enterGive(MavkaParser::GiveContext *ctx) = 0;
  virtual void exitGive(MavkaParser::GiveContext *ctx) = 0;

  virtual void enterGive_element(MavkaParser::Give_elementContext *ctx) = 0;
  virtual void exitGive_element(MavkaParser::Give_elementContext *ctx) = 0;

  virtual void enterTry(MavkaParser::TryContext *ctx) = 0;
  virtual void exitTry(MavkaParser::TryContext *ctx) = 0;

  virtual void enterThrow(MavkaParser::ThrowContext *ctx) = 0;
  virtual void exitThrow(MavkaParser::ThrowContext *ctx) = 0;

  virtual void enterNl(MavkaParser::NlContext *ctx) = 0;
  virtual void exitNl(MavkaParser::NlContext *ctx) = 0;

  virtual void enterNls(MavkaParser::NlsContext *ctx) = 0;
  virtual void exitNls(MavkaParser::NlsContext *ctx) = 0;


};

