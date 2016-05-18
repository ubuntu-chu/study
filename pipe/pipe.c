#if 0
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fds[2];
	if (pipe(fds) == -1) {
		perror("pipe error");
		exit(EXIT_FAILURE);

	}
	int ret;
	int count = 0;
	while (1) {
		ret = write(fds[1], "A", 1);	//fds[1]默认是阻塞模式
		if (ret == -1) {
			perror("write error");
			break;

		}
		count++;

		printf("count = %d\n", count);
	}

	return 0;

}

#else

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

void sighandler(int signo);
int main(void)
{
	int fds[2];
	if (signal(SIGPIPE, sighandler) == SIG_ERR) {
		perror("signal error");
		exit(EXIT_FAILURE);

	}
	if (pipe(fds) == -1) {
		perror("pipe error");
		exit(EXIT_FAILURE);

	}
	pid_t pid;
	pid = fork();
	if (pid == -1) {
		perror("fork error");
		exit(EXIT_FAILURE);

	}
	if (pid == 0) {
		close(fds[0]);			//子进程关闭读端
		exit(EXIT_SUCCESS);

	}

	close(fds[0]);				//父进程关闭读端
	sleep(1);					//确保子进程也将读端关闭
	int ret;
	ret = write(fds[1], "hello", 5);
	if (ret == -1) {
		printf("write error\n");

	}
	return 0;

}

void sighandler(int signo)
{
	printf("catch a SIGPIPE signal and signum = %d\n", signo);

}
#endif
