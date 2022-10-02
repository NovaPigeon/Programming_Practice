#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int maxL = 55;
int n, m;
string num;

struct BigInt {
    int len;
    int s[maxL];

    int operator [](int x) const {
        return s[x];
    }

    int &operator [](int x) {
        return s[x];
    }

    BigInt(): len(0) {
        memset(s, 0, sizeof(s));
    }
    BigInt(int x) {
        memset(s, 0, sizeof(s));
        while (x) {
            s[len++] = x % 10;
            x /= 10;
        }
    }
    BigInt(string x) {
        memset(s, 0, sizeof(s));
        len = x.size();
        for (int i = 0; i < len; ++i)
            s[len - i - 1] = x[i] - '0';
    }
    BigInt(const BigInt &x) {
        len = x.len;
        memcpy(s, x.s, sizeof(s));
    }

    friend BigInt operator +(const BigInt &a, const BigInt &b) {
        BigInt c(0);
        int go = 0;
        for (int i = 0; i < max(a.len, b.len) || go; ++i) {
            c[i] = a[i] + b[i] + go;
            go = c[i] / 10;
            c[i] %= 10;
            c.len = i + 1;
        }
        return c;
    }

    friend bool operator <(const BigInt &a, const BigInt &b) {
        if (a.len != b.len) return a.len < b.len;
        for (int i = a.len - 1; ~i; --i)
            if (a[i] != b[i]) return a[i] < b[i];
        return false;
    }

    friend ostream &operator <<(ostream &os, const BigInt &a) {
        for (int i = a.len - 1; ~i; --i)
            os << a[i];
        return os;
    }
};

BigInt INF;

bool vis[maxL][maxL][maxL];
BigInt dp[maxL][maxL][maxL];

BigInt dfs(int l, int r, int k) {
    if (vis[l][r][k]) return dp[l][r][k];
    if (!k) return BigInt(num.substr(l, r - l));
    if (l == r) return INF;

    vis[l][r][k] = true;

    BigInt ret(INF);
    for (int mid = l + 1; mid <= r - 1; ++mid)
        ret = min(dfs(l, mid, 0) + dfs(mid, r, k - 1), ret);
    return dp[l][r][k] = ret;
}

int main() {
    string inf = "1";
    for (int i = 1; i <= 50; ++i)
        inf += "0";
    INF = BigInt(inf);

    while (cin >> m) {
        memset(vis, 0, sizeof(vis));

        cin >> num;
        n = num.size();

        cout << dfs(0, n, m) << endl;
    }
    return 0;
}