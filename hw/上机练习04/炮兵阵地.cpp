/*
02I:炮兵阵地
查看 提交 统计 提问
总时间限制: 2000ms 内存限制: 65536kB
描述
司令部的将军们打算在N*M的网格地图上部署他们的炮兵部队。一个N*M的地图由N行M列组成，地图的每一格可能是山地（用"H" 表示），也可能是平原（用"P"表示），如下图。在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；一支炮兵部队在地图上的攻击范围如图中黑色区域所示：


如果在地图中的灰色所标识的平原上部署一支炮兵部队，则图中的黑色的网格表示它能够攻击到的区域：沿横向左右各两格，沿纵向上下各两格。图上其它白色网格均攻击不到。从图上可见炮兵的攻击范围不受地形的影响。
现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。
输入
第一行包含两个由空格分割开的正整数，分别表示N和M；
接下来的N行，每一行含有连续的M个字符('P'或者'H')，中间没有空格。按顺序表示地图中每一行的数据。N <= 100；M <= 10。
输出
仅一行，包含一个整数K，表示最多能摆放的炮兵部队的数量。
样例输入
5 4
PHPP
PPHH
PPPP
PHPP
PHHP
样例输出
6
来源
Noi 01
*/
#include<iostream>
#include<string.h>
#include<math.h>
using  namespace std;
int N,M,Max_N=0,flag[101][11]={0};
char map_pic[101][11]={'\0'};
bool judge()
{
    int cnt=0;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            cnt+=flag[i][j];
    if(cnt==N*M)
        return true;
    return false;
}
void trun_on(int i,int j)
{
    flag[i][j]=1;
    flag[max(i-1,0)][j]=1;
    flag[max(i-2,0)][j]=1;
    flag[min(i+1,M-1)][j]=1;
    flag[min(i+2,M-1)][j]=1;
    flag[i][min(j-1,0)]=1;
    flag[i][min(j-2,0)]=1;
    flag[i][max(j+1,N-1)]=1;
    flag[i][max(j+2,N-1)]=1;
}
void dfs(int n)
{
    if(judge())
    {
        Max_N=max(Max_N,n);
        return;
    }
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
        {
            if(flag[i][j]==0)
            {
                int record[101][11];
                for(int i=0;i<N;++i)
                    for(int j=0;j<N;++j)
                        record[i][j]=flag[i][j];
                trun_on(i,j);
                dfs(n+1);
                for(int i=0;i<N;++i)
                    for(int j=0;j<N;++j)
                        flag[i][j]=record[i][j];
            }
        }
}
int main()
{
    cin>>N>>M;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
        {
            cin>>map_pic[i][j];
            if(map_pic[i][j]=='H')
                flag[i][j]=1;
            else
                flag[i][j]=0;
        }
    dfs(0);
    cout<<Max_N;
    return 0;
}
/*
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n,g[10001],cnt;
int s[10001],num[10001];
int f[2][1001][1001];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            if(c=='P')
                g[i]+=1<<(m-j-1);
        } 
    for(int i=0;i<(1<<m);i++)
    {
        if(!(i&i>>1)&&!(i&i>>2))
        {
            s[cnt++]=i;
            for(int j=0;j<m;j++)
                num[i]+=(i>>j&1);
        }
    }
    for(int i=1;i<=n+2;i++)
        for(int a=0;a<cnt;a++)
            for(int b=0;b<cnt;b++)
                for(int c=0;c<cnt;c++)
                {
                    if(!(s[a]&s[c])&&!(s[b]&s[c])&&!(s[a]&s[b])&&(g[i]&s[a])==s[a]&&(g[i-1]&s[b])==s[b])
                        f[i&1][a][b]=max(f[i&1][a][b],f[i-1&1][b][c]+num[s[a]]);
                }
    printf("%d",f[n+2&1][0][0]);
}
*/