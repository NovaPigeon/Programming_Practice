//
//  main.cpp
//  List
//
//  Created by 寿晨宸 on 2022/4/8.
//

/*
A:List
查看提交统计提问
总时间限制: 4000ms 内存限制: 65536kB
描述
写一个程序完成以下命令：
new id ——新建一个指定编号为id的序列(id<10000)
add id num——向编号为id的序列加入整数num
merge id1 id2——合并序列id1和id2中的数，并将id2清空
unique id——去掉序列id中重复的元素
out id ——从小到大输出编号为id的序列中的元素，以空格隔开

输入
第一行一个数n，表示有多少个命令( n＜＝２０００００)。以后n行每行一个命令。
输出
按题目要求输出。
样例输入
16
new 1
new 2
add 1 1
add 1 2
add 1 3
add 2 1
add 2 2
add 2 3
add 2 4
out 1
out 2
merge 1 2
out 1
out 2
unique 1
out 1
样例输出
1 2 3
1 2 3 4
1 1 2 2 3 3 4

1 2 3 4
*/
#include<list>
#include <iostream>
#include<string.h>
#include <algorithm>
using namespace std;
int main()
{
    /*string cmd;
    int n;
    cin>>n;
    map <int, vector<int>> lists;
    while(n--)
    {
        cin>>cmd;
        if(cmd=="new")
        {
            int id;
            cin>>id;
            lists[id];
        }
        else if(cmd=="add")
        {
            int id,num;
            cin>>id>>num;
            lists[id].push_back(num);
            sort(lists[id].begin(),lists[id].end());
        }
        else if(cmd=="merge")
        {
            int id1,id2;
            cin>>id1>>id2;
            vector<int>::iterator i=lists[id2].begin();
            for(;i!=lists[id2].end();++i)
                lists[id1].push_back(*i);
            lists[id2].clear();
            sort(lists[id1].begin(),lists[id1].end());
        }
        else if(cmd=="unique")
        {
            int id;
            cin>>id;
            vector<int>::iterator i=unique(lists[id].begin(), lists[id].end());
            int len=lists[id].end()-i;
            for(int j=0;j<len;++j)
                lists[id].pop_back();
        }
        else if(cmd=="out")
        {
            int id;
            cin>>id;
            vector<int>::iterator i=lists[id].begin();
            for(;i!=lists[id].end();++i)
                cout<<*i<<" ";
            cout<<endl;
        }
    }
     */
    int n;
    cin>>n;
    list<int> l[10000];
    string cmd;
    while(n--)
    {
        cin>>cmd;
        int num,id,id1,id2;
        if(cmd=="new")
        {
            cin>>num;
        }
        else if(cmd=="add")
        {
            cin>>id>>num;
            l[id].push_back(num);
        }
        else if(cmd=="merge")
        {
            cin>>id1>>id2;
            l[id1].merge(l[id2]);
        }
        else if(cmd=="unique")
        {
            cin>>id;
            l[id].sort();
            l[id].unique();
        }
        else if(cmd=="out")
        {
            cin>>id;
            l[id].sort();
            list<int>::iterator i=l[id].begin();
            for(;i!=l[id].end();++i)
                cout<<*i<<" ";
            cout<<endl;
        }
    }
    return 0;
}
