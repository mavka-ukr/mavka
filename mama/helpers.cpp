#include "mama.h"

namespace mavka::mama {
  std::string gettypename(size_t type) {
    switch (type) {
      case MA_CELL_EMPTY:
        return "пусто";
      case MA_CELL_NUMBER:
        return "число";
      case MA_CELL_YES:
        return "логічне";
      case MA_CELL_NO:
        return "логічне";
      case MA_CELL_OBJECT:
        return "обʼєкт";
      default:
        break;
    }
    return std::to_string(type);
  }

  std::string getcelltypename(MaCell cell) {
    if (cell.type == MA_CELL_OBJECT) {
      if (cell.v.object->structure) {
        return cell.v.object->structure->d.structure->name;
      }
    }
    return gettypename(cell.type);
  }

  std::string getcellstructurename(MaCell cell) {
    if (cell.type == MA_CELL_OBJECT) {
      return cell.v.object->structure->d.structure->name;
    }
    return "";
  }

  std::string cell_to_string(MaCell cell, int depth) {
    if (cell.type == MA_CELL_EMPTY) {
      return "пусто";
    }
    if (cell.type == MA_CELL_NUMBER) {
      return ma_number_to_string(cell.v.number);
    }
    if (cell.type == MA_CELL_YES) {
      return "так";
    }
    if (cell.type == MA_CELL_NO) {
      return "ні";
    }
    if (cell.type == MA_CELL_OBJECT) {
      if (cell.v.object->type == MA_OBJECT) {
        std::vector<std::string> items;
        for (const auto& param :
             cell.v.object->structure->d.structure->params) {
          const auto value = ma_object_get(cell.v.object, param.name);
          items.push_back(param.name + "=" + cell_to_string(value, depth + 1));
        }
        return cell.v.object->structure->d.structure->name + "(" +
               internal::tools::implode(items, ", ") + ")";
      }
      if (cell.v.object->type == MA_OBJECT_DIIA) {
        const auto name = cell.v.object->d.diia->name;
        if (name == "") {
          return "<дія>";
        }
        return "<дія " + name + ">";
      }
      if (cell.v.object->type == MA_OBJECT_DIIA_NATIVE) {
        const auto name = cell.v.object->d.diia_native->name;
        if (name == "") {
          return "<дія>";
        }
        return "<дія " + name + ">";
      }
      if (cell.v.object->type == MA_OBJECT_STRING) {
        if (depth > 0) {
          return "\"" + cell.v.object->d.string->data + "\"";
        }
        return cell.v.object->d.string->data;
      }
      if (cell.v.object->type == MA_OBJECT_LIST) {
        std::vector<std::string> items;
        for (const auto& item : cell.v.object->d.list->data) {
          items.push_back(cell_to_string(item, depth + 1));
        }
        return "[" + internal::tools::implode(items, ", ") + "]";
      }
      if (cell.v.object->type == MA_OBJECT_DICT) {
        std::vector<std::string> items;
        for (const auto& item : cell.v.object->d.dict->data) {
          items.push_back(cell_to_string(item.first, depth + 1) + "=" +
                          cell_to_string(item.second, depth + 1));
        }
        return "(" + internal::tools::implode(items, ", ") + ")";
      }
      if (cell.v.object->type == MA_OBJECT_STRUCTURE) {
        return "<структура " + cell.v.object->d.structure->name + ">";
      }
      if (cell.v.object->type == MA_OBJECT_MODULE) {
        const auto name = cell.v.object->d.module->name;
        std::vector<std::string> items;
        for (const auto& [k, v] : cell.v.object->properties) {
          if (k != "назва") {
            items.push_back(k);
          }
        }
        return "<модуль " + name + "[" + internal::tools::implode(items, ", ") +
               "]>";
      }
    }
    return "<невідомо>";
  }

  void print_cell(MaCell* cell) {
    std::cout << "unknown" << std::endl;
  }

  void print_instruction_with_index(MaCode* code,
                                    int index,
                                    MaInstruction instruction) {
    std::cout << code << "[" << index << "]: " << getopname(instruction.v)
              << " [";
    if (instruction.v == VStore) {
      std::cout << instruction.args.store->name;
    }
    if (instruction.v == VLoad) {
      std::cout << instruction.args.load->name;
    }
    if (instruction.v == VJumpIfTrue ||
        instruction.v == VEJumpIfTrue) {
      std::cout << instruction.args.jumpiftrue;
    }
    if (instruction.v == VJumpIfFalse ||
        instruction.v == VEJumpIfFalse) {
      std::cout << instruction.args.jumpiffalse;
    }
    if (instruction.v == VJump) {
      std::cout << instruction.args.jump;
    }
    if (instruction.v == VStoreArg) {
      std::cout << instruction.args.storearg->name;
    }
    if (instruction.v == VNumber) {
      std::cout << instruction.args.number;
    }
    std::cout << "]" << std::endl;
  }

  void print_code(MaCode* code) {
    for (int i = 0; i < code->instructions.size(); ++i) {
      const auto& instruction = code->instructions[i];
      print_instruction_with_index(code, i, instruction);
    }
  }
} // namespace mavka::mama
