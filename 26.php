<?php
function factorial($n) {
    if ($n <= 1) return 1;
    return $n * factorial($n - 1);
}
$num = 6;
echo "Factorial of $num = " . factorial($num);
?>