<?php
$a = readline("Enter first number: ");
$b = readline("Enter second number: ");
echo "Before Swap: a = $a, b = $b\n";
$temp = $a;
$a = $b;
$b = $temp;
echo "After Swap: a = $a, b = $b";
?>