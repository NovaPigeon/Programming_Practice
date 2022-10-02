/*
0008:编程填空：维护平面点
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，一开始平面上一个点都没有
每次可以插入一个点，删除一个已经存在的点，或者按照x 或y 来查询一个存在的点
保证任何时候任意两个点一定是一个点严格在另一个点的右下方
即两点(x1, y1), (x2, y2)，必定有x1 > x2 且y1 < y2 ，或者x1 < x2 且y1 > y2
*/

#include <set>
#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
//判断谁在右下方，并考虑-1的情况
typedef pair<int,int> Key;
class myComp
{
public:
    bool operator()(const Key &a,const Key &b)const
    {
        if(a.first>=0&&a.second>=0&&b.first>=0&&b.second>=0)
        {
            return a.first>b.first && a.second<b.second;
        }
        else 
        {
            if(a.first<0||b.first<0){
                return a.second<b.second;
            }
            else if(a.second<0||b.second<0){
                return a.first>b.first;
            }

        }

    }
};
int main() {
	string cmd;
	set<pair<int, int>, myComp> S;
	while (cin >> cmd) {
		if (cmd == "A") {
			int x, y;
			cin >> x >> y;
			S.insert(make_pair(x, y));
		} else if (cmd == "Qx") {
			int x;
			cin >> x;
			cout << S.lower_bound(make_pair(x, -1))->second << endl;
		} else if (cmd == "Qy") {
			int y;
			cin >> y;
			cout << S.lower_bound(make_pair(-1, y))->first << endl;
		} else {
			int x, y;
			cin >> x >> y;
			S.erase(make_pair(x, y));
		}
	}
	return 0;
}
/*
输入
输入数据的每一行，格式为以下之一：
A x y
R x y
Qx x
Qy y
其中 x 与 y 都是 0 到 10^9 之间的整数
A x y 表示插入点 (x, y)
R x y 表示删除点 (x, y)，保证存在
Qx x 表示在当前所有点中，找到第一维为x的点，输出其第二维的值，保证存在
Qy y 表示在当前所有点中，找到第二维为y的点，输出其第一维的值，保证存在
总共操作数不超过100000
输出
对于每一个 Qx 和 Qy 操作，输出一行表示对应的答案
样例输入
A 3 5
A 4 2
Qx 4
R 4 2
A 4 3
Qy 3
样例输出
2
4
*/