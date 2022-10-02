/*
A:Saving Tang Monk
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
《Journey to the West》(also 《Monkey》) is one of the Four Great Classical Novels of Chinese literature. It was written by Wu Cheng'en during the Ming Dynasty. In this novel, Monkey King Sun Wukong, pig Zhu Bajie and Sha Wujing, escorted Tang Monk to India to get sacred Buddhism texts.

During the journey, Tang Monk was often captured by demons. Most of demons wanted to eat Tang Monk to achieve immortality, but some female demons just wanted to marry him because he was handsome. So, fighting demons and saving Monk Tang is the major job for Sun Wukong to do.

Once, Tang Monk was captured by the demon White Bones. White Bones lived in a palace and she cuffed Tang Monk in a room. Sun Wukong managed to get into the palace. But to rescue Tang Monk, Sun Wukong might need to get some keys and kill some snakes in his way.

The palace can be described as a matrix of characters. Each character stands for a room. In the matrix, 'K' represents the original position of Sun Wukong, 'T' represents the location of Tang Monk and 'S' stands for a room with a snake in it. Please note that there are only one 'K' and one 'T', and at most five snakes in the palace. And, '.' means a clear room as well '#' means a deadly room which Sun Wukong couldn't get in.

There may be some keys of different kinds scattered in the rooms, but there is at most one key in one room. There are at most 9 kinds of keys. A room with a key in it is represented by a digit(from '1' to '9'). For example, '1' means a room with a first kind key, '2' means a room with a second kind key, '3' means a room with a third kind key... etc. To save Tang Monk, Sun Wukong must get ALL kinds of keys(in other words, at least one key for each kind).

For each step, Sun Wukong could move to the adjacent rooms(except deadly rooms) in 4 directions(north,west,south and east), and each step took him one minute. If he entered a room in which a living snake stayed, he must kill the snake. Killing a snake also took one minute. If Sun Wukong entered a room where there is a key of kind N, Sun would get that key if and only if he had already got keys of kind 1,kind 2 ... and kind N-1. In other words, Sun Wukong must get a key of kind N before he could get a key of kind N+1 (N>=1). If Sun Wukong got all keys he needed and entered the room in which Tang Monk was cuffed, the rescue mission is completed. If Sun Wukong didn't get enough keys, he still could pass through Tang Monk's room. Since Sun Wukong was a impatient monkey, he wanted to save Tang Monk as quickly as possible. Please figure out the minimum time Sun Wukong needed to rescue Tang Monk.

输入
There are several test cases.

For each case, the first line includes two integers N and M(0 < N <= 100, 0 <= M <= 9), meaning that the palace is a N * N matrix and Sun Wukong needed M kinds of keys(kind 1, kind 2, ... kind M).

Then the N*N matrix follows.

The input ends with N = 0 and M = 0.
输出
For each test case, print the minimum time (in minute) Sun Wokong needed to save Tang Monk. If it's impossible for Sun Wokong to complete the mission, print "impossible".
样例输入
3 1
K.S
##1
1#T
3 1
K#T
.S#
1#.
3 2
K#T
.S.
21.
0 0
样例输出
5
impossible
8
来源
Guo Wei
*/
//bfs+状态压缩
#include<bits/stdc++.h>
using namespace std;
const int inf=INT_MAX;
const int max_n=102;
int cnt=0;//用于记录蛇的总数
int N,M;//矩阵大小和钥匙数量
char maze[max_n][max_n];
int dp[max_n][max_n][10][33];//用于记录信息，防止重复展开，分别为坐标，得到的钥匙编号，和杀的蛇的状态，其中杀的蛇的状态由一个数字来记录（由于蛇最多只有5条，可以状态压缩）
int dx[4]={0,0,1,-1},dy[4]={-1,1,0,0};
class Info
{   /*用于记录节点信息,坐标，时间，蛇状态，钥匙编号*/
    public:
        int x,y,t,s,id;
        Info(){}
        Info(int x_,int y_,int t_,int s_,int id_):x(x_),y(y_),t(t_),s(s_),id(id_){}
};
int bfs(Info st)
{
    int ans=inf;
    queue<Info> que;
    que.push(st);
    while(!que.empty())
    {
        Info now=que.front();
        que.pop();
        int x=now.x,y=now.y,t=now.t,s=now.s,id=now.id;
        if(id==M&&maze[x][y]=='T')
            ans=min(ans,t);
        if(dp[x][y][id][s]!=-1)
            continue;//即如果该状态已被记录
        dp[x][y][id][s]=t;//标记该状态
        for(int i=0;i<4;++i)
        {
            int newX=x+dx[i],newY=y+dy[i];
            char f=maze[newX][newY];
            int snake_id=f-'A';
            if(f=='#'||newX<=0||newY<=0||newX>N||newY>N)
                continue;
            else if(snake_id>=0&&snake_id<cnt)//判断是否有蛇
            {
                if(s&(1<<snake_id))//如果该蛇已经被杀
                    que.push(Info(newX,newY,t+1,s,id));
                else
                    que.push(Info(newX,newY,t+2,s^(1<<snake_id),id));
            }
            else if(f=='1'+id)//拿取钥匙
                que.push(Info(newX,newY,t+1,s,id+1));
            else 
                que.push(Info(newX,newY,t+1,s,id));

        }
    }
    return ans;

}
int main()
{
    while(cin>>N>>M)
    {
        if(N==0&&M==0)
            return 0;
        memset(dp,-1,sizeof(dp));
        memset(maze,0,sizeof(maze));
        cnt=0;
        int ans=inf,sx,sy;
        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
            {
                cin>>maze[i][j];
                if(maze[i][j]=='S')
                {
                    maze[i][j]='A'+cnt;
                    cnt++;//用于记录蛇的状态
                }
                if(maze[i][j]=='K')
                {
                    sx=i;
                    sy=j;
                }
            }
        ans=bfs(Info(sx,sy,0,0,0));
        if(ans==inf)
            cout<<"impossible\n";
        else
            cout<<ans<<endl;
    }
    return 0;
}