const IT = 10000000;

let a = 0;

function pos() {
  return a - a;
}

function x() {
  function f(value) {
    const x = [2];
    return x[pos()] + value * 2;
  }

  let l = a + a;

  f(l);
}

while (a <= IT) {
    x();
    a = a + 1;
}