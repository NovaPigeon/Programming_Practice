/*
07:编程填空：统计个数
查看提交统计提问
总时间限制: 3000ms 内存限制: 65536kB
描述
请补充下列代码，使其可以根据输入分别统计不同数字个数以及不同字符串个数。
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Counter{
    int cnt;
public:
    Counter():cnt(0){}
    virtual void push(void*) = 0;
    virtual string name() = 0;
    void inc(){
        ++cnt;
    }
    int number(){
        return cnt;
    }
};

template<class T>
class TCounter: public Counter{
// 在此处补充你的代码
public:
    string name1;
    set<T> elememts;
    TCounter(string name_):name1(name_){}
    virtual void push(void*ele)
    {
        int temp=elememts.size();
        elememts.insert(*(T*)ele);
        if(elememts.size()!=temp)
            inc();
    }
    virtual string name(){return name1;}

};

Counter* build_counter(string name){
    if (name == "int") return new TCounter<int>("int");
    else return new TCounter<string>("string");
}



int main(){
    int n, m;
    cin >> n >> m;
    Counter *a = build_counter("int"), *b = build_counter("string");
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a->push(&x);
    }
    for (int i = 0; i < m; ++i){
        string x;
        cin >> x;
        b->push(&x);
    }
    cout << a->name() << ": " << a->number() << endl;
    cout << b->name() << ": " << b->number();
    return 0;
}
/*
输入
第一行两个整数n,m(1<=n,m<=1e5)，分别代表接下来将会输入的数字个数以及字符串个数。
接下来两行分别是n个数字以及m个字符串，由空格分隔。
数字大小不超过int的表示范围，字符串长度不超过10.
输出
输出两行，分别代表不同的数字个数以及不同的字符串个数。
样例输入
5 5
1 2 3 4 3
a b b a ab
样例输出
int: 4
string: 3
*/
