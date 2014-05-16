//server.c
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

#define SERV_PORT 9877   
#define SER_IP "127.0.0.1" 
#define WAIT_COUNT 5 


int main(int argc, char** argv)  
{  
    int listen_fd, real_fd;  
    struct sockaddr_in listen_addr, client_addr;  
    socklen_t len = sizeof(struct sockaddr_in);  
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);  
    if(listen_fd == -1)  
    {  
        perror("socket failed   ");  
        return -1;  
    }  
    bzero(&listen_addr,sizeof(listen_addr));  
    listen_addr.sin_family = AF_INET;  
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);  
    listen_addr.sin_port = htons(SERV_PORT);  
    bind(listen_fd,(struct sockaddr *)&listen_addr, len);  
    listen(listen_fd, WAIT_COUNT);  
    while(1)  
    {  
        real_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &len);  
        if(real_fd == -1)  
        {  
            perror("accpet fail  ");  
            return -1;  
        }  
        if(fork() == 0)  
        {  
			int rt;
			int m = 1;
            close(listen_fd);  
            char pcContent[4096];
			for (rt = 4001; rt < 4096; rt++){
				pcContent[rt]    = m++;
			}
#if 0
            if ((rt = write(real_fd,pcContent,4096)) <= 0){
				printf("rt = %d\n", rt);
				perror("write");
			}
				printf("write rt = %d\n", rt);
#endif
			printf("prepare to read\n");
		while (1){
            rt = read(real_fd,pcContent,4096); 
			printf("read rt = %d\n", rt);
            if (rt == 0){
				printf("client normal exit\n");
				perror("read");
				sleep(2);
				rt = write(real_fd,pcContent,4096); 
				printf("write rt = %d\n", rt);
				if (rt < 0){
					perror("write");
				}
				break;
			}else if (rt < 0){
				printf("client abnormal exit\n");
				perror("read");
				break;
			}
		}
		sleep(10);
            close(real_fd);  

			printf("child process quit\n");
            exit(0);              
        }  
        close(real_fd);  
    }     
    return 0;  
}

