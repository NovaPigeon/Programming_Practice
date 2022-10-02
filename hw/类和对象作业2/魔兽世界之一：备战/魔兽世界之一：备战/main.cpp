//
//  main.cpp
//  魔兽世界之一：备战
//
//  Created by 寿晨宸 on 2022/3/2.
//
/*描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。

每组测试数据共两行。

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。
输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
样例输入
1
20
3 4 5 6 7
样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors*/
#include <iostream>
#include <string>
#include<cstring>
#include<math.h>
#include<algorithm>
const int NUM=5;//部队人数
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
    Warriors(Headquarter* pHeadquarter_,int id_,int num_);//构造函数
    void PrintInfo(int time);//打印信息
    
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
    pWarriors[warriors_total_num]=new Warriors(this,warriors_id,warriors_total_num+1);
    warriors_num[warriors_id]++;
    pWarriors[warriors_total_num]->PrintInfo(time);//new一个Warriors的指针，方便调用PrintInfo函数
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


