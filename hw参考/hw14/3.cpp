#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int maxN = 205;
const int maxX = 10005;

int a[maxN];
bool dp1[maxN][maxX], dp2[maxN][maxX];
bool wsw[maxN];

int n, X;

int main() {
    freopen("3.in", "r", stdin);

    scanf("%d%d", &n, &X);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    dp1[0][0] = dp2[n + 1][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= X; ++j) {
            dp1[i][j] = dp1[i - 1][j];
            if (j - a[i] >= 0 && dp1[i - 1][j - a[i]])
                dp1[i][j] = 1;
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= X; ++j) {
            dp2[i][j] = dp2[i + 1][j];
            if (j - a[i] >= 0 && dp2[i + 1][j - a[i]])
                dp2[i][j] = 1;
        }
    }

    vector<int> answer;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= X; ++j)
            if (dp1[i - 1][j] && dp2[i + 1][X - j])
                wsw[i] = 1;
        if (!wsw[i]) answer.push_back(a[i]);
    }

    printf("%d\n", (int)answer.size());
    for (int i = 0; i < answer.size(); ++i)
        if (i == answer.size() - 1) {
            printf("%d", answer[i]);
        } else {
            printf("%d ", answer[i]);
        }
    
    printf("\n");
}