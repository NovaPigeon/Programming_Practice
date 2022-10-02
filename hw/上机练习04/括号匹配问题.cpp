/*
02E:扩号匹配问题
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；
规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。
写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。
不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.
输入
输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100
注意：cin.getline(str,100)最多只能输入99个字符！
输出
对每组输出数据，输出两行，第一行包含原始输入字符，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。
样例输入
((ABCD(x)
)(rttyy())sss)(
样例输出
((ABCD(x)
$$
)(rttyy())sss)(
?            ?$
*/
#include<iostream>
#include<string.h>
using namespace std;
char a[101],b[101];
int find(int i)
{
    if(i==-1)
        return -1;
    else if(b[i]=='$')
        return i;
    else 
        return find(i-1);
}
int main()
{
    while(scanf("%s",a)!=-1)
    {
        cout<<a<<endl;
        int len=strlen(a);
        memset(b,' ',sizeof(b));
        for(int i=0;i<len;++i)
        {
            if(a[i]=='(')
                b[i]='$';
            else if(a[i]==')')
            {
                if(find(i-1)==-1)
                    b[i]='?';
                else
                    b[find(i-1)]=' ';
            }
            else
                b[i]=' ';
        }
        cout<<b<<endl;
    }
    return 0;
}