#pragma once

inline void do_GET_ELEMENT(MaMa* M) {
  const auto value = M->stack.top();
  M->stack.pop();
  const auto key = M->stack.top();
  M->stack.pop();

  if (value->type == MA_LIST) {
    const auto list = value->cast_list();
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
  } else {
    M->stack.push(M->empty_cell);
  }
}
