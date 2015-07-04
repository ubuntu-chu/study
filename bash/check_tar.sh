#!/bin/sh 

echo $1 | grep "tar.gz$"  > /dev/null

echo "grep return $?"

echo $1

case "$1" in
	*tar.gz )
		echo "tar.gz"
		;;
	*tar.bz2 )
		echo "tar.bz2"
		;;
	*)
		echo "unkown style"
		;;
esac
		
