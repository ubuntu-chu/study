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
	char buf[100];
	
	unsigned char no = -1;

	const char *name = "hello world\n";
	//const char name[] = "hello world\n";
//	const char *name = "hello world\n";
    float f = 1.0;
	time_t now_time;

    mymul((double *) &f);

	snprintf(buf, sizeof(buf), "0x%2x", no); 
	printf(buf);
	printf("\n");
 //   mymul_float(&f);
    //printf("now f = %f\n", f);
    printf("now f = %f\n", f);
//	printf("name = %1$s", name);
	printf("name = %1$s\n", name);

	now_time		= time(NULL);
	printf("utc sec = %ld; sizeof(time_t) = %d\n", now_time, sizeof(time_t));

>>>>>>> 37aa81bfea57e066059c07c7d8a84f4d9ce0f2c0
    return 0;
}
