#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxN = 5;
const int INF = 1e9;

int a[maxN][maxN], b[maxN][maxN];
char s[maxN][maxN];

bool check(int state) {
    memcpy(b, a, sizeof(a));

    int id = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (state & (1 << (id++))) {
                b[i][j] ^= 1;
                if (i) b[i - 1][j] ^= 1;
                if (j) b[i][j - 1] ^= 1;
                if (i < 3) b[i + 1][j] ^= 1;
                if (j < 3) b[i][j + 1] ^= 1;
            }
    int all0 = 1, all1 = 1;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            if (b[i][j]) all0 = 0;
            else all1 = 0;
        }
    return all0 | all1;
}

int main() {
    for (int i = 0; i < 4; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < 4; ++j)
            a[i][j] = (s[i][j] == 'b');
    }

    int ans = INF;
    for (int i = 0; i < (1 << 16); ++i)
        if (check(i)) {
            ans = min(ans, __builtin_popcount(i));
        }
    if (ans == INF) {
        printf("Impossible\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}