#!/bin/bash

# reverse of a number

r=0
echo "Enter a number:"
read n

while [[ n -gt 0 ]]; do
	((d=n%10))
	((r=r*10+d))
	((n/=10))
done

echo -e "Reverse:\n$r"
