#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
    static const int maxN = 210;
public:
    int number[maxN];
    int len;

    CHugeInt() {}
    CHugeInt(int x) {
        len = 0;
        memset(number, 0, sizeof(number));
        while (x) {
            number[len++] = x % 10;
            x /= 10;
        }
        len = max(len, 1);
    }

    CHugeInt(const char *x) {
        memset(number, 0, sizeof(number));
        len = strlen(x);
        for (int i = 0; i < len; ++i)
            number[i] = x[len - i - 1] - '0';
    }

    CHugeInt(CHugeInt &x) {
        memcpy(number, x.number, sizeof(number));
        len = x.len;
    }

    CHugeInt(CHugeInt &&x) {
        memcpy(number, x.number, sizeof(number));
        len = x.len;
    }

    CHugeInt &operator =(const CHugeInt &x) {
        memcpy(number, x.number, sizeof(number));
        len = x.len;
        return *this;
    }

    CHugeInt &operator =(const CHugeInt &&x) {
        memcpy(number, x.number, sizeof(number));
        len = x.len;
        return *this;
    }


    CHugeInt &operator +=(int x) {
        number[0] += x;
        for (int i = 0; i < len; ++i) {
            if (number[i] > 9) {
                number[i + 1] += number[i] / 10;
                number[i] %= 10;
                len = max(len, i + 2);
            }
        }
        return *this;
    }

    CHugeInt &operator ++() {
        *this += 1;
        return *this;
    }

    CHugeInt operator ++(int x) {
        CHugeInt c(*this);
        *this += 1;
        return c;
    }

    int &operator [](int x) {
        return number[x];
    }

    friend CHugeInt operator +(CHugeInt &a, CHugeInt &b) {
        CHugeInt c(0);
        c.len = max(a.len, b.len);
        for (int i = 0; i < c.len; ++i) {
            c[i] += a[i] + b[i];
            if (c[i] > 9) {
                c[i + 1] += c[i] / 10;
                c[i] %= 10;
                c.len = max(c.len, i + 2);
            }
        }
        return c;
    }

    friend CHugeInt operator +(CHugeInt &a, int x) {
        CHugeInt c(a);
        return c += x;
    }

    friend CHugeInt operator +(int x, CHugeInt &a) {
        return a + x;
    }

    friend ostream &operator <<(ostream &os, CHugeInt &a) {
        if (a.len) {
            for (int i = a.len - 1; ~i; --i)
                os << a[i];
        } else {
            os << 0;
        }
        return os;
    }

    friend ostream &operator <<(ostream &os, CHugeInt &&a) {
        if (a.len) {
            for (int i = a.len - 1; ~i; --i)
                os << a[i];
        } else {
            os << 0;
        }
        return os;
    }
};

int  main() 
{
    char s[210];
	int n;

    while (cin >> s >> n) {
		CHugeInt a(s);
	 	CHugeInt b(n);
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}