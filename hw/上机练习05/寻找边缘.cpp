/*
C:寻找边缘
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一张 R*C 的地图，由 "X" 和 "O" 组成。

现在需要重新处理这张地图，找到地图边缘的那些 "O"。你需要将这些地图边缘上的 "O" 保留下来，然后将其他的 "O" 全部替换为 "X"。

地图边缘的 "O" 指的是那些处于第一行/列或最后一行/列上的 "O"，以及从这些 "O" 的相邻位置（上下左右）延伸出去的 "O"。

输入
第一行是一个正整数 T，表示一共有 T 组数据。
对于每组数据，其第一行是两个正整数 R 和 C，表示地图的大小，用一个空格分开。
接下来的 R 行，每行包含了 C 个字符，分别是 "X" 或 "O"。
其中，0 < T <= 10，0 < R, C <= 500。
输出
对于每组数据，输出 R 行，每行包含了 C 个字符，分别是 "X" 或 "O"。
每组数据之间需要额外输出一个空行。
样例输入
2
2 3
OXX
XXO
5 5
XXXOX
XXXOX
XOOXX
XXOXX
XOXXX
样例输出
OXX
XXO

XXXOX
XXXOX
XXXXX
XXXXX
XOXXX
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int flag[501][501];
int T,R,C;
char map[501][501];
bool judge(int x,int y)
{
    if(x<0||y<0||x>=R||y>=C)
        return false;
    if(map[x][y]!='O'||flag[x][y]==1)
        return false;
    return true;
    
}
void dfs(int x,int y)
{
    flag[x][y]=1;
    int cnt=0;
    for(int i=0;i<4;++i)
    {
        
        int x_=x+dx[i],y_=y+dy[i];
        if(judge(x_,y_))
        {
            cnt++;
            dfs(x_,y_);
        }
    }
    if(cnt==0)
        return;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>R>>C;
        memset(flag,0,sizeof(flag));
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                cin>>map[i][j];
        for(int i=0;i<C;++i)
        {
            if(judge(0,i))
                dfs(0,i);
            if(judge(R-1,i))
                dfs(R-1,i);
        }
        for(int i=0;i<R;++i)
        {
            if(judge(i,0))
                dfs(i,0);
            if(judge(i,C-1))
                dfs(i,C-1);
        }
        for(int i=0;i<R;++i)
        {
            for(int j=0;j<C;++j)
            {
                if(flag[i][j]==1)
                    cout<<"O";
                else 
                    cout<<"X";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}