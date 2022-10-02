
/*
B:Minecraft
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Minecraft是一个几乎无所不能的沙盒游戏，玩家可以利用游戏内的各种资源进行创造，搭建自己的世界。



在Minecraft中，基本的建筑元素是边长为1个单位的立方体，Tony想用N个这种小立方体搭建一个长方体，并用他珍藏已久的贴纸对其进行装饰。如果一张贴纸可以贴满小立方体的一个面。那么，他需要用掉多少张贴纸呢？

输入
一个整数N，表示小明所拥有的小立方体的个数。N不会超过1000。
输出
一个整数，即小明最少用掉的贴纸有多少张。
样例输入
9
样例输出
30
*/
#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	int N;
	int M=INT_MAX;
	cin>>N;
	for(int i=1;i<=N;++i)
	{
		if(N%i==0)
		{
			for(int j=1;j<=N/i;++j)
			{
				if((N/i)%j==0)
				{
					int k=N/(i*j); 
					//cout<<i<<" "<<j<<" "<<k<<endl;
					if(i*j*2+i*k*2+j*k*2<M)
						M=i*j*2+i*k*2+j*k*2;
				}
			}
		}
	}
	cout<<M;
	return 0;
}
