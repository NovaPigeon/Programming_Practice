/*
C:派
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
我的生日要到了！根据习俗，我需要将一些派分给大家。我有N个不同口味、不同大小的派。
有F个朋友会来参加我的派对，每个人会拿到一块派（必须一个派的一块，不能由几个派的小块拼成；可以是一整个派）。
我的朋友们都特别小气，如果有人拿到更大的一块，就会开始抱怨。
因此所有人拿到的派是同样大小的（但不需要是同样形状的），虽然这样有些派会被浪费，但总比搞砸整个派对好。
当然，我也要给自己留一块，而这一块也要和其他人的同样大小。
请问我们每个人拿到的派最大是多少？每个派都是一个高为1，半径不等的圆柱体。

输入
第一行包含两个正整数N和F，1 ≤ N, F ≤ 10 000，表示派的数量和朋友的数量。
第二行包含N个1到10000之间的整数，表示每个派的半径。
输出
输出每个人能得到的最大的派的体积，精确到小数点后三位。
样例输入
3 3
4 3 3
样例输出
25.133
*/
#include<iostream>
#include<cmath>
using namespace std;
const double pi=acos(-1.0),EPS=1e-5;
//二分法
bool judge(double v_cut,double* v,int n,int f)
{
    int cnt=0;
    for(int i=0;i<n;++i)
        cnt+=int(v[i]/v_cut);//每块pi最多能分给v/v_cut个人
    if(cnt>=f)//若能分的人总数大于f，则说明pi还有再分的余地，v_cut增加，否则v_cut减少
        return true;
    else
        return false;
}
int main()
{
    int N,F,r;
    double v[10010],v_max=0;
    cin>>N>>F;
    F++;
    for(int i=0;i<N;++i)
    {
        cin>>r;
        v[i]=r*r*pi;//略去常数pi
        v_max=max(v_max,v[i]);
    }
    double L=0,R=v_max,mid;//v_cut最小为0，最大为v_max
    while(R-L>EPS)
    {
        mid=(R+L)/2;
        if(judge(mid,v,N,F))
            L=mid;
        else
            R=mid;
    }
    printf("%.3lf",mid);
    return 0;
}