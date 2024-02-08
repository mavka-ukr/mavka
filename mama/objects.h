#ifndef OBJECTS_H
#define OBJECTS_H

class MaList;
class MaDict;
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
  std::map<std::string, MaObject*> methods;
  std::string name;
  long diia_index;
  MaObject* diia_me;
  std::function<MaCell(MaCell* self, MaMa* M, MaScope* S)> diia_native;
  std::string string;
};

union MaCellV {
  MaObject* object;
  double number;
  long integer;
};

struct MaCell {
  unsigned char type;
  MaCellV v;
};

class MaList final {
 public:
  std::vector<MaCell> data;

  void append(MaCell cell);
  void set(long index, MaCell cell);
  MaCell get(long index) const;
  long size() const;
};

class MaDict final {
 public:
  std::vector<std::pair<MaCell, MaCell>> data;

  void set(MaCell key, MaCell value);
  MaCell get(MaCell key) const;
  void remove(MaCell key);
  long size() const;
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
  ma_object->type = MA_OBJECT_STRING;
  ma_object->string = value;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_list() {
  const auto ma_object = new MaObject();
  ma_object->type = MA_OBJECT_LIST;
  const auto ma_list = new MaList();
  ma_object->d.list = ma_list;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_dict() {
  const auto ma_object = new MaObject();
  ma_object->type = MA_OBJECT_DICT;
  const auto ma_dict = new MaDict();
  ma_object->d.dict = ma_dict;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_diia(const int& index) {
  const auto ma_object = new MaObject();
  ma_object->type = MA_OBJECT_DIIA;
  ma_object->diia_index = index;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_diia_native(
    const std::function<MaCell(MaCell*, MaMa*, MaScope*)>& diia_native_fn) {
  const auto ma_object = new MaObject();
  ma_object->type = MA_OBJECT_DIIA_NATIVE;
  ma_object->diia_native = diia_native_fn;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_object(MaObject* structure) {
  const auto ma_object = new MaObject();
  const auto object_cell = MaCell{MA_CELL_OBJECT, {.object = ma_object}};
  ma_object->structure = structure;
  for (const auto& [name, method] : structure->methods) {
    const auto diia_cell = create_diia(method->diia_index);
    diia_cell.v.object->params = method->params;
    diia_cell.v.object->diia_me = ma_object;
    ma_object_set(ma_object, name, diia_cell);
  }
  return object_cell;
}

inline MaCell create_structure() {
  const auto ma_object = new MaObject();
  ma_object->type = MA_OBJECT_STRUCTURE;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

#endif // OBJECTS_H
