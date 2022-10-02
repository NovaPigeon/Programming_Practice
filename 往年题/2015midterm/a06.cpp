/*
描述
请写出 MyString类，使得下面程序的输出结果符合下面的要求。

输入
无
输出
1. abcd-efgh-abcd-
2. abcd-
3. 
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
样例输入
无
样例输出
1. abcd-efgh-abcd-
2. abcd-
3. 
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-

*/

#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
//your code starts here
class MyString 
{
	public:
		char * str;
		MyString():str(new char[1]) {
			str[0] = 0;
		}
		~MyString() { delete [] str;}
		MyString(const char * s) {
			str = new char [strlen(s) + 1];
			strcpy(str,s); 
		}
		MyString(const MyString & st) {
			str = new char[strlen(st.str) + 1];
			strcpy( str,st.str);
		}
		MyString & operator = ( const MyString & st) 
		{
			delete [] str;
			str = new char[strlen(st.str)+1];
			strcpy(str,st.str);
		}
		bool operator <(const MyString & st)
		{
			if( strcmp(str,st.str) < 0)
				return true;
			else
				return false;
		
		}
		bool operator >(const MyString & st)
		{
			if( strcmp(str,st.str) > 0)
				return true;
			else
				return false;
		
		}

		bool operator ==(const MyString & st)
		{
			if( strcmp(str,st.str) == 0)
				return true;
			else
				return false;
		
		}

		MyString & operator += ( const MyString & st) 
		{
			char * tmp = new char[strlen(str) + strlen(st.str) + 1];
			strcpy(tmp,str);
			strcat(tmp,st.str);
			delete [] str;
			str = tmp;
			return * this;
		}

		MyString operator +(const MyString & st) {
			char * tmp = new char[strlen(str) + strlen(st.str) + 1];
			strcpy(tmp,str);
			strcat(tmp,st.str);
			return MyString(tmp);
		}
		char & operator[](int i) {
			return str[i];
		}
		MyString operator()(int s,int L)
		{
			char * tmp = new char[L+1];
			
			for(int i = 0;i < L; ++i)
				tmp[i] = str[s+i];
			tmp[L] = 0;
			return MyString(tmp);
		}
		friend ostream & operator << (ostream & o,const MyString & st)
		{
			o << st.str;
			return o;
			
		}
		friend MyString operator + ( const char * s,const MyString & st)
		{
			char * tmp = new char[strlen(s) + strlen(st.str)+1];
			strcpy( tmp,s);
			strcat(tmp,st.str);
			return MyString(tmp); 
		}
			

};
//your code ends here
int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
		return -1;
	else if( *s1 == *s2)
		return 0;
	else if( *s1 > *s2 )
		return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}
