#ifndef MA_OBJECT_H
#define MA_OBJECT_H

class MaString;
class MaList;
class MaDict;
class MaDiia;
class MaStructure;
class MaDiiaNative;
class MaModule;
struct MaCell;

struct MaObject {
  unsigned char type;
  union {
    void* ptr;
    MaString* string;
    MaList* list;
    MaDict* dict;
    MaDiia* diia;
    MaStructure* structure;
    MaDiiaNative* diia_native;
    MaModule* module;
  } d;
  MaObject* structure;
  tsl::ordered_map<std::string, MaCell> properties;
  std::function<
      void(MaMa* M, MaObject* me, const std::string& name, MaCell value)>
      set;
  std::function<MaCell(MaMa* M, MaObject* me, const std::string& name)> get;
};

union MaCellV {
  MaObject* object;
  double number;
  MaArgs* args;
};

struct MaCell {
  unsigned char type;
  MaCellV v;
};

class MaString final {
 public:
  std::string data;

  size_t length() const;
  std::string substr(size_t start, size_t length) const;
};

class MaList final {
 public:
  std::vector<MaCell> data;

  void append(MaCell cell);
  void set(size_t index, MaCell cell);
  MaCell get(size_t index) const;
  size_t size() const;
  bool contains(MaCell cell);
};

class MaDict final {
 public:
  std::vector<std::pair<MaCell, MaCell>> data;

  void set(MaCell key, MaCell value);
  MaCell get(MaCell key) const;
  void remove(MaCell key);
  size_t size() const;
};

class MaDiiaParam final {
 public:
  std::string name;
  MaCell default_value;
};

class MaDiia final {
 public:
  std::string name;
  MaCode* code;
  MaObject* me;
  MaScope* scope;
  MaObject* module;
  std::vector<MaDiiaParam> params;
};

class MaStructure final {
 public:
  std::string name;
  std::vector<MaDiiaParam> params;
  std::vector<MaObject*> methods;
};

typedef void DiiaNativeFn(MaMa* M, MaObject* me, MaArgs* args);

class MaDiiaNative final {
 public:
  std::string name;
  std::function<DiiaNativeFn> fn;
  MaObject* me;
};

class MaModule final {
 public:
  std::string name;
  MaCode* code;
  bool is_file_module;
};

inline std::string ma_number_to_string(const double number) {
  std::ostringstream stream;
  stream << number;
  return stream.str();
}

inline void ma_object_set(MaObject* object,
                          const std::string& name,
                          MaCell value) {
  object->properties.insert_or_assign(name, value);
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

void init_object(MaMa* M);
void init_structure(MaMa* M);
void init_structure_2(MaMa* M);
void init_number(MaMa* M);
void init_logical(MaMa* M);
void init_text(MaMa* M);
void init_list(MaMa* M);
void init_dict(MaMa* M);
void init_diia(MaMa* M);
void init_module(MaMa* M);
void init_object(MaMa* M);

MaCell create_empty_object(MaMa* M);
MaCell create_object(MaMa* M,
                     unsigned char type,
                     MaObject* structure_object,
                     void* d);
MaCell create_string(MaMa* M, const std::string& value);
MaCell create_diia(MaMa* M,
                   const std::string& name,
                   MaCode* code,
                   MaObject* me);
MaCell create_diia_native(MaMa* M,
                          const std::string& name,
                          const std::function<DiiaNativeFn>& diia_native_fn,
                          MaObject* me);
MaCell bind_diia(MaMa* M, MaObject* diia, MaObject* object);
MaCell create_list(MaMa* M);
MaCell create_dict(MaMa* M);
MaCell create_structure(MaMa* M, const std::string& name);
MaCell create_module(MaMa* M, const std::string& name);

#endif // MA_OBJECT_H
