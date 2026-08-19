<?php
$a = readline("Enter first number: ");
$b = readline("Enter second number: ");
$c = readline("Enter third number: ");
$largest = $a;
if ($b > $largest) $largest = $b;
if ($c > $largest) $largest = $c;
echo "Largest = " . $largest;
?>