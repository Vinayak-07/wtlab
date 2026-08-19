<?php
$num = 98765;
$count = 0;
$temp = $num;
while ($temp != 0) {
    $count++;
    $temp = (int)($temp / 10);
}
echo "Number of Digits = " . $count;
?>