
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define N 1010
int t,dp[N][N];
string s1,s2;

int main()
{
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin.ignore();
		cin>>s1>>s2;
		s1=" "+s1;
		s2=" "+s2;
		for(int i=0;i<max(s1.length(),s2.length());i++) dp[i][0]=dp[0][i]=i;
		for(int i=1;i<s1.length();i++){
			for(int j=1;j<s2.length();j++){
				if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1];
				else{
					dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				}
			}
		}
		cout<<dp[s1.length()-1][s2.length()-1]<<endl;
	}
	return 0;
} 
