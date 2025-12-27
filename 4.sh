
#!/bin/bash
if [ $# -lt 1 ];then
	echo "Error: No input file given!!  Please give students.dat as input. "
	exit 1
fi

input="$1"

if [ ! -f"$input" ];then
	echo "Error:File '$input' not found!"
	exit 1
fi

echo "Menu:"
    echo "1) Sort the details accordoing to Roll no."
    echo "2) Replace lower case letters with the upper case letters in sorted.dat"
    echo "3) Append unique names from sorted.dat to students.dat"
    echo "4) Display only the 2nd and 3rd lines from the above file (students.dat)."
    echo "5) Exiting..."
while true; do
    
    read -p "Please select an option from above menu(1-5): " option

    case $option in
        1)
            sort -t '|' -k2nr  "$input" > sorted.dat
      		cat sorted.dat
      		;;
   
       	2)
       		out=$( cat sorted.dat | tr [:lower:] [:upper:])
       		echo "$out" > sorted.dat
       		cat sorted.dat
       		;;
       	3)	
       		cut -d '|' -f1 sorted.dat | sort | uniq -u  | while read name
			do
				grep "^$name|" sorted.dat >> "$input"
			done
			cat students.dat
		;;
       		
       	4)
       		out=$(cat "$input" |head -3 | tail -2)
       		echo "$out"
       		;;
       5)	
       		echo "Exiting..."
            	exit 0
            ;;	
        *)
            echo "Invalid option. Please try again."
            ;;
    esac
    echo ""
done
