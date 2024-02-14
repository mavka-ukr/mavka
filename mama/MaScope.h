#ifndef MA_SCOPE_H
#define MA_SCOPE_H

class MaScope final {
 public:
  MaScope* parent;
  std::map<std::string, MaCell> variables;

  bool has_variable(const std::string& name);
  bool has_local_variable(const std::string& name);
  MaCell get_variable(const std::string& name);
  MaCell get_local_variable(const std::string& name);
  void set_variable(const std::string& name, MaCell value);
  void delete_variable(const std::string& name);
};

#endif // MA_SCOPE_H