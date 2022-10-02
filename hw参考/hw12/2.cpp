#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int maxN = 10;

int a[maxN], b[maxN];

vector<int> plan[9] = {
    {0, 1, 3, 4},
    {0, 1, 2},
    {1, 2, 4, 5},
    {0, 3, 6},
    {1, 3, 4, 5, 7},
    {2, 5, 8},
    {3, 4, 6, 7},
    {6, 7, 8},
    {4, 5, 7, 8}
};

vector<int> now, answer;

void work(int x) {
    for (auto i: plan[x])
        (b[i] += 1) &= 3;
}

int check(int state) {
    memcpy(b, a, sizeof(a));
    if (state == 20800) {
        int x = 1;
    }

    now.clear();
    for (int i = 0; i < 9; ++i) {
        int times = (state & (3 << (2 * i))) >> (2 * i);
        while (times--) work(i), now.push_back(i);
    }
    for (int i = 0; i < 9; ++i)
        if (b[i]) return INF;
    return (int)now.size();
}

int main() {
    for (int i = 0; i < 9; ++i)
        scanf("%d", a + i);

    int ans = INF;
    for (int i = 0; i < (1 << 18); ++i) {
        if (ans > check(i)) {
            answer = now;
        }
    }

    sort(answer.begin(), answer.end());
    for (auto x: answer)
        printf("%d ", x + 1);
    printf("\n");
}


