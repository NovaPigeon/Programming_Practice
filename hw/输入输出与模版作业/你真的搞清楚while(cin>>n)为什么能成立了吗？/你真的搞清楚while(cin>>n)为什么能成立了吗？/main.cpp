//
//  main.cpp
//  你真的搞清楚while(cin>>n)为什么能成立了吗？
//
//  Created by 寿晨宸 on 2022/3/27.
//

/*
D:你真的搞清楚为啥 while(cin >> n) 能成立了吗？
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
读入两个整数，输出两个整数 ，直到碰到-1
*/
#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
private:
    bool flag;
public:
    MyCin():flag(true){}
    MyCin& operator>>(int &n)
    {
        if(!flag)
            return *this;
        cin>>n;
        if(n==-1)
            flag=false;
        return *this;
    }
    operator bool(){return flag;}//类型转换函数
    /*
     模板为
     operator type()
     {
        return data；
     }
     */
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2)
        cout  << n1 << " " << n2 << endl;
    return 0;
}
/*输入
多组数据，每组一行，是两个整数
输出
对每组数据，原样输出
当碰到输入中出现-1 时，程序结束
输入中保证会有 -1
样例输入
12 44
344 555
-1
2 3
样例输出
12 44
344 555
来源
Guo Wei
*/
