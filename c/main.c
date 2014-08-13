#include <stdio.h>


void mymul(double *p)
{
    *p *= 2.0;
}

void mymul_float(float *p)
{
    *p *= 2.0;
}

int main(int argc, char *argv[])
{
	char buf[100];
	
	unsigned char no = -1;

	const char *name = "hello world\n";
    float f = 1.0;
    mymul((double *) &f);

	snprintf(buf, sizeof(buf), "0x%2x", no); 
	printf(buf);
	printf("\n");
 //   mymul_float(&f);
    //printf("now f = %f\n", f);
    printf("now f = %f\n", f);
//	printf("name = %1$s", name);
    return 0;
}
