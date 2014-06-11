#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <linux/unistd.h>

namespace {
    __thread int x = 0;
}

void print(const char *hint)
{
    printf("%s pid=%d tid=%d x=%d\n", hint, getpid(), ::syscall(SYS_gettid),
	   x);
}
int main() {
    printf("parent %d\n", getpid());
    print("parent");
    x = 1;
    print("parent");
    pid_t p = fork();

    if (p == 0) {
	printf("chlid %d\n", getpid());
	// child
	print("chlid");
	x = 2;
	print("chlid");

	if (fork() == 0) {
	    printf("grandchlid %d\n", getpid());
	    print("grandchild");
	    x = 3;
	    print("grandchild");
	}
    } else {
	// parent
	print("parent");
    }
}
