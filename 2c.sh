#!/bin/bash

read -p "Enter Username : " uname
found=$(grep "^$uname:" /etc/passwd)

if [ -z $found ];then
	echo "No record found!"
else
	echo "Found $uname"
fi
