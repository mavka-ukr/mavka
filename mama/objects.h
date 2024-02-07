#ifndef OBJECTS_H
#define OBJECTS_H

class MaNumber;
class MaString;
class MaList;
class MaDict;
class MaDiia;
class MaDiiaNative;
class MaObject;
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
  std::map<MaCell*, MaCell*> value;
};

class MaDiia final {
 public:
  int index;
};

typedef void (*MaDiiaNativeFn)(MaCell*, MaMa*, MaScope*);

class MaDiiaNative final {
 public:
  MaDiiaNativeFn value;
};

class MaObject final {
 public:
  std::map<std::string, MaCell*> properties;

  inline MaCell* get_property(const std::string& name) const {
    const auto it = properties.find(name);
    if (it != properties.end()) {
      return it->second;
    }
    return nullptr;
  }
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

#endif // OBJECTS_H
