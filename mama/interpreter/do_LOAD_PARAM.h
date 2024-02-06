#pragma once

inline void do_LOAD_PARAM(MaMa* M, int index, const std::string& name) {
  const auto args_cell = M->stack.top();
  const auto call_stack_value = M->call_stack.top();
  if (args_cell->args.contains(name)) {
    call_stack_value->scope->set_variable(name, args_cell->args[name]);
  } else if (args_cell->args.contains(std::to_string(index))) {
    call_stack_value->scope->set_variable(
        name, args_cell->args[std::to_string(index)]);
  } else {
    call_stack_value->scope->set_variable(name, M->empty_cell);
  }
}
