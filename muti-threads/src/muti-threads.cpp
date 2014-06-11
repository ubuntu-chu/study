//============================================================================
// Name        : muti-threads.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include<iostream>
#include<pthread.h>
#include<print.h>

int dump(void)
{
	static int m = 0;

	return m++;
}

void* threadPrintHello(void* arg)
{
	volatile int a, b, c;

    while(1)
    {
    	a++;
    	b++;
    	c = a+b;
        sleep(5);
        print(string("threadPrintHello"));
        c = dump();
    }

    return NULL;
}

void* threadPrintWorld(void* arg)
{
	volatile int d, e, f;
    while(1)
    {
    	d++;
    	e++;
    	f = d+e;
        sleep(3);
        print(string("threadPrintWorld"));
        f = dump();
    }

    return NULL;
}

int main( int argc , char* argv[])
{
    pthread_t pid_hello , pid_world;

    int ret = 0;

    ret = pthread_create(&pid_hello , NULL , threadPrintHello , NULL);

    if( ret != 0 )
    {
        std::cout << "Create threadHello error" << std::endl;
        return -1;
    }

    ret = pthread_create(&pid_world , NULL , threadPrintWorld , NULL);

    if( ret != 0 )
    {
        std::cout << "Create threadWorld error" << std::endl;
        return -1;
    }

//    while(1)
    {
        sleep(10);
        std::cout << "In main thread"  << std::endl;
    }

    pthread_join(pid_hello , NULL);
    pthread_join(pid_world , NULL);

    return 0;
}
