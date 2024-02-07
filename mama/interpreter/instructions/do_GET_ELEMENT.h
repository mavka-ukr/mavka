#pragma once

inline void do_GET_ELEMENT(MaMa* M) {
  const auto value = M->stack.top();
  M->stack.pop();
  const auto key = M->stack.top();
  M->stack.pop();
  if (value->type == MA_LIST) {
    if (key->type == MA_NUMBER) {
      const auto index = static_cast<int>(key->number);
      if (index >= 0 && index < value->list.size()) {
        M->stack.push(value->list[index]);
      } else {
        M->stack.push(M->empty_cell);
      }
    } else {
      M->stack.push(M->empty_cell);
    }
  } else {
    M->stack.push(M->empty_cell);
  }
}
