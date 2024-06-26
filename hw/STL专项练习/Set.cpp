//
//  main.cpp
//  Set
//
//  Created by 寿晨宸 on 2022/4/10.
//
/*
C:Set
查看提交统计提问
总时间限制: 5000ms 内存限制: 100000kB
描述
现有一整数集（允许有重复元素），初始为空。我们定义如下操作：
add x 把x加入集合
del x 把集合中所有与x相等的元素删除
ask x 对集合中元素x的情况询问
对每种操作，我们要求进行如下输出。
add 输出操作后集合中x的个数
del 输出操作前集合中x的个数
ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。
输入
第一行是一个整数n，表示命令数。0<=n<=100000。
后面n行命令，如Description中所述。
输出
共n行，每行按要求输出。
样例输入
7
add 1
add 1
ask 1
ask 2
del 2
del 1
ask 1
样例输出
1
2
1 2
0 0
0
2
1 0
提示
Please use STL’s set and multiset to finish the task
*/
#include <iostream>
#include <string.h>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,ele;
    int cnt[100000]={0};
    string cmd;
    cin>>n;
    multiset<int>nums;
    while(n--)
    {
        cin>>cmd;
        if(cmd=="add")
        {
            cin>>ele;
            nums.insert(ele);
            cnt[ele]=1;
            cout<<nums.count(ele)<<endl;
        }
        else if(cmd=="del")
        {
            cin>>ele;
            cout<<nums.count(ele)<<endl;
            nums.erase(ele);
        }
        else if(cmd=="ask")
        {
            cin>>ele;
            cout<<cnt[ele]<<" "<<nums.count(ele)<<endl;
        }
    }
    return 0;
}
