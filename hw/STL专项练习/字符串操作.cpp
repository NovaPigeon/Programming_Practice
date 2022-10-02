//
//  main.cpp
//  字符串操作
//
//  Created by 寿晨宸 on 2022/4/10.
//
/*
D:字符串操作
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定n个字符串（从1开始编号），每个字符串中的字符位置从0开始编号，长度为1-500，现有如下若干操作：

copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。
add S1 S2：判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。
find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
insert S N X：在第N个字符串的第X个字符位置中插入S字符串。
reset S N：将第N个字符串变为S。
print N：打印输出第N个字符串。
printall：打印输出所有字符串。
over：结束操作。
其中N，X，L可由find与rfind操作表达式构成，S，S1，S2可由copy与add操作表达式构成。

输入
第一行为一个整数n（n在1-20之间）


接下来n行为n个字符串，字符串不包含空格及操作命令等。


接下来若干行为一系列操作，直到over结束。

输出
根据操作提示输出对应字符串。

样例输入
3
329strjvc
Opadfk48
Ifjoqwoqejr
insert copy 1 find 2 1 2 2 2
print 2
reset add copy 1 find 3 1 3 copy 2 find 2 2 2 3
print 3
insert a 3 2
printall
over
样例输出
Op29adfk48
358
329strjvc
Op29adfk48
35a8
提示
推荐使用string类中的相关操作函数。
*/

#include <iostream>
#include <string>
#include<fstream>
using namespace std;
int n;
string strn[30];
string cmd;
bool is_num(const string&s)
{
    
    for(int i=0;i<s.length();++i)
        if(s[i]>'9'||s[i]<'0')
            return false;
    return true;
}       
string work()
{
    cin>>cmd;
    if(cmd=="over")
        return "";
    else if(cmd=="add")
    {
        string str1=work();
        string str2=work();
        if(is_num(str1)&&is_num(str2))
        {
            int a=atoi(str1.c_str()),b=atoi(str2.c_str());
            if(a>=0&&a<=99999&&b>=0&&b<=99999)
                return to_string(a+b);
        }
        return str1+str2;
    }
    else if(cmd=="find")
    {
        string str=work();
        int id=atoi(work().c_str())-1;
        if(strn[id].find(str,0)!=string::npos)
            return to_string(strn[id].find(str,0));
        else
            return to_string(int(str.length()));
    }
    else if(cmd=="rfind")
    {
        string str=work();
        int id=atoi(work().c_str());
        if(strn[id].rfind(str,strn[id].length()-1)!=string::npos)
            return to_string(strn[id].rfind(str,strn[id].length()-1));
        else
            return to_string(int(str.length()));
    }
    else if(cmd=="insert")
    {
        string str=work();
        int id=atoi(work().c_str())-1;
        int x=atoi(work().c_str());
        strn[id].insert(x, str);
    }
    else if(cmd=="reset")
    {
        string str=work();
        int id=atoi(work().c_str())-1;
        strn[id].assign(str);
    }
    else if(cmd=="copy")
    {
        int id=atoi(work().c_str())-1;
        int x=atoi(work().c_str());
        int l=atoi(work().c_str());
        return strn[id].substr(x,l);
    }
    else if(cmd=="print")
    {
        int id=atoi(work().c_str())-1;
        cout<<strn[id]<<endl;
    }
    else if(cmd=="printall")
    {
        for(int i=0;i<n;++i)
            cout<<strn[i]<<endl;
    }
    else
        return cmd;
    return "";
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //freopen("in.txt","r",stdin);
    freopen("test.txt","w",stdout);
    //cout<<is_num("8889nz")<<" "<<atoi("8889nz");
    cin>>n;
    string temp;
    for(int i=0;i<n;++i)
    {
        cin>>temp;
        strn[i].assign(temp);
    }
    while(1)
    {
        cmd="";
        string r=work();
        if(cmd=="over")
            break;
    }
    return 0;
}
