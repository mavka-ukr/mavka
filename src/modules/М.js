((function() {
  const М = mavka_module("М");
  М.__m_props__["Е"] = Math.E;
  М.__m_props__["ЛОГ10"] = Math.LN10;
  М.__m_props__["ЛОГ2"] = Math.LN2;
  М.__m_props__["ЛОГ2Е"] = Math.LOG2E;
  М.__m_props__["ЛОГ10Е"] = Math.LOG10E;
  М.__m_props__["ПІ"] = Math.PI;
  М.__m_props__["КОРІНЬ1_2"] = Math.SQRT1_2;
  М.__m_props__["КОРІНЬ2"] = Math.SQRT2;
  М.__m_props__["абс"] = mavka_diia(
    "абс",
    {
      "значення": mavka_param(0, "значення", м_число)
    },
    function(args, di, { arg }) {
      return Math.abs(arg("значення"));
    }
  );
  М.__m_props__["арккос"] = mavka_diia(
    "арккос",
    {
      "значення": mavka_param(0, "значення", м_число)
    },
    function(args, di, { arg }) {
      return Math.acos(arg("значення"));
    }
  );
  М.__m_props__["арксин"] = mavka_diia(
    "арксин",
    {
      "значення": mavka_param(0, "значення", м_число)
    },
    function(args, di, { arg }) {
      return Math.asin(arg("значення"));
    }
  );
  М.__m_props__["арктан"] = mavka_diia(
    "арктан",
    {
      "значення": mavka_param(0, "значення", м_число)
    },
    function(args, di, { arg }) {
      return Math.atan(arg("значення"));
    }
  );
  М.__m_props__["арктан2"] = mavka_diia(
    "арктан2",
    {
      "у": mavka_param(0, "у", м_число),
      "х": mavka_param(1, "х", м_число)
    },
    function(args, di, { arg }) {
      return Math.atan2(arg("у"), arg("х"));
    }
  );
  М.__m_props__["до_більшого"] = mavka_diia(
    "до_більшого",
    {
      "значення": mavka_param(0, "значення", м_число)
    },
    function(args, di, { arg }) {
      return Math.ceil(arg("значення"));
    }
  );
  М.__m_props__["до_меншого"] = mavka_diia(
    "до_меншого",
    {
      "значення": mavka_param(0, "значення", м_число)
    },
    function(args, di, { arg }) {
      return Math.floor(arg("значення"));
    }
  );
  М.__m_props__["кос"] = mavka_diia(
    "кос",
    {
      "кут": mavka_param(0, "кут", м_число)
    },
    function(args, di, { arg }) {
      return Math.cos(arg("кут"));
    }
  );
  М.__m_props__["експ"] = mavka_diia(
    "експ",
    {
      "експонента": mavka_param(0, "експонента", м_число)
    },
    function(args, di, { arg }) {
      return Math.exp(arg("експонента"));
    }
  );
  М.__m_props__["найбільше"] = mavka_diia(
    "найбільше",
    {
      "значення": mavka_param(0, "значення", м_список)
    },
    function(args, di, { arg }) {
      return Math.max(...arg("значення").map((v) => mavka_to_number(v, di)));
    }
  );
  М.__m_props__["найменше"] = mavka_diia(
    "найменше",
    {
      "значення": mavka_param(0, "значення", м_список)
    },
    function(args, di, { arg }) {
      return Math.min(...arg("значення").map((v) => mavka_to_number(v, di)));
    }
  );
  М.__m_props__["степінь"] = mavka_diia(
    "степінь",
    {
      "основа": mavka_param(0, "основа", м_число),
      "показник": mavka_param(1, "показник", м_число)
    },
    function(args, di, { arg }) {
      return Math.pow(arg("основа"), arg("показник"));
    }
  );
  М.__m_props__["округлити"] = mavka_diia(
    "округлити",
    {
      "значення": mavka_param(0, "значення", м_число)
    },
    function(args, di, { arg }) {
      return Math.round(arg("значення"));
    }
  );
  М.__m_props__["син"] = mavka_diia(
    "син",
    {
      "кут": mavka_param(0, "кут", м_число)
    },
    function(args, di, { arg }) {
      return Math.sin(arg("кут"));
    }
  );
  М.__m_props__["корінь"] = mavka_diia(
    "корінь",
    {
      "значення": mavka_param(0, "значення", м_число)
    },
    function(args, di, { arg }) {
      return Math.sqrt(arg("значення"));
    }
  );
  М.__m_props__["тан"] = mavka_diia(
    "тан",
    {
      "кут": mavka_param(0, "кут", м_число)
    },
    function(args, di, { arg }) {
      return Math.tan(arg("кут"));
    }
  );
  return М;
})());
