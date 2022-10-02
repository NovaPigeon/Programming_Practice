/*
02:编程填空：可恶的括号
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
填写代码，按要求输出结果
*/
#include <cstdio>
#include <iostream>
using namespace std;

class f {
// 在此处补充你的代码
public:
    int val;
    f(int val_):val(val_){}
    f(int a,int b):val(a*b){}
    operator int(){return val;}
    int operator()(int val_){return val_-val;}
};

int main() {
  cout << f(3)(5) << endl;
  cout << f(4)(10) << endl;
  cout << f(114)(514) << endl;
  cout << f(9,7) << endl;
  cout << f(2,3) << endl;
  cout << f(2,5) << endl;
}
/*
输入
.
输出
.
样例输入
(无)
样例输出
2
6
400
63
6
10
*/