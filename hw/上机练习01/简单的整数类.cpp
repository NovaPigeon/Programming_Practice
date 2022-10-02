
/*
03:简单的整数类
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入两个数 m,n( 0<=m,n <= 9)，输出它们的乘积
*/
#include <stdio.h>
#include <iostream>
using namespace std;
class MyNum{
public:
    char C;
    MyNum(char c='0'): C(c) {}
// 在此处补充你的代码
    friend MyNum operator*(const MyNum&a,const MyNum&b)
    {
        return MyNum((a.C-'0')*(b.C-'0')+'0');
    }
    operator int()
    {
        return C-'0';
    }
};

int main() { 
    char m,n;
    cin >> m >>  n;
    MyNum n1(m), n2(n);
    MyNum n3;
    n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}
/*
输入
两个数，m,n，确保乘积小于10
输出
它们的乘积
样例输入
3 2
样例输出
6
*/