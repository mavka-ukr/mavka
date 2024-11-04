#include "tools.h"

namespace mavka::parser::tools {
  std::string implode(const std::vector<std::string>& lst,
                      const std::string& delim) {
    std::string ret;
    for (const auto& s : lst) {
      if (!ret.empty()) {
        ret += delim;
      }
      ret += s;
    }
    return ret;
  }

  std::string implode_with_prefix(const std::vector<std::string>& lst,
                                  const std::string& delim,
                                  const std::string& prefix) {
    std::string ret;
    for (const auto& s : lst) {
      if (!ret.empty()) {
        ret += delim;
      }
      for (const auto& p : prefix) {
        ret += p;
      }
      ret += s;
    }
    return ret;
  }

  std::vector<std::string> explode(const std::string& s,
                                   const std::string& delim) {
    std::vector<std::string> ret;
    size_t last = 0;
    size_t next = 0;
    while ((next = s.find(delim, last)) != std::string::npos) {
      ret.push_back(s.substr(last, next - last));
      last = next + 1;
    }
    ret.push_back(s.substr(last));
    return ret;
  }

  std::string repeat_string(const std::string& s, size_t n) {
    std::string ret;
    for (int i = 0; i < n; i++) {
      ret += s;
    }
    return ret;
  }

  bool is_digit(std::string s) {
    return s == "0" || s == "1" || s == "2" || s == "3" || s == "4" ||
           s == "5" || s == "6" || s == "7" || s == "8" || s == "9";
  }

  void replace_all(std::string& str,
                   const std::string& from,
                   const std::string& to) {
    if (from.empty())
      return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
      str.replace(start_pos, from.length(), to);
      start_pos += to.length(); // In case 'to' contains 'from', like replacing
                                // 'x' with 'yx'
    }
  }

  std::string safe_substr(const std::string& str, int start, int count) {
    if (start < 0) {
      start = 0;
    }
    if (count < 0) {
      count = 0;
    }
    if (start + count > str.length()) {
      count = static_cast<int>(str.length()) - start;
    }
    return str.substr(start, count);
  }

  std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
      token = s.substr(pos_start, pos_end - pos_start);
      pos_start = pos_end + delim_len;
      res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
  }

  std::string trim(const std::string& source) {
    std::string s(source);
    s.erase(0, s.find_first_not_of(" \n\r\t"));
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
    return s;
  }

  std::string rtrim(const std::string& source) {
    std::string s(source);
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
    return s;
  }

  std::string ltrim(const std::string& source) {
    std::string s(source);
    s.erase(0, s.find_first_not_of(" \n\r\t"));
    return s;
  }
} // namespace mavka::parser::tools
