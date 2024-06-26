/*
02A:完美立方
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
形如a3= b3 + c3 + d3的等式被称为完美立方等式。
例如123= 63 + 83 + 103 。编写一个程序，对任给的正整数N (N≤100)，寻找所有的四元组(a, b, c, d)，
使得a3 = b3 + c3 + d3，其中a,b,c,d 大于 1, 小于等于N，且b<=c<=d。

输入
一个正整数N (N≤100)。
输出
每行输出一个完美立方。输出格式为：
Cube = a, Triple = (b,c,d)
其中a,b,c,d所在位置分别用实际求出四元组值代入。

请按照a的值，从小到大依次输出。当两个完美立方等式中a的值相同，则b值小的优先输出、仍相同则c值小的优先输出、再相同则d值小的先输出。
样例输入
24
样例输出
Cube = 6, Triple = (3,4,5)
Cube = 12, Triple = (6,8,10)
Cube = 18, Triple = (2,12,16)
Cube = 18, Triple = (9,12,15)
Cube = 19, Triple = (3,10,18)
Cube = 20, Triple = (7,14,17)
Cube = 24, Triple = (12,16,20)
来源
1543
*/
#include<iostream>
using namespace std;
int N;
int main()
{
    cin>>N;
    for(int a=6;a<=N;++a)
    {
        for(int b=2;b*b*b*3<=a*a*a;++b)
        {
            int r1=a*a*a-b*b*b;
            for(int c=2;c*c*c*2<=r1;++c)
            {
                if(c<b)
                    continue;
                int r2=r1-c*c*c;
                int d=2;
                for(;d*d*d<r2;++d);
                //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                if(d*d*d==r2&&d>=c)
                    cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
            }
        }
    }
}