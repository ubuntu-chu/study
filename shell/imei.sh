#!/bin/bash

imei_file=/data/.board/imei

[ -e $imei_file ] && exit 0 || touch $imei_file
chmod 777 $imei_file

serial=`getprop ro.serialno`
serial_str=0x`echo $serial | busybox cut -c 1-4,13-20`

serinal_no=`printf "%015d" $serial_str`
serinal_no=`echo ${serinal_no:1:15}`

echo serinal_no > $imei_file


