/*
B:夺宝探险
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
你无意中发现了装满了宝藏的迷宫，你想要获得尽可能多的宝藏，但是迷宫里的机关阻碍了你的计划。
迷宫的地面是M行N列的矩形网格，每格是一块带有机关且放置了1个宝藏的地砖，
宝藏一共有K种，用1-K表示其种类，迷宫的入口只有一个，为迷宫的第一行第一列。地砖的机关如下：

1. 每次你只能踏到你与你所在地砖相邻的地砖上（即前后左右4块）；

2. 当你踏上某块地砖后，其上的宝藏（假设种类为k）自动归属你，同时所有放置了种类为k的宝藏的地砖碎裂，
你无法踏上，你当前所在的地砖在你离开后也会立刻碎裂；
3. 当你无路可走的时候，你会被传送回迷宫出口，无法再进入迷宫.

你想知道你最多能获得多少宝藏。

输入
输入的第一行是三个用空格隔开的整数，分别是M、N和K（1 <= M,N <= 20, 1 <= K <= 100）
之后是M行，每行包含N个范围为1-K的整数，用空格隔开，表示放置的宝藏种类
输出
只有一行，为一个整数，表示最多能获得的宝藏个数。
样例输入
3 4 5
1 2 3 3
2 1 4 3
1 5 1 2
样例输出
4
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int M,N,K;
int map[30][30],flag[30][30]={1};
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int Max_N=0;
bool judge(int x,int y)
{
    if(x<0||y<0||x>=M||y>=N)
        return false;
    if(flag[x][y]==0)
        return false;
    return true;
}
bool check(int x,int y)
{
    int cnt=0;
    for(int i=0;i<4;++i)
    {
        int x_=x+dx[i],y_=y+dy[i];
        if(judge(x_,y_))
            cnt+=flag[x_][y_];
    }
    if(cnt==0)
        return true;
    else
        return false;
}
void dfs(int x,int y,int sum)
{
    //cout<<x<<" "<<y<<" "<<sum<<endl;
    if(check(x,y))
    {
        Max_N=max(Max_N,sum);
        //cout<<"**"<<endl;
        return;
    }
    for(int i=0;i<4;++i)
    {
        int x_=x+dx[i],y_=y+dy[i];
        if(judge(x_,y_))
        {
            int temp[30][30];
            for(int j=0;j<M;++j)
                for(int k=0;k<N;++k)
                {
                    temp[j][k]=flag[j][k];
                    if(map[j][k]==map[x_][y_])
                        flag[j][k]=0;
                }
            dfs(x_,y_,sum+1);
            for(int j=0;j<M;++j)
                for(int k=0;k<N;++k)
                {
                    flag[j][k]=temp[j][k];
                }
        }
    }
}
int main()
{
    cin>>M>>N>>K;
    memset(flag,1,sizeof(flag));
    for(int i=0;i<M;++i)
        for(int j=0;j<N;++j)
        {
            cin>>map[i][j];
            if(map[i][j]==map[0][0])
                flag[i][j]=0;
        }
    dfs(0,0,1);
    cout<<Max_N;
    return 0;
}
