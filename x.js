let a = 0;

const x = () => {
    a = a + 1;
}

while (a <= 100000000) {
    x();
}