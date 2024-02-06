#pragma once

inline void do_SET_ARG(MaMa* M, const std::string& name) {
  const auto value = M->stack.top();
  M->stack.pop();
  const auto args_cell = M->stack.top();
  args_cell->args.insert_or_assign(name, value);
}
