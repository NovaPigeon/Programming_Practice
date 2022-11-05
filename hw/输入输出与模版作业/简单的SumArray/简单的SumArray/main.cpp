//
//  main.cpp
//  简单的SumArray
//
//  Created by 寿晨宸 on 2022/3/27.
//


/*A:简单的SumArray
总时间限制: 1000ms 内存限制: 65536kB
描述
填写模板 PrintArray,使得程序输出结果是： TomJackMaryJohn 10 不得编写SumArray函数
*/
#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(
// 在此处补充你的代码
T* st,T* ed)
{
    T sum=*st;
    for(T* i=st+1;i<ed;++i)
        sum=sum+*i;
    return sum;
        
}
int main() {
    string array[4] = { "Tom","Jack","Mary","John"};
    cout << SumArray(array,array+4) << endl;
    int a[4] = { 1, 2, 3, 4};  //提示：1+2+3+4 = 10
    cout << SumArray(a,a+4) << endl;
    return 0;
}
/*
输入
无
输出
TomJackMaryJohn
10
样例输入
无
样例输出
TomJackMaryJohn
10
来源
Guo Wei
*/
