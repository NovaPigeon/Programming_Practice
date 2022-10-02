/*
B:最佳加法表达式
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，并输出该值。例如，在1234中摆放1个加号，最好的摆法就是12+34,和为36

输入
有不超过15组数据
每组数据两行。第一行是整数m，表示有m个加号要放( 0<=m<=50)
第二行是若干个数字。数字总数n不超过50,且 m <= n-1
输出
对每组数据，输出最小加法表达式的值
样例输入
2
123456
1
123456
4
12345
样例输出
102
579
15
提示
要用到高精度计算，即用数组来存放long long 都装不下的大整数，并用模拟列竖式的办法进行大整数的加法。
来源
Guo Wei
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
string num;
int N;
const int L = 1e2 + 5;
string dp[L][L];
//高精度计算
string add(string a, string b)
{
    string ans;
    int changea[L] = {0}, changeb[L] = {0};
    int la = a.size();
    int lb = b.size();
    for (int i = 0; i < la; ++i) // 翻转输进来的字符串，并存到整型数组
        changea[la - 1 - i] = a[i] - '0';
    for (int i = 0; i < lb; ++i)
        changeb[lb - 1 - i] = b[i] - '0';
    int lmax = la > lb ? la : lb;
    for (int i = 0; i < lmax; ++i)
    {
        changea[i] += changeb[i];
        changea[i + 1] += changea[i] / 10;
        changea[i] %= 10;
    }
    if (changea[lmax]) // 最高位有进位的话，字符串长度加一
        lmax++;
    for (int i = lmax - 1; i >= 0; --i)
        ans += changea[i] + '0';
    return ans;
}
string mins(string a, string b) // 判断字符串的大小
{
    if (a.length() < b.length())
        return a;
    else if (b.length() < a.length())
        return b;
    else
        return a < b ? a : b;
}
int main()
{
    //状态转移方程:dp[m][n]表示在m个数字内插入n个‘+’，则dp[m][n]=max{dp[i][n-1]+num[i+1,len]}
    while (cin >> N >> num)
    {
        num = " " + num; //为了能从1计数
        int len = num.length();
        for (int i = 0; i <= len; ++i)
            dp[i][0] = num.substr(1, i);
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j <= len; ++j)
            {
                for (int k = i; k < j; ++k)
                {
                    if (k == i)
                        dp[j][i] = add(dp[k][i - 1], num.substr(k + 1, i - k));
                    else
                        dp[j][i] = mins(dp[j][i], add(dp[k][i - 1], num.substr(k + 1, i - k)));
                }
            }
        }
        cout << dp[len][N] << endl;
    }
}
/*
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int L = 1e2 + 5;
string dp[L][L];
string add(string a, string b)
{
    string ans;
    int changea[L] = {0}, changeb[L] = {0};
    int la = a.size();
    int lb = b.size();
    for (int i = 0; i < la; ++i) // 翻转输进来的字符串，并存到整型数组
        changea[la - 1 - i] = a[i] - '0';
    for (int i = 0; i < lb; ++i)
        changeb[lb - 1 - i] = b[i] - '0';
    int lmax = la > lb ? la : lb;
    for (int i = 0; i < lmax; ++i)
    {
        changea[i] += changeb[i];
        changea[i + 1] += changea[i] / 10;
        changea[i] %= 10;
    }
    if (changea[lmax]) // 最高位有进位的话，字符串长度加一
        lmax++;
    for (int i = lmax - 1; i >= 0; --i)
        ans += changea[i] + '0';
    return ans;
}
string mins(string a, string b) // 判断字符串的大小
{
    if (a.length() < b.length())
        return a;
    else if (b.length() < a.length())
        return b;
    else
        return a < b ? a : b;
}
int main()
{
    int m;
    string s;
    while (cin >> m >> s)
    {
        s = " " + s;
        int len = s.length();
        for (int i = 0; i <= len; ++i)
            dp[i][0] = s.substr(1, i); //  从当前的1位置截取长度为i的字符串
        for (int j = 1; j <= m; ++j)
        {
            for (int i = 0; i <= len; ++i)
            {
                for (int x = j; x < i; ++x)
                {

                    if (x == j)
                        dp[i][j] = add(dp[x][j - 1], s.substr(x + 1, i - x));

                    else
                        dp[i][j] = mins(dp[i][j], add(dp[x][j - 1], s.substr(x + 1, i - x)));
                }
            }
        }
        cout << dp[len][m] << endl;
    }
    return 0;
}
*/