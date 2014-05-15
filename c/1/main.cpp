#include <stdio.h>

int main(int argc,char *argv[])
{
	int e = 9, c=9,d=0;
	e=e++%5;
	printf("e=%d\n",e);
	c=++c%5;
	d=c;

	e = (++d)++;
//	c = (d++)++;
	printf("d=%d\n",d);
	d=e;
	printf("d=%d\n",d);
	d = 10*(e++);
	//d = 10*++e;
	printf("d=%d\n",d);
	return 0;
}
