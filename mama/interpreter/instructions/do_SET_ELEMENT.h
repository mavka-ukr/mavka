#pragma once

inline void do_SET_ELEMENT(MaMa* M) {
  const auto value = M->stack.top();
  M->stack.pop();
  const auto key = M->stack.top();
  M->stack.pop();
  const auto cell = M->stack.top();
  if (cell->type == MA_LIST) {
    const auto list = cell->cast_list();
    if (key->type == MA_NUMBER) {
      const auto index = key->number_long();
      if (index >= 0 && index < list->value.size()) {
        list->value[index] = value;
      }
    }
  }
}
