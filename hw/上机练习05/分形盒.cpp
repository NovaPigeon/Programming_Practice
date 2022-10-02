/*
E:分形盒
查看提交统计提问
总时间限制: 1000ms 内存限制: 30000kB
描述
分形，通常被定义为一个粗糙或零碎的几何形状，可以分成数个部分，
且每一部分都（至少近似地）是整体缩小后的形状，即具有自相似的性质。
它跟分数维、自组织、非线性系统和混沌等具有非常重要的联系。

分形盒就是这样一种分形，它的定义如下：

维度是1的分形盒：

X

维度是2的分形盒：

X  X

  X

X  X

如果已知维度是(n-1)的分形盒，那么维度是n的分形盒的递归定义如下所示：

Box(n-1)               Box(n-1)

              Box(n-1)

Box(n-1)               Box(n-1)  

你的任务是画一个维度为n的分形盒。

输入
输入包含多组测试数据。每一行包含一个正整数n表示分形盒的维度，n不大于7；最后一行是一个-1，表示输入结束。
输出
对于每组测试数据，输出要求维度的分形盒，注意X为大写字母。每组测试数据之后包含一行，改行只包含一个破折号。
样例输入
1
2
3
4
-1
样例输出
X
-
X X
 X
X X
-
X X   X X
 X     X
X X   X X
   X X
    X
   X X
X X   X X
 X     X
X X   X X
-
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
   X X               X X
    X                 X
   X X               X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
         X X   X X
          X     X
         X X   X X
            X X
             X
            X X
         X X   X X
          X     X
         X X   X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
   X X               X X
    X                 X
   X X               X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
-
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int n;
char pic[900][900];
int pow_(int base,int k)
{
    int ans=1;
    for(int i=0;i<k;++i)
        ans*=base;
    return ans;
}
void draw(int x,int y,int n)
{
    if(n==1)
        pic[x][y]='X';
    else
    {
        draw(x,y,n-1);
        draw(x-pow(3,n-2),y-pow(3,n-2),n-1);
        draw(x+pow(3,n-2),y-pow(3,n-2),n-1);
        draw(x-pow(3,n-2),y+pow(3,n-2),n-1);
        draw(x+pow(3,n-2),y+pow(3,n-2),n-1);
    }
}
void print_pic(int n)
{
    int len=pow(3,n-1);
    for(int i=1;i<=len;++i)
    {
        for(int j=1;j<=len;++j)
            cout<<pic[i][j];
        cout<<endl;
    }
    cout<<"-"<<endl;
}
int main()
{
    while(cin>>n)
    {
        if(n==-1)
            break;
        int w=(pow(3,n-1)+1)/2;
        memset(pic,' ',sizeof(pic));
        draw(w,w,n);
        print_pic(n);
    }
}