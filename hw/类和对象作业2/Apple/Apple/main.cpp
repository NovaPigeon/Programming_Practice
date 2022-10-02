//
//  main.cpp
//  Apple
//
//  Created by 寿晨宸 on 2022/3/2.
//程序填空，使其输出4 5 1
#include <iostream>
using namespace std;
class Apple
{
private:
    static int nTotalNumber;
public:
    Apple(){nTotalNumber++;}
    Apple(const Apple &a){}
    ~Apple(){nTotalNumber--;}
    static void PrintTotal() {
        cout << nTotalNumber << endl;
    }
    
};
int Apple::nTotalNumber = 0;
Apple Fun(const Apple & a) {
    a.PrintTotal();
    return a;
}
int main()
{
    Apple * p = new Apple[4];
    Fun(p[2]);
    Apple p1,p2;
    Apple::PrintTotal ();
    delete [] p;
    p1.PrintTotal ();
    return 0;
}
