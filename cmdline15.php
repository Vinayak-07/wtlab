<?php
$num = readline("Enter a number: ");
$count = 0;
$temp = $num;
while ($temp != 0) {
    $count++;
    $temp = (int)($temp / 10);
}
echo "Number of Digits = " . $count;
?>