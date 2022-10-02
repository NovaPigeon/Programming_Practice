
/*
程序设计实习
程序设计实习 / 2022 程序设计实习之上机练习01(周六下午) 正在进行中
题目
排名
状态
统计
提问
01:静态成员
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，按要求输出*/

#include <iostream>
#include <vector>
using namespace std;

class A {
    static int count;
public:
// 在此处补充你的代码
static int theNumberOfA() {
        return count;
    }
    A(){count++;}
};

int A::count = 0;

int main() {
    vector<A> v;
    
    for(int i = 0; i < 3; i++) 
    {
        A a;
        v.push_back(a);
        cout << A::theNumberOfA() << endl;
    }

    return 0;
}
/*
样例输入
无
样例输出
1
2
3
*/