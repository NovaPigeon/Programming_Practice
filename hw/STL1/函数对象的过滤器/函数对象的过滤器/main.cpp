//
//  main.cpp
//  函数对象的过滤器
//
//  Created by 寿晨宸 on 2022/4/6.
//

/*
D:函数对象的过滤器
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
 程序填空输出指定结果*/

#include <iostream>
#include <vector>
using namespace std;
struct A {
    int v;
    A() { }
    A(int n):v(n) { };
    bool operator<(const A & a) const {
        return v < a.v;
    }
};
// 在此处补充你的代码

template <class T>
void Print(T s,T e)
{
    for(;s!=e; ++s)
        cout << *s << ",";
    cout << endl;
}
template <class T1, class T2,class T3>
T2 Filter( T1 s,T1 e, T2 s2, T3 op)
{
    for(;s != e; ++s) {
        if( op(*s)) {
            * s2 = * s;
            ++s2;
        }
    }
    return s2;
}
template <class T>
class FilterClass
{
private:
    T n1,n2;
public:
    FilterClass(T n1_,T n2_):n1(n1_),n2(n2_){}
    bool operator ()(T num)
    {
        return (num<n2 && n1<num);
    }
};
ostream & operator <<(ostream & o,A & a)
{
    o << a.v;
    return o;
}
vector<int> ia;
vector<A> aa;
int main()
{
    int m,n;
    while(cin >> m >> n) {
        ia.clear();
        aa.clear();
        int k,tmp;
        cin >> k;
        for(int i = 0;i < k; ++i) {
            cin >> tmp;
            ia.push_back(tmp);
            aa.push_back(tmp);
        }
        vector<int> ib(k);
        vector<A> ab(k);
        vector<int>::iterator p =  Filter(ia.begin(),ia.end(),ib.begin(),FilterClass<int>(m,n));
        Print(ib.begin(),p);
        vector<A>::iterator pp = Filter(aa.begin(),aa.end(),ab.begin(),FilterClass<A>(m,n));
        Print(ab.begin(),pp);
        
    }
    return 0;
}
/*
 输入
 多组数据
 每组数据两行
 
 第一行是两个整数 m 和 n
 第二行先是一个整数k ,然后后面跟着k个整数
 输出
 对每组数据，按原顺序输出第二行的后k个整数中，大于m且小于n的数
 输出两遍
 数据保证一定能找到符合要求的整数
 样例输入
 1 3
 1 2
 2 8
 5 1 2 3 4 9
 样例输出
 2,
 2,
 3,4,
 3,4,
 来源
 Guo Wei
 */
