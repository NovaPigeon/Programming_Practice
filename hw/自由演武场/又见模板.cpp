/*
0005:编程填空：又见模板
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
填写代码，按要求输出结果：
*/
#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template<class T1,int size=0>
class A
{
public:
	T1 *p;
	A(const T1 *p_)
	{
		p=new T1[size];
		for(int i=0;i<size;++i)
			p[i]=p_[i];
	}
	T1 operator[](int n)
	{
		return p[n];
	}
	T1 sum()
	{
		T1 s=p[0];
		for(int i=1;i<size;++i)
			s+=p[i];
		return s;
	}

};
int main() {
	
	int t;
	cin >> t;
	while( t -- ) { 
	    int b1[10];
	    for(int i = 0;i < 10; ++i) 	
	
	    	cin >> b1[i];
	    A<int, 10> a1 = b1;
	    cout << a1[2] << endl;
	    
	
	    double b2[5] ;
	    for(int i = 0;i < 5; ++i) 	
	    	cin >> b2[i];
	    
	    A<double, 5> a2 = b2;
	    cout << a2.sum() << endl;
	
		
	    string b3[4] ;
	    for(int i = 0;i < 4; ++i) 	
	    	cin >> b3[i];
	    
	    A<string, 4> a3 = b3;
	    cout << a3.sum() << endl;
	}
	return 0;
}
/*
输入
第一行是整数n，表示有n组数据
每组数据有3行
第一行是10个整数
第二行是5个小数
第三行是4个不带空格的字符串，它们之间用空格分隔
输出
先输出10个整数里面的第三个
再输出5个小数的和 (不用考虑小数点后面几位，用cout直接输出即可）
再输出4个字符串连在一起的字符串
样例输入
1
1 2 3 4 5 6 7 8 9 10
4.2 0.0 3.1 2.7 5.2
Hello , world !
样例输出
3
15.2
Hello,world!
*/