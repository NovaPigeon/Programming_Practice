//
//  main.cpp
//  二维数组类
//
//  Created by 寿晨宸 on 2022/3/11.
//

/*
D:二维数组类
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
写一个二维数组类 Array2,使得下面程序的输出结果是：

0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11,

程序：*/

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
private:
    int **p;
    int x;
    int y;
public:
    Array2(int x1,int y1):x(x1),y(y1)
    {
        int **p_=new int*[x1];
        for(int i=0;i<y;i++)
            p_[i]=new int[y1];
        p=p_;
    }
    Array2()
    {
         p=NULL;
    }
    Array2(const Array2& a)
    {
        if(p)
            delete [] p;
        if(a.p)
        {
            p=new int*[a.x+1];
            for(int i=0;i<a.y;i++)
                p[i]=new int[a.y+1];
            for(int i=0;i<a.x;i++)
                for(int j=0;j<a.y;j++)
                    p[i][j]=a.p[i][j];
            
        }
        else
            p=NULL;
    }
    int* operator[](int i)
    {
        return p[i];
    }
    int operator()(int i,int j)
    {
        return p[i][j];
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
/*输入
无
输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
样例输入
None
样例输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,*/
