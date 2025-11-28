let a = 0;

function x() {
  function f(value) {
    const x = [2];
    return x[0] + value * 2;
  }

  let l = a + a;

  f(l);
}

while (a <= 10000000) {
    x();
    a = a + 1;
}