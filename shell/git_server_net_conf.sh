#!/bin/sh

sudo ifconfig eth1 192.168.120.3 netmask 255.255.255.0
sudo ifconfig eth1:0 192.168.1.128 netmask 255.255.255.0
sudo route add default gw 192.168.120.1
#sudo route add gw 192.168.1.1
#sudo echo "nameserver 218.2.135.1" >> /etc/resolv.conf
