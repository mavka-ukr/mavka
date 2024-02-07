#ifndef OBJECTS_H
#define OBJECTS_H

class MaNumber;
class MaString;
class MaList;
class MaDict;
class MaDiia;
class MaDiiaNative;
class MaObject;
class MaStructure;
class MaCell;

class MaNumber final {
 public:
  double value;
};

class MaString final {
 public:
  std::string value;
};

class MaList final {
 public:
  std::vector<MaCell*> value;
};

class MaDict final {
 public:
  std::map<MaCell*, MaCell*> o_map;
  std::map<std::string, MaCell*> s_map;
  std::map<double, MaCell*> n_map;

  void set(MaCell* key, MaCell* value);
  void set(const std::string& key, MaCell* value);
  MaCell* get(MaCell* key) const;
  void remove(MaCell* key);
  long size() const;
};

class MaDiia final {
 public:
  int index;
  std::map<std::string, std::any> params;
};

typedef void (*MaDiiaNativeFn)(MaCell*, MaMa*, MaScope*);

class MaDiiaNative final {
 public:
  MaDiiaNativeFn value;
};

class MaObject final {
 public:
  std::map<std::string, MaCell*> properties;

  void set(const std::string& name, MaCell* value);
  MaCell* get(const std::string& name) const;
};

class MaStructure final {
 public:
  std::map<std::string, std::any> params;
};

class MaCell final {
 public:
  unsigned char type;
  void* value;

  inline MaNumber* cast_number() const { return static_cast<MaNumber*>(value); }
  inline double number() const { return cast_number()->value; }
  inline long number_long() const { return static_cast<long>(number()); }

  inline MaString* cast_string() const { return static_cast<MaString*>(value); }
  inline std::string string() const { return cast_string()->value; }

  inline MaList* cast_list() const { return static_cast<MaList*>(value); }

  inline MaDict* cast_dict() const { return static_cast<MaDict*>(value); }

  inline MaDiia* cast_diia() const { return static_cast<MaDiia*>(value); }

  inline MaDiiaNative* cast_diia_native() const {
    return static_cast<MaDiiaNative*>(value);
  }

  inline MaObject* cast_object() const { return static_cast<MaObject*>(value); }

  inline MaStructure* cast_structure() const {
    return static_cast<MaStructure*>(value);
  }
};

inline MaCell* create_number(const double& number) {
  return new MaCell(MA_NUMBER, new MaNumber(number));
}

inline MaCell* create_string(const std::string& string) {
  return new MaCell(MA_STRING, new MaString(string));
}

inline MaCell* create_list(const std::vector<MaCell*>& list) {
  return new MaCell(MA_LIST, new MaList(list));
}

inline MaCell* create_dict(const std::map<MaCell*, MaCell*>& dict) {
  return new MaCell(MA_DICT, new MaDict(dict));
}

inline MaCell* create_diia(const int& index) {
  return new MaCell(MA_DIIA, new MaDiia(index));
}

inline MaCell* create_diia_native(MaDiiaNativeFn diia_native_fn) {
  return new MaCell(MA_DIIA_NATIVE, new MaDiiaNative(diia_native_fn));
}

inline MaCell* create_object(const std::map<std::string, MaCell*>& properties) {
  return new MaCell(MA_OBJECT, new MaObject{properties});
}

inline MaCell* create_structure(
    const std::map<std::string, std::any>& definitions) {
  return new MaCell(MA_STRUCTURE, new MaStructure{definitions});
}

inline void MaDict::set(MaCell* key, MaCell* value) {
  if (key->type == MA_NUMBER) {
    n_map.insert_or_assign(key->number(), value);
  } else if (key->type == MA_STRING) {
    s_map.insert_or_assign(key->string(), value);
  } else {
    o_map.insert_or_assign(key, value);
  }
}

inline void MaDict::set(const std::string& key, MaCell* value) {
  s_map.insert_or_assign(key, value);
}

inline MaCell* MaDict::get(MaCell* key) const {
  if (key->type == MA_NUMBER) {
    const auto it = n_map.find(key->number());
    if (it != n_map.end()) {
      return it->second;
    }
  } else if (key->type == MA_STRING) {
    const auto it = s_map.find(key->string());
    if (it != s_map.end()) {
      return it->second;
    }
  } else {
    const auto it = o_map.find(key);
    if (it != o_map.end()) {
      return it->second;
    }
  }
  return nullptr;
}

inline void MaDict::remove(MaCell* key) {
  if (key->type == MA_NUMBER) {
    n_map.erase(key->number());
  } else if (key->type == MA_STRING) {
    s_map.erase(key->string());
  } else {
    o_map.erase(key);
  }
}

inline long MaDict::size() const {
  return n_map.size() + s_map.size() + o_map.size();
}

inline void MaObject::set(const std::string& name, MaCell* value) {
  properties.insert_or_assign(name, value);
}

inline MaCell* MaObject::get(const std::string& name) const {
  const auto it = properties.find(name);
  if (it != properties.end()) {
    return it->second;
  }
  return nullptr;
}

#endif // OBJECTS_H
