/*
A:篮球联赛
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
校篮球队每年都会举办“年级联赛”。篮球队的队员们将根据年级分为一年级、二年级、三年级和四年级4支队伍，参与角逐。

在年级联赛中，不同队伍两两之间比赛一场，胜者积1分，负者积0分（篮球比赛无平局）。
最终队伍将按照积分从高到低排名，若出现同分，则年级较低的排名靠前。

现在年级联赛正在进行中，有些比赛已经结束，有些比赛则因种种原因还未进行。
请你根据当前的比赛情况，计算出一年级队在联赛结束后，有可能得到的最高名次。

输入
输入包含多组数据。第一行是一个整数T(1 <= T <= 100)，表示数据组数。

对于每组数据，用一个4*4的字符矩阵表示当前的比赛情况。第i行第j列表示i年级与j年级的比赛情况，其中：
“-”表示i与j相同，无比赛
“W”表示i年级胜j年级
“L”表示i年级负j年级
“?”表示i年级和j年级的比赛还未进行

输入数据保证正确不存在矛盾，且无多余空格或空行。
输出
对于每组数据，输出一个整数，即一年级队在联赛结束后，有可能获得的最高名次。
样例输入
2
-LL?
W-L?
WW-L
??W-
-WL?
L-?L
W?-L
?WW-
样例输出
3
1
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int T,score[5]={0};
int dx[3]={2,2,3};
int dy[3]={3,4,4};
char cs[5][5];
int r=4;
int ans()
{
    int res=1;
    memset(score,0,sizeof(score));
    for(int i=1;i<=4;++i)
        for(int j=i+1;j<=4;++j)
        {
            if(cs[i][j]=='W')
                score[i]++;
            else if(cs[i][j]=='L')
                score[j]++;
        }
    for(int i=1;i<=4;++i)
        if(score[i]>score[1])
            res++;
    return res;

}
void dfs(int depth)
{
    if(depth==3)
    {
        r=min(r,ans());
        return;
    }
    int newX=dx[depth];
    int newY=dy[depth];
    if(cs[newX][newY]=='?')
    {
        cs[newX][newY]='W';
        dfs(depth+1);
        cs[newX][newY]='L';
        dfs(depth+1);
        cs[newX][newY]='?';
    }
    else 
        dfs(depth+1);
}
int main()
{
    cin>>T;
    while(T--)
    {
        r=4;
        memset(score,0,sizeof(score));
        for(int i=1;i<5;++i)
            for(int j=1;j<5;++j)
            {
                cin>>cs[i][j];
            }
        for(int i=2;i<=4;++i)
            if(cs[1][i]=='?')
                cs[1][i]='W';
        dfs(0);
        cout<<r<<endl;
        
    }

    return 0;
}