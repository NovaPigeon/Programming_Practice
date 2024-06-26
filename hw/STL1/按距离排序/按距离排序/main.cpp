//
//  main.cpp
//  按距离排序
//
//  Created by 寿晨宸 on 2022/4/6.
//

/*
B:按距离排序
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，输出指定结果*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
template <class T1,class T2>
struct Closer {
// 在此处补充你的代码
private:
    T1 obj;
    T2 Pred;
public:
    Closer(T1 obj_,T2 Pred_):obj(obj_),Pred(Pred_){}
    bool operator()(const T1& sub1,const T1& sub2)
    {
        return (Pred(sub1,obj)<Pred(sub2,obj))||(Pred(sub1,obj)==Pred(sub2,obj)&&sub1<sub2);
            
    }
};

int Distance1(int n1,int n2) {
    return abs(n1-n2);
}
int Distance2(const string & s1, const string & s2)
{
    return abs((int)s1.length()- (int) s2.length());
}
int a[10] = { 0,3,1,4,7,9,20,8,10,15};
string b[6] = {"American","Jack","To","Peking","abcdefghijklmnop","123456789"};
int main()
{
    int n;string s;
    while( cin >> n >> s ) {
        sort(a,a+10,Closer<int ,int (*)(int ,int)> (n,Distance1));
        for(int i = 0;i < 10; ++i)
            cout << a[i] << "," ;
        cout << endl;
        sort(b,b+6,Closer<string,int (*)(const string &,const string &  )> (s,Distance2));
        for(int i = 0;i < 6; ++i)
            cout << b[i] << "," ;
        cout << endl;
    }
    return 0;
}
/*输入
多组数据，每组一行，是一个整数n和一个字符串s
输出
定义两个整数的距离为两个整数差的绝对值
定义两个字符串的距离为两个字符串长度差的绝对值

对每组数据：
对数组a按和n的距离从小到大排序后输出。距离相同的，值小的排在前面。
然后对数组b，按照和s的距离从小到大输出。距离相同的，字典序小的排在前面
样例输入
2 a123456
4 a12345
样例输出
1,3,0,4,7,8,9,10,15,20,
American,Peking,123456789,Jack,To,abcdefghijklmnop,
4,3,1,7,0,8,9,10,15,20,
Peking,American,Jack,123456789,To,abcdefghijklmnop,
来源
Guo Wei*/
