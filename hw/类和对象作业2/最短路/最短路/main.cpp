//
//  main.cpp
//  最短路
//
//  Created by 寿晨宸 on 2022/3/9.
//

#include <iostream>
using namespace  std;
int main()
{
    int dp[105][105]={0};
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>dp[i][j];
    
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            for(int j=i+1;j<=i+len-1;j++)
            {
                for(int gap=i;gap<=j;gap++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][gap]+dp[gap][j]);
                }
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
