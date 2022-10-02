/*
请写出sum函数，使其可以计算输入数列的平方和。

输入
第一行是一个整数 t (t <= 10)，表示数据组数；
每组输入数据包含两行，第一行是一个整数 n (n <= 100)，
第二行是 n 个用空格分隔开的整数
输出
对每组输入数据，输出该组数据中 n 个整数的平方和
样例输入
2
2
4 3
3
0 1 2
样例输出
25
5

*/
#include <iostream>
using namespace std;



//your code starts here

int sum (int * p,int n, int ( * func) (int )) 
{
	int result = 0;
	for(int i = 0;i < n; ++i)
		result += func(p[i]);
	return result;
}

//your code ends here

int sqr(int n) {
    return n * n;
}
int main() {
    int t, n, a[0x100];
    cin >> t;
    for (int c = 0; c < t; ++c) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << sum(a, n, sqr) << endl;
    }
    return 0;
}
