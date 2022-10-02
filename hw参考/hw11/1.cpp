#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset 
{
	char a[bitNum/8+1];
	MyBitset() { memset(a,0,sizeof(a));};
	void Set(int i,int v) {
		char & c = a[i/8];
		int bp = i % 8;
		if( v ) 
			c |= (1 << bp);
		else 
			c &= ~(1 << bp);
	}

    struct reference {
        MyBitset *bit;
        int p1, p2;

        reference(MyBitset<bitNum> *p, int x, int y): bit(p), p1(x), p2(y) {}
        operator bool() {
            return bit->a[p1] & (1 << p2);
        }

        reference operator =(reference &x) const {
            bool v = (bool) x;
            if (x) {
                bit->a[p1] |= (1 << p2);
            } else {
                bit->a[p1] &= ~(1 << p2);
            }
            return *this;
        }

        reference operator =(bool x) {
            if (x) {
                bit->a[p1] |= (1 << p2);
            } else {
                bit->a[p1] &= ~(1 << p2);
            }
            return *this;
        }
    };

    reference operator [](int x) {
        return reference(this, x / 8, x % 8);
    }

    void Print() {
		for(int i = 0;i < bitNum; ++i) 
			cout << (*this) [i];
		cout << endl;
	}

};


int main()
{
	int n;
	int i,j,k,v;
	while( cin >>  n) {
		MyBitset<20> bs;
		for(int i = 0;i < n; ++i) {
			int t;
			cin >> t;
			bs.Set(t,1);
		}
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		bs[i] = bs[j] = bs[k];
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		(bs[i] = bs[j]) = bs[k];
		bs.Print();
	}
	return 0;
}