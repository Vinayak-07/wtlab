<?php
$arr = [5, 8, 12, 19, 25];
$target = 19;
$found = -1;
for ($i = 0; $i < count($arr); $i++) {
    if ($arr[$i] == $target) {
        $found = $i;
        break;
    }
}
echo ($found != -1) ? "Element found at index $found" : "Element not found";
?>