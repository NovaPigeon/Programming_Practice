//
//  main.cpp
//  山寨版istream_iterator
//
//  Created by 寿晨宸 on 2022/3/27.
//

/*
E:山寨版istream_iterator
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
模仿C++标准模板库istream_iterator用法，实现CMyistream_iterator使得程序按要求输出
*/
#include <iostream>
#include <string>
using namespace std;
template <class T>
class CMyistream_iterator
{
// 在此处补充你的代码
private:
    istream& is;
    T val;
public:
    CMyistream_iterator(istream& is_):is(is_)
    {
        is>>val;
    }
    T operator *()
    {
        return val;
    }
    void operator++(int k)
    {
        is>>val;
    }
};
int main()
{
    int t;
    cin >> t;
    while( t -- ) {
         CMyistream_iterator<int> inputInt(cin);//不通过参数实例化函数模板
         int n1,n2,n3;
         n1 = * inputInt; //读入 n1
         int tmp = * inputInt;
         cout << tmp << endl;
         inputInt ++;
         n2 = * inputInt; //读入 n2
         inputInt ++;
         n3 = * inputInt; //读入 n3
         cout << n1 << " " << n2<< " " << n3 << " ";
         CMyistream_iterator<string> inputStr(cin);
         string s1,s2;
         s1 = * inputStr;
         inputStr ++;
         s2 = * inputStr;
         cout << s1 << " " << s2 << endl;
    }
     return 0;
}
/*输入
第一行是整数t，表示有t组数据
每组数据一行，三个整数加两个字符串。字符串是不含空格的
输出
对每组数据，输出二行
在第一行输出第一个数
第二行原样输出输入的内容
样例输入
2
79 90 20 hello me
12 34 19 take up
样例输出
79
79 90 20 hello me
12
12 34 19 take up
提示
C++标准模板库 istream_iterator模版使用说明：

其构造函数执行过程中就会要求输入，然后每次执行++，则读取输入流中的下一个项目，执行 * 则返回上次从输入流中读取的项目。例如，下面程序运行时，就会等待用户输入数据，输入数据后程序才会结束：
#include
#include
using namespace std;
int main() {
istream_iterator inputInt(cin);
return 0;
}

下面程序运行时，如果输入 12 34 程序输出结果是： 12,12
#include
#include
using namespace std;
int main()
{
istream_iterator inputInt(cin);
cout << * inputInt << "," << * inputInt << endl;
return 0;
}

下面程序运行时，如果输入 12 34 56程序输出结果是： 12,56
#include
#include
using namespace std;
int main()
{
istream_iterator inputInt(cin);
cout << * inputInt << "," ;
inputInt ++;
inputInt ++;
cout << * inputInt;
return 0;
}
来源
Guo Wei
*/
