#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include "mama/src/mama.h"

using namespace mavka::mama;

namespace mavka {
  std::string cell_to_string(MaCell cell, int depth = 0);

  MaCell TakeBib(MaMa* M,
                 const std::vector<std::string>& parts,
                 const MaLocation& location);
  MaCell TakeFn(MaMa* M,
                const std::string& repository,
                bool relative,
                const std::vector<std::string>& parts,
                const MaLocation& location);
  MaCell TakePath(MaMa* M,
                  const std::string& raw_path,
                  const MaLocation& location);

  MaCell BibReadNativeFn(MaMa* M,
                         MaObject* o,
                         MaArgs* args,
                         const MaLocation& location);
  MaObject* BibInitReadModule(MaMa* M);

  MaCell BibMavkaEvalNativeFn(MaMa* M,
                              MaObject* o,
                              MaArgs* args,
                              const MaLocation& location);
  MaObject* BibInitMavkaModule(MaMa* M);
} // namespace mavka