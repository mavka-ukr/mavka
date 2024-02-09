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

  MaCell ma_list_iterate_diia_native_fn(MaMa* M,
                                        MaObject* list_me,
                                        std::map<std::string, MaCell>& args) {
    const auto iterator_object_cell = create_empty_object();
    const auto iterator_object = iterator_object_cell.v.object;

    ma_object_set(iterator_object, "_список",
                  MaCell{MA_CELL_OBJECT, {.object = list_me}});

    if (list_me->d.list->size() == 0) {
      ma_object_set(iterator_object, "завершено", MA_MAKE_YES());
    } else if (list_me->d.list->size() == 1) {
      ma_object_set(iterator_object, "завершено", MA_MAKE_NO());
      ma_object_set(iterator_object, "значення", list_me->d.list->data[0]);
      const auto next_diia_native_cell = create_diia_native(
          [](MaMa* M, MaObject* iterator_me,
             std::map<std::string, MaCell>& args) {
            ma_object_set(iterator_me, "завершено", MA_MAKE_YES());
            return MA_MAKE_EMPTY();
          },
          iterator_object);
      ma_object_set(iterator_object, "далі", next_diia_native_cell);
    } else {
      ma_object_set(iterator_object, "завершено", MA_MAKE_NO());
      ma_object_set(iterator_object, "значення", list_me->d.list->data[0]);
      ma_object_set(iterator_object, "_індекс", MA_MAKE_NUBMER(1));
      const auto next_diia_native_cell = create_diia_native(
          [](MaMa* M, MaObject* iterator_me,
             std::map<std::string, MaCell>& args) {
            const auto i = ma_object_get(iterator_me, "_індекс").v.number;
            const auto list =
                ma_object_get(iterator_me, "_список").v.object->d.list;
            if (i < list->size()) {
              ma_object_set(iterator_me, "завершено", MA_MAKE_NO());
              ma_object_set(iterator_me, "значення", list->data[i]);
              ma_object_set(iterator_me, "_індекс", MA_MAKE_NUBMER(i + 1));
            } else {
              ma_object_set(iterator_me, "завершено", MA_MAKE_YES());
            }
            return MA_MAKE_EMPTY();
          },
          iterator_object);
      ma_object_set(iterator_object, "далі", next_diia_native_cell);
    }

    return iterator_object_cell;
  }

  MaCell ma_list_append_diia_native_fn(MaMa* M,
                                       MaObject* list_me,
                                       std::map<std::string, MaCell>& args) {
    if (args.contains("0")) {
      list_me->d.list->append(args["0"]);
    } else {
      list_me->d.list->append(MA_MAKE_EMPTY());
    }
    return MA_MAKE_INTEGER(list_me->d.list->size());
  }
} // namespace mavka::mama