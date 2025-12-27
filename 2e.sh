#!/bin/bash

read -p "Enter Integer : " num
if [ "$num" -lt 1 ]; then
	echo "Invalid input"
	exit 1
fi
sqrt=$(echo "scale=2; sqrt($num)" | bc)
hex=$(echo "obase=16; $num" | bc)
echo "Square root is $sqrt , hexa-decimal is $hex"
