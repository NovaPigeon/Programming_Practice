/*
08:编程填空：整数整合问题
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
写出函数中缺失的部分，使得函数返回值为一个整数,该整数的后x位和前y位与n相同，其他位和m相同。
请补全calc函数使得程序能达到上述的功能
*/
#include <iostream>
#include<bitset>
using namespace std;
unsigned int calc(unsigned int n, unsigned m, int x, int y)
{
    // 在此处补充你的代码
    unsigned int res = 0;
    unsigned int a=0;
    for(int i=0;i<32-x-y;++i)
    {
        a+=(1<<i);
    }
    a=(a<<(x));
    //cout<<(bitset<32>)n<<" "<<(bitset<32>)m<<endl;
    //cout<<(bitset<32>)a<<endl;
    unsigned int m_=m&a;
    //cout<<(bitset<32>)m_<<endl;
    unsigned int b=0xffffffff-a;
    //cout<<(bitset<32>)b<<endl;
    unsigned int n_=n&b;
    //cout<<(bitset<32>)n_<<endl;
    res=m_+n_;
    return res;
}
int main()
{
    int x, y, t;
    unsigned int n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> x >> y;
        //n=5;m=2;x=1;y=30;
        cout << calc(n, m, x, y) << endl;
    }
    //cout<<0xffffffff;
    return 0;
}
/*
输入
第一行一个整数N，表示多组测试数据。
接下去每行4个整数，分别为n, m ,x, y。 （x+y <= 32）
输出
每组测试数据，输出一个整数，表示题目中的结果。
样例输入
2
258079 4064 5 20
5 2 1 30
样例输出
262143
7
*/