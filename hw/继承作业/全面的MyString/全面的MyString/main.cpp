//
//  main.cpp
//  全面的MyString
//
//  Created by 寿晨宸 on 2022/3/17.
//


/*A:全面的MyString
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，输出指定结果*/

#include <cstdlib>
#include <iostream>
using namespace std;
/*int strlen(const char * s)
{    int i = 0;
    for(; s[i]; ++i);
    return i;
}
void strcpy(char * d,const char * s)
{
    int i = 0;
    for( i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;
        
}*/
int strcmp(const char * s1,const char * s2)
{
    for(int i = 0; s1[i] && s2[i] ; ++i) {
        if( s1[i] < s2[i] )
            return -1;
        else if( s1[i] > s2[i])
            return 1;
    }
    return 0;
}
/*void strcat(char * d,const char * s)
{
    int len = strlen(d);
    strcpy(d+len,s);
}*/
class MyString
{
    char *p;
// 在此处补充你的代码
public:
    MyString(const char *p_=NULL)
    {
        if(p_)
        {
            p=new char[strlen(p_)+1];
            strcpy(p,p_);
        }
        else
        {
            p=new char[1];
            p[0]='\0';
        }
    }
    MyString(const MyString& s)
    {
        if(s.p)
        {
            p=new char[strlen(s.p)+1];
            strcpy(p,s.p);
        }
        else
        {
            p=new char[1];
            p[0]='\0';
        }
    }
    ~MyString(){if(p)delete [] p;}
    MyString operator+(const MyString& s)
    {
        char *temp=new char[strlen(p)+strlen(s.p)+1];
        strcpy(temp,p);
        strcat(temp, s.p);
        return MyString(temp);
    }
    friend MyString operator+(const char *p_,const MyString& s_)
    {
        char *temp=new char[strlen(p_)+strlen(s_.p)+1];
        strcpy(temp,p_);
        strcat(temp, s_.p);
        return MyString(temp);
    }
    MyString& operator+=(const char *s)
    {
        char *p_=new char[strlen(p)+1];
        strcpy(p_,p);
        delete [] p;
        p=new char[strlen(p)+strlen(s)+1];
        strcpy(p,p_);
        strcat(p,s);
        return *this;
    }
    MyString operator()(int sta,int len)
    {
        MyString s_;
        delete [] s_.p;
        s_.p=new char[len+1];
        for(int i=0;i<len;++i)
            s_.p[i]=p[sta+i];
        s_.p[len]='\0';
        return s_;
    }
    MyString& operator=(const MyString& s)
    {
        if(p==s.p)
            return *this;
        delete [] p;
        if(s.p)
        {
            p=new char[strlen(s.p)+1];
            strcpy(p,s.p);
        }
        else
        {
            p=new char[1];
            p[0]='\0';
        }
        return *this;
    }
    MyString& operator=(const char *s)
    {
        if(p==s)
            return *this;
        delete [] p;
        if(s)
        {
            p=new char[strlen(s)+1];
            strcpy(p,s);
        }
        else
        {
            p=new char[1];
            p[0]='\0';
        }
        return *this;
    }
    char &operator[](int n)
    {
        return p[n];
    }
    friend ostream& operator<<(ostream& os,const MyString& s)
    {
        if(s.p)
        os<<s.p;
        return os;
    }
    friend bool operator<(const MyString& s1,const MyString& s2)
    {
        if(strcmp(s1.p,s2.p)<0)
            return true;
        else
            return false;
    }
    friend bool operator==(const MyString& s1,const MyString& s2)
    {
        if(strcmp(s1.p,s2.p)==0)
            return true;
        else
            return false;
    }
    friend bool operator>(const MyString& s1,const MyString& s2)
    {
        if(strcmp(s1.p,s2.p)>0)
            return true;
        else
            return false;
    }
    
};


int CompareString( const void * e1, const void * e2)
{
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( * s1 < *s2 )
    return -1;
    else if( *s1 == *s2)
    return 0;
    else if( *s1 > *s2 )
    return 1;
    return 0;
}
int main()
{
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString),CompareString);
    for( int i = 0;i < 4;i ++ )
    cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}
/*输入
无
输出
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
样例输入
无
样例输出
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
来源
Guo Wei
*/
