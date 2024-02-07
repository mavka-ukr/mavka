#pragma once

inline void do_PUSH_DIIA(MaMa* M, int index, const std::string& name) {
  const auto diia_cell = new MaCell(MA_DIIA);
  diia_cell->diia_index = index;

  M->stack.push(diia_cell);
}
