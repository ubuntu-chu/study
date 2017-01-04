/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年12月20日 15时56分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream> 
#include <string> 
#include <unistd.h>
using namespace std; 

int bb(void)
{
	int i  = 0;
	while (1){
		if (1000 == i++){
			abort();
		}
		sleep(1);
	}
}

int aa(void)
{
	bb();
}

int   main(int   argc,char   *   argv[]) 
{ 
    string   strArr1[]={ "Trend ", "Micro ", "soft " }; 
    string   *p = new   string[2]; 
    p[0]= "US "; 
    p[1]= "CN "; 
    cout << sizeof(strArr1) << endl; 
    cout << "strArr1[0] = " << sizeof(strArr1[0]) << endl; 
    cout << sizeof(p) << endl; 
    cout << sizeof(string) << endl; 
    cout << "sizeof(string *) = " << sizeof(string *) << endl; 
    cout << "sizeof(p) = " << sizeof(p) << endl; 
    cout << "sizeof(*p) = " << sizeof(*p) << endl; 
    cout << "sizeof(p[2]) = " << sizeof(p[2]) << endl; 
    for(int   i=0;i <sizeof(strArr1)/sizeof(string);i++) 
    cout <<strArr1[i]; 
    for(int i=0;i <sizeof(*p)/sizeof(string);i++) 
		cout << p[i]; 
    cout << endl; 

	aa();
}

