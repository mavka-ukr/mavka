#pragma once

inline void do_LOAD(MaMa* M, const std::string& name) {
  const auto call_stack_value = M->call_stack.top();
  const auto value = call_stack_value->scope->get_variable(name);
  if (value != nullptr) {
    M->stack.push(value);
  } else {
    M->stack.push(M->empty_cell);
  }
}
