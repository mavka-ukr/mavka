#pragma once

inline void do_STORE(MaMa* M, const std::string& name) {
  const auto value = M->stack.top();
  M->stack.pop();

  const auto call_stack_value = M->call_stack.top();
  call_stack_value->scope->set_variable(name, value);
}
