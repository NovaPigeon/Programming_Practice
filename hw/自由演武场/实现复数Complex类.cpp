/*
0009:编程填空：实现复数Complex类
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
实现复数Complex类，使输出结果为：
3+2i
3+2i
-15
-12+2i
0
5+12i
-12+2i
2i
5+12i
*/
#include <iostream>
using namespace std;
// 在此处补充你的代码
class Complex
{
public:
    int real;
    int i;
    Complex(){}
    Complex(const string& str)
    {
        real=str.c_str()[0]-'0';
        i=str.c_str()[2]-'0';
    }
    Complex(const Complex& b):real(b.real),i(b.i){}
    Complex(const int& real_):real(real_),i(0){}
    Complex(int real_,int i_):real(real_),i(i_){}
    friend ostream& operator<<(ostream& os,const Complex& a)
    {
        if(a.i==0&&a.real==0)
            cout<<0;
        else if(a.i!=0&&a.real==0)
            cout<<a.i<<"i";
        else if(a.i==0&&a.real!=0)
            cout<<a.real;
        else
            cout<<a.real<<"+"<<a.i<<"i";
        return os;
    }
    Complex operator+(const Complex& b)
    {
        return Complex(real+b.real,i+b.i);
    }
    Complex operator-(const Complex& b)
    {
        return Complex(real-b.real,i-b.i);
    }
    Complex operator*(const Complex& a)
    {
        return Complex(real*a.real-i*a.i,real*a.i+i*a.real);
    }
    Complex& operator+=(const Complex& a)
    {
        real=real+a.real;
        i=i+a.i;
        return *this;
    }
    Complex& operator-=(const int& k)
    {
        real=real-k;
        return *this;
    }
    Complex& operator*=(Complex& a)
    {
        Complex temp;
        temp.real=real*a.real-i*a.i;
        temp.i=real*a.i+i*a.real;
        real=temp.real;
        i=temp.i;
        return *this;
    }


};
int main() {
	Complex c1;
	Complex c2("3+2i"); // 用字符串初始化时，只需考虑"a+bi"的形式，其中a和b都是1位数字
	Complex c3(c2);
	Complex c4(-15);
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c2 + c4 << endl;
	cout << c2 - c3 << endl;
	cout << c2 * c3 << endl;
	c2 += c4;
	cout << c2 << endl;
	c2 -= -12;
	cout << c2 << endl;
	c3 *= c3;
	cout << c3 << endl;
	return 0;
}
/*
输入
无
输出
3+2i
3+2i
-15
-12+2i
0
5+12i
-12+2i
2i
5+12i
*/