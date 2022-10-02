/*
10:编程填空：MySet模板
查看提交统计提问
总时间限制: 2000ms 内存限制: 131072kB
描述
程序填空，从set模板派生一个MySet模板  并按要求输出
*/
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector> 
#include <set>
#include <cstdio>
using namespace std;
// 在此处补充你的代码
template <class T>
class MySet
{
private:
    set<T>mst;
public:
    typedef typename set<T>::iterator i;
    void insert(const T& obj){mst.insert(obj);}
    i begin(){return mst.begin();}
    i end(){return mst.end();}
    void erase(i i1){mst.erase(i1);}
    i find(T obj){return mst.find(obj);}
    void erase(T* i1,T*i2){erase(i1,i2);}
    void erase(i i1,i i2){mst.erase(i1,i2);}
};
struct A {
	int n;
	A(int i):n(i) { }
	operator int() {
		return n;
	}
	bool operator >(const A & a) const {
		return n > a.n;
	}
};
template <class IT>
void print(IT s,IT e)
{	
	for(; s != e; ++s)
		cout << *s << ",";
	cout << endl;
}
int main()
{
	MySet<int> mst;
	for (int i = 0;i < 10; ++i)
		mst.insert(i);
	print(mst.begin(),mst.end());
	int a[] = {1,2,3,4};
	mst.erase(a,a+3);
	print(mst.begin(),mst.end());
	
	A b[] = {A(7),A(8)};
	mst.erase(b,b+2);
	print(mst.begin(),mst.end());	
	mst.erase(mst.find(6));
	print(mst.begin(),mst.end());
	for(int i = 0;i < 1000000; ++i)
		mst.insert(i);
	for(int i = 0; i < 1000000 - 10; ++i) 
		mst.erase(mst.find(i));
	int n;
	cin >> n;
	MySet<A> msta;
	
	for(int i = 0;i < n; ++i) {
		string cmd;
		int n;
		cin >> cmd >> n;
		if( cmd == "ADD") 
			msta.insert(A(n));
		else {
			if (msta.find(A(n))!= msta.end())
				cout << "YES"  <<endl; 
			else
				cout << "NO" <<endl;
		}
	}
	return 0;
}
/*
输入
第一行是整数n (n <= 10000)
接下来n行，每行一个命令，是以下两种格式之一：

ADD n 要求将整数n加入集合
FIND n 查询集合中有无整数n
输出
先产生一些固有的输出，然后，
对每个FIND命令， 如果集合中有整数n，则输出"YES"，否则输出"NO"
样例输入

6
ADD 1
ADD 2
FIND 3
FIND 2
ADD 3
FIND 3
样例输出
9,8,7,6,5,4,3,2,1,0,
9,8,7,6,5,4,0,
9,6,5,4,0,
9,5,4,0,
NO
YES
YES
*/