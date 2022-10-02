/*
07C:开餐馆
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
北大信息学院的同学小明毕业之后打算创业开餐馆.现在共有n 个地点可供选择。
小明打算从中选择合适的位置开设一些餐馆。这 n 个地点排列在同一条直线上。
我们用一个整数序列m1, m2, ... mn 来表示他们的相对位置。
由于地段关系,开餐馆的利润会有所不同。
我们用pi 表示在mi 处开餐馆的利润。
为了避免自己的餐馆的内部竞争,餐馆之间的距离必须大于k。
请你帮助小明选择一个总利润最大的方案。


输入
标准的输入包含若干组测试数据。输入第一行是整数T (1 <= T <= 1000) ，表明有T组测试数据。
紧接着有T组连续的测试。每组测试数据有3行,
第1行:地点总数 n (n < 100), 距离限制 k (k > 0 && k < 1000).
第2行:n 个地点的位置m1 , m2, ... mn ( 1000000 > mi > 0 且为整数,升序排列)
第3行:n 个地点的餐馆利润p1 , p2, ... pn ( 1000 > pi > 0 且为整数)
输出
对于每组测试数据可能的最大利润
样例输入
2
3 11
1 2 15
10 2 30
3 16
1 2 15
10 2 30
样例输出
40
30
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int T,n,k,m[105],p[105],dp[105];;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        memset(m,0,sizeof(m));
        memset(p,0,sizeof(p));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i)
            cin>>m[i];
        for(int i=0;i<n;++i)
            cin>>p[i];
        for(int i=0;i<n;++i)
            dp[i]=p[i];
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(m[i]-m[j]>k)
                {
                    dp[i]=max(dp[i],dp[j]+p[i]);
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;++i)
            mx=max(mx,dp[i]);
        cout<<mx<<endl;
    }
    return 0;
}