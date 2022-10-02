/*
11:编程填空：C++也能函数式编程
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
填写代码，按要求输出结果
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 设 vector v = [x1, x2, ..., xn], 表示其内顺序存储了 x1 ~ xn 共 n 个值

template <class T, class F>
vector<T> vecMap(vector<T> v, F f) {
    // 返回 retV = [f(x1), f(x2), ..., f(xn)]
    vector<T> retV;
    for (auto x : v)
        retV.push_back(f(x));
    return retV;
}

template <class T, class F>
T vecReduce(T init, vector<T> v, F f) {
    // 返回 ret = f(...f(f(f(init, x1), x2), x3) ..., xn)
    T ret = init;
    for (auto x : v)
        ret = f(ret, x);
    return ret;
}

template <class T, class F>
vector<T> vecFilter(vector<T> v, F f) {
    // 返回 retV = [xi : 1 <= i <= n 且 f(xi) 成立]
    vector<T> retV;
    for (auto x : v)
        if (f(x)) retV.push_back(x);
    return retV;
}

template <class T>
void vecPrintln(vector<T> v) {
    // 依次输出 vector v 中的元素
    cout << "[ ";
    for (auto x : v)
        cout << x << ", ";
    cout << "]" << endl;
}

vector<int> vecRangeInt(int l, int r) {
    // 返回一个包含 [l, r) 中整数的 vector
    vector<int> retV;
    for (int x = l; x < r; ++x)
        retV.push_back(x);
    return retV;
}

class UnaryAdd;
class BinaryAdd;
class GetSecond;
class IsPrime;
// 在此处补充你的代码
class UnaryAdd
{
public:
    int add;
    UnaryAdd(int add_):add(add_){}
    int operator()(int& x)
    {
        x+=add;
        return x;
    }
};
class BinaryAdd
{

};
class GetSecond
{

};
class IsPrime
{

};

int main() {
    // 测试 vecMap, UnaryAdd
    vector<int> a = vecRangeInt(0, 5);
    vecPrintln(a);                                  // [ 0, 1, 2, 3, 4, ]
    UnaryAdd addTen(10);
    vecPrintln(vecMap(a, addTen));                  // [ 10, 11, 12, 13, 14, ]
    UnaryAdd addOne(1);
    vecPrintln(vecMap(vecMap(a, addOne), addOne));  // [ 2, 3, 4, 5, 6, ]
    // 测试 vecReduce, GetSecond, BinaryAdd
    vector<int> b1 {1, 0, 2, 4};
    vector<int> b2 {8, 1, 9, 2};
    vector<int> b3 {2, 0, 4, 8};
    GetSecond getSecond;
    BinaryAdd binAdd;
    cout << vecReduce(-2, b1, getSecond) << endl;  // 4
    cout << vecReduce(-1, b2, getSecond) << endl;  // 2
    cout << vecReduce(0, b3, getSecond) << endl;   // 8
    cout << vecReduce(0, b1, binAdd) << endl;  // 0 + 1 + 0 + 2 + 4 = 7
    cout << vecReduce(1, b2, binAdd) << endl;  // 1 + 8 + 1 + 9 + 2 = 21
    cout << vecReduce(2, b3, binAdd) << endl;  // 2 + 2 + 0 + 4 + 8 = 16
    // 测试 vecFilter, isPrime
    vector<int> c1 = vecRangeInt(1, 10);
    vector<int> c2 {17, 11, 10, 19, 15, 23};
    IsPrime isPrime;
    vecPrintln(vecFilter(c1, isPrime));  // [ 2, 3, 5, 7, ]
    vecPrintln(vecFilter(c2, isPrime));  // [ 17, 11, 19, 23, ]

    vector<int> v1 = vecRangeInt(0, 8);
    cout << vecReduce(
            -1000000,
            vecMap(v1, [](int x) { return 7 * x - x * x + 2; }),
            [](int x, int y) { return max(x, y); }
    ) << endl;
    // max { 7x - x^2 + 2 : 0 <= x < 8 } = 14

    vector<int> v2 = vecRangeInt(0, 12);
    vecPrintln(vecFilter(
        vecMap(v2, [](int x) { return 2 * x + 1; }),
        [](int x) { return x % 3 == 0; }
    ));
    // [ 2x + 1 : 0 <= x < 12 且 (2x + 1) 是 3 的倍数 ] = [ 3, 9, 15, 21, ]
    return 0;
}
/*
样例输入
（无）
样例输出
[ 0, 1, 2, 3, 4, ]
[ 10, 11, 12, 13, 14, ]
[ 2, 3, 4, 5, 6, ]
4
2
8
7
21
16
[ 2, 3, 5, 7, ]
[ 17, 11, 19, 23, ]
14
[ 3, 9, 15, 21, ]
*/