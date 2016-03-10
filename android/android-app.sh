#!/bin/bash

image_path_prefix="/home/itl/work/A83T/"
image_path_suffix="lichee/tools/pack/"
image_dst_path="/home/mount/images"
image_test_path=$image_dst_path/history/dev_test
project_hevc_a83=hevc_a83
project_hevc_hi3516=hevc_hi3516
project_ist=ist

action_install="install"
action_test="test"
action_test_clr="test_clr"
action_list="list"

help(){
	echo "Usage						  : $0 <action> <project>"
	echo "Param action  : $action_install|$action_list|$action_test|$action_test_clr"
	echo "Param project : $project_hevc_a83|$project_hevc_hi3516|$project_ist"
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

if [ $# -ne 1 ] && [ $# -ne 2 ]; then
	help
fi

case "$1" in
	$action_install|$action_test|$action_test_clr)
		;;

	$action_list)
		which tree
		if [ $? -eq 0 ]; then
			tree $image_dst_path
		else
			ll -R $image_dst_path
		fi
		exit
		;;

	*)
		help
		break;
esac

do_image_install()
{
	image_install_path=$2/$project_name/$app_package_dest_path
	if [ ! -d $image_install_path ]; then
		execute_cmd mkdir -p /$image_install_path
	fi

	execute_cmd cd $image_path_prefix/$app_package_path
	execute_cmd cp *.tar.gz $image_install_path/
}

do_image_clear()
{
	image_install_path=$2/$project_name/$app_package_dest_path
	[ ! -d $image_install_path ] && execute_cmd mkdir -p $image_install_path
	execute_cmd rm -rf /$image_install_path/*
}

app_package_path_get()
{
	case "$1" in
		$project_hevc_a83)
			app_package_path=app_hevc/hevc/A83T
			project_name=hevc_v2
			app_package_dest_path=A83T/app
			;;
		
		$project_hevc_hi3516)
			app_package_path=app_hevc/hevc/Hi3516
			project_name=hevc_v2
			app_package_dest_path=hi3516/app
			;;

		$project_ist)
			app_package_path=app_ist/ue_part
			project_name=ist
			app_package_dest_path=A83T/app
			;;

		*)
			help
			;;
	esac
}

case "$2" in
	$project_hevc_a83 | $project_hevc_hi3516 | $project_ist)
		app_package_path_get $2

		case "$1" in
			$action_install)
				do_image_install $project_name $image_dst_path
				;;	

			$action_test)
				do_image_install $project_name $image_test_path
				;;

			$action_test_clr)
				do_image_clear $project_name $image_test_path
				;;

			*)
				help
				break;
		esac
		;;

	*)
		echo "$2 : invalid param! please check!"
		help
		;;
esac


