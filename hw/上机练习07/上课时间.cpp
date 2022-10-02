/*
07A:上课时间
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
小 A 修了 n 门课程, 第 i 门课程是从第 ai 天一直上到第 bi 天。

定义两门课程的冲突程度为 : 有几天是这两门课程都要上的。

例如 a1=1,b1=3,a2=2,b2=4 时, 这两门课的冲突程度为 2。

现在你需要求的是这 n 门课中冲突程度最大的两门课的冲突程度。
输入
第一行一个正整数 n 表示课程数量。
接下来 n 行,每行两个正整数 ai,bi。
2 ≤ n≤ 1000, 1 ≤ ai ≤ bi ≤ 1000。
输出
输出一个整数表示最大的冲突程度
样例输入
3
1 3
2 4
5 5
样例输出
2
*/
#include<iostream>
#include<math.h>
using namespace std;
int n,st[1005],ed[1005];
int mx=0;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>st[i]>>ed[i];
    for(int i=0;i<n-1;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int t=0;
            if(ed[i]<st[j]||ed[j]<st[i])
                t=0;
            else
            {
                if(st[i]<=st[j]&&ed[i]>=ed[j])
                    t=ed[j]-st[j]+1;
                if(st[j]<=st[i]&&ed[j]>=ed[i])
                    t=ed[i]-st[i]+1;
                if(st[j]<st[i]&&ed[j]<ed[i])
                    t=ed[j]-st[i]+1;
                if(st[i]<st[j]&&ed[i]<ed[j])
                    t=ed[i]-st[j]+1;
            }
            mx=max(mx,t);
        }
    }
    cout<<mx;
    return 0;
}