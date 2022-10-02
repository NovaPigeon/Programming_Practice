/*
10:宠物小精灵
查看提交统计提问
总时间限制: 1500ms 内存限制: 65536kB
描述
宠物小精灵的世界中，每位训练师都在收集自己的小精灵。但是，训练师的背包里只能同时携带6只小精灵。
如果一位训练师抓到了更多的精灵，那么最早抓到的精灵将被自动传送到电脑中，保证持有的小精灵数量依然是6只。 
训练师也可以随时从电脑中取出精灵，取出的精灵将从电脑中传送到训练师的背包里。取出的精灵同样被认为是最新的，
导致背包中最早取出或抓到的精灵被替换到电脑中，训练师持有的精灵数量依然是6只。 
初始状态下，所有训练师的背包中都没有小精灵，电脑中也没有任何训练师的精灵。

输入
输入数据包含多组测试。第一行一个整数T(1<=T<=20)，表示测试数据数目。
每组数据第一行有一个正整数N(1<=N<=20000)表示发生事件的数目。
接下来有N行分别表示发生的事件。
一共有两种事件：
C X, Y 表示训练师X抓到了精灵Y
T X, Y 表示训练师X试图从电脑中取出精灵Y。

X和Y都是长度在20以下的由字母或数字构成的字符串。

小精灵的世界中同样存在着作恶多端的火箭队。他们试图利用电脑的漏洞，
从电脑中取出本不属于自己的小精灵。因此，电脑需要识别并拒绝取出这种请求。
注意，如果一只小精灵仅存在于训练师的背包中而未被传送至电脑，该训练师也不能取出这只精灵。
相同训练师不会多次抓到相同名字的精灵。
输出
对于每次从电脑中取出小精灵的请求，输出一行。成功则输出Success，失败则输出Failed。
样例输入
1 10
C satoshi pikachu1
C satoshi pikachu2
C satoshi pikachu3
C satoshi pikachu4
C satoshi pikachu5
C satoshi pikachu6
C satoshi pikachu7
T satoshi pikachu2
T satoshi pikachu1
T pikachu pikachu2
样例输出
Failed
Success
Failed
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int T,N;
    string cmd,owner,pet;
    cin>>T;
    while(T--)
    {
        cin>>N;
        map<string,vector<string> > bag;
        map<string,vector<string> > computer;
        for(int i=0;i<N;++i)
        {
            cin>>cmd>>owner>>pet;
            if(cmd=="C")
            {
                bag[owner];
                if(bag[owner].end()-bag[owner].begin()<6)
                    bag[owner].push_back(pet);
                else
                {
                    string tmp=bag[owner].front();
                    bag[owner].push_back(pet);
                    bag[owner].erase(bag[owner].begin());
                    computer[owner].push_back(tmp);
                }
            }
            if(cmd=="T")
            {
                if(computer.find(owner)==bag.end())
                    cout<<"Failed"<<endl;
                else
                {
                    vector<string>::iterator i=computer[owner].begin();
                    for(;i!=computer[owner].end();++i)
                        if(*i==pet)
                            break;
                    if(i==computer[owner].end())
                        cout<<"Failed"<<endl;
                    else
                        cout<<"Success"<<endl;
                }
            }
        }
        computer.clear();
        bag.clear();
    }

    return 0;
}