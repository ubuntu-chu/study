#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd;
	char buf[32];
	struct stat buff;

	if ((fd = open("temp.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) < 0) {
		printf("create file error!\n");

	}
#if 0
	//此时因为 temp.txt只有一个硬链接 但此时已经有一个进程打开它  所以unlink会将temp.txt从磁盘上删除
	//但是因为前面有对此文件的open操作  所以内核仍然可以使用这个文件  直到最后一个引用计数被close掉
	if (unlink("temp.txt") < 0) {
		printf("unlink error !\n");

	}
	//此时access会返回失败
	if (access("temp.txt", F_OK)){
		perror("temp.txt is removed");
		return 1;	
	}
#endif
	stat("temp.txt", &buff);
	printf("temp.link=%d\n", buff.st_nlink);
	//建立硬链接    ll  可以看出文件的硬链接个数为2
	if (link("temp.txt", "test.txt")){
		perror("link error!");
	}
	stat("test.txt", &buff);
	printf("after link the test.link =%d\n", buff.st_nlink);
	stat("temp.txt", &buff);

	printf("after link the temp.link =%d\n", buff.st_nlink);
	//sleep(10);
	//删除此硬链接  硬链接个数减1
	if (unlink("test.txt") < 0) {
		printf("unlink error !\n");

	}
	//sleep(10);
	//此时 test.txt文件已经不存在
	if (0 == access("test.txt", F_OK)){
		stat("test.txt", &buff);
		printf("after unlink test.link=%d\n", buff.st_nlink);
	}
	stat("temp.txt", &buff);
	printf("after sdfsdfunlink temp.link=%d\n", buff.st_nlink);
	//因为前面已经open此文件， 所以此时可以对此文件进行操作
	if (write(fd, "temp", 5) < 0) {
		printf("write wrror!\n");

	}
	if ((lseek(fd, 0, SEEK_SET)) == -1) {
		printf("lseek error!\n");

	}
	if ((read(fd, buf, 5)) < 0) {
		printf("read error!\n");

	}
	printf("%s\n", buf);
	return 0;

}
