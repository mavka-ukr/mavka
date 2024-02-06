#pragma once

inline void do_RETURN(MaMa* M) {
  const auto call_stack_value = M->call_stack.top();
  M->call_stack.pop();
  M->i = call_stack_value->return_index;
}
