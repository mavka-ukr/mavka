#pragma once

inline void do_LOAD_ARG(MaMa* M, int index, const std::string& name) {
  const auto call_stack_value = M->call_stack.top();
  if (M->aR.contains(name)) {
    call_stack_value->scope->set_variable(name, M->aR[name]);
  } else if (M->aR.contains(std::to_string(index))) {
    call_stack_value->scope->set_variable(
        name, M->aR[std::to_string(index)]);
  } else {
    call_stack_value->scope->set_variable(name, M->empty_cell);
  }
}
