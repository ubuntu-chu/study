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
	unsigned char a = 0, b =250, c = 0, len = 128;
	unsigned char d=0, m = 5;

	//unsigned char aa=0, bb=255, cc=0;
	unsigned char aa=0, bb=1, cc=0;
	unsigned int aaa=1, bbb=-2, ccc=0;





	const char *name = "hello world";
	//const char name[] = "hello world\n";
//	const char *name = "hello world\n";
    float f = 1.0;
	time_t now_time;

	cc = aa-bb;
	printf("cc = %d\n", cc);

	ccc = aaa-bbb;
	printf("ccc = %d\n", ccc);
	//printf("name = %s\n", name);
	printf("name = %1$s", name, 2);
	c = a - b;
	d = a - m;
	//结论: 运算时均使用有符号数， 如果将负数赋值给unsigned char型变量， 则unsigned char型变量存放的是补码
	printf("a = 0x%x, b = 0x%x, c = %d 0x%x, d = %d 0x%x\n", a, b, c, c, d, d);
	printf("%d > %d = %s\n", c, len, (c > len)?("true"):"false");
	printf("%d > %d = %s\n", d, len, (d > len)?("true"):"false");

    mymul((double *) &f);

	snprintf(buf, sizeof(buf), "0x%2x", no); 
	printf(buf);
	printf("\n");
   //mymul_float(&f);
   mymul(&f);
    //printf("now f = %f\n", f);
    printf("now f = %f\n", f);

	now_time		= time(NULL);
	printf("utc sec = %ld; sizeof(time_t) = %d\n", now_time, sizeof(time_t));

    return 0;
}
