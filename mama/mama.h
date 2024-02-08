#ifndef MAMA_H
#define MAMA_H

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <vector>

#include "../parser/ast.h"
#include "../parser/parser.h"
#include "../utils/tools.h"
#include "compiler/compiler.h"

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
#define MAG_BW_POSITIVE "чародія_додатнє"
#define MAG_BW_NEGATIVE "чародія_відʼємне"
#define MAG_GREATER "чародія_більше"
#define MAG_LESSER "чародія_менше"
#define MAG_GREATER_EQUAL "чародія_не_менше"
#define MAG_LESSER_EQUAL "чародія_не_більше"
#define MAG_CONTAINS "чародія_містить"
#define MAG_GET_ELEMENT "чародія_отримати"
#define MAG_PUT_ELEMENT "чародія_покласти"
#define MAG_CALL "чародія_викликати"
#define MAG_ITERATOR "чародія_перебір"

#define MA_CELL_EMPTY 0
#define MA_CELL_NUMBER 1
#define MA_CELL_OBJECT 2

#define MA_STRING 5
#define MA_OBJECT 6
#define MA_DIIA 7
#define MA_LIST 8
#define MA_DICT 9
#define MA_DIIA_NATIVE 11
#define MA_STRUCTURE 12
#define MA_METHOD 13

namespace mavka::mama {
  class MaMa;
  class MaScope;

#include "objects.h"

  class MaCallStackValue final {
   public:
    MaCell cell;
    MaScope* scope;
    int return_index;
    int catch_index;
    std::map<std::string, MaCell> args;
  };

  class MaMa final {
   public:
    std::stack<MaCell> stack;
    std::stack<MaCallStackValue*> call_stack;
    size_t i;

    MaObject* number_structure_cell;
    MaObject* boolean_structure_cell;
    MaObject* text_structure_cell;

    MaCell yes_cell;
    MaCell no_cell;
  };

  class MaScope final {
   public:
    MaScope* parent;
    std::map<std::string, MaCell> variables;

    inline bool has_variable(const std::string& name) {
      if (this->variables.contains(name)) {
        return true;
      }
      if (this->parent) {
        return this->parent->has_variable(name);
      }
      return false;
    }

    inline MaCell get_variable(const std::string& name) {
      if (this->variables.contains(name)) {
        return this->variables.at(name);
      }
      if (this->parent) {
        return this->parent->get_variable(name);
      }
      return MaCell{MA_CELL_EMPTY};
    }

    inline void set_variable(const std::string& name, MaCell value) {
      variables.insert_or_assign(name, value);
    }

    inline void delete_variable(const std::string& name) {
      variables.erase(name);
    }
  };

  std::string gettypename(size_t type);

  std::string getcelltypename(MaCell cell);

  std::string getcellstructurename(MaCell cell);

  std::string cell_to_string(MaCell cell);

  void print_cell(MaCell* cell);

  void print_instruction_with_index(int index, MaInstruction* instruction);

  void print_instruction(MaInstruction* instruction);

  void print_code(MaCode* C);

  void run(MaMa* M, MaCode* C);
} // namespace mavka::mama

#endif // MAMA_H
