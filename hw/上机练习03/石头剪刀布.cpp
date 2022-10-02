
/* 
A:石头剪刀布
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
石头剪刀布是常见的猜拳游戏。石头胜剪刀，剪刀胜布，布胜石头。如果两个人出拳一样，则不分胜负。

一天，小A和小B正好在玩石头剪刀布。已知他们的出拳都是有周期性规律的，比如：“石头-布-石头-剪刀-石头-布-石头-剪刀……”，就是以“石头-布-石头-剪刀”为周期不断循环的。请问，小A和小B比了N轮之后，谁赢的轮数多？

输入
输入包含三行。
第一行包含三个整数：N，NA，NB，分别表示比了N轮，小A出拳的周期长度，小B出拳的周期长度。0 < N,NA,NB < 100。
第二行包含NA个整数，表示小A出拳的规律。
第三行包含NB个整数，表示小B出拳的规律。
其中，0表示“石头”，2表示“剪刀”，5表示“布”。相邻两个整数之间用单个空格隔开。
输出
输出一行，如果小A赢的轮数多，输出A；如果小B赢的轮数多，输出B；如果两人打平，输出draw。
样例输入
10 3 4
0 2 5
0 5 0 2
样例输出
A
提示
对于测试数据，猜拳过程为：
A：0 2 5 0 2 5 0 2 5 0
B：0 5 0 2 0 5 0 2 0 5
A赢了4轮，B赢了2轮，双方打平4轮，所以A赢的轮数多。
*/
#include<iostream>
using namespace std;
int main()
{
	int N,NA,NB;
	int cntA=0,cntB=0;
	int low[2][200]={0};
	cin>>N>>NA>>NB;
	for(int i=1;i<NA;++i)
		cin>>low[0][i];
	cin>>low[0][0];
	for(int i=1;i<NB;++i)
		cin>>low[1][i];
	cin>>low[1][0];
	for(int i=1;i<=N;++i)
	{
		int a=low[0][i%NA];
		int b=low[1][i%NB];
		if(a==0&&b==2)
			cntA++;
		if(a==0&&b==5)
			cntB++;
		if(a==2&&b==0)
			cntB++;
		if(a==2&&b==5)
			cntA++;
		if(a==5&&b==0)
			cntA++;
		if(a==5&&b==2)
			cntB++;
	}
	if(cntA==cntB)
		cout<<"draw";
	else if(cntA>cntB)
		cout<<"A";
	else
		cout<<"B";
	//cout<<cntA<<" "<<cntB;
	return 0;
}
