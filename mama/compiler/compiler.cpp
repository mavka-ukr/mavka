#include "compiler.h"

namespace mavka::mama {
  MaInstruction* MaInstruction::create_push_number(const double& number) {
    return new MaInstruction(OP_PUSH_NUMBER, number);
  }

  MaInstruction* MaInstruction::create_store(const std::string& name) {
    return new MaInstruction(OP_STORE, 0, name);
  }

  MaInstruction* MaInstruction::create_load(const std::string& name) {
    return new MaInstruction(OP_LOAD, 0, name);
  }

  MaInstruction* MaInstruction::create_get(const std::string& name) {
    return new MaInstruction(OP_GET, 0, name);
  }

  MaInstruction* MaInstruction::create_set(const std::string& name) {
    return new MaInstruction(OP_SET, 0, name);
  }

  MaInstruction* MaInstruction::create_push_string(const std::string& name) {
    return new MaInstruction(OP_PUSH_STRING, 0, name);
  }

  MaInstruction* MaInstruction::create_load_param(const int& index,
                                                  const std::string& name) {
    return new MaInstruction(OP_LOAD_ARG, index, name);
  }

  MaCompilationResult* compile_node(MaCode* C, mavka::ast::ASTSome* node) {
    if (!node) {
      return error(nullptr, "null node");
    }
    if (node->is_nullptr()) {
      return error(nullptr, "nullptr node");
    }

    if (node->AnonDiiaNode) {
      return compile_anon_diia_node(C, node->AnonDiiaNode);
    }

    if (node->ArithmeticNode) {
      return compile_arithmetic_node(C, node->ArithmeticNode);
    }

    if (node->ArrayNode) {
      return compile_array_node(C, node->ArrayNode);
    }

    if (node->AsNode) {
      return compile_as_node(C, node->AsNode);
    }

    if (node->AssignByElementNode) {
      return compile_assign_by_element_node(C, node->AssignByElementNode);
    }

    if (node->AssignByIdentifierNode) {
      return compile_assign_by_identifier_node(C, node->AssignByIdentifierNode);
    }

    if (node->AssignSimpleNode) {
      return compile_assign_simple_node(C, node->AssignSimpleNode);
    }

    if (node->BitwiseNode) {
      return compile_bitwise_node(C, node->BitwiseNode);
    }

    if (node->BitwiseNotNode) {
      return compile_bitwise_not_node(C, node->BitwiseNotNode);
    }

    if (node->BreakNode) {
      return compile_break_node(C, node->BreakNode);
    }

    if (node->CallNode) {
      return compile_call_node(C, node->CallNode);
    }

    if (node->ChainNode) {
      return compile_chain_node(C, node->ChainNode);
    }

    if (node->ComparisonNode) {
      return compile_comparison_node(C, node->ComparisonNode);
    }

    if (node->ContinueNode) {
      return compile_continue_node(C, node->ContinueNode);
    }

    if (node->DictionaryNode) {
      return compile_dictionary_node(C, node->DictionaryNode);
    }

    if (node->DiiaNode) {
      return compile_diia_node(C, node->DiiaNode);
    }

    if (node->EachNode) {
      return compile_each_node(C, node->EachNode);
    }

    if (node->EvalNode) {
      return compile_eval_node(C, node->EvalNode);
    }

    if (node->FromToComplexNode) {
      return compile_from_to_complex_node(C, node->FromToComplexNode);
    }

    if (node->FromToSimpleNode) {
      return compile_from_to_simple_node(C, node->FromToSimpleNode);
    }

    if (node->FunctionNode) {
      return compile_function_node(C, node->FunctionNode);
    }

    if (node->GetElementNode) {
      return compile_get_element_node(C, node->GetElementNode);
    }

    if (node->GiveNode) {
      return compile_give_node(C, node->GiveNode);
    }

    if (node->GodNode) {
      return compile_god_node(C, node->GodNode);
    }

    if (node->IdentifierNode) {
      return compile_identifier_node(C, node->IdentifierNode);
    }

    if (node->IfNode) {
      return compile_if_node(C, node->IfNode);
    }

    if (node->MethodDeclarationNode) {
      return compile_method_declaration_node(C, node->MethodDeclarationNode);
    }

    if (node->MMLNode) {
      return compile_mml_node(C, node->MMLNode);
    }

    if (node->MockupDiiaNode) {
      return compile_mockup_diia_node(C, node->MockupDiiaNode);
    }

    if (node->MockupModuleNode) {
      return compile_mockup_module_node(C, node->MockupModuleNode);
    }

    if (node->MockupStructureNode) {
      return compile_mockup_structure_node(C, node->MockupStructureNode);
    }

    if (node->MockupSubjectNode) {
      return compile_mockup_subject_node(C, node->MockupSubjectNode);
    }

    if (node->ModuleNode) {
      return compile_module_node(C, node->ModuleNode);
    }

    if (node->MRMDiiaNode) {
      return compile_mrm_diia_node(C, node->MRMDiiaNode);
    }

    if (node->NegativeNode) {
      return compile_negative_node(C, node->NegativeNode);
    }

    if (node->NotNode) {
      return compile_not_node(C, node->NotNode);
    }

    if (node->NumberNode) {
      return compile_number_node(C, node->NumberNode);
    }

    if (node->PositiveNode) {
      return compile_positive_node(C, node->PositiveNode);
    }

    if (node->PostDecrementNode) {
      return compile_post_decrement_node(C, node->PostDecrementNode);
    }

    if (node->PostIncrementNode) {
      return compile_post_increment_node(C, node->PostIncrementNode);
    }

    if (node->PreDecrementNode) {
      return compile_pre_decrement_node(C, node->PreDecrementNode);
    }

    if (node->PreIncrementNode) {
      return compile_pre_increment_node(C, node->PreIncrementNode);
    }

    if (node->ReturnNode) {
      return compile_return_node(C, node->ReturnNode);
    }

    if (node->StringNode) {
      return compile_string_node(C, node->StringNode);
    }

    if (node->StructureNode) {
      return compile_structure_node(C, node->StructureNode);
    }

    if (node->TakeModuleNode) {
      return compile_take_module_node(C, node->TakeModuleNode);
    }

    if (node->TakePakNode) {
      return compile_take_pak_node(C, node->TakePakNode);
    }

    if (node->TernaryNode) {
      return compile_ternary_node(C, node->TernaryNode);
    }

    if (node->TestNode) {
      return compile_test_node(C, node->TestNode);
    }

    if (node->ThrowNode) {
      return compile_throw_node(C, node->ThrowNode);
    }

    if (node->TryNode) {
      return compile_try_node(C, node->TryNode);
    }

    if (node->TypeValueSingleNode) {
      return compile_type_value_single_node(C, node->TypeValueSingleNode);
    }

    if (node->WaitNode) {
      return compile_wait_node(C, node->WaitNode);
    }

    if (node->WhileNode) {
      return compile_while_node(C, node->WhileNode);
    }

    return error(node, "unsupported node");
  }

  MaCompilationResult* compile_body(
      MaCode* C,
      const std::vector<mavka::ast::ASTSome*>& body) {
    for (const auto node : body) {
      const auto result = compile_node(C, node);
      if (result->error) {
        return result;
      }
    }
    return success();
  }

  MaCompilationResult* error(mavka::ast::ASTSome* node,
                             const std::string& message) {
    const auto result = new MaCompilationResult();
    const auto error = new MaCompilationError();
    if (node) {
      error->line = mavka::ast::get_ast_node(node)->start_line;
      error->column = mavka::ast::get_ast_node(node)->start_column;
    }
    error->message = message;
    result->error = error;
    return result;
  }

  MaCompilationResult* success() {
    return new MaCompilationResult();
  }
} // namespace mavka::mama