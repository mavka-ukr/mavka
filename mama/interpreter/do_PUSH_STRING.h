#pragma once

inline void do_PUSH_STRING(MaMa* M, const std::string& value) {
  M->stack.push(create_string(value));
}
