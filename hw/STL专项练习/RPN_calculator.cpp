//
//  main.cpp
//  RPN calculator
//
//  Created by 寿晨宸 on 2022/4/10.
//
/*
B:RPN Calculator
查看提交统计提问
总时间限制: 1000ms 内存限制: 10000kB
描述
Reverse Polish notation (or just RPN) by analogy with the related Polish notation, a prefix notation introduced in 1920 by the Polish mathematician Jan Łukasiewicz, is a mathematical notation wherein every operator follows all of its operands. It is also known as Postfix notation.

In Reverse Polish notation the operators follow their operands; for instance, to add three and four one would write "3 4 +" rather than "3 + 4". If there are multiple operations, the operator is given immediately after its second operand; so the expression written "3 − 4 + 5" in conventional infix notation would be written "3 4 − 5 +" in RPN: first subtract 4 from 3, then add 5 to that. An advantage of RPN is that it obviates the need for parentheses that are required by infix. While "3 − 4 * 5" can also be written "3 − (4 * 5)", that means something quite different from "(3 − 4) * 5", and only the parentheses disambiguate the two meanings. In postfix, the former would be written "3 4 5 * −", which unambiguously means "3 (4 5 *) −".

You were asked to design a simple RPN calculator, which will support the “+”, “-“, “*”, “/”(the absolute value of the divisor will not less then 10^-9) and “^”(power operator, if the base number b<=0, the exponential e must be a positive integer not greater than 10^9) operators. You can assume all the numbers during the calculation can fit into a double-precision floating point number.

In addition, our calculator has some memory. Each time we calculate an expression, the smallest number in the memory will be erased, and replace it with the value of the expression.

输入
The first line contains an integer n, which is the memory size of our calculator.


From the second line, we will give n numbers, which is the initial value of the memory. each line except last will have 10 numbers.


And then each line has a valid RPN expression we previously described, end with “=”, which is the command for calculation. Each term will no longer than 20 characters.

输出
For each expression, output the value of it in a line.
And then output an empty line to separate the two parts.
At last, output the all the numbers in memory, in increasing order, 10 numbers per line.

Each number should be formatted in scientific notation with 6 digits after decimal point and 2 digits of exponential, such like “%e” format string of printf() function in C. The numbers in a line should be separated by a space.
样例输入
4
1e6 1e-6 0.001 1000
1 2 + 3 4 + * =
1 0.1 / 8 ^ =
样例输出
2.100000e+01
1.000000e+08

2.100000e+01 1.000000e+03 1.000000e+06 1.000000e+08
提示
Huge input, scanf() is recommended

%e格式输出在windows环境下指数部分为3位，在系统的测试环境下为2位。
*/

#include <iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;
void Calculate(string symbol,stack<double>& nums)
{
    double num1=nums.top();nums.pop();
    double num2=nums.top();nums.pop();
    if(symbol=="+")nums.push(num1+num2);
    if(symbol=="-")nums.push(num2-num1);
    if(symbol=="*")nums.push(num2*num1);
    if(symbol=="/")nums.push(num2/num1);
    if(symbol=="^")nums.push(pow(num2, num1));
}
void RPN(string &symbol,stack<double> &nums)
{
    if(symbol!="+"&&symbol!="-"&&symbol!="*"&&symbol!="/"&&symbol!="^")
        nums.push(atof(symbol.c_str()));
    else 
        Calculate(symbol,nums);
}
int main(int argc, const char * argv[])
{
    int n;
    cin>>n;
    priority_queue<double,vector<double>,greater<double> > p;
    stack<double>nums;
    for(int i=0;i<n;++i)
    {
        double tmp;
        cin>>tmp;
        p.push(tmp);
    }
    getchar();
    string RPNcal;
    string symbol;
    while(getline(cin,RPNcal))
    {
        int id1=0,id2=RPNcal.length()-1;
        for(int i=0;i<=RPNcal.length();++i)
        {
            if(RPNcal[i]==' '||RPNcal[i]=='\0')
            {
                id2=i;
                symbol=RPNcal.substr(id1,id2-id1);
                id1=id2+1;
                if(symbol=="=")
                {
                    printf("%e\n",nums.top());
                    p.pop();
                    p.push(nums.top());
                    nums.pop();
                    if(!nums.empty())
                        printf("expect empty\n");
                }
                else
                    RPN(symbol, nums);
            }
        }
    }
    printf("\n");
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        cnt++;
        if(i==n)
            printf("%e",p.top());
        else if(cnt%10==0)
            printf("%e\n",p.top());
        else
            printf("%e ",p.top());
        p.pop();
    }
    return 0;
}
/*
后缀表达式的计算
用一个栈来存储数字，从左向左右遍历表达式
遇到数字就压栈
遇到操作符就弹出栈中的两个数字计算并压栈
最后栈中剩余的数字是我们要的结果
*/
