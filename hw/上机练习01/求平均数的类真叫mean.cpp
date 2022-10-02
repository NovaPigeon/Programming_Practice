/*
07:求平均数的类真叫mean
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一系列正整数, 计算它们的平均值，结果去尾取整数
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class CMean {
// 在此处补充你的代码
public:
    int& aver;
    int cnt;
    int sum;
    CMean(int& aver_):aver(aver_),cnt(0),sum(0){}
    void operator()(int& val)
    {
        cnt++;
        //cout<<cnt<<" "<<val<<endl;
        sum=sum+val;
        aver=sum/cnt;
    }
};

int main(int argc, char* argv[]) {
	int  v;
	int t;
	cin >> t;
	while ( t -- ) {
		cin >> v;
		vector<int> vec;
		while (v) {
			vec.push_back(v);
			cin >> v;
		}
		int myAver = 0;
		for_each(vec.begin(), vec.end(), CMean(myAver));
		cout << myAver << endl;
	}
	return 0;
}
/*
输入
第一行是测试数据组数T
接下T行，每行一组数据。每行是若干个正整数，以0表示输入结束(0不算)。
输出
对每组数据，输出所有数的平均值，结果去尾取整数
样例输入
1
17 4 8 18 0 
样例输出
11
*/