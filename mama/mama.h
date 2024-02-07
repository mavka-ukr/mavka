#ifndef MAMA_H
#define MAMA_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <vector>

#include "../utils/tools.h"
#include "compiler/compiler.h"
#include "parser/ast.h"
#include "parser/parser.h"

#define JJ_DEBUG 0

#define JJ_MAG_ADD "чародія_додати"
#define JJ_MAG_SUB "чародія_відняти"
#define JJ_MAG_MUL "чародія_помножити"
#define JJ_MAG_DIV "чародія_поділити"
#define JJ_MAG_MOD "чародія_остача"
#define JJ_MAG_DIVDIV "чародія_частка"
#define JJ_MAG_POW "чародія_степінь"
#define JJ_MAG_BW_NOT "чародія_дні"
#define JJ_MAG_BW_XOR "чародія_вабо"
#define JJ_MAG_BW_OR "чародія_дабо"
#define JJ_MAG_BW_AND "чародія_ді"
#define JJ_MAG_BW_SHIFT_LEFT "чародія_вліво"
#define JJ_MAG_BW_SHIFT_RIGHT "чародія_вправо"
#define JJ_MAG_BW_POSITIVE "чародія_додатнє"
#define JJ_MAG_BW_NEGATIVE "чародія_відʼємне"
#define JJ_MAG_GREATER "чародія_більше"
#define JJ_MAG_LESSER "чародія_менше"
#define JJ_MAG_GREATER_EQUAL "чародія_не_менше"
#define JJ_MAG_LESSER_EQUAL "чародія_не_більше"
#define JJ_MAG_CONTAINS "чародія_містить"
#define JJ_MAG_GET_ELEMENT "чародія_отримати"
#define JJ_MAG_PUT_ELEMENT "чародія_покласти"
#define JJ_MAG_CALL "чародія_викликати"
#define JJ_MAG_ITERATOR "чародія_перебір"

#define MA_EMPTY 0
#define MA_YES 1
#define MA_NO 3
#define MA_NUMBER 4
#define MA_STRING 5
#define MA_OBJECT 6
#define MA_DIIA 7
#define MA_LIST 8
#define MA_DICTIONARY 9
#define MA_DIIA_NATIVE 11

namespace mavka::mama {
    class MaMa;
    class MaScope;
    class MaDiia;
    class MaCell;

    class MaCallStackValue final {
    public:
        MaCell* cell;
        MaScope* scope;
        int return_index;
    };

    class MaMa final {
    public:
        std::stack<MaCell *> stack;
        std::stack<MaCallStackValue *> call_stack;
        bool do_throw;
        size_t i;
        std::unordered_map<std::string, MaCell *> aR; // args register

        MaCell* empty_cell;
        MaCell* yes_cell;
        MaCell* no_cell;
    };

    class MaScope final {
    public:
        MaScope* parent;
        std::map<std::string, MaCell *> variables;

        bool has_variable(const std::string& name) {
            if (this->variables.contains(name)) {
                return true;
            }
            if (this->parent) {
                return this->parent->has_variable(name);
            }
            return false;
        }

        MaCell* get_variable(const std::string& name) {
            if (this->variables.contains(name)) {
                return this->variables.at(name);
            }
            if (this->parent) {
                return this->parent->get_variable(name);
            }
            return nullptr;
        }

        void set_variable(const std::string& name, MaCell* value) {
            variables.insert_or_assign(name, value);
        }

        void delete_variable(const std::string& name) { variables.erase(name); }
    };

    class MaCell final {
    public:
        unsigned char type;
        double number;
        std::string string;
        std::map<std::string, MaCell *> properties;
        int diia_index;
        std::vector<MaCell *> list;
        std::map<MaCell *, MaCell *> dictionary;
        std::map<std::string, MaCell *> args;

        void (*diia_native)(MaCell* self, MaMa* M, MaScope* S);

        MaCell* get_property(const std::string& name) {
            if (this->properties.contains(name)) {
                return this->properties.at(name);
            }
            return nullptr;
        }

        bool has_property(const std::string& name) {
            return this->properties.contains(name);
        }

        void set_property(const std::string& name, MaCell* value) {
            properties.insert_or_assign(name, value);
        }
    };

    inline MaCell* create_number(const double& number) {
        return new MaCell(MA_NUMBER, number);
    }

    inline MaCell* create_string(const std::string& string) {
        return new MaCell(MA_STRING, 0, string);
    }

    std::string getopname(size_t op);

    std::string gettypename(size_t type);

    std::string cell_to_string(MaCell* cell);

    void print_cell(MaCell* cell);

    void print_instruction_with_index(int index, MaInstruction* instruction);

    void print_instruction(MaInstruction* instruction);

    void print_code(MaCode* C);

    void run(MaMa* M, MaScope* S, MaCode* C);
} // namespace mavka::mama

#endif // MAMA_H
