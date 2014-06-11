#include <iostream>

using namespace std;

class expt			//定义类expt
{
  public:			//定义公有成员
    expt()			//定义构造函数
    {
	cout << "structor of expt" << endl;
    } ~expt()			//定义析构函数
    {
	cout << "destructor of expt" << endl;
    }
};

class demo			//定义类demo
{
  public:
    demo()			//定义构造函数
    {
	cout << "structor of demo" << endl;
    } ~demo()			//定义析构函数
    {
	cout << "destructor of demo" << endl;
    }
};

void fuc1()			//定义函数
{
//    expt e;			//声明expt类的对象
    int s = 0;
    demo d;			//声明demo类的对象
    throw expt();			//抛出异常
}

void fuc2()
{
    fuc1();			//调用函数fuc1
}

int main()
{
    try				//定义异常
    {
	fuc2();			//调用函数
    }
    //catch(int e)			//定义异常处理
    //catch(...)			//定义异常处理
    catch(class expt &e)			//定义异常处理
    {
//		cout << "exception e = " << e << endl;
	cout << "catch int exception" << endl;
    }
    cout << "continue main()" << endl;

    return 0;
}
