#!/bin/bash

# print even numbers from 1 to 100

i=2

while [ $i -le 100 ]; do
	echo "$i"
	((i+=2))
done
