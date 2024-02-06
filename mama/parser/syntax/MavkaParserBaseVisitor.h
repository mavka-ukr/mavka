
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

  virtual std::any visitNl(MavkaParser::NlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNls(MavkaParser::NlsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber_token(MavkaParser::Number_tokenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString(MavkaParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(MavkaParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFile(MavkaParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram(MavkaParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram_element(MavkaParser::Program_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule(MavkaParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule_body(MavkaParser::Module_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule_body_element(MavkaParser::Module_body_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure(MavkaParser::StructureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_elements(MavkaParser::Structure_elementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_element(MavkaParser::Structure_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructure_param(MavkaParser::Structure_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGenerics(MavkaParser::GenericsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMockup(MavkaParser::MockupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMockup_module(MavkaParser::Mockup_moduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMockup_module_body(MavkaParser::Mockup_module_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMockup_structure(MavkaParser::Mockup_structureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMockup_structure_body(MavkaParser::Mockup_structure_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMockup_structure_body_element(MavkaParser::Mockup_structure_body_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMockup_diia(MavkaParser::Mockup_diiaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMockup_subject(MavkaParser::Mockup_subjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiia(MavkaParser::DiiaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf(MavkaParser::IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEach(MavkaParser::EachContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromto(MavkaParser::FromtoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromto_simple(MavkaParser::Fromto_simpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromto_complex(MavkaParser::Fromto_complexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromto_number(MavkaParser::Fromto_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromto_id(MavkaParser::Fromto_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromto_nested(MavkaParser::Fromto_nestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromto_middle_symbol(MavkaParser::Fromto_middle_symbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromto_to_symbol(MavkaParser::Fromto_to_symbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile(MavkaParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTry(MavkaParser::TryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEval(MavkaParser::EvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTake_module(MavkaParser::Take_moduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTake_remote(MavkaParser::Take_remoteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTake_module_elements(MavkaParser::Take_module_elementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTake_module_element(MavkaParser::Take_module_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGive(MavkaParser::GiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGive_element(MavkaParser::Give_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMrm(MavkaParser::MrmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMrm_element(MavkaParser::Mrm_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMrm_element_closed(MavkaParser::Mrm_element_closedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMrm_args(MavkaParser::Mrm_argsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMrm_arg(MavkaParser::Mrm_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMrm_content(MavkaParser::Mrm_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMrm_chardata(MavkaParser::Mrm_chardataContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMrm_diia(MavkaParser::Mrm_diiaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGet_element(MavkaParser::Get_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChain(MavkaParser::ChainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString_value(MavkaParser::String_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPre_increment(MavkaParser::Pre_incrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwise_not(MavkaParser::Bitwise_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeless_dictionary(MavkaParser::Typeless_dictionaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPositive(MavkaParser::PositiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNested(MavkaParser::NestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(MavkaParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(MavkaParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNegative(MavkaParser::NegativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNot(MavkaParser::NotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeless_array(MavkaParser::Typeless_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPre_decrement(MavkaParser::Pre_decrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPost_decrement(MavkaParser::Post_decrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitId(MavkaParser::IdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPost_increment(MavkaParser::Post_incrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmetic_mul(MavkaParser::Arithmetic_mulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmetic_add(MavkaParser::Arithmetic_addContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison(MavkaParser::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTest(MavkaParser::TestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwise(MavkaParser::BitwiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_atom(MavkaParser::Value_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_generics(MavkaParser::Call_genericsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_elements(MavkaParser::Array_elementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_element(MavkaParser::Array_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictionary_args(MavkaParser::Dictionary_argsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictionary_arg(MavkaParser::Dictionary_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_parent(MavkaParser::Call_parentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple(MavkaParser::SimpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAs(MavkaParser::AsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTernary(MavkaParser::TernaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGod(MavkaParser::GodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWait(MavkaParser::WaitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(MavkaParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnonymous_diia(MavkaParser::Anonymous_diiaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_mrm(MavkaParser::Expr_mrmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThrow(MavkaParser::ThrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(MavkaParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_simple(MavkaParser::Assign_simpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_by_identifier(MavkaParser::Assign_by_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_by_element(MavkaParser::Assign_by_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_symbol(MavkaParser::Assign_symbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWait_assign(MavkaParser::Wait_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifiers_chain(MavkaParser::Identifiers_chainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuper_identifiers_chain(MavkaParser::Super_identifiers_chainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_value(MavkaParser::Type_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_value_item(MavkaParser::Type_value_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_value_item_simple(MavkaParser::Type_value_item_simpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_value_item_generics(MavkaParser::Type_value_item_genericsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_value_item_array(MavkaParser::Type_value_item_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgs(MavkaParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg(MavkaParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNamed_args(MavkaParser::Named_argsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNamed_arg(MavkaParser::Named_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(MavkaParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(MavkaParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_value_number(MavkaParser::Param_value_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_value_string(MavkaParser::Param_value_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_value_identifier(MavkaParser::Param_value_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_value_empty_dictionary(MavkaParser::Param_value_empty_dictionaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_value_empty_list(MavkaParser::Param_value_empty_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody(MavkaParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody_element_or_return(MavkaParser::Body_element_or_returnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody_element(MavkaParser::Body_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_body_line(MavkaParser::Return_body_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmetic_op_mul(MavkaParser::Arithmetic_op_mulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmetic_op_add(MavkaParser::Arithmetic_op_addContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwise_op(MavkaParser::Bitwise_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTest_op(MavkaParser::Test_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison_op(MavkaParser::Comparison_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_inst_block_program(MavkaParser::Comp_inst_block_programContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_inst_assign(MavkaParser::Comp_inst_assignContext *ctx) override {
    return visitChildren(ctx);
  }


};

