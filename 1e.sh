#!/bin/bash
echo "Fibbo from Term 0 "
read -p "Enter upto which term req : " num
if [ $num -lt 0 ];
then echo "Invalid Input from user"
	exit 1
fi
a=0
b=1
if [ $num -eq 0 ];
then echo "$((a))"

else
	echo "$((a))"
echo "$((b))"
for (( i=0 ; i<num-1 ; i++))
do
	c=$((a+b))
	a=$((b))
	b=$((c))
	echo "$((c))"
done
fi
