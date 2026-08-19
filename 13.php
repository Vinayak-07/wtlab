<?php
$a = 36;
$b = 60;
$x = $a;
$y = $b;
while ($y != 0) {
    $temp = $y;
    $y = $x % $y;
    $x = $temp;
}
echo "GCD of $a and $b = " . $x;
?>