#include<time.h>
#include<stdlib.h>
main()
{
	int i,j;

	//srand((int)time(0));
	srand(100);
	for(i=0;i<10;i++)
	{
		j=1+(int)(10.0*rand()/(RAND_MAX+1.0));
		srand(j);
		printf(" %d ",j);

	}

}

