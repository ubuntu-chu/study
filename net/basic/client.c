//client.c
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>             
#include <unistd.h> 
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <netinet/in.h>

#define SER_PORT 9877   
#define WAIT_COUNT 5 
#define SER_IP "127.0.0.1" 

int main(int argc, char** argv)  
{  
    int send_sk;  
    struct sockaddr_in s_addr;  
    socklen_t len = sizeof(s_addr);  
    send_sk = socket(AF_INET, SOCK_STREAM, 0);  
    if(send_sk == -1)  
    {  
        perror("socket failed  ");  
        return -1;  
    }  
    bzero(&s_addr, sizeof(s_addr));  
    s_addr.sin_family = AF_INET;  

    inet_pton(AF_INET,SER_IP,&s_addr.sin_addr);  
    s_addr.sin_port = htons(SER_PORT);  
    if(connect(send_sk,(struct sockaddr*)&s_addr,len) == -1)  
    {  
        perror("connect fail  ");  
        return -1;  
    }  
    char pcContent[5000]={0};
	int rt;
	/*
    char pcContent[5000]={0};
    write(send_sk,pcContent,5000);
    sleep(1);
    write(send_sk,pcContent,5000);
    sleep(1);
    write(send_sk,pcContent,5000);
    sleep(1);
    write(send_sk,pcContent,5000);
    sleep(1);
    write(send_sk,pcContent,5000);
    sleep(1);
    write(send_sk,pcContent,5000);
    sleep(1);
	*/
	if ((rt = read(send_sk,pcContent,4000)) <= 0){
		printf("rt = %d\n", rt);
		perror("read");
	}
	/*
	for (rt = 0; rt < 4096; rt++){
		printf("pcContent[%d] = %d\n", rt, pcContent[rt]);
	}
	*/

	if ((rt = read(send_sk,pcContent,96)) <= 0){
		printf("rt = %d\n", rt);
		perror("read");
	}
	for (rt = 0; rt < 96; rt++){
		printf("pcContent[%d] = %d\n", rt, pcContent[rt]);
	}

   // sleep(1000);
    close(send_sk);
}
