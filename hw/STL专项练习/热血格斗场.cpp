//
//  main.cpp
//  热血格斗场
//
//  Created by 寿晨宸 on 2022/4/10.
//
/*
E:热血格斗场
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家热血格斗场。格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。

我们假设格斗的实力可以用一个正整数表示，成为实力值。另外，每个人都有一个唯一的id，也是一个正整数。为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，如果有两个人的实力值与他差别相同，则他会选择比他弱的那个（显然，虐人必被虐好）。

不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。

输入
第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。以后n行每一行两个数，按照入会的时间给出会员的id和实力值。一开始，facer就算是会员，id为1，实力值1000000000。输入保证两人的实力值不同。

输出
N行，每行两个数，为每场比赛双方的id，新手的id写在前面。

样例输入
3
2 1
3 3
4 2
样例输出
2 1
3 2
4 2
*/

/*#include <iostream>
#include<vector>
#include <climits>
#include <cmath>
using namespace std;
struct info
{
public:
    int id;
    int val;
    info(int id_,int val_):id(id_),val(val_){}
    info(){}
};
int main(int argc, const char * argv[]) {
    
    int n,id,val;
    cin>>n;
    vector<info>members;
    members.push_back(info(1,10000));
    while(n--)
    {
        cin>>id>>val;
        int mindis=INT_MAX;
        int eneid=1;
        vector<info>::iterator i=members.end()-1;
        for(;i!=members.begin()-1;--i)
        {
            if(abs((*i).val-val)<mindis)
            {
                mindis=abs((*i).val-val);
                eneid=(*i).id;
            }
           if(abs((*i).val-val)==mindis)
           {
               if((*i).val<val)
                   eneid=(*i).id;
           }
        }
        members.push_back(info(id,val));
        cout<<id<<" "<<eneid<<endl;
    }
    return 0;
}
 */
/*
 #include<iostream>
 #include<map>
 using namespace std;
 int main()
 {
     int id,power,num;
     multimap<int ,int> data;
     data.insert(make_pair(1000000000,1));//第一个数据
     cin >> num;
     while(num --)
     {
         cin >> id >> power;
         multimap<int ,int>::iterator im,in,i,j;
         im = data.insert(make_pair(power,id));
         if(im == data.begin()){//判断是否是第一个元素
             in = im;
             in++;
              cout<<im->second <<" "<< in->second << endl;
         }
         else if(im == (--data.end())){//判断是否是最后一个元素
             in = im;
             --in;
             cout<<im->second <<" "<< in->second << endl;
         }
         else{
             i = im;
             --i;
             j = im;
             ++j;
             if(im->first - i->first > (j->first - im->first))
                 cout<<im->second <<" "<< j->second<<endl;
             else
                 cout<<im->second <<" "<< i->second<<endl;
         }
         
     }
 }
  
*/
/*
 #include <iostream>
 #include <string>
 #include <map>
 #include <cmath>
 using namespace std;
 typedef map<int,int> mmii;

 int main()
 {
     int members,id,attack;
     cin>>members;
     string func;
     mmii boxingmap;
     mmii::iterator p1,p2;
     boxingmap.insert(make_pair(1000000000,1));
     while(members--)
     {
         cin>>id>>attack;
         p1 = boxingmap.lower_bound(attack);
         p2 = boxingmap.upper_bound(attack);
         if(p1 == boxingmap.begin() || abs((--p1)->first-attack) > abs(p2->first-attack))  p1 = p2;
         cout<<id<<' '<<p1->second<<endl;
         boxingmap.insert(make_pair(attack,id));
     }
     return 0;
 }


 */
#include <iostream>
#include<map>
#include<cmath>
using namespace std;
int main()
{
    map<int,int>members;
    members.insert(make_pair(1000000000, 1));
    map<int,int>::iterator i1,i2;
    int n,id,val;
    cin>>n;
    while(n--)
    {
        cin>>id>>val;
        i1=members.lower_bound(val);
        i2=members.upper_bound(val);
        if(i1==members.begin()||abs((--i1)->first-val)>abs(i2->first-val))
            i1=i2;
        cout<<id<<" "<<i1->second<<endl;
        members.insert(make_pair(val, id));
    }
}
