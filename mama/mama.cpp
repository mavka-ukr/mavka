#include "mama.h"

#define DO_THROW_STRING(v)               \
  M->throw_cell = create_string(M, (v)); \
  throw MaException();

#define DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(varname, cell)                 \
  DO_THROW_STRING("Дію \"" + std::string(varname) +                       \
                  "\" не визначено для типу \"" + getcelltypename(cell) + \
                  "\".")

#define DO_THROW_PROP_NOT_DEFINED_FOR_TYPE(varname, cell)                 \
  DO_THROW_STRING("Властивість \"" + std::string(varname) +               \
                  "\" не визначено для типу \"" + getcelltypename(cell) + \
                  "\".")

#define DO_THROW_CANNOT_CALL_CELL(cell) \
  DO_THROW_STRING("Неможливо викликати \"" + getcelltypename(cell) + "\".")

#define OBJECT_GET(cell, varname, propname)                       \
  MaCell varname{};                                               \
  if ((cell).v.object->get) {                                     \
    varname = (cell).v.object->get(M, (cell).v.object, propname); \
  } else {                                                        \
    if ((cell).v.object->properties.contains(propname)) {         \
      varname = (cell).v.object->properties[propname];            \
    } else {                                                      \
      DO_THROW_PROP_NOT_DEFINED_FOR_TYPE(propname, cell)          \
    }                                                             \
  }

#define OBJECT_SET(cell, propname, value)                      \
  if ((cell).v.object->set) {                                  \
    (cell).v.object->set(M, (cell).v.object, propname, value); \
  } else {                                                     \
    (cell).v.object->properties[propname] = value;             \
  }

namespace mavka::mama {
  void restore_frames(MaMa* M, size_t frames_size) {
    while (M->frames.size() > frames_size) {
      FRAME_POP();
    }
  }

  void run(MaMa* M,
           std::stack<MaCell>& stack,
           MaCode* code,
           size_t start_index) {
    auto size = code->instructions.size();
    size_t i = start_index;
    for (;;) {
    start:
      if (i >= size) {
        return;
      }
      auto I = code->instructions[i];

      DEBUG_DO(print_instruction_with_index(code, i, I))

      switch (I.v) {
        case VPop: {
          POP();
          break;
        }
        case VConstant: {
          PUSH(M->constants[I.args.constant]);
          break;
        }
        case VNumber: {
          PUSH_NUMBER(I.args.number);
          break;
        }
        case VEmpty: {
          PUSH_EMPTY();
          break;
        }
        case VYes: {
          PUSH_YES();
          break;
        }
        case VNo: {
          PUSH_NO();
          break;
        }
        case VInitargs: {
          const auto args = new MaArgs(I.args.initargs->args_type);
          PUSH_ARGS(args);
          break;
        }
        case VPushArg: {
          POP_VALUE(value);
          TOP_VALUE(args);
          ARGS_PUSH(args, value);
          break;
        }
        case VStoreArg: {
          POP_VALUE(value);
          TOP_VALUE(args);
          ARGS_SET(args, I.args.store->name, value);
          break;
        }
        case VCall: {
          POP_VALUE(args_cell);
          POP_VALUE(cell);
          PUSH(docall(M, cell, args_cell.v.args, I.location));
          break;
        }
        case VReturn: {
          auto frame = M->frames.top();
          FRAME_POP();
          while (frame->type != FRAME_TYPE_CALL) {
            frame = M->frames.top();
            FRAME_POP();
          }
          return;
        }
        case VDiia: {
          READ_TOP_FRAME();
          const auto diia_cell =
              create_diia(M, I.args.diia->name, I.args.diia->code, nullptr);
          diia_cell.v.object->d.diia->scope = frame->scope;
          diia_cell.v.object->d.diia->module = M->current_module;
          PUSH(diia_cell);
          break;
        }
        case VDiiaParam: {
          POP_VALUE(default_value_cell);
          TOP_VALUE(diia_cell);
          diia_cell.v.object->d.diia->params.push_back(
              MaDiiaParam{.name = I.args.diiaparam->name,
                          .default_value = default_value_cell});
          break;
        }
        case VStore: {
          POP_VALUE(value);
          READ_TOP_FRAME();
          frame->scope->set_variable(I.args.store->name, value);
          break;
        }
        case VLoad: {
          READ_TOP_FRAME();
          const auto scope = frame->scope;
          if (scope->has_variable(I.args.load->name)) {
            PUSH(scope->get_variable(I.args.load->name));
            break;
          }
          DO_THROW_STRING("Субʼєкт \"" + I.args.load->name + "\" не визначено.")
        }
        case VJump: {
          i = I.args.jump;
          goto start;
        }
        case VJumpIfTrue: {
          POP_VALUE(cell);
          if (IS_NUMBER(cell) && cell.v.number != 0.0) {
            i = I.args.jumpiftrue;
            goto start;
          }
          if (!IS_NO(cell)) {
            i = I.args.jumpiftrue;
            goto start;
          }
          break;
        }
        case VJumpIfFalse: {
          POP_VALUE(cell);
          if (IS_EMPTY(cell)) {
            i = I.args.jumpiffalse;
            goto start;
          } else if (IS_NUMBER(cell)) {
            if (cell.v.number == 0.0) {
              i = I.args.jumpiffalse;
              goto start;
            }
          } else if (IS_NO(cell)) {
            i = I.args.jumpiffalse;
            goto start;
          }
          break;
        }
        case VEJumpIfTrue: {
          TOP_VALUE(cell);
          if (IS_NUMBER(cell)) {
            if (cell.v.number != 0.0) {
              i = I.args.jumpiftrue;
              goto start;
            }
          } else if (!IS_NO(cell)) {
            i = I.args.jumpiftrue;
            goto start;
          }
          break;
        }
        case VEJumpIfFalse: {
          TOP_VALUE(cell);
          if (IS_EMPTY(cell)) {
            i = I.args.jumpiffalse;
            goto start;
          }
          if (IS_NUMBER(cell) && cell.v.number == 0.0) {
            i = I.args.jumpiffalse;
            goto start;
          }
          if (IS_NO(cell)) {
            i = I.args.jumpiffalse;
            goto start;
          }
          break;
        }
        case VGet: {
          POP_VALUE(cell);
          if (IS_OBJECT(cell)) {
            OBJECT_GET(cell, value, I.args.get->name);
            PUSH(value);
            break;
          }
          DO_THROW_PROP_NOT_DEFINED_FOR_TYPE(I.args.get->name, cell);
          break;
        }
        case VSet: {
          POP_VALUE(cell);
          POP_VALUE(value);
          if (IS_OBJECT(cell)) {
            if (IS_OBJECT_STRING(cell)) {
              break;
            }
            OBJECT_SET(cell, I.args.set->name, value);
            break;
          }
          break;
        }
        case VESetR: {
          POP_VALUE(value);
          TOP_VALUE(cell);
          if (IS_OBJECT(cell)) {
            ma_object_set(cell.v.object, I.args.set->name, value);
          }
          break;
        }
        case VTry: {
          const auto frame_size = M->frames.size();
          try {
            run(M, stack, I.args.try_->try_code, 0);
          } catch (const MaException& e) {
            const auto value = M->throw_cell;
            PUSH(value);
            restore_frames(M, frame_size);
            run(M, stack, I.args.try_->catch_code, 0);
          }
          break;
        }
        case VTryDone: {
          FRAME_POP();
          i = I.args.trydone->index;
          break;
        }
        case VThrow: {
          throw MaException();
        }
        case VList: {
          PUSH(create_list(M));
          break;
        }
        case VListAppend: {
          POP_VALUE(value);
          TOP_VALUE(list_cell);
          list_cell.v.object->d.list->append(value);
          break;
        }
        case VDict: {
          PUSH(create_dict(M));
          break;
        }
        case VDictSet: {
          POP_VALUE(value);
          TOP_VALUE(dict_cell);
          dict_cell.v.object->d.dict->set(create_string(M, I.args.dictset->key),
                                          value);
          break;
        }
        case VStruct: {
          const auto structure_cell = create_structure(M, I.args.struct_->name);
          PUSH(structure_cell);
          break;
        }
        case VStructParam: {
          POP_VALUE(default_value_cell);
          TOP_VALUE(structure_cell);
          structure_cell.v.object->d.structure->params.push_back(
              MaDiiaParam{.name = I.args.diiaparam->name,
                          .default_value = default_value_cell});
          break;
        }
        case VStructMethod: {
          POP_VALUE(diia_cell);
          TOP_VALUE(structure_cell);
          if (IS_OBJECT(structure_cell)) {
            if (IS_OBJECT_STRUCTURE(structure_cell)) {
              structure_cell.v.object->d.structure->methods.push_back(
                  diia_cell.v.object);
              break;
            }
          }
          DO_THROW_STRING("Неможливо створити метод для типу " +
                          getcelltypename(structure_cell))
        }
        case VModule: {
          READ_TOP_FRAME();
          const auto module_cell = create_module(M, I.args.module->name);
          const auto module_scope = new MaScope(frame->scope);
          const auto cf_data =
              new MaFrameModuleData{.module = module_cell.v.object};
          FRAME_PUSH(MaFrame::module(module_scope, cf_data));
          frame->scope->set_variable(I.args.module->name, module_cell);
          break;
        }
        case VGive: {
          POP_VALUE(value);
          READ_TOP_FRAME();
          if (frame->type == FRAME_TYPE_MODULE) {
            frame->data.module->module->properties.insert_or_assign(
                I.args.give->name, value);
            break;
          }
          DO_THROW_STRING("Неможливо дати \"" + I.args.give->name + "\".")
        }
        case VModuleDone: {
          FRAME_POP();
          break;
        }
        case VEq: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_EMPTY(left)) {
            if (IS_EMPTY(right)) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
          } else if (IS_YES(left)) {
            if (IS_YES(right)) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
          } else if (IS_NO(left)) {
            if (IS_NO(right)) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
          } else if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              if (left.v.number == right.v.number) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            } else {
              PUSH_NO();
            }
          } else if (IS_OBJECT(left)) {
            if (IS_OBJECT_STRING(left)) {
              if (IS_OBJECT(right) && IS_OBJECT_STRING(right)) {
                if (OBJECT_STRING_DATA(left) == OBJECT_STRING_DATA(right)) {
                  PUSH_YES();
                } else {
                  PUSH_NO();
                }
              } else {
                PUSH_NO();
              }
            } else {
              if (left.v.object == right.v.object) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            }
          } else {
            PUSH_NO();
          }
          break;
        }
        case VGt: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              if (left.v.number > right.v.number) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_GREATER) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_GREATER);
            PUSH(ma_call(M, diia_cell, {right}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_GREATER, left);
          }
          break;
        }
        case VGe: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              if (left.v.number >= right.v.number) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_GREATER_EQUAL) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_GREATER_EQUAL);
            PUSH(ma_call(M, diia_cell, {right}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_GREATER_EQUAL, left);
          }
          break;
        }
        case VLt: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              if (left.v.number < right.v.number) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_LESSER) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_LESSER);
            PUSH(ma_call(M, diia_cell, {right}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_LESSER, left);
          }
          break;
        }
        case VLe: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              if (left.v.number <= right.v.number) {
                PUSH_YES();
              } else {
                PUSH_NO();
              }
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_LESSER_EQUAL) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_LESSER_EQUAL);
            PUSH(ma_call(M, diia_cell, {right}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_LESSER_EQUAL, left);
          }
          break;
        }
        case VContains: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_CONTAINS);
            PUSH(ma_call(M, diia_cell, {right}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_CONTAINS, left);
          }
          break;
        }
        case VIs: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_EMPTY(left)) {
            if (IS_EMPTY(right)) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
            break;
          }
          if (IS_NUMBER(left)) {
            if (right.v.object == M->number_structure_object) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
            break;
          }
          if (IS_YES(left) || IS_NO(left)) {
            if (right.v.object == M->logical_structure_object) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
            break;
          }
          if (IS_OBJECT(right) && IS_OBJECT(left)) {
            if (right.v.object == left.v.object->structure) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
            break;
          }
          PUSH_NO();
          break;
        }
        case VNot: {
          POP_VALUE(value);
          if (IS_EMPTY(value)) {
            PUSH_YES();
          } else if (IS_NUMBER(value)) {
            if (value.v.number == 0.0) {
              PUSH_YES();
            } else {
              PUSH_NO();
            }
          } else if (IS_YES(value)) {
            PUSH_NO();
          } else if (IS_NO(value)) {
            PUSH_YES();
          } else {
            PUSH_NO();
          }
          break;
        }
        case VNegative: {
          POP_VALUE(value);
          if (IS_NUMBER(value)) {
            PUSH_NUMBER(-value.v.number);
          } else if (IS_OBJECT(value)) {
            OBJECT_GET(value, diia_cell, MAG_NEGATIVE);
            PUSH(ma_call(M, diia_cell, {}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_NEGATIVE, value);
          }
          break;
        }
        case VPositive: {
          POP_VALUE(value);
          if (IS_NUMBER(value)) {
            PUSH_NUMBER(value.v.number * -1);
          } else if (IS_OBJECT(value)) {
            OBJECT_GET(value, diia_cell, MAG_POSITIVE);
            PUSH(ma_call(M, diia_cell, {}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_POSITIVE, value);
          }
          break;
        }
        case VBnot: {
          POP_VALUE(value);
          if (IS_NUMBER(value)) {
            PUSH_NUMBER(
                static_cast<double>(~static_cast<long>(value.v.number)));
          } else if (IS_OBJECT(value)) {
            OBJECT_GET(value, diia_cell, MAG_BW_NOT);
            PUSH(ma_call(M, diia_cell, {}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_NOT, value);
          }
          break;
        }
        case VAdd: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(left.v.number + right.v.number);
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_ADD) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_ADD);
            PUSH(ma_call(M, diia_cell, {right}, I.location));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_ADD, left);
          }
          break;
        }
        case VSub: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(left.v.number - right.v.number);
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_SUB) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_SUB);
            PUSH(ma_call(M, diia_cell, {right}, I.location));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_SUB, left);
          }
          break;
        }
        case VMul: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(left.v.number * right.v.number);
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_MUL) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_MUL);
            PUSH(ma_call(M, diia_cell, {right}, I.location));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_MUL, left);
          }
          break;
        }
        case VDiv: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(left.v.number / right.v.number);
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_DIV) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_DIV);
            PUSH(ma_call(M, diia_cell, {right}, I.location));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_DIV, left);
          }
          break;
        }
        case VMod: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(fmod(left.v.number, right.v.number));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_MOD) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_MOD);
            PUSH(ma_call(M, diia_cell, {right}, I.location));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_MOD, left);
          }
          break;
        }
        case VDivDiv: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(floor(left.v.number / right.v.number));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_DIVDIV) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_DIVDIV);
            PUSH(ma_call(M, diia_cell, {right}, I.location));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_DIVDIV, left);
          }
          break;
        }
        case VPow: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(pow(left.v.number, right.v.number));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_POW) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_POW);
            PUSH(ma_call(M, diia_cell, {right}, I.location));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_POW, left);
          }
          break;
        }
        case VXor: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(
                  static_cast<double>(static_cast<long>(left.v.number) ^
                                      static_cast<long>(right.v.number)));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_BW_XOR) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_BW_XOR);
            PUSH(ma_call(M, diia_cell, {right}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_XOR, left);
          }
          break;
        }
        case VBor: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(
                  static_cast<double>(static_cast<long>(left.v.number) |
                                      static_cast<long>(right.v.number)));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_BW_OR) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_BW_OR);
            PUSH(ma_call(M, diia_cell, {right}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_OR, left);
          }
          break;
        }
        case VBand: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(
                  static_cast<double>(static_cast<long>(left.v.number) &
                                      static_cast<long>(right.v.number)));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_BW_AND) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_BW_AND);
            PUSH(ma_call(M, diia_cell, {right}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_AND, left);
          }
          break;
        }
        case VShl: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(
                  static_cast<double>(static_cast<long>(left.v.number)
                                      << static_cast<long>(right.v.number)));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_BW_SHIFT_LEFT) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_BW_SHIFT_LEFT);
            PUSH(ma_call(M, diia_cell, {right}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_SHIFT_LEFT, left);
          }
          break;
        }
        case VShr: {
          POP_VALUE(right);
          POP_VALUE(left);
          if (IS_NUMBER(left)) {
            if (IS_NUMBER(right)) {
              PUSH_NUMBER(
                  static_cast<double>(static_cast<long>(left.v.number) >>
                                      static_cast<long>(right.v.number)));
            } else {
              DO_THROW_STRING("Дія \"" + std::string(MAG_BW_SHIFT_RIGHT) +
                              "\" для типу \"число\" "
                              "очікує параметром значення типу \"число\".")
            }
          } else if (IS_OBJECT(left)) {
            OBJECT_GET(left, diia_cell, MAG_BW_SHIFT_RIGHT);
            PUSH(ma_call(M, diia_cell, {right}, nullptr));
            break;
          } else {
            DO_THROW_DIIA_NOT_DEFINED_FOR_TYPE(MAG_BW_SHIFT_RIGHT, left);
          }
          break;
        }
        case VTake: {
          const auto rawpath = I.args.take->path;
          if (!std::filesystem::exists(rawpath)) {
            DO_THROW_STRING("Не вдалося прочитати файл \"" + rawpath + "\".");
            return;
          }
          const auto path =
              std::filesystem::canonical(I.args.take->path).string();
          const auto stdpath = std::filesystem::path(path);
          if (!stdpath.has_filename()) {
            DO_THROW_STRING("Не вдалося прочитати файл \"" + path + "\".");
            return;
          }
          const auto name = stdpath.stem().string();

          if (M->loaded_file_modules.contains(name)) {
            PUSH(MA_MAKE_OBJECT(M->loaded_file_modules[name]));
            break;
          } else {
            auto file = std::ifstream(path);
            if (!file.is_open()) {
              DO_THROW_STRING("Не вдалося прочитати файл \"" + path + "\".");
              return;
            }
            const auto source = std::string(std::istreambuf_iterator(file),
                                            std::istreambuf_iterator<char>());
            const auto parser_result = parser::parse(source, path);
            if (!parser_result.errors.empty()) {
              const auto error = parser_result.errors[0];
              DO_THROW_STRING(error.path + ":" + std::to_string(error.line) +
                              ":" + std::to_string(error.column) + ": " +
                              error.message);
              return;
            }
            const auto module_code = new MaCode();
            const auto module_cell = create_module(M, name);
            const auto module_object = module_cell.v.object;
            module_object->d.module->code = module_code;
            module_object->d.module->is_file_module = true;
            if (M->main_module == nullptr) {
              M->main_module = module_cell.v.object;
            }
            M->loaded_file_modules.insert_or_assign(
                module_object->d.module->name, module_object);
            module_code->path = path;
            const auto body_compilation_result =
                compile_body(M, module_code, parser_result.module_node->body);
            if (body_compilation_result.error) {
              DO_THROW_STRING(
                  path + ":" +
                  std::to_string(body_compilation_result.error->line) + ":" +
                  std::to_string(body_compilation_result.error->column) + ": " +
                  body_compilation_result.error->message);
              return;
            }
            READ_TOP_FRAME();
            FRAME_PUSH(MaFrame::module(new MaScope(frame->scope),
                                       new MaFrameModuleData{
                                           .module = module_object,
                                       }));
            M->current_module = module_object;
            std::stack<MaCell> stack;
            run(M, stack, module_code, 0);
            M->current_module = module_object;
            FRAME_POP();
            goto start;
          }
          break;
        }
        case VKeepModule: {
          READ_TOP_FRAME();
          const auto current_module_path =
              frame->data.module->module->d.module->name;
          M->loaded_file_modules.insert_or_assign(current_module_path,
                                                  frame->data.module->module);
          break;
        }
        case VLoadModule: {
          READ_TOP_FRAME();
          PUSH(MA_MAKE_OBJECT(frame->data.module->module));
          break;
        }
        case VModuleLoad: {
          TOP_VALUE(module_cell);
          OBJECT_GET(module_cell, value, I.args.moduleload->name);
          READ_TOP_FRAME();
          frame->scope->set_variable(I.args.moduleload->as, value);
          break;
        }
        default: {
          std::cout << "unsupported instruction " << getopname(I.v)
                    << std::endl;
          return;
        }
      }

      i++;
    }
  }

  MaCell ma_call(MaMa* M,
                 MaCell cell,
                 const std::vector<MaCell>& args,
                 MaInstructionLocation* location) {
    return docall(M, cell, new MaArgs(MA_ARGS_POSITIONED, {}, args), location);
  }

  MaCell ma_call_named(MaMa* M,
                       MaCell cell,
                       const std::unordered_map<std::string, MaCell>& args,
                       MaInstructionLocation* location) {
    return docall(M, cell, new MaArgs(MA_ARGS_NAMED, args, {}), location);
  }

  MaCell docall(MaMa* M,
                MaCell cell,
                MaArgs* args,
                MaInstructionLocation* location) {
    auto frame = M->frames.top();
  repeat:
    if (IS_OBJECT(cell)) {
      const auto object = cell.v.object;

      if (IS_OBJECT_DIIA(cell)) {
        const auto cf_data = new MaCallFrameCallData({
            .type = FRAME_CALL_TYPE_DIIA,
            .o =
                {
                    .diia = object,
                },
            .location = location,
        });
        const auto scope = new MaScope(object->d.diia->scope);
        frame = MaFrame::call(scope, cf_data);
        FRAME_PUSH(frame);
        const auto call_data = frame->data.call;
        const auto diia = call_data->o.diia;
        if (diia->d.diia->me) {
          frame->scope->set_variable("я", MA_MAKE_OBJECT(diia->d.diia->me));
        }
        for (int i = 0; i < diia->d.diia->params.size(); ++i) {
          const auto& param = diia->d.diia->params[i];
          const auto arg_value =
              ARGS_GET(args, i, param.name, param.default_value);
          frame->scope->set_variable(param.name, arg_value);
        }
        std::stack<MaCell> stack;
        run(M, stack, diia->d.diia->code, 0);
        const auto result = stack.top();
        return result;
      } else if (IS_OBJECT_DIIA_NATIVE(cell)) {
        const auto cf_data = new MaCallFrameCallData({
            .type = FRAME_CALL_TYPE_DIIA_NATIVE,
            .o =
                {
                    .diia_native = object,
                },
            .location = location,
        });
        frame = MaFrame::call(frame->scope, cf_data);
        FRAME_PUSH(frame);
        const auto call_data = frame->data.call;
        const auto diia_native = call_data->o.diia_native;
        const auto result = diia_native->d.diia_native->fn(M, diia_native->d.diia_native->me, args);
        FRAME_POP();
        return result;
      } else if (object->properties.contains(MAG_CALL)) {
        cell = object->properties[MAG_CALL];
        goto repeat;
      } else if (IS_OBJECT_STRUCTURE(cell)) {
        const auto cf_data = new MaCallFrameCallData({
            .type = FRAME_CALL_TYPE_STRUCTURE,
            .o =
                {
                    .structure = object,
                },
            .location = location,
        });
        frame = MaFrame::call(frame->scope, cf_data);
        FRAME_PUSH(frame);
        const auto call_data = frame->data.call;
        const auto structure = call_data->o.structure;
        const auto object_cell =
            create_object(M, MA_OBJECT, structure, nullptr);
        for (int i = 0; i < structure->d.structure->params.size(); ++i) {
          const auto& param = structure->d.structure->params[i];
          const auto arg_value =
              ARGS_GET(args, i, param.name, param.default_value);
          ma_object_set(object_cell.v.object, param.name, arg_value);
        }
        FRAME_POP();
        return object_cell;
      } else {
        DO_THROW_CANNOT_CALL_CELL(cell);
      }
    }
    DO_THROW_CANNOT_CALL_CELL(cell);
  }
} // namespace mavka::mama
