#!/bin/bash

A80_REPOSITORY_TOP_DIR="/home/itl/work/A83T"
A83_REPOSITORY_TOP_DIR="/home/itl/work/A83T"

project_array=("hmt" "hmt_v3" "hevc" "hevc_v2" "cpe" "ist")

project=${project_array[1]}
platform_a83=A83
platform_a80=A80
platform=$platform_a83
sysconfig_project_dir=
project_num=

alias ca83='cd $A83_REPOSITORY_TOP_DIR/'

project_reassign()
{
	#case $project in
	#	$project_hmt)
	#		sysconfig_project_dir=hmt
	#		;;
	#	*)
	#		sysconfig_project_dir=$project
	#		;;
	#esac
	sysconfig_project_dir=$project
}

project_reassign

project_select()
{
	select value in ${project_array[*]}; do 
	if [ $value  ]; then 
		project=${value}
		echo "project = $project" 
		break   
	else 
		echo "Invaild selection" 
	fi 
	done 
	project_reassign

	if [ $platform = $platform_a83 ]; then
		repository_top_dir=$A80_REPOSITORY_TOP_DIR/$project
	else
		repository_top_dir=$A83_REPOSITORY_TOP_DIR/$project
	fi
}

do_change_dir()
{
	if [ $# -ne 1 ]; then
		return
	fi
	if [ -z $project ]; then
		echo "please run <project_select> select project first!"
		return
	fi
	cd $repository_top_dir/$1
}

clichee()
{
	do_change_dir lichee	
}

clinux()
{
	do_change_dir lichee/linux-3.4
}

cuboot()
{
	do_change_dir lichee/brandy/u-boot-2011.09
}

cbrandy()
{
	do_change_dir lichee/brandy/
}

cpack()
{
	do_change_dir lichee/tools/pack
}

candroid()
{
	do_change_dir android
}

csysconfig()
{
	do_change_dir lichee/tools/pack/chips/sun8iw6p1/configs/$sysconfig_project_dir
}

goto_android_top_path()
{
	#candroid
	now_path=`pwd`
	if [ $now_path != $repository_top_dir/android ]; then
		echo "invalid path: $now_path!  you path must be: $repository_top_dir/android"
		return 1
	fi

	return 0
}

#candroid
#check_is_android_top_path
#[ $? -ne 0 ] && return

cbuild_kernel()
{
	goto_android_top_path
	[ $? -ne 0 ] && return

	(cd ../lichee && ./build.sh)
}

cbuild_bootimage()
{
	goto_android_top_path
	[ $? -ne 0 ] && return

	extract-bsp && make bootimage -j16
}

cbuild_systemimage()
{
	goto_android_top_path
	[ $? -ne 0 ] && return

	extract-bsp && make systemimage -j16
}

cbuild_android()
{
	goto_android_top_path
	[ $? -ne 0 ] && return

	extract-bsp && make -j16
}

cbuild_installclean_android()
{
	goto_android_top_path
	[ $? -ne 0 ] && return

	extract-bsp && make installclean && make -j16
}

cbuild_pack()
{
	goto_android_top_path
	[ $? -ne 0 ] && return

	if [ $# -eq 1 ]; then
		if [ $1 = "-d" ]; then
			pack -d
		else
			echo "invalid param"
		fi
	else
		pack
	fi
}

cbuild_setupenv()
{
	goto_android_top_path
	[ $? -ne 0 ] && return

	. build/envsetup.sh
	project_num=`print_lunch_menu | grep hevc_v2 | cut -d '.' -f 1 | tr -d ' '`
	if [ $? -ne 0 ]; then
		echo "project [$project] is invalid! please check what happend!"
		return
	fi
	echo "project_num = $project_num"
	lunch $project_num
}


#alias apt-get='apt-get -o Acquire::http::proxy="http://192.168.1.126:3128/"'

