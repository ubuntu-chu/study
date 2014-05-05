#!/bin/bash 
# 
# 
SPATH="/home/barnard/test" 
DPATH="/web" 
 
# 函数开始部分
CYCLING(){ 
filelist=`ls -1 $SPATH` 

for filename in $filelist ; do  
	if [ -f $filename ] ; then  
		echo Filename:$filename 
		#/usr/bin/iconv -f GBK -t UTF-8  $SPATH/$filename -o  $DPATH/$filename 
		#cp -pv $SPATH/$filename  $DPATH/$filename 该句为前期便利效果测试
		#sed  -i  -e  's/gb2312/UTF-8/g'  -e 's/GB2312/UTF-8/g'  $DPATH/$filename 
	elif [ -d $filename ] ; then 
		DPATH=$DPATH/$filename 
#		mkdir -pv $DPATH 
		cd $filename 
		echo "dir:$filename"
		SPATH=`pwd` 
		echo "SPATH Prev = $SPATH"

		# Next for recurse 如果遇到目录进行自我调用。。。实现深层遍历
		CYCLING 

		# Next Usag: basename dirname 
		DPATH=`dirname $DPATH` 
		SPATH=`dirname $SPATH` 
		echo "SPATH Next = $SPATH"
		cd $SPATH 
	else 
		echo "File $SPATH/$filename is not a common file.Please check." 
	fi 
done 
} 

# 命令开始部分
cd $SPATH 
CYCLING 
echo "All Done." 
