//
//  main.cpp
//  返回什么才好呢
//
//  Created by 寿晨宸 on 2022/3/2.
//

#include <iostream>
using namespace std;
class A {
public:
    int val;

    A(int
      n=123){val=n;}
    A &GetObj(){return *this;}
// 在此处补充你的代码
};
int main()
{
    int m,n;
    A a;
    cout << a.val << endl;
    while(cin >> m >> n) {
        a.GetObj() = m;
        cout << a.val << endl;
        a.GetObj() = A(n);
        cout << a.val<< endl;
    }
    return 0;
}
