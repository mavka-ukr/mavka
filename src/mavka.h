#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include "mama/src/mama.h"

using namespace mavka::mama;

namespace mavka {
  std::string cell_to_string(MaMa* M, MaValue cell, int depth = 0);

  MaValue TakeBib(MaMa* M, const std::vector<std::string>& parts, size_t li);

  MaValue BibReadNativeFn(MaMa* M, MaObject* o, MaObject* args, size_t li);
  MaObject* BibInitReadModule(MaMa* M);

  MaValue BibMavkaEvalNativeFn(MaMa* M, MaObject* o, MaObject* args, size_t li);
  MaObject* BibInitMavkaModule(MaMa* M);

  MaValue BibFsSyncReadNativeFn(MaMa* M,
                                MaObject* diiaObject,
                                MaObject* args,
                                size_t li);
  MaValue BibFsSyncReadTextNativeFn(MaMa* M,
                                    MaObject* o,
                                    MaObject* args,
                                    size_t li);
  MaObject* BibInitFsSyncModule(MaMa* M);
} // namespace mavka