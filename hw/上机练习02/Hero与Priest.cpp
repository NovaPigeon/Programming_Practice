/*
01:编程填空：Hero与Priest
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
完善以下程序，使其输出为

Hero::defense()

Hero::attack()

Priest::defense()

Priest::attack()

Priest::defense()
*/
#include <iostream>
using namespace std;
class Hero {
public:
// 在此处补充你的代码
    virtual void defense(){cout<<"Hero::defense()"<<endl;}
    void attack(){cout<<"Hero::attack()"<<endl;}
};
class Priest: public Hero {
public:
    virtual void attack() { cout << "Priest::attack()" << endl; }
    virtual void defense() { cout << "Priest::defense()" << endl; } 
}; 

int main() {
    Priest anduin;
    Hero h;
    h.defense();
    Hero *player = &anduin;
    player->attack();
    player->defense();
    anduin.attack();
    anduin.defense();
    return 0;
}
/*
输入
无
输出
Hero::defense()
Hero::attack()
Priest::defense()
Priest::attack()
Priest::defense()
样例输入
无
样例输出
Hero::defense()
Hero::attack()
Priest::defense()
Priest::attack()
Priest::defense()
*/