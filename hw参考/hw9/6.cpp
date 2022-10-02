#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

#include <sstream>

template <class T1, class T2, class T3 = greater<T1> >
class MyMultimap {
public:
    class iterator {
    public:
        using iter = typename multimap<T1, T2>:: iterator;
        iter it;

        iterator() {}
        iterator(iter i): it(i) {}

        iter operator ->() {
            return it;
        }

        void operator ++() {
            ++it;
        }

        bool operator !=(const iterator &b) {
            return it != b.it;
        }

        string operator *() {
            ostringstream stream;
            stream << "(";
            stream << it->first;
            stream << ",";
            stream << it->second;
            stream << ")";
            return stream.str();
        }
    };

    multimap<T1, T2, T3> student;
    void insert(pair<T1, T2> x) {
        student.insert(x);
    }

    iterator begin() {
        return iterator(student.begin());
    }

    iterator end() {
        return iterator(student.end());
    }

    iterator find(string name) {
        return iterator(student.find(name));
    }

    void Set(T1 name, T2 score) {
        auto it = student.equal_range(name);
        int number = 0;
        for (auto i = it.first; i != it.second; ++i, ++number);
        student.erase(it.first, it.second);
        while (number--) student.insert(make_pair(name, score));
    }

    void Set(T2 score, T1 name) {
        auto it = student.equal_range(score);
        int number = 0;
        for (auto i = it.first; i != it.second; ++i, ++number);
        student.erase(it.first, it.second);
        while (number--) student.insert(make_pair(name, score));
    }




    void clear() {
        student.clear();
    }
};


struct Student 
{
	string name;
	int score;
};
template <class T>
void Print(T first,T last) {
	for(;first!= last; ++ first)
		cout << * first << ",";
	cout << endl;
}
int main()
{
	
	Student s[] = { {"Tom",80},{"Jack",70},
					{"Jone",90},{"Tom",70},{"Alice",100} };
	
	MyMultimap<string,int> mp;
	for(int i = 0; i<5; ++ i)
		mp.insert(make_pair(s[i].name,s[i].score));
	Print(mp.begin(),mp.end()); //按姓名从大到小输出

	mp.Set("Tom",78); //把所有名为"Tom"的学生的成绩都设置为78
	Print(mp.begin(),mp.end());
	
	
	
	MyMultimap<int,string,less<int> > mp2;
	for(int i = 0; i<5; ++ i) 
		mp2.insert(make_pair(s[i].score,s[i].name));
	
	Print(mp2.begin(),mp2.end()); //按成绩从小到大输出
	mp2.Set(70,"Error");          //把所有成绩为70的学生，名字都改为"Error"
	Print(mp2.begin(),mp2.end());
	cout << "******" << endl;
	
	mp.clear();
	
	string name;
	string cmd;
	int score;		
	while(cin >> cmd ) {
		if( cmd == "A") {
			cin >> name >> score;
			if(mp.find(name) != mp.end() ) {
				cout << "erroe" << endl;
			}
			mp.insert(make_pair(name,score));
		}
		else if(cmd == "Q") {
			cin >> name;
			MyMultimap<string,int>::iterator p = mp.find(name);
			if( p!= mp.end()) {
				cout << p->second << endl;
			}
			else {
				cout << "Not Found" << endl; 
			}		
		}
	}
	return 0;
}
