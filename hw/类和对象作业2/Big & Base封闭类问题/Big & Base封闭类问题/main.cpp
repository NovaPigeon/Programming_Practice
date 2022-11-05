//
//  main.cpp
//  Big & Base封闭类问题
//
//  Created by 寿晨宸 on 2022/3/2.
//

#include <iostream>
#include <string>
using namespace std;
class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big
{
public:
    int v;
    Base b;
    Big(int n):v(n),b(n){}
    Big(const Big &t):v(t.v),b(t.b){}
    

    
// 在此处补充你的代码
};
int main()
{
    int n;
    while(cin >>n) {
        Big a1(n);
        Big a2 = a1;
        cout << a1.v << "," << a1.b.k << endl;
        cout << a2.v << "," << a2.b.k << endl;
    }
}
