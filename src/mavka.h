#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include "mama/src/mama.h"

using namespace mavka::mama;

namespace mavka {
  std::string cell_to_string(MaMa* M, MaValue cell, int depth = 0);

  MaValue TakeBib(MaMa* M,
                  MaObject* scope,
                  const std::vector<std::string>& parts,
                  size_t li);
  MaObject* BibInitReadModule(MaMa* M);
  MaObject* BibInitMavkaModule(MaMa* M);
  MaObject* BibInitFsSyncModule(MaMa* M);
} // namespace mavka