#!/bin/bash

sum=0
for n in "$@"; do
if [ "$n" -lt 1 ]; then
 echo "Wrong input, enter natural no.s only"
exit 1
else
  sum=$((sum+n))
fi
done

echo "Sum of the given natural numbers $sum"
