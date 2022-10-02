
/*
A:Boolean Expressions
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
The objective of the program you are going to produce is to evaluate boolean expressions as the one shown next:
Expression: ( V | V ) & F & ( F | V )

where V is for True, and F is for False. The expressions may include the following operators: ! for not , & for and, | for or , the use of parenthesis for operations grouping is also allowed.

To perform the evaluation of an expression, it will be considered the priority of the operators, the not having the highest, and the or the lowest. The program must yield V or F , as the result for each expression in the input file.
输入
The expressions are of a variable length, although will never exceed 100 symbols. Symbols may be separated by any number of spaces or no spaces at all, therefore, the total length of an expression, as a number of characters, is unknown.

The number of expressions in the input file is variable and will never be greater than 20. Each expression is presented in a new line, as shown below.
输出
For each test expression, print "Expression " followed by its sequence number, ": ", and the resulting value of the corresponding test expression. Separate the output for consecutive test expressions with a new line.

Use the same format as that shown in the sample output shown below.
样例输入
( V | V ) & F & ( F| V)
!V | V & V & !F & (F | V ) & (!F | F | !V & V)
(F&F|V|!V&!F&!(F|F&V))
样例输出
Expression 1: F
Expression 2: V
Expression 3: V
来源
México and Central America 2004
*/
#include<iostream>
#include<cstring>
using namespace std;
char eps[150]={'\0'};
char true_eps[150]={'\0'};
int eps_ptr=0;
bool not_value();
bool factor_value();
bool item_value();
bool expression_value();
int main()
{
    int cnt=0;
    while(cin.getline(eps,150))
    {
        cnt++;
        int strcnt=0;
        eps_ptr=0;
        for(int i=0;i<strlen(eps);++i)
        {
            if(eps[i]!='\0'&&eps[i]!='\n'&&eps[i]!=' ')
            {
                true_eps[strcnt]=eps[i];
                strcnt++;
            }
        }
        cout<<"Expression "<<cnt<<": ";
        if(expression_value()==true)
            cout<<"V"<<endl;
        else
            cout<<"F"<<endl;
    }
    return 0;
}
bool expression_value()
{
    bool res=item_value();
    while(true_eps[eps_ptr]=='|')
    {
        eps_ptr++;
        res=res|item_value();
    }
    return res;
}
bool item_value()
{
    bool res=factor_value();
    while(true_eps[eps_ptr]=='&')
    {
        eps_ptr++;
        res=res&factor_value();
    }
    return res;
}
bool factor_value()
{
    bool res=true;
    switch (true_eps[eps_ptr])
    {
    case 'V':
        eps_ptr++;
        res=true;
        break;
    case 'F':
        eps_ptr++;
        res=false;
        break;
    case '(':
        eps_ptr++;
        res=expression_value();
        eps_ptr++;
        break;
    case '!':
        res=not_value(); 
        break;
    default:
        break;
    }
    return res;
}
bool not_value()
{
    bool res=false;
    eps_ptr++;
    switch (true_eps[eps_ptr])
    {
    case 'V':
        eps_ptr++;
        res=true;
        break;
    case 'F':
        eps_ptr++;
        res=false;
        break;
    case '(':
        eps_ptr++;
        res=expression_value();
        eps_ptr++;
        break;
    case '!':
        res=not_value(); 
        break;
    default:
        break;
    }
    return !res;
    
}