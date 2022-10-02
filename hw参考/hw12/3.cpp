#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxN = 35;
const int INF = 1e9;

char s1[maxN], s2[maxN];
int a[maxN], b[maxN], c[maxN];
int n;

int work(int x) {
    if (x) c[x - 1] ^= 1;
    if (x < n - 1) c[x + 1] ^= 1;
    c[x] ^= 1;
}

int work() {
    int ret = 0;
    for (int i = 0; i < n; ++i) c[i] = a[i];
    for (int i = 1; i < n; ++i) {
        if (c[i - 1] != b[i - 1]) work(i), ret += 1;
    }
    if (c[n - 1] != b[n - 1])
        return INF;
    return ret;
}

int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    n = strlen(s1);

    for (int i = 0; i < n; ++i)
        a[i] = s1[i] - '0', b[i] = s2[i] - '0';

    int ans = INF;
    ans = min(ans, work());

    if (n > 1) {
        a[0] ^= 1;
        a[1] ^= 1;
        ans = min(ans, work() + 1);
    } else {
        ans = min(ans, 1);
    }

    if (ans == INF) {
        printf("impossible\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}