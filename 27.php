<?php
function fibonacci($n) {
    if ($n <= 1) return $n;
    return fibonacci($n - 1) + fibonacci($n - 2);
}
echo "Fibonacci Series: ";
for ($i = 0; $i < 10; $i++) {
    echo fibonacci($i) . " ";
}
?>