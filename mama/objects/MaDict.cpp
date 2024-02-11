#include "../mama.h"

namespace mavka::mama {
  void MaDict::set(const MaCell key, const MaCell value) {
    for (auto& item : this->data) {
      if (key.type == MA_CELL_EMPTY) {
        if (item.first.type == MA_CELL_EMPTY) {
          item.second = value;
          return;
        }
      } else if (key.type == MA_CELL_NUMBER) {
        if (item.first.type == MA_CELL_NUMBER &&
            item.first.v.number == key.v.number) {
          item.second = value;
          return;
        }
      } else if (key.type == MA_CELL_OBJECT) {
        if (item.first.type == MA_CELL_OBJECT) {
          const auto key_object = key.v.object;
          const auto item_object = item.first.v.object;
          if (key_object->type == MA_OBJECT_STRING) {
            if (item_object->type == MA_OBJECT_STRING) {
              if (key_object->d.string->data == item_object->d.string->data) {
                item.second = value;
                return;
              }
            }
          } else {
            if (key_object == item_object) {
              item.second = value;
              return;
            }
          }
        }
      }
    }
    this->data.push_back({key, value});
  }

  MaCell MaDict::get(const MaCell key) const {
    for (const auto& item : this->data) {
      if (key.type == MA_CELL_EMPTY) {
        if (item.first.type == MA_CELL_EMPTY) {
          return item.second;
        }
      } else if (key.type == MA_CELL_NUMBER) {
        if (item.first.type == MA_CELL_NUMBER &&
            item.first.v.number == key.v.number) {
          return item.second;
        }
      } else if (key.type == MA_CELL_OBJECT) {
        if (item.first.type == MA_CELL_OBJECT) {
          const auto key_object = key.v.object;
          const auto item_object = item.first.v.object;
          if (key_object->type == MA_OBJECT_STRING) {
            if (item_object->type == MA_OBJECT_STRING) {
              if (key_object->d.string->data == item_object->d.string->data) {
                return item.second;
              }
            }
          } else {
            if (key_object == item_object) {
              return item.second;
            }
          }
        }
      }
    }
    return MA_MAKE_EMPTY();
  }

  void MaDict::remove(MaCell key) {
    long index = 0;
    for (const auto& item : this->data) {
      if (key.type == MA_CELL_EMPTY) {
        if (item.first.type == MA_CELL_EMPTY) {
          this->data.erase(this->data.begin() + index);
          return;
        }
      } else if (key.type == MA_CELL_NUMBER) {
        if (item.first.type == MA_CELL_NUMBER &&
            item.first.v.number == key.v.number) {
          this->data.erase(this->data.begin() + index);
          return;
        }
      } else if (key.type == MA_CELL_OBJECT) {
        if (item.first.type == MA_CELL_OBJECT) {
          const auto key_object = key.v.object;
          const auto item_object = item.first.v.object;
          if (key_object->type == MA_OBJECT_STRING) {
            if (item_object->type == MA_OBJECT_STRING) {
              if (key_object->d.string->data == item_object->d.string->data) {
                this->data.erase(this->data.begin() + index);
                return;
              }
            }
          } else {
            if (key_object == item_object) {
              this->data.erase(this->data.begin() + index);
              return;
            }
          }
        }
      }
      ++index;
    }
  }

  size_t MaDict::size() const {
    return this->data.size();
  }

  MaCell create_dict(MaMa* M) {
    const auto dict_object = new MaObject();
    dict_object->type = MA_OBJECT_DICT;
    dict_object->structure = M->dict_structure_object;
    const auto dict = new MaDict();
    dict_object->d.dict = dict;
    return MaCell{MA_CELL_OBJECT, {.object = dict_object}};
  }

  void init_dict(MaMa* M) {
    const auto dict_structure_object = new MaObject();
    dict_structure_object->type = MA_OBJECT_STRUCTURE;
    dict_structure_object->structure = M->structure_structure_object;
    const auto dict_structure = new MaStructure();
    dict_structure_object->d.structure = dict_structure;
    ma_object_set(dict_structure_object, "назва", create_string(M, "словник"));
    const auto dict_structure_cell =
        MaCell{MA_CELL_OBJECT, {.object = dict_structure_object}};
    M->global_scope->set_variable("словник", dict_structure_cell);
    M->dict_structure_object = dict_structure_object;
  }
} // namespace mavka::mama