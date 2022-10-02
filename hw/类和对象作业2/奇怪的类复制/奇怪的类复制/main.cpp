//
//  main.cpp
//  奇怪的类复制
//
//  Created by 寿晨宸 on 2022/3/2.
//

#include <iostream>
using namespace std;
class Sample {
public:
    int v;
// 在此处补充你的代码 9 22 5
    Sample(int n=0):v(n){}
    Sample(const Sample &s){v=s.v+2;}
};
void PrintAndDouble(Sample o)//使用参数时会调用复制构造函数
{
    cout << o.v;
    cout << endl;
}
int main()
{
    Sample a(5);
    Sample b = a;
    PrintAndDouble(b);
    Sample c = 20;
    PrintAndDouble(c);
    Sample d;
    d = a;
    cout << d.v;
    return 0;
}
