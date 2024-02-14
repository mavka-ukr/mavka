#include "../mama.h"

std::string getopname(const OP op) {
  switch (op) {
    case OP_CONSTANT:
      return "OP_CONSTANT";
    case OP_ADD:
      return "OP_ADD";
    case OP_SUB:
      return "OP_SUB";
    case OP_MUL:
      return "OP_MUL";
    case OP_DIV:
      return "OP_DIV";
    case OP_MOD:
      return "OP_MOD";
    case OP_DIVDIV:
      return "OP_DIVDIV";
    case OP_POW:
      return "OP_POW";
    case OP_STORE:
      return "OP_STORE";
    case OP_LOAD:
      return "OP_LOAD";
    case OP_GET:
      return "OP_GET";
    case OP_SET:
      return "OP_SET";
    case OP_XOR:
      return "OP_XOR";
    case OP_BOR:
      return "OP_BOR";
    case OP_BAND:
      return "OP_BAND";
    case OP_SHL:
      return "OP_SHL";
    case OP_SHR:
      return "OP_SHR";
    case OP_BNOT:
      return "OP_BNOT";
    case OP_JUMP_IF_FALSE:
      return "OP_JUMP_IF_FALSE";
    case OP_JUMP_IF_TRUE:
      return "OP_JUMP_IF_TRUE";
    case OP_E_JUMP_IF_FALSE:
      return "OP_E_JUMP_IF_FALSE";
    case OP_E_JUMP_IF_TRUE:
      return "OP_E_JUMP_IF_TRUE";
    case OP_JUMP:
      return "OP_JUMP";
    case OP_THROW:
      return "OP_THROW";
    case OP_EQ:
      return "OP_EQ";
    case OP_LT:
      return "OP_LT";
    case OP_LE:
      return "OP_LE";
    case OP_CONTAINS:
      return "OP_CONTAINS";
    case OP_GT:
      return "OP_GT";
    case OP_GE:
      return "OP_GE";
    case OP_CALL:
      return "OP_CALL";
    case OP_RETURN:
      return "OP_RETURN";
    case OP_POP:
      return "OP_POP";
    case OP_LIST:
      return "OP_LIST";
    case OP_LIST_APPEND:
      return "OP_LIST_APPEND";
    case OP_NEGATIVE:
      return "OP_NEGATIVE";
    case OP_POSITIVE:
      return "OP_POSITIVE";
    case OP_DIIA:
      return "OP_DIIA";
    case OP_DICT:
      return "OP_DICT";
    case OP_DICT_SET:
      return "OP_DICT_SET";
    case OP_STRUCT:
      return "OP_STRUCT";
    case OP_GIVE:
      return "OP_GIVE";
    case OP_MODULE:
      return "OP_MODULE";
    case OP_TRY:
      return "OP_TRY";
    case OP_TRY_DONE:
      return "OP_TRY_DONE";
    case OP_NOT:
      return "OP_NOT";
    case OP_INITCALL:
      return "OP_INITCALL";
    case OP_DIIA_PARAM:
      return "OP_DIIA_PARAM";
    case OP_STRUCT_PARAM:
      return "OP_STRUCT_PARAM";
    case OP_STRUCT_METHOD:
      return "OP_STRUCT_METHOD";
    case OP_MODULE_DONE:
      return "OP_MODULE_DONE";
    case OP_STORE_ARG:
      return "OP_STORE_ARG";
    case OP_NUMBER:
      return "OP_NUMBER";
    case OP_EMPTY:
      return "OP_EMPTY";
    case OP_YES:
      return "OP_YES";
    case OP_NO:
      return "OP_NO";
    case OP_KEEP_MODULE:
      return "OP_KEEP_MODULE";
    case OP_IS:
      return "OP_IS";
    case OP_TAKE:
      return "OP_TAKE";
    case OP_LOAD_MODULE:
      return "OP_LOAD_MODULE";
    default:
      break;
  }
  return std::to_string(op);
}

namespace mavka::mama {
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