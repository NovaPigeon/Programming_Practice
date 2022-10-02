/*
B:特殊密码锁
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。
然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。
当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。
输入
两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。
输出
至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
样例输入
011
000
样例输出
1
*/
#include<iostream>
#include<cmath>
#include<climits>
#include<cstring>
using namespace std;
char str[50];
char str_target[50];
int button[50]={0};
int button_target[50]={0};
int main()
{
    cin>>str>>str_target;
    int n=strlen(str);
    int cnt[2]={0};
    int flag_=0;
    int res[2][50]={0};
    for(int i=0;i<n;++i)
    {
        button[i]=str[i]-'0';
        button_target[i]=str_target[i]-'0';
    }
    for(int i=0;i<2;++i)
    {
        res[i][0]=i;
        bool flag=true;
        int temp[50]={0};
        for(int i=0;i<n;++i)
            temp[i]=button[i];
        temp[0]=(temp[0]+res[i][0])%2;
        temp[1]=(temp[1]+res[i][0])%2;
        for(int j=1;j<n;++j)
        {
            res[i][j]=(button_target[j-1]+2-temp[j-1])%2;
            temp[j-1]=(temp[j-1]+res[i][j])%2;
            temp[j]=(temp[j]+res[i][j])%2;
            temp[j+1]=(temp[j+1]+res[i][j])%2;
        }
        for(int j=0;j<n;++j)
        {
            if(temp[j]!=button_target[j])
            {
                flag=false;
                cnt[i]=INT_MAX;
                break;
            }
        }
        if(flag)
        {
            flag_++;
            for(int j=0;j<n;++j)
                cnt[i]+=res[i][j];
        }
    }
    int min_cnt=min(cnt[0],cnt[1]);
    if(flag_==0)
        cout<<"impossible";
    else
        cout<<min_cnt;
    return 0;
}