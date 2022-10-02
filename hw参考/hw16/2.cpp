#include <cstdio>
#include <cstring>
using namespace std;

const int maxN = 10;
const int maxM = 1 << maxN;

int n, k;
int dp[maxM];
char s[maxN][maxN];

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        if (n < 0 || k < 0) break;

        for (int i = 0; i < n; ++i)
            scanf("%s", s[i]);

        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int t = (1 << n) - 1; ~t; --t) {
                for (int j = 0; j < n; ++j)
                    if ((t & (1 << j)) && s[i][j] == '#') {
                        dp[t] += dp[t ^ (1 << j)];
                    }
            }
        }

        int ans = 0;
        for (int i = 0; i < (1 << n); ++i) {
            int tot = 0;
            for (int j = 0; j < n; ++j)
                if (i & (1 << j)) tot += 1;
            if (tot == k)
                ans += dp[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}