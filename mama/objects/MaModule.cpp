#include "../mama.h"

namespace mavka::mama {
  MaCell create_module(MaMa* M, const std::string& name) {
    const auto ma_object = new MaObject();
    ma_object->type = MA_OBJECT_MODULE;
    const auto ma_structure = new MaStructure();
    ma_object->d.structure = ma_structure;
    ma_object_set(ma_object, "назва", create_string(M, name));
    return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
  }
} // namespace mavka::mama