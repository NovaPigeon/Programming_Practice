/*
F:42点
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
42是：

·组合数学上的第5个卡特兰数

·字符'*'的ASCII码

·钼的原子序数

·6与9的乘积结果的13进制表示

·生命、宇宙以及任何事情的终极答案

·以及……表达式(1+5)/2*(6-4)*7的值

因此，小机器人Marvin发明了这个叫42点的小游戏。在这个游戏中，玩家会获得n个数。玩家需要使用'+'、'-'、'*'、'/'、'('、')'以及这n个数构成一个合法的中缀表达式，并使得该表达式的值为42。n个数之间的顺序可以改变。表达式运算过程中只能出现整数。

由于过于抑郁，Marvin无力完成这个游戏，于是来找你帮忙。你的任务是对于给定的n个数，判断他们是否能根据上述游戏规则算出42。

输入
第一行为一个数n，1<=n<=6。
第二行为n个数，每个数均为[1,13]范围内的整数。
输出
输出一行，若可以算出42则输出“YES”，否则输出“NO”（注意大小写）。
样例输入
6
1 5 2 6 4 7
样例输出
YES
*/
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int n, num[7] = {0}, flag[7] = {0}, is_success = 0;
void dfs(int depth, int res)
{
    if (depth == n)
    {
        if (res == 42)
            is_success = 1;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (flag[i] == 0)
        {
            flag[i] = 1;
            dfs(depth + 1, res * num[i]);
            dfs(depth + 1, res + num[i]);
            dfs(depth + 1, res - num[i]);
            if (res % num[i] == 0)
                dfs(depth + 1, res / num[i]);
            flag[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    for (int i = 0; i < n; ++i)
    {
        flag[i] = 1;
        dfs(1, num[i]);
    }
    if (is_success == 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}