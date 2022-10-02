/*
0004:编程填空：输出指定结果
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
填写代码，按要求输出结果
*/
#include <iostream>
using namespace std;

class A {
public:
// 在此处补充你的代码
    int val;
    A(int val_):val(val_){}
    A(const A& b){val=b.val;}
    friend ostream& operator<<(ostream& os,A a)
    {
        os<<a.val;
        return os;
    }
    A& operator=(int k)
    {
        val=k;
        return *this;
    }
    A& getValue()
    {
        return *this;
    }
    A& operator+=(A& b)
    {
        val=val+b.val;
        return *this;
    }
    A& operator-=(int k)
    {
        val=val-k;
        return *this;
    }
};

int main() {
	int t;
	cin >> t;
	while(t-- ) {
		int m,n,k;
		cin >> m >> n >> k;	
	    A a(m);
	    A b = a;
	    cout << b << endl;
	    cout << (a += b -= n) << endl;
	    cout << a.getValue() << endl;
	    a.getValue() = k;
	    cout << a << endl;
	} 
	return 0;
}
/*
输入
第一行是数据组数 t
每组数据1行，包含三个整数 m ,n , k
输出
对每组数据，输出4行，分别是：
m
2m-n
2m-n
k
样例输入
1
3 2 10
样例输出
3
4
4
10
*/