#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int INF = 1e9;
const int maxN = 20;

int n;
char s[maxN][maxN];
int a[maxN][maxN], b[maxN][maxN];

void light(int x, int y) {
    b[x][y] ^= 1;
    if (x) b[x - 1][y] ^= 1;
    if (y) b[x][y - 1] ^= 1;
    if (x < n - 1) b[x + 1][y] ^= 1;
    if (y < n - 1) b[x][y + 1] ^= 1;
}

int check(int state) {
    memcpy(b, a, sizeof(a));

    int tot = 0;
    for (int i = 0; i < n; ++i)
        if (state & (1 << i)) light(0, i), tot += 1;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!b[i - 1][j]) light(i, j), tot += 1;
    for (int i = 0; i < n; ++i)
        if (!b[n - 1][i]) return INF;
    return tot;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'y') a[i][j] = 1;
        }
    }

    int ans = INF;
    for (int i = 0; i < (1 << n); ++i) {
        ans = min(ans, check(i));
    }

    if (ans == INF) {
        printf("inf\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}