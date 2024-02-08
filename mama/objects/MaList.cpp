#include "../mama.h"

namespace mavka::mama {
  void MaList::append(const MaCell cell) {
    this->data.push_back(cell);
  }

  void MaList::set(const long index, const MaCell cell) {
    if (index >= 0) {
      if (index >= this->data.size()) {
        this->data.resize(index + 1);
      }
      this->data[index] = cell;
    }
  }

  MaCell MaList::get(const long index) const {
    if (index >= 0 && index < this->data.size()) {
      return this->data[index];
    }
    return MA_MAKE_EMPTY();
  }

  long MaList::size() const {
    return static_cast<long>(this->data.size());
  }
} // namespace mavka::mama