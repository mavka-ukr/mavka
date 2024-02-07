#pragma once

inline void do_XOR(MaMa* M) {
  const auto right = M->stack.top();
  M->stack.pop();
  const auto left = M->stack.top();
  M->stack.pop();

  M->stack.push(create_number(left->number_long() ^ right->number_long()));
}
