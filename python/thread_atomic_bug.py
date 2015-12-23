#!/usr/bin/python
# -*- coding: utf-8 -*-

from threading import Thread,Lock
import time
lock = Lock()
 
class CreateListThread(Thread):
    def run(self):
        self.entries = []
        for i in range(10):
            time.sleep(0.01)
            self.entries.append(i)
        lock.acquire()
        #print 列表不是一个原子操作
        print self.entries
        lock.release()
  
def use_create_list_thread():
    for i in range(3):
        t = CreateListThread()
        t.start()
  
use_create_list_thread()


    