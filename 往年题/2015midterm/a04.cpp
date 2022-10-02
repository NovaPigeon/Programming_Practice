#include <iostream>
using namespace std;
// 在此处补充你的代码
//your code starts here
class CType 
{
	public:
		int v;
		void setvalue(int n) {
			v = n;
		}
		friend ostream & operator <<(ostream & o,const CType & c)
		{
				o << c.v;
				return o;
		}
		CType operator++(int) {
			CType tmp = * this;
			v *= v;
			return tmp;	
				
		}
};
//your code ends here
int main(int argc, char* argv[]) {
	CType obj;
	int   n;		
	cin>>n;
	while ( n ) {
		obj.setvalue(n);
		cout<<obj++<<" "<<obj<<endl;
		cin>>n;
	}
	return 0;
}
