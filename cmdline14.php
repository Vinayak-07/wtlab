<?php
$num = readline("Enter a number: ");
$sum = 0;
$temp = $num;
while ($temp != 0) {
    $sum += $temp % 10;
    $temp = (int)($temp / 10);
}
echo "Sum of Digits = " . $sum;
?>