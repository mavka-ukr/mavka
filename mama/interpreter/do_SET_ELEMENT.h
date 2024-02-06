#pragma once

inline void do_SET_ELEMENT(MaMa* M) {
  const auto value = M->stack.top();
  M->stack.pop();
  const auto key = M->stack.top();
  M->stack.pop();
  const auto list_cell = M->stack.top();
  if (list_cell->type == MA_LIST) {
    if (key->type == MA_NUMBER) {
      const auto index = static_cast<int>(key->number);
      if (index >= 0 && index < list_cell->list.size()) {
        list_cell->list[index] = value;
      }
    }
  }
}
