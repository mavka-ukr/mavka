// todo: optimize

function mavka_call(a, args = [], di = undefined) {
  if (a == null) {
    throw new MavkaError("Неможливо виконати \"пусто\".", di);
  }
  if (a === м_логічне) {
    return mavka_to_boolean(mavka_arg(args, 0, "значення"), di);
  }
  if (a === м_число) {
    return mavka_to_number(mavka_arg(args, 0, "значення"), di);
  }
  if (a === м_текст) {
    return mavka_to_string(mavka_arg(args, 0, "значення"), di);
  }
  if (a === м_список) {
    return [];
  }
  if (a === м_байти) {
    var argValue = mavka_arg(args, 0, "значення", [м_число]);
    var bytesObject;
    if (mavka_compare_is(argValue, м_число, di)) {
      bytesObject = new Uint8Array(argValue);
    } else if (mavka_compare_is(argValue, м_текст, di)) {
      bytesObject = mavka_utf8Encoder.encode(argValue);
    } else {
      throw new MavkaError("Неможливо створити байти.", di);
    }
    return bytesObject;
  }
  if (a === м_словник) {
    var dictMap = new Map();
    if (Array.isArray(args)) {
      for (let i = 0; i < args.length; i++) {
        dictMap.set(i, args[i]);
      }
    } else {
      for (const [k, v] of Object.entries(args)) {
        dictMap.set(k, v);
      }
    }
    return dictMap;
  }
  if (a === м_Дія) {
    throw new MavkaError("Неможливо виконати.", di);
  }
  if (a === м_Структура) {
    throw new MavkaError("Неможливо виконати.", di);
  }
  if (a === м_Модуль) {
    throw new MavkaError("Неможливо виконати.", di);
  }
  if (a.__m_type__ === "diia") {
    return a.__m_call__(args, di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_викликати"]) {
    return a.__m_props__["чародія_викликати"].__m_call__(args, di);
  }
  throw new MavkaError(`Неможливо виконати "${mavka_get_type_name(a)}".`, di);
}