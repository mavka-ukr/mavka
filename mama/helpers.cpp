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
    return gettypename(cell.type);
  }

  std::string getcellstructurename(MaCell cell) {
    if (cell.type == MA_CELL_OBJECT) {
      return ma_object_get(cell.v.object->structure, "назва")
          .v.object->d.string->data;
    }
    return "";
  }

  std::string cell_to_string(MaCell cell) {
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
        return "<обʼєкт>";
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
        return cell.v.object->d.string->data;
      }
      if (cell.v.object->type == MA_OBJECT_LIST) {
        return "<список>";
      }
      if (cell.v.object->type == MA_OBJECT_DICT) {
        return "<словник>";
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
    std::cout << index << ": " << getopname(instruction.op) << std::endl;
  }

  void print_instruction(MaInstruction instruction) {
    std::cout << getopname(instruction.op) << std::endl;
  }

  void print_code(MaMa* M) {
    for (int i = 0; i < M->instructions.size(); ++i) {
      const auto& instruction = M->instructions[i];
      print_instruction_with_index(i, instruction);
    }
  }
} // namespace mavka::mama
