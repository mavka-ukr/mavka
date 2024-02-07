#pragma once

inline void do_LIST_APPEND(MaMa* M) {
  const auto value = M->stack.top();
  M->stack.pop();
  const auto cell = M->stack.top();
  const auto list = cell->cast_list();
  list->value.push_back(value);
}
