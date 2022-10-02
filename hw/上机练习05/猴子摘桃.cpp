/*
D:猴子摘桃
查看提交统计提问
总时间限制: 10000ms 内存限制: 65536kB
描述
一只猴子正在赶路，发现了一排桃树。它想去摘桃子，但桃树上可能有马蜂。幸好它带着一罐蜂蜜。
每次它接近一个桃树时，只要给树上的每只马蜂一克蜂蜜，就可以放心经过和摘桃，不用担心了被蜇，
否则就过不了这棵树且会蜇。幸运的是，猴子可以直接跳到任意一颗桃树开始采摘，
然后就只能沿着桃树所在的直线单向走且不可跳过桃树，一旦离开桃树所在的直线就不能再回去。
请问被马蜂蜇之前，猴子最多可以摘到多少桃子。

输入
包含多个案例。每个案例的第一行是一个正整数，表示猴子所带蜂蜜的重量，单位为克，接着若干行，
每行两个整数，分别表示一颗桃树上的桃子数量和马蜂数量，每个案例的最后一行是两个-1。排在前面的桃树先输入。
输入的最后一行是-1。(桃树的数量最大为100)
输出
每个案例输出一个整数，表示猴子被马蜂蛰之前可以摘到的最大桃子数。
样例输入
50
30 25
24 8
45 17
38 20
27 8
18 5
10 20
-1 -1
-1
样例输出
128
提示
输入数据确保输入数据和计算结果均可表示为4字节的整数。
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int w;
int bee[120],peach[120];
int max_w;
int main()
{
    while(1)
    {
        cin>>w;
        if(w==-1)
            break;
        int cnt=0;
        while(1)
        {
            cin>>peach[cnt]>>bee[cnt];
            if(peach[cnt]==-1&&bee[cnt]==-1)
                break;
            cnt++;
        }
        max_w=0;
        for(int i=0;i<cnt;++i)
        {
            int sum=0,w_=w;
            for(int j=i;j<cnt;++j)
            {
                w_-=bee[j];
                if(w_<0)
                    break;
                sum+=peach[j];
            }
            max_w=max(max_w,sum);
            sum=0,w_=w;
            for(int j=i;j>=0;--j)
            {
                w_-=bee[j];
                if(w_<0)
                    break;
                sum+=peach[j];
            }
            max_w=max(max_w,sum);
        }
        cout<<max_w<<endl;

    }
    return 0;
}