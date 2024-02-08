#ifndef OBJECTS_H
#define OBJECTS_H

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

#define MA_MAKE_NUBMER(value) (MaCell{MA_CELL_NUMBER, {.number = (value)}})
#define MA_MAKE_INTEGER(value) (MaCell{MA_CELL_NUMBER, {.integer = (value)}})
#define MA_MAKE_OBJECT(value) (MaCell{MA_CELL_OBJECT, {.object = (value)}})
#define MA_MAKE_EMPTY() (MaCell{MA_CELL_EMPTY})

class MaString;
class MaList;
class MaDict;
class MaDiia;
class MaDiiaNative;
class MaStructure;
class MaMethod;

struct MaCell;

struct MaObject {
  unsigned char type;
  union {
    MaList* list;
    MaDict* dict;
  } d;
  MaObject* structure;
  std::map<std::string, MaCell> properties;
  std::vector<std::string> params;
  std::map<std::string, MaMethod*> methods;
  std::string name;
  long diia_index;
  std::function<MaCell(MaCell*, MaMa*, MaScope*)> diia_native;
  MaObject* me;
  std::string string;
};

union MaCellValue {
  MaObject* object;
  double number;
  long integer;
};

struct MaCell {
  unsigned char type;
  MaCellValue v;
};

class MaString final {
 public:
  std::string value;
};

class MaList final {
 public:
  std::vector<MaCell> v;

  void append(MaCell cell);
  void set(size_t index, MaCell cell);
  MaCell get(size_t index) const;
  long size() const;
};

class MaDict final {
 public:
  void set(MaCell key, MaCell value);
  void set(const std::string& key, MaCell value);
  MaCell get(MaCell key) const;
  void remove(MaCell key);
  long size() const;
};

class MaDiia final {
 public:
  int index;
  MaObject* me;
};

class MaDiiaNative final {
 public:
};

class MaStructure final {
 public:
  std::string name;
  std::vector<std::string> params;
  std::map<std::string, MaMethod*> methods;
};

class MaMethod final {
 public:
  int index;
  std::vector<std::string> params;
};

inline void ma_object_set(MaObject* object,
                          const std::string& name,
                          MaCell value) {
  if (object->properties.contains(name)) {
    object->properties.at(name) = value;
  } else {
    object->properties.insert({name, value});
  }
}

inline MaCell ma_object_get(const MaObject* object, const std::string& name) {
  if (object->properties.contains(name)) {
    return object->properties.at(name);
  }
  return MA_MAKE_EMPTY();
}

inline bool ma_object_has(const MaObject* object, const std::string& name) {
  return object->properties.contains(name);
}

inline MaCell create_string(const std::string& value) {
  const auto ma_object = new MaObject();
  ma_object->type = MA_STRING;
  ma_object->string = value;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_list() {
  const auto ma_object = new MaObject();
  ma_object->type = MA_LIST;
  const auto ma_list = new MaList();
  ma_object->d.list = ma_list;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_dict() {
  const auto ma_object = new MaObject();
  ma_object->type = MA_DICT;
  const auto ma_dict = new MaDict();
  ma_object->d.dict = ma_dict;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_diia(const int& index) {
  const auto ma_object = new MaObject();
  ma_object->type = MA_DIIA;
  ma_object->diia_index = index;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_diia_native(
    const std::function<MaCell(MaCell*, MaMa*, MaScope*)>& diia_native_fn) {
  const auto ma_object = new MaObject();
  ma_object->type = MA_DIIA_NATIVE;
  ma_object->diia_native = diia_native_fn;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_object(MaObject* structure) {
  const auto ma_object = new MaObject();
  const auto object_cell = MaCell{MA_CELL_OBJECT, {.object = ma_object}};
  ma_object->structure = structure;
  for (const auto& [name, method] : structure->methods) {
    const auto diia_cell = create_diia(method->index);
    diia_cell.v.object->params = method->params;
    diia_cell.v.object->me = ma_object;
    ma_object_set(ma_object, name, diia_cell);
  }
  return object_cell;
}

inline MaCell create_structure() {
  const auto ma_object = new MaObject();
  ma_object->type = MA_STRUCTURE;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline void MaList::append(MaCell cell) {
  this->v.push_back(cell);
}

inline void MaList::set(size_t index, MaCell cell) {
  if (index >= 0) {
    if (index >= this->v.size()) {
      this->v.resize(index + 1);
    }
    this->v[index] = cell;
  }
}

inline MaCell MaList::get(size_t index) const {
  if (index >= 0 && index < this->v.size()) {
    return this->v[index];
  }
  return MA_MAKE_EMPTY();
}

inline long MaList::size() const {
  return this->v.size();
}

inline void MaDict::set(MaCell key, MaCell value) {
  throw std::runtime_error("Not implemented");
}

inline void MaDict::set(const std::string& key, MaCell value) {
  throw std::runtime_error("Not implemented");
}

inline MaCell MaDict::get(MaCell key) const {
  throw std::runtime_error("Not implemented");
  return MA_MAKE_EMPTY();
}

inline void MaDict::remove(MaCell key) {
  throw std::runtime_error("Not implemented");
}

inline long MaDict::size() const {
  return 0;
}

#endif // OBJECTS_H
