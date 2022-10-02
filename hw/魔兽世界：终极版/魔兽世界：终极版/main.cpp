
//
//  main.cpp
//  魔兽世界：终极版
//
//  Created by 寿晨宸 on 2022/4/5.
//
/*
A:魔兽世界终极版
查看提交统计提问
总时间限制: 6000ms 内存限制: 65536kB
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20 )。红魔军的司令部算作编号为0的城市，蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。
两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。
双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。
武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。
有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。每次战斗只有一方发起主动进攻一次。被攻击者生命值会减去进攻者的攻击力值和进攻者手中sword的攻击力值。被进攻者若没死，就会发起反击，被反击者的生命值要减去反击者攻击力值的一半(去尾取整)和反击者手中sword的攻击力值。反击可能致敌人于死地。
如果武士在战斗中杀死敌人（不论是主动进攻杀死还是反击杀死），则其司令部会立即向其发送8个生命元作为奖励，使其生命值增加8。当然前提是司令部得有8个生命元。如果司令部的生命元不足以奖励所有的武士，则优先奖励距离敌方司令部近的武士。
如果某武士在某城市的战斗中杀死了敌人，则该武士的司令部立即取得该城市中所有的生命元。注意，司令部总是先完成全部奖励工作，然后才开始从各个打了胜仗的城市回收生命元。对于因司令部生命元不足而领不到奖励的武士，司令部也不会在取得战利品生命元后为其补发奖励。
如果一次战斗的结果是双方都幸存(平局)，则双方都不能拿走发生战斗的城市的生命元。
城市可以插旗子，一开始所有城市都没有旗子。在插红旗的城市，以及编号为奇数的无旗城市，由红武士主动发起进攻。在插蓝旗的城市，以及编号为偶数的无旗城市，由蓝武士主动发起进攻。
当某个城市有连续两场战斗都是同一方的武士杀死敌人(两场战斗之间如果有若干个战斗时刻并没有发生战斗，则这两场战斗仍然算是连续的；但如果中间有平局的战斗，就不算连续了) ，那么该城市就会插上胜方的旗帜，若原来插着败方的旗帜，则败方旗帜落下。旗帜一旦插上，就一直插着，直到被敌人更换。一个城市最多只能插一面旗帜，旗帜没被敌人更换前，也不会再次插同颜色的旗。
各种武器有其特点：
sword武器的初始攻击力为拥有它的武士的攻击力的20%（去尾取整）。但是sword每经过一次战斗(不论是主动攻击还是反击)，就会变钝，攻击力变为本次战斗前的80% (去尾取整)。sword攻击力变为0时，视为武士失去了sword。如果武士降生时得到了一个初始攻击力为0的sword，则视为武士没有sword.
arrow有一个攻击力值R。如果下一步要走到的城市有敌人，那么拥有arrow的武士就会放箭攻击下一个城市的敌人（不能攻击对方司令部里的敌人）而不被还击。arrow使敌人的生命值减少R，若减至小于等于0，则敌人被杀死。arrow使用3次后即被耗尽，武士失去arrow。两个相邻的武士可能同时放箭把对方射死。
拥有bomb的武士，在战斗开始前如果判断自己将被杀死（不论主动攻击敌人，或者被敌人主动攻击都可能导致自己被杀死，而且假设武士可以知道敌人的攻击力和生命值），那么就会使用bomb和敌人同归于尽。武士不预测对方是否会使用bomb。
武士使用bomb和敌人同归于尽的情况下，不算是一场战斗，双方都不能拿走城市的生命元，也不影响城市的旗帜。
不同的武士有不同的特点。
dragon可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。dragon 在一次在它主动进攻的战斗结束后，如果还没有战死，而且士气值大于0.8，就会欢呼。dragon每取得一次战斗的胜利(敌人被杀死)，士气就会增加0.2，每经历一次未能获胜的战斗，士气值就会减少0.2。士气增减发生在欢呼之前。
ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。ninja 挨打了也从不反击敌人。
iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。iceman 每前进两步，在第2步完成的时候，生命值会减少9，攻击力会增加20。但是若生命值减9后会小于等于0，则生命值不减9,而是变为1。即iceman不会因走多了而死。
lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每经过一场未能杀死敌人的战斗，忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。Lion在己方司令部可能逃跑。lion 若是战死，则其战斗前的生命值就会转移到对手身上。所谓“战斗前”，就是每个小时的40分前的一瞬间。
wolf降生时没有武器，但是在战斗中如果获胜（杀死敌人），就会缴获敌人的武器，但自己已有的武器就不缴获了。被缴获的武器当然不能算新的，已经被用到什么样了，就是什么样的。
以下是不同时间会发生的不同事件：
在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。
红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。
蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。
制造武士需要生命元。
制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。
如果司令部中的生命元不足以制造某武士，那么司令部就等待，直到获得足够生命元后的第一个整点，才制造该武士。例如，在2:00，红方司令部本该制造一个 wolf ，如果此时生命元不足，那么就会等待，直到生命元足够后的下一个整点，才制造一个 wolf。
在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。
在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。
在每个小时的第20分：每个城市产出10个生命元。生命元留在城市，直到被武士取走。
在每个小时的第30分：如果某个城市中只有一个武士，那么该武士取走该城市中的所有生命元，并立即将这些生命元传送到其所属的司令部。
在每个小时的第35分，拥有arrow的武士放箭，对敌人造成伤害。放箭事件应算发生在箭发出的城市。注意，放箭不算是战斗，因此放箭的武士不会得到任何好处。武士在没有敌人的城市被箭射死也不影响其所在城市的旗帜更换情况。
在每个小时的第38分，拥有bomb的武士评估是否应该使用bomb。如果是，就用bomb和敌人同归于尽。
在每个小时的第40分：在有两个武士的城市，会发生战斗。 如果敌人在5分钟前已经被飞来的arrow射死，那么仍然视为发生了一场战斗，而且存活者视为获得了战斗的胜利。此情况下不会有“武士主动攻击”，“武士反击”，“武士战死”的事件发生，但战斗胜利后应该发生的事情都会发生。如Wolf一样能缴获武器，旗帜也可能更换，等等。在此情况下,Dragon同样会通过判断是否应该轮到自己主动攻击来决定是否欢呼。
在每个小时的第50分，司令部报告它拥有的生命元数量。
在每个小时的第55分，每个武士报告其拥有的武器情况。
武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。
任何一方的司令部里若是出现了2个敌人，则认为该司令部已被敌人占领。
任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。
给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：
1) 武士降生
输出样例： 000:00 blue lion 1 born
表示在 0点0分，编号为1的蓝魔lion武士降生
如果造出的是dragon，那么还要多输出一行，例：
000:00 blue dragon 1 born
Its morale is 23.34
表示该该dragon降生时士气是23. 34(四舍五入到小数点后两位)
如果造出的是lion，那么还要多输出一行，例:
000:00 blue lion 1 born
Its loyalty is 24
表示该lion降生时的忠诚度是24
2) lion逃跑
输出样例： 000:05 blue lion 1 ran away
表示在 0点5分，编号为1的蓝魔lion武士逃走
3) 武士前进到某一城市
输出样例： 000:10 red iceman 1 marched to city 1 with 20 elements and force 30
表示在 0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30
对于iceman,输出的生命值和攻击力应该是变化后的数值
4)武士放箭
输出样例： 000:35 blue dragon 1 shot
表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭。如果射出的箭杀死了敌人，则应如下输出：
000:35 blue dragon 1 shot and killed red lion 4
表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭，杀死了编号为4的红魔lion。
5)武士使用bomb
输出样例： 000:38 blue dragon 1 used a bomb and killed red lion 7
表示在 0点38分，编号为1的蓝魔dragon武士用炸弹和编号为7的红魔lion同归于尽。
6) 武士主动进攻
输出样例：000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30
表示在0点40分，1号城市中，红魔1号武士iceman 进攻蓝魔1号武士lion,在发起进攻前，红魔1号武士iceman生命值为20，攻击力为 30
7) 武士反击
输出样例：001:40 blue dragon 2 fought back against red lion 2 in city 1
表示在1点40分，1号城市中，蓝魔2号武士dragon反击红魔2号武士lion
8) 武士战死
输出样例：001:40 red lion 2 was killed in city 1
被箭射死的武士就不会有这一条输出。
9) 武士欢呼
输出样例：003:40 blue dragon 2 yelled in city 4
10) 武士获取生命元( elements )
输出样例：001:40 blue dragon 2 earned 10 elements for his headquarter
输出不包括在30分不是通过战斗获取的elements
11) 旗帜升起
输出样例：004:40 blue flag raised in city 4
12) 武士抵达敌军司令部
输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
(此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值
13) 司令部被占领
输出样例：003:10 blue headquarter was taken
14)司令部报告生命元数量
000:50 100 elements in red headquarter
000:50 120 elements in blue headquarter
表示在0点50分，红方司令部有100个生命元，蓝方有120个
15)武士报告武器情况
000:55 blue wolf 2 has arrow(2),bomb,sword(23)
000:55 blue wolf 4 has no weapon
000:55 blue wolf 5 has sword(20)
表示在0点55分，蓝魔2号武士wolf有一支arrow（这支arrow还可以用2次），一个bomb，还有一支攻击力为23的sword。
蓝魔4号武士wolf没武器。
蓝魔5号武士wolf有一支攻击力为20的sword。
交代武器情况时，次序依次是：arrow,bomb,sword。如果没有某种武器，某种武器就不用提。报告时，先按从西向东的顺序所有的红武士报告，然后再从西向东所有的蓝武士报告。

输出事件时：
首先按时间顺序输出；
同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。
在一次战斗中有可能发生上面的 6 至 11 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。
两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。
显然，13号事件发生之前的一瞬间一定发生了12号事件。输出时，这两件事算同一时间发生，但是应先输出12号事件
虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。
输入
第一行是t,代表测试数据组数
每组样例共三行。
第一行，五个整数 M,N,R,K, T。其含义为：
每个司令部一开始都有M个生命元( 1 <= M <= 10000)
两个司令部之间一共有N个城市( 1 <= N <= 20 )
arrow的攻击力是R
lion每经过一场未能杀死敌人的战斗，忠诚度就降低K。
要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 5000
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000
第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于10000

输出
对每组数据，先输出一行：
Case n:
如对第一组数据就输出 Case1:
然后按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。

样例输入
1
20 1 10 10 1000
20 20 30 10 20
5 5 5 5 5
样例输出
Case 1:
000:00 blue lion 1 born
Its loyalty is 10
000:10 blue lion 1 marched to city 1 with 10 elements and force 5
000:30 blue lion 1 earned 10 elements for his headquarter
000:50 20 elements in red headquarter
000:50 20 elements in blue headquarter
000:55 blue lion 1 has no weapon
001:00 blue dragon 2 born
Its morale is 0.00
001:10 blue lion 1 reached red headquarter with 10 elements and force 5
001:10 blue dragon 2 marched to city 1 with 20 elements and force 5
001:30 blue dragon 2 earned 10 elements for his headquarter
001:50 20 elements in red headquarter
001:50 10 elements in blue headquarter
001:55 blue lion 1 has no weapon
001:55 blue dragon 2 has arrow(3)
002:10 blue dragon 2 reached red headquarter with 20 elements and force 5
002:10 red headquarter was taken
*/

#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
using namespace std;
const int NUM = 5;
const int WEAPONKINDS = 3;
int M, N, R, K, T, t;                                     //司令部初始生命元，城市数量，Lion每前进一步降低的忠诚度，要求输出的直到时间T为止的所有时间(T以分钟为单位),测试样例组数
string weapons[WEAPONKINDS] = {"sword", "bomb", "arrow"}; //武器有三种，sword, bomb,和arrow
bool red_lost = false;                                    //红军指挥部是否沦陷
bool blue_lost = false;                                   //蓝军指挥部是否沦陷
class Weapon;                                             //武器类
class Sword;                                              //剑
class Bomb;                                               //炸弹
class Arrow;                                              //箭
class Headquarter;                                        //指挥部
class Warriors;                                           //武士
class Lion;
class Iceman;
class Ninja;
class Wolf;
class Dragon;
//各类武士
class City;                                                 //城市
bool cmp(const Weapon *A, const Weapon *B);                 //给武器排序，NULL指针也能进行排序，用于处理武器被夺走或用尽后的重排问题
void PrintTotalWarriorsInfo(int time);                      //打印所有士兵的信息
void GlobalMarch(int time);                                  //所有士兵前进
void GlobalLionEscape(int time);                            //所有该逃离的Lion逃离战场
void GlobalArrowAttack(int time);                           //所有拥有弓箭的士兵使用之
void GlobalBombAttack(int time);                            //使用炸弹
void Fighting(Warriors *Former, Warriors *Later, int time); //士兵战斗
void GlobalFight(int time);                                 //所有士兵进行战斗
void GlobalHpIncrease();                                    //所有城市的生命值增加10点
void GlobalTakeHp(int time);                                //士兵取走城市中的生命元
void GlobalThpSet();
class Weapon
{
public:
    int id;         //武器编号
    int durability; //武器耐久度
    int arm_atk;
    string name;
    Weapon(int id_, int arm_atk_ = 0) : id(id_), arm_atk(arm_atk_) { name = weapons[id_]; }
    bool Can_use() { return durability > 0; }
    virtual void Attack(Warriors *Owner, Warriors *Enemy) = 0;
    virtual void PrintWeaponInfo() = 0;
};
bool cmp(const Weapon *A, const Weapon *B)
{
    if (A == NULL)
        return false;
    if (B == NULL)
        return true;
    if (A->id != B->id)
        return A->id > B->id;
    return A->durability < B->durability;
}
class Sword : public Weapon
{
public:
    Sword(int arm_atk_) : Weapon(0, arm_atk_) { durability = 1; }
    virtual void Attack(Warriors *Owner, Warriors *Enemy);
    virtual void PrintWeaponInfo();
};
class Bomb : public Weapon
{
public:
    Bomb() : Weapon(1) { durability = 1; }
    virtual void Attack(Warriors *Owner, Warriors *Enemy);
    virtual void PrintWeaponInfo();
};
class Arrow : public Weapon
{
public:
    Arrow() : Weapon(2, R) { durability = 3; }
    virtual void Attack(Warriors *Owner, Warriors *Enemy);
    virtual void PrintWeaponInfo();
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
    int t_hp;                  //临时储存生命值
    int atk;                   //攻击力
    int color;
    bool has_reached;
    string name;
    Weapon *arms[10];
    int weapon_totalnum;  //武士拥有的武器数量
    int weapon_num[3];    //武士拥有的每种武器的数量
    void Hurt(int damage) //武士收到伤害
    {
        hp -= damage;
        if (hp <= 0)
        {
            is_die = true;
            hp = 0;
        }
    }
    string rtcolor()
    {
        if (color == 0)
            return "red";
        else
            return "blue";
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
    void takeHp(int time);
    void ArrowAttack(int time);                 //射箭
    void BombAttack(Warriors *Enemy, int time); //使用炸弹
    virtual void March();                       //前进
    virtual void Rob(Warriors *Enemy) = 0;      //Wolf抢夺武器
    virtual bool isEscape() = 0;                //判断是否逃离战场
    virtual void PrintBornInfo(int time);       //打印初始信息
    virtual bool isYell() = 0;                  //判断是否欢呼
    /*被攻击者生命值会减去进攻者的攻击力值和进攻者手中sword的攻击力值。
    被进攻者若没死，就会发起反击，被反击者的生命值要减去反击者攻击力值的一半(去尾取整)和反击者手中sword的攻击力值。反击可能致敌人于死地。*/
    virtual void Fight(Warriors *Enemy, int time);
    virtual void FightBack(Warriors *Enemy, int time);
};

class Dragon : public Warriors
{
    /*dragon可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。
    dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
    dragon 在一次在它主动进攻的战斗结束后，如果还没有战死，而且士气值大于0.8，就会欢呼。
    dragon每取得一次战斗的胜利(敌人被杀死)，士气就会增加0.2，每经历一次未能获胜的战斗，士气值就会减少0.2。
    士气增减发生在欢呼之前。*/
private:
    int weapon_id;
    double morale;

public:
    virtual void PrintBornInfo(int time)
    {
        Warriors::PrintBornInfo(time);
        //Its morale is 0.00
        printf("Its morale is %.2f\n", morale);
    }
    virtual bool isYell() { return morale > 0.8; }
    virtual void March() { Warriors::March(); }
    virtual bool isEscape() { return false; }
    virtual void Rob(Warriors *Enemy) {}
    virtual void Fight(Warriors *Enemy, int time)
    {
        Warriors::Fight(Enemy, time);
        if (Enemy->is_die)
            morale += 0.2;
        else
            morale -= 0.2;
    }
    virtual void FightBack(Warriors *Enemy, int time)
    {
        Warriors::FightBack(Enemy, time);
        if (Enemy->is_die && !is_die)
            morale += 0.2;
        else
            morale -= 0.2;
    }
    Dragon(Headquarter *pHeadquarter_, int id_, int num_, int location_, double morale_) : Warriors(pHeadquarter_, id_, num_, location_), weapon_id(num_ % 3), morale(morale_)
    {
        switch (num_ % 3)
        {
        case 0:
            if (atk * 2 / 10 > 0)
            {
                arms[weapon_totalnum++] = new Sword(atk * 2 / 10);
                weapon_num[num_ % 3]++;
            }
            break;
        case 1:
            arms[weapon_totalnum++] = new Bomb();
            weapon_num[num_ % 3]++;
            break;
        case 2:
            arms[weapon_totalnum++] = new Arrow();
            weapon_num[num_ % 3]++;
            break;
        default:
            break;
        }
    }
};
class Ninja : public Warriors
{
    /*ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。ninja 挨打了也从不反击敌人。*/
private:
    int weapon_id1;
    int weapon_id2;

public:
    virtual void PrintBornInfo(int time) { Warriors::PrintBornInfo(time); }
    virtual void March() { Warriors::March(); }
    virtual bool isEscape() { return false; }
    virtual void Rob(Warriors *Enemy) {}
    virtual void Fight(Warriors *Enemy, int time) { Warriors::Fight(Enemy, time); }
    virtual bool isYell() { return false; }
    virtual void FightBack(Warriors *Enemy, int time) {}
    Ninja(Headquarter *pHeadquarter_, int id_, int num_, int location_) : Warriors(pHeadquarter_, id_, num_, location_), weapon_id1(num_ % 3), weapon_id2((num_ + 1) % 3)
    {
        switch (num_ % 3)
        {
        case 0:
            if (atk * 2 / 10 > 0)
            {
                arms[weapon_totalnum++] = new Sword(atk * 2 / 10);
                weapon_num[num_ % 3]++;
            }
            break;
        case 1:
            arms[weapon_totalnum++] = new Bomb();
            weapon_num[num_ % 3]++;
            break;
        case 2:
            arms[weapon_totalnum++] = new Arrow();
            weapon_num[num_ % 3]++;
            break;
        default:
            break;
        }
        switch ((num_ + 1) % 3)
        {
        case 0:
            if (atk * 2 / 10 > 0)
            {
                arms[weapon_totalnum++] = new Sword(atk * 2 / 10);
                weapon_num[(num_ + 1) % 3]++;
            }
            break;
        case 1:
            arms[weapon_totalnum++] = new Bomb();
            weapon_num[(num_ + 1) % 3]++;
            break;
        case 2:
            arms[weapon_totalnum++] = new Arrow();
            weapon_num[(num_ + 1) % 3]++;
            break;
        default:
            break;
        }
        sort(arms, arms + 10, cmp);
    }
};
class Iceman : public Warriors
{
    /*iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
    iceman 每前进两步，在第2步完成的时候，生命值会减少9，攻击力会增加20。
    但是若生命值减9后会小于等于0，则生命值不减9,而是变为1。即iceman不会因走多了而死。*/
private:
    int weapon_id;

public:
    virtual void PrintBornInfo(int time) { Warriors::PrintBornInfo(time); }
    virtual bool isEscape() { return false; }
    virtual void Rob(Warriors *Enemy) {}
    virtual bool isYell() { return false; }
    virtual void Fight(Warriors *Enemy, int time) { Warriors::Fight(Enemy, time); }
    virtual void FightBack(Warriors *Enemy, int time) { Warriors::FightBack(Enemy, time); }
    Iceman(Headquarter *pHeadquarter_, int id_, int num_, int location_) : Warriors(pHeadquarter_, id_, num_, location_), weapon_id(num_ % 3)
    {
        switch (num_ % 3)
        {
        case 0:
            if (atk * 2 / 10 > 0)
            {
                arms[weapon_totalnum++] = new Sword(atk * 2 / 10);
                weapon_num[num_ % 3]++;
            }
            break;
        case 1:
            arms[weapon_totalnum++] = new Bomb();
            weapon_num[num_ % 3]++;
            break;
        case 2:
            arms[weapon_totalnum++] = new Arrow();
            weapon_num[num_ % 3]++;

            break;
        default:
            break;
        }
    }
    virtual void March()
    {
        int distance = abs(location + (1 - 2 * color) - (N + 1) * color);
        if (distance % 2 == 0)
        {
            if (hp > 9)
            {
                hp -= 9;
                atk += 20;
            }
            else
            {
                hp = 1;
                atk += 20;
            }
        }
        Warriors::March();
    }
};
class Lion : public Warriors
{
    /*lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。
    每经过一场未能杀死敌人的战斗，忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。
    但是已经到达敌人司令部的lion不会逃跑。Lion在己方司令部可能逃跑。
    lion 若是战死，则其战斗前的生命值就会转移到对手身上。所谓“战斗前”，就是每个小时的40分前的一瞬间。*/
public:
    int loyalty;
    virtual bool isEscape() { return loyalty <= 0; }
    virtual void Rob(Warriors *Enemy) {}
    virtual void Fight(Warriors *Enemy, int time)
    {
        Warriors::Fight(Enemy, time);
        if (!Enemy->is_die && !is_die)
            loyalty -= K;
    }
    virtual void FightBack(Warriors *Enemy, int time)
    {
        Warriors::FightBack(Enemy, time);
        if (!Enemy->is_die && !is_die)
            loyalty -= K;
    }
    virtual bool isYell() { return false; }
    Lion(Headquarter *pHeadquarter_, int id_, int num_, int location_, int loyalty_) : Warriors(pHeadquarter_, id_, num_, location_), loyalty(loyalty_) {}
    virtual void PrintBornInfo(int ntime)
    {
        Warriors::PrintBornInfo(ntime);
        cout << "Its loyalty is " << loyalty << endl;
    } //It's loyalty is 24
    virtual void March()
    {
        Warriors::March();
    }
};
class Wolf : public Warriors
{
    /*wolf降生时没有武器，但是在战斗中如果获胜（杀死敌人），就会缴获敌人的武器，但自己已有的武器就不缴获了。
    被缴获的武器当然不能算新的，已经被用到什么样了，就是什么样的。*/
public:
    virtual void March() { Warriors::March(); }
    virtual bool isEscape() { return false; }
    virtual bool isYell() { return false; }
    Wolf(Headquarter *pHeadquarter_, int id_, int num_, int location_) : Warriors(pHeadquarter_, id_, num_, location_) {}
    virtual void PrintBornInfo(int ntime) { Warriors::PrintBornInfo(ntime); }
    virtual void Rob(Warriors *Enemy);
    virtual void Fight(Warriors *Enemy, int time)
    {
        Warriors::Fight(Enemy, time);
        if (Enemy->is_die && !is_die)
            Rob(Enemy);
    }
    virtual void FightBack(Warriors *Enemy, int time)
    {
        Warriors::FightBack(Enemy, time);
        if (Enemy->is_die && !is_die)
            Rob(Enemy);
    }
};

class Headquarter
{
private:
    int color;                 //指挥部颜色
    bool is_end;               //判断是否停止制造士兵
    int warriors_num[NUM];     //指挥部内各种战士数量
    int current_id;            //当下制造的兵种在该指挥部内的序号
    int warriors_total_num;    //该士兵在该指挥部内的编号
    Warriors *pWarriors[1000]; //指向战士的指针
public:
    int total_hp; //指挥部总生命值
    int t_total_hp;
    friend class Warriors;                    //友元，方便调用私有成员
    static int rules[2][NUM];                 //静态数组，生产士兵的规则
    void __Init__(int color_, int total_hp_); //初始化
    void Produce(int time);                   //制造士兵
    void PrintHpInfo(int time);               //汇报司令部生命元数量
    string Rtcolor();                         //得到颜色的字符串
    int rtcolor() { return color; }
    ~Headquarter(){}; //析构函数
};
class City
{
public:
    Warriors *members[2];
    int members_num[2];
    bool flag[2];
    int hp_stored;
    int win_count[2];
    City()
    {
        win_count[0] = 0;
        win_count[1] = 0;
        hp_stored = 0;
        members_num[0] = 0;
        members_num[1] = 0;
        flag[0] = 0;
        flag[1] = 0;
        members[0] = NULL;
        members[1] = NULL;
    }
} Citys[22];
void Sword::Attack(Warriors *Owner, Warriors *Enemy)
{
    /*sword武器的初始攻击力为拥有它的武士的攻击力的20%（去尾取整）。
    但是sword每经过一次战斗(不论是主动攻击还是反击)，就会变钝，攻击力变为本次战斗前的80% (去尾取整)。
    sword攻击力变为0时，视为武士失去了sword。如果武士降生时得到了一个初始攻击力为0的sword，则视为武士没有sword.
    被攻击者生命值会减去进攻者的攻击力值和进攻者手中sword的攻击力值。*/
    Enemy->Hurt(arm_atk);
    arm_atk = arm_atk * 8 / 10;
    if (arm_atk <= 0)
        durability--;
}
void Bomb::Attack(Warriors *Owner, Warriors *Enemy)
{
    //拥有bomb的武士，在战斗开始前如果判断自己将被杀死（不论主动攻击敌人，或者被敌人主动攻击都可能导致自己被杀死，而且假设武士可以知道敌人的攻击力和生命值），那么就会使用bomb和敌人同归于尽。武士不预测对方是否会使用bomb。
    //武士使用bomb和敌人同归于尽的情况下，不算是一场战斗，双方都不能拿走城市的生命元，也不影响城市的旗帜。
    Enemy->Hurt(Enemy->hp);
    Owner->Hurt(Owner->hp);
    durability -= 1;
}
void Arrow::Attack(Warriors *Owner, Warriors *Enemy)
{
    /*arrow有一个攻击力值R。如果下一步要走到的城市有敌人，那么拥有arrow的武士就会放箭攻击下一个城市的敌人（不能攻击对方司令部里的敌人）而不被还击。
    arrow使敌人的生命值减少R，若减至小于等于0，则敌人被杀死。arrow使用3次后即被耗尽，武士失去arrow。
    两个相邻的武士可能同时放箭把对方射死。*/
    Enemy->Hurt(arm_atk);
    durability--;
}
void Sword::PrintWeaponInfo()
{
    cout << "sword(" << arm_atk << ")";
}
void Bomb::PrintWeaponInfo()
{
    cout << "bomb";
}

void Arrow::PrintWeaponInfo()
{
    cout << "arrow(" << durability << ")";
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
    color = pHeadquarter_->rtcolor();
    is_die = false;
    has_reached = false;
    hp = Warriors::warriors_hp[id_];
    t_hp = hp;
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
    cout << " has ";
    if (weapon_totalnum == 0)
        cout << "no weapon" << endl;
    else
    {
        arms[0]->PrintWeaponInfo();
        for (int i = 1; i < weapon_totalnum; ++i)
        {
            cout << ",";
            arms[i]->PrintWeaponInfo();
        }
        cout << endl;
    }
}
/*000:55 blue wolf 2 has arrow(2),bomb,sword(23)
000:55 blue wolf 4 has no weapon
000:55 blue wolf 5 has sword(20)
表示在0点55分，蓝魔2号武士wolf有一支arrow（这支arrow还可以用2次），一个bomb，还有一支攻击力为23的sword。
蓝魔4号武士wolf没武器。
蓝魔5号武士wolf有一支攻击力为20的sword。
交代武器情况时，次序依次是：arrow,bomb,sword。如果没有某种武器，某种武器就不用提。报告时，先按从西向东的顺序所有的红武士报告，然后再从西向东所有的蓝武士报告。
*/

void Warriors::March()
{
    //y=-2x+1
    //000:10 red iceman 1 marched to city 1 with 20 elements and force 30
    Citys[location].members[color] = NULL;
    Citys[location].members_num[color]--;
    location = location + (-2 * color + 1);
    Citys[location].members[color] = this;
    Citys[location].members_num[color]++;
    return;
}
void Warriors::PrintMarchInfo(int time)
{
    if (has_reached)
        return;
    if (location == 0 || location == N + 1)
    {
        //武士抵达敌军司令部
        has_reached = true;
        printf("%03d:10 ", (time - time % 60) / 60);
        cout << pHeadquarter->Rtcolor() << " " << name << " " << num << " reached ";
        if (pHeadquarter->color == 0)
            cout << "blue";
        else
            cout << "red";
        cout << " headquarter with " << hp << " elements and force " << atk << endl;
        //输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
        //（此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值
    }
    else
    {
        printf("%03d:10 ", (time - time % 60) / 60);
        cout << pHeadquarter->Rtcolor() << " " << name << " " << num;
        cout << " marched to city " << location << " with " << hp << " elements and force " << atk << endl;
    }
}
void Warriors::PrintLostInfo(int time)
{
    //司令部被占领
    printf("%03d:10 ", (time - time % 60) / 60); //输出样例：003:10 blue headquarter was taken
    if (color == 0)
        cout << "blue";
    else
        cout << "red";
    cout << " headquarter was taken" << endl;
    /*int cnt=0;
    for(int i=1;i<=N;++i)
    {
        cnt+=Citys[i].members_num[0]+Citys[i].members_num[1];
    }
    if(Citys[N+1].members_num[0]>=1)
    {
        if(!Citys[N+1].members[0]->has_reached)
            cnt++;
    }
    if(color==1&&cnt>0)
        cout<<endl;*/
}
//000:05 blue lion 1 ran away
void Warriors::PrintEscapeInfo(int time)
{
    printf("%03d:05 ", (time - time % 60) / 60);
    cout << pHeadquarter->Rtcolor() << " lion " << num << " ran away" << endl;
}
void Warriors::takeHp(int time)
{
    int getHp = Citys[location].hp_stored;
    pHeadquarter->total_hp += Citys[location].hp_stored;
    Citys[location].hp_stored = 0;
    printf("%03d:%d %s %s %d earned %d elements for his headquarter\n", (time - time % 60) / 60, time % 60, rtcolor().c_str(), name.c_str(), num, getHp);
}
void Warriors::ArrowAttack(int time)
{
    /*arrow有一个攻击力值R。如果下一步要走到的城市有敌人，那么拥有arrow的武士就会放箭攻击下一个城市的敌人
    （不能攻击对方司令部里的敌人）而不被还击。arrow使敌人的生命值减少R，若减至小于等于0，则敌人被杀死。
    arrow使用3次后即被耗尽，武士失去arrow。两个相邻的武士可能同时放箭把对方射死。
    武士放箭
    输出样例： 000:35 blue dragon 1 shot
    表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭。如果射出的箭杀死了敌人，则应如下输出：
    000:35 blue dragon 1 shot and killed red lion 4
    表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭，杀死了编号为4的红魔lion。*/
    int nextstep = location + (1 - 2 * color);
    if (Citys[nextstep].members_num[1 - color] == 1 && nextstep != 0 && nextstep != N + 1)
    {

        Warriors *Enemy = Citys[nextstep].members[1 - color];
        int tmp = Enemy->hp;
        if (weapon_num[2] > 0)
        {
            //cout<<"arrow called";
            for (int i = 0; i < weapon_totalnum; ++i)
            {
                if (arms[i]->id == 2)
                {
                    arms[i]->Attack(this, Enemy);
                    if (!arms[i]->Can_use())
                    {
                        weapon_totalnum--;
                        weapon_num[2]--;
                        arms[i] = NULL;
                        sort(arms, arms + 10, cmp);
                    }
                    break;
                }
            }
            //cout<<" decrease hp"<<tmp-Enemy->hp<<endl;
            //cout<<Enemy->rtcolor()<<" "<<Enemy->name<<" "<<Enemy->num<<" "<<Enemy->hp<<endl;
            if (Enemy->is_die)
                printf("%03d:35 %s %s %d shot and killed %s %s %d\n", (time - time % 60) / 60, rtcolor().c_str(), name.c_str(), num, Enemy->rtcolor().c_str(), Enemy->name.c_str(), Enemy->num);
            else
                printf("%03d:35 %s %s %d shot\n", (time - time % 60) / 60, rtcolor().c_str(), name.c_str(), num);
        }
    }
    return;
}
void Warriors::BombAttack(Warriors *Enemy, int time)
{
    /*拥有bomb的武士，在战斗开始前如果判断自己将被杀死（不论主动攻击敌人，或者被敌人主动攻击都可能导致自己被杀死，
    而且假设武士可以知道敌人的攻击力和生命值），那么就会使用bomb和敌人同归于尽。武士不预测对方是否会使用bomb。
    武士使用bomb和敌人同归于尽的情况下，不算是一场战斗，双方都不能拿走城市的生命元，也不影响城市的旗帜。
    */
    if (weapon_num[1] == 0)
        return;
    int temphp = hp;
    int tempEnemyhp = Enemy->hp;
    if (!is_die && !Enemy->is_die)
    {
        //cout << "bomb called" << rtcolor() << name << num << " " << hp << endl;
        if (Citys[location].flag[color] == 1 || (location % 2 == 1 - color && Citys[location].flag[1 - color] == 0))
        {
            tempEnemyhp -= atk;
            if (weapon_num[0] > 0)
            {
                for (int i = 0; i < weapon_totalnum; ++i)
                {
                    if (arms[i]->id == 0)
                    {
                        tempEnemyhp -= arms[i]->arm_atk;
                        break;
                    }
                }
            }
            if (tempEnemyhp <= 0)
                return;
            if (Enemy->warrior_id != 1)
            {
                temphp -= Enemy->atk * 5 / 10;
                if (Enemy->weapon_num[0] > 0)
                {
                    for (int i = 0; i < Enemy->weapon_totalnum; ++i)
                    {
                        if (Enemy->arms[i]->id == 0)
                        {
                            temphp -= Enemy->arms[i]->arm_atk;
                            break;
                        }
                    }
                }
            }
            if (temphp > 0)
                return;
        }
        else
        {
            temphp -= Enemy->atk;
            if (Enemy->weapon_num[0] > 0)
            {
                for (int i = 0; i < Enemy->weapon_totalnum; ++i)
                {
                    if (Enemy->arms[i]->id == 0)
                    {
                        temphp -= Enemy->arms[i]->arm_atk;
                        break;
                    }
                }
            }
            //cout<<temphp<<endl;
            if (temphp > 0)
                return;
        }
        /* 武士使用bomb
        输出样例： 000:38 blue dragon 1 used a bomb and killed red lion 7
        表示在 0点38分，编号为1的蓝魔dragon武士用炸弹和编号为7的红魔lion同归于尽。*/
        for (int i = 0; i < weapon_totalnum; ++i)
        {
            if (arms[i]->id == 1)
            {
                arms[i]->Attack(this, Enemy);
                weapon_totalnum--;
                weapon_num[1]--;
                arms[i] = NULL;
                sort(arms, arms + 10, cmp);
                Citys[location].members[0] = NULL;
                Citys[location].members[1] = NULL;
                Citys[location].members_num[0]--;
                Citys[location].members_num[1]--;
                printf("%03d:38 %s %s %d used a bomb and killed %s %s %d\n", (time - time % 60) / 60, rtcolor().c_str(), name.c_str(), num, Enemy->rtcolor().c_str(), Enemy->name.c_str(), Enemy->num);
                break;
            }
        }
    }
    return;
}
void Wolf::Rob(Warriors *Enemy)
{
    /*自己已有的武器就不缴获了。被缴获的武器当然不能算新的，已经被用到什么样了，就是什么样的。*/
    int cnt = 0;
    for (int i = 0; i < Enemy->weapon_totalnum; ++i)
    {
        if (weapon_num[Enemy->arms[i]->id] == 0)
        {
            weapon_num[Enemy->arms[i]->id]++;
            arms[weapon_totalnum] = Enemy->arms[i];
            Enemy->arms[i] = NULL;
            weapon_totalnum++;
            cnt++;
        }
    }
    sort(arms, arms + 10, cmp);
    sort(Enemy->arms, Enemy->arms + 10, cmp);
    return;
}
void Warriors::Fight(Warriors *Enemy, int time)
{
    /*
         武士主动进攻
        输出样例：000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30
        表示在0点40分，1号城市中，红魔1号武士iceman 进攻蓝魔1号武士lion,在发起进攻前，红魔1号武士iceman生命值为20，攻击力为 30
         */
    if (!Enemy->is_die && !is_die)
    {
        Enemy->Hurt(atk);
        printf("%03d:40 %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n", (time - time % 60) / 60, rtcolor().c_str(), name.c_str(), num, Enemy->rtcolor().c_str(), Enemy->name.c_str(), Enemy->num, location, hp, atk);
        if (weapon_num[0] > 0)
        {
            for (int i = 0; i < weapon_totalnum; ++i)
            {
                if (arms[i]->id == 0)
                {
                    arms[i]->Attack(this, Enemy);
                    if (!arms[i]->Can_use())
                    {
                        weapon_totalnum--;
                        weapon_num[0]--;
                        arms[i] = NULL;
                        sort(arms, arms + 10, cmp);
                    }
                    break;
                }
            }
        }
        //输出样例：001:40 red lion 2 was killed in city 1,被箭射死的武士就不会有这一条输出。
        if (Enemy->is_die)
            printf("%03d:40 %s %s %d was killed in city %d\n", (time - time % 60) / 60, Enemy->rtcolor().c_str(), Enemy->name.c_str(), Enemy->num, location);
    }
}
void Warriors::FightBack(Warriors *Enemy, int time)
{ /*武士反击
        输出样例：001:40 blue dragon 2 fought back against red lion 2 in city 1
        表示在1点40分，1号城市中，蓝魔2号武士dragon反击红魔2号武士lion*/
    if (!is_die && !Enemy->is_die)
    {
        printf("%03d:40 %s %s %d fought back against %s %s %d in city %d\n", (time - time % 60) / 60, rtcolor().c_str(), name.c_str(), num, Enemy->rtcolor().c_str(), Enemy->name.c_str(), Enemy->num, location);
        Enemy->Hurt(atk * 5 / 10);
        if (weapon_num[0] > 0)
        {
            for (int i = 0; i < weapon_totalnum; ++i)
            {
                if (arms[i]->id == 0)
                {
                    arms[i]->Attack(this, Enemy);
                    if (!arms[i]->Can_use())
                    {
                        weapon_totalnum--;
                        weapon_num[0]--;
                        arms[i] = NULL;
                        sort(arms, arms + 10, cmp);
                    }
                    break;
                }
            }
        }
        //输出样例：001:40 red lion 2 was killed in city 1,被箭射死的武士就不会有这一条输出。
        if (Enemy->is_die)
            printf("%03d:40 %s %s %d was killed in city %d\n", (time - time % 60) / 60, Enemy->rtcolor().c_str(), Enemy->name.c_str(), Enemy->num, location);
    }
}
void Headquarter::__Init__(int color_, int total_hp_)
{
    color = color_;
    is_end = false;
    total_hp = total_hp_;
    t_total_hp = total_hp;
    for (int i = 0; i < NUM; i++)
        warriors_num[i] = 0;
    current_id = 0;
    warriors_total_num = 0;
}
void Headquarter::Produce(int time)
{
    int warriors_id = rules[color][current_id];
    if (Warriors::warriors_hp[warriors_id] > total_hp)
    {
        is_end = true;
        return;
    }
    else
        is_end = false;
    int start_location = (N + 1) * color; //士兵的出发位置,红魔军(0)的司令部算作编号为0的城市，蓝魔军(1)的司令部算作编号为N+1的城市
    if (Warriors::warriors_hp[warriors_id] > total_hp)
    {
        is_end = true;
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
    for (int i = 0; i <= N + 1; ++i)
    {
        if (Citys[i].members_num[0] == 1)
            Citys[i].members[0]->PrintWarriorInfo(time);
    }
    for (int i = 0; i <= N + 1; ++i)
    {
        if (Citys[i].members_num[1] == 1)
            Citys[i].members[1]->PrintWarriorInfo(time);
    }
}
void GlobalMarch(int time)
{ //同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。
    //表示在0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30
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
    if (Citys[0].members_num[1] >= 1)
    {
        Citys[0].members[1]->PrintMarchInfo(time);
        if (Citys[0].members_num[1] == 2)
        {
            red_lost = true;
            Citys[0].members[1]->PrintLostInfo(time);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (Citys[i].members_num[0] == 1)
            Citys[i].members[0]->PrintMarchInfo(time);
        if (Citys[i].members_num[1] == 1)
            Citys[i].members[1]->PrintMarchInfo(time);
    }
    if (Citys[N + 1].members_num[0] >= 1)
    {
        Citys[N + 1].members[0]->PrintMarchInfo(time);
        if (Citys[N + 1].members_num[0] == 2)
        {
            blue_lost = true;
            Citys[N + 1].members[0]->PrintLostInfo(time);
        }
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
void GlobalArrowAttack(int time)
{
    if (Citys[0].members_num[0] == 1)
        Citys[0].members[0]->ArrowAttack(time);
    for (int i = 1; i <= N; ++i)
    {
        if (Citys[i].members_num[0] == 1)
            Citys[i].members[0]->ArrowAttack(time);
        if (Citys[i].members_num[1] == 1)
            Citys[i].members[1]->ArrowAttack(time);
    }
    if (Citys[N + 1].members_num[1] == 1)
        Citys[N + 1].members[1]->ArrowAttack(time);
}
void GlobalBombAttack(int time)
{
    for (int i = 1; i <= N; ++i)
    {
        if (Citys[i].members_num[0] == 1 && Citys[i].members_num[1] == 1)
            Citys[i].members[0]->BombAttack(Citys[i].members[1], time);
        if (Citys[i].members_num[0] == 1 && Citys[i].members_num[1] == 1)
            Citys[i].members[1]->BombAttack(Citys[i].members[0], time);
    }
}
void Fighting(Warriors *Former, Warriors *Later, int time)
{
    // 如果敌人在5分钟前已经被飞来的arrow射死，那么仍然视为发生了一场战斗，而且存活者视为获得了战斗的胜利。
    //此情况下不会有“武士主动攻击”，“武士反击”，“武士战死”的事件发生，但战斗胜利后应该发生的事情都会发生。
    //如Wolf一样能缴获武器，旗帜也可能更换，等等。在此情况下,Dragon同样会通过判断是否应该轮到自己主动攻击来决定是否欢呼。
    //同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。
    //武士欢呼
    //  输出样例：003:40 blue dragon 2 yelled in city 4
    //武士获取生命元( elements )
    //  输出样例：001:40 blue dragon 2 earned 10 elements for his headquarter
    //  输出不包括在30分不是通过战斗获取的elements
    //旗帜升起
    //  输出样例：004:40 blue flag raised in city 4
    //当某个城市有连续两场战斗都是同一方的武士杀死敌人(两场战斗之间如果有若干个战斗时刻并没有发生战斗，则这两场战斗仍然算是连续的；
    //但如果中间有平局的战斗，就不算连续了) ，那么该城市就会插上胜方的旗帜，若原来插着败方的旗帜，则败方旗帜落下。
    //旗帜一旦插上，就一直插着，直到被敌人更换。一个城市最多只能插一面旗帜，旗帜没被敌人更换前，也不会再次插同颜色的旗。
    //dragon 在一次在它主动进攻的战斗结束后，如果还没有战死，而且士气值大于0.8，就会欢呼。
    int location = Former->location;
    int getHp = Citys[location].hp_stored;
    int flagcolor;
    if (Citys[location].flag[0] == 1)
        flagcolor = 0;
    else if (Citys[location].flag[1] == 1)
        flagcolor = 1;
    else
        flagcolor = -1;
    Former->Fight(Later, time);
    Later->FightBack(Former, time);
    if (!Former->is_die && Former->warrior_id == 0 && Former->isYell())
    {
        printf("%03d:40 %s %s %d yelled in city %d\n", (time - time % 60) / 60, Former->rtcolor().c_str(), Former->name.c_str(), Former->num, location);
    }
    if (Former->is_die && !Later->is_die)
    {
        if (Former->warrior_id == 3)
        {
            //cout<<Former->t_hp<<" ";
            Later->hp += Former->t_hp;
            //cout<<Later->name<<Later->hp<<"+"<<endl;
        }
        Later->takeHp(time);
        if (flagcolor != Later->color)
        {
            Citys[location].win_count[Later->color]++;
            if (Citys[location].win_count[Later->color] == 2)
            {
                Citys[location].flag[Later->color] = 1;
                Citys[location].flag[1 - Later->color] = 0;
                printf("%03d:40 %s flag raised in city %d\n", (time - time % 60) / 60, Later->rtcolor().c_str(), location);
            }
        }
        Citys[location].win_count[1 - Later->color] = 0;
    }
    if (!Former->is_die && Later->is_die)
    {
        if (Later->warrior_id == 3)
        {
            //cout<<Later->t_hp<<" ";
            Former->hp += Later->t_hp;
            //cout<<Former->name<<Former->hp<<"+"<<endl;
        }
        Former->takeHp(time);
        if (flagcolor != Former->color)
        {
            Citys[location].win_count[Former->color]++;
            if (Citys[location].win_count[Former->color] == 2)
            {
                Citys[location].flag[Former->color] = 1;
                Citys[location].flag[1 - Former->color] = 0;
                printf("%03d:40 %s flag raised in city %d\n", (time - time % 60) / 60, Former->rtcolor().c_str(), location);
            }
        }
        Citys[location].win_count[1 - Former->color] = 0;
    }
    if (!Former->is_die && !Later->is_die)
    {
        Citys[location].win_count[0] = 0;
        Citys[location].win_count[1] = 0;
    }
}
void GlobalFight(int time)
{
    //武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。战斗的规则是：
    //在插红旗的城市，以及编号为奇数的无旗城市，由红武士主动发起进攻。在插蓝旗的城市，以及编号为偶数的无旗城市，由蓝武士主动发起进攻。
    //每次战斗只有一方发起主动进攻一次。被攻击者生命值会减去进攻者的攻击力值和进攻者手中sword的攻击力值。被进攻者若没死，就会发起反击，被反击者的生命值要减去反击者攻击力值的一半(去尾取整)和反击者手中sword的攻击力值。反击可能致敌人于死地。
    //如果武士在战斗中杀死敌人（不论是主动进攻杀死还是反击杀死），则其司令部会立即向其发送8个生命元作为奖励，使其生命值增加8。当然前提是司令部得有8个生命元。如果司令部的生命元不足以奖励所有的武士，则优先奖励距离敌方司令部近的武士。
    //如果某武士在某城市的战斗中杀死了敌人，则该武士的司令部立即取得该城市中所有的生命元。注意，司令部总是先完成全部奖励工作，然后才开始从各个打了胜仗的城市回收生命元。对于因司令部生命元不足而领不到奖励的武士，司令部也不会在取得战利品生命元后为其补发奖励。
    //如果一次战斗的结果是双方都幸存(平局)，则双方都不能拿走发生战斗的城市的生命元。
    for (int i = 1; i <= N; ++i)
    {
        if (Citys[i].members_num[0] == 1 && Citys[i].members_num[1] == 1)
        {
            if ((i % 2 == 0 && Citys[i].flag[0] == 0) || Citys[i].flag[1] == 1)
                Fighting(Citys[i].members[1], Citys[i].members[0], time);
            else if ((i % 2 == 1 && Citys[i].flag[1] == 0) || Citys[i].flag[0] == 1)
                Fighting(Citys[i].members[0], Citys[i].members[1], time);
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (Citys[i].members_num[0] == 1 && Citys[i].members_num[1] == 1)
        {
            if (Citys[i].members[0]->is_die && !Citys[i].members[1]->is_die)
            {
                if (Citys[i].members[1]->pHeadquarter->t_total_hp >= 8)
                {
                    //cout << "allocate";
                    Citys[i].members[1]->pHeadquarter->t_total_hp -= 8;
                    Citys[i].members[1]->pHeadquarter->total_hp -= 8;
                    //cout << Citys[i].members[1]->hp << " ";
                    Citys[i].members[1]->hp += 8;
                    //cout << Citys[i].members[1]->hp << endl;
                }
            }
        }
    }
    for (int i = N; i >= 1; --i)
    {
        if (Citys[i].members_num[0] == 1 && Citys[i].members_num[1] == 1)
        {
            if (Citys[i].members[1]->is_die && !Citys[i].members[0]->is_die)
            {
                if (Citys[i].members[0]->pHeadquarter->t_total_hp >= 8)
                {
                    //cout << "allocate";
                    Citys[i].members[0]->pHeadquarter->t_total_hp -= 8;
                    Citys[i].members[0]->pHeadquarter->total_hp -= 8;
                    Citys[i].members[0]->hp += 8;
                    //cout << Citys[i].members[0]->hp << endl;
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (Citys[i].members_num[0] == 1)
        {
            if (Citys[i].members[0]->is_die)
            {
                Citys[i].members_num[0]--;
                Citys[i].members[0] = NULL;
            }
        }
        if (Citys[i].members_num[1] == 1)
        {
            if (Citys[i].members[1]->is_die)
            {
                Citys[i].members_num[1]--;
                Citys[i].members[1] = NULL;
            }
        }
    }
}
void GlobalHpIncrease()
{
    for (int i = 1; i <= N; ++i)
        Citys[i].hp_stored += 10;
}
void GlobalTakeHp(int time)
{
    //如果某个城市中只有一个武士，那么该武士取走该城市中的所有生命元，并立即将这些生命元传送到其所属的司令部。
    for (int i = 1; i <= N; ++i)
    {
        if (Citys[i].members_num[0] == 1 && Citys[i].members_num[1] == 0)
            Citys[i].members[0]->takeHp(time);
        if (Citys[i].members_num[0] == 0 && Citys[i].members_num[1] == 1)
            Citys[i].members[1]->takeHp(time);
    }
}
void GlobalThpSet()
{
    for (int i = 0; i <= N + 1; ++i)
    {
        if (Citys[i].members_num[0] == 1)
            Citys[i].members[0]->t_hp = Citys[i].members[0]->hp;
        if (Citys[i].members_num[1] == 1)
            Citys[i].members[1]->t_hp = Citys[i].members[1]->hp;
    }
}
string Warriors::warriors_name[NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int Headquarter::rules[2][NUM] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}};
//红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。//蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
int Warriors::warriors_hp[NUM] = {0};
int Warriors::warriors_atk[NUM] = {0};
int main()
{
    /*输入
    第一行是t,代表测试数据组数
    每组样例共三行。
    第一行，五个整数 M,N,R,K, T。其含义为：
    每个司令部一开始都有M个生命元( 1 <= M <= 10000)
    两个司令部之间一共有N个城市( 1 <= N <= 20 )
        arrow的攻击力是R
    lion每经过一场未能杀死敌人的战斗，忠诚度就降低K。
    要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 5000
    第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000
    第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于10000
    */
    int cnt = 1;
    //freopen("test.txt", "w", stdout);
    cin >> t;
    while (t--)
    {
        Headquarter red, blue;
        memset(Warriors::warriors_atk, 0, sizeof(Warriors::warriors_atk));
        memset(Warriors::warriors_hp, 0, sizeof(Warriors::warriors_hp));
        red_lost = false;
        blue_lost = false;
        for (int i = 0; i < 22; ++i)
        {
            Citys[i].members[0] = NULL;
            Citys[i].members[1] = NULL;
            Citys[i].members_num[0] = 0;
            Citys[i].members_num[1] = 0;
            Citys[i].flag[0] = 0;
            Citys[i].flag[1] = 0;
            Citys[i].win_count[0] = 0;
            Citys[i].win_count[1] = 0;
            Citys[i].hp_stored = 0;
        }
        cout << "Case " << cnt << ":" << endl;
        cnt++;
        cin >> M >> N >> R >> K >> T;
        for (int i = 0; i < NUM; ++i)
            cin >> Warriors::warriors_hp[i];
        for (int i = 0; i < NUM; ++i)
            cin >> Warriors::warriors_atk[i];
        red.__Init__(0, M);
        blue.__Init__(1, M); //初始化指挥部
        for (int time = 0; time <= T; time += 1)
        {
            switch (time % 60)
            {
                //如果司令部中的生命元不足以制造某武士，那么司令部就等待，直到获得足够生命元后的第一个整点，才制造该武士。
                //例如，在2:00，红方司令部本该制造一个 wolf ，如果此时生命元不足，那么就会等待，直到生命元足够后的下一个整点，才制造一个 wolf。
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
                GlobalMarch(time);
                break;
                //在每个小时的第20分：每个城市产出10个生命元。生命元留在城市，直到被武士取走。
            case 20:
                GlobalHpIncrease();
                break;
                //在每个小时的第30分：如果某个城市中只有一个武士，那么该武士取走该城市中的所有生命元，并立即将这些生命元传送到其所属的司令部。
            case 30:
                GlobalTakeHp(time);
                break;
                //在每个小时的第35分：拥有arrow的武士放箭
            case 35:
                GlobalArrowAttack(time);
                break;
                //在每个小时的第38分，拥有bomb的武士评估是否应该使用bomb。如果是，就用bomb和敌人同归于尽。
            case 38:
                GlobalThpSet();
                red.t_total_hp = red.total_hp;
                blue.t_total_hp = blue.total_hp;
                GlobalBombAttack(time);
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
