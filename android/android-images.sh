#!/bin/sh

image_path_prefix="/home/itl/work/A83T/"
image_path_suffix="lichee/tools/pack/"
image_dst_path="/home/mount/images"
image_test_path=$image_dst_path/history/dev_test
project_hmt=hmt
project_hmt_v3=hmt_v3
project_hevc=hevc
project_hevc_v2=hevc_v2
project_cpe=cpe
project_ist=ist

action_install="install"
action_test="test"
action_test_clr="test_clr"
action_list="list"

help(){
	echo "Usage						  : $0 <action> <project>"
	echo "Param action  : $action_install|$action_list|$action_test|$action_test_clr"
	echo "Param project : $project_ist|$project_hmt|$project_hmt_v3|$project_hevc|$project_hevc_v2|$project_cpe"
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
	project_name=$1
	image_install_path=$2/$project_name/A83T/firmware
	if [ ! -d $image_install_path ]; then
		execute_cmd mkdir -p /$image_install_path
	fi

	execute_cmd cd $image_path_prefix/$project_name/$image_path_suffix/
	image_list="sun8iw6p1_android_${project_name}_card0.img sun8iw6p1_android_${project_name}_uart0.img"
	for image_name in $image_list; do
		if [ -r ${image_name} ]; then
			install_image_name=`echo ${image_name} | cut -d '.' -f 1`
			install_image_name_suffiex=`echo ${image_name} | cut -d '.' -f 2`
			image_date=`stat ${image_name} | grep "最近更改"| sed -n "s/最近更改：\(.*\) \(.*\) \(.*\)/\1_\2/p"|tr -d '-'|tr -d ':' | cut -d '.' -f 1`
			execute_cmd cp ${image_name} $image_install_path/${install_image_name}_${image_date}.${install_image_name_suffiex}


			#execute_cmd cp ${image_name} $image_install_path/${install_image_name}_`date +"%Y%m%d_%H%M%S"`.${install_image_name_suffiex}
		fi
	done

	#find ./ -iregex ".*sun8iw6p1_android_hmt_\(card0\|uart0\)\.img$" -print0 | xargs -0 -I {} cp {} /home/mount/Images-Android/hmt/
}

do_image_clear()
{
	project_name=$1
	image_install_path=$2/$project_name/A83T/firmware
	[ ! -d $image_install_path ] && execute_cmd mkdir -p /$image_install_path
	execute_cmd rm -rf /$image_install_path/*
}

case "$2" in
	$project_hmt | $project_hmt_v3 | $project_hevc | $project_hevc_v2 | $project_cpe | $project_ist)
		case "$1" in
			$action_install)
				do_image_install $2 $image_dst_path
				;;	

			$action_test)
				do_image_install $2 $image_test_path
				;;

			$action_test_clr)
				do_image_clear $2 $image_test_path
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


