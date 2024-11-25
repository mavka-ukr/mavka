
// Generated from MavkaParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MavkaParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MavkaParser.
 */
class  MavkaParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MavkaParser.
   */
    virtual std::any visitFile(MavkaParser::FileContext *context) = 0;

    virtual std::any visitProgram(MavkaParser::ProgramContext *context) = 0;

    virtual std::any visitAtom_nested(MavkaParser::Atom_nestedContext *context) = 0;

    virtual std::any visitOperation_array(MavkaParser::Operation_arrayContext *context) = 0;

    virtual std::any visitOperation_string(MavkaParser::Operation_stringContext *context) = 0;

    virtual std::any visitOperation_dict_empty(MavkaParser::Operation_dict_emptyContext *context) = 0;

    virtual std::any visitOperation_dict(MavkaParser::Operation_dictContext *context) = 0;

    virtual std::any visitAtom_get(MavkaParser::Atom_getContext *context) = 0;

    virtual std::any visitOperation_string_multiline(MavkaParser::Operation_string_multilineContext *context) = 0;

    virtual std::any visitAtom_subject(MavkaParser::Atom_subjectContext *context) = 0;

    virtual std::any visitAtom_position_get(MavkaParser::Atom_position_getContext *context) = 0;

    virtual std::any visitOperation_symbol(MavkaParser::Operation_symbolContext *context) = 0;

    virtual std::any visitAtom_call(MavkaParser::Atom_callContext *context) = 0;

    virtual std::any visitObject_arg(MavkaParser::Object_argContext *context) = 0;

    virtual std::any visitDict_arg(MavkaParser::Dict_argContext *context) = 0;

    virtual std::any visitCall_arg(MavkaParser::Call_argContext *context) = 0;

    virtual std::any visitOperation_pow(MavkaParser::Operation_powContext *context) = 0;

    virtual std::any visitOperation_gte(MavkaParser::Operation_gteContext *context) = 0;

    virtual std::any visitOperation_neq(MavkaParser::Operation_neqContext *context) = 0;

    virtual std::any visitOperation_xor(MavkaParser::Operation_xorContext *context) = 0;

    virtual std::any visitOperation_lte(MavkaParser::Operation_lteContext *context) = 0;

    virtual std::any visitOperation_pre_plus(MavkaParser::Operation_pre_plusContext *context) = 0;

    virtual std::any visitOperation_add(MavkaParser::Operation_addContext *context) = 0;

    virtual std::any visitOperation_lt(MavkaParser::Operation_ltContext *context) = 0;

    virtual std::any visitOperation_pre_minus(MavkaParser::Operation_pre_minusContext *context) = 0;

    virtual std::any visitOperation_land(MavkaParser::Operation_landContext *context) = 0;

    virtual std::any visitOperation_or(MavkaParser::Operation_orContext *context) = 0;

    virtual std::any visitOperation_pre_not(MavkaParser::Operation_pre_notContext *context) = 0;

    virtual std::any visitOperation_contains(MavkaParser::Operation_containsContext *context) = 0;

    virtual std::any visitOperation_delete_element(MavkaParser::Operation_delete_elementContext *context) = 0;

    virtual std::any visitOperation_delete_prop(MavkaParser::Operation_delete_propContext *context) = 0;

    virtual std::any visitOperation_wait(MavkaParser::Operation_waitContext *context) = 0;

    virtual std::any visitOperation_div_div(MavkaParser::Operation_div_divContext *context) = 0;

    virtual std::any visitOperation_not_is(MavkaParser::Operation_not_isContext *context) = 0;

    virtual std::any visitOperation_atom(MavkaParser::Operation_atomContext *context) = 0;

    virtual std::any visitOperation_sub(MavkaParser::Operation_subContext *context) = 0;

    virtual std::any visitOperation_mod(MavkaParser::Operation_modContext *context) = 0;

    virtual std::any visitOperation_is(MavkaParser::Operation_isContext *context) = 0;

    virtual std::any visitOperation_mul(MavkaParser::Operation_mulContext *context) = 0;

    virtual std::any visitOperation_gt(MavkaParser::Operation_gtContext *context) = 0;

    virtual std::any visitOperation_eq(MavkaParser::Operation_eqContext *context) = 0;

    virtual std::any visitOperation_delete_id(MavkaParser::Operation_delete_idContext *context) = 0;

    virtual std::any visitOperation_pre_bw_not(MavkaParser::Operation_pre_bw_notContext *context) = 0;

    virtual std::any visitOperation_lor(MavkaParser::Operation_lorContext *context) = 0;

    virtual std::any visitOperation_ternary(MavkaParser::Operation_ternaryContext *context) = 0;

    virtual std::any visitOperation_urshift(MavkaParser::Operation_urshiftContext *context) = 0;

    virtual std::any visitOperation_not_contains(MavkaParser::Operation_not_containsContext *context) = 0;

    virtual std::any visitOperation_div(MavkaParser::Operation_divContext *context) = 0;

    virtual std::any visitOperation_rshift(MavkaParser::Operation_rshiftContext *context) = 0;

    virtual std::any visitOperation_lshift(MavkaParser::Operation_lshiftContext *context) = 0;

    virtual std::any visitOperation_number(MavkaParser::Operation_numberContext *context) = 0;

    virtual std::any visitOperation_and(MavkaParser::Operation_andContext *context) = 0;

    virtual std::any visitOp_pow(MavkaParser::Op_powContext *context) = 0;

    virtual std::any visitOp_div_div(MavkaParser::Op_div_divContext *context) = 0;

    virtual std::any visitOp_lshift(MavkaParser::Op_lshiftContext *context) = 0;

    virtual std::any visitOp_rshift(MavkaParser::Op_rshiftContext *context) = 0;

    virtual std::any visitOp_urshift(MavkaParser::Op_urshiftContext *context) = 0;

    virtual std::any visitOp_lt(MavkaParser::Op_ltContext *context) = 0;

    virtual std::any visitOp_lte(MavkaParser::Op_lteContext *context) = 0;

    virtual std::any visitOp_gt(MavkaParser::Op_gtContext *context) = 0;

    virtual std::any visitOp_gte(MavkaParser::Op_gteContext *context) = 0;

    virtual std::any visitOp_eq(MavkaParser::Op_eqContext *context) = 0;

    virtual std::any visitOp_neq(MavkaParser::Op_neqContext *context) = 0;

    virtual std::any visitOp_land(MavkaParser::Op_landContext *context) = 0;

    virtual std::any visitOp_lor(MavkaParser::Op_lorContext *context) = 0;

    virtual std::any visitOp_not_contains(MavkaParser::Op_not_containsContext *context) = 0;

    virtual std::any visitOp_not_is(MavkaParser::Op_not_isContext *context) = 0;

    virtual std::any visitGendef(MavkaParser::GendefContext *context) = 0;

    virtual std::any visitExpr_operation(MavkaParser::Expr_operationContext *context) = 0;

    virtual std::any visitExpr_diia(MavkaParser::Expr_diiaContext *context) = 0;

    virtual std::any visitExpr_structure(MavkaParser::Expr_structureContext *context) = 0;

    virtual std::any visitFunction(MavkaParser::FunctionContext *context) = 0;

    virtual std::any visitStructure_define(MavkaParser::Structure_defineContext *context) = 0;

    virtual std::any visitStructure_element(MavkaParser::Structure_elementContext *context) = 0;

    virtual std::any visitDiia_define(MavkaParser::Diia_defineContext *context) = 0;

    virtual std::any visitDiia_param(MavkaParser::Diia_paramContext *context) = 0;

    virtual std::any visitAssign(MavkaParser::AssignContext *context) = 0;

    virtual std::any visitAssign_op(MavkaParser::Assign_opContext *context) = 0;

    virtual std::any visitSet(MavkaParser::SetContext *context) = 0;

    virtual std::any visitPosition_set(MavkaParser::Position_setContext *context) = 0;

    virtual std::any visitIf(MavkaParser::IfContext *context) = 0;

    virtual std::any visitWhile(MavkaParser::WhileContext *context) = 0;

    virtual std::any visitEach(MavkaParser::EachContext *context) = 0;

    virtual std::any visitEach_range_value(MavkaParser::Each_range_valueContext *context) = 0;

    virtual std::any visitEach_range(MavkaParser::Each_rangeContext *context) = 0;

    virtual std::any visitLoop_part(MavkaParser::Loop_partContext *context) = 0;

    virtual std::any visitLoop(MavkaParser::LoopContext *context) = 0;

    virtual std::any visitBody(MavkaParser::BodyContext *context) = 0;

    virtual std::any visitBody_element(MavkaParser::Body_elementContext *context) = 0;

    virtual std::any visitReturn(MavkaParser::ReturnContext *context) = 0;

    virtual std::any visitModule(MavkaParser::ModuleContext *context) = 0;

    virtual std::any visitType_get(MavkaParser::Type_getContext *context) = 0;

    virtual std::any visitType_nested(MavkaParser::Type_nestedContext *context) = 0;

    virtual std::any visitType_subject(MavkaParser::Type_subjectContext *context) = 0;

    virtual std::any visitTypes(MavkaParser::TypesContext *context) = 0;

    virtual std::any visitParam(MavkaParser::ParamContext *context) = 0;

    virtual std::any visitTake(MavkaParser::TakeContext *context) = 0;

    virtual std::any visitTake_part(MavkaParser::Take_partContext *context) = 0;

    virtual std::any visitTake_element(MavkaParser::Take_elementContext *context) = 0;

    virtual std::any visitGive(MavkaParser::GiveContext *context) = 0;

    virtual std::any visitGive_element(MavkaParser::Give_elementContext *context) = 0;

    virtual std::any visitTry(MavkaParser::TryContext *context) = 0;

    virtual std::any visitThrow(MavkaParser::ThrowContext *context) = 0;

    virtual std::any visitNl(MavkaParser::NlContext *context) = 0;

    virtual std::any visitNls(MavkaParser::NlsContext *context) = 0;


};

