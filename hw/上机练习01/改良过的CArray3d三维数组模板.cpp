/*

11:改良过的CArray3d三维数组模板类
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，按要求输出
*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
// 在此处补充你的代码
    /*
    int x,y,z;
    T ***array;
    CArray3D(int x_,int y_,int z_):x(x_),y(y_),z(z_)
    {
        array=new T**[x];
        for(int i=0;i<x;++i)
        {
            array[i]=new T*[y];
            for(int j=0;j<y;++j)
                array[i][j]=new T[z];
        }
        for(int i=0;i<x;++i)
            for(int j=0;j<y;++j)
                for(int k=0;k<z;++k)
                    array[i][j][k]=0;
    }
    T** operator[](int k)
    {
        return array[k];
    }
    operator T***()
    {
        return array;
    }
    */


   /*
    class CArray2D {
    public:
        int layer2;
        T* inner;
        CArray2D(T*p,int c) :inner(p), layer2(c) {}
        T* operator[](int b) {
            return inner + layer2 * b;
        }
        operator T*() {
            return inner;
        }
    };
    T*p;
    int layer1, layer2, layer3;
    CArray3D(int a, int b, int c) :layer1(a), layer2(b), layer3(c) {
        p = new T[a*b*c];
    }
    CArray2D operator[](int a) {
        return CArray2D(p + a * layer2*layer3, layer3);
    }
    operator void*() {
        return (void*)p;
    }
*/
public:
    int d1,d2,d3;
    T* arr;
    class CArray2D
    {
    public:
        T* arr2D;
        int d3;
        CArray2D(T* p_,int d3_):arr2D(p_),d3(d3_){}
        T* operator[](int k)
        {
            return arr2D+k*d3;
        }
        operator T*()
        {
            return arr2D;
        }
    };
    CArray3D(int d1_,int d2_,int d3_):d1(d1_),d2(d2_),d3(d3_)
    {
        arr=new T[d1_*d2_*d3_];
    }
    CArray2D operator[](int k)
    {
        return CArray2D(arr+k*d2*d3,d3);
    }
    operator void*()
    {
        return (void*)arr;
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
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    PrintA();
    memset(a, -1, 60 * sizeof(int));        //注意这里
    memset(a[1][1], 0, 5 * sizeof(int));
    PrintA();
    
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                b[i][j][k] = 10.0 / (i + j + k + 1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;
    
    return 0;
}
/*
输入
无
输出
如样例
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
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
layer 1:
-1,-1,-1,-1,-1,
0,0,0,0,0,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
layer 2:
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
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
-1,3.33333
*/