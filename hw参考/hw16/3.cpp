#include <cstdio>
#include <cstring>
using namespace std;

const int maxN = 17;
const int maxM = 1 << maxN;

int a[maxN][maxN];
int dp[maxM][maxN];
int n;

void update(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);

    memset(dp, 0x3f, sizeof(dp));
    dp[1 << 0][0] = 0;

    for (int s = 1; s < (1 << n); ++s)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!(s & (1 << j)))
                    update(dp[s | (1 << j)][j], dp[s][i] + a[i][j]);
            }
        }
    printf("%d\n", dp[(1 << n) - 1][n - 1]);
    return 0;
}