/*
02:买肉付牛肉
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
补全代码，使运行结果为： Buy Nothing Pay Beef Buy Meat Pay Beef
*/
#include<iostream>
using namespace std;

class Food {
public:
// 在此处补充你的代码
public:
	void Buy(){cout<<"Buy Nothing"<<endl;}
	virtual void Pay(){}
};

class Meat : public Food {
public:
	void Buy() { cout << "Buy Meat" << endl; }
	virtual void Pay() { cout << "Pay Meat" << endl; }
};

class Beef : public Meat {
public:
	void Buy() { cout << "Buy Beef" << endl; }
	void Pay() { cout << "Pay Beef" << endl; }
};
int main() {
	Beef bf;
	Meat* pmt = &bf;
	Food* pfd = &bf;

	pfd->Buy();
	pfd->Pay();
	pmt->Buy();
	pmt->Pay();
	return 0;
}
/*
输入
无
输出
Buy Nothing
Pay Beef
Buy Meat
Pay Beef
*/