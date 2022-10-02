/*
A:迷宫问题
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
定义一个二维数组：

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。



输入
一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
输出
左上角到右下角的最短路径，格式如样例所示。
样例输入
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
样例输出
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
*/
#include<iostream>
#include<string.h>
#include<vector>
#include<climits>
using namespace std;
int dx[4]={0,0,1,-1},dy[4]={-1,1,0,0};
int flag[5][5]={0},maze[5][5]={0};
int min_lenth=INT_MAX;
class points
{
    public:
        int x,y;
        points(int x_,int y_):x(x_),y(y_){};
};
vector<points> result,record;
bool judge(int x,int y)
{
    if(x<0||x>=5||y<0||y>=5)
        return false;
    if(flag[x][y]==1||maze[x][y]==1)
        return false;
    return true;
}
void dfs(int x,int y,int lenth)
{   if(x==0&&y==0)
        record.push_back({0,0});
    if(x==4&&y==4)
    {
        if(lenth<min_lenth)
        {
            min_lenth=lenth;
            result=record;
        }
        return;
    }
    for(int i=0;i<4;++i)
    {
        int newX=x+dx[i],newY=y+dy[i];
        if(judge(newX,newY))
        {
            flag[newX][newY]=1;
            record.push_back(points(newX,newY));
            dfs(newX,newY,lenth+1);
            record.pop_back();
            flag[newX][newY]=0;
        }
    }
}
int main()
{
    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j)
            cin>>maze[i][j];
    dfs(0,0,1);
    for(int i=0;i<result.size();++i)
        cout<<"("<<result[i].x<<", "<<result[i].y<<")"<<endl;
    return 0;
}