#!/bin/bash
#

DEBUG=1

debug(){
	[ $DEBUG = 1 ] && $@
}

#vlan 配置选择
VLAN_CONFIGURE=1

case $VLAN_CONFIGURE in
	1)
		#vlan定义  ()内的为bcm5396的端口号 从0开始索引  每个端口号之间用空格分开
		vlan1=(2 9 11)
		vlan2=(0 1 3 8 10 12)
		vlan3=(4 5 6 7 13 14 15)
		;;
	2)
		#3为一个独立的vlan  其他的划分到一起
		vlan1=(3)
		vlan2=(2 9 11 0 1 8 10 12)
		vlan3=(4 5 6 7 13 14 15)
		;;
	*)
		echo "invalid vlan configure!"
		exit 1
esac

#划分vlan
cd /opt/itl/bin

function vlan_add()
{
	eval len=\${#${1}[@]}
	debug echo ${1} len = $len

	#获取vlan值
	vlan_value=0
	for ((i=0; i<$len; i++))
	do
		eval port=\${${1}[${i}]}
		debug echo "port = ${port}"
		shift_value=$((1<<${port}))
		debug echo "shift_value = ${shift_value}"
		vlan_value=$(($vlan_value + ${shift_value}))
		debug echo "vlan_value = ${vlan_value}"

		debug printf "hex=0x%08x\n" ${vlan_value}
		#debug printf "vlan_value = 0x%08x\n" ${vlan_value}
		debug echo ""
	done

	#写入5396
	for ((i=0; i<$len; i++))
	do
		eval port=\${${1}[${i}]}
		debug echo "port = ${port}"
		#每个reg占4个字节
		reg=$((${port}<<2))
		debug echo "reg = ${reg}"
		debug printf "hex=0x%02x\n" ${reg}
		./bcm5396 0x11 $reg $vlan_value 4
		./bcm5396 0x10 $reg 4
	done
}


./bcm5396 0x11 0xff 0x1c 1
./bcm5396 0x10 0x28 1
#选择vlan寄存器
./bcm5396 0x11 0xff 0x31 1

vlan_add vlan1
vlan_add vlan2
vlan_add vlan3


