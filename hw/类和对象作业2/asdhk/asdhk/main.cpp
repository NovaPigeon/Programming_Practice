//
//  main.cpp
//  asdhk
//
//  Created by 寿晨宸 on 2022/3/9.
//

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int a[100],b[100],c[100],d[100];
//a数组表示的是行；
//b数组表示的是列；
//c表示的是左下到右上的对角线；
//d表示的是左上到右下的对角线；
int total=0;//总数:记录解的总数
int n,bf;
    void queen(int i)
{
    if(i>8)
    {
        total++;
    if(total==bf)
    {
        for(int k=1;k<=8;k++)
        cout<<a[k]<<" ";
        
    }
        return;
    }
    else
    {
        for(int j=1;j<=8;j++)//尝试可能的位置
        {
            if((!b[j])&&(!c[i+j])&&(!d[i-j+8]))//如果没有皇后占领，执行以下程序
            {
                a[i]=j;//标记i排是第j个
                b[j]=1;//占领纵列
                c[i+j]=1;
                d[i-j+8]=1;
                //占领两条对角线
                queen(i+1);//进一步搜索，下一个皇后
                b[j]=0;
                c[i+j]=0;
                d[i-j+8]=0;
                //（回到上一步）清除标记
            }
        }
    }
}
int main()
{
int y1,y2;
 cin>>y1>>y2;
a[1]=y1;a[2]=y2;
b[y1]=1;b[y2]=1;
c[1+y1]=1;d[1-y1+8]=1;
c[2+y2]=1;d[2-y2+8]=1;
        bf=1;
        total=0;
        queen(3);
    return 0;
}
