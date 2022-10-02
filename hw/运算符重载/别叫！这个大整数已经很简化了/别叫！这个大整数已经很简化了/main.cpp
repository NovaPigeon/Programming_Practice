//
//  main.cpp
//  别叫！这个大整数已经很简化了
//
//  Created by 寿晨宸 on 2022/3/11.
//

/*
E:别叫，这个大整数已经很简化了!
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，输出指定结果*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

class CHugeInt {
// 在此处补充你的代码
private:
    char hugenum[220];
    int len=0;
public:
    CHugeInt(int n)
    {
        int i=0;
        if(n==0)
            {
                    hugenum[i++]='0';
            }else{
                while(n)
                {
                    hugenum[i++]=n%10+'0';
                    n=n/10;
                }
            }
            hugenum[i]='\0';
        len=i;
        //cout<<hugenum<<endl;
    }
    CHugeInt(char *p)
    {
        strcpy(hugenum,p);
        len=strlen(p);
        for(int i=0;i<len/2;++i)
            swap(hugenum[i],hugenum[len-i-1]);
        hugenum[len]='\0';
        //cout<<hugenum<<endl;
    }
    CHugeInt()
    {
        len=0;
    }
    friend ostream& operator<<(ostream& os, const CHugeInt& num)
    {
        for(int i=num.len-1;i>=0;--i)
            os<<num.hugenum[i];
        return os;
    }
    friend CHugeInt operator+( int n, CHugeInt a)
    {
        CHugeInt b(n);
        return a+b;
    }
    CHugeInt& operator+(int n)
    {
        CHugeInt b(n);
        *this=this->operator+(b);
        return *this;
    }
    CHugeInt operator+(CHugeInt b)
    {
        CHugeInt ans;
        memset(ans.hugenum,'0',sizeof(hugenum));
        if(len>b.len)
        {
            for(int i=b.len;i<len+1;i++)
                b.hugenum[i]='0';
            hugenum[len]='0';
        }
        else
        {
            for(int i=len;i<b.len+1;i++)
                hugenum[i]='0';
            b.hugenum[b.len]='0';
        }
        for(int i=0;i<max(len,b.len);i++)
        {
            ans.hugenum[i]+=(b.hugenum[i]-'0'+hugenum[i]-'0')%10;
            b.hugenum[i+1]+=(b.hugenum[i]-'0'+hugenum[i]-'0')/10;
        }
        ans.hugenum[max(len,b.len)]=b.hugenum[max(len,b.len)];
        if(ans.hugenum[max(len,b.len)]!='0')
        {
            ans.len=max(len,b.len)+1;
            //cout<<ans.hugenum[len]<<endl;
        }
        else
        {
            ans.len=max(len,b.len);
        }
            ans.hugenum[ans.len]='\0';
        //cout<<ans.hugenum<<endl;
        //cout<<ans.len<<endl;
        //cout<<len<<endl;
        
        return ans;
    }
    
    CHugeInt operator++()
    {
        *this=this->operator+(1);
        return *this;
    }
    CHugeInt operator++(int k)
    {
        CHugeInt temp;
        temp=*this;
        *this=this->operator+(1);
        return temp;
    }
    CHugeInt& operator+=(int n)
    {
        *this=this->operator+(n);
        return *this;
    }
    ~CHugeInt()
    {
        //cout<<"CALLED"<<endl;
    }
    CHugeInt(const CHugeInt &b)
    {
        strcpy(hugenum,b.hugenum);
        len=b.len;
    }
};
int  main()
{
    char s[210];
    int n;

    while (cin >> s >> n) {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout  << ++ b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}
/*输入
多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示
输出
对每组数据，输出6行，内容分别是：
样例输入
99999999999999999999999999888888888888888812345678901234567789 12
6 6
样例输出
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
25
25
26
12
12
12
13
13
14
来源
Guo Wei*/
