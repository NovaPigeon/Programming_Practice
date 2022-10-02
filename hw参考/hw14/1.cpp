#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 105;
int height[maxN][maxN];
int maxlen[maxN][maxN];

typedef pair<int, int> pii;
bool cmp(pii a, pii b) {
    return height[a.first][a.second] > height[b.first][b.second];
}

int R, C;

bool inMap(int x, int y) {
    return 0 <= x && x < R && 0 <= y && y < C;
}

void update(int x1, int y1, int x2, int y2) {
    if (!inMap(x1, y1)) return;
    if (height[x1][y1] > height[x2][y2])
        maxlen[x2][y2] = max(maxlen[x2][y2], maxlen[x1][y1] + 1);
}



int main() {
    vector<pii> permu;

    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            scanf("%d", &height[i][j]);
            permu.push_back(pii(i, j));
        }

    sort(permu.begin(), permu.end(), cmp);
    for (auto ele: permu) {
        int x = ele.first;
        int y = ele.second;

        maxlen[x][y] = 1;
        update(x - 1, y, x, y);
        update(x, y - 1, x, y);
        update(x + 1, y, x, y);
        update(x, y + 1, x, y);
    }

    int ans = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            ans = max(ans, maxlen[i][j]);
    printf("%d\n", ans);
}