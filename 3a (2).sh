#!/bin/bash

while true; do
	echo "Menu: 1- Show permissions, 2- Show no. of files and dir , 3- Show mod date time, 4- Exit"
    
    read -p "Enter option : " option

    case $option in
        1)
            read -p "Enter the file or directory name: " name
            if [ -e "$name" ]; then
                ls -l "$name"  | cut -f1 -d ' ' | cut -c2- 
            else
                echo "does not exist."
            fi
            ;;
       2)
       		dirnum=$(ls -l | grep "^d" | wc -l)
       	    	Total=$(ls -l |  wc -l)
       	    	filenum=$((Total - num_dirs - 1))
       	    	echo "Number of files: $filenum"
            	echo "Number of directories: $dirnum"
            ;;
        3)
        	read -p "Enter the file name: " file
            	if [ -e "$file" ]; then
                	ls -l "$file"  | tr -s ' ' | cut  -f 6-8 -d ' '
            	else
                	echo "File does not exist."
            	fi
            ;;
        	
       4)
            	exit 0
            ;;
        *)
            echo "Invalid option"
            ;;
    esac
done
