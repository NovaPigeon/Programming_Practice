/*
02B:最简真分数
描述
给出n个正整数，任取两个数分别作为分子和分母组成最简真分数，编程求共有几个这样的组合。

输入
第一行是一个正整数n（n<=600）。
第二行是n个不同的整数，相邻两个整数之间用单个空格隔开。整数大于1且小于等于1000。
输出
一个整数，即最简真分数组合的个数。
样例输入
7
3 5 7 9 11 13 15
样例输出
17
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int N,num[700]={0};
    cin>>N;
    int cnt=0;
    for(int i=0;i<N;++i)
    {
        cin>>num[i];
    }
    for(int i=0;i<N-1;++i)
        for(int j=i+1;j<N;++j)
        {
            //cout<<num[i]<<" "<<num[j]<<endl;
            int flag=0;
            for(int k=2;k<=min(num[i],num[j]);++k)
            {
                
                if(num[i]%k==0&&num[j]%k==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                cnt++;
        }
    cout<<cnt;
}