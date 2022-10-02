
/*
06:输出Fibonacci数列
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Fibonacci数列指的是数列第一项和第二项为1，之后每一项是之前两项的和所构成的数列。 现有多组数据，每组数据给出一个数字n，请你输出Fibonacci数列的前n-1项。
*/
#include <iostream>
#include <iterator>
using namespace std;
template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
// 在此处补充你的代码
class Fib
{
public:
    static int val[1000];
    int position;
    Fib(int position_):position(position_)
    {
        memset(val,0,sizeof(val));
        val[0]=0;
        val[1]=1;
        val[2]=1;
        for(int i=3;i<position;++i)
        {
            val[i]=val[i-1]+val[i-2];
        }
    }
    int& operator*()
    {
        return val[position];
    }
    bool operator!=(const Fib& b)
    {
        return position!=b.position;
    }
    Fib& operator++()
    {
        position++;
        return *this;
    }
};
int Fib::val[1000];
int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == 0)
			break;
		
	    Fib f1(1), f2(n);
	    ostream_iterator<int> it(cout, " ");
	    Copy(f1, f2, it);
	    cout << endl;
	}
	return 0;
}
/*
输入
每组数据一行，整数n
输入以0结尾
输出
对每组数据输出前 n-1项
样例输入
3
0
样例输出
1 1
*/