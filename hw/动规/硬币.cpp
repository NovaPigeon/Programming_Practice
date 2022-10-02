/*
B:硬币
总时间限制: 1000ms 内存限制: 262144kB
描述
宇航员Bob有一天来到火星上，他有收集硬币的习惯。
于是他将火星上所有面值的硬币都收集起来了，一共有n种，每种只有一个：
面值分别为a1,a2… an。 Bob在机场看到了一个特别喜欢的礼物，想买来送给朋友Alice，这个礼物的价格是X元。
Bob很想知道为了买这个礼物他的哪些硬币是必须被使用的，即Bob必须放弃收集好的哪些硬币种类。
飞机场不提供找零，只接受恰好X元。

输入
第一行包含两个正整数n和x。（1 <= n <= 200, 1 <= x <= 10000)
第二行从小到大为n个正整数a1, a2, a3 … an （1 <= ai <= 10000)
输出
第一行是一个整数，即有多少种硬币是必须被使用的。
第二行是这些必须使用的硬币的面值（从小到大排列）。
样例输入
5 18
1 2 3 5 10
样例输出
2
5 10
提示
输入数据将保证给定面值的硬币中至少有一种组合能恰好能够支付X元。
如果不存在必须被使用的硬币，则第一行输出0，第二行输出空行。
*/

#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int N, X, coins[300] = {0},flag[300]={0};
int dp[10001]={0};
int cnt = 0;
int main()
{
    cin >> N >> X;
    for (int i = 0; i < N; ++i)
        cin >> coins[i];
    //若去掉coins[i]就无法支付价格X,则coins[i]无法替代
    for(int i=0;i<N;++i)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int cn=0,tmp[300]={0};
        for(int j=0;j<N;++j)
        {
            if(j==i)
                continue;
            else
            {
                tmp[cn]=coins[j];
                cn++;
            }
        }
        for(int j=0;j<N-1;++j)
            for(int k=X;k>=tmp[j];--k)
            {
                dp[k]+=dp[k-tmp[j]];
            }
        if(dp[X]==0)
        {
            cnt++;
            flag[i]=1;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<N;++i)
    {
        if(flag[i]==1)
            cout<<coins[i]<<" ";
    }
    
}
/*
#include <cstdio>
#include <cstring>

int dp[10010];
int ans[10010]; //ans数组表示在去掉a[i]币值之后，硬币能不能表示价格j
int a[200];
int b[200];

int main()
{
    int n, x;
    int cnt;
    while (scanf("%d%d", &n, &x) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        memset(b, 0, sizeof(b));
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = x; j >= a[i]; j--)
            {
                dp[j] += dp[j - a[i]];
            }
        }
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= x; j++)
            {
                if (j < a[i])
                    ans[j] = dp[j];
                else
                    ans[j] = dp[j] - ans[j - a[i]]; //这里理解有点困难，dp[j]表示可以包括a[i]也可以不包括a[i]，凑成j面值的方法数，ans[j-a[i]]表示不带a[i]可以凑成
                                                    // j-a[i] 的方法总数， j - a[i] + a[i]就是j，也就是ans[j - a[i]]是必须带上a[i]能凑成j 面值的方法总数，两者减就是不带上a[i] 凑成 j面值的方法数。
            }
            if (ans[x] == 0)
            {
                b[cnt++] = a[i];
            }
        }
        printf("%d", cnt);
        if (cnt == 0)
            printf("");
        else
            for (int i = 0; i < cnt; i++)
            {
                if (i != cnt - 1)
                    printf("%d ", b[i]);
                else
                    printf("%d", b[cnt - 1]);
            }
    }
}
*/