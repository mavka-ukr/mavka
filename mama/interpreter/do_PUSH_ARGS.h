#pragma once

inline void do_PUSH_ARGS(MaMa* M) {
  M->stack.push(new MaCell(MA_ARGS));
}
