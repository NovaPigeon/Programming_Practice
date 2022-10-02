#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n = 5;

const int maxN = 5;
const int maxM = 25;

int a[maxN][maxN];
int d[maxM], p[maxM];
bool inq[maxM];

void update(int x1, int x2) {
    if (d[x1] > d[x2] + 1) {
        d[x1] = d[x2] + 1;
        p[x1] = x2;
    }
}

int id(int x, int y) {
    return x * 5 + y;
}

void dijkstra(int start) {
    d[start] = 0;
    for (int t = 0; t < n * n; ++t) {
        int v = -1;
        for (int i = 0; i < n * n; ++i)
            if (!inq[i] && (v < 0 || d[i] < d[v]))
                v = i;

        inq[v] = 1;
        int x = v / 5;
        int y = v % 5;
        if (!a[x][y]) {
            if (x && !a[x - 1][y]) update(id(x - 1, y), v);
            if (y && !a[x][y - 1]) update(id(x, y - 1), v);
            if (x < n - 1 && !a[x + 1][y]) update(id(x + 1, y), v);
            if (y < n - 1 && !a[x][y + 1]) update(id(x, y + 1), v);
        }
    }
}

int main() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    memset(d, 63, sizeof(d));

    dijkstra(id(0, 0));

    vector<int> ans;
    int end = id(n - 1, n - 1);
    do {
        ans.push_back(end);
    } while (end = p[end]);
    ans.push_back(0);

    reverse(ans.begin(), ans.end());
    for (auto t: ans) {
        printf("(%d, %d)\n", t / 5, t % 5);
    }
    return 0;
}