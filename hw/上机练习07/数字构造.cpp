/*
07E:数字构造
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
火山宝打算造一个 n 位的十进制数字出来。

对于 1 到 n 中的每一个 i，火山宝可以从 xi,1, ..., xi,ki 这 ki 个 0-9 的数字中选择一个作为 ai。

在选择结束后，a1a2...an 形成了一个 n 位的十进制数——这就是火山宝造出来的数。

你需要帮火山宝计算他能造出的数中，有多少个是 3 的倍数。
输入
第一行输入一个整数 n(1 ≤ n ≤ 18)，表示数字的位数。

接下来 n 行，每行第一个整数 ki (1 ≤ ki ≤ 10)，表示第 i 中候选的数字数量。接着是 ki 个两两不同的 0-9 范围内的数字 xi,1, ..., xi,ki。

输入保证 0 不是第一位的可选项。
输出
你需要输出一行一个整数，表示火山宝能造出的数字中，3 的倍数的数量。
样例输入
样例输入1：
2
5 5 6 7 8 9
5 0 1 2 3 4

样例输入2：
5
9 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9

15
9 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
9 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
9 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
10 0 1 2 3 4 5 6 7 8 9
样例输出
样例输出1:
9

样例输出2:
30000
*/
#include<iostream>
#include<ctime>
using namespace std;
int flag[20][20]={0};
int cnt,n,num[20][20]={0},k[20]={0};
void dfs(int s,int depth)
{
    if(depth==n)
    {
        if(s%3==0)
            cnt++;
        return;
    }
    int len=k[depth];
    for(int i=0;i<len;i++)
    {
        if(flag[depth][i]==0)
        {
            flag[depth][i]=1;
            dfs(s+num[depth][i],depth+1);
            flag[depth][i]=0;
        }
    }
}
int main()
{
    time_t begin,end;
    double ret;
    begin =clock();
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>k[i];
        for(int j=0;j<k[i];++j)
        {
            cin>>num[i][j];
            num[i][j]%=3;
        }
    }
    dfs(0,0);
    cout<<cnt;
    end =clock();
    ret =double(end-begin)/CLOCKS_PER_SEC;
    cout<<"\n"<<ret;
    return 0;
}