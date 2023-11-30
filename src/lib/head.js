class MavkaError {
  constructor(value, di) {
    this.value = value;
    this.di = di;
  }
}

var mavka_utf8Decoder = new TextDecoder("utf-8");
var mavka_utf8Encoder = new TextEncoder("utf-8");

var м_обʼєкт = Object;
var м_пусто = null;
var м_так = true;
var м_ні = false;
var м_логічне = Boolean;
var м_число = Number;
var м_текст = String;
var м_список = Array;
var м_словник = Map;
var м_Дія = Function;
var м_Структура;
var м_Модуль;
var м_байти = Uint8Array;
var м_безкрай = Infinity;
var м_нечисло = NaN;

Object.__m_name__ = "обʼєкт";
Object.__m_props__ = Object.create(null);

Boolean.__m_name__ = "логічне";
Boolean.__m_props__ = Object.create(null);
Boolean.prototype.__m_type__ = "logical";

Number.__m_name__ = "число";
Number.__m_props__ = Object.create(null);
Number.prototype.__m_type__ = "number";

String.__m_name__ = "текст";
String.__m_props__ = Object.create(null);
String.prototype.__m_type__ = "text";

Array.__m_name__ = "список";
Array.__m_props__ = Object.create(null);
Array.prototype.__m_type__ = "list";

Function.__m_name__ = "Дія";
Function.__m_props__ = Object.create(null);
Function.prototype.__m_type__ = "diia";
Function.__m_props__["назва"] = (args, di) => {
  const value = mavka_arg(args, 0, "значення", м_Дія, undefined, di);
  return value.__m_name__;
};
Function.__m_props__["виконати"] = (args, di) => {
  const value = mavka_arg(args, 0, "значення", м_Дія, undefined, di);
  const valueArgs = mavka_arg(args, 1, "аргументи", [м_список, м_словник], undefined, di);
  if (mavka_compare_is(valueArgs, м_словник)) {
    return value(Object.fromEntries(valueArgs.entries()), di);
  }
  return value(valueArgs, di);
};

Map.__m_name__ = "словник";
Map.__m_props__ = Object.create(null);
Map.prototype.__m_type__ = "dictionary";
Map.__m_props__["розмір"] = (args, di) => {
  const value = mavka_arg(args, 0, "значення", м_словник, undefined, di);
  return value.size;
};

м_Структура = Object.create(null);
м_Структура.__m_name__ = "Структура";
м_Структура.__m_props__ = Object.create(null);
м_Структура.__m_props__["дізнатись"] = (args, di) => {
  const value = mavka_arg(args, 0, "значення", undefined, undefined, di);
  if (value == null) {
    return null;
  }
  switch (value.__m_type__) {
    case "logical":
      return м_логічне;
    case "number":
      return м_число;
    case "text":
      return м_текст;
    case "list":
      return м_список;
    case "diia":
      return м_Дія;
    case "dictionary":
      return м_словник;
    case "bytes":
      return м_байти;
    case "object":
      return value.__m_structure__;
    default:
      return null;
  }
};

м_Модуль = Object.create(null);
м_Модуль.__m_props__ = Object.create(null);

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
      if (value === Infinity) {
        return "безкрай";
      }
      if (Number.isNaN(value)) {
        return "неч";
      }
      return value.toString();
    case "text":
      return value;
    case "bytes":
      return mavka_utf8Decoder.decode(value);
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
    if (value === Infinity) {
      return "безкрай";
    }
    if (Number.isNaN(value)) {
      return "неч";
    }
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

var mavka_spread = (value, di) => {
  if (Array.isArray(value)) {
    return value;
  }
  if (value.__m_type__ === "dictionary") {
    return Array.from(value.values());
  }
  throw new MavkaError("Неможливо розгорнути значення.", di);
};

var mavka_entries = (value, di) => {
  if (value == null) {
    throw new MavkaError("Неможливо отримати ітератор.", di);
  }
  if (value.__m_type__ === "list") {
    return value.entries();
  }
  if (value.__m_type__ === "dictionary") {
    return value.entries();
  }
  if (value.__m_type__ === "object") {
    return Object.entries(value.__m_props__);
  }
  throw new MavkaError("Неможливо отримати ітератор.", di);
};

var mavka_values = (value, di) => {
  if (value == null) {
    throw new MavkaError("Неможливо отримати ітератор.", di);
  }
  if (value.__m_type__ === "list") {
    return value;
  }
  if (value.__m_type__ === "dictionary") {
    return value.values();
  }
  if (value.__m_type__ === "object") {
    return Object.values(value.__m_props__);
  }
  throw new MavkaError("Неможливо отримати ітератор.", di);
};

var м_Помилка = mavka_structure(
  "Помилка",
  null,
  {
    "повідомлення": mavka_param(0, "повідомлення", м_текст, "")
  }
);