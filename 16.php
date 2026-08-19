<?php
$char = 'e';
$char = strtolower($char);
if (strpos("aeiou", $char) !== false) {
    echo "$char is a Vowel";
} else {
    echo "$char is a Consonant";
}
?>