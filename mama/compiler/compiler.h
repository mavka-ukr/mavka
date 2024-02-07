#pragma once

#include <string>
#include <vector>

#include "../parser/ast.h"
#include "ops.h"

namespace mavka::mama {
  class MaCompilationError;
  class MaCompilationResult;
  class MaCode;
  class MaInstruction;

  class MaInstruction final {
   public:
    OP op;
    double numval;
    std::string strval;

    static MaInstruction* create_push_number(const double& number);
    static MaInstruction* create_store(const std::string& name);
    static MaInstruction* create_load(const std::string& name);
    static MaInstruction* create_get(const std::string& name);
    static MaInstruction* create_set(const std::string& name);
    static MaInstruction* create_push_string(const std::string& name);
    static MaInstruction* create_load_param(const int& index,
                                            const std::string& name);
    static MaInstruction* create_jump(const int& index);
    static MaInstruction* create_try(const int& index);
    static MaInstruction* create_try_done();
  };

  class MaCompilationError final {
   public:
    std::string path;
    size_t line = 0;
    size_t column = 0;
    std::string message;
  };

  class MaCompilationResult final {
   public:
    MaCompilationError* error;
  };

  class MaCode final {
   public:
    std::vector<MaInstruction*> instructions;
  };

  MaCompilationResult* error(mavka::ast::ASTSome* node,
                             const std::string& message);

  MaCompilationResult* success();

  MaCompilationResult* compile_node(MaCode* C, mavka::ast::ASTSome* node);
  MaCompilationResult* compile_body(
      MaCode* C,
      const std::vector<mavka::ast::ASTSome*>& body);

  MaCompilationResult* compile_diia(
      MaCode* C,
      bool async,
      const std::vector<ast::GenericNode*>& generics,
      const std::string& name,
      const std::vector<ast::ParamNode*>& params,
      const std::vector<ast::TypeValueSingleNode*>& return_types,
      const std::vector<ast::ASTSome*>& body);

  MaCompilationResult* compile_anon_diia_node(
      MaCode* C,
      mavka::ast::AnonDiiaNode* anon_diia_node);
  MaCompilationResult* compile_arithmetic_node(
      MaCode* C,
      mavka::ast::ArithmeticNode* arithmetic_node);
  MaCompilationResult* compile_array_node(MaCode* C,
                                          mavka::ast::ArrayNode* array_node);
  MaCompilationResult* compile_as_node(MaCode* C, mavka::ast::AsNode* as_node);
  MaCompilationResult* compile_assign_by_element_node(
      MaCode* C,
      mavka::ast::AssignByElementNode* assign_by_element_node);
  MaCompilationResult* compile_assign_by_identifier_node(
      MaCode* C,
      mavka::ast::AssignByIdentifierNode* assign_by_identifier_node);
  MaCompilationResult* compile_assign_simple_node(
      MaCode* C,
      mavka::ast::AssignSimpleNode* assign_simple_node);
  MaCompilationResult* compile_bitwise_node(
      MaCode* C,
      mavka::ast::BitwiseNode* bitwise_node);
  MaCompilationResult* compile_bitwise_not_node(
      MaCode* C,
      mavka::ast::BitwiseNotNode* bitwise_not_node);
  MaCompilationResult* compile_break_node(MaCode* C,
                                          mavka::ast::BreakNode* break_node);
  MaCompilationResult* compile_call_node(MaCode* C,
                                         mavka::ast::CallNode* call_node);
  MaCompilationResult* compile_chain_node(MaCode* C,
                                          mavka::ast::ChainNode* chain_node);
  MaCompilationResult* compile_comparison_node(
      MaCode* C,
      mavka::ast::ComparisonNode* comparison_node);
  MaCompilationResult* compile_continue_node(
      MaCode* C,
      mavka::ast::ContinueNode* continue_node);
  MaCompilationResult* compile_dictionary_node(
      MaCode* C,
      mavka::ast::DictionaryNode* dictionary_node);
  MaCompilationResult* compile_diia_node(MaCode* C,
                                         mavka::ast::DiiaNode* diia_node);
  MaCompilationResult* compile_each_node(MaCode* C,
                                         mavka::ast::EachNode* each_node);
  MaCompilationResult* compile_eval_node(MaCode* C,
                                         mavka::ast::EvalNode* eval_node);
  MaCompilationResult* compile_from_to_complex_node(
      MaCode* C,
      mavka::ast::FromToComplexNode* from_to_complex_node);
  MaCompilationResult* compile_from_to_simple_node(
      MaCode* C,
      mavka::ast::FromToSimpleNode* from_to_simple_node);
  MaCompilationResult* compile_function_node(
      MaCode* C,
      mavka::ast::FunctionNode* function_node);
  MaCompilationResult* compile_get_element_node(
      MaCode* C,
      mavka::ast::GetElementNode* get_element_node);
  MaCompilationResult* compile_give_node(MaCode* C,
                                         mavka::ast::GiveNode* give_node);
  MaCompilationResult* compile_god_node(MaCode* C,
                                        mavka::ast::GodNode* god_node);
  MaCompilationResult* compile_identifier_node(
      MaCode* C,
      mavka::ast::IdentifierNode* identifier_node);
  MaCompilationResult* compile_if_node(MaCode* C, mavka::ast::IfNode* if_node);
  MaCompilationResult* compile_method_declaration_node(
      MaCode* C,
      mavka::ast::MethodDeclarationNode* method_declaration_node);
  MaCompilationResult* compile_mockup_diia_node(
      MaCode* C,
      mavka::ast::MockupDiiaNode* mockup_diia_node);
  MaCompilationResult* compile_mockup_module_node(
      MaCode* C,
      mavka::ast::MockupModuleNode* mockup_module_node);
  MaCompilationResult* compile_mockup_structure_node(
      MaCode* C,
      mavka::ast::MockupStructureNode* mockup_structure_node);
  MaCompilationResult* compile_mockup_subject_node(
      MaCode* C,
      mavka::ast::MockupSubjectNode* mockup_subject_node);
  MaCompilationResult* compile_module_node(MaCode* C,
                                           mavka::ast::ModuleNode* module_node);
  MaCompilationResult* compile_mrm_diia_node(
      MaCode* C,
      mavka::ast::MRMDiiaNode* mrm_diia_node);
  MaCompilationResult* compile_negative_node(
      MaCode* C,
      mavka::ast::NegativeNode* negative_node);
  MaCompilationResult* compile_not_node(MaCode* C,
                                        mavka::ast::NotNode* not_node);
  MaCompilationResult* compile_number_node(
      MaCode* C,
      const mavka::ast::NumberNode* number_node);
  MaCompilationResult* compile_positive_node(
      MaCode* C,
      mavka::ast::PositiveNode* positive_node);
  MaCompilationResult* compile_post_decrement_node(
      MaCode* C,
      mavka::ast::PostDecrementNode* post_decrement_node);
  MaCompilationResult* compile_post_increment_node(
      MaCode* C,
      mavka::ast::PostIncrementNode* post_increment_node);
  MaCompilationResult* compile_pre_decrement_node(
      MaCode* C,
      mavka::ast::PreDecrementNode* pre_decrement_node);
  MaCompilationResult* compile_pre_increment_node(
      MaCode* C,
      mavka::ast::PreIncrementNode* pre_increment_node);
  MaCompilationResult* compile_return_node(MaCode* C,
                                           mavka::ast::ReturnNode* return_node);
  MaCompilationResult* compile_string_node(MaCode* C,
                                           mavka::ast::StringNode* string_node);
  MaCompilationResult* compile_structure_node(
      MaCode* C,
      const mavka::ast::StructureNode* structure_node);
  MaCompilationResult* compile_take_module_node(
      MaCode* C,
      mavka::ast::TakeModuleNode* take_module_node);
  MaCompilationResult* compile_take_pak_node(
      MaCode* C,
      mavka::ast::TakePakNode* take_pak_node);
  MaCompilationResult* compile_ternary_node(
      MaCode* C,
      mavka::ast::TernaryNode* ternary_node);
  MaCompilationResult* compile_test_node(MaCode* C,
                                         mavka::ast::TestNode* test_node);
  MaCompilationResult* compile_throw_node(MaCode* C,
                                          mavka::ast::ThrowNode* throw_node);
  MaCompilationResult* compile_try_node(MaCode* C,
                                        mavka::ast::TryNode* try_node);
  MaCompilationResult* compile_type_value_single_node(
      MaCode* C,
      mavka::ast::TypeValueSingleNode* type_value_single_node);
  MaCompilationResult* compile_wait_node(MaCode* C,
                                         mavka::ast::WaitNode* wait_node);
  MaCompilationResult* compile_while_node(MaCode* C,
                                          mavka::ast::WhileNode* while_node);
} // namespace mavka::mama