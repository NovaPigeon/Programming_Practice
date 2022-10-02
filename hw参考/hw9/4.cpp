#include <cstdio>
#include <set>
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



multiset <int> s;
set <int> appear;
int m;
char op[10];

int main() {
    for (int i = read(); i--; ) {
        scanf("%s", op);
        int x = read();

        if (*op == 'a' && op[1] == 'd') {
            s.insert(x), appear.insert(x);
            printf("%d\n", (int)s.count(x));
        }

        if (*op == 'd') {
            printf("%d\n", (int)s.count(x));
            s.erase(x);
        }

        if (*op == 'a' && op[1] == 's') {
            printf("%d ", appear.find(x) != appear.end() ? 1 : 0);
            printf("%d\n", (int)s.count(x));
        }
    }
    return 0;
}