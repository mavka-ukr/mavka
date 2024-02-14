#include "../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_node(MaMa* M,
                                   MaCode* code,
                                   mavka::ast::ASTSome* node) {
    if (!node) {
      return error(nullptr, "null node");
    }
    if (node->is_nullptr()) {
      return error(nullptr, "nullptr node");
    }

    if (node->AnonDiiaNode) {
      return compile_anon_diia_node(M, code, node->AnonDiiaNode);
    }

    if (node->ArithmeticNode) {
      return compile_arithmetic_node(M, code, node->ArithmeticNode);
    }

    if (node->ArrayNode) {
      return compile_array_node(M, code, node->ArrayNode);
    }

    if (node->AsNode) {
      return compile_as_node(M, code, node->AsNode);
    }

    if (node->AssignByElementNode) {
      return compile_assign_by_element_node(M, code, node->AssignByElementNode);
    }

    if (node->AssignByIdentifierNode) {
      return compile_assign_by_identifier_node(M, code,
                                               node->AssignByIdentifierNode);
    }

    if (node->AssignSimpleNode) {
      return compile_assign_simple_node(M, code, node->AssignSimpleNode);
    }

    if (node->BitwiseNode) {
      return compile_bitwise_node(M, code, node->BitwiseNode);
    }

    if (node->BitwiseNotNode) {
      return compile_bitwise_not_node(M, code, node->BitwiseNotNode);
    }

    if (node->BreakNode) {
      return compile_break_node(M, code, node->BreakNode);
    }

    if (node->CallNode) {
      return compile_call_node(M, code, node->CallNode);
    }

    if (node->ChainNode) {
      return compile_chain_node(M, code, node->ChainNode);
    }

    if (node->ComparisonNode) {
      return compile_comparison_node(M, code, node->ComparisonNode);
    }

    if (node->ContinueNode) {
      return compile_continue_node(M, code, node->ContinueNode);
    }

    if (node->DictionaryNode) {
      return compile_dictionary_node(M, code, node->DictionaryNode);
    }

    if (node->DiiaNode) {
      return compile_diia_node(M, code, node->DiiaNode);
    }

    if (node->EachNode) {
      return compile_each_node(M, code, node->EachNode);
    }

    if (node->EvalNode) {
      return compile_eval_node(M, code, node->EvalNode);
    }

    if (node->FunctionNode) {
      return compile_function_node(M, code, node->FunctionNode);
    }

    if (node->GetElementNode) {
      return compile_get_element_node(M, code, node->GetElementNode);
    }

    if (node->GiveNode) {
      return compile_give_node(M, code, node->GiveNode);
    }

    if (node->GodNode) {
      return compile_god_node(M, code, node->GodNode);
    }

    if (node->IdentifierNode) {
      return compile_identifier_node(M, code, node->IdentifierNode);
    }

    if (node->IfNode) {
      return compile_if_node(M, code, node->IfNode);
    }

    if (node->MethodDeclarationNode) {
      return compile_method_declaration_node(M, code,
                                             node->MethodDeclarationNode);
    }

    if (node->MockupDiiaNode) {
      return compile_mockup_diia_node(M, code, node->MockupDiiaNode);
    }

    if (node->MockupModuleNode) {
      return compile_mockup_module_node(M, code, node->MockupModuleNode);
    }

    if (node->MockupStructureNode) {
      return compile_mockup_structure_node(M, code, node->MockupStructureNode);
    }

    if (node->MockupSubjectNode) {
      return compile_mockup_subject_node(M, code, node->MockupSubjectNode);
    }

    if (node->ModuleNode) {
      return compile_module_node(M, code, node->ModuleNode);
    }

    if (node->MRMDiiaNode) {
      return compile_mrm_diia_node(M, code, node->MRMDiiaNode);
    }

    if (node->NegativeNode) {
      return compile_negative_node(M, code, node->NegativeNode);
    }

    if (node->NotNode) {
      return compile_not_node(M, code, node->NotNode);
    }

    if (node->NumberNode) {
      return compile_number_node(M, code, node->NumberNode);
    }

    if (node->PositiveNode) {
      return compile_positive_node(M, code, node->PositiveNode);
    }

    if (node->PostDecrementNode) {
      return compile_post_decrement_node(M, code, node->PostDecrementNode);
    }

    if (node->PostIncrementNode) {
      return compile_post_increment_node(M, code, node->PostIncrementNode);
    }

    if (node->PreDecrementNode) {
      return compile_pre_decrement_node(M, code, node->PreDecrementNode);
    }

    if (node->PreIncrementNode) {
      return compile_pre_increment_node(M, code, node->PreIncrementNode);
    }

    if (node->ReturnNode) {
      return compile_return_node(M, code, node->ReturnNode);
    }

    if (node->StringNode) {
      return compile_string_node(M, code, node->StringNode);
    }

    if (node->StructureNode) {
      return compile_structure_node(M, code, node->StructureNode);
    }

    if (node->TakeModuleNode) {
      return compile_take_module_node(M, code, node->TakeModuleNode);
    }

    if (node->TakePakNode) {
      return compile_take_pak_node(M, code, node->TakePakNode);
    }

    if (node->TernaryNode) {
      return compile_ternary_node(M, code, node->TernaryNode);
    }

    if (node->TestNode) {
      return compile_test_node(M, code, node->TestNode);
    }

    if (node->ThrowNode) {
      return compile_throw_node(M, code, node->ThrowNode);
    }

    if (node->TryNode) {
      return compile_try_node(M, code, node->TryNode);
    }

    if (node->TypeValueSingleNode) {
      return compile_type_value_single_node(M, code, node->TypeValueSingleNode);
    }

    if (node->WaitNode) {
      return compile_wait_node(M, code, node->WaitNode);
    }

    if (node->WhileNode) {
      return compile_while_node(M, code, node->WhileNode);
    }

    return error(node, "unsupported node");
  }

  MaCompilationResult compile_body(
      MaMa* M,
      MaCode* code,
      const std::vector<mavka::ast::ASTSome*>& body) {
    for (const auto node : body) {
      if (!node) {
        continue;
      }
      if (node->is_nullptr()) {
        continue;
      }
      const auto result = compile_node(M, code, node);
      if (result.error) {
        return result;
      }
      if (node->is_popable()) {
        code->instructions.push_back(MaInstruction{OP_POP});
      }
    }
    return success();
  }

  void find_each_node_jumps(MaMa* M,
                            const std::vector<mavka::ast::ASTSome*>& body,
                            std::vector<EachNodeJumps>& jumps) {
    for (const auto node : body) {
      if (!node) {
        continue;
      }
      if (node->is_nullptr()) {
        continue;
      }
      if (node->ContinueNode) {
        jumps.push_back(EachNodeJumps{.continue_node = node->ContinueNode});
      } else if (node->BreakNode) {
        jumps.push_back(EachNodeJumps{.break_node = node->BreakNode});
      }
      if (node->IfNode) {
        find_each_node_jumps(M, node->IfNode->body, jumps);
        find_each_node_jumps(M, node->IfNode->else_body, jumps);
      }
      if (node->TryNode) {
        find_each_node_jumps(M, node->TryNode->body, jumps);
        find_each_node_jumps(M, node->TryNode->catch_body, jumps);
      }
    }
  }

  MaCompilationResult error(mavka::ast::ASTSome* node,
                            const std::string& message) {
    const auto error = new MaCompilationError();
    if (node) {
      error->line = mavka::ast::get_ast_node(node)->start_line;
      error->column = mavka::ast::get_ast_node(node)->start_column;
    }
    error->message = message;
    return MaCompilationResult{.error = error};
  }

  MaCompilationResult success() {
    return MaCompilationResult{};
  }
} // namespace mavka::mama