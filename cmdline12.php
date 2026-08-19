<?php
$num = readline("Enter a number: ");
$temp = $num;
$reversed = 0;
while ($temp != 0) {
    $reversed = $reversed * 10 + ($temp % 10);
    $temp = (int)($temp / 10);
}
echo ($num == $reversed) ? "$num is a Palindrome" : "$num is Not a Palindrome";
?>
