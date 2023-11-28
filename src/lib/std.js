// std
var $друк = function(params, di) {
  console.log(...params.map((v) => mavka_to_pretty_string(v)));
};

// deprecated. use 0..n instead
var $діапазон = function* (params, di) {
  const start = Array.isArray(params) ? params[0] : params.старт;
  const end = Array.isArray(params) ? params[1] : params.стоп;

  for (let i = start; i < end; i++) {
    yield i;
  }
};

var $Помилка = mavka_structure(
  "Помилка",
  null,
  {
    "повідомлення": mavka_param(0, "повідомлення", $текст, "")
  }
);