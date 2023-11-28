// std
var $друк = function(args, di) {
  console.log(...args.map((v) => mavka_to_pretty_string(v)));
};

var $вивести = function(args, di) {
  process.stdout.write(args.map((v) => mavka_to_pretty_string(v)).join(""));
};

// deprecated. use 0..n instead
var $діапазон = function* (args, di) {
  const start = Array.isArray(args) ? args[0] : args.старт;
  const end = Array.isArray(args) ? args[1] : args.стоп;
  for (let i = start; i < end; i++) {
    yield i;
  }
};

var $читати = function(args, di) {
  var ask = mavka_arg(args, 0, "питання", $текст, "", di);
  return mavka_read({ sigint: true, encoding: "windows-1251" })(ask);
};