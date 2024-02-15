#include "../mama.h"

namespace mavka::mama {
  void MaList::append(const MaCell cell) {
    this->data.push_back(cell);
  }

  void MaList::set(const size_t index, const MaCell cell) {
    if (index >= 0) {
      if (index >= this->data.size()) {
        this->data.resize(index + 1);
      }
      this->data[index] = cell;
    }
  }

  MaCell MaList::get(const size_t index) const {
    if (index >= 0 && index < this->data.size()) {
      return this->data[index];
    }
    return MA_MAKE_EMPTY();
  }

  size_t MaList::size() const {
    return this->data.size();
  }

  bool MaList::contains(MaCell cell) {
    for (const auto& item : this->data) {
      if (item.type == MA_CELL_EMPTY) {
        if (cell.type == MA_CELL_EMPTY) {
          return true;
        }
      } else if (item.type == MA_CELL_NUMBER) {
        if (cell.type == MA_CELL_NUMBER) {
          if (item.v.number == cell.v.number) {
            return true;
          }
        }
      } else if (item.type == MA_CELL_YES) {
        if (cell.type == MA_CELL_YES) {
          return true;
        }
      } else if (item.type == MA_CELL_NO) {
        if (cell.type == MA_CELL_NO) {
          return true;
        }
      } else if (item.type == MA_CELL_OBJECT) {
        if (cell.type == MA_CELL_OBJECT) {
          if (item.v.object->type == MA_OBJECT_STRING) {
            if (cell.v.object->type == MA_OBJECT_STRING) {
              if (item.v.object->d.string->data ==
                  cell.v.object->d.string->data) {
                return true;
              }
            }
          } else {
            if (item.v.object == cell.v.object) {
              return true;
            }
          }
        }
      }
    }
    return false;
  }

  void ma_list_iterate_diia_native_fn(MaMa* M,
                                      MaObject* list_me,
                                      MaArgs* args) {
    const auto iterator_object_cell = create_empty_object(M);
    const auto iterator_object = iterator_object_cell.v.object;

    ma_object_set(iterator_object, "_список",
                  MaCell{MA_CELL_OBJECT, {.object = list_me}});

    if (list_me->d.list->size() == 0) {
      ma_object_set(iterator_object, "завершено", MA_MAKE_YES());
    } else if (list_me->d.list->size() == 1) {
      ma_object_set(iterator_object, "завершено", MA_MAKE_NO());
      ma_object_set(iterator_object, "значення", list_me->d.list->data[0]);
      const auto next_diia_native_cell = create_diia_native(
          M, "далі",
          [](MaMa* M, MaObject* iterator_me, MaArgs* args) {
            ma_object_set(iterator_me, "завершено", MA_MAKE_YES());
            return MA_MAKE_EMPTY();
          },
          iterator_object);
      ma_object_set(iterator_object, "далі", next_diia_native_cell);
    } else {
      ma_object_set(iterator_object, "завершено", MA_MAKE_NO());
      ma_object_set(iterator_object, "значення", list_me->d.list->data[0]);
      ma_object_set(iterator_object, "_індекс", MA_MAKE_NUMBER(1));
      const auto next_diia_native_cell = create_diia_native(
          M, "далі",
          [](MaMa* M, MaObject* iterator_me, MaArgs* args) {
            const auto i = iterator_me->properties["_індекс"].v.number;
            const auto list =
                iterator_me->properties["_список"].v.object->d.list;
            if (i < list->size()) {
              ma_object_set(iterator_me, "завершено", MA_MAKE_NO());
              ma_object_set(iterator_me, "значення", list->data[i]);
              ma_object_set(iterator_me, "_індекс", MA_MAKE_NUMBER(i + 1));
            } else {
              ma_object_set(iterator_me, "завершено", MA_MAKE_YES());
            }
            return MA_MAKE_EMPTY();
          },
          iterator_object);
      ma_object_set(iterator_object, "далі", next_diia_native_cell);
    }
    M->stack.push(iterator_object_cell);
  }

  void ma_list_get_element_diia_native_fn(MaMa* M,
                                          MaObject* list_me,
                                          MaArgs* args) {
    const auto key = FRAME_GET_ARG(args, 0, "ключ", MA_MAKE_EMPTY());
    if (key.type == MA_CELL_NUMBER) {
      M->stack.push(list_me->d.list->get(key.v.number));
      return;
    }
    M->stack.push(MA_MAKE_EMPTY());
  }

  void ma_list_set_element_diia_native_fn(MaMa* M,
                                          MaObject* list_me,
                                          MaArgs* args) {
    const auto key = FRAME_GET_ARG(args, 0, "ключ", MA_MAKE_EMPTY());
    const auto value = FRAME_GET_ARG(args, 1, "значення", MA_MAKE_EMPTY());
    list_me->d.list->set(key.v.number, value);
    M->stack.push(MA_MAKE_EMPTY());
  }

  void ma_list_append_diia_native_fn(MaMa* M, MaObject* list_me, MaArgs* args) {
    const auto cell = FRAME_GET_ARG(args, 0, "значення", MA_MAKE_EMPTY());
    list_me->d.list->append(cell);
    M->stack.push(MA_MAKE_INTEGER(list_me->d.list->size()));
  }

  void ma_list_contains_diia_native_fn(MaMa* M,
                                       MaObject* list_me,
                                       MaArgs* args) {
    const auto cell = FRAME_GET_ARG(args, 0, "значення", MA_MAKE_EMPTY());
    if (list_me->d.list->contains(cell)) {
      M->stack.push(MA_MAKE_YES());
    } else {
      M->stack.push(MA_MAKE_NO());
    }
  }

  MaCell ma_list_get_handler(MaMa* M, MaObject* me, const std::string& name) {
    if (name == "довжина") {
      return MA_MAKE_INTEGER(me->d.list->size());
    }
    if (!me->properties.contains(name)) {
      M->stack.push(create_string(
          M, "Властивість \"" + name + "\" не визначено для типу \"список\"."));
      M->diia_native_throw = true;
      return MA_MAKE_EMPTY();
    }
    return me->properties[name];
  }

  MaCell create_list(MaMa* M) {
    const auto list = new MaList();
    const auto list_cell =
        create_object(M, MA_OBJECT_LIST, M->list_structure_object, list);
    list_cell.v.object->get = ma_list_get_handler;
    ma_object_set(
        list_cell.v.object, MAG_ITERATOR,
        create_diia_native(M, MAG_ITERATOR, ma_list_iterate_diia_native_fn,
                           list_cell.v.object));
    ma_object_set(list_cell.v.object, MAG_GET_ELEMENT,
                  create_diia_native(M, MAG_GET_ELEMENT,
                                     ma_list_get_element_diia_native_fn,
                                     list_cell.v.object));
    ma_object_set(list_cell.v.object, MAG_SET_ELEMENT,
                  create_diia_native(M, MAG_SET_ELEMENT,
                                     ma_list_set_element_diia_native_fn,
                                     list_cell.v.object));
    ma_object_set(list_cell.v.object, "додати",
                  create_diia_native(M, "додати", ma_list_append_diia_native_fn,
                                     list_cell.v.object));
    ma_object_set(
        list_cell.v.object, MAG_CONTAINS,
        create_diia_native(M, MAG_CONTAINS, ma_list_contains_diia_native_fn,
                           list_cell.v.object));
    return list_cell;
  }

  void init_list(MaMa* M) {
    const auto list_structure_object = create_structure(M, "список");
    M->global_scope->set_variable("список", list_structure_object);
    M->list_structure_object = list_structure_object.v.object;
  }
} // namespace mavka::mama