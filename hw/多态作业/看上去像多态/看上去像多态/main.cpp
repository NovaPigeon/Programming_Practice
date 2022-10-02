//
//  main.cpp
//  看上去像多态
//
//  Created by 寿晨宸 on 2022/3/23.
//


/*
A:看上去像多态
程序填空产生指定输出
*/
//不是多态，只是简单的继承
#include <iostream>
using namespace std;
class B {
    private:
        int nBVal;
    public:
        void Print()
        { cout << "nBVal="<< nBVal << endl; }
        void Fun()
        {cout << "B::Fun" << endl; }
        B ( int n ) { nBVal = n;}
};
// 在此处补充你的代码
class D:public B
{
private:
    int nDVal;
public:
    D(int n):B(3*n),nDVal(n){}
    void Fun()
    {cout<<"D::Fun"<<endl;}
    void Print()
    {B::Print();cout<<"nDVal="<<nDVal<<endl;}
};
int main() {
    B * pb; D * pd;
    D d(4); d.Fun();
    pb = new B(2); pd = new D(8);
    pb -> Fun(); pd->Fun();
    pb->Print (); pd->Print ();
    pb = & d; pb->Fun();
    pb->Print();//因为不包含多态，所以仍将pb视为B*的对象，调用B的函数
    return 0;
}
/*输入
无
输出
D::Fun
B::Fun
D::Fun
nBVal=2
nBVal=24
nDVal=8
B::Fun
nBVal=12

来源
Guo Wei*/
