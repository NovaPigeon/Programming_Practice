//
//  main.cpp
//  排序，又见排序！
//
//  Created by 寿晨宸 on 2022/3/27.
//

/*
G:排序，又见排序!
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
自己编写一个能对任何类型的数组进行排序的mysort函数模版。只能写一个mysort模板，不能写mysort函数！
*/
#include <iostream>
using namespace std;

bool Greater2(int n1,int n2)
{
    return n1 > n2;
}
bool Greater1(int n1,int n2)
{
    return n1 < n2;
}
bool Greater3(double d1,double d2)
{
    return d1 < d2;
}

template <class T1,class T2>
void mysort
// 在此处补充你的代码
(T1* st,T1* ed,T2 func)
{
    int n=ed-st;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
        {
            if(!func(*(st+j),*(st+j+1)))
            {
                T1 temp;
                temp=*(st+j);
                *(st+j)=*(st+j+1);
                *(st+j+1)=temp;
            }
        }
}
#define NUM 5
int main()
{
    int an[NUM] = { 8,123,11,10,4 };
    mysort(an,an+NUM,Greater1); //从小到大排序
    for( int i = 0;i < NUM; i ++ )
       cout << an[i] << ",";
    mysort(an,an+NUM,Greater2); //从大到小排序
    cout << endl;
    for( int i = 0;i < NUM; i ++ )
        cout << an[i] << ",";
    cout << endl;
    double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1};
    mysort(d+1,d+5,Greater3); //将数组从下标1到下标4从小到大排序
    for( int i = 0;i < 6; i ++ )
         cout << d[i] << ",";
    return 0;
}
/*输入
无
输出
4,8,10,11,123,
123,11,10,8,4,
1.4,1.2,1.8,3.1,3.2,2.1,
样例输入
无
样例输出
4,8,10,11,123,
123,11,10,8,4,
1.4,1.2,1.8,3.1,3.2,2.1,
来源
Guo Wei
*/
