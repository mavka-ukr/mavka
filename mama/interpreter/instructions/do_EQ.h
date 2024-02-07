#pragma once

inline void do_EQ(MaMa* M) {
  const auto right = M->stack.top();
  M->stack.pop();
  const auto left = M->stack.top();
  M->stack.pop();

  if (left->type == MA_NUMBER && right->type == MA_NUMBER) {
    if (left->number() == right->number()) {
      M->stack.push(M->yes_cell);
    } else {
      M->stack.push(M->no_cell);
    }
  } else if (left->type == MA_STRING && right->type == MA_STRING) {
    if (left->string() == right->string()) {
      M->stack.push(M->yes_cell);
    } else {
      M->stack.push(M->no_cell);
    }
  } else {
    if (left == right) {
      M->stack.push(M->yes_cell);
    } else {
      M->stack.push(M->no_cell);
    }
  }
}
