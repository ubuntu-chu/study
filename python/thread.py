#!/usr/bin/python
# -*- coding: utf-8 -*-

#import time  
#import thread  
#
#def timer(no, interval):  
#    cnt = 0  
#    while cnt<10:  
#        print 'Thread:(%d) Time:%s\n'%(no, time.ctime())  
#        time.sleep(interval)  
#        cnt+=1  
#    thread.exit_thread()  
#     
#   
#def test(): #Use thread.start_new_thread() to create 2 new threads  
#    thread.start_new_thread(timer, (1,1))  
#    thread.start_new_thread(timer, (2,2))  
#   
#if __name__=='__main__':  
#    test()  
    
import threading  
mylock = threading.RLock()  
num=0  
   
class myThread(threading.Thread):  
    def __init__(self, name):  
        threading.Thread.__init__(self)  
        self.t_name = name  
          
    def run(self):  
        global num  
        while True:  
            mylock.acquire()  
            mylock.acquire()  
            print '\nThread(%s) locked, Number: %d'%(self.t_name, num)  
            if num>=4:  
                mylock.release()  
                mylock.release() 
                print '\nThread(%s) released, Number: %d'%(self.t_name, num)  
                break  
            num+=1  
            print '\nThread(%s) released, Number: %d'%(self.t_name, num)  
            mylock.release()  
            mylock.release() 
              
def test():  
    thread1 = myThread('A')  
    thread2 = myThread('B')  
    thread1.start()  
    thread2.start()  
   
if __name__== '__main__':  
    test()  
    