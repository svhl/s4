#!/bin/bash

# finding factorial of a number

i=1
f=1
echo "Enter a number:"
read n

while [ $i -le $n ]; do
	((f*=i))
	((i++))
done

echo -e "Factorial:\n$f"
