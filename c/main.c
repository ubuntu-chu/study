#include <stdio.h>
#include <time.h>


void mymul(double *p)
{
    *p *= 2.0;
}

void mymul_float(float *p)
{
    *p *= 2.0;
}

const char *name = "hello world\n";

int main(int argc, char *argv[])
{
	//const char name[] = "hello world\n";
//	const char *name = "hello world\n";
    float f = 1.0;
	time_t now_time;

    mymul((double *) &f);
 //   mymul_float(&f);
    //printf("now f = %f\n", f);
    printf("now f = %f\n", f);
	printf("name = %1$s\n", name);

	now_time		= time(NULL);
	printf("utc sec = %ld; sizeof(time_t) = %d\n", now_time, sizeof(time_t));

    return 0;
}
