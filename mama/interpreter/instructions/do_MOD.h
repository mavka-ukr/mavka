#pragma once

inline void do_MOD(MaMa* M) {
  const auto right = M->stack.top();
  M->stack.pop();
  const auto left = M->stack.top();
  M->stack.pop();

  M->stack.push(create_number(std::fmod(left->number(), right->number())));
}
