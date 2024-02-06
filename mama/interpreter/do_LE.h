#pragma once

inline void do_LE(MaMa* M) {
  const auto right = M->stack.top();
  M->stack.pop();
  const auto left = M->stack.top();
  M->stack.pop();
  if (left->number <= right->number) {
    M->stack.push(M->yes_cell);
  } else {
    M->stack.push(M->no_cell);
  }
}
