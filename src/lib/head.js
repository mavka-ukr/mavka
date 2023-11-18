class MavkaError {
  constructor(value, di) {
    this.value = value;
    this.di = di;
  }
}

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
Object.__m_props__ = Object.create(null);
Object.prototype.__m_type__ = "object";

Boolean.__m_type__ = "structure";
Boolean.__m_props__ = Object.create(null);
Boolean.prototype.__m_type__ = "logical";

Number.__m_type__ = "structure";
Number.__m_props__ = Object.create(null);
Number.prototype.__m_type__ = "number";

String.__m_type__ = "structure";
String.__m_props__ = Object.create(null);
String.prototype.__m_type__ = "text";

Array.__m_type__ = "structure";
Array.__m_props__ = Object.create(null);
Array.prototype.__m_type__ = "list";

Function.__m_type__ = "structure";
Function.__m_props__ = Object.create(null);
Function.prototype.__m_type__ = "diia";

$словник = Object.create(null);
$словник.__m_type__ = "structure";
$словник.__m_props__ = Object.create(null);
$словник.__m_props__["розмір"] = (params, di) => {
  const value = param(params, 0, "значення", undefined, $словник, di);
  return value.__m_map__.size;
};

$Структура = Object.create(null);
$Структура.__m_type__ = "structure";
$Структура.__m_props__ = Object.create(null);

$Модуль = Object.create(null);
$Модуль.__m_type__ = "structure";
$Модуль.__m_props__ = Object.create(null);

// comparison
var compare_eq = (a, b, context) => {
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

var compare_lt = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням: ", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_менше"]) {
    return a.__m_props__["чародія_порівняти_чи_менше"]([b], context);
  }
  return a < b;
};

var compare_gt = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням: ", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_більше"]) {
    return a.__m_props__["чародія_порівняти_чи_більше"]([b], context);
  }
  return a > b;
};

var compare_le = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням: ", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_не_більше"]) {
    return a.__m_props__["чародія_порівняти_чи_не_більше"]([b], context);
  }
  return a <= b;
};

var compare_ge = (a, b, context) => {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням: ", context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_не_менше"]) {
    return a.__m_props__["чародія_порівняти_чи_не_менше"]([b], context);
  }
  return a >= b;
};

var compare_is = (a, b, context) => {
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
      if (a.constructor === b) {
        return true;
      }
      let parent = a.constructor.__m_parent__;
      while (parent) {
        if (parent === b) {
          return true;
        }
        parent = parent.__m_parent__;
      }
      return false;
    case "god":
      return a.__m_elements__.some((el) => compare_is(el, b, context));
    default:
      throw new MavkaError("[BUG] невідоме значення для порівняння: " + a.__m_type__, context);
  }
};

var compare_is_not = (a, b) => {
  return !compare_is(a, b);
};

var compare_contains = (a, b) => {
  if (typeof a === "string" && typeof b === "string") {
    return a.includes(b);
  }
  if (Array.isArray(a)) {
    return a.includes(b);
  }
  if (typeof a === "object" && typeof b === "string") {
    return b in a.__m_props__;
  }
  return false;
};

var compare_not_contains = (a, b) => {
  return !compare_contains(a, b);
};

// arithmetic
var add = (a, b, context) => {
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
var sub = (a, b, context) => {
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
var mul = (a, b, context) => {
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
var div = (a, b, context) => {
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
var mod = (a, b, context) => {
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
var divDiv = (a, b, context) => {
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
var pow = (a, b, context) => {
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
var shiftLeft = (a, b, context) => {
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
var shiftRight = (a, b, context) => {
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
var bitAnd = (a, b, context) => {
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
var bitOr = (a, b, context) => {
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
var bitNot = (a, context) => {
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
var bitXor = (a, b, context) => {
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
var positive = (a, context) => {
  if (a == null) {
    throw new MavkaError("Неможливо отримати позитивне значення з \"пусто\".", context);
  }
  if (a.__m_type__ === "number") {
    return +a;
  }
  throw new MavkaError("Неможливо отримати позитивне значення.", context);
};
var negative = (a, context) => {
  if (a == null) {
    throw new MavkaError("Неможливо отримати відʼємне значення з \"пусто\".", context);
  }
  if (a.__m_type__ === "number") {
    return -a;
  }
  throw new MavkaError("Неможливо отримати відʼємне значення.", context);
};
var not = (a, context) => {
  return !to_boolean(a, context);
};

var to_boolean = (value, context) => {
  if (value && typeof value === "object") {
    if (value.__m_props__ && value.__m_props__["чародія_перетворення_на_логічне"]) {
      return value.__m_props__["чародія_перетворення_на_логічне"]();
    }
  }
  // todo: handle all mavka types and not just cast it to boolean
  return Boolean(value);
};

var to_number = (value, context) => {
  if (value && typeof value === "object") {
    if (value.__m_props__ && value.__m_props__["чародія_перетворення_на_число"]) {
      return value.__m_props__["чародія_перетворення_на_число"]();
    }
  }
  // todo: handle all mavka types and not just cast it to boolean
  return Number(value);
};

var to_string = (value, context) => {
  if (value && typeof value === "object") {
    if (value.__m_props__ && value.__m_props__["чародія_перетворення_на_текст"]) {
      return value.__m_props__["чародія_перетворення_на_текст"]();
    }
  }
  // todo: handle all mavka types and not just cast it to boolean
  return String(value);
};

var to_pretty_string = (value, root = true) => {
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
    return "[" + value.map((v) => to_pretty_string(v, false)).join(", ") + "]";
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
        return el.constructor.__m_name__;
      }
      return "пусто";
    });
    return `<бог [${elementConstructors.join(", ")}]>`;
  }
  if (value.__m_type__ === "module") {
    var moduleKeys = Object.keys(value.__m_props__);
    return `<модуль ${value.__m_name__}[${moduleKeys.join(", ")}]>`;
  }
  if (value.__m_type__ === "dictionary") {
    const entries = [];
    for (const [k, v] of value.__m_map__) {
      entries.push(`${to_pretty_string(k)}=${to_pretty_string(v, false)}`);
    }
    return "(" + entries.join(", ") + ")";
  }
  if (value.__m_props__ && value.__m_props__["чародія_перетворення_на_текст"]) {
    return value.__m_props__["чародія_перетворення_на_текст"]();
  }
  return "<невідоме значення>";
};

var param = (params, index, name, defaultValue, type, di) => {
  if (type) {
    return mapParam(Array.isArray(params) ? params[index] : params[name], type, defaultValue, di);
  }
  return Array.isArray(params) ? params[index] : params[name];
};

// calls
var call = (a, params, context = {}) => {
  if (!a) {
    throw new MavkaError("Неможливо виконати \"пусто\".", context);
  }
  if (a === $логічне) {
    return to_boolean(param(params, 0, "значення"), context);
  }
  if (a === $число) {
    return to_number(param(params, 0, "значення"), context);
  }
  if (a === $текст) {
    return to_string(param(params, 0, "значення"), context);
  }
  if (a === $список) {
    return [];
  }
  if (a === $словник) {
    const value = Object.create(null);
    value.constructor = $словник;
    value.__m_type__ = "dictionary";
    value.__m_props__ = Object.create(null);
    value.__m_map__ = new Map();
    value.constructor = $словник;
    if (Array.isArray(params)) {
      for (let i = 0; i < params.length; i++) {
        value.__m_map__.set(i, params[i]);
      }
    } else {
      for (const [k, v] of Object.entries(params)) {
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
    return a(params, context);
  }
  if (a.__m_props__ && a.__m_props__["чародія_викликати"]) {
    return a.__m_props__["чародія_викликати"](params, context);
  }
  throw new MavkaError("Неможливо виконати.", context);
};

// get/set
var get = (a, b, context) => {
  if (!a) {
    throw new MavkaError("Неможливо отримати властивість з \"пусто\".", context);
  }
  if (a.__m_type__ === "list") {
    if (b.__m_type__ === "number") {
      return a[b];
    } else {
      if (b === "додати") {
        return (params) => {
          var value = param(params, 0, "значення");
          a.push(value);
          return a;
        };
      }
      if (b === "довжина") {
        return a.length;
      }
      return null;
    }
  }
  if (a.__m_type__ === "dictionary") {
    return a.__m_map__.get(b);
  }
  if (!a.__m_props__) {
    throw new MavkaError(`Неможливо отримати властивість ${to_pretty_string(b, false)}.`, context);
  }
  return a.__m_props__[b];
};

var getSpecial = (a, b, context) => {
  if (!a) {
    throw new MavkaError("Неможливо отримати спеціальну властивість з \"пусто\".", context);
  }
  if (a.__m_type__ === "list") {
    if (b.__m_type__ === "number") {
      return a[b];
    } else {
      if (b === "додати") {
        return (params) => {
          var value = param(params, 0, "значення");
          a.push(value);
          return a;
        };
      }
      if (b === "довжина") {
        return a.length;
      }
      return null;
    }
  }
  if (a.__m_type__ === "dictionary") {
    return a.__m_map__.get(b);
  }
  if (!a.__m_props__) {
    throw new MavkaError(`Неможливо отримати спеціальну властивість ${to_pretty_string(b, false)}.`, context);
  }
  if (a.__m_props__["чародія_отримати_спеціальну_властивість"]) {
    return a.__m_props__["чародія_отримати_спеціальну_властивість"]([b], context);
  }
  return a.__m_props__[b];
};
var set = (a, b, c, context) => {
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
var setSpecial = (a, b, c, context) => {
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

// params
var mapParam = (value, type, defaultValue, di) => {
  if (value) {
    if (compare_is_not(value, type, di)) {
      throw new MavkaError("Передано невідповідний обʼєкт.", di);
    }
  } else {
    if (defaultValue !== undefined) {
      return defaultValue;
    }
  }
  return value;
};

var mapReturn = (value, type, di) => {
  if (compare_is_not(value, type, di)) {
    throw new MavkaError("Невірний тип результату.", di);
  }
  return value;
};

// as
var as = (value, type, di) => {
  if (value && value.__m_type__ === "god") {
    const el = value.__m_elements__.find((el) => compare_is(el, type, di));
    if (el) {
      return el;
    }
    throw new MavkaError("Неможливо отримати бога як todo.", di);
  }
  throw new MavkaError("Неможливо перетворити значення.", di);
};
