function mavka_diia(name, params, fn, result, di) {
  var diia = function(...args) {
    return diia.__m_call__(args);
  };
  diia.__m_call__ = function(args, di) {
    var arg = function(argName) {
      return mavka_arg(
        args,
        diia.__m_params__[argName].get("позиція"),
        argName,
        diia.__m_params__[argName].get("тип"),
        diia.__m_params__[argName].get("значення"),
        di
      );
    };
    return fn(args, di, { arg });
  };
  diia.__m_name__ = name;
  diia.__m_params__ = params;
  diia.__m_type__ = "diia";
  return diia;
}

function mavka_method(params, fn, result, di) {
  var method = function(me, args, di) {
    var arg = function(argName) {
      return mavka_arg(
        args,
        method.__m_params__[argName].get("позиція"),
        argName,
        method.__m_params__[argName].get("тип"),
        method.__m_params__[argName].get("значення"),
        di
      );
    };
    return fn(me, args, di, { arg });
  };
  method.__m_params__ = params;
  return method;
}

function mavka_param(index, type, defaultValue) {
  return new Map([
    ["позиція", index],
    ["тип", type],
    ["значення", defaultValue]
  ]);
}

function mavka_arg(args, index, name, type, defaultValue, di) {
  var value = Array.isArray(args) ? args[index] : args[name];
  if (type === undefined) {
    if (defaultValue === undefined) {
      return value === undefined ? null : value;
    } else {
      return value === undefined ? defaultValue : value;
    }
  }
  if (value === undefined) {
    if (defaultValue === undefined) {
      throw new MavkaError(`Не вистачає аргумента "${name}".`, di);
    } else {
      return defaultValue;
    }
  }
  if (Array.isArray(type)) {
    // todo: implement
  } else {
    if (type) {
      if (type.__m_type__ === "structure") {
        if (value != null) {
          if (value.__m_type__ === "dictionary") {
            return mavka_call(type, Object.fromEntries(value.entries()), di);
          }
        }
      }
      if (!mavka_compare_is(value, type, di)) {
        throw new MavkaError(`Очікується, що "${name}" буде "${type.__m_name__}", отримано "${mavka_get_type_name(value)}".`, di);
      }
    } else {
      if (value !== null) {
        throw new MavkaError(`Очікується, що "${name}" буде "пусто", отримано "${mavka_get_type_name(value)}".`, di);
      }
    }
  }
  return value;
}