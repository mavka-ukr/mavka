#ifndef COMPILER_H
#define COMPILER_H

struct MaCompilationError {
  std::string path;
  size_t line = 0;
  size_t column = 0;
  std::string message;
};

struct MaCompilationResult {
  MaCompilationError* error;
};

struct EachNodeJumps {
  ast::BreakNode* break_node;
  ast::ContinueNode* continue_node;
};

MaCompilationResult error(mavka::ast::ASTSome* node,
                          const std::string& message);

MaCompilationResult success();

MaCompilationResult compile_node(MaMa* M,
                                 MaCode* code,
                                 mavka::ast::ASTSome* node);
MaCompilationResult compile_body(MaMa* M,
                                 MaCode* code,
                                 const std::vector<mavka::ast::ASTSome*>& body,
                                 bool nopop = false);
void find_each_node_jumps(MaMa* M,
                          MaCode* code,
                          const std::vector<mavka::ast::ASTSome*>& body,
                          std::vector<EachNodeJumps>& jumps);

MaCompilationResult compile_diia(
    MaMa* M,
    MaCode* code,
    bool async,
    const std::vector<ast::GenericNode*>& generics,
    const std::string& name,
    const std::vector<ast::ParamNode*>& params,
    const std::vector<ast::TypeValueSingleNode*>& return_types,
    const std::vector<ast::ASTSome*>& body);

MaCompilationResult compile_method(
    MaMa* M,
    MaCode* code,
    const std::string& structure,
    bool ee,
    bool async,
    const std::vector<ast::GenericNode*>& generics,
    const std::string& name,
    const std::vector<ast::ParamNode*>& params,
    const std::vector<ast::TypeValueSingleNode*>& return_types,
    const std::vector<ast::ASTSome*>& body);

MaCompilationResult compile_anon_diia_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::AnonDiiaNode* anon_diia_node);
MaCompilationResult compile_arithmetic_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ArithmeticNode* arithmetic_node);
MaCompilationResult compile_array_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::ArrayNode* array_node);
MaCompilationResult compile_as_node(MaMa* M,
                                    MaCode* code,
                                    mavka::ast::AsNode* as_node);
MaCompilationResult compile_assign_by_element_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::AssignByElementNode* assign_by_element_node);
MaCompilationResult compile_assign_by_identifier_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::AssignByIdentifierNode* assign_by_identifier_node);
MaCompilationResult compile_assign_simple_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::AssignSimpleNode* assign_simple_node);
MaCompilationResult compile_bitwise_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::BitwiseNode* bitwise_node);
MaCompilationResult compile_bitwise_not_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::BitwiseNotNode* bitwise_not_node);
MaCompilationResult compile_break_node(MaMa* M,
                                       MaCode* code,
                                       mavka::ast::BreakNode* break_node);
MaCompilationResult compile_call_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::CallNode* call_node);
MaCompilationResult compile_chain_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::ChainNode* chain_node);
MaCompilationResult compile_comparison_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::ComparisonNode* comparison_node);
MaCompilationResult compile_continue_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::ContinueNode* continue_node);
MaCompilationResult compile_dictionary_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::DictionaryNode* dictionary_node);
MaCompilationResult compile_diia_node(MaMa* M,
                                      MaCode* code,
                                      mavka::ast::DiiaNode* diia_node);
MaCompilationResult compile_each_node(MaMa* M,
                                      MaCode* code,
                                      mavka::ast::EachNode* each_node);
MaCompilationResult compile_eval_node(MaMa* M,
                                      MaCode* code,
                                      mavka::ast::EvalNode* eval_node);
MaCompilationResult compile_function_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::FunctionNode* function_node);
MaCompilationResult compile_get_element_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::GetElementNode* get_element_node);
MaCompilationResult compile_give_node(MaMa* M,
                                      MaCode* code,
                                      mavka::ast::GiveNode* give_node);
MaCompilationResult compile_god_node(MaMa* M,
                                     MaCode* code,
                                     mavka::ast::GodNode* god_node);
MaCompilationResult compile_identifier_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::IdentifierNode* identifier_node);
MaCompilationResult compile_if_node(MaMa* M,
                                    MaCode* code,
                                    const mavka::ast::IfNode* if_node);
MaCompilationResult compile_method_declaration_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::MethodDeclarationNode* method_declaration_node);
MaCompilationResult compile_mockup_diia_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::MockupDiiaNode* mockup_diia_node);
MaCompilationResult compile_mockup_module_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::MockupModuleNode* mockup_module_node);
MaCompilationResult compile_mockup_structure_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::MockupStructureNode* mockup_structure_node);
MaCompilationResult compile_mockup_subject_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::MockupSubjectNode* mockup_subject_node);
MaCompilationResult compile_module_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ModuleNode* module_node);
MaCompilationResult compile_mrm_diia_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::MRMDiiaNode* mrm_diia_node);
MaCompilationResult compile_negative_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::NegativeNode* negative_node);
MaCompilationResult compile_not_node(MaMa* M,
                                     MaCode* code,
                                     const mavka::ast::NotNode* not_node);
MaCompilationResult compile_number_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::NumberNode* number_node);
MaCompilationResult compile_positive_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::PositiveNode* positive_node);
MaCompilationResult compile_post_decrement_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::PostDecrementNode* post_decrement_node);
MaCompilationResult compile_post_increment_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::PostIncrementNode* post_increment_node);
MaCompilationResult compile_pre_decrement_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::PreDecrementNode* pre_decrement_node);
MaCompilationResult compile_pre_increment_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::PreIncrementNode* pre_increment_node);
MaCompilationResult compile_return_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ReturnNode* return_node);
MaCompilationResult compile_string_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::StringNode* string_node);
MaCompilationResult compile_structure_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::StructureNode* structure_node);
MaCompilationResult compile_take_module_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::TakeModuleNode* take_module_node);
MaCompilationResult compile_take_pak_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::TakePakNode* take_pak_node);
MaCompilationResult compile_ternary_node(MaMa* M,
                                         MaCode* code,
                                         mavka::ast::TernaryNode* ternary_node);
MaCompilationResult compile_test_node(MaMa* M,
                                      MaCode* code,
                                      mavka::ast::TestNode* test_node);
MaCompilationResult compile_throw_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::ThrowNode* throw_node);
MaCompilationResult compile_try_node(MaMa* M,
                                     MaCode* code,
                                     const mavka::ast::TryNode* try_node);
MaCompilationResult compile_type_value_single_node(
    MaMa* M,
    MaCode* code,
    mavka::ast::TypeValueSingleNode* type_value_single_node);
MaCompilationResult compile_wait_node(MaMa* M,
                                      MaCode* code,
                                      mavka::ast::WaitNode* wait_node);
MaCompilationResult compile_while_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::WhileNode* while_node);

#endif // COMPILER_H