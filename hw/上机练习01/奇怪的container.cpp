/*
05:奇怪的container
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空：生成指定输出
*/
#include <iostream>
#include <string>
using namespace std;
template <class T> 
class container{
// 在此处补充你的代码
public:
    T value;
    container(const T& b){value=b;}
    T operator+(const container&b)
    {
        T res=value;
        res=res+b.value+b.value;
        return res;
    }
    T operator+(const T&b)
    {
        return value+b;
    }
};
int main(){
	int n,m;
	cin >> n >> m;
	string s1,s2;
	cin >> s1 >> s2;
    container <int> a = n;
    container <int> b = m;
    cout<<a+b<<endl;
    cout<<a+m<<endl;
    container <string> sa = string(s1);
    container <string> sb = string(s2);
    cout<<sa+sb<<endl;
    cout<< sa + s2<<endl;
}
/*
输入
第一行是整数n
第二行是整数m
第三行是字符串s1
第四行是字符串s2
输出
第一行是 n+2*m
第二行是 n + m
第三行是 s1+s2+s2
第四行是 s1+s2
样例输入
5
3
foo
bar
样例输出
11
8
foobarbar
foobar
*/