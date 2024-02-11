#include "../mama.h"

namespace mavka::mama {
  MaCell create_module(MaMa* M, const std::string& name) {
    const auto module = new MaModule();
    module->name = name;
    return create_object(M, MA_OBJECT_MODULE, M->module_structure_object,
                         module);
  }

  void init_module(MaMa* M) {
    const auto module_structure_cell = create_structure(M, "Модуль");
    M->global_scope->set_variable("Модуль", module_structure_cell);
    M->module_structure_object = module_structure_cell.v.object;
  }
} // namespace mavka::mama