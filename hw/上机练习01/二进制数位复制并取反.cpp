/*
08:二进制数位复制并取反
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入整数a b i j，把b从第i到j位(包括i,j)的二进制位全部取反，并填入a的i到j位中，a的其他位不变。输出a。 最右边一位是第0位。

输入
整数a b i j(范围不超过int)
输出
改变以后的a
样例输入
6123 3344 2 9
样例输出
5871
*/
#include<iostream>
using namespace std;
int main()
{   
    int a,b,i,j;
    cin>>a>>b>>i>>j;
    int k=(1<<(j+1))-(1<<i);
    a&=(~k);
    a|=(~b)&k;
    cout<<a;
    return 0;
}