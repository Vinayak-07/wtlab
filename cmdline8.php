<?php
$num = readline("Enter a number: ");
$fact = 1;
for ($i = 1; $i <= $num; $i++) {
    $fact = $fact * $i;
}
echo "Factorial = " . $fact;
?>