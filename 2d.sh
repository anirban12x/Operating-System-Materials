#!/bin/bash

if [ $# -lt 1 ]; then
	echo "No input"
	exit 1
fi
n=${1}
if [ "$n" -lt 1 ]; then
 echo "Wrong input"
	exit 1
fi
res=$(echo "scale=2; l($n)/l(10)" | bc -l)
echo "Common log is : $res"
