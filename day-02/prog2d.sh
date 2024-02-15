#!/bin/bash

# check whether a 3 digit number is armstrong number

i=0
s=0
echo "Enter a number:"
read n1
((n2=n1))

while [[ n2 -gt 0 ]]; do
	((d=n2%10))
	((s+=d**3))
	((n2/=10))
done

if [ $n1 == $s ]; then
	echo "Armstrong number"

else
	echo "Not armstrong number"
fi
