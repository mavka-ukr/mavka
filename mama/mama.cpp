#include "mama.h"

namespace mavka::mama {
  bool MaScope::has_variable(const std::string& name) {
    if (this->variables.contains(name)) {
      return true;
    }
    auto parent = this->parent;
    while (parent) {
      if (parent->variables.contains(name)) {
        return true;
      }
      parent = parent->parent;
    }
    return false;
  }

  bool MaScope::has_local_variable(const std::string& name) {
    return this->variables.contains(name);
  }

  MaCell MaScope::get_variable(const std::string& name) {
    if (this->variables.contains(name)) {
      return this->variables.at(name);
    }
    auto parent = this->parent;
    while (parent) {
      if (parent->variables.contains(name)) {
        return parent->variables[name];
      }
      parent = parent->parent;
    }
    return MA_MAKE_EMPTY();
  }

  MaCell MaScope::get_local_variable(const std::string& name) {
    if (this->has_local_variable(name)) {
      return this->variables.at(name);
    }
    return MA_MAKE_EMPTY();
  }

  void MaScope::set_variable(const std::string& name, MaCell value) {
    variables.insert_or_assign(name, value);
  }

  void MaScope::delete_variable(const std::string& name) {
    variables.erase(name);
  }
} // namespace mavka::mama