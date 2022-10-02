/*
通过填空使得程序输出的结果符合下面的要求。

输入
不需要输入。
输出
使得程序的输出结果是：
2
3
B::destructor
A::destructor
3
4
B::destructor
A::destructor
3
B::destructor
A::destructor
A::destructor
A::destructor
样例输入
不需要输入。
样例输出
2
3
B::destructor
A::destructor
3
4
B::destructor
A::destructor
3
B::destructor
A::destructor
A::destructor
A::destructor
提示
int A::count = 0; 这个变量是用来记录一共有多少个类A及类A的派生类的对象的。

*/
#include <iostream>
#include <map>
using namespace std;
//your code starts here
struct A {
	static int count;
	int v;
	A(int v_= 0):v(v_) { ++count;}
	virtual ~A() { -- count; cout << "A::destructor" << endl;}
	A(const A & a):v(a.v) {
		++count;
	}
};
struct B:public A
{
	
	//派生类的缺省复制构造函数会调用基类的复制构造函数
	~B() { cout << "B::destructor" << endl;}
	B(int v):A(v) { }
		
};
//your code ends here
int A::count = 0;
void func(B b) {  }
int main()
{
	A a1(5),a2;
	cout << A::count << endl;
	B b1(4);
	cout << A::count << endl;
	func(b1);
	cout << A::count << endl;
	A * pa = new B(4);
	cout << A::count << endl;
	delete pa;
	cout << A::count << endl;
	return 0;
}
