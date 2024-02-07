#pragma once

inline void do_GET(MaMa* M, const std::string& name) {
  const auto cell = M->stack.top();
  M->stack.pop();
  const auto object = cell->cast_object();
  const auto value = object->get(name);
  if (value != nullptr) {
    M->stack.push(value);
  } else {
    M->stack.push(M->empty_cell);
  }
}
