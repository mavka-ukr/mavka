// todo: optimize

function mavka_add(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати додавання з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_додати"]) {
    return a.__m_props__["чародія_додати"]([b], di);
  }
  if (a.__m_type__ === "text" || b.__m_type__ === "text") {
    return a + b;
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a + b;
  }
  throw new MavkaError("Неможливо виконати додавання.", di);
}

function mavka_sub(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати віднімання з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_відняти"]) {
    return a.__m_props__["чародія_відняти"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a - b;
  }
  throw new MavkaError("Неможливо виконати віднімання.", di);
}

function mavka_mul(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати множення з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_помножити"]) {
    return a.__m_props__["чародія_помножити"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a * b;
  }
  throw new MavkaError("Неможливо виконати множення.", di);
}

function mavka_div(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати ділення з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_поділити"]) {
    return a.__m_props__["чародія_поділити"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a / b;
  }
  throw new MavkaError("Неможливо виконати ділення: ", di);
}

function mavka_mod(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати ділення за модулем остача з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_поділити_за_модулем_остача"]) {
    return a.__m_props__["чародія_поділити_за_модулем_остача"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a % b;
  }
  throw new MavkaError("Неможливо виконати ділення за модулем остача.", di);
}

function mavka_divDiv(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати ділення за модулем частка з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_поділити_за_модулем_частка"]) {
    return a.__m_props__["чародія_поділити_за_модулем_частка"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return Math.floor(a / b);
  }
  throw new MavkaError("Неможливо виконати ділення за модулем частка.", di);
}

function mavka_pow(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати піднесення до степеня з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_піднести_до_степеня"]) {
    return a.__m_props__["чародія_піднести_до_степеня"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a ** b;
  }
  throw new MavkaError("Неможливо виконати піднесення до степеня.", di);
}

function mavka_shiftLeft(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати зсув вліво з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_зсунути_вліво"]) {
    return a.__m_props__["чародія_зсунути_вліво"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a << b;
  }
  throw new MavkaError("Неможливо виконати зсув вліво.", di);
}

function mavka_shiftRight(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати зсув вправо з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_зсунути_вправо"]) {
    return a.__m_props__["чародія_зсунути_вправо"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a >> b;
  }
  throw new MavkaError("Неможливо виконати зсув вправо.", di);
}

function mavka_bitAnd(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати побітове і з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_побітове_і"]) {
    return a.__m_props__["чародія_побітове_і"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a & b;
  }
  throw new MavkaError("Неможливо виконати побітове і.", di);
}

function mavka_bitOr(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати побітове або з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_побітове_або"]) {
    return a.__m_props__["чародія_побітове_або"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a | b;
  }
  throw new MavkaError("Неможливо виконати побітове або.", di);
}

function mavka_bitNot(a, di) {
  if (a == null) {
    throw new MavkaError("Неможливо виконати побітове не з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_побітове_не"]) {
    return a.__m_props__["чародія_побітове_не"]();
  }
  if (a.__m_type__ === "number") {
    return ~a;
  }
  throw new MavkaError("Неможливо виконати побітове не.", di);
}

function mavka_bitXor(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо виконати побітове виключне або з \"пусто\".", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_побітове_виключне_або"]) {
    return a.__m_props__["чародія_побітове_виключне_або"]([b], di);
  }
  if (a.__m_type__ === "number" && b.__m_type__ === "number") {
    return a ^ b;
  }
  throw new MavkaError("Неможливо виконати побітове виключне або.", di);
}

function mavka_positive(a, di) {
  if (a == null) {
    throw new MavkaError("Неможливо отримати позитивне значення з \"пусто\".", di);
  }
  if (a.__m_type__ === "number") {
    return +a;
  }
  throw new MavkaError("Неможливо отримати позитивне значення.", di);
}

function mavka_negative(a, di) {
  if (a == null) {
    throw new MavkaError("Неможливо отримати відʼємне значення з \"пусто\".", di);
  }
  if (a.__m_type__ === "number") {
    return -a;
  }
  throw new MavkaError("Неможливо отримати відʼємне значення.", di);
}