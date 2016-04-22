#!/usr/bin/python
#coding=utf-8
"""
#
# Authors: limanman
# OsChina: http://my.oschina.net/pydevops/
# Purpose:
#
"""

import sys 
import socket
import struct

version_server_addr = ("192.192.192.242", 30080) 
#version_server_addr = ("192.192.192.240", 30080) 
#version_server_addr = ("192.192.192.244", 30080) 
udpsock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 
version_packet = '''90 90'''

# 转换为二进制流
def struct_pack(hex_strs):
	"""Pack hex_strs to """

	all_strs = ''
	hex_strs = hex_strs.replace('\n', ' ')
	hex_list = hex_strs.split()

	for cur_item in hex_list:
		# 十六进制转换为10进制然后在组包二进制字符流
		all_strs += struct.pack('B', int(cur_item, 16))
	return all_strs


def main():
	"""Main function."""

	version_udp_packet = struct_pack(version_packet)
	# 组包解密
	print repr(version_udp_packet)

	while(1):  
		#udpsock.sendto("adf", version_server_addr)
		send_len = udpsock.sendto(version_udp_packet,version_server_addr)
		if (send_len):
			pass #UDP发送数据  
		print "send_len: ", send_len

		recv_data, server = udpsock.recvfrom(1024) 
		format = "!BBBB%ds" % (len(recv_data)-4)
		send_host,msg_id,len_low,len_high,data=struct.unpack(format,recv_data)
		data_len = len_low + len_high*256

		print "len_high: 0x%02x, len_low = 0x%02x" %(len_high, len_low)  
		print "recv_data: ", recv_data  
		print "data: ", data  
		print "send_host: 0x%02x, msg_id = 0x%02x, len=%d" %(send_host, msg_id, data_len)  
		print "server: ", server  

		udpsock.close()  
		break  

if __name__ == '__main__':
	main()


