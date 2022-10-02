#include <iostream>
#include <cstring>
using namespace std;



class Array2 {
public:
    class Array1 {
    public:
        int a[10], len;
        Array1() {}

        int &operator [](int x) {
            return a[x];
        }

        void operator =(const Array1 &b) {
            for (int i = 0; i < len; ++i)
                a[i] = b.a[i];
        }
    } a[10];

    int len;

    Array2() {}
    Array2(int x, int y): len(x) {
        for (int i = 0; i < len; ++i)
            a[i].len = y;
    }

    Array1 &operator [](int x) {
        return a[x];
    }

    int operator ()(int x, int y) {
        return a[x][y];
    }

    void operator =(const Array2 &b) {
        len = b.len;
        for (int i = 0; i < len; ++i)
            a[i].len = b.a[i].len, a[i] = b.a[i];
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