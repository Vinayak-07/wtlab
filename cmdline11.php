<?php
$num = readline("Enter a number: ");
$temp = $num;
$reversed = 0;
while ($temp != 0) {
    $digit = $temp % 10;
    $reversed = $reversed * 10 + $digit;
    $temp = (int)($temp / 10);
}
echo "Reversed Number = " . $reversed;
?>