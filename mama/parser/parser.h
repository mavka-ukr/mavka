#pragma once

#ifndef PARSER_H
#define PARSER_H

#include "../../utils/tools.h"
#include "ast.h"
#include "syntax/MavkaLexer.h"
#include "syntax/MavkaParser.h"
#include "syntax/MavkaParserBaseVisitor.h"
#include "syntax/antlr4-cpp-runtime/runtime/src/antlr4-runtime.h"

namespace mavka::parser {
  ast::ASTSome* any_to_ast_some(std::any any);

  void fill_ast_node(ast::ASTNode* node, antlr4::ParserRuleContext* context);

  std::string process_number(std::string number);

  void processASTBody(std::vector<ast::ASTSome*>& body);

  class MavkaASTVisitor final : public MavkaParserBaseVisitor {
   public:
    antlr4::CommonTokenStream* tokens;

    std::any visitFile(MavkaParser::FileContext* ctx) override;

    std::any visitProgram(MavkaParser::ProgramContext* context) override;

    std::any visitProgram_element(
        MavkaParser::Program_elementContext* context) override;

    std::any visitModule(MavkaParser::ModuleContext* context) override;

    std::any visitModule_body(
        MavkaParser::Module_bodyContext* context) override;

    std::any visitModule_body_element(
        MavkaParser::Module_body_elementContext* context) override;

    std::any visitStructure(MavkaParser::StructureContext* context) override;

    std::any visitStructure_elements(
        MavkaParser::Structure_elementsContext* context) override;

    std::any visitStructure_element(
        MavkaParser::Structure_elementContext* context) override;

    std::any visitStructure_param(
        MavkaParser::Structure_paramContext* context) override;

    std::any visitGenerics(MavkaParser::GenericsContext* context) override;

    std::any visitMockup(MavkaParser::MockupContext* context) override;

    std::any visitMockup_module(
        MavkaParser::Mockup_moduleContext* context) override;

    std::any visitMockup_structure(
        MavkaParser::Mockup_structureContext* context) override;

    std::any visitMockup_module_body(
        MavkaParser::Mockup_module_bodyContext* context) override;

    std::any visitMockup_structure_body(
        MavkaParser::Mockup_structure_bodyContext* context) override;

    std::any visitMockup_structure_body_element(
        MavkaParser::Mockup_structure_body_elementContext* context) override;

    std::any visitMockup_diia(
        MavkaParser::Mockup_diiaContext* context) override;

    std::any visitMockup_subject(
        MavkaParser::Mockup_subjectContext* context) override;

    std::any visitDiia(MavkaParser::DiiaContext* context) override;

    std::any visitIf(MavkaParser::IfContext* context) override;

    std::any visitEach(MavkaParser::EachContext* context) override;

    std::any visitFromto(MavkaParser::FromtoContext* context) override;

    std::any visitFromto_simple(
        MavkaParser::Fromto_simpleContext* context) override;

    std::any visitFromto_complex(
        MavkaParser::Fromto_complexContext* context) override;

    std::any visitFromto_value(MavkaParser::Fromto_valueContext* context);

    std::any visitWhile(MavkaParser::WhileContext* context) override;

    std::any visitTry(MavkaParser::TryContext* context) override;

    std::any _visitContext(antlr4::ParserRuleContext* context);

    std::any visitValue_atom(MavkaParser::Value_atomContext* context) override;

    std::any visitNumber(MavkaParser::NumberContext* context) override;

    std::any visitString_value(
        MavkaParser::String_valueContext* context) override;

    std::any visitId(MavkaParser::IdContext* context) override;

    std::any visitIdentifier(MavkaParser::IdentifierContext* context) override;

    std::any visitChain(MavkaParser::ChainContext* context) override;

    std::any visitCall(MavkaParser::CallContext* context) override;

    std::any visitCall_generics(
        MavkaParser::Call_genericsContext* context) override;

    std::any visitGet_element(
        MavkaParser::Get_elementContext* context) override;

    std::any visitPositive(MavkaParser::PositiveContext* context) override;

    std::any visitNegative(MavkaParser::NegativeContext* context) override;

    std::any visitPre_decrement(
        MavkaParser::Pre_decrementContext* context) override;

    std::any visitPre_increment(
        MavkaParser::Pre_incrementContext* context) override;

    std::any visitPost_decrement(
        MavkaParser::Post_decrementContext* context) override;

    std::any visitPost_increment(
        MavkaParser::Post_incrementContext* context) override;

    std::any visitNot(MavkaParser::NotContext* context) override;

    std::any visitBitwise_not(
        MavkaParser::Bitwise_notContext* context) override;

    std::any visitNested(MavkaParser::NestedContext* context) override;

    std::any visitAs(MavkaParser::AsContext* context) override;

    std::any visitArithmetic_mul(
        MavkaParser::Arithmetic_mulContext* context) override;

    std::any visitArithmetic_op_mul(
        MavkaParser::Arithmetic_op_mulContext* context) override;

    std::any visitArithmetic_add(
        MavkaParser::Arithmetic_addContext* context) override;

    std::any visitArithmetic_op_add(
        MavkaParser::Arithmetic_op_addContext* context) override;

    std::any visitBitwise(MavkaParser::BitwiseContext* context) override;

    std::any visitBitwise_op(MavkaParser::Bitwise_opContext* context) override;

    std::any visitComparison(MavkaParser::ComparisonContext* context) override;

    std::any visitComp_inst_block_program(
        MavkaParser::Comp_inst_block_programContext* context) override;

    std::any visitComp_inst_assign(
        MavkaParser::Comp_inst_assignContext* context) override;

    std::any visitTest(MavkaParser::TestContext* context) override;

    std::any visitTernary(MavkaParser::TernaryContext* context) override;

    std::any visitTypeless_array(
        MavkaParser::Typeless_arrayContext* context) override;

    std::any visitArray_elements(
        MavkaParser::Array_elementsContext* context) override;

    std::any visitArray_element(
        MavkaParser::Array_elementContext* context) override;

    std::any visitTypeless_dictionary(
        MavkaParser::Typeless_dictionaryContext* context) override;

    std::any visitDictionary_args(
        MavkaParser::Dictionary_argsContext* context) override;

    std::any visitGod(MavkaParser::GodContext* context) override;

    std::any visitWait(MavkaParser::WaitContext* context) override;

    std::any visitFunction(MavkaParser::FunctionContext* context) override;

    std::any visitAnonymous_diia(
        MavkaParser::Anonymous_diiaContext* context) override;

    std::any visitThrow(MavkaParser::ThrowContext* context) override;

    std::any visitEval(MavkaParser::EvalContext* context) override;

    std::any visitWait_assign(
        MavkaParser::Wait_assignContext* context) override;

    std::any visitAssign(MavkaParser::AssignContext* context) override;

    std::any visitAssign_simple(
        MavkaParser::Assign_simpleContext* context) override;

    std::any visitAssign_by_identifier(
        MavkaParser::Assign_by_identifierContext* context) override;

    std::any visitAssign_by_element(
        MavkaParser::Assign_by_elementContext* context) override;

    std::any visitAssign_symbol(
        MavkaParser::Assign_symbolContext* context) override;

    std::any visitTake(MavkaParser::TakeContext* context);

    std::any visitTake_module(
        MavkaParser::Take_moduleContext* context) override;

    std::any visitTake_remote(
        MavkaParser::Take_remoteContext* context) override;

    std::any visitGive(MavkaParser::GiveContext* context) override;

    std::any visitGive_element(
        MavkaParser::Give_elementContext* context) override;

    std::any visitParams(MavkaParser::ParamsContext* context) override;

    std::any visitParam(MavkaParser::ParamContext* context) override;

    std::any visitParam_value(MavkaParser::Param_valueContext* context);

    std::any visitParam_value_string(
        MavkaParser::Param_value_stringContext* context) override;

    std::any visitParam_value_number(
        MavkaParser::Param_value_numberContext* context) override;

    std::any visitParam_value_identifier(
        MavkaParser::Param_value_identifierContext* context) override;

    std::any visitParam_value_empty_dictionary(
        MavkaParser::Param_value_empty_dictionaryContext* context) override;

    std::any visitParam_value_empty_list(
        MavkaParser::Param_value_empty_listContext* context) override;

    std::any visitIdentifiers_chain(
        MavkaParser::Identifiers_chainContext* context) override;

    std::any visitSuper_identifiers_chain(
        MavkaParser::Super_identifiers_chainContext* context) override;

    std::any visitType_value(MavkaParser::Type_valueContext* context) override;

    std::any visitType_value_item(
        MavkaParser::Type_value_itemContext* context) override;

    std::any visitType_value_item_array(
        MavkaParser::Type_value_item_arrayContext* context) override;

    std::any visitType_value_item_simple(
        MavkaParser::Type_value_item_simpleContext* context) override;

    std::any visitArgs(MavkaParser::ArgsContext* context) override;

    std::any visitArg(MavkaParser::ArgContext* context, int index);

    std::any visitNamed_args(MavkaParser::Named_argsContext* context) override;

    std::any visitNamed_arg(MavkaParser::Named_argContext* context, int index);

    std::any visitBody(MavkaParser::BodyContext* context) override;

    std::any _visitDiiaBody(MavkaParser::BodyContext* context);

    std::any visitBody_element_or_return(
        MavkaParser::Body_element_or_returnContext* context) override;

    std::any visitBody_element(
        MavkaParser::Body_elementContext* context) override;

    std::any visitReturn_body_line(
        MavkaParser::Return_body_lineContext* context) override;

    std::any visitMrm(MavkaParser::MrmContext* context) override;

    std::any visitMrm_element(
        MavkaParser::Mrm_elementContext* context) override;
  };

  class MavkaParserError : public std::exception {
   public:
    std::string path;
    size_t line = 0;
    size_t column = 0;
    std::string message;
  };

  class MavkaParserErrorListener final : public antlr4::BaseErrorListener {
   public:
    void syntaxError(antlr4::Recognizer* recognizer,
                     antlr4::Token* offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string& msg,
                     std::exception_ptr e) override;
  };

  class MavkaParserResult {
   public:
    MavkaParserError* error = nullptr;
    ast::ProgramNode* program_node = nullptr;
  };

  MavkaParserResult* parse(std::string code, std::string path);
} // namespace mavka::parser
#endif // PARSER_H
