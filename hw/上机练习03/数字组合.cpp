/*
J:数字组合
总时间限制: 1000ms 内存限制: 65536kB
描述
有n个正整数，找出其中和为t(t也是正整数)的可能的组合方式。如：
n=5,5个数分别为1,2,3,4,5，t=5；
那么可能的组合有5=1+4和5=2+3和5=5三种组合方式。
输入
输入的第一行是两个正整数n和t，用空格隔开，其中1<=n<=20,表示正整数的个数，t为要求的和(1<=t<=1000)
接下来的一行是n个正整数，用空格隔开。
输出
和为t的不同的组合方式的数目。
样例输入
5 5
1 2 3 4 5
样例输出
3
*/
#include<bits/stdc++.h>
using namespace std;
 
int num[30],dp[1005];
 
int main(){
	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=t;j>=num[i];j--){
			dp[j]+=dp[j-num[i]];
		}
	}
	cout << dp[t] <<endl;
	return 0;
}
