#include <cstdio>
#include <algorithm>
using namespace std;

const int maxN = 3500;
const int maxM = 13000;

int sum[maxM];
int n, m, d[maxN], w[maxN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", d + i, w + i);
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= d[i]; --j)
            sum[j] = max(sum[j], sum[j - d[i]] + w[i]);

    int ans = 0;
    for (int i = 1; i <= m; ++i)
        ans = max(ans, sum[i]);
    printf("%d\n", ans);
    return 0;
}