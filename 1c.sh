#!/bin/bash

read -p "Enter the Year : " year
if [ $((year%100)) -eq 0 ];
then if [ $((year%400)) -eq 0 ];
then echo "Given Year is a Leap Year"
else echo "Not a Leap Year"
fi
else
cal=$((year%4))
if [ $cal -eq 0 ];
	then echo "Given Year is a Leap Year"
	else echo "Not a Leap Year"
fi
fi
