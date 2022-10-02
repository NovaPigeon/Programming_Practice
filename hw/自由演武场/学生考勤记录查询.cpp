/*
0007:编程填空：学生考勤记录查询
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
学生考勤记录查询，可以完成下面三条操作：
1)add date id，例如add 1 1500012755，学号为1500012755的学生，在本月1日缺勤
2)querydate_begin date_end，例如query 1 3，查询本月1日至本月3日（包含1日及3日）缺勤学生名单，输出格式为（同一日内缺勤的学生输出顺序与add操作顺序一致）：
date id id ……
date id ……
3)exit 结束程序
请实现QueryResult函数。
*/
#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;
// 在此处补充你的代码
typedef map<int,list<int> >::iterator Iterator;
void QueryResult(Iterator day_lower,Iterator day_upper)
{
    Iterator i=day_lower;
    for(;i!=day_upper;++i)
    {
        cout<<i->first<<":";
        list<int>::iterator j=(i->second).begin();
        for(;j!=i->second.end();++j)
            cout<<" "<<*j;
        cout<<endl;
    }


}
int main(int argc, char* argv[])
{
	map<int, list<int> > Attendance;
	map<int, list<int> >::iterator it;
	string cmd;
	int date, id, date_lower, date_upper;
	while (cin >> cmd){
		if (cmd == "add"){
			cin >> date >> id;
			it = Attendance.find(date);
			if (it != Attendance.end()){
				it->second.push_back(id);
			}
			else{
				list<int> lst_id;
				lst_id.push_back(id);
				Attendance.insert(make_pair(date,lst_id));
			}
		}
		else if (cmd == "query"){
			cin >> date_lower>>date_upper;
			QueryResult(Attendance.lower_bound(date_lower), Attendance.upper_bound(date_upper));
		}
		else if (cmd == "exit")
			return 0;
	}
	return 0;
}
/*
输入
每一行数据格式如上述两条命令，其中date是int型，0 < date < 32，id为int型，以15开头的10位学号。
输出
在输入数据有query命令时，输出相应格式的缺勤名单(每个学号后面有一个空格)
样例输入
add 1 1500012755
add 1 1500012796
add 3 1500012755
query 1 2
add 4 1500012737
query 1 4
exit
样例输出
1: 1500012755 1500012796
1: 1500012755 1500012796
3: 1500012755
4: 1500012737
*/
