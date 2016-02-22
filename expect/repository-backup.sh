#!/bin/bash

repository_dir_src=/home/git/project
repository_dir_dst_path=/opt/repository_backup
repository_dir_dst_file=project_git_backup_`date +"%Y%m%d"`.tar.gz
repository_dir_dst=$repository_dir_dst_path/$repository_dir_dst_file

execute_cmd()
{
	echo "$@"
	$@
	if [ $? -ne 0  ];then
		echo "execute $@ failed! please check what happened!"
		exit 1
	fi                                                                                                                   
}

if [ -d $repository_dir_dst ]; then
	echo "$repository_dir_dst exist! donot need to backup today!"
	exit 0
fi

#execute_cmd cp -r -v $repository_dir_src $repository_dir_dst
execute_cmd pushd $repository_dir_src
execute_cmd tar zcvf $repository_dir_dst *
execute_cmd popd $repository_dir_src

execute_cmd /usr/sbin/scp.exp itl-bsp chum chumojing $repository_dir_dst '~/work/gitserver_back'

exit 0


