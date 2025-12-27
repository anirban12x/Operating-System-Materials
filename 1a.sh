#!/bin/bash

read -p "Enter First Number : " a
read -p "Enter Second Number : " b

echo "1. Addition of 2 numbers
2. Subtraction of 2 numbers
3. Multiplication of 2 numbers
4. Division of 2 numbers
5. Modulo of 2 numbers
6. Exit"
while (true)
do
read -p "Enter Choice : " choice

case $choice in
	1) echo "The Sum is : $(($a+$b))";;
	2) echo "The Subs is : $(($a-$b))";;
	3) echo "The Mul is : $(($a*$b))";;
	4) if [ $b -eq 0 ];
	then echo "Invalid Input"
	
	else echo"The Div is : $(($a/$b))"
		fi;;
	
	5) echo "The Mod is : $(($a%$b))";;
	6) echo "Exited"
		exit 1;;
	*) echo "Wrong Menu";;

esac
done
