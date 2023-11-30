// todo: optimize

function mavka_compare_eq(a, b, di) {
  if (a === b) {
    return true;
  }
  if (a == null && b == null) {
    return true;
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_рівно"]) {
    return a.__m_props__["чародія_порівняти_чи_рівно"]([b], di);
  }
  return false;
}

function mavka_compare_lt(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням.", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_менше"]) {
    return a.__m_props__["чародія_порівняти_чи_менше"]([b], di);
  }
  return a < b;
}

function mavka_compare_gt(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням.", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_більше"]) {
    return a.__m_props__["чародія_порівняти_чи_більше"]([b], di);
  }
  return a > b;
}

function mavka_compare_le(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням.", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_не_більше"]) {
    return a.__m_props__["чародія_порівняти_чи_не_більше"]([b], di);
  }
  return a <= b;
}

function mavka_compare_ge(a, b, di) {
  if (a == null || b == null) {
    throw new MavkaError("Неможливо порівняти з пустим значенням.", di);
  }
  if (a.__m_props__ && a.__m_props__["чародія_порівняти_чи_не_менше"]) {
    return a.__m_props__["чародія_порівняти_чи_не_менше"]([b], di);
  }
  return a >= b;
}

function mavka_compare_is(a, b, di) {
  if (a == null && b == null) {
    return true;
  }
  if (a == null && b != null) {
    return false;
  }
  if (a != null && b == null) {
    return false;
  }
  if (a.__m_type__ === "number") {
    return b === м_число;
  }
  if (a.__m_type__ === "text") {
    return b === м_текст;
  }
  if (a.__m_type__ === "logical") {
    return b === м_логічне;
  }
  if (a.__m_type__ === "list") {
    return b === м_список;
  }
  if (a.__m_type__ === "diia") {
    return b === м_Дія;
  }
  if (a.__m_type__ === "dictionary") {
    return b === м_словник;
  }
  if (a.__m_type__ === "bytes") {
    return b === м_байти;
  }
  if (a.__m_type__ === "god") {
    return a.__m_elements__.some((el) => mavka_compare_is(el, b, di));
  }
  if (a.__m_type__ === "object") {
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
  }
  throw new MavkaError("[BUG] невідоме значення для порівняння: " + a.__m_type__, di);
}

function mavka_compare_contains(a, b, di) {
  if (a == null) {
    throw new MavkaError("Неможливо перевірити чи містить з пустим значенням.", di);
  }
  if (a.__m_type__ === "text") {
    if (b && b.__m_type__ === "text") {
      return a.includes(b);
    }
  }
  if (a.__m_type__ === "list" || a.__m_type__ === "bytes") {
    return a.includes(b);
  }
  if (a.__m_type__ === "dictionary") {
    return a.has(b);
  }
  if (a.__m_type__ === "object") {
    if (b && b.__m_type__ === "text") {
      return b in a.__m_props__;
    }
  }
  throw new MavkaError("Неможливо перевірити чи містить.", di);
}

var not = function(a, di) {
  return !mavka_to_boolean(a, di);
};