#pragma once

inline void do_LIST_APPEND(MaMa* M) {
  const auto value = M->stack.top();
  M->stack.pop();
  const auto list_cell = M->stack.top();
  list_cell->list.push_back(value);
}
