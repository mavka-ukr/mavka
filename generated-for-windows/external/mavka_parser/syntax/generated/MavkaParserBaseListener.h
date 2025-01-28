
// Generated from MavkaParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MavkaParserListener.h"


/**
 * This class provides an empty implementation of MavkaParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MavkaParserBaseListener : public MavkaParserListener {
public:

  virtual void enterFile(MavkaParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(MavkaParser::FileContext * /*ctx*/) override { }

  virtual void enterProgram(MavkaParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(MavkaParser::ProgramContext * /*ctx*/) override { }

  virtual void enterAtom_nested(MavkaParser::Atom_nestedContext * /*ctx*/) override { }
  virtual void exitAtom_nested(MavkaParser::Atom_nestedContext * /*ctx*/) override { }

  virtual void enterOperation_array(MavkaParser::Operation_arrayContext * /*ctx*/) override { }
  virtual void exitOperation_array(MavkaParser::Operation_arrayContext * /*ctx*/) override { }

  virtual void enterOperation_string(MavkaParser::Operation_stringContext * /*ctx*/) override { }
  virtual void exitOperation_string(MavkaParser::Operation_stringContext * /*ctx*/) override { }

  virtual void enterOperation_dict_empty(MavkaParser::Operation_dict_emptyContext * /*ctx*/) override { }
  virtual void exitOperation_dict_empty(MavkaParser::Operation_dict_emptyContext * /*ctx*/) override { }

  virtual void enterOperation_dict(MavkaParser::Operation_dictContext * /*ctx*/) override { }
  virtual void exitOperation_dict(MavkaParser::Operation_dictContext * /*ctx*/) override { }

  virtual void enterAtom_get(MavkaParser::Atom_getContext * /*ctx*/) override { }
  virtual void exitAtom_get(MavkaParser::Atom_getContext * /*ctx*/) override { }

  virtual void enterOperation_string_multiline(MavkaParser::Operation_string_multilineContext * /*ctx*/) override { }
  virtual void exitOperation_string_multiline(MavkaParser::Operation_string_multilineContext * /*ctx*/) override { }

  virtual void enterAtom_subject(MavkaParser::Atom_subjectContext * /*ctx*/) override { }
  virtual void exitAtom_subject(MavkaParser::Atom_subjectContext * /*ctx*/) override { }

  virtual void enterAtom_position_get(MavkaParser::Atom_position_getContext * /*ctx*/) override { }
  virtual void exitAtom_position_get(MavkaParser::Atom_position_getContext * /*ctx*/) override { }

  virtual void enterOperation_symbol(MavkaParser::Operation_symbolContext * /*ctx*/) override { }
  virtual void exitOperation_symbol(MavkaParser::Operation_symbolContext * /*ctx*/) override { }

  virtual void enterAtom_call(MavkaParser::Atom_callContext * /*ctx*/) override { }
  virtual void exitAtom_call(MavkaParser::Atom_callContext * /*ctx*/) override { }

  virtual void enterObject_arg(MavkaParser::Object_argContext * /*ctx*/) override { }
  virtual void exitObject_arg(MavkaParser::Object_argContext * /*ctx*/) override { }

  virtual void enterDict_arg(MavkaParser::Dict_argContext * /*ctx*/) override { }
  virtual void exitDict_arg(MavkaParser::Dict_argContext * /*ctx*/) override { }

  virtual void enterCall_arg(MavkaParser::Call_argContext * /*ctx*/) override { }
  virtual void exitCall_arg(MavkaParser::Call_argContext * /*ctx*/) override { }

  virtual void enterOperation_pow(MavkaParser::Operation_powContext * /*ctx*/) override { }
  virtual void exitOperation_pow(MavkaParser::Operation_powContext * /*ctx*/) override { }

  virtual void enterOperation_gte(MavkaParser::Operation_gteContext * /*ctx*/) override { }
  virtual void exitOperation_gte(MavkaParser::Operation_gteContext * /*ctx*/) override { }

  virtual void enterOperation_neq(MavkaParser::Operation_neqContext * /*ctx*/) override { }
  virtual void exitOperation_neq(MavkaParser::Operation_neqContext * /*ctx*/) override { }

  virtual void enterOperation_xor(MavkaParser::Operation_xorContext * /*ctx*/) override { }
  virtual void exitOperation_xor(MavkaParser::Operation_xorContext * /*ctx*/) override { }

  virtual void enterOperation_lte(MavkaParser::Operation_lteContext * /*ctx*/) override { }
  virtual void exitOperation_lte(MavkaParser::Operation_lteContext * /*ctx*/) override { }

  virtual void enterOperation_pre_plus(MavkaParser::Operation_pre_plusContext * /*ctx*/) override { }
  virtual void exitOperation_pre_plus(MavkaParser::Operation_pre_plusContext * /*ctx*/) override { }

  virtual void enterOperation_add(MavkaParser::Operation_addContext * /*ctx*/) override { }
  virtual void exitOperation_add(MavkaParser::Operation_addContext * /*ctx*/) override { }

  virtual void enterOperation_lt(MavkaParser::Operation_ltContext * /*ctx*/) override { }
  virtual void exitOperation_lt(MavkaParser::Operation_ltContext * /*ctx*/) override { }

  virtual void enterOperation_pre_minus(MavkaParser::Operation_pre_minusContext * /*ctx*/) override { }
  virtual void exitOperation_pre_minus(MavkaParser::Operation_pre_minusContext * /*ctx*/) override { }

  virtual void enterOperation_land(MavkaParser::Operation_landContext * /*ctx*/) override { }
  virtual void exitOperation_land(MavkaParser::Operation_landContext * /*ctx*/) override { }

  virtual void enterOperation_or(MavkaParser::Operation_orContext * /*ctx*/) override { }
  virtual void exitOperation_or(MavkaParser::Operation_orContext * /*ctx*/) override { }

  virtual void enterOperation_pre_not(MavkaParser::Operation_pre_notContext * /*ctx*/) override { }
  virtual void exitOperation_pre_not(MavkaParser::Operation_pre_notContext * /*ctx*/) override { }

  virtual void enterOperation_contains(MavkaParser::Operation_containsContext * /*ctx*/) override { }
  virtual void exitOperation_contains(MavkaParser::Operation_containsContext * /*ctx*/) override { }

  virtual void enterOperation_delete_element(MavkaParser::Operation_delete_elementContext * /*ctx*/) override { }
  virtual void exitOperation_delete_element(MavkaParser::Operation_delete_elementContext * /*ctx*/) override { }

  virtual void enterOperation_delete_prop(MavkaParser::Operation_delete_propContext * /*ctx*/) override { }
  virtual void exitOperation_delete_prop(MavkaParser::Operation_delete_propContext * /*ctx*/) override { }

  virtual void enterOperation_wait(MavkaParser::Operation_waitContext * /*ctx*/) override { }
  virtual void exitOperation_wait(MavkaParser::Operation_waitContext * /*ctx*/) override { }

  virtual void enterOperation_div_div(MavkaParser::Operation_div_divContext * /*ctx*/) override { }
  virtual void exitOperation_div_div(MavkaParser::Operation_div_divContext * /*ctx*/) override { }

  virtual void enterOperation_not_is(MavkaParser::Operation_not_isContext * /*ctx*/) override { }
  virtual void exitOperation_not_is(MavkaParser::Operation_not_isContext * /*ctx*/) override { }

  virtual void enterOperation_atom(MavkaParser::Operation_atomContext * /*ctx*/) override { }
  virtual void exitOperation_atom(MavkaParser::Operation_atomContext * /*ctx*/) override { }

  virtual void enterOperation_sub(MavkaParser::Operation_subContext * /*ctx*/) override { }
  virtual void exitOperation_sub(MavkaParser::Operation_subContext * /*ctx*/) override { }

  virtual void enterOperation_mod(MavkaParser::Operation_modContext * /*ctx*/) override { }
  virtual void exitOperation_mod(MavkaParser::Operation_modContext * /*ctx*/) override { }

  virtual void enterOperation_is(MavkaParser::Operation_isContext * /*ctx*/) override { }
  virtual void exitOperation_is(MavkaParser::Operation_isContext * /*ctx*/) override { }

  virtual void enterOperation_mul(MavkaParser::Operation_mulContext * /*ctx*/) override { }
  virtual void exitOperation_mul(MavkaParser::Operation_mulContext * /*ctx*/) override { }

  virtual void enterOperation_gt(MavkaParser::Operation_gtContext * /*ctx*/) override { }
  virtual void exitOperation_gt(MavkaParser::Operation_gtContext * /*ctx*/) override { }

  virtual void enterOperation_eq(MavkaParser::Operation_eqContext * /*ctx*/) override { }
  virtual void exitOperation_eq(MavkaParser::Operation_eqContext * /*ctx*/) override { }

  virtual void enterOperation_delete_id(MavkaParser::Operation_delete_idContext * /*ctx*/) override { }
  virtual void exitOperation_delete_id(MavkaParser::Operation_delete_idContext * /*ctx*/) override { }

  virtual void enterOperation_pre_bw_not(MavkaParser::Operation_pre_bw_notContext * /*ctx*/) override { }
  virtual void exitOperation_pre_bw_not(MavkaParser::Operation_pre_bw_notContext * /*ctx*/) override { }

  virtual void enterOperation_lor(MavkaParser::Operation_lorContext * /*ctx*/) override { }
  virtual void exitOperation_lor(MavkaParser::Operation_lorContext * /*ctx*/) override { }

  virtual void enterOperation_ternary(MavkaParser::Operation_ternaryContext * /*ctx*/) override { }
  virtual void exitOperation_ternary(MavkaParser::Operation_ternaryContext * /*ctx*/) override { }

  virtual void enterOperation_urshift(MavkaParser::Operation_urshiftContext * /*ctx*/) override { }
  virtual void exitOperation_urshift(MavkaParser::Operation_urshiftContext * /*ctx*/) override { }

  virtual void enterOperation_not_contains(MavkaParser::Operation_not_containsContext * /*ctx*/) override { }
  virtual void exitOperation_not_contains(MavkaParser::Operation_not_containsContext * /*ctx*/) override { }

  virtual void enterOperation_div(MavkaParser::Operation_divContext * /*ctx*/) override { }
  virtual void exitOperation_div(MavkaParser::Operation_divContext * /*ctx*/) override { }

  virtual void enterOperation_rshift(MavkaParser::Operation_rshiftContext * /*ctx*/) override { }
  virtual void exitOperation_rshift(MavkaParser::Operation_rshiftContext * /*ctx*/) override { }

  virtual void enterOperation_lshift(MavkaParser::Operation_lshiftContext * /*ctx*/) override { }
  virtual void exitOperation_lshift(MavkaParser::Operation_lshiftContext * /*ctx*/) override { }

  virtual void enterOperation_number(MavkaParser::Operation_numberContext * /*ctx*/) override { }
  virtual void exitOperation_number(MavkaParser::Operation_numberContext * /*ctx*/) override { }

  virtual void enterOperation_and(MavkaParser::Operation_andContext * /*ctx*/) override { }
  virtual void exitOperation_and(MavkaParser::Operation_andContext * /*ctx*/) override { }

  virtual void enterOp_pow(MavkaParser::Op_powContext * /*ctx*/) override { }
  virtual void exitOp_pow(MavkaParser::Op_powContext * /*ctx*/) override { }

  virtual void enterOp_div_div(MavkaParser::Op_div_divContext * /*ctx*/) override { }
  virtual void exitOp_div_div(MavkaParser::Op_div_divContext * /*ctx*/) override { }

  virtual void enterOp_lshift(MavkaParser::Op_lshiftContext * /*ctx*/) override { }
  virtual void exitOp_lshift(MavkaParser::Op_lshiftContext * /*ctx*/) override { }

  virtual void enterOp_rshift(MavkaParser::Op_rshiftContext * /*ctx*/) override { }
  virtual void exitOp_rshift(MavkaParser::Op_rshiftContext * /*ctx*/) override { }

  virtual void enterOp_urshift(MavkaParser::Op_urshiftContext * /*ctx*/) override { }
  virtual void exitOp_urshift(MavkaParser::Op_urshiftContext * /*ctx*/) override { }

  virtual void enterOp_lt(MavkaParser::Op_ltContext * /*ctx*/) override { }
  virtual void exitOp_lt(MavkaParser::Op_ltContext * /*ctx*/) override { }

  virtual void enterOp_lte(MavkaParser::Op_lteContext * /*ctx*/) override { }
  virtual void exitOp_lte(MavkaParser::Op_lteContext * /*ctx*/) override { }

  virtual void enterOp_gt(MavkaParser::Op_gtContext * /*ctx*/) override { }
  virtual void exitOp_gt(MavkaParser::Op_gtContext * /*ctx*/) override { }

  virtual void enterOp_gte(MavkaParser::Op_gteContext * /*ctx*/) override { }
  virtual void exitOp_gte(MavkaParser::Op_gteContext * /*ctx*/) override { }

  virtual void enterOp_eq(MavkaParser::Op_eqContext * /*ctx*/) override { }
  virtual void exitOp_eq(MavkaParser::Op_eqContext * /*ctx*/) override { }

  virtual void enterOp_neq(MavkaParser::Op_neqContext * /*ctx*/) override { }
  virtual void exitOp_neq(MavkaParser::Op_neqContext * /*ctx*/) override { }

  virtual void enterOp_land(MavkaParser::Op_landContext * /*ctx*/) override { }
  virtual void exitOp_land(MavkaParser::Op_landContext * /*ctx*/) override { }

  virtual void enterOp_lor(MavkaParser::Op_lorContext * /*ctx*/) override { }
  virtual void exitOp_lor(MavkaParser::Op_lorContext * /*ctx*/) override { }

  virtual void enterOp_not_contains(MavkaParser::Op_not_containsContext * /*ctx*/) override { }
  virtual void exitOp_not_contains(MavkaParser::Op_not_containsContext * /*ctx*/) override { }

  virtual void enterOp_not_is(MavkaParser::Op_not_isContext * /*ctx*/) override { }
  virtual void exitOp_not_is(MavkaParser::Op_not_isContext * /*ctx*/) override { }

  virtual void enterGendef(MavkaParser::GendefContext * /*ctx*/) override { }
  virtual void exitGendef(MavkaParser::GendefContext * /*ctx*/) override { }

  virtual void enterExpr_operation(MavkaParser::Expr_operationContext * /*ctx*/) override { }
  virtual void exitExpr_operation(MavkaParser::Expr_operationContext * /*ctx*/) override { }

  virtual void enterExpr_diia(MavkaParser::Expr_diiaContext * /*ctx*/) override { }
  virtual void exitExpr_diia(MavkaParser::Expr_diiaContext * /*ctx*/) override { }

  virtual void enterExpr_structure(MavkaParser::Expr_structureContext * /*ctx*/) override { }
  virtual void exitExpr_structure(MavkaParser::Expr_structureContext * /*ctx*/) override { }

  virtual void enterFunction(MavkaParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(MavkaParser::FunctionContext * /*ctx*/) override { }

  virtual void enterStructure_define(MavkaParser::Structure_defineContext * /*ctx*/) override { }
  virtual void exitStructure_define(MavkaParser::Structure_defineContext * /*ctx*/) override { }

  virtual void enterStructure_element(MavkaParser::Structure_elementContext * /*ctx*/) override { }
  virtual void exitStructure_element(MavkaParser::Structure_elementContext * /*ctx*/) override { }

  virtual void enterDiia_define(MavkaParser::Diia_defineContext * /*ctx*/) override { }
  virtual void exitDiia_define(MavkaParser::Diia_defineContext * /*ctx*/) override { }

  virtual void enterDiia_param(MavkaParser::Diia_paramContext * /*ctx*/) override { }
  virtual void exitDiia_param(MavkaParser::Diia_paramContext * /*ctx*/) override { }

  virtual void enterAssign(MavkaParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(MavkaParser::AssignContext * /*ctx*/) override { }

  virtual void enterAssign_op(MavkaParser::Assign_opContext * /*ctx*/) override { }
  virtual void exitAssign_op(MavkaParser::Assign_opContext * /*ctx*/) override { }

  virtual void enterSet(MavkaParser::SetContext * /*ctx*/) override { }
  virtual void exitSet(MavkaParser::SetContext * /*ctx*/) override { }

  virtual void enterPosition_set(MavkaParser::Position_setContext * /*ctx*/) override { }
  virtual void exitPosition_set(MavkaParser::Position_setContext * /*ctx*/) override { }

  virtual void enterIf(MavkaParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(MavkaParser::IfContext * /*ctx*/) override { }

  virtual void enterWhile(MavkaParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(MavkaParser::WhileContext * /*ctx*/) override { }

  virtual void enterEach(MavkaParser::EachContext * /*ctx*/) override { }
  virtual void exitEach(MavkaParser::EachContext * /*ctx*/) override { }

  virtual void enterEach_range_value(MavkaParser::Each_range_valueContext * /*ctx*/) override { }
  virtual void exitEach_range_value(MavkaParser::Each_range_valueContext * /*ctx*/) override { }

  virtual void enterEach_range(MavkaParser::Each_rangeContext * /*ctx*/) override { }
  virtual void exitEach_range(MavkaParser::Each_rangeContext * /*ctx*/) override { }

  virtual void enterLoop_part(MavkaParser::Loop_partContext * /*ctx*/) override { }
  virtual void exitLoop_part(MavkaParser::Loop_partContext * /*ctx*/) override { }

  virtual void enterLoop(MavkaParser::LoopContext * /*ctx*/) override { }
  virtual void exitLoop(MavkaParser::LoopContext * /*ctx*/) override { }

  virtual void enterBody(MavkaParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(MavkaParser::BodyContext * /*ctx*/) override { }

  virtual void enterBody_element(MavkaParser::Body_elementContext * /*ctx*/) override { }
  virtual void exitBody_element(MavkaParser::Body_elementContext * /*ctx*/) override { }

  virtual void enterReturn(MavkaParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(MavkaParser::ReturnContext * /*ctx*/) override { }

  virtual void enterModule(MavkaParser::ModuleContext * /*ctx*/) override { }
  virtual void exitModule(MavkaParser::ModuleContext * /*ctx*/) override { }

  virtual void enterType_get(MavkaParser::Type_getContext * /*ctx*/) override { }
  virtual void exitType_get(MavkaParser::Type_getContext * /*ctx*/) override { }

  virtual void enterType_nested(MavkaParser::Type_nestedContext * /*ctx*/) override { }
  virtual void exitType_nested(MavkaParser::Type_nestedContext * /*ctx*/) override { }

  virtual void enterType_subject(MavkaParser::Type_subjectContext * /*ctx*/) override { }
  virtual void exitType_subject(MavkaParser::Type_subjectContext * /*ctx*/) override { }

  virtual void enterTypes(MavkaParser::TypesContext * /*ctx*/) override { }
  virtual void exitTypes(MavkaParser::TypesContext * /*ctx*/) override { }

  virtual void enterParam(MavkaParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(MavkaParser::ParamContext * /*ctx*/) override { }

  virtual void enterTake(MavkaParser::TakeContext * /*ctx*/) override { }
  virtual void exitTake(MavkaParser::TakeContext * /*ctx*/) override { }

  virtual void enterTake_part(MavkaParser::Take_partContext * /*ctx*/) override { }
  virtual void exitTake_part(MavkaParser::Take_partContext * /*ctx*/) override { }

  virtual void enterTake_element(MavkaParser::Take_elementContext * /*ctx*/) override { }
  virtual void exitTake_element(MavkaParser::Take_elementContext * /*ctx*/) override { }

  virtual void enterGive(MavkaParser::GiveContext * /*ctx*/) override { }
  virtual void exitGive(MavkaParser::GiveContext * /*ctx*/) override { }

  virtual void enterGive_element(MavkaParser::Give_elementContext * /*ctx*/) override { }
  virtual void exitGive_element(MavkaParser::Give_elementContext * /*ctx*/) override { }

  virtual void enterTry(MavkaParser::TryContext * /*ctx*/) override { }
  virtual void exitTry(MavkaParser::TryContext * /*ctx*/) override { }

  virtual void enterThrow(MavkaParser::ThrowContext * /*ctx*/) override { }
  virtual void exitThrow(MavkaParser::ThrowContext * /*ctx*/) override { }

  virtual void enterNl(MavkaParser::NlContext * /*ctx*/) override { }
  virtual void exitNl(MavkaParser::NlContext * /*ctx*/) override { }

  virtual void enterNls(MavkaParser::NlsContext * /*ctx*/) override { }
  virtual void exitNls(MavkaParser::NlsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

