#!/bin/sh
#
#everyday fix hour.min.sec system will reboot

help(){
	case $1 in
		1) echo "hour:param range error!\n"
			;;
		2) echo "min :param range error!\n"
			;;
		3) echo "sec :param range error!\n"
			;;
		0) echo "param cnt error\n"
			;;
		*) echo "unknown error!"
			;;
	esac
	
	echo "Usage     : $0 <hour> <min> <sec>"
	echo "Param     : hour:0-23  "
	echo "            min :0-59  "
	echo "            sec :0-59  "
	exit 1
}

while true
do
	sleep 1
	HOUR=`date +%H`
	MIN=`date +%M`
	SEC=`date +%S`

	#`date`|`cut -d" " -f3` > HOUR
	date|cut -d" " -f3 > $HOUR

	echo ${HOUR}

done


