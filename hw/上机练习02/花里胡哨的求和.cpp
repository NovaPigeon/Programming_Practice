/*
05:编程填空:花里胡哨的求和
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
读入 n 个数, 输出 n 个数, 其中第 i 个数是读入中前 i 个数的和
*/
#include<iostream>
#include<vector>
using namespace std;
class A{
// 在此处补充你的代码
public:
    static int presum;
    int val;
    A(int val_):val(val_+presum){presum+=val_;}
    void output(){cout<<val<<endl;}
};
int A::presum=0;
int main(){
  int n;cin>>n;
  vector<A*> p;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    p.push_back(new A(x));
  }
  for(int i=0;i<n;i++){
    p[i]->output();
  }
  return 0;
}
/*
输入
.
输出
.
样例输入
3
1 2 3
样例输出
1
3
6
*/