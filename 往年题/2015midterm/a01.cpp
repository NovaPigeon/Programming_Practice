/*
使以下代码输出结果为200.

输入
不需要输入。
输出
输出结果为200。
样例输入
不需要输入。
样例输出
200

*/
#include<iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n=0): num(n) {}
//your code starts here    
    int operator * (const Number & n) {
    	return Number(num * n.num);
	}
	operator int() {
		return num;
	}
//your code ends here	
};

int main() {
    Number n1(10), n2(20);
    Number n3;
    n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}
