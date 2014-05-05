#!/bin/bash
function ergodic(){
for file in ` ls $1 `
do
	if [ -d $1"/"$file ]
	then
		ergodic $1"/"$file
	else
		echo "filename: $1"/"$file"
		#wc -L $1"/"$file | cut -d' ' -f1 
		#wc -L $1"/"$file | cut -d' ' -f1 >> /home/chenguolin/out
	fi
done
}

INIT_PATH="/home/barnard/test"
ergodic $INIT_PATH


