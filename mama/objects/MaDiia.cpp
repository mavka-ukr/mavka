#include "../mama.h"

namespace mavka::mama {
  MaCell create_diia(MaMa* M,
                     const std::string& name,
                     MaCode* code,
                     MaObject* me) {
    const auto diia = new MaDiia();
    diia->name = name;
    diia->code = code;
    diia->me = me;
    const auto cell =
        create_object(M, MA_OBJECT_DIIA, M->diia_structure_object, diia);
    cell.v.object->call = [](MaMa* M, MaObject* o, MaArgs* args,
                             MaInstructionLocation* location) {
      const auto frame = new MaFrame(nullptr, o, location);
      FRAME_PUSH(frame);
      const auto diia_scope = new MaScope(o->d.diia->scope);
      frame->scope = diia_scope;
      if (o->d.diia->me) {
        frame->scope->set_variable("я", MA_MAKE_OBJECT(o->d.diia->me));
      }
      for (int i = 0; i < o->d.diia->params.size(); ++i) {
        const auto& param = o->d.diia->params[i];
        const auto arg_value =
            ARGS_GET(args, i, param.name, param.default_value);
        frame->scope->set_variable(param.name, arg_value);
      }
      run(M, o->d.diia->code);
      const auto result = frame->stack.top();
      FRAME_POP();
      return result;
    };
    return cell;
  }

  MaCell create_diia_native(MaMa* M,
                            const std::string& name,
                            const std::function<DiiaNativeFn>& diia_native_fn,
                            MaObject* me) {
    const auto diia_native = new MaDiiaNative();
    diia_native->name = name;
    diia_native->fn = diia_native_fn;
    diia_native->me = me;
    const auto cell = create_object(M, MA_OBJECT_DIIA_NATIVE,
                                    M->diia_structure_object, diia_native);
    cell.v.object->call = [](MaMa* M, MaObject* o, MaArgs* args,
                             MaInstructionLocation* location) {
      return o->d.diia_native->fn(M, o, args);
    };
    return cell;
  }

  MaCell bind_diia(MaMa* M, MaObject* diia, MaObject* object) {
    const auto diia_cell =
        create_diia(M, diia->d.diia->name, diia->d.diia->code, object);
    diia_cell.v.object->d.diia->scope = diia->d.diia->scope;
    diia_cell.v.object->d.diia->module = diia->d.diia->module;
    diia_cell.v.object->d.diia->params = diia->d.diia->params;
    return diia_cell;
  }

  void init_diia(MaMa* M) {
    const auto diia_structure_cell = create_structure(M, "Дія");
    M->global_scope->set_variable("Дія", diia_structure_cell);
    M->diia_structure_object = diia_structure_cell.v.object;
  }
} // namespace mavka::mama