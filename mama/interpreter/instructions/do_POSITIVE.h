#pragma once

inline void do_POSITIVE(MaMa* M) {
  const auto value = M->stack.top();
  M->stack.pop();
  if (value->type == MA_NUMBER) {
    M->stack.push(create_number(+value->number));
  } else {
    M->stack.push(M->empty_cell);
  }
}
