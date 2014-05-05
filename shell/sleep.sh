#!/bin/bash

function sum()
{
	SU=`expr $1 + $2`

	#`expr $1+$2`
	return "$SU"
}

RET=1
VA=2
VB=2

#while true
while :
do 
	sleep 1;
	`sum $VA $VB`
	echo $?
	RET=$?
	echo "the sum = ""${RET}"
	echo "------"
done

