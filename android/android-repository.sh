#!/bin/sh

branch_name=itl
gitserver=git@gitserver:/home/git/project/A83T
lichee_repository=lichee
lichee_sub_repository="brandy linux tools"

android_repository=android
android_sub_repository="external frameworks hardware device"

action_clone=clone
action_cmd=cmd
action_seturl=seturl

help(){
	echo "Usage						  : $0 <action> <param>"
	echo "Param action  : $action_clone|$action_cmd|$action_seturl"
	echo "Param param   : action=$action_clone, param=<repository_local_dir> <clone_branch>"
	echo "                action=$action_cmd, param=<cmd param>"
	exit 1
}

execute_cmd()
{
	echo "$@"
	$@
	if [ $? -ne 0  ];then
		echo "execute $@ failed! please check what happened!"
		exit 1
	fi                                                                                                                   
}

git_set_url()
{
	repository=$1
	echo ""
	execute_cmd cd $repository
	execute_cmd git remote set-url origin $gitserver/${2}.git

	for sub_repository in $3;
	do
		sub_repository_dir=$sub_repository
		if [ $sub_repository = "linux" ]; then
			sub_repository_dir=linux-3.4
		fi
		echo ""
		execute_cmd cd $repository/$sub_repository_dir
		execute_cmd git remote set-url origin $gitserver/$2/${sub_repository}.git 
		cd $repository
	done
}

git_clone_repository()
{
	repository=$1
	execute_cmd git clone -b $branch_name $gitserver/${repository}.git
	execute_cmd cd $repository

	for sub_repository in $2;
	do
		sub_repository_dir=$sub_repository
		if [ $sub_repository = "linux" ]; then
			sub_repository_dir=linux-3.4
		fi
		execute_cmd git clone -b $branch_name $gitserver/$repository/${sub_repository}.git $sub_repository_dir
	done
}

git_cmd_repository()
{
	repository=$1
	sub_repository_list=$2
	shift
	shift
	git_cmd=$*

	echo ""
	execute_cmd cd $repository
	execute_cmd $git_cmd

	for sub_repository in $sub_repository_list;
	do
		if [ $sub_repository = "linux" ]; then
			sub_repository=linux-3.4
		fi
		echo ""
		execute_cmd cd $repository/$sub_repository
		execute_cmd $git_cmd
		cd $repository
	done
}

do_action_clone()
{
	repository_local_dir=`pwd`/$1
	branch_name=$2
	echo "repository_local_dir = $repository_local_dir"
	echo "branch_name		   = $branch_name"
	if [ -d $repository_local_dir ]; then
		echo "$repository_local_dir exist, please remove it first and run $0 again!"
		exit 1
	fi

	execute_cmd rm -rf $repository_local_dir
	execute_cmd mkdir -p $repository_local_dir
	execute_cmd cd $repository_local_dir

	git_clone_repository $lichee_repository "$lichee_sub_repository"
	execute_cmd cd $repository_local_dir
	git_clone_repository $android_repository "$android_sub_repository"
}

do_action_cmd()
{
#判断当前的目录是否为版本库的顶级目录
	if [ -d $android_repository -a -d $lichee_repository ]; then
		repository_local_dir=`pwd`
		echo "repository_local_dir = $repository_local_dir"
		echo "git cmd = $*"
		git_cmd_repository $repository_local_dir/$lichee_repository "$lichee_sub_repository" $*
		execute_cmd cd $repository_local_dir
		git_cmd_repository $repository_local_dir/$android_repository "$android_sub_repository" $*
	else
		echo "`pwd` is not repository top dir"
		exit 3
	fi
}

do_action_set_url()
{
#判断当前的目录是否为版本库的顶级目录
	if [ -d $android_repository -a -d $lichee_repository ]; then
		repository_local_dir=`pwd`
		echo "repository_local_dir = $repository_local_dir"
		git_set_url $repository_local_dir/$lichee_repository $lichee_repository "$lichee_sub_repository" 
		execute_cmd cd $repository_local_dir
		git_set_url $repository_local_dir/$android_repository $android_repository "$android_sub_repository"
	else
		echo "`pwd` is not repository top dir"
		exit 3
	fi
}

if [ $# -eq 0 ]; then
	help
fi

case "$1" in
	$action_clone)
		if [ $# -ne 3 ]; then
			help
		fi
		do_action_clone $2 $3
		;;

	$action_cmd)
		if [ $# -eq 1 ]; then
			help
		fi
		shift
		do_action_cmd $*
		;;

	$action_seturl)
		if [ $# -ne 1 ]; then
			help
		fi
		do_action_set_url
		;;

	*)
		echo "$1 : invalid param! please check!"
		help
		;;
esac


