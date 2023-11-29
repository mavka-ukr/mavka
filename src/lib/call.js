// todo: optimize

function mavka_call(a, args = [], di = undefined) {
  if (a == null) {
    throw new MavkaError("Неможливо виконати \"пусто\".", di);
  }
  if (a === $логічне) {
    return mavka_to_boolean(mavka_arg(args, 0, "значення"), di);
  }
  if (a === $число) {
    return mavka_to_number(mavka_arg(args, 0, "значення"), di);
  }
  if (a === $текст) {
    return mavka_to_string(mavka_arg(args, 0, "значення"), di);
  }
  if (a === $список) {
    return [];
  }
  if (a === $байти) {
    var argValue = mavka_arg(args, 0, "значення", [$число]);
    var bytesObject;
    if (mavka_compare_is(argValue, $число, di)) {
      bytesObject = new Uint8Array(argValue);
    } else if (mavka_compare_is(argValue, $текст, di)) {
      bytesObject = globalUtf8Encoder.encode(argValue);
    } else {
      throw new MavkaError("Неможливо створити байти.", di);
    }
    return bytesObject;
  }
  if (a === $словник) {
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
  if (a === $Дія) {
    throw new MavkaError("Неможливо виконати.", di);
  }
  if (a === $Структура) {
    throw new MavkaError("Неможливо виконати.", di);
  }
  if (a === $Модуль) {
    throw new MavkaError("Неможливо виконати.", di);
  }
  if (a.__m_type__ === "diia") {
    return a(args, di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_викликати"]) {
    return a.__m_props__["чародія_викликати"](args, di);
  }
  throw new MavkaError(`Неможливо виконати "${mavka_get_type_name(a)}".`, di);
}