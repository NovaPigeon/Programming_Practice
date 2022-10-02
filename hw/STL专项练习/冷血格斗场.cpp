//
//  main.cpp
//  冷血格斗场
//
//  Created by 寿晨宸 on 2022/4/10.
//
/*
 
 F:冷血格斗场
 查看提交统计提问
 总时间限制: 1000ms 内存限制: 65536kB
 描述
 为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家冷血格斗场。格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。

 我们假设格斗的实力可以用一个非负整数表示，称为实力值，两人的实力值可以相同。另外，每个人都有一个唯一的id，也是一个正整数。为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，如果有多个人的实力值与他差别相同，则他会选择id最小的那个。

 不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。

 输入
 第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。以后n行每一行两个数，按照入会的时间给出会员的id和实力值。一开始，facer就算是会员，id为1，实力值1000000000。

 输出
 N行，每行两个数，为每场比赛双方的id，新手的id写在前面。

 样例输入
 3
 2 3
 3 1
 4 2
 样例输出
 2 1
 3 2
 4 2
 
*/

/*
#include <iostream>
#include<map>
#include<cmath>
using namespace std;
typedef multimap<int,int> mmid;
int main(int argc, const char * argv[])
{
    int n,id,val;
    mmid members;
    members.insert(make_pair(1000000000, 1));
    mmid::iterator i1,i2,i;
    cin>>n;
    while(n--)
    {
        cin>>id>>val;
        i1=members.lower_bound(val);
        i2=members.upper_bound(val);
        if(i1==members.begin())
        {
            i=i2;
            cout<<id<<" "<<i->second<<endl;
            members.insert(make_pair(val, id));
            continue;
        }
        else
            i1--;
        
        if(abs(i1->first-val)<abs(i2->first-val))
           i=i1;
        else if(abs(i1->first-val)>abs(i2->first-val))
           i=i2;
        else
        {
            if(i1->second<i2->second)
                i=i1;
            else
                i=i2;
        }
        cout<<id<<" "<<i->second<<endl;
        members.insert(make_pair(val, id));
    }
    return 0;
}
*/

#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int n,id,val;
class men
{
public:
    int id;
    int val;
    men(int id_,int val_):id(id_),val(val_){}
    men(){}
};
bool cmp(const men& a,const men& b)
{
    if(abs(a.val-val)<abs(b.val-val))
        return true;
    if(abs(a.val-val)==abs(b.val-val))
    {
        if(a.id<b.id)
            return true;
        else
            return false;
    }
    return false;
}
int main()
{
    vector<men>members;
    men temp(1,1000000000);
    members.push_back(temp);
    cin>>n;
    while(n--)
    {
        cin>>id>>val;
        sort(members.begin(),members.end(),cmp);
        cout<<id<<" "<<members[0].id<<endl;
        members.push_back(men(id,val));
    }
    return 0;
}
/*
 #include<iostream>
 #include<map>
 #include<cmath>
 using namespace std;
 const int MAXN=10000+10;
 int N,id,p;
 map<int,int> mp;//first为实力，second为id
 int main(){
     freopen("C:\\Users\\Ambition\\Desktop\\in.txt","r",stdin);
     mp[1000000000]=1;//facer
     scanf("%d",&N);
     for(int i=0; i<N; ++i){
         scanf("%d%d",&id,&p);
         map<int,int>::iterator it;
         it=mp.lower_bound(p);
         if(it==mp.end()) it--;//没有实力比他大的
         int t=abs(it->first-p);
         int idx=it->second;
         if(it!=mp.begin()){
             it--;
             if(abs(it->first-p)<t||(abs(it->first-p)==t&&it->second<idx))//如果实力值相等取id较小的
                 idx=it->second;
         }
         printf("%d %d\n",id,idx);
         it=mp.find(p);
         if(it==mp.end()||it->second>id) mp[p]=id;//如果原来map中没有或者id比输入id大就更新它
     }
     return 0;
 } 
 */
