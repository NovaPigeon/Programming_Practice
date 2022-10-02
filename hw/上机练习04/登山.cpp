/*
02F:登山
查看 提交 统计 提问
总时间限制: 5000ms 内存限制: 131072kB
描述
五一到了，PKU-ACM队组织大家去登山观光，队员们发现山上一个有N个景点，
并且决定按照顺序来浏览这些景点，即每次所浏览景点的编号都要大于前一个浏览景点的编号。
同时队员们还有另一个登山习惯，就是不连续浏览海拔相同的两个景点，并且一旦开始下山，就不再向上走了。
队员们希望在满足上面条件的同时，尽可能多的浏览景点，你能帮他们找出最多可能浏览的景点数么？

输入
Line 1： N (2 <= N <= 1000) 景点数
Line 2： N个整数，每个景点的海拔
输出
最多能浏览的景点数
样例输入
8
186 186 150 200 160 130 197 220
样例输出
4
来源
第六届北京大学程序设计大赛暨ACM/ICPC选拔赛
*/
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int dp_up[1005]={1},dp_down[1005]={1};
int N,scene[1005];
int Max=0;
int main()
{
    cin>>N;
    for(int i=0;i<N;++i)
    {
        cin>>scene[i];
        dp_up[i]=dp_down[i]=1;
    }
    for(int i=1;i<N;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(scene[i]>scene[j])
                dp_up[i]=max(dp_up[i],dp_up[j]+1);
        }
    }
    for(int i=N-2;i>=0;--i)
    {
        for(int j=N-1;j>i;--j)
        {
            if(scene[i]>scene[j])
                dp_down[i]=max(dp_down[i],dp_down[j]+1);
        }
    }
    for(int i=0;i<N;++i)
        Max=max(Max,dp_down[i]+dp_up[i]-1);
    /*
    for(int i=0;i<N;++i)
        cout<<dp_up[i]<<" ";
    cout<<endl;
    for(int i=0;i<N;++i)
        cout<<dp_down[i]<<" ";
    cout<<endl;
    */
    cout<<Max;
    return 0;
}
