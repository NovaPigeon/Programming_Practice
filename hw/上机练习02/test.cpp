#include<iostream>
using namespace std;
class A 
{ 
    public: 
    A(int n = 0) { cout<<"called"<<endl;} 
    A(const A& a_){cout<<"copy"<<endl;}
};
class B:public A
{
    public:
        B():A(){};
        int operator<(A& obj)const
        {return 1;}
};
void func(A a) { }

int main() {

    //A* a1[3];

    A a2[2];
    a2[0] = 4;
    const A a;

   //func(a2[0]);

   return 0;

}
