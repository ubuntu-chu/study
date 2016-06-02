#include <stdio.h>

struct p
{
	int a;
	char b;
	char c;
	//float d;

}__attribute__((aligned(32))) pp;

struct q
{
	int a;
	char b;
	char c;
	struct p qn;
	char d;

//}__attribute__((aligned(8))) qq;
}__attribute__((aligned(4))) qq;

/*************************************************************************
 * 1) 结构体变量的首地址能够被其最宽基本类型成员的大小所整除；
 * 2) 结构体每个成员相对于结构体首地址的偏移量（offset）都是成员大小的整数倍，如有需要编译器会在成员之间加上填充字节（internal adding）；
 * 3) 结构体的总大小为结构体最宽基本类型成员大小的整数倍，如有需要编译器会在最末一个成员之后加上填充字节（trailing padding）。
 *
 * 补充说明：
 *    结构体使用属性 aligned后， 则当aligned执行的对齐大小小于结构体内成员类型大小时， aligned指定的大小无效
 *    仅当aligned执行的对齐大小大于结构体内成员类型大小时, 此时结构体对齐必须满足如上三个条件， 只是此时结构体的首地址和总大小
 *    必须都为aligned指定大小的整数倍。结构体内部的成员类型依旧按照自己的自然大小进行对齐。
 *
 *    当此使用aligned指定对齐大小的结构体做为其他结构体的成员时： 此时务必注意如下几点：
 *    struct p是struct q的成员，在q内  p的首地址和总大小要按照其aligned指定的大小进行对齐 
 *    q内p为具有最大宽度的成员变量,因此q的首地址和总大小也必须为p的整数倍，要按照上述1，2，3点进行对齐和填充操作
 *
 * ***********************************************************************/

int main()
{
	printf("sizeof(int)=%d,sizeof(short)=%d.sizeof(char)=%d\n",sizeof(int),sizeof(short),sizeof(char));
	printf("pp=%d,qq=%d \n", sizeof(pp),sizeof(qq));
	printf("&pp.a=%p, &pp.b = %p, &pp.c = %p \n", &pp.a, &pp.b, &pp.c);
	printf("&qq.a=%p, &qq.b = %p, &qq.qn.a = %p, &qq.c = %p, &qq.d = %p\n", &qq.a, &qq.b, &qq.qn.a, &qq.c, &qq.d);

	return 0;

}
