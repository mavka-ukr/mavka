#pragma once

inline void do_DIIA(MaMa* M, int index, const std::string& name) {
  M->stack.push(create_diia(index));
}
