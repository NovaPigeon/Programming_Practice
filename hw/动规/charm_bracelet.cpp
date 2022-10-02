/*
C:Charm Bracelet
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Bessie has gone to the mall's jewelry store and spies a charm bracelet. 
Of course, she'd like to fill it with the best charms possible from the N(1 ≤ N≤ 3,402) available charms.
 Each charm iin the supplied list has a weight Wi(1 ≤ Wi≤ 400), a 'desirability' factor Di(1 ≤ Di≤ 100), and can be used at most once.
  Bessie can only support a charm bracelet whose weight is no more than M(1 ≤ M≤ 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, 
deduce the maximum possible sum of ratings.



输入
Line 1: Two space-separated integers: N and M
Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di
输出
Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints
样例输入
4 6
1 4
2 6
3 12
2 7
样例输出
23
来源
USACO 2007 December Silver
*/
//背包问题，背包容量为M，共有N个珠宝，给定每个珠宝的重量Wi和价值Di
//求背包最多可容纳多少价值的珠宝
//状态转移方程：设dp(i,j)为前i个珠宝在j的容量内最多能取到的价值总量
//if Wi>j:dp(i,j)=dp(i-1,j);
//if Wi<=j:dp(i,j)=max{dp(i-1,j),dp(i-1,j-Wi)+Di}
//如果要优化为一维，则需要逆序
//dp(i)=max{dp(i),dp(i-Wi)+Di}
#include<iostream>
#include<bits/stdc++.h>
#define MAX_N 3405
using namespace std;
int dp[2000010]={0};
int main()
{
  int N,M;
  int w[MAX_N],d[MAX_N];
  cin>>N>>M;
  for(int i=1;i<=N;++i)
    cin>>w[i]>>d[i];
  for(int i=1;i<=N;++i)//即二维方法中的前i个珠宝
  {
    for(int j=M;j>=w[i];j--)
    {
      //必须逆序，否则会被本次循环中的更新污染，即dp[i-wi]已被本次循环所更新
      //本来若使用二维方法，两次循环会被第一重角标i和i-1所隔开，
      dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
    }
  }
  cout<<dp[M];
}