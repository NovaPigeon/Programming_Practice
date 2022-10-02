/*
H:迷宫入口

描述
爱好探险的你，找到一座装满了宝藏的迷宫的入口，
你看到入口的大门上有一个边长为s的正方形的大锁，旁边散落着n块正方形的金属小片，
你意识到锁的钥匙，即是用这n小块，拼成大门上的正方形，你想知道是否能拼成这把钥匙打开迷宫的大门。

输入
输入包含多组数组，第一行是一个整数t（1 <= t <= 10)，表示有t组数据。
接下里每组数组包含整数s，即锁的边长，整数n（1 <= n <= 16)，即金属小片的数量，
接下来n个整数，分别是各个小片的边长ci（1 <= ci <= 10）。
输出
每组数据输出一行，输出“YES"或者"NO"，表示是否可以打开大门。
样例输入
2
4 8 1 1 1 1 1 3 1 1
5 6 3 3 2 1 1 1
样例输出
YES
NO
*/
#include<bits/stdc++.h>
using namespace std;
int t,s,n,C,c[12]={0},mp[20][20]={0};
bool can_put(int x,int y,int d)
{
    if(x+d-1>s||y+d-1>s)
        return 0;
    for(int i=0;i<d;++i)
        for(int j=0;j<d;++j)
            if(mp[x+i][y+j]==1)
                return 0;
    return 1;
}
void put(int x,int y,int d,int val)
{
    for(int i=0;i<d;++i)
        for(int j=0;j<d;++j)
            mp[i+x][j+y]=val;
}
bool dfs()
{
    int i,j;
    for(i=1;i<=s;++i)
        for(j=1;j<=s;++j)
            if(mp[i][j]==0)
                goto END;
    END:;
    if(i==s+1&&j==s+1)
        return 1;
    for(int k=1;k<=10;++k)
    {
        if(c[k]&&can_put(i,j,k))
        {
            c[k]--;
            put(i,j,k,1);
            if(dfs())
                return 1;
            put(i,j,k,0);
            c[k]++;
        }
    }
    return 0;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s>>n;
        memset(c,0,sizeof(c));
        memset(mp,0,sizeof(mp));
        for(int i=0;i<n;++i)
        {
            cin>>C;
            c[C]++;
        }
        bool is_success=dfs();
        if(is_success)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}