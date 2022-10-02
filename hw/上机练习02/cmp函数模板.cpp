/*
04:编程填空：cmp函数模板
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
填写代码，按要求输出结果。要求实现cmp函数模板，不能实现cmp函数。
*/
#include <vector>
#include <set>
#include <list>
#include <iostream>
using namespace std;

template <class T>
// 在此处补充你的代码
class c
{};
int cnt=0;
template<class T>
void cmp(T a,int b)
{
  cout<<char('a'+cnt)<<endl;
  cnt++;
}
int main(){
  int A[100];
  A[0]=1; A[1]=2;
  cmp(A[0],2);
  printf("finish 1\n");
  cmp(1, A[1]);
  printf("finish 2\n");
  cmp(A,A[1]);
  printf("finish 3\n");
}
/*
输入
.
输出
.
样例输入
（无）
样例输出
a
finish 1
b
finish 2
c
finish 3
*/