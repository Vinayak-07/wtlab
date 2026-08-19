<?php
$str = "Web Technology Lab";
$str = strtolower($str);
$count = 0;
for ($i = 0; $i < strlen($str); $i++) {
    if (strpos("aeiou", $str[$i]) !== false) {
        $count++;
    }
}
echo "Number of Vowels = " . $count;
?>