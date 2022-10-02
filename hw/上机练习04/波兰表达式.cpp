/*
02D:波兰表达式
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
波兰表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的波兰表示法为+ 2 3。波兰表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，例如(2 + 3) * 4的波兰表示法为* + 2 3 4。本题求解波兰表达式的值，其中运算符包括+ - * /四个。

输入
输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。
输出
输出为一行，表达式的值。
可直接用printf("%f\n", v)输出表达式的值v。
样例输入
* + 11.0 12.0 + 24.0 35.0
样例输出
1357.000000
提示
可使用atof(str)把字符串转换为一个double类型的浮点数。atof定义在math.h中。
此题可使用函数递归调用的方法求解。
来源
计算概论05
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
double PolandExpression()
{
    string sign;
    cin>>sign;
    
    if(sign=="+")
        return PolandExpression()+PolandExpression();
    else if(sign=="-")
        return PolandExpression()-PolandExpression();
    else if(sign=="*")
        return PolandExpression()*PolandExpression();
    else if(sign=="/")
        return PolandExpression()/PolandExpression();
    else
        return atof(sign.c_str());
}

int main()
{
    double res=PolandExpression();
    printf("%f\n", res);
    return 0;
}