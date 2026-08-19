<?php
$num = 12345;
$reversed = 0;
$temp = $num;
while ($temp != 0) {
    $digit = $temp % 10;
    $reversed = $reversed * 10 + $digit;
    $temp = (int)($temp / 10);
}
echo "Reversed Number = " . $reversed;
?>