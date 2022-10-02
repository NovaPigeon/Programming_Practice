/*

D:分解因数
总时间限制: 1000ms 内存限制: 65536kB
描述
给出一个正整数a，要求分解成若干个正整数的乘积，即a = a1 * a2 * a3 * ... * an，并且1 < a1 <= a2 <= a3 <= ... <= an，问这样的分解的种数有多少。注意到a = a也是一种分解。
输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a (1 < a < 32768)
输出
n行，每行输出对应一个输入。输出应是一个正整数，指明满足要求的分解的种数
样例输入
2
2
20
样例输出
1
4
*/
#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std;
int cnt=0;
void factor(int num,int t)
{
	if(num==1)
	{
		cnt++;
		return;
	}
	else
	{
		for(int i=t;i*i<=num;++i)
		{
			if(num%i==0)
				factor(num/i,i);
					
		}
		factor(1,num);
	}
}
int main()
{
	int n,num;
	cin>>n;
	while(n--)
	{
		cnt=0;
		cin>>num;
		factor(num,2);
		cout<<cnt<<endl;
	}	
	return 0;
}
