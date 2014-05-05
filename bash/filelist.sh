#!/bin/bash 

echo "general file list files: $#" 

echo "General by: $0" 

echo "Param1: $1" > filelist.txt 
echo "Param2: $2" >> filelist.txt 

echo "All param: $*" >> filelist.txt 
echo "All param: $@" >> filelist.txt 

echo "Flag: $-" >> filelist.txt 
echo "Last PID: $!" >> filelist.txt 

echo "Last command: $_" 
echo "Is normal: $?" 
echo "Current PID: $$" 

while [ $# -ne 0 ]
do
	echo "arg: $1"
	shift
done
