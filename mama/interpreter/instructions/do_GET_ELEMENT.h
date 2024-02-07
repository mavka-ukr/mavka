#pragma once

inline void do_GET_ELEMENT(MaMa* M) {
  const auto cell = M->stack.top();
  M->stack.pop();
  const auto key = M->stack.top();
  M->stack.pop();

  if (cell->type == MA_LIST) {
    const auto list = cell->cast_list();
    if (key->type == MA_NUMBER) {
      const auto index = key->number_long();
      if (index >= 0 && index < list->value.size()) {
        M->stack.push(list->value[index]);
      } else {
        M->stack.push(M->empty_cell);
      }
    } else {
      M->stack.push(M->empty_cell);
    }
  } else if (cell->type == MA_DICT) {
    const auto value = cell->cast_dict()->get(key);
    if (value) {
      M->stack.push(value);
    } else {
      M->stack.push(M->empty_cell);
    }
  } else {
    M->stack.push(M->empty_cell);
  }
}
