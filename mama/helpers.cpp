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
    return "<невідомо>";
  }

  void print_cell(MaCell* cell) {
    std::cout << "unknown" << std::endl;
  }

  void print_instruction_with_index(int index, MaInstruction* instruction) {
    std::cout << index << ": " << getopname(instruction->op) << " ["
              << instruction->numval << ", "
              << "\"" + instruction->strval + "\"]" << std::endl;
  }

  void print_instruction(MaInstruction* instruction) {
    std::cout << getopname(instruction->op) << " [" << instruction->numval
              << ", "
              << "\"" + instruction->strval + "\"]" << std::endl;
  }

  void print_code(MaCode* C) {
    for (int i = 0; i < C->instructions.size(); ++i) {
      const auto instruction = C->instructions[i];
      print_instruction_with_index(i, instruction);
    }
  }
} // namespace mavka::mama
