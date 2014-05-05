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

if ! [ $# -eq 3 ]
then
	help 0
fi

if [ $1 -lt "0" -o $1 -gt "23" ]
then
	help 1
fi

if [ $2 -lt "0" -o $2 -gt "59" ]
then
	help 2
fi

if [ $3 -lt "0" -o $3 -gt "59" ]
then
	help 3
fi

DEBUG="0"
LOG="1"

if [ ${DEBUG} = "1" ]
then
	echo "reboot time is(hour.min.sec):${1}.${2}.${3}"
fi

while true
do
	sleep 1
	HOUR=`date +%H`
	MIN=`date +%M`
	SEC=`date +%S`

	if [ ${DEBUG} = "1" ]
	then
		echo "HOUR = ${HOUR}"
		echo "MIN  = ${MIN}"
		echo "SEC  = ${SEC}"
	fi
	#everyday fix hour.min.sec will reboot
	if [ ${HOUR} -eq ${1} -a ${MIN} -eq ${2} -a ${SEC} -eq ${3} ] 
	then 
		if [ ${LOG} = "1" ]
		then
			echo "`date`:system auto reboot" >> /home/reboot.log
		fi
		reboot
	fi
done


