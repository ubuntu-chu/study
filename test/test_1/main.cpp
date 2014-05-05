#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int i	= 3;
	int a	= 0;
	int b	= 9999;

	while (b){
		a++;
		cout << "a = " << a << endl;
		cout << "before b = "<< b<<endl;
		printf("before b = %x\n", b);
		b	= b & (b-1);
		cout << "after b = "<< b<<endl;
		printf("after b = %x\n", b);
	}

	cout << "result = " << (++i)*(++i) << endl;
	cout << "i = " << i << endl;
	cout << "a = " << a << endl;

	return 0;
}
