//
//  main.cpp
//  我自己的ostream_iterator
//
//  Created by 寿晨宸 on 2022/4/6.
//

/*
F:我自己的 ostream_iterator
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空输出指定结果*/

#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T1,class T2>
void Copy(T1 s,T1 e, T2 x)
{
    for(; s != e; ++s,++x)
        *x = *s;
}

 
template<class T>
class myostream_iteraotr
{
// 在此处补充你的代码
private:
    ostream& os;
    string str;
public:
    myostream_iteraotr(ostream& os_,string str_):os(os_),str(str_){}
    void operator=(const T& obj)
    {
        os<<obj<<str;
    }
    myostream_iteraotr& operator++(){return *(this+1);}
    myostream_iteraotr& operator*(){return *this;}
};


int main()
{    const int SIZE = 5;
    int a[SIZE] = {5,21,14,2,3};
    double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3};
    list<int> lst(a,a+SIZE);
    myostream_iteraotr<int> output(cout,",");
    Copy( lst.begin(),lst.end(),output);
    cout << endl;
    myostream_iteraotr<double> output2(cout,"--");
    Copy(b,b+SIZE,output2);
    return 0;
}
/*输入
无
输出
5,21,14,2,3,
1.4--5.56--3.2--98.3--3.3--
样例输入
无
样例输出
同输入
来源
Guo Wei*/

