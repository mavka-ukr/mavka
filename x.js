function x() {
}

x.lol = "kek";

const xb = x.bind(2);

console.log(x);
console.log(x.lol);
console.log(xb);
console.log(xb.lol);
console.log(xb);
console.log(x === xb);