#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T *a, T *b) {
    T ans = *a;
    for (T *i = a + 1; i != b; ++i)
        ans += *i;
    return ans;
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  
	cout << SumArray(a,a+4) << endl;
	return 0;
}