#pragma once

inline void do_JUMP_IF_FALSE(MaMa* M, int index) {
  const auto value = M->stack.top();
  M->stack.pop();
  if (value->type == MA_NUMBER) {
    if (value->number == 0) {
      M->i = index;
    }
  } else if (value->type == MA_NO) {
    M->i = index;
  }
}
