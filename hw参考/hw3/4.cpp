#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };

    friend istream &operator >>(istream &is, Point &o) {
        is >> o.x >> o.y;
        return is;
    }

    friend ostream &operator <<(ostream &os, Point &o) {
        os << o.x << "," << o.y;
        return os;
    }
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}