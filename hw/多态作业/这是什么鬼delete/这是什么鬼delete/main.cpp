//
//  main.cpp
//  这是什么鬼delete
//
//  Created by 寿晨宸 on 2022/3/23.
//

/*
C:这是什么鬼delete
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空输出指定结果*/

#include <iostream>
using namespace std;
class A
{
public:
    A() { }
// 在此处补充你的代码
    //~A(){cout<<"destructor B"<<endl<<"destructor A"<<endl;}
    virtual ~A(){cout<<"destructor A"<<endl;}
};
class B:public A {
    public:
    ~B() { cout << "destructor B" << endl; }
};
int main()
{
    A * pa;
    pa = new B;
    delete pa;
    return 0;
}
/*输入
无
输出
destructor B
destructor A
样例输入
无
样例输出
destructor B
destructor A
来源
Guo Wei*/
