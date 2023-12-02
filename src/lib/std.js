var м_друк = mavka_diia("друк", {}, function(args, di) {
  console.log(...args.map((v) => mavka_to_pretty_string(v)));
});

var м_вивести = mavka_diia("вивести", {}, function(args, di) {
  process.stdout.write(args.map((v) => mavka_to_pretty_string(v)).join(""));
});

var м_читати = mavka_diia(
  "читати", {
    "питання": mavka_param(0, м_текст, "")
  },
  function(args, di, { arg }) {
    return mavka_read({ sigint: true, encoding: "windows-1251" })(arg("питання"));
  }
);

var м_діапазон = function() {
};
м_діапазон.__m_call__ = function* (args, di) {
  const start = Array.isArray(args) ? args[0] : args.старт;
  const end = Array.isArray(args) ? args[1] : args.стоп;
  for (let i = start; i < end; i++) {
    yield i;
  }
};
м_діапазон.__m_type__ = "diia";
