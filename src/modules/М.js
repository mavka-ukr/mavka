((function() {
  return {
    __m_type__: "module",
    __m_name__: "М",
    __m_props__: {
      "Е": Math.E,
      "ЛОГ10": Math.LN10,
      "ЛОГ2": Math.LN2,
      "ЛОГ2Е": Math.LOG2E,
      "ЛОГ10Е": Math.LOG10E,
      "ПІ": Math.PI,
      "КОРІНЬ1_2": Math.SQRT1_2,
      "КОРІНЬ2": Math.SQRT2,
      "абс": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "значення", м_число, undefined, di);
          return Math.abs(value);
        };
        diiaValue.__m_name__ = "абс";
        return diiaValue;
      })()),
      "арккос": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "значення", м_число, undefined, di);
          return Math.acos(value);
        };
        diiaValue.__m_name__ = "арккос";
        return diiaValue;
      })()),
      "арксин": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "значення", м_число, undefined, di);
          return Math.asin(value);
        };
        diiaValue.__m_name__ = "арксин";
        return diiaValue;
      })()),
      "арктан": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "значення", м_число, undefined, di);
          return Math.atan(value);
        };
        diiaValue.__m_name__ = "арктан";
        return diiaValue;
      })()),
      "арктан2": ((function() {
        var diiaValue = (params, di) => {
          let y = mavka_arg(params, 0, "y", м_число, undefined, di);
          let x = mavka_arg(params, 1, "x", м_число, undefined, di);
          return Math.atan2(y, x);
        };
        diiaValue.__m_name__ = "арктан2";
        return diiaValue;
      })()),
      "до_більшого": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "значення", м_число, undefined, di);
          return Math.ceil(value);
        };
        diiaValue.__m_name__ = "до_більшого";
        return diiaValue;
      })()),
      "до_меншого": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "значення", м_число, undefined, di);
          return Math.floor(value);
        };
        diiaValue.__m_name__ = "до_меншого";
        return diiaValue;
      })()),
      "кос": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "кут", м_число, undefined, di);
          return Math.cos(value);
        };
        diiaValue.__m_name__ = "кос";
        return diiaValue;
      })()),
      "експ": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "експонента", м_число, undefined, di);
          return Math.exp(value);
        };
        diiaValue.__m_name__ = "експ";
        return diiaValue;
      })()),
      "найбільше": ((function() {
        var diiaValue = (params, di) => {
          let values = Object.values(params).map((v) => mavka_to_number(v, di));
          return Math.max(...values);
        };
        diiaValue.__m_name__ = "найбільше";
        return diiaValue;
      })()),
      "найменше": ((function() {
        var diiaValue = (params, di) => {
          let values = Object.values(params).map((v) => mavka_to_number(v, di));
          return Math.min(...values);
        };
        diiaValue.__m_name__ = "найменше";
        return diiaValue;
      })()),
      "степінь": ((function() {
        var diiaValue = (params, di) => {
          let base = mavka_arg(params, 0, "основа", м_число, undefined, di);
          let exponent = mavka_arg(params, 1, "показник", м_число, undefined, di);
          return Math.pow(base, exponent);
        };
        diiaValue.__m_name__ = "степінь";
        return diiaValue;
      })()),
      "округлити": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "значення", м_число, undefined, di);
          return Math.round(value);
        };
        diiaValue.__m_name__ = "округлити";
        return diiaValue;
      })()),
      "син": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "кут", м_число, undefined, di);
          return Math.sin(value);
        };
        diiaValue.__m_name__ = "син";
        return diiaValue;
      })()),
      "корінь": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "значення", м_число, undefined, di);
          return Math.sqrt(value);
        };
        diiaValue.__m_name__ = "корінь";
        return diiaValue;
      })()),
      "тан": ((function() {
        var diiaValue = (params, di) => {
          let value = mavka_arg(params, 0, "кут", м_число, undefined, di);
          return Math.tan(value);
        };
        diiaValue.__m_name__ = "тан";
        return diiaValue;
      })())
    }
  };
})());
