#pragma once

inline void do_DICT_SET(MaMa* M, const std::string& name) {
  const auto value = M->stack.top();
  M->stack.pop();
  const auto cell = M->stack.top();
  const auto dict = cell->cast_dict();

  dict->set(create_string(name), value);
}
