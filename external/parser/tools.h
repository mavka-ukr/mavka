#pragma once

#ifndef MAVKA_PARSER_TOOLS_H
#define MAVKA_PARSER_TOOLS_H

#include <string>
#include <vector>

namespace mavka::parser::tools {
  std::string implode(const std::vector<std::string>& lst,
                      const std::string& delim);

  std::string implode_with_prefix(const std::vector<std::string>& lst,
                                  const std::string& delim,
                                  const std::string& prefix);

  std::vector<std::string> explode(const std::string& s,
                                   const std::string& delim);

  std::string repeat_string(const std::string& s, size_t n);

  bool is_digit(std::string s);

  void replace_all(std::string& str,
                   const std::string& from,
                   const std::string& to);

  std::string safe_substr(const std::string& str, int start, int count);

  std::vector<std::string> split(std::string s, std::string delimiter);

  std::string trim(const std::string& source);
  std::string rtrim(const std::string& source);
  std::string ltrim(const std::string& source);

  template <typename Base, typename T>
  bool instanceof (const T* ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
  }

  template <typename Base, typename T>
  bool instance_of(const T* ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
  }
} // namespace mavka::parser::tools
#endif // MAVKA_PARSER_TOOLS_H
