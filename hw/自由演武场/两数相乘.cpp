/*
0001:编程填空：两数相乘
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
完善程序，使按指定方式输出
*/
#include <iostream>
using namespace std;
class Number 
{
public: 
    int num;
    Number(int n): num(n) {}
// 在此处补充你的代码
    friend Number operator*(Number n_,int n)
    {
        return Number(n*n_.num);
    }
    Number(const Number& b)
    {
        num=b.num;
    }
    friend bool operator==(int n,Number n_)
    {
        return n==n_.num;
    }
    friend ostream& operator<<(ostream& os,Number n)
     {
         os<<n.num;
         return os;
     }
};
int main() {
	int t;
	int m,n;
	cin >> t;
	while(t--) {
	    cin >> m>> n;
	    Number n1(m), n2 = n1 * n;
	    if( m * n == n2 )
	    	cout << n2 << endl;
	}
    return 0;
}
/*输入
第一行是数据组数t
每组数据1行，为两个整数 m 和 n
输出
对每组数据，输出 m * n
样例输入
2
2 5
3 8
样例输出
10
24
*/
