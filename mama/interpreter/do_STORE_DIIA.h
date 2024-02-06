#pragma once

inline void do_STORE_DIIA(MaMa* M, int index, const std::string& name) {
  const auto diia_cell = new MaCell(MA_DIIA);
  diia_cell->diia_index = index;
  const auto call_stack_value = M->call_stack.top();
  call_stack_value->scope->set_variable(name, diia_cell);
}
