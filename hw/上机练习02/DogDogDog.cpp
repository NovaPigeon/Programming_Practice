/*
03:编程填空：Dog！Dog！Dog！
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，编写Dog类，使得程序按样例进行输出
*/
#include <iostream>
using namespace std;
class Mammal {
public:
  Mammal() { cout << "Mammal constructor...\n"; }
  virtual ~Mammal() { cout << "Mammal destructor...\n"; }
  Mammal (const Mammal & rhs);
  virtual void Speak() const { cout << "Mammal speak!\n"; }
  virtual Mammal* Clone() { return new Mammal(*this); }
};
  
class Dog : public Mammal {
// 在此处补充你的代码
public:
    Dog();
    ~Dog();
    virtual void Speak()const;
    Dog(const Dog& d):Mammal(d){cout<<"Dog copy constructor...\n";}
    virtual Dog* Clone(){return new Dog(*this);}
};

Mammal::Mammal (const Mammal & rhs) {
  cout << "Mammal Copy Constructor...\n";
}
  
Dog::Dog(){ cout << "Dog constructor...\n"; }
Dog::~Dog(){ cout << "Dog destructor...\n"; }
void Dog::Speak()const { cout << "Woof!\n"; }

int main() {
  Mammal* x=new Dog, *y=new Mammal;
  Mammal* x1=x->Clone(), *y1=y->Clone();
  x1->Speak(); y1->Speak();
  return 0;
}
/*
输入
.
输出
.
样例输入
（无）
样例输出
Mammal constructor...
Dog constructor...
Mammal constructor...
Mammal Copy Constructor...
Dog copy constructor...
Mammal Copy Constructor...
Woof!
Mammal speak! 
*/