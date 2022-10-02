//
//  main.cpp
//  魔兽世界之二：装备
//
//  Created by 寿晨宸 on 2022/3/18.
//
/*描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。
有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

不同的武士有不同的特点。
dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
wolf没特点。
请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
如果造出的是dragon，那么还要输出一行，例：
It has a arrow,and it's morale is 23.34
表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
如果造出的是ninja，那么还要输出一行，例：
It has a bomb and a arrow
表示该ninja降生时得到了bomb和arrow。
如果造出的是iceman，那么还要输出一行，例：
It has a sword
表示该iceman降生时得到了sword。
如果造出的是lion，那么还要输出一行，例：
It's loyalty is 24
表示该lion降生时的忠诚度是24。
2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在 10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。

每组测试数据共两行。

第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000
输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
样例输入
1
20
3 4 5 6 7
样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors
 */
#include <iostream>
#include <string>
#include<cstring>
#include<math.h>
#include<algorithm>
const int NUM=5;//部队人数
const int WEAPONKINDS=3;
using namespace std;
class Warriors;//战士类
class Headquarter;//指挥部类
class Warriors
{
private:
    Headquarter* pHeadquarter;//指向指挥部的指针
    int warrior_id;//战士种类的代号
    int num;
    
public:
    friend class Headquarter;//友元，方便调用私有成员
    static string warriors_name[NUM];//静态数组，指某种代号的战士的名称
    static int warriors_hp[NUM];//静态数组，指某种代号的战士的生命值
    static string weapons[WEAPONKINDS];//静态数组，指战士的武器
    Warriors(Headquarter* pHeadquarter_,int id_,int num_);//构造函数
    virtual void PrintInfo(int time);//打印信息
    
};
/*
 不同的武士有不同的特点。
 dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
 ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
 iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
 lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
 wolf没特点。 */
class Dragon:public Warriors
{
private:
    int weapon_num;
    double morale;
public:
    Dragon(Headquarter* pHeadquarter_,int id_,int num_,double morale_):Warriors(pHeadquarter_,id_,num_),weapon_num(num_%3),morale(morale_){}
    virtual void PrintInfo(int ntime)
    {
        Warriors::PrintInfo(ntime);
        printf("It has a ");
        cout<<Warriors::weapons[weapon_num];
        printf(",and it's morale is %.2f\n",morale);
    }//It has a arrow,and it's morale is 23.34
};
class Ninja:public Warriors
{
private:
    int weapon_num1;
    int weapon_num2;
public:
    Ninja(Headquarter* pHeadquarter_,int id_,int num_):Warriors(pHeadquarter_,id_,num_),weapon_num1(num_%3),weapon_num2((num_+1)%3){}
    virtual void PrintInfo(int ntime)
    {
        Warriors::PrintInfo(ntime);
        cout<<"It has a "<<Warriors::weapons[weapon_num1]<<" and a "<<Warriors::weapons[weapon_num2]<<endl;
        
    }//It has a bomb and a arrow
};
class Iceman:public Warriors
{
private:
    int weapon_num;
public:
    Iceman(Headquarter* pHeadquarter_,int id_,int num_):Warriors(pHeadquarter_,id_,num_),weapon_num(num_%3){}
    virtual void PrintInfo(int ntime)
    {
        Warriors::PrintInfo(ntime);
        cout<<"It has a "<<Warriors::weapons[weapon_num]<<endl;
    }//It has a sword
};
class Lion:public Warriors
{
private:
    int loyalty;
public:
    Lion(Headquarter* pHeadquarter_,int id_,int num_,int loyalty_):Warriors(pHeadquarter_,id_,num_),loyalty(loyalty_){}
    virtual void PrintInfo(int ntime)
    {
        Warriors::PrintInfo(ntime);
        cout<<"It's loyalty is "<<loyalty<<endl;
    }//It's loyalty is 24
};
class Wolf:public Warriors
{
public:
    Wolf(Headquarter* pHeadquarter_,int id_,int num_):Warriors(pHeadquarter_,id_,num_){}
    virtual void PrintInfo(int ntime)
    {
        Warriors::PrintInfo(ntime);
    }
};
class Headquarter
{
private:
    int color;//指挥部颜色
    bool is_end;//判断是否停止制造士兵
    int total_hp;//指挥部总生命值
    int warriors_num[NUM];//指挥部内各种战士数量
    int current_id;//当下制造的兵种在该指挥部内的序号
    int warriors_total_num;//该士兵在该指挥部内的编号
    Warriors* pWarriors[1000];//指向战士的指针
public:
    friend class Warriors;//友元，方便调用私有成员
    static int rules[2][NUM];//静态数组，生产士兵的规则
    
    void __Init__(int color_,int total_hp_);//初始化
    int Produce(int time);//制造士兵
    string Rtcolor();//得到颜色的字符串
    ~Headquarter();//析构函数
    
};
Warriors::Warriors(Headquarter* pHeadquarter_,int id_,int num_)
{
    pHeadquarter=pHeadquarter_;
    warrior_id=id_;
    num=num_;
}
void Warriors::PrintInfo(int time)
{
    string color=pHeadquarter->Rtcolor();
    printf("%03d",time);
    cout<<" "<<color<<" "<<warriors_name[warrior_id]<<" "<<num<<" born with strength "<<warriors_hp[warrior_id]<<","<<pHeadquarter->warriors_num[warrior_id]<<" "<<warriors_name[warrior_id]<<" in "<<color<<" headquarter"<<endl;
}//000 red iceman 1 born with strength 5,1 iceman in red headquarter

void Headquarter::__Init__(int color_, int total_hp_)
{
    color=color_;
    is_end=false;
    total_hp=total_hp_;
    for(int i=0;i<NUM;i++)
        warriors_num[i]=0;
    current_id=0;
    warriors_total_num=0;
    
}
int Headquarter::Produce(int time)
{
    if(is_end)
        return 0;//若已停止制造士兵，则终止函数
    int cnt_seek=0;
    while(Warriors::warriors_hp[rules[color][current_id]]>total_hp && cnt_seek<NUM)
    {
        current_id=(current_id+1)%NUM;
        cnt_seek++;
    }//若当前总生命值小于特定兵种生命值，跳过，遍历所有兵种
    int warriors_id=rules[color][current_id];
    if(Warriors::warriors_hp[warriors_id]>total_hp)//遍历过后仍无法制造士兵，则停止制造
    {
        is_end=true;
        //004 blue headquarter stops making warriors
        printf("%03d ",time);
        cout<<Rtcolor()<<" headquarter stops making warriors"<<endl;
        return 0;
    }
    //制造士兵
    total_hp=total_hp-Warriors::warriors_hp[warriors_id];//更新总生命值
    current_id=(current_id+1)%NUM;
    double hp=double(total_hp);
    double dragon_hp=double(Warriors::warriors_hp[0]);
    switch (warriors_id) {
        case 0:pWarriors[warriors_total_num]=new Dragon(this,warriors_id,warriors_total_num+1,hp/dragon_hp);break;
        case 1:pWarriors[warriors_total_num]=new Ninja(this,warriors_id,warriors_total_num+1);break;
        case 2:pWarriors[warriors_total_num]=new Iceman(this,warriors_id,warriors_total_num+1);break;
        case 3:pWarriors[warriors_total_num]=new Lion(this,warriors_id,warriors_total_num+1,total_hp);break;
        case 4:pWarriors[warriors_total_num]=new Wolf(this,warriors_id,warriors_total_num+1);
        default:
            break;
    }//"dragon","ninja","iceman","lion","wolf"
    warriors_num[warriors_id]++;
    pWarriors[warriors_total_num]->PrintInfo(time);//多态
    warriors_total_num++;
    
    //更新其他信息
    return 1;
    
    
}
string Headquarter::Rtcolor()
{
    if(color == 0)
        return "red";
    else
        return "blue";
}
Headquarter::~Headquarter()
{
    for(int i=0;i<warriors_total_num;i++)
        delete pWarriors[i];
}
string Warriors::warriors_name[NUM]={"dragon","ninja","iceman","lion","wolf"};
int Headquarter::rules[2][NUM]={{2,3,4,1,0},{3,0,1,2,4}};
//红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。//蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
int Warriors::warriors_hp[NUM]={0};
string Warriors::weapons[WEAPONKINDS]={"sword","bomb","arrow"};//武器有三种，sword, bomb,和arrow
int main()
{
    int N,M,cnt=1;
    cin>>N;
    Headquarter red,blue;
    while(N--)
    {
        int time=0;
        cout<<"Case:"<<cnt<<endl;
        cnt++;
        cin>>M;
        for(int i=0;i<NUM;i++)
            cin>>Warriors::warriors_hp[i];
        red.__Init__(0, M);
        blue.__Init__(1, M); //初始化指挥部
        while(true)
        {
            int red_flag=red.Produce(time);
            int blue_flag=blue.Produce(time);//制造士兵的同时，判断是否已经停止制造
            time++;
            if(red_flag==0 && blue_flag==0)
                break;
        }
    }
    return 0;
}
