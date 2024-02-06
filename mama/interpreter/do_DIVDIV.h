#pragma once

inline void do_DIVDIV(MaMa* M) {
  const auto right = M->stack.top();
  M->stack.pop();
  const auto left = M->stack.top();
  M->stack.pop();

  M->stack.push(create_number(std::floor(left->number / right->number)));
}
