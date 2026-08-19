<?php
$str = "PHP Program";
$reversed = "";
for ($i = strlen($str) - 1; $i >= 0; $i--) {
    $reversed .= $str[$i];
}
echo "Reversed String = " . $reversed;
?>