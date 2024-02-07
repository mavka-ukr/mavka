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
  std::unordered_map<MaCell*, MaCell*> o_map;
  std::unordered_map<std::string, MaCell*> s_map;
  std::unordered_map<double, MaCell*> n_map;

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
  bool has(const std::string& name) const;
};

class MaStructure final {
 public:
  std::map<std::string, std::any> params;
};

class MaCell final {
 public:
  unsigned char type;
  void* value;
  long ref_count;

  void retain();
  void release();

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

inline MaCell* create_list() {
  return new MaCell(MA_LIST, new MaList());
}

inline MaCell* create_dict() {
  return new MaCell(MA_DICT, new MaDict());
}

inline MaCell* create_diia(const int& index) {
  return new MaCell(MA_DIIA, new MaDiia(index));
}

inline MaCell* create_diia_native(MaDiiaNativeFn diia_native_fn) {
  return new MaCell(MA_DIIA_NATIVE, new MaDiiaNative(diia_native_fn));
}

inline MaCell* create_object() {
  return new MaCell(MA_OBJECT, new MaObject());
}

inline MaCell* create_structure() {
  return new MaCell(MA_STRUCTURE, new MaStructure());
}

inline void MaDict::set(MaCell* key, MaCell* value) {
  if (key->type == MA_NUMBER) {
    if (const auto it = n_map.find(key->number()); it != n_map.end()) {
      it->second->release();
    }
    value->retain();
    n_map.insert_or_assign(key->number(), value);
  } else if (key->type == MA_STRING) {
    if (const auto it = s_map.find(key->string()); it != s_map.end()) {
      it->second->release();
    }
    value->retain();
    s_map.insert_or_assign(key->string(), value);
  } else {
    if (const auto it = o_map.find(key); it != o_map.end()) {
      it->second->release();
    }
    value->retain();
    o_map.insert_or_assign(key, value);
  }
}

inline void MaDict::set(const std::string& key, MaCell* value) {
  if (const auto it = s_map.find(key); it != s_map.end()) {
    it->second->release();
  }
  value->retain();
  s_map.insert_or_assign(key, value);
}

inline MaCell* MaDict::get(MaCell* key) const {
  if (key->type == MA_NUMBER) {
    if (const auto it = n_map.find(key->number()); it != n_map.end()) {
      return it->second;
    }
  } else if (key->type == MA_STRING) {
    if (const auto it = s_map.find(key->string()); it != s_map.end()) {
      return it->second;
    }
  } else {
    if (const auto it = o_map.find(key); it != o_map.end()) {
      return it->second;
    }
  }
  return nullptr;
}

inline void MaDict::remove(MaCell* key) {
  if (key->type == MA_NUMBER) {
    if (n_map.contains(key->number())) {
      const auto value = n_map[key->number()];
      value->release();
      n_map.erase(key->number());
    }
  } else if (key->type == MA_STRING) {
    if (s_map.contains(key->string())) {
      const auto value = s_map[key->string()];
      value->release();
      s_map.erase(key->string());
    }
  } else {
    if (o_map.contains(key)) {
      const auto value = o_map[key];
      value->release();
      o_map.erase(key);
      key->release();
    }
  }
}

inline long MaDict::size() const {
  return n_map.size() + s_map.size() + o_map.size();
}

inline void MaObject::set(const std::string& name, MaCell* value) {
  if (const auto it = properties.find(name); it != properties.end()) {
    it->second->release();
  }
  properties.insert_or_assign(name, value);
  value->retain();
}

inline MaCell* MaObject::get(const std::string& name) const {
  const auto it = properties.find(name);
  if (it != properties.end()) {
    return it->second;
  }
  return nullptr;
}

inline bool MaObject::has(const std::string& name) const {
  return properties.contains(name);
}

inline void MaCell::retain() {
  ref_count++;
}

inline void MaCell::release() {
  ref_count--;

  if (ref_count == 0) {
    // delete this;
  }
}

#endif // OBJECTS_H
