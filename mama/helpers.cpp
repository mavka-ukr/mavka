#include "mama.h"

namespace mavka::mama {
  std::string getopname(size_t op) {
    switch (op) {
      case OP_PUSH_NUMBER:
        return "OP_PUSH_NUMBER";
      case OP_ADD:
        return "OP_ADD";
      case OP_SUB:
        return "OP_SUB";
      case OP_MUL:
        return "OP_MUL";
      case OP_DIV:
        return "OP_DIV";
      case OP_MOD:
        return "OP_MOD";
      case OP_DIVDIV:
        return "OP_DIVDIV";
      case OP_POW:
        return "OP_POW";
      case OP_STORE:
        return "OP_STORE";
      case OP_LOAD:
        return "OP_LOAD";
      case OP_GET:
        return "OP_GET";
      case OP_SET:
        return "OP_SET";
      case OP_PUSH_STRING:
        return "OP_PUSH_STRING";
      case OP_XOR:
        return "OP_XOR";
      case OP_BOR:
        return "OP_BOR";
      case OP_BAND:
        return "OP_BAND";
      case OP_SHL:
        return "OP_SHL";
      case OP_SHR:
        return "OP_SHR";
      case OP_BNOT:
        return "OP_BNOT";
      case OP_JUMP_IF_FALSE:
        return "OP_JUMP_IF_FALSE";
      case OP_JUMP:
        return "OP_JUMP";
      case OP_THROW:
        return "OP_THROW";
      case OP_EQ:
        return "OP_EQ";
      case OP_NE:
        return "OP_NE";
      case OP_LT:
        return "OP_LT";
      case OP_LE:
        return "OP_LE";
      case OP_GT:
        return "OP_GT";
      case OP_GE:
        return "OP_GE";
      case OP_AND:
        return "OP_AND";
      case OP_OR:
        return "OP_OR";
      case OP_CALL:
        return "OP_CALL";
      case OP_RETURN:
        return "OP_RETURN";
      case OP_LOAD_ARG:
        return "OP_LOAD_ARG";
      case OP_POP:
        return "OP_POP";
      case OP_SET_ELEMENT:
        return "OP_SET_ELEMENT";
      case OP_SET_ARG:
        return "OP_SET_ARG";
      case OP_LIST:
        return "OP_LIST";
      case OP_LIST_APPEND:
        return "OP_LIST_APPEND";
      case OP_GET_ELEMENT:
        return "OP_GET_ELEMENT";
      case OP_NEGATIVE:
        return "OP_NEGATIVE";
      case OP_POSITIVE:
        return "OP_POSITIVE";
      case OP_PUSH_DIIA:
        return "OP_PUSH_DIIA";
      case OP_EACH_SIMPLE:
        return "OP_EACH_SIMPLE";
      case OP_CLEAR_ARGS:
        return "OP_CLEAR_ARGS";
      default:
        break;
    }
    return std::to_string(op);
  }

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
      return std::to_string(cell->number);
    } else if (cell->type == MA_STRING) {
      return cell->string;
    } else if (cell->type == MA_EMPTY) {
      return "пусто";
    } else if (cell->type == MA_YES) {
      return "так";
    } else if (cell->type == MA_NO) {
      return "ні";
    } else if (cell->type == MA_DIIA) {
      return "<дія>";
    }
    return "<невідомо>";
  }

  void print_cell(MaCell* cell) {
    if (cell->type == MA_NUMBER) {
      std::cout << "number: " << std::to_string(cell->number) << std::endl;
    } else if (cell->type == MA_STRING) {
      std::cout << "string: " << cell->string << std::endl;
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
