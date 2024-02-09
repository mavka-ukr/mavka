#ifndef OBJECTS_H
#define OBJECTS_H

class MaString;
class MaList;
class MaDict;
class MaDiia;
class MaStructure;
class MaDiiaNative;
struct MaCell;

struct MaObject {
  unsigned char type;
  union {
    MaString* string;
    MaList* list;
    MaDict* dict;
    MaDiia* diia;
    MaStructure* structure;
    MaDiiaNative* diia_native;
  } d;
  MaObject* structure;
  std::map<std::string, MaCell> properties;
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

class MaString final {
 public:
  std::string data;
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

class MaDiia final {
 public:
  long index;
  MaObject* me;
  std::vector<std::string> params;
  bool is_method;
};

class MaStructure final {
 public:
  std::vector<std::string> params;
  std::map<std::string, MaObject*> methods;
};

class MaDiiaNative final {
 public:
  std::function<MaCell(MaCell* self, MaMa* M, MaScope* S)> fn;
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
  const auto ma_string = new MaString();
  ma_string->data = value;
  ma_object->d.string = ma_string;
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
  const auto ma_diia = new MaDiia();
  ma_diia->index = index;
  ma_object->d.diia = ma_diia;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_diia_native(
    const std::function<MaCell(MaCell*, MaMa*, MaScope*)>& diia_native_fn) {
  const auto ma_object = new MaObject();
  ma_object->type = MA_OBJECT_DIIA_NATIVE;
  const auto ma_diia_native = new MaDiiaNative();
  ma_diia_native->fn = diia_native_fn;
  ma_object->d.diia_native = ma_diia_native;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaCell create_object(MaObject* ma_structure_object) {
  const auto ma_object = new MaObject();
  const auto object_cell = MaCell{MA_CELL_OBJECT, {.object = ma_object}};
  ma_object->structure = ma_structure_object;
  for (const auto& [name, method] : ma_structure_object->d.structure->methods) {
    const auto diia_cell = create_diia(method->d.diia->index);
    diia_cell.v.object->d.diia->params = method->d.diia->params;
    diia_cell.v.object->d.diia->me = ma_object;
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
