await ((async function() {
  var json = mavka_module("json");
  json.__m_props__["parse"] = mavka_diia(
    "parse",
    {
      "значення": mavka_param(0, "значення", м_текст)
    },
    function(args, di, { arg }) {
      var value = arg("значення");
      var result = JSON.parse(value);

      function toMavkaValue(v) {
        if (Array.isArray(v)) {
          return v.map(toMavkaValue);
        }
        if (typeof v === "object" && v) {
          return new Map(Object.entries(v));
        }
        return v;
      }

      return toMavkaValue(result);
    }
  );
  json.__m_props__["stringify"] = mavka_diia(
    "stringify",
    {
      "значення": mavka_param(0, "значення")
    },
    function(args, di, { arg }) {
      var value = arg("значення");

      function replacer(key, value) {
        if (value instanceof Map) {
          return Object.fromEntries(value.entries());
        } else {
          return value;
        }
      }

      return JSON.stringify(value, replacer);
    }
  );
  return json;
})());
