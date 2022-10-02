//
//  main.cpp
//  惊呆！point竟然能这样输出！
//
//  Created by 寿晨宸 on 2022/3/11.
//

/*
C:惊呆！Point竟然能这样输入输出
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空*/
#include <iostream>
using namespace std;
class Point {
    private:
        int x;
        int y;
    public:
        Point() { };
// 在此处补充你的代码
    friend ostream & operator<<(ostream & os,const Point& p)
    {
        os<<p.x<<","<<p.y;
        return os;
    }
    friend istream & operator>>(istream & is,Point& p)
    {
        int x_,y_;
        is>>x_>>y_;
        p.x=x_;
        p.y=y_;
        return is;
    }
};
int main()
{
     Point p;
     while(cin >> p) {
         cout << p << endl;
     }
    return 0;
}
/*输入
多组数据，每组两个整数
输出
对每组数据，输出一行，就是输入的两个整数
样例输入
2 3
4 5
样例输出
2,3
4,5
来源
Guo Wei*/
