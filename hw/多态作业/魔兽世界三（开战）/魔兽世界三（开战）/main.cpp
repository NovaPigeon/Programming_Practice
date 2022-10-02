//
//  main.cpp
//  魔兽世界三（开战）
//
//  Created by 寿晨宸 on 2022/3/24.
//
/*
E:魔兽世界三(开战)
查看提交统计提问
总时间限制: 2000ms 内存限制: 65536kB
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20)。红魔军的司令部算作编号为0的城市，蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。
两军的司令部都会制造武士。武士一共有dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。
双方的武士编号都是从1开始计算。红方制造出来的第n 个武士，编号就是n。同样，蓝方制造出来的第n 个武士，编号也是n。武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。
武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
sword的攻击力是使用者当前攻击力的20%(去尾取整)。
bomb的攻击力是使用者当前攻击力的40%(去尾取整)，但是也会导致使用者受到攻击，对使用者的攻击力是对敌人取整后的攻击力的1/2(去尾取整)。Bomb一旦使用就没了。
arrow的攻击力是使用者当前攻击力的30%(去尾取整)。一个arrow用两次就没了。
武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。战斗的规则是：
在奇数编号城市，红武士先发起攻击
在偶数编号城市，蓝武士先发起攻击
战斗开始前，双方先对自己的武器排好使用顺序，然后再一件一件地按顺序使用。编号小的武器，排在前面。若有多支arrow，用过的排在前面。排好序后，攻击者按此排序依次对敌人一件一件地使用武器。如果一种武器有多件，那就都要用上。每使用一件武器，被攻击者生命值要减去武器攻击力。如果任何一方生命值减为0或小于0即为死去。有一方死去，则战斗结束。
双方轮流使用武器，甲用过一件，就轮到乙用。某一方把自己所有的武器都用过一轮后，就从头开始再用一轮。如果某一方没有武器了，那就挨打直到死去或敌人武器用完。武器排序只在战斗前进行，战斗中不会重新排序。
如果双方武器都用完且都还活着，则战斗以平局结束。如果双方都死了，也算平局。
有可能由于武士自身攻击力太低，而导致武器攻击力为0。攻击力为0的武器也要使用。如果战斗中双方的生命值和武器的状态都不再发生变化，则战斗结束，算平局。
战斗的胜方获得对方手里的武器。武士手里武器总数不超过10件。缴获武器时，按照武器种类编号从小到大缴获。如果有多件arrow，优先缴获没用过的。
如果战斗开始前双方都没有武器，则战斗视为平局。如果先攻击方没有武器，则由后攻击方攻击。
不同的武士有不同的特点。
编号为n的dragon降生时即获得编号为n%3 的武器。dragon在战斗结束后，如果还没有战死，就会欢呼。
编号为n的ninjia降生时即获得编号为n%3 和(n+1)%3的武器。ninja 使用bomb不会让自己受伤。
编号为n的iceman降生时即获得编号为n%3 的武器。iceman每前进一步，生命值减少10%(减少的量要去尾取整)。
编号为n的lion降生时即获得编号为n%3 的武器。lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每前进一步忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。lion在己方司令部可能逃跑。
wolf降生时没有武器，但是在战斗开始前会抢到敌人编号最小的那种武器。如果敌人有多件这样的武器，则全部抢来。Wolf手里武器也不能超过10件。如果敌人arrow太多没法都抢来，那就先抢没用过的。如果敌人也是wolf，则不抢武器。
以下是不同时间会发生的不同事件：
在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。
红方司令部按照iceman、lion、wolf、ninja、dragon 的顺序制造武士。
蓝方司令部按照lion、dragon、ninja、iceman、wolf 的顺序制造武士。
制造武士需要生命元。
制造一个初始生命值为m 的武士，司令部中的生命元就要减少m 个。
如果司令部中的生命元不足以制造某本该造的武士，那就从此停止制造武士。
在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。
在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。
在每个小时的第35分：在有wolf及其敌人的城市，wolf要抢夺对方的武器。
在每个小时的第40分：在有两个武士的城市，会发生战斗。
在每个小时的第50分，司令部报告它拥有的生命元数量。
在每个小时的第55分，每个武士报告其拥有的武器情况。
武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。
任何一方的司令部里若是出现了敌人，则认为该司令部已被敌人占领。
任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。
给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：
1) 武士降生
输出样例：000:00 blue dragon 1 born
表示在0点0分，编号为1的蓝魔dragon武士降生
如果造出的是lion，那么还要多输出一行，例:
000:00 blue lion 1 born
Its loyalty is 24
表示该lion降生时的忠诚度是24
2) lion逃跑
输出样例：000:05 blue lion 1 ran away
表示在0点5分，编号为1的蓝魔lion武士逃走
3) 武士前进到某一城市
输出样例：
000:10 red iceman 1 marched to city 1 with 20 elements and force 30
表示在0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30
对于iceman,输出的生命值应该是变化后的数值
4) wolf抢敌人的武器
000:35 blue wolf 2 took 3 bomb from red dragon 2 in city 4
表示在0点35分，4号城市中，红魔1号武士wolf 抢走蓝魔2号武士dragon 3个bomb。为简单起见，武器不写复数形式
5) 报告战斗情况
战斗只有3种可能的输出结果：
000:40 red iceman 1 killed blue lion 12 in city 2 remaining 20 elements
表示在0点40分，1号城市中，红魔1号武士iceman 杀死蓝魔12号武士lion后，剩下生命值20
000:40 both red iceman 1 and blue lion 12 died in city 2
注意，把红武士写前面
000:40 both red iceman 1 and blue lion 12 were alive in city 2
注意，把红武士写前面
6) 武士欢呼,dragon在战斗结束后，如果还没有战死，就会欢呼。
输出样例：003:40 blue dragon 2 yelled in city 4
7) 武士抵达敌军司令部
输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
（此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值
8) 司令部被占领
输出样例：003:10 blue headquarter was taken
9)司令部报告生命元数量
000:50 100 elements in red headquarter
000:50 120 elements in blue headquarter
表示在0点50分，红方司令部有100个生命元，蓝方有120个
10)武士报告情况
000:55 blue wolf 2 has 2 sword 3 bomb 0 arrow and 7 elements
为简单起见，武器都不写复数形式。elements一律写复数，哪怕只有1个
交代武器情况时，次序依次是：sword,bomb, arrow。
输出事件时：
首先按时间顺序输出；
同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。
在一次战斗中有可能发生上面的 5 至 6 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。
两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。
对于同一城市，同一时间发生的事情，先输出红方的，后输出蓝方的。
显然，8号事件发生之前的一瞬间一定发生了7号事件。输出时，这两件事算同一时间发生，但是应先输出7号事件
虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。

输入
第一行是t,代表测试数据组数

每组样例共三行。
第一行，4个整数 M,N,K, T。其含义为：
每个司令部一开始都有M个生命元( 1 <= M <= 100000)
两个司令部之间一共有N个城市( 1 <= N <= 20 )
lion每前进一步，忠诚度就降低K。(0<=K<=100)
要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 6000
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于200
第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于200
输出
对每组数据，先输出一行：

Case n:

如对第一组数据就输出 Case 1:
然后按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。
样例输入
1
20 1 10 400
20 20 30 10 20
5 5 5 5 5
样例输出
Case 1:
000:00 blue lion 1 born
Its loyalty is 10
000:10 blue lion 1 marched to city 1 with 10 elements and force 5
000:50 20 elements in red headquarter
000:50 10 elements in blue headquarter
000:55 blue lion 1 has 0 sword 1 bomb 0 arrow and 10 elements
001:05 blue lion 1 ran away
001:50 20 elements in red headquarter
001:50 10 elements in blue headquarter
002:50 20 elements in red headquarter
002:50 10 elements in blue headquarter
003:50 20 elements in red headquarter
003:50 10 elements in blue headquarter
004:50 20 elements in red headquarter
004:50 10 elements in blue headquarter
005:50 20 elements in red headquarter
005:50 10 elements in blue headquarter
提示
请注意浮点数精度误差问题。OJ上的编译器编译出来的可执行程序，在这方面和你电脑上执行的程序很可能会不一致。5 * 0.3 的结果，有的机器上可能是 15.00000001，去尾取整得到15,有的机器上可能是14.9999999，去尾取整后就变成14。因此,本题不要写 5 * 0.3，要写 5 * 3 / 10。
来源
Guo Wei
*/

#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include<fstream>
using namespace std;
const int NUM = 5;
const int WEAPONKINDS = 3;
int M, N, K, T, t;                                        //司令部初始生命元，城市数量，Lion每前进一步降低的忠诚度，要求输出的直到时间T为止的所有时间(T以分钟为单位),测试样例组数
string weapons[WEAPONKINDS] = {"sword", "bomb", "arrow"}; //武器有三种，sword, bomb,和arrow
bool red_lost = false;
bool blue_lost = false;
class Weapon;
class Sword;
class Bomb;
class Arrow;
class Headquarter;
class Warriors;
class Lion;
class Iceman;
class Ninja;
class Wolf;
class Dragon;
class City;
class Weapon
{
public:
    int id;         //武器编号
    int durability; //武器耐久度
    string name;
    Weapon(int id_) : id(id_) { name = weapons[id_]; }
    bool Can_use() { return durability > 0; }
    virtual void Attack(Warriors *Owner, Warriors *Enemy)=0;
};
bool cmp(const Weapon *A, const Weapon *B)
{
    if (A == NULL)
        return false;
    if (B == NULL)
        return true;
    if (A->id != B->id)
        return A->id < B->id;
    return A->durability > B->durability; //给武器排序，NULL指针也能进行排序，用于处理武器被夺走或用尽后的重排问题
}
class Sword : public Weapon
{
public:
    Sword() : Weapon(0) { durability = 3; }
    virtual void Attack(Warriors *Owner, Warriors *Enemy);
};
class Bomb : public Weapon
{
public:
    Bomb() : Weapon(1) { durability = 1; }
    virtual void Attack(Warriors *Owner, Warriors *Enemy);
};
class Arrow : public Weapon
{
public:
    Arrow() : Weapon(2) { durability = 2; }
    virtual void Attack(Warriors *Owner, Warriors *Enemy);
};
class Warriors
{
public:
    Headquarter *pHeadquarter; //指向指挥部的指针
    int warrior_id;            //战士种类的代号
    int num;                   //战士的编号
    int location;              //位置
    bool is_die;               //生死
    int hp;                    //生命值
    int atk;                   //攻击力
    string name;
    Weapon *arms[10];
    int weapon_totalnum;  //武士拥有的武器数量
    int weapon_num[3];    //武士拥有的每种武器的数量
    void Hurt(int damage) //武士收到伤害
    {
        hp -= damage;
        if (hp <= 0)
            is_die = true;
    }
    friend class Headquarter;         //友元，方便调用私有成员
    static string warriors_name[NUM]; //静态数组，指某种代号的战士的名称
    static int warriors_hp[NUM];      //静态数组，指某种代号的战士的生命值
    static int warriors_atk[NUM];
    Warriors(Headquarter *pHeadquarter_, int id_, int num_, int location_); //构造函数
    void PrintWarriorInfo(int time);                                        //打印武士信息;
    void PrintMarchInfo(int time);                                          //打印移动信息;
    void PrintEscapeInfo(int time);                                         //打印Lion的逃跑信息
    void PrintLostInfo(int time);                                           //打印城市被占领的信息
    virtual void March();                                                   //前进
    virtual void Rob(Warriors *Enemy, int time) = 0;                        //Wolf抢夺武器
    virtual bool isEscape() = 0;
    virtual void PrintBornInfo(int time); //打印初始信息
};
/*
编号为n的dragon降生时即获得编号为n%3 的武器。dragon在战斗结束后，如果还没有战死，就会欢呼。
编号为n的ninjia降生时即获得编号为n%3 和(n+1)%3的武器。ninja 使用bomb不会让自己受伤。
编号为n的iceman降生时即获得编号为n%3 的武器。iceman每前进一步，生命值减少10%(减少的量要去尾取整)。
编号为n的lion降生时即获得编号为n%3 的武器。lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每前进一步忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。lion在己方司令部可能逃跑。
wolf降生时没有武器，但是在战斗开始前会抢到敌人编号最小的那种武器。如果敌人有多件这样的武器，则全部抢来。Wolf手里武器也不能超过10件。如果敌人arrow太多没法都抢来，那就先抢没用过的。如果敌人也是wolf，则不抢武器。
  */
/*输出样例：000:00 blue dragon 1 born
表示在0点0分，编号为1的蓝魔dragon武士降生
如果造出的是lion，那么还要多输出一行，例:
000:00 blue lion 1 born
Its loyalty is 24
表示该lion降生时的忠诚度是24*/

class Dragon : public Warriors
{
private:
    int weapon_id;
    double morale;

public:
    virtual void PrintBornInfo(int time) { Warriors::PrintBornInfo(time); }
    virtual void March() { Warriors::March(); }
    virtual bool isEscape() { return false; }
    virtual void Rob(Warriors *Enemy, int time) {}
    Dragon(Headquarter *pHeadquarter_, int id_, int num_, int location_, double morale_) : Warriors(pHeadquarter_, id_, num_, location_), weapon_id(num_ % 3), morale(morale_)
    {
        weapon_num[num_ % 3]++;
        switch (num_ % 3)
        {
        case 0:
            arms[weapon_totalnum++] = new Sword();
            break;
        case 1:
            arms[weapon_totalnum++] = new Bomb();
            break;
        case 2:
            arms[weapon_totalnum++] = new Arrow();
            break;
        default:
            break;
        }
    }
};
class Ninja : public Warriors
{
private:
    int weapon_id1;
    int weapon_id2;

public:
    virtual void PrintBornInfo(int time) { Warriors::PrintBornInfo(time); }
    virtual void March() { Warriors::March(); }
    virtual bool isEscape() { return false; }
    virtual void Rob(Warriors *Enemy, int time) {}
    Ninja(Headquarter *pHeadquarter_, int id_, int num_, int location_) : Warriors(pHeadquarter_, id_, num_, location_), weapon_id1(num_ % 3), weapon_id2((num_ + 1) % 3)
    {
        weapon_num[num_ % 3]++;
        weapon_num[(num_ + 1) % 3]++;
        switch (num_ % 3)
        {
        case 0:
            arms[weapon_totalnum++] = new Sword();
            break;
        case 1:
            arms[weapon_totalnum++] = new Bomb();
            break;
        case 2:
            arms[weapon_totalnum++] = new Arrow();
            break;
        default:
            break;
        }
        switch ((num_ + 1) % 3)
        {
        case 0:
            arms[weapon_totalnum++] = new Sword();
            break;
        case 1:
            arms[weapon_totalnum++] = new Bomb();
            break;
        case 2:
            arms[weapon_totalnum++] = new Arrow();
            break;
        default:
            break;
        }
        sort(arms, arms + 10, cmp);
    }
};
class Iceman : public Warriors
{
private:
    int weapon_id;
public:
    virtual void PrintBornInfo(int time) { Warriors::PrintBornInfo(time); }
    virtual bool isEscape() { return false; }
    virtual void Rob(Warriors *Enemy, int time) {}
    Iceman(Headquarter *pHeadquarter_, int id_, int num_, int location_) : Warriors(pHeadquarter_, id_, num_, location_), weapon_id(num_ % 3)
    {
        weapon_num[num_ % 3]++;
        switch (num_ % 3)
        {
        case 0:
            arms[weapon_totalnum] = new Sword();
            break;
        case 1:
            arms[weapon_totalnum] = new Bomb();
            break;
        case 2:
            arms[weapon_totalnum] = new Arrow();
            break;
        default:
            break;
        }
        weapon_totalnum++;
    }
    virtual void March()
    {
        hp = hp - hp * 1 / 10;
        Warriors::March();
    }
};
class Lion : public Warriors
{
public:
    int loyalty;
    virtual bool isEscape() { return loyalty <= 0; }
    virtual void Rob(Warriors *Enemy, int time) {}
    Lion(Headquarter *pHeadquarter_, int id_, int num_, int location_, int loyalty_) : Warriors(pHeadquarter_, id_, num_, location_), loyalty(loyalty_)
    {
        weapon_num[num_ % 3]++;
        switch (num_ % 3)
        {
        case 0:
                arms[weapon_totalnum] = new Sword();
            break;
        case 1:
            arms[weapon_totalnum] = new Bomb();
            break;
        case 2:
            arms[weapon_totalnum] = new Arrow();
            break;
        default:
            break;
        }
        weapon_totalnum++;
    }
    virtual void PrintBornInfo(int ntime)
    {
        Warriors::PrintBornInfo(ntime);
        cout << "Its loyalty is " << loyalty << endl;
    } //It's loyalty is 24
    virtual void March()
    {
        loyalty -= K;
        Warriors::March();
    }
};
class Wolf : public Warriors
{
public:
    virtual void March() { Warriors::March(); }
    virtual bool isEscape() { return false; }
    Wolf(Headquarter *pHeadquarter_, int id_, int num_, int location_) : Warriors(pHeadquarter_, id_, num_, location_) {}
    virtual void PrintBornInfo(int ntime) { Warriors::PrintBornInfo(ntime); }
    virtual void Rob(Warriors *Enemy, int time);
};

class Headquarter
{
private:
    int color;                 //指挥部颜色
    bool is_end;               //判断是否停止制造士兵
    int total_hp;              //指挥部总生命值
    int warriors_num[NUM];     //指挥部内各种战士数量
    int current_id;            //当下制造的兵种在该指挥部内的序号
    int warriors_total_num;    //该士兵在该指挥部内的编号
    Warriors *pWarriors[1000]; //指向战士的指针
public:
    friend class Warriors;                    //友元，方便调用私有成员
    static int rules[2][NUM];                 //静态数组，生产士兵的规则
    void __Init__(int color_, int total_hp_); //初始化
    void Produce(int time);                   //制造士兵
    void PrintHpInfo(int time);               //汇报司令部生命元数量
    string Rtcolor();                         //得到颜色的字符串
    ~Headquarter(){};                         //析构函数
};
class City
{
public:
    Warriors *members[2];
    int members_num[2];
    City()
    {
        members_num[0] = 0;
        members_num[1] = 0;
        members[0] = NULL;
        members[1] = NULL;
    }
} Citys[22];
/*sword的攻击力是使用者当前攻击力的20%(去尾取整)。
bomb的攻击力是使用者当前攻击力的40%(去尾取整)，但是也会导致使用者受到攻击，对使用者的攻击力是对敌人取整后的攻击力的1/2(去尾取整)。Bomb一旦使用就没了。
arrow的攻击力是使用者当前攻击力的30%(去尾取整)。一个arrow用两次就没了。*/
void Sword::Attack(Warriors *Owner, Warriors *Enemy)
{
    Enemy->Hurt(Owner->atk * 2 / 10);
}
void Bomb::Attack(Warriors *Owner, Warriors *Enemy)
{
    Enemy->Hurt(Owner->atk * 4 / 10);
    durability--;
    if (Owner->warrior_id != 1)
    {
        Owner->Hurt(Owner->atk * 4 / 10 * 5 / 10);
    }
}
void Arrow::Attack(Warriors *Owner, Warriors *Enemy)
{
    Enemy->Hurt(Owner->atk * 3 / 10);
    durability--;
}
void Warriors::PrintBornInfo(int ntime)
{
    printf("%03d:00 ", (ntime - ntime % 60) / 60); //000:00 blue lion 1 born
    cout << pHeadquarter->Rtcolor() << " " << name << " " << num << " born" << endl;
}
Warriors::Warriors(Headquarter *pHeadquarter_, int id_, int num_, int location_)
{
    pHeadquarter = pHeadquarter_;
    warrior_id = id_;
    //cout<<id_<<endl;
    num = num_;
    location = location_;
    is_die = false;
    hp = Warriors::warriors_hp[id_];
    atk = Warriors::warriors_atk[id_];
    weapon_totalnum = 0;
    name = warriors_name[warrior_id];
    for (int i = 0; i < 3; i++)
        weapon_num[i] = 0;
    for (int i = 0; i < 10; i++)
        arms[i] = NULL;
}
void Warriors::PrintWarriorInfo(int time)
{
    printf("%03d:55 ", (time - time % 60) / 60);
    cout << pHeadquarter->Rtcolor() << " " << name << " " << num;
    cout << " has " << weapon_num[0] << " sword " << weapon_num[1] << " bomb " << weapon_num[2] << " arrow and " << hp << " elements" << endl;
} //000:55 blue wolf 2 has 2 sword 3 bomb 0 arrow and 7 elements

void Warriors::March()
{
    //y=-2x+1
    //000:10 red iceman 1 marched to city 1 with 20 elements and force 30
    int color = pHeadquarter->color;
    Citys[location].members[color] = NULL;
    Citys[location].members_num[color]--;
    location = location + (-2 * color + 1);
    Citys[location].members[color] = this;
    Citys[location].members_num[color]++;
    return;
}
void Warriors::PrintMarchInfo(int time)
{
    printf("%03d:10 ", (time - time % 60) / 60);
    cout << pHeadquarter->Rtcolor() << " " << name << " " << num;
    cout << " marched to city " << location << " with " << hp << " elements and force " << atk << endl;
}
void Warriors::PrintLostInfo(int time)
{
    //武士抵达敌军司令部
    printf("%03d:10 ", (time - time % 60) / 60);
    cout << pHeadquarter->Rtcolor() << " " << name << " " << num << " reached ";
    if (pHeadquarter->color == 0)
        cout << "blue";
    else
        cout << "red";
    cout << " headquarter with " << hp << " elements and force " << atk << endl;
    //输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
    //（此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值
    //司令部被占领
    printf("%03d:10 ", (time - time % 60) / 60); //输出样例：003:10 blue headquarter was taken
    if (pHeadquarter->color == 0)
        cout << "blue";
    else
        cout << "red";
    cout << " headquarter was taken" << endl;
}
//000:05 blue lion 1 ran away
void Warriors::PrintEscapeInfo(int time)
{
    printf("%03d:05 ", (time - time % 60) / 60);
    cout << pHeadquarter->Rtcolor() << " lion " << num << " ran away" << endl;
}
void Wolf::Rob(Warriors *Enemy, int time)
{
    //wolf降生时没有武器，但是在战斗开始前会抢到敌人编号最小的那种武器。
    //如果敌人有多件这样的武器，则全部抢来。Wolf手里武器也不能超过10件。
    //如果敌人arrow太多没法都抢来，那就先抢没用过的。如果敌人也是wolf，则不抢武器。
    if (Enemy->warrior_id == 4)
        return;
    if (weapon_totalnum < 10 && Enemy->weapon_totalnum > 0)
    {
        sort(arms, arms + 10, cmp);
        sort(Enemy->arms, Enemy->arms + 10, cmp);
        int Min_id = Enemy->arms[0]->id;
        int cnt = 0; //用于记录抢夺武器的数量
        for (int i = Enemy->weapon_num[Min_id]-1;i>=0 && weapon_totalnum < 10; --i)
        {
            arms[weapon_totalnum++] = Enemy->arms[i];
            cnt++;
            weapon_num[Min_id]++;
            Enemy->arms[i] = NULL;
            Enemy->weapon_totalnum--;
        }
        //000:35 blue wolf 2 took 3 bomb from red dragon 2 in city 4
        Enemy->weapon_num[Min_id] -= cnt;
        printf("%03d:35 ", (time - time % 60) / 60);
        cout << pHeadquarter->Rtcolor() << " wolf " << num << " took " << cnt << " " << weapons[Min_id] << " from ";
        cout << Enemy->pHeadquarter->Rtcolor() << " " << Enemy->name << " " << Enemy->num << " in city " << location << endl;
    }
    return;
}
void Headquarter::__Init__(int color_, int total_hp_)
{
    color = color_;
    is_end = false;
    total_hp = total_hp_;
    for (int i = 0; i < NUM; i++)
        warriors_num[i] = 0;
    current_id = 0;
    warriors_total_num = 0;
}
void Headquarter::Produce(int time)
{
    /*如果司令部中的生命元不足以制造某本该造的武士，那就从此停止制造武士。*/
    if (is_end)
        return; //若已停止制造士兵，则终止函数
    //int cnt_seek = 0;
    int start_location = (N + 1) * color; //士兵的出发位置,红魔军(0)的司令部算作编号为0的城市，蓝魔军(1)的司令部算作编号为N+1的城市
    /*while (Warriors::warriors_hp[Headquarter::rules[color][current_id]] > total_hp && cnt_seek < NUM)
    {
        current_id = (current_id + 1) % NUM;
        cnt_seek++;
    } //若当前总生命值小于特定兵种生命值，跳过，遍历所有兵种->不必遍历，直接终止制造*/
    int warriors_id = rules[color][current_id];
    //cout<<warriors_id<<" "<<current_id<<endl;
    if (Warriors::warriors_hp[warriors_id] > total_hp) //遍历过后仍无法制造士兵，则停止制造
    {
        is_end = true;
        //004 blue headquarter stops making warriors
        //printf("%03d ", time);
        //cout << Rtcolor() << " headquarter stops making warriors" << endl;
        return;
    }
    //制造士兵
    total_hp = total_hp - Warriors::warriors_hp[warriors_id]; //更新总生命值
    current_id = (current_id + 1) % NUM;
    double hp = double(total_hp);
    double dragon_hp = double(Warriors::warriors_hp[0]);
    switch (warriors_id)
    {
    case 0:
        pWarriors[warriors_total_num] = new Dragon(this, warriors_id, warriors_total_num + 1, start_location, hp / dragon_hp);
        break;
    case 1:
        pWarriors[warriors_total_num] = new Ninja(this, warriors_id, warriors_total_num + 1, start_location);
        break;
    case 2:
        pWarriors[warriors_total_num] = new Iceman(this, warriors_id, warriors_total_num + 1, start_location);
        break;
    case 3:
        pWarriors[warriors_total_num] = new Lion(this, warriors_id, warriors_total_num + 1, start_location, total_hp);
        break;
    case 4:
        pWarriors[warriors_total_num] = new Wolf(this, warriors_id, warriors_total_num + 1, start_location);
        break;
    default:
        break;
    } //"dragon","ninja","iceman","lion","wolf"
    warriors_num[warriors_id]++;
    pWarriors[warriors_total_num]->PrintBornInfo(time); //多态
    Citys[start_location].members[color] = pWarriors[warriors_total_num];
    Citys[start_location].members_num[color]++;
    warriors_total_num++;
    //更新其他信息
    return;
}
void Headquarter::PrintHpInfo(int time)
{
    //司令部报告生命元数量
    printf("%03d:50 ", (time - time % 60) / 60);                                //000:50 100 elements in red headquarter
    cout << total_hp << " elements in " << Rtcolor() << " headquarter" << endl; //000:50 120 elements in blue headquarter
}
string Headquarter::Rtcolor()
{
    if (color == 0)
        return "red";
    else
        return "blue";
} /*
Headquarter::~Headquarter()
{
    for(int i=0;i<warriors_total_num;i++)
        delete pWarriors[i];
}*/
void PrintTotalWarriorsInfo(int time)
{
    for (int i = 1; i <= N; i++)
    {
        if (Citys[i].members_num[0] == 1)
            Citys[i].members[0]->PrintWarriorInfo(time);
        if (Citys[i].members_num[1] == 1)
            Citys[i].members[1]->PrintWarriorInfo(time);
    }
}
void TotalMarch(int time)
{ //同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。
    //表示在0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30
    //对于iceman,输出的生命值应该是变化后的数值,iceman每前进一步，生命值减少10%(减少的量要去尾取整)。
    //每前进一步忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。
    for (int i = N; i >= 0; --i)
    {
        if (Citys[i].members_num[0] == 1)
            Citys[i].members[0]->March();
    }
    for (int i = 1; i <= N + 1; ++i)
    {
        if (Citys[i].members_num[1] == 1)
            Citys[i].members[1]->March();
    }
    if (Citys[0].members_num[1] == 1)
    {
        red_lost = true;
        Citys[0].members[1]->PrintLostInfo(time);
    }
    for (int i = 1; i <= N; i++)
    {
        if (Citys[i].members_num[0] == 1)
            Citys[i].members[0]->PrintMarchInfo(time);
        if (Citys[i].members_num[1] == 1)
            Citys[i].members[1]->PrintMarchInfo(time);
    }
    if (Citys[N + 1].members_num[0] == 1)
    {
        blue_lost = true;
        Citys[N + 1].members[0]->PrintLostInfo(time);
    }
}
void GlobalLionEscape(int time)
{
    //但是已经到达敌人司令部的lion不会逃跑。lion在己方司令部可能逃跑。
    if (Citys[0].members_num[0] == 1)
        if (Citys[0].members[0]->warrior_id == 3)
            if (Citys[0].members[0]->isEscape())
            {
                Citys[0].members[0]->PrintEscapeInfo(time);
                //delete Citys[0].members[0];
                Citys[0].members[0] = NULL;
                Citys[0].members_num[0]--;
            }
    for (int i = 1; i <= N; ++i)
    {
        if (Citys[i].members_num[0] == 1)
            if (Citys[i].members[0]->warrior_id == 3)
                if (Citys[i].members[0]->isEscape())
                {
                    Citys[i].members[0]->PrintEscapeInfo(time);
                    //delete Citys[i].members[0];
                    Citys[i].members[0] = NULL;
                    Citys[i].members_num[0]--;
                }
        if (Citys[i].members_num[1] == 1)
            if (Citys[i].members[1]->warrior_id == 3)
                if (Citys[i].members[1]->isEscape())
                {
                    Citys[i].members[1]->PrintEscapeInfo(time);
                    //delete Citys[i].members[1];
                    Citys[i].members[1] = NULL;
                    Citys[i].members_num[1]--;
                }
    }
    if (Citys[N + 1].members_num[1] == 1)
        if (Citys[N + 1].members[1]->warrior_id == 3)
            if (Citys[N + 1].members[1]->isEscape())
            {
                Citys[N + 1].members[1]->PrintEscapeInfo(time);
                //delete Citys[N + 1].members[1];
                Citys[N + 1].members[1] = NULL;
                Citys[N + 1].members_num[1]--;
            }
}
void GlobalWolfRob(int time)
{
    for (int i = 1; i <= N; ++i)
    {
        if (Citys[i].members_num[0] == 1 && Citys[i].members_num[1] == 1)
        {
            Citys[i].members[0]->Rob(Citys[i].members[1], time);
            Citys[i].members[1]->Rob(Citys[i].members[0], time);
        }
    }
}
void Fight(Warriors *Former, Warriors *Later, int time)
{
    //武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。战斗的规则是：
    //在奇数编号城市，红武士先发起攻击
    //在偶数编号城市，蓝武士先发起攻击
    //战斗开始前，双方先对自己的武器排好使用顺序，然后再一件一件地按顺序使用。编号小的武器，排在前面。若有多支arrow，用过的排在前面。排好序后，攻击者按此排序依次对敌人一件一件地使用武器。如果一种武器有多件，那就都要用上。每使用一件武器，被攻击者生命值要减去武器攻击力。如果任何一方生命值减为0或小于0即为死去。有一方死去，则战斗结束。
    //双方轮流使用武器，甲用过一件，就轮到乙用。某一方把自己所有的武器都用过一轮后，就从头开始再用一轮。如果某一方没有武器了，那就挨打直到死去或敌人武器用完。武器排序只在战斗前进行，战斗中不会重新排序。
    //如果双方武器都用完且都还活着，则战斗以平局结束。如果双方都死了，也算平局。
    //有可能由于武士自身攻击力太低，而导致武器攻击力为0。攻击力为0的武器也要使用。如果战斗中双方的生命值和武器的状态都不再发生变化，则战斗结束，算平局。
    //战斗的胜方获得对方手里的武器。武士手里武器总数不超过10件。缴获武器时，按照武器种类编号从小到大缴获。如果有多件arrow，优先缴获没用过的。
    //如果战斗开始前双方都没有武器，则战斗视为平局。如果先攻击方没有武器，则由后攻击方攻击。
    sort(Former->arms, Former->arms + 10, cmp);
    sort(Later->arms, Later->arms + 10, cmp);
    int Fid = 0, Lid = 0;
    //if (Former->weapon_totalnum == 0 && Later->weapon_totalnum == 0)
        //return;
    int FormerNum = Former->weapon_totalnum;
    int LaterNum = Later->weapon_totalnum;
    const int Fed = FormerNum;
    const int Led = LaterNum;
    if (Former->weapon_totalnum == 0 && Later->weapon_totalnum != 0)
    {
        Fight(Later, Former, time);
        return;
    }
    while (1)
    {
        if (Former->weapon_totalnum == 0 && Later->weapon_totalnum == 0)
            break;

        if (Former->weapon_totalnum != 0)
        {
            int Fst = (Fid + 1) % Fed;
            for (int i = Fid; i < Fed + Fst + 1; ++i)
            {
                if (Former->arms[i % Fed] != NULL)
                {
                    Fid = i % Fed;
                    break;
                }
                else
                    continue;
            }
            Former->arms[Fid]->Attack(Former, Later);
            if (!Former->arms[Fid]->Can_use())
            {
                //delete Former->arms[Fid];
                Former->weapon_num[Former->arms[Fid]->id]--;
                Former->arms[Fid] = NULL;
                Former->weapon_totalnum--;
            }
            Fid=(Fid+1)%Fed;
            if (Later->hp <= 0)
            {
                Later->is_die = true;
                break;
            }
        }
        if (Later->weapon_totalnum != 0)
        {
            int Lst = (Lid + 1) % Led;
            for (int i = Lid; i < Led + Lst + 1; ++i)
            {
                if (Later->arms[i % Led] != NULL)
                {
                    Lid = i % Led;
                    break;
                }
                else
                    continue;
            }
            Later->arms[Lid]->Attack(Later, Former);
            if (!Later->arms[Lid]->Can_use())
            {
                Later->weapon_num[Later->arms[Lid]->id]--;
                //delete Later->arms[Lid];
                Later->arms[Lid] = NULL;
                Later->weapon_totalnum--;
            }
            Lid=(Lid+1)%Led;
            if (Former->hp <= 0)
            {
                Former->is_die = true;
                break;
            }
        }
        /*if (maxNUM - 1 == 0)
        {
            if (FormerNum == Former->weapon_totalnum && LaterNum == Later->weapon_totalnum && FormerHp == Former->hp && LaterHp == Later->hp)
                break;
        }
            
        FormerNum = Former->weapon_totalnum;
        LaterNum = Later->weapon_totalnum;
        FormerHp = Former->hp;
        LaterHp = Later->hp;
        maxNUM = max(FormerNum, LaterNum);*/
        if(Former->weapon_totalnum==1&&Former->weapon_num[1]==0&&Former->weapon_num[2]==0&&Former->atk*3/10<1)
        {
            if(Later->weapon_totalnum==0)
                break;
            if(Later->weapon_totalnum==1&&Later->weapon_num[1]==0&&Later->weapon_num[2]==0&&Later->atk*3/10<1)
                break;
        }
        if(Later->weapon_totalnum==1&&Later->weapon_num[1]==0&&Later->weapon_num[2]==0&&Later->atk*3/10<1)
        {
            if(Former->weapon_totalnum==0)
                break;
            if(Former->weapon_totalnum==1&&Former->weapon_num[1]==0&&Former->weapon_num[2]==0&&Former->atk*3/10<1)
                break;
        }
    }
    sort(Former->arms, Former->arms + 10, cmp);
    sort(Later->arms, Later->arms + 10, cmp);
    //报告战斗情况
    //战斗只有3种可能的输出结果：
    //000:40 red iceman 1 killed blue lion 12 in city 2 remaining 20 elements
    //表示在0点40分，1号城市中，红魔1号武士iceman 杀死蓝魔12号武士lion后，剩下生命值20
    //000:40 both red iceman 1 and blue lion 12 died in city 2
    //注意，把红武士写前面
    //000:40 both red iceman 1 and blue lion 12 were alive in city 2
    //注意，把红武士写前面
    //武士欢呼,dragon在战斗结束后，如果还没有战死，就会欢呼。
    //输出样例：003:40 blue dragon 2 yelled in city 4
    Warriors *red = Citys[Former->location].members[0];
    Warriors *blue = Citys[Former->location].members[1];
    if (!red->is_die && !blue->is_die)
    {
        printf("%03d:40 both red ", (time - time % 60) / 60);
        cout << red->name << " " << red->num << " and blue " << blue->name << " " << blue->num << " were alive in city " << red->location << endl;
    }
    if (red->is_die && (!blue->is_die))
    {
        for (int i = 0; i < red->weapon_totalnum && blue->weapon_totalnum < 10; ++i)
        {
            blue->arms[blue->weapon_totalnum++] = red->arms[i];
            blue->weapon_num[red->arms[i]->id]++;
            red->arms[i] = NULL;
        }
        printf("%03d:40 blue ", (time - time % 60) / 60);
        cout << blue->name << " " << blue->num << " killed red " << red->name << " " << red->num << " in city " << red->location << " remaining " << blue->hp << " elements" << endl;
        //delete red;
        Citys[blue->location].members_num[0]--;
        Citys[blue->location].members[0] = NULL;
    }
    if ((!red->is_die) && blue->is_die)
    {
        for (int i = 0; i < blue->weapon_totalnum && red->weapon_totalnum < 10; ++i)
        {
            red->arms[red->weapon_totalnum++] = blue->arms[i];
            red->weapon_num[blue->arms[i]->id]++;
            blue->arms[i] = NULL;
        }
        printf("%03d:40 red ", (time - time % 60) / 60);
        cout << red->name << " " << red->num << " killed blue " << blue->name << " " << blue->num << " in city " << blue->location << " remaining " << red->hp << " elements" << endl;
        //delete blue;
        Citys[red->location].members_num[1]--;
        Citys[red->location].members[1] = NULL;
    }
    if (red->is_die && blue->is_die)
    {
        Citys[red->location].members_num[1]--;
        Citys[red->location].members[1] = NULL;
        Citys[red->location].members_num[0]--;
        Citys[red->location].members[0] = NULL;
        printf("%03d:40 both red ", (time - time % 60) / 60);
        cout << red->name << " " << red->num << " and blue " << blue->name << " " << blue->num << " died in city " << red->location << endl;
        //delete red;
        //delete blue;
    }
    if (red->warrior_id == 0&&!red->is_die)
    {
        printf("%03d:40 red dragon ", (time - time % 60) / 60);
        cout << red->num << " yelled in city " << red->location << endl;
    }
    if (blue->warrior_id == 0&&!blue->is_die)
    {
        printf("%03d:40 blue dragon ", (time - time % 60) / 60);
        cout << blue->num << " yelled in city " << blue->location << endl;
    }
    return;
}
void GlobalFight(int time)
{
    for (int i = 1; i <= N; ++i)
    {
        if (Citys[i].members_num[0] == 1 && Citys[i].members_num[1] == 1)
        {
            if (i % 2 == 0)
            {
                Fight(Citys[i].members[1], Citys[i].members[0], time);
            }
            else
            {
                Fight(Citys[i].members[0], Citys[i].members[1], time);
            }
        }
    }
}
string Warriors::warriors_name[NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int Headquarter::rules[2][NUM] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}};
//红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。//蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
int Warriors::warriors_hp[NUM] = {0};
int Warriors::warriors_atk[NUM] = {0};
int main()
{
    /*每组样例共三行。
    t为测试样例数
    第一行，4个整数 M,N,K, T。其含义为：
    每个司令部一开始都有M个生命元( 1 <= M <= 100000)
    两个司令部之间一共有N个城市( 1 <= N <= 20 )
    lion每前进一步，忠诚度就降低K。(0<=K<=100)
    要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 6000
    第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于200
    第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于200
    */
    int cnt = 1;
    //freopen("test.txt","w",stdout);
    cin >> t;
    Headquarter red, blue;
    while (t--)
    {
        red_lost=false;
        blue_lost=false;
        for(int i=0;i<22;++i)
        {
            Citys[i].members[0]=NULL;
            Citys[i].members[1]=NULL;
            Citys[i].members_num[0]=0;
            Citys[i].members_num[1]=0;
        }
        cout << "Case " << cnt <<":"<< endl;
        cnt++;
        cin >> M >> N >> K >> T;
        for (int i = 0; i < NUM; ++i)
            cin >> Warriors::warriors_hp[i];
        for (int i = 0; i < NUM; ++i)
            cin >> Warriors::warriors_atk[i];
        red.__Init__(0, M);
        blue.__Init__(1, M); //初始化指挥部
        for (int time = 0; time <= T; time += 5)
        {
            switch (time % 60)
            {
                //制造一个初始生命值为m 的武士，司令部中的生命元就要减少m 个。
                //如果司令部中的生命元不足以制造某本该造的武士，那就从此停止制造武士。
            case 0:
                red.Produce(time);
                blue.Produce(time);
                break;
                //在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。
            case 5:
                GlobalLionEscape(time);
                break;
                //在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。
            case 10:
                TotalMarch(time);
                break;
                //在每个小时的第35分：在有wolf及其敌人的城市，wolf要抢夺对方的武器。
            case 35:
                GlobalWolfRob(time);
                break;
                //在每个小时的第40分：在有两个武士的城市，会发生战斗。
            case 40:
                GlobalFight(time);
                break;
                //在每个小时的第50分，司令部报告它拥有的生命元数量。
            case 50:
                red.PrintHpInfo(time);
                blue.PrintHpInfo(time);
                break;
                //在每个小时的第55分，每个武士报告其拥有的武器情况。
            case 55:
                PrintTotalWarriorsInfo(time);
                break;
            default:
                break;
            }
            if (red_lost || blue_lost)
                break;
            //武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。
            //任何一方的司令部里若是出现了敌人，则认为该司令部已被敌人占领。
            //任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。
        }
    }
    return 0;
}
