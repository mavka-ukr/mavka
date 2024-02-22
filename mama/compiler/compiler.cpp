#include "../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_node(MaMa* M,
                                   MaCode* code,
                                   mavka::ast::ASTValue* ast_value) {
    if (!ast_value) {
      return error(nullptr, "null node");
    }

    if (ast_value->kind == ast::KindArithmeticNode) {
      return compile_arithmetic_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindAsNode) {
      return compile_as_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindAssignByIdentifierNode) {
      return compile_assign_by_identifier_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindAssignNode) {
      return compile_assign_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindBitwiseNode) {
      return compile_bitwise_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindBitwiseNotNode) {
      return compile_bitwise_not_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindBreakNode) {
      return compile_break_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindCallNode) {
      return compile_call_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindChainNode) {
      return compile_chain_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindComparisonNode) {
      return compile_comparison_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindContinueNode) {
      return compile_continue_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindDictionaryNode) {
      return compile_dictionary_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindDiiaNode) {
      return compile_diia_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindEachNode) {
      return compile_each_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindGetElementNode) {
      return compile_get_element_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindGiveNode) {
      return compile_give_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindGodNode) {
      return compile_god_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindIdentifierNode) {
      return compile_identifier_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindIfNode) {
      return compile_if_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindListNode) {
      return compile_array_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindMockupDiiaNode) {
      return compile_mockup_diia_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindMockupModuleNode) {
      return compile_mockup_module_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindMockupStructureNode) {
      return compile_mockup_structure_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindMockupSubjectNode) {
      return compile_mockup_subject_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindModuleNode) {
      return compile_module_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindMRMDiiaNode) {
      return compile_mrm_diia_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindNegativeNode) {
      return compile_negative_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindNotNode) {
      return compile_not_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindNumberNode) {
      return compile_number_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindPositiveNode) {
      return compile_positive_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindPostDecrementNode) {
      return compile_post_decrement_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindPostIncrementNode) {
      return compile_post_increment_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindPreDecrementNode) {
      return compile_pre_decrement_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindPreIncrementNode) {
      return compile_pre_increment_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindReturnNode) {
      return compile_return_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindStringNode) {
      return compile_string_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindStructureNode) {
      return compile_structure_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindTakeNode) {
      return compile_take_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindTernaryNode) {
      return compile_ternary_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindTestNode) {
      return compile_test_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindThrowNode) {
      return compile_throw_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindTryNode) {
      return compile_try_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindTypeNode) {
      return compile_type_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindWaitNode) {
      return compile_wait_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindWhileNode) {
      return compile_while_node(M, code, ast_value);
    }

    return error(ast_value, "unsupported node");
  }

  MaCompilationResult compile_body(
      MaMa* M,
      MaCode* code,
      const std::vector<mavka::ast::ASTValue*>& body) {
    for (const auto node : body) {
      if (!node) {
        continue;
      }
      const auto result = compile_node(M, code, node);
      if (result.error) {
        return result;
      }
      // if (ast_value->is_popable() && !nopop) {
      //   code->instructions.push_back(MaInstruction{OP_POP});
      // }
    }
    return success();
  }

  void find_each_node_jumps(MaMa* M,
                            MaCode* code,
                            const std::vector<mavka::ast::ASTValue*>& body,
                            std::vector<EachNodeJumps>& jumps) {
    for (const auto ast_value : body) {
      if (!ast_value) {
        continue;
      }
      if (ast_value->kind == ast::KindContinueNode) {
        jumps.push_back(
            EachNodeJumps{.continue_node = ast_value->data.ContinueNode});
      } else if (ast_value->kind == ast::KindBreakNode) {
        jumps.push_back(EachNodeJumps{.break_node = ast_value->data.BreakNode});
      }
      if (ast_value->kind == ast::KindIfNode) {
        find_each_node_jumps(M, code, ast_value->data.IfNode->body, jumps);
        find_each_node_jumps(M, code, ast_value->data.IfNode->else_body, jumps);
      }
      if (ast_value->kind == ast::KindTryNode) {
        find_each_node_jumps(M, code, ast_value->data.TryNode->body, jumps);
        find_each_node_jumps(M, code, ast_value->data.TryNode->catch_body,
                             jumps);
      }
    }
  }

  MaCompilationResult error(const mavka::ast::ASTValue* ast_value,
                            const std::string& message) {
    const auto error = new MaCompilationError();
    if (ast_value) {
      error->line = ast_value->start_line;
      error->column = ast_value->start_column;
    }
    error->message = message;
    return MaCompilationResult{.error = error};
  }

  MaCompilationResult success() {
    return MaCompilationResult{};
  }
} // namespace mavka::mama