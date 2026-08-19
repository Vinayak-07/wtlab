<?php
$arr = [12, 45, 3, 67, 22, 9];
$max = $arr[0];
foreach ($arr as $val) {
    if ($val > $max) {
        $max = $val;
    }
}
echo "Maximum Value = " . $max;
?>