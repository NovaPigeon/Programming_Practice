/*
描述
输入整数 n ( 0 <=n<= 2^30) , 以及整数i,j(0 <= i,j <31,i < j-1), 输出整数k(按十六进制输出结果 )，k的第i位和n相同，第j位和n不同，i,j之间的位是1, 其他位都是0。这里提到的所有的位，指的都是二进制位，最右边算第0位。

输入
第一行是整数 t，表示数据组数。
每组输入数据是一行，三个整数 n,i和j。
输出
对每组输入数据，按十六进制输出结果。
样例输入
2
23 3 5 
7 0 2
样例输出
30
3
*/
#include <iostream>
#include <string>
#include <list>
using namespace std;

inline void SetBit(int & n,int i,int v)
{
	if( v )  
		n |= (1 << i);
	else
		n &= ~(1 << i); 
} 
inline int GetBit(int n, int i)
{
	return (n >> i) & 1;
}
int main()
{
	int n,i,j;
	int t;
	cin >> t;
	while( t --) {
		cin >> n >> i >> j;
		int tmp = (0xffffffff << i) & (0xffffffff >> (31-j));
		SetBit(tmp,i,GetBit(n,i));
		if( GetBit(n,j) ) 
			SetBit(tmp,j,0);
		else
			SetBit(tmp,j,1);
		cout << hex << tmp << endl;
	}
	return 0;
}
