<?php
$arr = [1, 2, 2, 3, 4, 4, 5, 1];
$unique = array_unique($arr);
echo "Array without duplicates: " . implode(", ", $unique);
?>