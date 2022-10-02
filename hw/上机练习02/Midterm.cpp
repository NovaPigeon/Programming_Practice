/*
06:编程填空：Midterm
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
填写缺失的部分，使程序输出要求的结果。
*/
#include<iostream>
using namespace std;

class Midterm {
private:
  int val; 
public:
// 在此处补充你的代码
    Midterm(int val_=0):val(val_){}
    friend ostream& operator<<(ostream& os,const Midterm& m)
    {
        os<<m.val;
        return os;
    }
    Midterm operator+(int a){return Midterm(val+a);}
    Midterm& operator++(int k){val++;return *this;}
    Midterm& operator-=(int a){val-=a;return*this;}
    operator int(){return val;}

};

int Min(int a,int b) {
  if(a < b)
    return a;
  else
    return b;
}
int main(){
  Midterm a; 
  cout << a << endl;
  cout << a + 2021 << endl;
  Midterm b(1000);
  cout << b ++ << endl; 
  ((b-=10)-=20)-=30;
  cout << b ++ << endl; 
  cout << Min(255,b) <<endl;
  return 0;
}
/*
输入
.
输出
.
样例输入
(无)
样例输出
0
2021
1001
942
255
*/