/*
07B:网线主管
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
仙境的居民们决定举办一场程序设计区域赛。裁判委员会完全由自愿组成，他们承诺要组织一次史上最公正的比赛。他们决定将选手的电脑用星形拓扑结构连接在一起，即将它们全部连到一个单一的中心服务器。为了组织这个完全公正的比赛，裁判委员会主席提出要将所有选手的电脑等距离地围绕在服务器周围放置。

为购买网线，裁判委员会联系了当地的一个网络解决方案提供商，要求能够提供一定数量的等长网线。裁判委员会希望网线越长越好，这样选手们之间的距离可以尽可能远一些。

该公司的网线主管承接了这个任务。他知道库存中每条网线的长度（精确到厘米），并且只要告诉他所需的网线长度（精确到厘米），他都能够完成对网线的切割工作。但是，这次，所需的网线长度并不知道，这让网线主管不知所措。

你需要编写一个程序，帮助网线主管确定一个最长的网线长度，并且按此长度对库存中的网线进行切割，能够得到指定数量的网线。

输入
第一行包含两个整数N和K，以单个空格隔开。N（1 <= N <= 10000）是库存中的网线数，K（1 <= K <= 10000）是需要的网线数量。
接下来N行，每行一个数，为库存中每条网线的长度（单位：米）。所有网线的长度至少1m，至多100km。输入中的所有长度都精确到厘米，即保留到小数点后两位。
输出
网线主管能够从库存的网线中切出指定数量的网线的最长长度（单位：米）。必须精确到厘米，即保留到小数点后两位。
若无法得到长度至少为1cm的指定数量的网线，则必须输出“0.00”（不包含引号）。
样例输入
4 11
8.02
7.43
4.57
5.39
样例输出
2.00
来源
Northeastern Europe 2001
查看 提交 统计 提问
全局题号
66
提交次数
721
尝试人数
117
通过人数
108
*/
#include<iostream>
#include<math.h>
using namespace std;
int N,K;
int len[10005],L,R,mid,mx=0;
double d,eps=0.9;
int main()
{
    cin>>N>>K;
    for(int i=0;i<N;++i)
    {
        cin>>d;
        len[i]=d*100;
        mx=max(mx,len[i]);
    }
    L=0;
    R=mx;
    double ans=0;
    while(R>L)
    {
        int s=0;
        mid=(R+L+1)/2;
        for(int i=0;i<N;++i)
            s+=(len[i]-len[i]%mid)/mid;
        if(s>=K)
        {
            L=mid;
            ans=mid;
        }
        else 
            R=mid-1;
    }
    if(ans<1)
        cout<<"0.00";
    else 
    {
        printf("%.2f",ans/100);
    }
    
    return 0;
}