#!/usr/bin/python
# -*- coding: utf-8 -*-

import socket
from time import ctime

'''
hostΪ�ձ�ʾbind���԰󶨵�������Ч��ַ��
port ����Ҫ����1024
bufsizΪ������ ��������Ϊ1K
'''
host = ''  
port = 23456
bufsiz = 1024
ADDR = (host,port)

udpSerSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udpSerSock.bind(ADDR)

try:
    while True:
        print 'waiting for connection...'
        data,addr = udpSerSock.recvfrom(bufsiz)
        print '[%s] %s' %(ctime(),data)
        udpSerSock.sendto('[%s] %s' %(ctime(),data),addr)
        if data == 'exit':
            break
        print '...received from and returned to:',addr,'msg: ''[%s] %s' %(ctime(),data)
except BaseException, e:
    print e
    udpSerSock.close()