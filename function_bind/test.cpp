/*- ==========================================================
*     文件名  ：TestCpp11_1.cpp
*     开发人员：袁培荣
*     当前版本：1.0.0.2595
*     创建时间：2012-05-20
*     修改时间：2012-05-20
*     功能说明：测试编译器是否支持C++11新特性(1)
*     版权说明：版权所有 袁培荣 YuanPeirong 
*     编译环境：Windows 7(x64) SP1 简体中文专业版
*     编译器：  Visual Studio 2010 SP1(中文旗舰版)
                MinGW 20120426 GNU GCC 4.6.2
                MinGW Distro 9.0 GNU GCC 4.7.0
                Visual C++ 6.0 SP6(中文企业版)
- ==========================================================*/

#include <iostream>
#include <vector>
using namespace std;

//=====1.测试右值引用和move语意
bool is_r_value(int &&) { return true; } 
bool is_r_value(const int &) { return false; }
 
void test(int && i)
{
    is_r_value(i); 
    is_r_value(std::move<int>(i));
}
//====================================

int main(int argc, char* argv[])
{
 
//=====2.测试以范围为基础的 for 循环
    int my_array[5] = {1, 2, 3, 4, 5};
    for (int &x : my_array) 
    {
      x *= 2;
    }
//====================================
    
//=====3.测试型别推导
    constexpr int GetFive() {return 5;}
    int some_value[GetFive() + 5];
    const std::vector<int> v(1);
    auto a = v[0];
    decltype(v[0])b;   
    auto c = 0;         
    auto d = c;   
    decltype(c) e;  
    decltype((c)) f = e;
    decltype(0) g;  
//====================================
    return 0;
}



//=====4.测试初始化表达式
class C
{
    int a=7; //在类的定义时初始化非静态变量，只有C++11支持
    public:
    C();
};
//====================================


//====================================
//=====测试结果

// 测试标准:编译对测试代码不报错为支持，否则不支持

//1.Visual Studio 2010 SP1(中文旗舰版) 全部不支持

//2.MinGW 20120426 GNU GCC 4.6.2
//   支持前两个，不支持后两个
//  （注意，编译时应该开启新特性 -std=c++0x 或者 -std=gnu++0x）
//  命令: g++ TestCpp11_1.cpp -o TestCpp11_1 -std=c++0x

//3.MinGW Distro 9.0 GNU GCC 4.7.0
//   很高兴，全部支持
//  （注意，编译时应该开启新特性 -std=c++0x 或者 -std=gnu++0x）
//  命令: g++ TestCpp11_1.cpp -o TestCpp11_1 -std=c++0x

//4.Visual C++ 6.0 SP6(中文企业版) 全部不支持
//==============================
