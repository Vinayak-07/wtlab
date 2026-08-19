<?php
$a = 12;
$b = 18;
$x = $a;
$y = $b;
while ($y != 0) {
    $temp = $y;
    $y = $x % $y;
    $x = $temp;
}
$gcd = $x;
$lcm = ($a * $b) / $gcd;
echo "LCM of $a and $b = " . $lcm;
?>