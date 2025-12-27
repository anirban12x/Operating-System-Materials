#!/bin/bash

while true
do
	echo "Menu - 1. Enter Details , 2. Display Details , 3. Exit"

	read -p "Enter Choice : " choice

case $choice in
	1) echo "File - personal.dat"
		echo "Enter pass : "
		stty -echo
		read pass1
		pass=$(echo "$pass1")
		stty echo
		echo "$pass" > personal.dat
		read -p "Enter ur name : " name
		echo "$name" >> personal.dat
		echo "Done"
		;;
	2) stty -echo
		read -p "Enter password : " input1
		input=$(echo "$input1")
		stty echo
		check=$(cat personal.dat | head -1)
			if [ "$input" == "$check" ]; then
				out=$(cat personal.dat | tail -n +2)
				echo ""
				echo "$out"
			else echo "Wrong pass"
			fi
		;;
	3) exit 1 ;;
	*) echo "Invalid option";;
esac
done

