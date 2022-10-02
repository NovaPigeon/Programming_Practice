
/*
B:Pots

描述
You are given two pots, having the volume of A and B liters respectively. The following operations can be performed:



FILL(i)        fill the pot i (1 ≤ i ≤ 2) from the tap;

DROP(i)      empty the pot i to the drain;

POUR(i,j)    pour from pot i to pot j; after this operation either the pot j is full (and there may be some water left in the pot i), or the pot i is empty (and all its contents have been moved to the pot j).


Write a program to find the shortest possible sequence of these operations that will yield exactly C liters of water in one of the pots.

输入
On the first and only line are the numbers A, B, and C. These are all integers in the range from 1 to 100 and C≤max(A,B).

输出
The first line of the output must contain the length of the sequence of operations K. The following K lines must each describe one operation. If there are several sequences of minimal length, output any one of them. If the desired result can’t be achieved, the first and only line of the file must contain the word ‘impossible’.

样例输入
3 5 4
样例输出
6
FILL(2)
POUR(2,1)
DROP(1)
POUR(2,1)
FILL(2)
POUR(2,1)
*/
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
const int inf=INT_MAX;
int vis[120][120]={0};//用于记录已走过的状态
int A,B,C;
class Info
{
    public:
        int sa,sb,step;
        vector<string>move;
};
queue<Info> que;
Info bfs()
{
    int ans=inf;
    Info cur,tmp;
    cur.sa=0;cur.sb=0;cur.step=0;
    vis[0][0]=1;
    que.push(cur);
    while(!que.empty())
    {
        Info cur=que.front();
        que.pop();
        if(cur.sa==C||cur.sb==C)
            return cur;
        //FILL(1)
        tmp=cur;
        tmp.sa=A;
        if(!vis[tmp.sa][tmp.sb])
        {
            vis[tmp.sa][tmp.sb]=1;
            tmp.step++;
            tmp.move.push_back("FILL(1)");
            que.push(tmp);
        }
        //FILL(2)
        tmp=cur;
        tmp.sb=B;
        if(!vis[tmp.sa][tmp.sb])
        {
            vis[tmp.sa][tmp.sb]=1;
            tmp.step++;
            tmp.move.push_back("FILL(2)");
            que.push(tmp);
        }
        //DROP(1)
        tmp=cur;
        tmp.sa=0;
        if(!vis[tmp.sa][tmp.sb])
        {
            vis[tmp.sa][tmp.sb]=1;
            tmp.step++;
            tmp.move.push_back("DROP(1)");
            que.push(tmp);
        }
        //DROP(2)
        tmp=cur;
        tmp.sb=0;
        if(!vis[tmp.sa][tmp.sb])
        {
            vis[tmp.sa][tmp.sb]=1;
            tmp.step++;
            tmp.move.push_back("DROP(2)");
            que.push(tmp);
        }
        //POUR(1,2)
        tmp=cur;
        if(B-cur.sb<=cur.sa)
        {
            tmp.sb=B;
            tmp.sa=cur.sa-(B-cur.sb);
        }
        else
        {
            tmp.sb=cur.sb+cur.sa;
            tmp.sa=0;
        }
        if(!vis[tmp.sa][tmp.sb])
        {
            vis[tmp.sa][tmp.sb]=1;
            tmp.step++;
            tmp.move.push_back("POUR(1,2)");
            que.push(tmp);
        }
        tmp=cur;
        if(A-cur.sa<=cur.sb)
        {
            tmp.sa=A;
            tmp.sb=cur.sb-(A-cur.sa);
        }
        else
        {
            tmp.sa=cur.sa+cur.sb;
            tmp.sb=0;
        }
        if(!vis[tmp.sa][tmp.sb])
        {
            vis[tmp.sa][tmp.sb]=1;
            tmp.step++;
            tmp.move.push_back("POUR(2,1)");
            que.push(tmp);
        }
    }
    Info fail;
    fail.step=inf;
    return fail;
}
int main()
{
    cin>>A>>B>>C;
    Info ans;
    ans=bfs();
    if(ans.step==inf)
        cout<<"impossible\n";
    else
    {
        cout<<ans.step<<endl;
        int len=ans.move.size();
        for(int i=0;i<len;++i)
            cout<<ans.move[i]<<endl;
    }

}