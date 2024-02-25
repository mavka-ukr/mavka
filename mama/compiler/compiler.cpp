#include "../mama.h"

namespace mavka::mama {
  MaCompilationResult compile_node(MaMa* M,
                                   MaCode* code,
                                   mavka::ast::ASTValue* ast_value) {
    if (!ast_value) {
      return error(nullptr, "null node");
    }

    //    if (ast_value->kind == ast::KindNone) {
    //      return success();
    //    }

    if (ast_value->kind == ast::KindPropertySetNode) {
      return compile_property_set_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindAssignNode) {
      return compile_assign_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindBinaryNode) {
      return compile_binary_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindBreakNode) {
      return compile_break_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindCallNode) {
      return compile_call_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindPropertyGetNode) {
      return compile_property_get_node(M, code, ast_value);
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
      return compile_list_node(M, code, ast_value);
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

    if (ast_value->kind == ast::KindNumberNode) {
      return compile_number_node(M, code, ast_value);
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

    if (ast_value->kind == ast::KindUnaryNode) {
      return compile_unary_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindWaitNode) {
      return compile_wait_node(M, code, ast_value);
    }

    if (ast_value->kind == ast::KindWhileNode) {
      return compile_while_node(M, code, ast_value);
    }

    return error(ast_value,
                 "unsupported node: " + std::to_string(ast_value->kind));
  }

  MaCompilationResult compile_body(
      MaMa* M,
      MaCode* code,
      const std::vector<mavka::ast::ASTValue*>& body) {
    for (const auto ast_value : body) {
      if (!ast_value) {
        continue;
      }
      if (ast_value->kind == ast::KindNone) {
        continue;
      }
      if (ast_value->kind == ast::KindBlockNode) {
        const auto result =
            compile_body(M, code, ast_value->data.BlockNode->body);
        if (result.error) {
          return result;
        }
        continue;
      }
      const auto result = compile_node(M, code, ast_value);
      if (result.error) {
        return result;
      }
      // if (ast_value->is_popable() && !nopop) {
      //   code->instructions.push_back(MaInstruction{VPop});
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

  MaCompilationResult error(mavka::ast::ASTValue* ast_value,
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