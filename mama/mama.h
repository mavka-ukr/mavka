#ifndef MAMA_H
#define MAMA_H

#include <algorithm>
#include <cmath>
#include <codecvt>
#include <functional>
#include <iostream>
#include <locale>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <variant>
#include <vector>

#include <tsl/ordered_map.h>
#include "../external/parser/ast.h"
#include "../external/parser/parser.h"
#include "../utils/tools.h"
#include "MaInstruction.h"
#include "compiler/ops.h"

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

#define MAMA_DEBUG 0

#if MAMA_DEBUG == 0
#define DEBUG_LOG(value)
#else
#define DEBUG_LOG(value) std::cout << (value) << std::endl;
#endif

#if MAMA_DEBUG == 0
#define DEBUG_DO(value)
#else
#define DEBUG_DO(value) (value);
#endif

#define MAG_ADD "чародія_додати"
#define MAG_SUB "чародія_відняти"
#define MAG_MUL "чародія_помножити"
#define MAG_DIV "чародія_поділити"
#define MAG_MOD "чародія_остача"
#define MAG_DIVDIV "чародія_частка"
#define MAG_POW "чародія_степінь"
#define MAG_BW_NOT "чародія_дні"
#define MAG_BW_XOR "чародія_вабо"
#define MAG_BW_OR "чародія_дабо"
#define MAG_BW_AND "чародія_ді"
#define MAG_BW_SHIFT_LEFT "чародія_вліво"
#define MAG_BW_SHIFT_RIGHT "чародія_вправо"
#define MAG_POSITIVE "чародія_додатнє"
#define MAG_NEGATIVE "чародія_відʼємне"
#define MAG_GREATER "чародія_більше"
#define MAG_LESSER "чародія_менше"
#define MAG_GREATER_EQUAL "чародія_не_менше"
#define MAG_LESSER_EQUAL "чародія_не_більше"
#define MAG_CONTAINS "чародія_містить"
#define MAG_GET_ELEMENT "чародія_отримати"
#define MAG_SET_ELEMENT "чародія_покласти"
#define MAG_CALL "чародія_викликати"
#define MAG_ITERATOR "чародія_перебір"
#define MAG_NUMBER "чародія_число"
#define MAG_TEXT "чародія_текст"
#define MAG_LOGICAL "чародія_логічне"
#define MAG_BYTES "чародія_байти"
#define MAG_BYTES "чародія_байти"

#define MA_CELL_EMPTY 0
#define MA_CELL_NUMBER 1
#define MA_CELL_YES 2
#define MA_CELL_NO 3
#define MA_CELL_OBJECT 4

#define MA_OBJECT 0
#define MA_OBJECT_DIIA 1
#define MA_OBJECT_DIIA_NATIVE 2
#define MA_OBJECT_STRING 3
#define MA_OBJECT_LIST 4
#define MA_OBJECT_DICT 5
#define MA_OBJECT_STRUCTURE 6
#define MA_OBJECT_MODULE 7

#define MA_MAKE_EMPTY() (MaCell{MA_CELL_EMPTY})
#define MA_MAKE_NUBMER(value) (MaCell{MA_CELL_NUMBER, {.number = (value)}})
#define MA_MAKE_INTEGER(value) \
  (MaCell{MA_CELL_NUMBER, {.number = ((double)(value))}})
#define MA_MAKE_YES() (MaCell{MA_CELL_YES})
#define MA_MAKE_NO() (MaCell{MA_CELL_NO})
#define MA_MAKE_OBJECT(value) (MaCell{MA_CELL_OBJECT, {.object = (value)}})

#define IS_EMPTY(cell) ((cell).type == MA_CELL_EMPTY)
#define IS_NUMBER(cell) ((cell).type == MA_CELL_NUMBER)
#define IS_YES(cell) ((cell).type == MA_CELL_YES)
#define IS_NO(cell) ((cell).type == MA_CELL_NO)
#define IS_OBJECT(cell) ((cell).type == MA_CELL_OBJECT)
#define IS_OBJECT_STRING(cell) (cell).v.object->type == MA_OBJECT_STRING
#define IS_OBJECT_STRUCTURE(cell) (cell).v.object->type == MA_OBJECT_STRUCTURE
#define IS_STRING(cell) IS_OBJECT(cell) && IS_OBJECT_STRING(cell)

#define PUSH(cell) M->stack.push(cell)
#define PUSH_EMPTY() PUSH(MA_MAKE_EMPTY())
#define PUSH_NUMBER(v) PUSH(MA_MAKE_NUBMER((v)))
#define PUSH_YES() PUSH(MA_MAKE_YES())
#define PUSH_NO() PUSH(MA_MAKE_NO())

#define TOP() M->stack.top();
#define TOP_VALUE(name) const auto name = TOP();
#define POP() M->stack.pop();
#define POP_VALUE(name)    \
  const auto name = TOP(); \
  POP();

#define OBJECT_STRING_DATA(cell) (cell).v.object->d.string->data

#define READ_TOP_FRAME() const auto frame = M->call_stack.top();
#define FRAME_POP() M->call_stack.pop();
#define FRAME_PUSH(frame) M->call_stack.push(frame);

namespace mavka::mama {
  struct MaMa;
  struct MaCallFrame;
  struct MaInstruction;
  class MaScope;
  class MaCompilationError;
  class MaCompilationResult;

#include "objects.h"

  struct MaCallFrame {
    MaScope* scope;
    MaObject* diia;
    MaObject* diia_native;
    MaObject* structure;
    MaObject* module;
    size_t return_index;
    std::function<void(MaMa* M)> return_callback;
    size_t catch_index;
    std::map<std::string, MaCell> args;
    size_t line;
    size_t column;
  };

  struct MaMa {
    std::vector<MaInstruction> code;
    size_t iterator_count;
    std::vector<MaCell> constants;

    MaScope* global_scope;
    std::stack<MaCell> stack;
    size_t i;
    std::stack<MaCallFrame*> call_stack;
    bool need_to_throw;
    std::function<bool(MaMa* M, MaInstruction& I)> diia_native_redirect;

    MaObject* object_structure_object;
    MaObject* structure_structure_object;
    MaObject* number_structure_object;
    MaObject* logical_structure_object;
    MaObject* text_structure_object;
    MaObject* diia_structure_object;
    MaObject* list_structure_object;
    MaObject* dict_structure_object;
    MaObject* module_structure_object;
  };

  class MaScope final {
   public:
    MaScope* parent;
    std::map<std::string, MaCell> variables;

    bool has_variable(const std::string& name);
    bool has_local_variable(const std::string& name);
    MaCell get_variable(const std::string& name);
    MaCell get_local_variable(const std::string& name);
    void set_variable(const std::string& name, MaCell value);
    void delete_variable(const std::string& name);
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

  struct EachNodeJumps {
    ast::BreakNode* break_node;
    ast::ContinueNode* continue_node;
  };

  MaCompilationResult error(mavka::ast::ASTSome* node,
                            const std::string& message);

  MaCompilationResult success();

  MaCompilationResult compile_node(MaMa* M, mavka::ast::ASTSome* node);
  MaCompilationResult compile_body(
      MaMa* M,
      const std::vector<mavka::ast::ASTSome*>& body);
  void find_each_node_jumps(MaMa* M,
                            const std::vector<mavka::ast::ASTSome*>& body,
                            std::vector<EachNodeJumps>& jumps);

  MaCompilationResult compile_diia(
      MaMa* M,
      bool async,
      const std::vector<ast::GenericNode*>& generics,
      const std::string& name,
      const std::vector<ast::ParamNode*>& params,
      const std::vector<ast::TypeValueSingleNode*>& return_types,
      const std::vector<ast::ASTSome*>& body);

  MaCompilationResult compile_method(
      MaMa* M,
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
      const mavka::ast::AnonDiiaNode* anon_diia_node);
  MaCompilationResult compile_arithmetic_node(
      MaMa* M,
      const mavka::ast::ArithmeticNode* arithmetic_node);
  MaCompilationResult compile_array_node(
      MaMa* M,
      const mavka::ast::ArrayNode* array_node);
  MaCompilationResult compile_as_node(MaMa* M, mavka::ast::AsNode* as_node);
  MaCompilationResult compile_assign_by_element_node(
      MaMa* M,
      mavka::ast::AssignByElementNode* assign_by_element_node);
  MaCompilationResult compile_assign_by_identifier_node(
      MaMa* M,
      mavka::ast::AssignByIdentifierNode* assign_by_identifier_node);
  MaCompilationResult compile_assign_simple_node(
      MaMa* M,
      mavka::ast::AssignSimpleNode* assign_simple_node);
  MaCompilationResult compile_bitwise_node(
      MaMa* M,
      const mavka::ast::BitwiseNode* bitwise_node);
  MaCompilationResult compile_bitwise_not_node(
      MaMa* M,
      const mavka::ast::BitwiseNotNode* bitwise_not_node);
  MaCompilationResult compile_break_node(MaMa* M,
                                         mavka::ast::BreakNode* break_node);
  MaCompilationResult compile_call_node(MaMa* M,
                                        const mavka::ast::CallNode* call_node);
  MaCompilationResult compile_chain_node(
      MaMa* M,
      const mavka::ast::ChainNode* chain_node);
  MaCompilationResult compile_comparison_node(
      MaMa* M,
      mavka::ast::ComparisonNode* comparison_node);
  MaCompilationResult compile_continue_node(
      MaMa* M,
      mavka::ast::ContinueNode* continue_node);
  MaCompilationResult compile_dictionary_node(
      MaMa* M,
      const mavka::ast::DictionaryNode* dictionary_node);
  MaCompilationResult compile_diia_node(MaMa* M,
                                        mavka::ast::DiiaNode* diia_node);
  MaCompilationResult compile_each_node(MaMa* M,
                                        mavka::ast::EachNode* each_node);
  MaCompilationResult compile_eval_node(MaMa* M,
                                        mavka::ast::EvalNode* eval_node);
  MaCompilationResult compile_function_node(
      MaMa* M,
      const mavka::ast::FunctionNode* function_node);
  MaCompilationResult compile_get_element_node(
      MaMa* M,
      const mavka::ast::GetElementNode* get_element_node);
  MaCompilationResult compile_give_node(MaMa* M,
                                        mavka::ast::GiveNode* give_node);
  MaCompilationResult compile_god_node(MaMa* M, mavka::ast::GodNode* god_node);
  MaCompilationResult compile_identifier_node(
      MaMa* M,
      const mavka::ast::IdentifierNode* identifier_node);
  MaCompilationResult compile_if_node(MaMa* M,
                                      const mavka::ast::IfNode* if_node);
  MaCompilationResult compile_method_declaration_node(
      MaMa* M,
      mavka::ast::MethodDeclarationNode* method_declaration_node);
  MaCompilationResult compile_mockup_diia_node(
      MaMa* M,
      mavka::ast::MockupDiiaNode* mockup_diia_node);
  MaCompilationResult compile_mockup_module_node(
      MaMa* M,
      mavka::ast::MockupModuleNode* mockup_module_node);
  MaCompilationResult compile_mockup_structure_node(
      MaMa* M,
      mavka::ast::MockupStructureNode* mockup_structure_node);
  MaCompilationResult compile_mockup_subject_node(
      MaMa* M,
      mavka::ast::MockupSubjectNode* mockup_subject_node);
  MaCompilationResult compile_module_node(
      MaMa* M,
      const mavka::ast::ModuleNode* module_node);
  MaCompilationResult compile_mrm_diia_node(
      MaMa* M,
      mavka::ast::MRMDiiaNode* mrm_diia_node);
  MaCompilationResult compile_negative_node(
      MaMa* M,
      const mavka::ast::NegativeNode* negative_node);
  MaCompilationResult compile_not_node(MaMa* M,
                                       const mavka::ast::NotNode* not_node);
  MaCompilationResult compile_number_node(
      MaMa* M,
      const mavka::ast::NumberNode* number_node);
  MaCompilationResult compile_positive_node(
      MaMa* M,
      const mavka::ast::PositiveNode* positive_node);
  MaCompilationResult compile_post_decrement_node(
      MaMa* M,
      mavka::ast::PostDecrementNode* post_decrement_node);
  MaCompilationResult compile_post_increment_node(
      MaMa* M,
      mavka::ast::PostIncrementNode* post_increment_node);
  MaCompilationResult compile_pre_decrement_node(
      MaMa* M,
      mavka::ast::PreDecrementNode* pre_decrement_node);
  MaCompilationResult compile_pre_increment_node(
      MaMa* M,
      mavka::ast::PreIncrementNode* pre_increment_node);
  MaCompilationResult compile_return_node(
      MaMa* M,
      const mavka::ast::ReturnNode* return_node);
  MaCompilationResult compile_string_node(
      MaMa* M,
      const mavka::ast::StringNode* string_node);
  MaCompilationResult compile_structure_node(
      MaMa* M,
      mavka::ast::StructureNode* structure_node);
  MaCompilationResult compile_take_module_node(
      MaMa* M,
      mavka::ast::TakeModuleNode* take_module_node);
  MaCompilationResult compile_take_pak_node(
      MaMa* M,
      mavka::ast::TakePakNode* take_pak_node);
  MaCompilationResult compile_ternary_node(
      MaMa* M,
      mavka::ast::TernaryNode* ternary_node);
  MaCompilationResult compile_test_node(MaMa* M,
                                        mavka::ast::TestNode* test_node);
  MaCompilationResult compile_throw_node(
      MaMa* M,
      const mavka::ast::ThrowNode* throw_node);
  MaCompilationResult compile_try_node(MaMa* M,
                                       const mavka::ast::TryNode* try_node);
  MaCompilationResult compile_type_value_single_node(
      MaMa* M,
      mavka::ast::TypeValueSingleNode* type_value_single_node);
  MaCompilationResult compile_wait_node(MaMa* M,
                                        mavka::ast::WaitNode* wait_node);
  MaCompilationResult compile_while_node(
      MaMa* M,
      const mavka::ast::WhileNode* while_node);

  std::string gettypename(size_t type);

  std::string getcelltypename(MaCell cell);

  std::string getcellstructurename(MaCell cell);

  std::string cell_to_string(MaCell cell, int depth = 0);

  void print_cell(MaCell* cell);

  void print_instruction_with_index(int index, MaInstruction instruction);

  void print_code(MaMa* M);

  void run(MaMa* M);

  inline bool initcall(MaMa* M,
                       MaCell cell,
                       const size_t return_index,
                       const std::function<void(MaMa*)>& return_callback) {
    READ_TOP_FRAME();

  repeat_op_initcall:
    if (cell.type == MA_CELL_OBJECT) {
      const auto object = cell.v.object;

      if (object->type == MA_OBJECT_DIIA_NATIVE) {
        FRAME_PUSH(new MaCallFrame({.scope = frame->scope,
                                    .diia_native = object,
                                    .return_index = return_index,
                                    .return_callback = return_callback}));
        return true;
      }
      if (object->type == MA_OBJECT_DIIA) {
        FRAME_PUSH(new MaCallFrame({.scope = frame->scope,
                                    .diia = object,
                                    .return_index = return_index,
                                    .return_callback = return_callback}));
        return true;
      }
      if (object->properties.contains(MAG_CALL)) {
        cell = object->properties[MAG_CALL];
        goto repeat_op_initcall;
      }
      if (object->type == MA_OBJECT_STRUCTURE) {
        FRAME_PUSH((new MaCallFrame{.scope = frame->scope,
                                  .structure = object,
                                  .return_index = return_index,
                                  .return_callback = return_callback}));
          return true;
        }
      }

    return false;
  }
} // namespace mavka::mama

#endif // MAMA_H
