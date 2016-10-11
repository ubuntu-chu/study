#!/bin/sh

LINK_SRC_DIR=`pwd`/proc
LINK_DEST_DIR=`pwd`/etc

file_list=`ls "$LINK_SRC_DIR"`
echo $file_list

[ ! -d $LINK_DEST_DIR ] && mkdir -p $LINK_DEST_DIR

for file in $file_list; do
	if [ ! -e $LINK_DEST_DIR/$file ]; then
		echo "ln -sf $LINK_SRC_DIR/$file $LINK_DEST_DIR/$file"
		ln -sf $LINK_SRC_DIR/$file $LINK_DEST_DIR/$file	
	fi
done

#while true;
#do
#	sleep 1
#	echo "hh"
#done





