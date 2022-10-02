#include <iostream>
#include <cstring>

const int N = 10;


template<class T, int n>
class ndArray {
    ndArray<T, n - 1> *val;

public:
    ndArray(int *d) {
        val = new ndArray<T, n - 1> [*d];
    }

    ndArray<T, n - 1> &operator [](int x) {
        return val[x];
    }
};

template<class T>
class ndArray<T, 1> {
    T a[N];

public:
    T &operator [](int x) {
        return a[x];
    }
};

int d[] = {1, 2, 3, 4};

int main() {
    ndArray<int, 4> a(d);
    return 0;
}