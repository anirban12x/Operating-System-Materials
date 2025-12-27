#!/bin/bash

read -p "Enter Number : " num
fact=num
for ((i=num-1 ; i>0; i--))
do 
	fact=$((fact*i))
done

echo "Factorial of $num is $fact"
