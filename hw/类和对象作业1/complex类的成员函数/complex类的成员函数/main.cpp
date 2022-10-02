//
//  main.cpp
//  complex类的成员函数
//
//  Created by 寿晨宸 on 2022/2/25.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex
{
private:
    double r,i;
public:
    void Print()
    {
        cout << r << "+" << i << "i" << endl;
    }
    Complex():r(0),i(0){}
    Complex &operator=(const char *str)
    {
        Complex f;
        int cnt=0;
        char str2[100];
        while(*str!='+')
        {
            str2[cnt]=*str;
            cnt++;
            str++;
        }
        str2[cnt]='\n';
        str++;
        r=atoi(str2);
        i=atoi(str);
        return *this;
    }
    
};
int main()
{
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
