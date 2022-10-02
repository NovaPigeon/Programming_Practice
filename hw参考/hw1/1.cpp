#include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
    return n ^ (n & (1 << i)) ^ (m & (1 << i));
}

int main() {
	int x=0x80000000;
	int y=0x7fffffff;
	int z=0x7fffffff;
	int bitSign=((y>>31)&1)-((x>>31)&1);
	int sub=y+(~x+1);
	int bitSignSub=(sub>>31)&1;
	float f=0x7fc00000;
	cout<<f;
	printf("%x",int(f));
	return 0;
}