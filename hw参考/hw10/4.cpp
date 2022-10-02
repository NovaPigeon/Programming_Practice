#include <iostream>
#include <queue>
using namespace std;

const int maxN = 1e7;

int value[maxN], prime[maxN], tot;
bool visit[maxN];
void prework() {
    for (int i = 2; i < maxN; ++i) {
        if (!visit[i]) prime[++tot] = i, value[i] = 1;
        for (int j = 1; j <= tot && prime[j] * i < maxN; ++j) {
            visit[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                value[i * prime[j]] = value[i];
                break;
            } else {
                value[i * prime[j]] = value[i] + 1;
            }
        }
    }
    for (int i = 1; i <= tot; ++i)
        value[prime[i]] -= 1;
}

class cmp1 {
public:
    bool operator ()(int x, int y) {
        int vx = value[x];
        int vy = value[y];
        if (vx == vy) return x < y;
        return vx < vy;
    }
};

class cmp2 {
public:
    bool operator ()(int x, int y) {
        int vx = value[x];
        int vy = value[y];
        if (vx == vy) return x > y;
        return vx > vy;
    }
};

priority_queue<int, vector<int>, cmp1> q1;
priority_queue<int, vector<int>, cmp2> q2;

int num;

int main() {
    prework();

    cin >> num;
    for (int i = 1; i <= num; ++i) {
        for (int j = 1, x; j <= 10; ++j) {
            cin >> x;
            q1.push(x);
            q2.push(x);
        }
        cout << q1.top() << " ";
        cout << q2.top() << endl;
        q1.pop(), q2.pop();
    }
    return 0;
}