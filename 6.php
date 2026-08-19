<?php
$num = 153;
$temp = $num;
$sum = 0;
$digits = strlen((string)$num);
while ($temp != 0) {
    $digit = $temp % 10;
    $sum += pow($digit, $digits);
    $temp = (int)($temp / 10);
}
echo ($sum == $num) ? "$num is an Armstrong Number" : "$num is Not an Armstrong Number";
?>