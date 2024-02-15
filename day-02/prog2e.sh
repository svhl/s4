#!/bin/bash

# check whether a number is prime number

i=2
c=0
echo "Enter a number:"
read n

if [ $n == 1 ] || [ $n == 0 ]; then
	echo "Neither prime nor composite"
	
elif [ $n -lt 0 ]; then
	echo "Negative number"

else
	while [ $i -lt $n ]; do
		if [ $((n%i)) == 0 ]; then
			((c++))
		fi
		
		((i++))
	done
	
	if [ $c == 0 ]; then
		echo "Prime number"
	
	else
		echo "Composite number"
	fi
fi
