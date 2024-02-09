#include "../mama.h"

namespace mavka::mama {
  MaInstruction create_constant_instruction(MaCell* constant) {
    return MaInstruction{OP_CONSTANT, {.constant = constant}};
  }

  MaCompilationResult compile_node(MaMa* M, mavka::ast::ASTSome* node) {
    if (!node) {
      return error(nullptr, "null node");
    }
    if (node->is_nullptr()) {
      return error(nullptr, "nullptr node");
    }

    if (node->AnonDiiaNode) {
      return compile_anon_diia_node(M, node->AnonDiiaNode);
    }

    if (node->ArithmeticNode) {
      return compile_arithmetic_node(M, node->ArithmeticNode);
    }

    if (node->ArrayNode) {
      return compile_array_node(M, node->ArrayNode);
    }

    if (node->AsNode) {
      return compile_as_node(M, node->AsNode);
    }

    if (node->AssignByElementNode) {
      return compile_assign_by_element_node(M, node->AssignByElementNode);
    }

    if (node->AssignByIdentifierNode) {
      return compile_assign_by_identifier_node(M, node->AssignByIdentifierNode);
    }

    if (node->AssignSimpleNode) {
      return compile_assign_simple_node(M, node->AssignSimpleNode);
    }

    if (node->BitwiseNode) {
      return compile_bitwise_node(M, node->BitwiseNode);
    }

    if (node->BitwiseNotNode) {
      return compile_bitwise_not_node(M, node->BitwiseNotNode);
    }

    if (node->BreakNode) {
      return compile_break_node(M, node->BreakNode);
    }

    if (node->CallNode) {
      return compile_call_node(M, node->CallNode);
    }

    if (node->ChainNode) {
      return compile_chain_node(M, node->ChainNode);
    }

    if (node->ComparisonNode) {
      return compile_comparison_node(M, node->ComparisonNode);
    }

    if (node->ContinueNode) {
      return compile_continue_node(M, node->ContinueNode);
    }

    if (node->DictionaryNode) {
      return compile_dictionary_node(M, node->DictionaryNode);
    }

    if (node->DiiaNode) {
      return compile_diia_node(M, node->DiiaNode);
    }

    if (node->EachNode) {
      return compile_each_node(M, node->EachNode);
    }

    if (node->EvalNode) {
      return compile_eval_node(M, node->EvalNode);
    }

    if (node->FromToComplexNode) {
      return compile_from_to_complex_node(M, node->FromToComplexNode);
    }

    if (node->FromToSimpleNode) {
      return compile_from_to_simple_node(M, node->FromToSimpleNode);
    }

    if (node->FunctionNode) {
      return compile_function_node(M, node->FunctionNode);
    }

    if (node->GetElementNode) {
      return compile_get_element_node(M, node->GetElementNode);
    }

    if (node->GiveNode) {
      return compile_give_node(M, node->GiveNode);
    }

    if (node->GodNode) {
      return compile_god_node(M, node->GodNode);
    }

    if (node->IdentifierNode) {
      return compile_identifier_node(M, node->IdentifierNode);
    }

    if (node->IfNode) {
      return compile_if_node(M, node->IfNode);
    }

    if (node->MethodDeclarationNode) {
      return compile_method_declaration_node(M, node->MethodDeclarationNode);
    }

    if (node->MockupDiiaNode) {
      return compile_mockup_diia_node(M, node->MockupDiiaNode);
    }

    if (node->MockupModuleNode) {
      return compile_mockup_module_node(M, node->MockupModuleNode);
    }

    if (node->MockupStructureNode) {
      return compile_mockup_structure_node(M, node->MockupStructureNode);
    }

    if (node->MockupSubjectNode) {
      return compile_mockup_subject_node(M, node->MockupSubjectNode);
    }

    if (node->ModuleNode) {
      return compile_module_node(M, node->ModuleNode);
    }

    if (node->MRMDiiaNode) {
      return compile_mrm_diia_node(M, node->MRMDiiaNode);
    }

    if (node->NegativeNode) {
      return compile_negative_node(M, node->NegativeNode);
    }

    if (node->NotNode) {
      return compile_not_node(M, node->NotNode);
    }

    if (node->NumberNode) {
      return compile_number_node(M, node->NumberNode);
    }

    if (node->PositiveNode) {
      return compile_positive_node(M, node->PositiveNode);
    }

    if (node->PostDecrementNode) {
      return compile_post_decrement_node(M, node->PostDecrementNode);
    }

    if (node->PostIncrementNode) {
      return compile_post_increment_node(M, node->PostIncrementNode);
    }

    if (node->PreDecrementNode) {
      return compile_pre_decrement_node(M, node->PreDecrementNode);
    }

    if (node->PreIncrementNode) {
      return compile_pre_increment_node(M, node->PreIncrementNode);
    }

    if (node->ReturnNode) {
      return compile_return_node(M, node->ReturnNode);
    }

    if (node->StringNode) {
      return compile_string_node(M, node->StringNode);
    }

    if (node->StructureNode) {
      return compile_structure_node(M, node->StructureNode);
    }

    if (node->TakeModuleNode) {
      return compile_take_module_node(M, node->TakeModuleNode);
    }

    if (node->TakePakNode) {
      return compile_take_pak_node(M, node->TakePakNode);
    }

    if (node->TernaryNode) {
      return compile_ternary_node(M, node->TernaryNode);
    }

    if (node->TestNode) {
      return compile_test_node(M, node->TestNode);
    }

    if (node->ThrowNode) {
      return compile_throw_node(M, node->ThrowNode);
    }

    if (node->TryNode) {
      return compile_try_node(M, node->TryNode);
    }

    if (node->TypeValueSingleNode) {
      return compile_type_value_single_node(M, node->TypeValueSingleNode);
    }

    if (node->WaitNode) {
      return compile_wait_node(M, node->WaitNode);
    }

    if (node->WhileNode) {
      return compile_while_node(M, node->WhileNode);
    }

    return error(node, "unsupported node");
  }

  MaCompilationResult compile_body(
      MaMa* M,
      const std::vector<mavka::ast::ASTSome*>& body) {
    for (const auto node : body) {
      if (!node) {
        continue;
      }
      if (node->is_nullptr()) {
        continue;
      }
      const auto result = compile_node(M, node);
      if (result.error) {
        return result;
      }
      if (node->is_popable()) {
        M->code.push_back(MaInstruction{OP_POP});
      }
    }
    return success();
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