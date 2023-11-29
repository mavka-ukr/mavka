class MavkaError {
  constructor(value, di) {
    this.value = value;
    this.di = di;
  }
}

var globalUtf8Decoder = new TextDecoder();
var globalUtf8Encoder = new TextEncoder();

var $обʼєкт = Object;
var $пусто = null;
var $так = true;
var $ні = false;
var $логічне = Boolean;
var $число = Number;
var $текст = String;
var $список = Array;
var $словник = Map;
var $Дія = Function;
var $Структура;
var $Модуль;
var $байти = Uint8Array;

Object.__m_type__ = "structure";
Object.__m_name__ = "обʼєкт";
Object.__m_props__ = Object.create(null);

Boolean.__m_type__ = "structure";
Boolean.__m_name__ = "логічне";
Boolean.__m_props__ = Object.create(null);
Boolean.prototype.__m_type__ = "logical";

Number.__m_type__ = "structure";
Number.__m_name__ = "число";
Number.__m_props__ = Object.create(null);
Number.prototype.__m_type__ = "number";

String.__m_type__ = "structure";
String.__m_name__ = "текст";
String.__m_props__ = Object.create(null);
String.prototype.__m_type__ = "text";

Array.__m_type__ = "structure";
Array.__m_name__ = "список";
Array.__m_props__ = Object.create(null);
Array.prototype.__m_type__ = "list";

Function.__m_type__ = "structure";
Function.__m_name__ = "Дія";
Function.__m_props__ = Object.create(null);
Function.prototype.__m_type__ = "diia";
Function.__m_props__["назва"] = (args, di) => {
  const value = mavka_arg(args, 0, "значення", $Дія, undefined, di);
  return value.__m_name__;
};
Function.__m_props__["виконати"] = (args, di) => {
  const value = mavka_arg(args, 0, "значення", $Дія, undefined, di);
  const valueArgs = mavka_arg(args, 1, "аргументи", [$список, $словник], undefined, di);
  if (mavka_compare_is(valueArgs, $словник)) {
    return value(Object.fromEntries(valueArgs.entries()), di);
  }
  return value(valueArgs, di);
};

Map.__m_type__ = "structure";
Map.__m_name__ = "словник";
Map.__m_props__ = Object.create(null);
Map.prototype.__m_type__ = "dictionary";
Map.__m_props__["розмір"] = (args, di) => {
  const value = mavka_arg(args, 0, "значення", $словник, undefined, di);
  return value.size;
};

$Структура = Object.create(null);
$Структура.__m_type__ = "structure";
$Структура.__m_name__ = "Структура";
$Структура.__m_props__ = Object.create(null);
$Структура.__m_props__["дізнатись"] = (args, di) => {
  const value = mavka_arg(args, 0, "значення", undefined, undefined, di);
  if (value == null) {
    return null;
  }
  switch (value.__m_type__) {
    case "logical":
      return $логічне;
    case "number":
      return $число;
    case "text":
      return $текст;
    case "list":
      return $список;
    case "diia":
      return $Дія;
    case "dictionary":
      return $словник;
    case "bytes":
      return $байти;
    case "object":
      return value.__m_structure__;
    default:
      return null;
  }
};

$Модуль = Object.create(null);
$Модуль.__m_type__ = "structure";
$Модуль.__m_props__ = Object.create(null);

Uint8Array.__m_type__ = "structure";
Uint8Array.__m_name__ = "байти";
Uint8Array.__m_props__ = Object.create(null);
Uint8Array.prototype.__m_type__ = "bytes";

var mavka_to_boolean = (value, di) => {
  if (value == null) {
    return false;
  }
  if (value.__m_props__ && value.__m_props__["чародія_перетворення_на_логічне"]) {
    return value.__m_props__["чародія_перетворення_на_логічне"]();
  }
  return Boolean(value);
};

var mavka_to_number = (value, di) => {
  if (value == null) {
    return 0;
  }
  if (value.__m_props__ && value.__m_props__["чародія_перетворення_на_число"]) {
    return value.__m_props__["чародія_перетворення_на_число"]();
  }
  if (value.__m_type__ === "number") {
    return value;
  }
  if (value.__m_type__ === "text") {
    return Number(value);
  }
  throw new MavkaError("Неможливо перетворити на число.", di);
};

var mavka_to_string = (value, di) => {
  if (value == null) {
    return "пусто";
  }
  if (value.__m_props__ && value.__m_props__["чародія_перетворення_на_текст"]) {
    return value.__m_props__["чародія_перетворення_на_текст"]();
  }
  switch (value.__m_type__) {
    case "logical":
      return value ? "так" : "ні";
    case "number":
      return value.toString();
    case "text":
      return value;
    case "bytes":
      return globalUtf8Decoder.decode(value);
    default:
      throw new MavkaError("Неможливо перетворити на текст.", di);
  }
};

var mavka_get_type_name = (value) => {
  if (value == null) {
    return "пусто";
  }
  switch (value.__m_type__) {
    case "logical":
      return "логічне";
    case "number":
      return "число";
    case "text":
      return "текст";
    case "list":
      return "список";
    case "diia":
      return "Дія";
    case "god":
      return "бог";
    case "dictionary":
      return "словник";
    case "object":
      return value.__m_structure__.__m_name__;
    case "structure":
      return "Структура";
    case "module":
      return value.__m_name__;
    case "portal":
      return "портал";
    default:
      return "<невідомий тип>";
  }
};

var mavka_to_pretty_string = (value, root = true) => {
  if (value == null) {
    return "пусто";
  }
  if (value.__m_type__ === "logical") {
    return value ? "так" : "ні";
  }
  if (value.__m_type__ === "number") {
    return value.toString();
  }
  if (value.__m_type__ === "text") {
    if (root) {
      return value;
    }
    return `"${value}"`;
  }
  if (value.__m_type__ === "diia") {
    if (value.__m_name__) {
      return `<дія ${value.__m_name__}>`;
    } else {
      return `<дія>`;
    }
  }
  if (value.__m_type__ === "list") {
    return "[" + value.map((v) => mavka_to_pretty_string(v, false)).join(", ") + "]";
  }
  if (value.__m_type__ === "god") {
    const elementConstructors = value.__m_elements__.map((el) => {
      if (el.__m_type__ === "logical") {
        return "логічне";
      }
      if (el.__m_type__ === "number") {
        return "число";
      }
      if (el.__m_type__ === "text") {
        return "текст";
      }
      if (el.__m_type__ === "list") {
        return "список";
      }
      if (el.__m_type__ === "diia") {
        return "Дія";
      }
      if (el.__m_type__ === "god") {
        return "бог";
      }
      if (el.__m_type__ === "dictionary") {
        return "словник";
      }
      if (el.__m_type__ === "structure") {
        return "Структура";
      }
      if (el.__m_type__ === "object") {
        return el.__m_structure__.__m_name__;
      }
      return "пусто";
    });
    return `<бог [${elementConstructors.join(", ")}]>`;
  }
  if (value.__m_type__ === "module") {
    var moduleKeys = Object.keys(value.__m_props__);
    return `<модуль ${value.__m_name__}[${moduleKeys.join(", ")}]>`;
  }
  if (value.__m_type__ === "structure") {
    return `<структура ${value.__m_name__}>`;
  }
  if (value.__m_type__ === "dictionary") {
    const entries = [];
    for (const [k, v] of value) {
      entries.push(`${mavka_to_pretty_string(k, false)}=${mavka_to_pretty_string(v, false)}`);
    }
    return `(${entries.join(", ")})`;
  }
  if (value.__m_type__ === "object") {
    const entries = [];
    for (const k in value.__m_structure__.__m_params__) {
      entries.push(`${k}=${mavka_to_pretty_string(value.__m_props__[k], false)}`);
    }
    return `${value.__m_structure__.__m_name__}(${entries.join(", ")})`;
  }
  if (value.__m_type__ === "portal") {
    return `<портал>`;
  }
  if (value.__m_type__ === "bytes") {
    return `<байти ${value.length}>`;
  }
  return "<невідоме значення>";
};

var mavka_arg = (args, index, name, type, defaultValue, di) => {
  if (type === undefined) {
    if (defaultValue === undefined) {
      return Array.isArray(args) ? args[index] : args[name];
    }
  }
  return mavka_mapArg(Array.isArray(args) ? args[index] : args[name], name, type, defaultValue, di);
};

// args
var mavka_mapArg = (value, name, type, defaultValue, di) => {
  if (value === undefined) {
    if (defaultValue === undefined) {
      if (type === undefined) {
        throw new MavkaError("Передано невідповідний обʼєкт.", di);
      } else {
        if (Array.isArray(type)) {
          throw new MavkaError(`Очікується, що "${name}" буде "${type.map((t) => t.__m_name__).join(" або ")}", отримано ніщо.`, di);
        }
        throw new MavkaError(`Очікується, що "${name}" буде "${type.__m_name__}", отримано ніщо.`, di);
      }
    } else {
      return defaultValue;
    }
  } else {
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
      }
    }
  }
  return value;
};

var mavka_mapReturn = (value, type, di) => {
  if (!mavka_compare_is(value, type, di)) {
    throw new MavkaError("Невірний тип результату.", di);
  }
  return value;
};

// as
var mavka_do_as = (value, type, di) => {
  if (value && value.__m_type__ === "god") {
    const el = value.__m_elements__.find((el) => mavka_compare_is(el, type, di));
    if (el) {
      return el;
    }
    throw new MavkaError("Неможливо отримати бога як todo.", di);
  }
  throw new MavkaError("Неможливо перетворити значення.", di);
};

var mavka_portal = (value) => {
  if (value == null) {
    return null;
  }

  switch (typeof value) {
    case "string":
      return value;
    case "number":
      return value;
    case "boolean":
      return value;
    case "function":
      return value;
    default:
      if (Array.isArray(value)) {
        return value;
      }

      if (value.__m_type__) {
        return value;
      }

      var objectProxy = function(obj) {
        var object = Object.create(null);
        object.__m_type__ = "portal";
        object.__m_props__ = new Proxy(obj, {
          get(target, prop, receiver) {
            if (prop in target) {
              return mavka_portal(target[prop]);
            }
            return null;
          },
          set(target, prop, value, receiver) {
            if (value != null && value.__m_type__ === "object") {
              target[prop] = value.__m_props__;
            } else {
              target[prop] = value;
            }
            return true;
          }
        });
        return object;
      };

      return objectProxy(value);
  }
};

var mavka_module = (name) => {
  var value = Object.create(null);
  value.__m_structure__ = $Модуль;
  value.__m_type__ = "module";
  value.__m_props__ = Object.create(null);
  value.__m_name__ = name;
  return value;
};

var mavka_object = () => {
  var value = Object.create(null);
  value.__m_structure__ = $обʼєкт;
  value.__m_type__ = "object";
  value.__m_props__ = Object.create(null);
  return value;
};

var mavka_structure = (name, parent = null, params = {}, di = null) => {
  var mergedParams = params;
  var mergedMethods = Object.create(null);
  if (parent && parent.__m_type__ !== "structure") {
    throw new MavkaError("Неможливо створити структуру.", di);
  }
  // todo: check for circular inheritance
  // todo: check for duplicate params and methods
  var currStructure = parent;
  while (currStructure != null && currStructure.__m_type__ === "structure") {
    for (const [k, v] of Object.entries(currStructure.__m_params__)) {
      if (mergedParams[k]) {
        continue;
      }
      mergedParams[k] = v;
    }
    for (const [k, v] of Object.entries(currStructure.__m_methods__)) {
      if (mergedMethods[k]) {
        continue;
      }
      mergedMethods[k] = v;
    }
    currStructure = currStructure.__m_parent__;
  }
  var structure = class {
    static __m_type__ = "structure";
    static __m_props__ = Object.create(null);
    static __m_name__ = name;
    // structure specific
    static __m_params__ = mergedParams;
    static __m_methods__ = mergedMethods;
    static __m_parent__ = parent;

    constructor() {
      this.__m_structure__ = structure;
      this.__m_type__ = "object";
      this.__m_props__ = Object.create(null);
      // fill props and attach methods
      for (const [k, v] of Object.entries(structure.__m_params__)) {
        if (this.__m_props__[k]) {
          continue;
        }
        this.__m_props__[k] = v.defaultValue ?? null;
      }
      for (const [k, v] of Object.entries(structure.__m_methods__)) {
        if (this.__m_props__[k]) {
          continue;
        }
        this.__m_props__[k] = mavka_diia(k, v.__m_params__, (args, callDi) => {
          return v(this, args, callDi);
        }, undefined, di);
      }
    }
  };
  structure.__m_props__["чародія_викликати"] = mavka_diia("чародія_викликати", {}, (args, callDi) => {
    var value = new structure();
    if (value.__m_props__["чародія_створити"]) {
      value.__m_props__["чародія_створити"](args, callDi);
    } else {
      for (const [k, v] of Object.entries(structure.__m_params__)) {
        value.__m_props__[k] = mavka_arg(
          args,
          v.get("позиція"),
          k,
          v.get("тип"),
          v.get("значення"),
          callDi
        );
      }
    }
    if (value.__m_props__["чародія_після_створення"]) {
      value.__m_props__["чародія_після_створення"](args, callDi);
    }
    return value;
  }, undefined, di);
  return structure;
};

var mavka_param = (index, name, type, defaultValue) => {
  return new Map([
    ["позиція", index],
    ["назва", name],
    ["тип", type],
    ["значення", defaultValue]
  ]);
};

var mavka_diia = (name, params, fn, result, di) => {
  var value = function(args, di) {
    var arg = (argName) => {
      return mavka_arg(
        args,
        value.__m_params__[argName].get("позиція"),
        argName,
        value.__m_params__[argName].get("тип"),
        value.__m_params__[argName].get("значення"),
        di
      );
    };
    return fn(args, di, { arg });
  };
  value.__m_name__ = name;
  value.__m_params__ = params;
  return value;
};

var mavka_method = (structure, name, params, fn, result, di) => {
  if (structure.__m_type__ !== "structure") {
    throw new MavkaError(`${structure} не є структурою.`, di);
  }
  var value = function(me, args, di) {
    var arg = (argName) => {
      return mavka_arg(
        args,
        value.__m_params__[argName].get("позиція"),
        argName,
        value.__m_params__[argName].get("тип"),
        value.__m_params__[argName].get("значення"),
        di
      );
    };
    return fn(me, args, di, { arg });
  };
  value.__m_name__ = name;
  value.__m_params__ = params;
  return value;
};

var mavka_spread = (value, di) => {
  if (Array.isArray(value)) {
    return value;
  }
  if (value.__m_type__ === "dictionary") {
    return Array.from(value.values());
  }
  throw new MavkaError("Неможливо розгорнути значення.", di);
};

var $Помилка = mavka_structure(
  "Помилка",
  null,
  {
    "повідомлення": mavka_param(0, "повідомлення", $текст, "")
  }
);