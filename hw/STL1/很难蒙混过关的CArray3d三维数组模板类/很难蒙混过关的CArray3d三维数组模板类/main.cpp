//
//  main.cpp
//  很难蒙混过关的CArray3d三维数组模板类
//
//  Created by 寿晨宸 on 2022/4/6.
//

/*
C:很难蒙混过关的CArray3d三维数组模板类
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
实现一个三维数组模版CArray3D，可以用来生成元素为任意类型变量的三维数组，输出指定结果*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
// 在此处补充你的代码
private:
    int x;
    int y;
    int z;
    class CArray2D
    {
    private:
        int yy;
        int xx;
        T array[4][5];
    public:
        CArray2D(int yy_,int xx_):yy(yy_),xx(xx_){}
        T* operator[](int n)
        {
            return array[n];
        }
        operator T*()
        {
            return &array[0][0];
        }
        
    };
    CArray2D Array2D[3];
public:
    CArray3D(int z_,int y_,int x_):x(x_),y(y_),z(z_),Array2D{{y_,x_},{y_,x_},{y_,x_}}{}
    CArray2D& operator[](int n)
    {
        return Array2D[n];
    }
    
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 5; ++k)
                cout << a[i][j][k] << "," ;
            cout << endl;
        }
    }
}
void PrintB()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k)
                cout << b[i][j][k] << "," ;
            cout << endl;
        }
    }
}

int main()
{

    int No = 0;
    for( int i = 0; i < 3; ++ i ) {
        a[i];
        for( int j = 0; j < 4; ++j ) {
            a[j][i];
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
            a[j][i][i];
        }
    }
    PrintA();
    memset(a[1],-1 ,20*sizeof(int));
    memset(a[1],-1 ,20*sizeof(int));
    PrintA();
    memset(a[1][1],0 ,5*sizeof(int));
    PrintA();

    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                b[i][j][k] = 10.0/(i+j+k+1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;
        
    return 0;
}
/*输入
无
输出
等同于样例
样例输入
无
样例输出
layer 0:
0,1,2,3,4,
5,6,7,8,9,
10,11,12,13,14,
15,16,17,18,19,
layer 1:
20,21,22,23,24,
25,26,27,28,29,
30,31,32,33,34,
35,36,37,38,39,
layer 2:
40,41,42,43,44,
45,46,47,48,49,
50,51,52,53,54,
55,56,57,58,59,
layer 0:
0,1,2,3,4,
5,6,7,8,9,
10,11,12,13,14,
15,16,17,18,19,
layer 1:
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
layer 2:
40,41,42,43,44,
45,46,47,48,49,
50,51,52,53,54,
55,56,57,58,59,
layer 0:
0,1,2,3,4,
5,6,7,8,9,
10,11,12,13,14,
15,16,17,18,19,
layer 1:
-1,-1,-1,-1,-1,
0,0,0,0,0,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
layer 2:
40,41,42,43,44,
45,46,47,48,49,
50,51,52,53,54,
55,56,57,58,59,
layer 0:
10,5,
5,3.33333,
layer 1:
5,3.33333,
3.33333,2.5,
layer 2:
3.33333,2.5,
2.5,2,
****
7,3.33333
提示
建议做法：
1. a[i][j][k] 这个表达式的第一个[]返回一个内部类的对象，该内部类也重载了[],且返回值为指针。
2. 必要时需重载对象到指针的强制类型转换运算符
来源
Guo Wei
*/
