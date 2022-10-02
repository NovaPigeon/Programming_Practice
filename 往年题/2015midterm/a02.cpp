/*
填写代码，使输出结果为

2

2

8

10

输入
不需要输入。
输出
使输出结果为
2
2
8
10
样例输入
不需要输入。
样例输出
2
2
8
10

*/
#include <iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n): num(n) {
    }
//your code starts here    
	int & value() { return num; }
	void operator + (const Number & n) {
		num += n.num;
	}
	
//your code ends here
};
int main() {
    Number a(2);
    Number b = a;
    cout << a.value() << endl;
    cout << b.value() << endl;
    a.value() = 8;
    cout << a.value() << endl;
    a+b;
    cout << a.value() << endl;
    return 0;
}
