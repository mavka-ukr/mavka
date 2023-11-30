var mavka_module = (name) => {
  var value = Object.create(null);
  value.__m_structure__ = м_Модуль;
  value.__m_type__ = "module";
  value.__m_props__ = Object.create(null);
  value.__m_name__ = name;
  return value;
};