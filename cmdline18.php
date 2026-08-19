<?php
$n = readline("Enter N: ");
$sum = 0;
for ($i = 1; $i <= $n; $i++) {
    $sum += $i;
}
echo "Sum of first $n natural numbers = " . $sum;
?>