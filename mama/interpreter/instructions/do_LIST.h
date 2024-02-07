#pragma once

inline void do_LIST(MaMa* M) {
  M->stack.push(new MaCell(MA_LIST));
}
