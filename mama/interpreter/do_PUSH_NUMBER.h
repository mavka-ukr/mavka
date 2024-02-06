#pragma once

inline void do_PUSH_NUMBER(MaMa* M, double value) {
  M->stack.push(create_number(value));
}
