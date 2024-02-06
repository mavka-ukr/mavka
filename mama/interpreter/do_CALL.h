#pragma once

inline void do_CALL(MaMa* M) {
  const auto cell = M->stack.top();
  M->stack.pop();
  const auto call_stack_value = M->call_stack.top();
  const auto dS = new MaScope(call_stack_value->scope);
  M->call_stack.push(new MaCallStackValue(cell, dS, M->i + 1));
  if (cell->type == MA_DIIA_NATIVE) {
    cell->diia_native(cell, M, dS);
  } else if (cell->type == MA_DIIA) {
    M->i = cell->diia_index;
  }
}
