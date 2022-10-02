//
//  main.cpp
//  Fun和Do
//
//  Created by 寿晨宸 on 2022/3/23.
//

/*
B:Fun和Do
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空输出指定结果*/

#include <iostream>
using namespace std;
class A {
    private:
    int nVal;
    public:
    void Fun()
    { cout << "A::Fun" << endl; };
    void Do()
    { cout << "A::Do" << endl; }
};
class B:public A {
    public:
    virtual void Do()
    { cout << "B::Do" << endl;}
};
class C:public B {
    public:
    void Do( )
    { cout <<"C::Do"<<endl; }
    void Fun()
    { cout << "C::Fun" << endl; }
};
void Call(
// 在此处补充你的代码
B &p
) {
    p.Fun(); p.Do();
}
int main() {
    C c;
    Call( c);
    return 0;
}
/*输入
无
输出
A::Fun
C::Do
样例输入
None
样例输出
A::Fun
C::Do
来源
Guo Wei
查看 提交 统计 提问
全局题号
9594
提交次数
171
尝试人数
145
通过人数
145
Other language verions
English*/
