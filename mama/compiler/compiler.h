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

MaCompilationResult error(const mavka::ast::ASTValue* ast_value,
                          const std::string& message);

MaCompilationResult success();

MaCompilationResult compile_node(MaMa* M,
                                 MaCode* code,
                                 const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_body(MaMa* M,
                                 MaCode* code,
                                 const std::vector<mavka::ast::ASTValue*>& body,
                                 bool nopop = false);
void find_each_node_jumps(MaMa* M,
                          MaCode* code,
                          const std::vector<mavka::ast::ASTValue*>& body,
                          std::vector<EachNodeJumps>& jumps);

MaCompilationResult compile_diia(
    MaMa* M,
    MaCode* code,
    bool async,
    const std::vector<ast::Generic*>& generics,
    const std::string& name,
    const std::vector<ast::Param*>& params,
    const std::vector<ast::TypeNode*>& return_types,
    const std::vector<ast::ASTValue*>& body);

MaCompilationResult compile_method(
    MaMa* M,
    MaCode* code,
    const std::string& structure,
    bool ee,
    bool async,
    const std::vector<ast::Generic*>& generics,
    const std::string& name,
    const std::vector<ast::Param*>& params,
    const std::vector<ast::TypeNode*>& return_types,
    const std::vector<ast::ASTValue*>& body);

MaCompilationResult compile_anon_diia_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_arithmetic_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_array_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_as_node(MaMa* M,
                                    MaCode* code,
                                    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_assign_by_element_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_assign_by_identifier_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_assign_node(MaMa* M,
                                        MaCode* code,
                                        const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_bitwise_node(MaMa* M,
                                         MaCode* code,
                                         const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_bitwise_not_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_break_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_call_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_chain_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_comparison_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_continue_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_dictionary_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_diia_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_each_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_eval_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_function_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_get_element_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_give_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_god_node(MaMa* M,
                                     MaCode* code,
                                     const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_identifier_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_if_node(MaMa* M,
                                    MaCode* code,
                                    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_list_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_method_declaration_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_mockup_diia_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_mockup_module_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_mockup_structure_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_mockup_subject_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_module_node(MaMa* M,
                                        MaCode* code,
                                        const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_mrm_diia_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_negative_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_not_node(MaMa* M,
                                     MaCode* code,
                                     const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_number_node(MaMa* M,
                                        MaCode* code,
                                        const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_positive_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_post_decrement_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_post_increment_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_pre_decrement_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_pre_increment_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_return_node(MaMa* M,
                                        MaCode* code,
                                        const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_string_node(MaMa* M,
                                        MaCode* code,
                                        const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_structure_node(
    MaMa* M,
    MaCode* code,
    const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_take_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_ternary_node(MaMa* M,
                                         MaCode* code,
                                         const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_test_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_throw_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_try_node(MaMa* M,
                                     MaCode* code,
                                     const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_type_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_wait_node(MaMa* M,
                                      MaCode* code,
                                      const mavka::ast::ASTValue* ast_value);
MaCompilationResult compile_while_node(MaMa* M,
                                       MaCode* code,
                                       const mavka::ast::ASTValue* ast_value);

#endif // COMPILER_H