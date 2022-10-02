//
//  main.cpp
//  自己实现bitset
//
//  Created by 寿晨宸 on 2022/4/13.
//

/*
C:自己实现bitset
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，实现一个类似STL bitset的 MyBitset, 输出指定结果
 */
#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset
{
    char a[bitNum/8+1];
    MyBitset() { memset(a,0,sizeof(a));};
    void Set(int i,int v) {
        char & c = a[i/8];
        int bp = i % 8;
        if( v )
            c |= (1 << bp);
        else
            c &= ~(1 << bp);
    }
    //由于bitNum不止8位，故1字节无法处理所有请求，使用a，把a的每一个char的二进制连起来后就形成要求的二进制数
// 在此处补充你的代码
    class refer
    {
    public:
        int bits[20];
        int flag;
        refer(){memset(bits, 0, sizeof(int)*20);flag=1;}
        int &operator()(int k,MyBitset& p)
        {
            if(flag)
            {
                for(int i=0;i<20;++i)
                {
                    bits[i]=((p.a[i/8]&(1<<(i%8)))>>(i%8));
                }
                flag=0;
            }
            return bits[k];
        }
    };
    refer reference;
    int& operator[](int k)
    {
        return reference(k,*this);
    }
void Print() {
        for(int i = 0;i < bitNum; ++i)
            cout << (*this) [i];
        cout << endl;
    }

};

int main()
{
    int n;
    int i,j,k,v;
    while( cin >>  n) {
        MyBitset<20> bs;
        for(int i = 0;i < n; ++i) {
            int t;
            cin >> t;
            bs.Set(t,1);
        }
        bs.Print();
        cin >> i >> j >> k >> v;
        bs[k] = v;
        bs[i] = bs[j] = bs[k];
        bs.Print();
        cin >> i >> j >> k >> v;
        bs[k] = v;
        (bs[i] = bs[j]) = bs[k];
        bs.Print();
    }
    return 0;
}
/*
输入
多组数据
每组数据：
第一行是整数 n , 1 <= n < 20;
第二行是n个整数 k1,k2... kn,均在范围 [0,19]内。
第三行是 四个整数 i1,j1,k1,v1 。 0 <= i1,j1,k1 <= 19, v1值为0或1
第三行是 四个整数 i2,j2,k2,v2 。 0 <= i2,j2,k2 <= 19, v2值为0或1
输出
对每组数据，共输出3行，每行20位，每位为1或者0。最左边称为第0位
第一行： 第 k1,k2 ... kn位为1，其余位为0。
第二行： 将第一行中的第 i1,j1,k1位变为 v1,其余位不变
第三行： 将第二行中的第i2位和k2位变为v2，其余位不变
样例输入
4
0 1 2 8
7 19 0 1
7 2 8 0
1
1
1 1 1 0
1 1 1 1
样例输出
11100000100000000000
11100001100000000001
11100000000000000001
01000000000000000000
00000000000000000000
01000000000000000000
提示
推荐使用内部类，内部类中使用引用成员。引用成员要在构造函数中初始化。
来源
Guo Wei
*/
