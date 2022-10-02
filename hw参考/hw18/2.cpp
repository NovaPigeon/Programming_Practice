#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int maxN = 105;
const int maxM = 12;
const int maxS = 1 << 6;
const int INF = 1e9;

char s[maxN][maxN];
int id[maxN][maxN];
int n, m;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct State {
    int x, y, key, snake, step;
    State(int _x, int _y, int _k, int _sn, int _st): x(_x), y(_y), key(_k), snake(_sn), step(_st) {}
};

//bool inq[maxN][maxN][maxM][maxS];
int dp[maxN][maxN][maxM];
int tim;

int bfs() {
    int bx = n, by = n, ex = n, ey = n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'K') bx = i, by = j;
            if (s[i][j] == 'T') ex = i, ey = j;
        }
    if (bx == n || ex == n)
        return -1;
//    memset(inq, 0, sizeof(inq));
    memset(dp, 63, sizeof(dp));

    queue<State> q;
    q.push(State(bx, by, 0, 0, 0));
//    inq[bx][by][0][0] = 1;
    dp[bx][by][0] = 0;


    while (!q.empty()) {
        State v = q.front(); q.pop();
        //        inq[v.x][v.y][v.key][v.snake] = 0;
        // if (v.x == ex && v.y == ey && v.key == m) {
        //     ans = min(ans, v.step);
        //     continue;
        // }
//        printf("%d %d %d %d %d\n", v.x, v.y, v.key, v.snake, v.step);

        for (int i = 0; i < 4; ++i) {
            int nx = v.x + dx[i];
            int ny = v.y + dy[i];
            int nstep = v.step + 1;
            int nsnake = v.snake;
            int nkey = v.key;

            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= n) continue;
            if (s[nx][ny] == '#') continue;

            if (s[nx][ny] == 'S' && (!(nsnake & (1 << id[nx][ny])))) {
                nsnake |= 1 << id[nx][ny];
                nstep += 1;
            }
            if (s[nx][ny] >= '1' && s[nx][ny] <= '9') {
                if (nkey == s[nx][ny] - '0' - 1)
                    nkey += 1;
            }

            if (dp[nx][ny][nkey] > nstep) {
                dp[nx][ny][nkey] = nstep;
                q.push(State(nx, ny, nkey, nsnake, nstep));
            }
        }
    }

    int ans = dp[ex][ey][m];
    if (ans >= INF) return -1;
    return ans;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        if (!n || !m) break;

        int idx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
            for (int j = 0; j < n; ++j)
                if (s[i][j] == 'S') {
                    id[i][j] = idx++;
                }
        }

        int ans = bfs();
        if (ans < 0) printf("impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}