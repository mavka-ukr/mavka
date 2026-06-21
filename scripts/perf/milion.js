function f(a, b, c, d) {
  return a + b + c + d;
}

class C {
  constructor(x) {
    this.x = x;
  }
}

let x = 0;
let c = new C(x);
const m = 1000000;

while (x < m) {
  f(1, 2, 3, 4);
  c = new C(x);
  x += 1;
}

console.log(c);
console.log(x);