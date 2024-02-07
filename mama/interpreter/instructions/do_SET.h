#pragma once

inline void do_SET(MaMa* M, const std::string& name) {
  const auto cell = M->stack.top();
  M->stack.pop();
  const auto value = M->stack.top();
  M->stack.pop();

  if (cell->type == MA_OBJECT) {
    const auto object = cell->cast_object();
    object->set(name, value);
  }
}
