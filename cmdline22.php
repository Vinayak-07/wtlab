<?php
$principal = readline("Enter principal amount: ");
$rate = readline("Enter rate of interest: ");
$time = readline("Enter time (years): ");
$simpleInterest = ($principal * $rate * $time) / 100;
echo "Simple Interest = " . $simpleInterest;
?>