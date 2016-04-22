#!/bin/bash

a=2
b=3

#if [ $a -eq 1 ] && [ $b -eq 2 ]; then
if [ $a -eq 1 ] || [ $b -eq 2 ]; then
	echo "ok"
else
	echo "--------"
fi


