class MavkaError {
  constructor(value, di) {
    this.value = value;
    this.di = di;
  }
}

var $обʼєкт = Object;
var $пусто = null;
var $так = true;
var $ні = false;
var $логічне = Boolean;
var $число = Number;
var $текст = String;
var $список = Array;
var $словник;
var $Дія = Function;
var $Структура;
var $Модуль;

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
    return value([...valueArgs.__m_map__.entries()].reduce((acc, [k, v]) => {
      acc[k] = v;
      return acc;
    }, {}), di);
  }
  return value(valueArgs, di);
};

$словник = Object.create(null);
$словник.__m_type__ = "structure";
$словник.__m_name__ = "словник";
$словник.__m_props__ = Object.create(null);
$словник.__m_props__["розмір"] = (args, di) => {
  const value = mavka_arg(args, 0, "значення", $словник, undefined, di);
  return value.__m_map__.size;
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
    case "object":
      return value.__m_structure__;
    default:
      return null;
  }
};

$Модуль = Object.create(null);
$Модуль.__m_type__ = "structure";
$Модуль.__m_props__ = Object.create(null);

// comparison
var mavka_compare_eq = (a, b, context) => {
  if (a == null && b == null) {
    return true;
  }
  if (a === b) {
    return true;
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_рівно"]) {
    return a.__m_props__["чародія_порівняти_чи_рівно"]([b], context);
  }
  return false;
};

var mavka_compare_lt = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням: ", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_менше"]) {
    return a.__m_props__["чародія_порівняти_чи_менше"]([b], context);
  }
  return a < b;
};

var mavka_compare_gt = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням: ", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_більше"]) {
    return a.__m_props__["чародія_порівняти_чи_більше"]([b], context);
  }
  return a > b;
};

var mavka_compare_le = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням: ", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_не_більше"]) {
    return a.__m_props__["чародія_порівняти_чи_не_більше"]([b], context);
  }
  return a <= b;
};

var mavka_compare_ge = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням: ", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_не_менше"]) {
    return a.__m_props__["чародія_порівняти_чи_не_менше"]([b], context);
  }
  return a >= b;
};

var mavka_compare_is = (a, b, context) => {
  if (a == null && b == null) {
    return true;
  }
  if (a == null && b != null) {
    return false;
  }
  if (a != null && b == null) {
    return false;
  }
  switch (a.__m_type__) {
    case "number":
      return b === $число;
    case "text":
      return b === $текст;
    case "logical":
      return b === $логічне;
    case "list":
      return b === $список;
    case "diia":
      return b === $Дія;
    case "dictionary":
      return b === $словник;
    case "object":
      if (a.__m_structure__ === b) {
        return true;
      }
      let parent = a.__m_structure__.__m_parent__;
      while (parent) {
        if (parent === b) {
          return true;
        }
        parent = parent.__m_parent__;
      }
      return false;
    case "god":
      return a.__m_elements__.some((el) => mavka_compare_is(el, b, context));
    default:
      throw new MavkaError("[BUG] невідоме значення для порівняння: " + a.__m_type__, context);
  }
};

var mavka_compare_is_not = (a, b) => {
  return !mavka_compare_is(a, b);
};

var mavka_compare_contains = (a, b) => {
  if (typeof a === "string" && typeof b === "string") {
    return a.includes(b);
  }
  if (Array.isArray(a)) {
    return a.includes(b);
  }
  if (a.__m_type__ === "dictionary") {
    return a.__m_map__.has(b);
  }
  if (typeof a === "object" && typeof b === "string") {
    return b in a.__m_props__;
  }
  return false;
};

var mavka_compare_not_contains = (a, b) => {
  return !mavka_compare_contains(a, b);
};

// arithmetic
var mavka_add = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати додавання з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_додати"]) {
    return a.__m_props__["чародія_додати"]([b], context);
  }
  if (a.__m_type__ === "text" || b.__m_type__ === "text") {
    return a + b;
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a + b;
  }
  throw new MavkaError("Неможливо виконати додавання.", context);
};
var mavka_sub = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати віднімання з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_відняти"]) {
    return a.__m_props__["чародія_відняти"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a - b;
  }
  throw new MavkaError("Неможливо виконати віднімання.", context);
};
var mavka_mul = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати множення з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_помножити"]) {
    return a.__m_props__["чародія_помножити"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a * b;
  }
  throw new MavkaError("Неможливо виконати множення.", context);
};
var mavka_div = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати ділення з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_поділити"]) {
    return a.__m_props__["чародія_поділити"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a / b;
  }
  throw new MavkaError("Неможливо виконати ділення: ", context);
};
var mavka_mod = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати ділення за модулем остача з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_поділити_за_модулем_остача"]) {
    return a.__m_props__["чародія_поділити_за_модулем_остача"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a % b;
  }
  throw new MavkaError("Неможливо виконати ділення за модулем остача.", context);
};
var mavka_divDiv = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати ділення за модулем частка з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_поділити_за_модулем_частка"]) {
    return a.__m_props__["чародія_поділити_за_модулем_частка"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return Math.floor(a / b);
  }
  throw new MavkaError("Неможливо виконати ділення за модулем частка.", context);
};
var mavka_pow = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати піднесення до степеня з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_піднести_до_степеня"]) {
    return a.__m_props__["чародія_піднести_до_степеня"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a ** b;
  }
  throw new MavkaError("Неможливо виконати піднесення до степеня.", context);
};
var mavka_shiftLeft = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати зсув вліво з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_зсунути_вліво"]) {
    return a.__m_props__["чародія_зсунути_вліво"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a << b;
  }
  throw new MavkaError("Неможливо виконати зсув вліво.", context);
};
var mavka_shiftRight = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати зсув вправо з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_зсунути_вправо"]) {
    return a.__m_props__["чародія_зсунути_вправо"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a >> b;
  }
  throw new MavkaError("Неможливо виконати зсув вправо.", context);
};
var mavka_bitAnd = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати побітове і з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_побітове_і"]) {
    return a.__m_props__["чародія_побітове_і"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a & b;
  }
  throw new MavkaError("Неможливо виконати побітове і.", context);
};
var mavka_bitOr = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати побітове або з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_побітове_або"]) {
    return a.__m_props__["чародія_побітове_або"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a | b;
  }
  throw new MavkaError("Неможливо виконати побітове або.", context);
};
var mavka_bitNot = (a, context) => {
  if (a == null) {
    throw new MavkaError("Неможливо виконати побітове не з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_побітове_не"]) {
    return a.__m_props__["чародія_побітове_не"]();
  }
  if (a.__m_type__ === "number") {
    return ~a;
  }
  throw new MavkaError("Неможливо виконати побітове не.", context);
};
var mavka_bitXor = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати побітове виключне або з \"пусто\".", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_побітове_виключне_або"]) {
    return a.__m_props__["чародія_побітове_виключне_або"]([b], context);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a ^ b;
  }
  throw new MavkaError("Неможливо виконати побітове виключне або.", context);
};
var mavka_positive = (a, context) => {
  if (a == null) {
    throw new MavkaError("Неможливо отримати позитивне значення з \"пусто\".", context);
  }
  if (a.__m_type__ === "number") {
    return +a;
  }
  throw new MavkaError("Неможливо отримати позитивне значення.", context);
};
var mavka_negative = (a, context) => {
  if (a == null) {
    throw new MavkaError("Неможливо отримати відʼємне значення з \"пусто\".", context);
  }
  if (a.__m_type__ === "number") {
    return -a;
  }
  throw new MavkaError("Неможливо отримати відʼємне значення.", context);
};
var not = (a, context) => {
  return !mavka_to_boolean(a, context);
};

var mavka_to_boolean = (value, context) => {
  if (value && typeof value === "object") {
    if (value.__m_props__ && value.__m_props__["чародія_перетворення_на_логічне"]) {
      return value.__m_props__["чародія_перетворення_на_логічне"]();
    }
  }
  // todo: handle all mavka types and not just cast it to boolean
  return Boolean(value);
};

var mavka_to_number = (value, di) => {
  if (value && typeof value === "object") {
    if (value.__m_props__ && value.__m_props__["чародія_перетворення_на_число"]) {
      return value.__m_props__["чародія_перетворення_на_число"]();
    }
  }
  if (typeof value === "number") {
    return value;
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
    case "list":
      return "<список>";
    case "diia":
      return "<дія>";
    case "god":
      return "<бог>";
    case "dictionary":
      return "<словник>";
    case "object":
      return "<обʼєкт>";
    case "structure":
      return "<структура>";
    case "module":
      return "<модуль>";
    case "portal":
      return "<портал>";
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
    for (const [k, v] of value.__m_map__) {
      entries.push(`${mavka_to_pretty_string(k)}=${mavka_to_pretty_string(v, false)}`);
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
  return "<невідоме значення>" + value;
};

var mavka_arg = (args, index, name, type, defaultValue, di) => {
  if (type === undefined) {
    if (defaultValue === undefined) {
      return Array.isArray(args) ? args[index] : args[name];
    }
  }
  return mavka_mapArg(Array.isArray(args) ? args[index] : args[name], type, defaultValue, di);
};

// calls
var mavka_call = (a, args, context = {}) => {
  if (!a) {
    throw new MavkaError("Неможливо виконати \"пусто\".", context);
  }
  if (a === $логічне) {
    return mavka_to_boolean(mavka_arg(args, 0, "значення"), context);
  }
  if (a === $число) {
    return mavka_to_number(mavka_arg(args, 0, "значення"), context);
  }
  if (a === $текст) {
    return mavka_to_string(mavka_arg(args, 0, "значення"), context);
  }
  if (a === $список) {
    return [];
  }
  if (a === $словник) {
    const value = mavka_dictionary();
    if (Array.isArray(args)) {
      for (let i = 0; i < args.length; i++) {
        value.__m_map__.set(i, args[i]);
      }
    } else {
      for (const [k, v] of Object.entries(args)) {
        value.__m_map__.set(k, v);
      }
    }
    return value;
  }
  if (a === $Дія) {
    throw new MavkaError("Неможливо виконати.", context);
  }
  if (a === $Структура) {
    throw new MavkaError("Неможливо виконати.", context);
  }
  if (a === $Модуль) {
    throw new MavkaError("Неможливо виконати.", context);
  }
  if (a.__m_type__ === "diia") {
    return a(args, context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_викликати"]) {
    return a.__m_props__["чародія_викликати"](args, context);
  }
  throw new MavkaError("Неможливо виконати.", context);
};

// get/set
var mavka_commonGet = (a, b, context, magicDiia) => {
  if (!a) {
    throw new MavkaError("Неможливо отримати властивість з \"пусто\".", context);
  }
  if (a.__m_type__ === "list") {
    if (b.__m_type__ === "number") {
      return a[b];
    } else {
      if (b === "довжина") {
        return a.length;
      }
      if (b === "додати") {
        return function(p, di) {
          var value = mavka_arg(p, 0, "значення", undefined, undefined, di);
          a.push(value);
          return a;
        };
      }
      if (b === "забрати") {
        return function() {
          return a.pop();
        };
      }
      if (b === "отримати") {
        return function(p, di) {
          var index = mavka_arg(p, 0, "позиція", $число, undefined, di);
          return a[index];
        };
      }
      if (b === "сортувати") {
        return function(p, di) {
          var compareFn = mavka_arg(p, 0, "дія_порівняння", $Дія, undefined, di);
          return a.sort((a, b) => compareFn([a, b], di));
        };
      }
      if (b === "фільтрувати") {
        return function(p, di) {
          var predicateFn = mavka_arg(p, 0, "дія_перевірки", $Дія, undefined, di);
          return a.filter((v) => predicateFn([v], di));
        };
      }
      if (b === "знайти") {
        return function(p, di) {
          var predicateFn = mavka_arg(p, 0, "дія_перевірки", $Дія, undefined, di);
          return a.find((v) => predicateFn([v], di));
        };
      }
      if (b === "знайти_позицію") {
        return function(p, di) {
          var predicateFn = mavka_arg(p, 0, "дія_перевірки", $Дія, undefined, di);
          return a.findIndex((v) => predicateFn([v], di));
        };
      }
      if (b === "перетворити") {
        return function(p, di) {
          var transformFn = mavka_arg(p, 0, "дія_перетворення", $Дія, undefined, di);
          return a.map((v) => transformFn([v], di));
        };
      }
      if (b === "заповнити") {
        return function(p, di) {
          var value = mavka_arg(p, 0, "значення", undefined, undefined, di);
          return a.fill(value);
        };
      }
      if (b === "злити") {
        return function(p, di) {
          var value = mavka_arg(p, 0, "значення", $список, undefined, di);
          return a.concat(value);
        };
      }
      if (b === "зʼєднати") {
        return function(p, di) {
          var separator = mavka_arg(p, 0, "роздільник", $текст, "", di);
          return a.map((v) => mavka_to_string(v, di)).join(separator);
        };
      }
      if (b === "обернути") {
        return function() {
          return a.reverse();
        };
      }
      if (b === "зрізати") {
        return function(p, di) {
          var indexStart = mavka_arg(p, 0, "від", $число, undefined, di);
          var indexEnd = mavka_arg(p, 1, "до", [$число, null], undefined, di);
          return a.slice(indexStart, indexEnd ?? undefined);
        };
      }
      if (b === "скоротити") {
        return function(p, di) {
          var reduceFn = mavka_arg(p, 0, "дія_скорочення", $Дія, undefined, di);
          var initialValue = mavka_arg(p, 1, "початкове_значення", undefined, undefined, di);
          return a.reduce((acc, v) => reduceFn([acc, v], di), initialValue);
        };
      }
      return null;
    }
  }
  if (a.__m_type__ === "dictionary") {
    return a.__m_map__.get(b);
  }
  if (a.__m_type__ === "text") {
    if (b === "символ") {
      return function(p, di) {
        var index = mavka_arg(p, 0, "позиція", $число, undefined, di);
        return a.charAt(index);
      };
    }
    if (b === "код_символу") {
      return function(p, di) {
        var index = mavka_arg(p, 0, "позиція", $число, undefined, di);
        return a.charCodeAt(index);
      };
    }
    if (b === "позиція") {
      return function(p, di) {
        var value = mavka_arg(p, 0, "значення", $текст, undefined, di);
        return a.indexOf(value);
      };
    }
    if (b === "повторити") {
      return function(p, di) {
        var count = mavka_arg(p, 0, "кількість", $число, undefined, di);
        return a.repeat(count);
      };
    }
    if (b === "замінити") {
      return function(p, di) {
        var value = mavka_arg(p, 0, "старе_значення", $текст, undefined, di);
        var replacement = mavka_arg(p, 1, "нове_значення", $текст, undefined, di);
        return a.replaceAll(value, replacement);
      };
    }
    if (b === "замінити_перше") {
      return function(p, di) {
        var value = mavka_arg(p, 0, "старе_значення", $текст, undefined, di);
        var replacement = mavka_arg(p, 1, "нове_значення", $текст, undefined, di);
        return a.replace(value, replacement);
      };
    }
    if (b === "зрізати") {
      return function(p, di) {
        var indexStart = mavka_arg(p, 0, "від", $число, undefined, di);
        var indexEnd = mavka_arg(p, 1, "до", [$число, null], undefined, di);
        return a.substring(indexStart, indexEnd ?? undefined);
      };
    }
    if (b === "приєднати") {
      return function(p, di) {
        var value = (Array.isArray(p) ? p : Object.values(p))
          .map((v) => mavka_to_string(v, di))
          .join("");
        return a.concat(value);
      };
    }
    if (b === "розділити") {
      return function(p, di) {
        var separator = mavka_arg(p, 0, "роздільник", $текст, undefined, di);
        return a.split(separator);
      };
    }
    if (b === "починається_з") {
      return function(p, di) {
        var value = mavka_arg(p, 0, "значення", $текст, undefined, di);
        return a.startsWith(value);
      };
    }
    if (b === "закінчується_на") {
      return function(p, di) {
        var value = mavka_arg(p, 0, "значення", $текст, undefined, di);
        return a.endsWith(value);
      };
    }
    if (b === "обрізати") {
      return function(p, di) {
        return a.trim();
      };
    }
    if (b === "обтяти") {
      return function(p, di) {
        var lineNumberWhereSmallestIndentationIs = 0;
        var lines = a.split("\n");
        var smallestIndentation = Infinity;
        for (let i = 0; i < lines.length; i++) {
          const line = lines[i];
          if (!line.trim()) {
            continue;
          }
          const indentation = line.match(/^\s*/)[0].length;
          if (indentation < smallestIndentation) {
            smallestIndentation = indentation;
            lineNumberWhereSmallestIndentationIs = i;
          }
        }
        const result = [];
        for (let i = 0; i < lines.length; i++) {
          const line = lines[i];
          if (!line.trim()) {
            continue;
          }
          result.push(line.slice(smallestIndentation));
        }
        return result.join("\n");
      };
    }
    if (b === "довжина") {
      return a.length;
    }
  }
  if (!a.__m_props__) {
    throw new MavkaError(`Неможливо отримати властивість ${mavka_to_pretty_string(b, false)}.`, context);
  }
  if (magicDiia) {
    if (a.__m_props__[magicDiia]) {
      return a.__m_props__[magicDiia]([b], context);
    }
  }
  return a.__m_props__[b];
};

var mavka_get = (a, b, context) => mavka_commonGet(a, b, context);
var mavka_getSpecial = (a, b, context) => mavka_commonGet(a, b, context, "чародія_отримати_спеціальну_властивість");

var mavka_set = (a, b, c, context) => {
  if (a == null) {
    throw new MavkaError("Неможливо встановити властивість для \"пусто\".", context);
  }
  if (a.__m_type__ === "list" && b.__m_type__ === "number") {
    a[b] = c;
  } else if (a.__m_type__ === "dictionary") {
    a.__m_map__.set(b, c);
  } else if (a.__m_props__) {
    a.__m_props__[b] = c;
  } else {
    throw new MavkaError("Неможливо встановити властивість.", context);
  }
};
var mavka_setSpecial = (a, b, c, context) => {
  if (a == null) {
    throw new MavkaError("Неможливо встановити властивість для \"пусто\".", context);
  }
  if (a.__m_type__ === "list" && b.__m_type__ === "number") {
    a[b] = c;
  } else if (a.__m_type__ === "dictionary") {
    a.__m_map__.set(b, c);
  } else if (a.__m_props__) {
    if (a.__m_props__["чародія_змінити_спеціальну_властивість"]) {
      a.__m_props__["чародія_змінити_спеціальну_властивість"]([b, c], context);
      return a;
    }
    a.__m_props__[b] = c;
  } else {
    throw new MavkaError("Неможливо встановити властивість.", context);
  }
};

// args
var mavka_mapArg = (value, type, defaultValue, di) => {
  if (value === undefined) {
    if (defaultValue === undefined) {
      if (type === undefined) {
        throw new MavkaError("Передано невідповідний обʼєкт.", di);
      } else {
        throw new MavkaError(`Очікується "${mavka_get_type_name(type)}", отримано ніщо.`, di);
      }
    } else {
      return defaultValue;
    }
  } else {
    if (Array.isArray(type)) {
      // todo: implement
    } else {
      if (type) {
        if (mavka_compare_is_not(value, type, di)) {
          var name = type.__m_type__ === "structure" ? type.__m_name__ : mavka_get_type_name(type);
          throw new MavkaError(`Очікується "${name}", отримано "${mavka_get_type_name(value)}".`, di);
        }
      }
    }
  }
  return value;
};

var mavka_mapReturn = (value, type, di) => {
  if (mavka_compare_is_not(value, type, di)) {
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

var mavka_dictionary = () => {
  var value = Object.create(null);
  value.__m_structure__ = $словник;
  value.__m_type__ = "dictionary";
  value.__m_props__ = Object.create(null);
  value.__m_map__ = new Map();
  return value;
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
          v.__m_props__["позиція"],
          k,
          v.__m_props__["тип"],
          v.__m_props__["значення"],
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
  var param = mavka_object();
  param.__m_props__["позиція"] = index;
  param.__m_props__["назва"] = name;
  param.__m_props__["тип"] = type;
  param.__m_props__["значення"] = defaultValue;
  return param;
};

var mavka_diia = (name, params, fn, result, di) => {
  var value = function(p, di) {
    return fn(p, di);
  };
  value.__m_name__ = name;
  return value;
};

var mavka_method = (structure, name, params, fn, result, di) => {
  if (structure.__m_type__ !== "structure") {
    throw new MavkaError(`${structure} не є структурою.`, di);
  }
  var value = function(me, p, di) {
    return fn(me, p, di);
  };
  value.__m_name__ = name;
  return value;
};

var mavka_spread = (value, di) => {
  if (Array.isArray(value)) {
    return value;
  }
  if (value.__m_type__ === "dictionary") {
    return Array.from(value.__m_map__.values());
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