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

class MaDiiaParam final {
 public:
  std::string name;
  MaCell default_value;
};

class MaDiia final {
 public:
  int index;
  MaObject* me;
  MaScope* scope;
  std::vector<MaDiiaParam> params;
};

class MaStructure final {
 public:
  std::vector<MaDiiaParam> params;
  std::vector<MaObject*> methods;
};

class MaDiiaNative final {
 public:
  std::function<MaCell(MaMa* M, MaScope* S)> fn;
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
    const std::function<MaCell(MaMa*, MaScope*)>& diia_native_fn) {
  const auto ma_object = new MaObject();
  ma_object->type = MA_OBJECT_DIIA_NATIVE;
  const auto ma_diia_native = new MaDiiaNative();
  ma_diia_native->fn = diia_native_fn;
  ma_object->d.diia_native = ma_diia_native;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

inline MaObject* bind_diia(MaObject* diia, MaObject* object) {
  const auto new_ma_diia = new MaDiia();
  new_ma_diia->index = diia->d.diia->index;
  new_ma_diia->me = object;
  new_ma_diia->scope = diia->d.diia->scope;
  new_ma_diia->params = diia->d.diia->params;
  const auto new_diia_object = new MaObject();
  new_diia_object->type = MA_OBJECT_DIIA;
  new_diia_object->d.diia = new_ma_diia;
  return new_diia_object;
}

inline MaCell create_object(MaObject* ma_structure_object) {
  const auto ma_object = new MaObject();
  const auto object_cell = MaCell{MA_CELL_OBJECT, {.object = ma_object}};
  ma_object->structure = ma_structure_object;
  for (const auto& method : ma_structure_object->d.structure->methods) {
    const auto diia_name =
        ma_object_get(method, "назва").v.object->d.string->data;
    const auto bound_diia = bind_diia(method, ma_object);
    ma_object_set(ma_object, diia_name,
                  MaCell{MA_CELL_OBJECT, {.object = bound_diia}});
  }
  return object_cell;
}

inline MaCell create_structure() {
  const auto ma_object = new MaObject();
  ma_object->type = MA_OBJECT_STRUCTURE;
  const auto ma_structure = new MaStructure();
  ma_object->d.structure = ma_structure;
  return MaCell{MA_CELL_OBJECT, {.object = ma_object}};
}

#endif // OBJECTS_H
