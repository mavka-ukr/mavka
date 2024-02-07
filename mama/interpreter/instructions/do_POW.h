#pragma once

inline void do_POW(MaMa* M) {
  const auto right = M->stack.top();
  M->stack.pop();
  const auto left = M->stack.top();
  M->stack.pop();

  M->stack.push(create_number(std::pow(left->number(), right->number())));
}
