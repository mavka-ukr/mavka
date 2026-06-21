<?php

function f($a, $b, $c, $d) {
    return $a + $b + $c + $d;
}

$m = 2;

class C {
    public $x;

    public function __construct($x) {
        $this->x = $x;
    }
}

$x = 0;
$c = new C($x);
$m = 1000000;

while ($x < $m) {
    f(1, 2, 3, 4);
    $c = new C($x);
    $x += 1; // Or $x++;
}

// PHP doesn't echo objects directly unless they have a __toString() method.
// print_r gives a clean string representation of the object.
print_r($c);
echo $x . PHP_EOL;