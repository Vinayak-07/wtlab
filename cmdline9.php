<?php
$n = readline("Enter number of terms: ");
$a = 0; $b = 1;
echo "Fibonacci Series: ";
for ($i = 1; $i <= $n; $i++) {
    echo $a . " ";
    $next = $a + $b;
    $a = $b;
    $b = $next;
}
?>