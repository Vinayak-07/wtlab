<?php
$a = readline("Enter first number: ");
$b = readline("Enter second number: ");
$x = $a;
$y = $b;
while ($y != 0) {
    $temp = $y;
    $y = $x % $y;
    $x = $temp;
}
echo "GCD = " . $x;
?>