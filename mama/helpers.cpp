#include "mama.h"

namespace mavka::mama {
  std::string gettypename(size_t type) {
    switch (type) {
      case MA_NUMBER:
        return "MA_NUMBER";
      case MA_STRING:
        return "MA_STRING";
      case MA_EMPTY:
        return "MA_EMPTY";
      case MA_YES:
        return "MA_YES";
      case MA_NO:
        return "MA_NO";
      case MA_DIIA:
        return "MA_DIIA";
      default:
        break;
    }
    return std::to_string(type);
  }

  std::string cell_to_string(MaCell* cell) {
    if (cell->type == MA_NUMBER) {
      return std::to_string(cell->number());
    } else if (cell->type == MA_STRING) {
      return cell->string();
    } else if (cell->type == MA_EMPTY) {
      return "пусто";
    } else if (cell->type == MA_YES) {
      return "так";
    } else if (cell->type == MA_NO) {
      return "ні";
    } else if (cell->type == MA_DIIA) {
      return "<дія>";
    } else if (cell->type == MA_DICT) {
      return "<словник " + std::to_string(cell->cast_dict()->size()) + ">";
    } else if (cell->type == MA_LIST) {
      return "<список>";
    } else if (cell->type == MA_STRUCTURE) {
      return "<структура>";
    } else if (cell->type == MA_OBJECT) {
      return "<обʼєкт>";
    }
    return "<невідомо>";
  }

  void print_cell(MaCell* cell) {
    if (cell->type == MA_NUMBER) {
      std::cout << "number: " << std::to_string(cell->number()) << std::endl;
    } else if (cell->type == MA_STRING) {
      std::cout << "string: " << cell->string() << std::endl;
    } else if (cell->type == MA_EMPTY) {
      std::cout << "empty" << std::endl;
    } else if (cell->type == MA_YES) {
      std::cout << "yes" << std::endl;
    } else if (cell->type == MA_NO) {
      std::cout << "no" << std::endl;
    } else if (cell->type == MA_DIIA) {
      std::cout << "diia" << std::endl;
    } else if (cell->type == MA_LIST) {
      std::cout << "list" << std::endl;
    } else if (cell->type == MA_DICT) {
      std::cout << "dict" << std::endl;
    } else if (cell->type == MA_STRUCTURE) {
      std::cout << "structure" << std::endl;
    } else {
      std::cout << "unknown" << std::endl;
    }
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
