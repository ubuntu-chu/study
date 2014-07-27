#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

namespace
{
__thread int x = 0;
}

void print(const char *str)
{
  printf("pid=%d msg=%s x=%d\n", getpid(), str, x);
}

int main()
{
  printf("parent %d\n", getpid());
  print("parent");
  x = 1;
  print("parent");
  pid_t p = fork();

  if (p == 0)
  {
    printf("chlid %d\n", getpid());
    // child
    print("child");
    x = 2;
    print("child");

    if (fork() == 0)
    {
      printf("grandchlid %d\n", getpid());
      print("grandchild");
      x = 3;
      print("grandchild");
    }
  }
  else
  {
    // parent
    print("parent");
  }
}
