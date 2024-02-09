#include "mama.h"

namespace mavka::mama {
  std::string gettypename(size_t type) {
    switch (type) {
      case MA_CELL_EMPTY:
        return "пусто";
      case MA_CELL_NUMBER:
        return "число";
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
        return ma_object_get(cell.v.object->structure, "назва")
            .v.object->d.string->data;
      }
    }
    return gettypename(cell.type);
  }

  std::string getcellstructurename(MaCell cell) {
    if (cell.type == MA_CELL_OBJECT) {
      return ma_object_get(cell.v.object->structure, "назва")
          .v.object->d.string->data;
    }
    return "";
  }

  std::string cell_to_string(MaCell cell, int depth) {
    if (cell.type == MA_CELL_EMPTY) {
      return "пусто";
    }
    if (cell.type == MA_CELL_NUMBER) {
      std::ostringstream stream;
      stream << cell.v.number;
      return stream.str();
    }
    if (cell.type == MA_CELL_OBJECT) {
      if (cell.v.object->type == MA_OBJECT) {
        std::vector<std::string> items;
        for (const auto& item : cell.v.object->properties) {
          items.push_back(item.first + "=" +
                          cell_to_string(item.second, depth + 1));
        }
        const auto name = ma_object_get(cell.v.object->structure, "назва");
        return name.v.object->d.string->data + "(" +
               internal::tools::implode(items, ", ") + ")";
      }
      if (cell.v.object->type == MA_OBJECT_DIIA) {
        const auto name_cell = ma_object_get(cell.v.object, "назва");
        if (name_cell.type == MA_CELL_EMPTY) {
          return "<дія>";
        }
        return "<дія " + name_cell.v.object->d.string->data + ">";
      }
      if (cell.v.object->type == MA_OBJECT_DIIA_NATIVE) {
        const auto name_cell = ma_object_get(cell.v.object, "назва");
        if (name_cell.type == MA_CELL_EMPTY) {
          return "<дія>";
        }
        return "<дія " + name_cell.v.object->d.string->data + ">";
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
        const auto name =
            ma_object_get(cell.v.object, "назва").v.object->d.string->data;
        return "<структура " + name + ">";
      }
    }
    return "<невідомо>";
  }

  void print_cell(MaCell* cell) {
    std::cout << "unknown" << std::endl;
  }

  void print_instruction_with_index(int index, MaInstruction instruction) {
    std::cout << index << ": " << getopname(instruction.op) << " [";
    if (instruction.op == OP_STORE) {
      std::cout << instruction.args.store->name;
    }
    std::cout << "]" << std::endl;
  }

  void print_code(MaMa* M) {
    for (int i = 0; i < M->code.size(); ++i) {
      const auto& instruction = M->code[i];
      print_instruction_with_index(i, instruction);
    }
  }
} // namespace mavka::mama
