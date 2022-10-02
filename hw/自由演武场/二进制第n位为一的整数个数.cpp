/*
0003:编程填空：二进制第n位为1的整数个数
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
给出一组整数，统计其中有多少整数符合条件“二进制表示的第n位为1”
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
class Pred
{
	public:
		int n;
		Pred(int n_):n(n_){}
		bool operator()(int val)
		{
			if(((val>>n)&1)==1)
				return true;
			else
				return false;
		}
};
int main(int argc, char** argv) {	
	int n, x;
	vector<int> intVec;
	cin>>n>>x; 
	while(x) {
		intVec.push_back(x);
		cin>>x;
	}
	cout<<count_if(intVec.begin(), intVec.end(), Pred(n))<<endl;
	return 0;
}
/*
输入
输入数据包含两行
第一行为正整数n (0 <= n < 32)
第二行是一组待统计的整数，以0表示结束。
输出
输出一行，为符合条件“二进制表示的第n位为1”的整数个数
样例输入
0
1 2 3 4 5 0
样例输出
3
提示
最右边一位为第0位
*/