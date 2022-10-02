//
//  main.cpp
//  priority queue练习题
//
//  Created by 寿晨宸 on 2022/4/10.
//
/*
G:priority queue练习题
查看提交统计提问
总时间限制: 2500ms 内存限制: 131072kB
描述
我们定义一个正整数a比正整数b优先的含义是：
*a的质因数数目（不包括自身）比b的质因数数目多；
*当两者质因数数目相等时，数值较大者优先级高。


现在给定一个容器，初始元素数目为0，之后每次往里面添加10个元素，每次添加之后，要求输出优先级最高与最低的元素，并把该两元素从容器中删除。

输入
第一行: num (添加元素次数，num <= 30)

下面10*num行，每行一个正整数n（n < 10000000).

输出
每次输入10个整数后，输出容器中优先级最高与最低的元素，两者用空格间隔。

样例输入
1
10 7 66 4 5 30 91 100 8 9
样例输出
66 5
*/

#include <iostream>
#include<queue>
#include <set>
using namespace std;
int pnum(int n)
{
    set<int>pnums;
    int cnt=0;
    while(1)
    {
        int flag=0;
        for(int i=2;i*i<=n;++i)
        {
            if(n%i==0)
            {
                cnt++;
                pnums.insert(i);
                n=n/i;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(cnt>0)
                pnums.insert(n);
            break;
        }
        
    }
    return pnums.size();
}
struct MyLess
{
    bool operator()(int a,int b)
    {
        if(pnum(a)<pnum(b))
            return true;
        if(pnum(a)==pnum(b)&&a<b)
            return true;
        return false;
    }
};
struct MyGreater
{
    bool operator()(int a,int b)
    {
        if(pnum(a)>pnum(b))
            return true;
        if(pnum(a)==pnum(b)&&a>b)
            return true;
        return false;
    }
};

int main() {
    int n;
    cin>>n;
    priority_queue<int,vector<int>,MyLess> q;
    priority_queue<int,vector<int>,MyGreater> p;
    while(n--)
    {
        int num;
        for(int i=0;i<10;++i)
        {
            cin>>num;
            q.push(num);
            p.push(num);
        }
        cout<<q.top()<<" "<<p.top()<<endl;
        q.pop();
        p.pop();
        
    }
    return 0;
}
