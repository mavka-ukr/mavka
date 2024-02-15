#ifndef MAMA_H
#define MAMA_H

#include <algorithm>
#include <cmath>
#include <codecvt>
#include <filesystem>
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
#define MA_MAKE_NUMBER(value) (MaCell{MA_CELL_NUMBER, {.number = (value)}})
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
#define IS_OBJECT_DIIA(cell) (cell).v.object->type == MA_OBJECT_DIIA
#define IS_OBJECT_DIIA_NATIVE(cell) \
  (cell).v.object->type == MA_OBJECT_DIIA_NATIVE
#define IS_STRING(cell) IS_OBJECT(cell) && IS_OBJECT_STRING(cell)

#define PUSH(cell) M->stack.push(cell)
#define PUSH_EMPTY() PUSH(MA_MAKE_EMPTY())
#define PUSH_NUMBER(v) PUSH(MA_MAKE_NUMBER((v)))
#define PUSH_YES() PUSH(MA_MAKE_YES())
#define PUSH_NO() PUSH(MA_MAKE_NO())

#define TOP() M->stack.top();
#define TOP_VALUE(name) const auto name = TOP();
#define POP() M->stack.pop();
#define POP_VALUE(name)    \
  const auto name = TOP(); \
  POP();

#define OBJECT_STRING_DATA(cell) (cell).v.object->d.string->data

#define READ_TOP_FRAME() const auto frame = M->frames.top();
#define FRAME_POP() M->frames.pop();
#define FRAME_PUSH(frame) M->frames.push(frame);

#define OBJECT_HAS(object, name) (object)->properties.contains((name))

namespace mavka::mama {
  struct MaMa;
  struct MaFrame;
  struct MaInstruction;
  class MaScope;
  struct MaCompilationError;
  struct MaCompilationResult;
  class MaString;
  class MaList;
  class MaDict;
  class MaDiia;
  class MaStructure;
  class MaDiiaNative;
  class MaModule;
  struct MaCell;
  struct MaObject;

#include "MaFrame.h"
#include "MaInstruction.h"
#include "MaObject.h"
#include "MaScope.h"
#include "compiler/compiler.h"
#include "helpers.h"

  struct MaMa {
    std::string cwd;

    std::vector<MaInstruction> code;
    std::vector<MaCell> constants;
    MaScope* global_scope;
    std::unordered_map<std::string, MaObject*> loaded_file_modules;

    size_t i;
    std::stack<MaCell> stack;
    std::stack<MaFrame*> frames;

    bool diia_native_throw;
    bool diia_native_repeat;
    std::function<void(MaMa* M)> diia_native_callback;

    MaObject* object_structure_object;
    MaObject* structure_structure_object;
    MaObject* number_structure_object;
    MaObject* logical_structure_object;
    MaObject* text_structure_object;
    MaObject* diia_structure_object;
    MaObject* list_structure_object;
    MaObject* dict_structure_object;
    MaObject* module_structure_object;

    size_t iterator_count;
  };

  void run(MaMa* M, size_t start_index = 0);

  struct MaInitcallOptions {
    size_t return_index;
    size_t line;
    size_t column;
  };

  bool initcall(MaMa* M,
                MaArgsType args_type,
                MaCell cell,
                MaInitcallOptions options);
} // namespace mavka::mama

#endif // MAMA_H
