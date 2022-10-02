#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
public:
    static const int maxN = 205;
    char number[maxN];
    int len;

    CHugeInt() {}
    CHugeInt(char *s) {
        if (s) {
            memcpy(number, s, sizeof(number));
            len = strlen(s);
            for (int i = 0; i < len / 2; ++i)
                swap(number[i], number[len - i - 1]);
            for (int i = 0; i < len; ++i)
                number[i] -= '0';
            for (int i = len; i < maxN; ++i)
                number[i] = 0;
        }
    }

    CHugeInt(int x): len(0) {
        memset(number, 0, sizeof(number));
        while (x) {
            number[len++] = x % 10;
            x /= 10;
        }
    }

    CHugeInt(const CHugeInt &x) {
        memcpy(number, x.number, sizeof(number));
        len = x.len;
    }

    CHugeInt operator +(const CHugeInt x) {
        CHugeInt ret(0);
        ret.len = max(len, x.len);
        for (int i = 0; i < ret.len; ++i) {
            ret.number[i] += number[i] + x.number[i];
            ret.number[i + 1] += ret.number[i] / 10;
            if (ret.number[i] / 10) ret.len = max(ret.len, i + 2);
            ret.number[i] %= 10;
        }
        return ret;
    }

    CHugeInt &operator +=(int b) {
        number[0] += b;
        for (int i = 0; i < len; ++i)
            if (number[i] > 9) {
                number[i + 1] += number[i] / 10;
                number[i] %= 10;
                len = max(len, i + 2);
            }
        return *this;
    }

    CHugeInt operator +(int b) {
        return *this + CHugeInt(b);
    }

    CHugeInt &operator ++() {
        number[0] += 1;
        for (int i = 0; i < len; ++i)
            if (number[i] > 9) {
                number[i + 1] += number[i] / 10;
                number[i] %= 10;
                len = max(len, i + 2);
            }
        return *this;
    }

    CHugeInt &operator ++(int x) {
        number[0] += 1;
        for (int i = 0; i < len; ++i)
            if (number[i] > 9) {
                number[i + 1] += number[i] / 10;
                number[i] %= 10;
                len = max(len, i + 2);
            }
        return *this;
    }

    friend CHugeInt operator +(int a, CHugeInt b) {
        return b + CHugeInt(a);
    }

    friend ostream &operator <<(ostream &os, CHugeInt a) {
        for (int i = a.len - 1; ~i; --i)
            os << (int)a.number[i];
    }
};
int  main() 
{ 
	char s[210];
	int n;

    while (cin >> s >> n) {
        printf("*");
		CHugeInt a(s);
		CHugeInt b(n);
        printf("0");
		cout << a + b << endl;
        printf("1");
		cout << n + a << endl;
        printf("2");
		cout << a + n << endl;
        printf("3");
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
