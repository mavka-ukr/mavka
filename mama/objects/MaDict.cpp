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
} // namespace mavka::mama