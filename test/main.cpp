#include <iostream>
#include <stdio.h>

using namespace std;
class A
{
public:
//	A(int b):a(b){};
	A(){};
	void virtual f() { cout<<"A"<<endl;}
	void foo(){cout << "A::foo" << endl;}
	void foo1(){cout << "A::foo1" << endl;}
	//const int a;
	//static const int c = 4545;
	//static int d;
};
class B:public A
{
public:
//	B(int b):A(b){};
	B(){};
	void virtual f() { cout<<"B"<<endl;}
	void foo(){cout << "B::foo" << endl;}
	void foo1(int a){cout << "B::foo1_int a = " << a << endl;}
};
//int A::d;
int main()
{
#if 0
	A *pa = new B(34);
	B *pb = dynamic_cast<B *>(pa);
	B *pc = static_cast<B *>(pa);
	cout << "pa = " << pa << endl;
	if (NULL == pb){
		cout << "fuck" << endl;
		cout << "pb = " <<pb << endl;
	}
	pb->foo1(34);
	if (NULL == pc){
		cout << "fuck" << endl;
	}
		cout << "pc = " <<pc << endl;
	pc->foo1(34);
#endif
#if 1
	A *pa = new B;
	B *pb = (B*)pa;
	B bclas;
	pa->f();
	pa->foo();
	pa->foo1();
	pb->foo();
//	pb->foo1();
//	bclass.foo1();
	//pa->foo1(1);
//	cout << "c = " << pa->c<< endl;
//	cout << "d = " << pa->d<< endl;
#endif
#if 0
	A *pa=new A;
	pa->f();
	B *pb=(B*)pa;
	//B *pb=new B;
	pb->f();
	cout << "pa == " << pa << endl;
	cout << "pb == " << pb << endl;
	delete pa,pb;
	cout << "pa == " << pa << endl;
	cout << "pb == " << pb << endl;
	pa=new B;
	pa->f();
	cout << "pa == " << pa << endl;
	cout << "pb == " << pb << endl;
	pb=(B*)pb;
	pb->f();

	pa->foo();                 //调用的是A::foo
	pa->foo1();                //调用的是A::foo
//	pa->foo1(1);               //编译错误 A类中没有foo1(int a)类型的函数  因为是通过pa指针调用的！！！
	pb->foo1(1);               //调用的是B::foo1_int  


#endif
}
