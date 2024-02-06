#pragma once

inline void do_ADD(MaMa* M) {
  const auto right_cell = M->stack.top();
  M->stack.pop();
  const auto left_cell = M->stack.top();
  M->stack.pop();

  M->stack.push(create_number(left_cell->number + right_cell->number));
}