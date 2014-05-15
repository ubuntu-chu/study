#!/bin/sh 

CUR_PATH=$(pwd)
CTAGS_CSCOPE_PATH="./.ctags_cscope"
USR_INCLUDE_PATH="./.ctags_cscope/usr_include"
CTAGS_FLAG="--c++-kinds=+p --fields=+ialS --extra=+q"

echo "-----------------------------------------"
echo "-       cscope -- ctags  start          -"
echo "-                        Author:chuM    -"
echo "-----------------------------------------"

#找到所有的头文件 C文件 CPP文件 CC文件
find $CUR_PATH -name "*.h" -o -name "*.c" -o -name "*.cc" -o -name "*.cpp" > cscope.files 
if [ ! -d "$CTAGS_CSCOPE_PATH" ]; then
	mkdir "$CTAGS_CSCOPE_PATH"	
fi

cscope -bkq -i cscope.files 

if [ ! -f "$USR_INCLUDE_PATH/tags" ]; then
echo "-       ctags-->/usr/include            -"
	#产生TAGS文件
	ctags -R  $CTAGS_FLAG /usr/include
	if [ ! -d "$USR_INCLUDE_PATH" ]; then
		mkdir -p $USR_INCLUDE_PATH
	fi
	mv tags $USR_INCLUDE_PATH
fi

#-L好像有问题  应该是cscope.file的格式与ctags要求格式不同所引起的
#ctags -R --exclude .git --exclude .gitignore --exclude $CTAGS_CSCOPE_PATH $CTAGS_FLAG -f cscope.files
ctags -R --exclude bin --exclude *.o --exclude .git --exclude .gitignore --exclude $CTAGS_CSCOPE_PATH $CTAGS_FLAG .

mv cscope.* tags $CTAGS_CSCOPE_PATH

echo "-----------------------------------------"
echo "-       cscope -- ctags  done           -"
echo "-----------------------------------------"
