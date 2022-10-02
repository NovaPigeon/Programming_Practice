#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;
inline int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

const int maxN = 10005;
list<int> a[maxN];
char op[10];
int m;

int main() {
    m = read();
    while (m--) {
        scanf("%s", op);
        int x = read(), y;
        if (*op == 'a' || *op == 'm' ) y = read();
        if (*op == 'n') continue;
        if (*op == 'o') {
            a[x].sort();
            for (auto it = a[x].begin(); it != a[x].end(); ++it)
                printf("%d ", *it);
            printf("\n");
        }
        if (*op == 'u') {
            a[x].sort();
            a[x].unique();
        }

        if (*op == 'a') a[x].push_back(y);
        if (*op == 'm') {
            if (x == y) continue;
            a[x].sort();
            a[y].sort();
            a[x].merge(a[y]);
            a[y].clear();
        }
    }
}