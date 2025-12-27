#!/bin/bash

read -p "Enter The Number : " num
if [ $num -lt 0 ];
then echo "Neg no. not allowed"
       	exit 1
fi
sum=0
while [ "$num" -ne 0 ]
do
	rem=$((num%10))
	sum=$((sum + rem))
	num=$((num/10))
done

echo "Total Sum $((sum))"
