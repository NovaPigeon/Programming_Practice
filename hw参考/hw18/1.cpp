#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int maxN = 1e6 + 5;

int dp[maxN][4][3];
bool inq[maxN][4][3];

struct Node {
    string number;
    int op2, op3;
    Node(string n, int _, int __): number(n), op2(_), op3(__) {}
};

queue <Node> q;

void prepare() {
    inq[12345][0][0] = 1;
    q.push((Node){"12345", 0, 0});

    while (!q.empty()) {
        Node v = q.front(); q.pop();
        string num = v.number;
        int pre_num = stoi(v.number);

        for (int i = 0; i < 4; ++i) {
            swap(num[i], num[i + 1]);
            int new_num = stoi(num);

            if (!inq[new_num][v.op2][v.op3]) {
                inq[new_num][v.op2][v.op3] = 1;
                dp[new_num][v.op2][v.op3] = dp[pre_num][v.op2][v.op3] + 1;
                q.push(Node(num, v.op2, v.op3));
            }
            swap(num[i], num[i + 1]);
        }

        if (v.op2 < 3) {
            for (int i = 0; i < 5; ++i) {
                int pre = num[i] - '0', now = pre + 1;
                if (now >= 10) now -= 10;
                num[i] = now + '0';

                int new_num = stoi(num);
                if (!inq[new_num][v.op2 + 1][v.op3]) {
                    inq[new_num][v.op2 + 1][v.op3] = 1;
                    dp[new_num][v.op2 + 1][v.op3] = dp[pre_num][v.op2][v.op3] + 1;
                    q.push(Node(num, v.op2 + 1, v.op3));
                }
                num[i] = pre + '0';
            }
        }

        if (v.op3 < 2) {
            for (int i = 0; i < 5; ++i) {
                int pre = num[i] - '0', now = pre * 2;
                if (now >= 10) now -= 10;
                num[i] = now + '0';

                int new_num = stoi(num);
                if (!inq[new_num][v.op2][v.op3 + 1]) {
                    inq[new_num][v.op2][v.op3 + 1] = 1;
                    dp[new_num][v.op2][v.op3 + 1] = dp[pre_num][v.op2][v.op3] + 1;
                    q.push(Node(num, v.op2, v.op3 + 1));
                }
                num[i] = pre + '0';
            }
        }
    }
}

int n;
int main() {
    prepare();
    while (cin >> n) {
        int ans = -1;
        for (int i = 0; i <= 3; ++i)
            for (int j = 0; j <= 2; ++j)
                if (inq[n][i][j]) {
                    if (ans < 0 || ans > dp[n][i][j])
                        ans = dp[n][i][j];
                }
        cout << ans << endl;
    }
    return 0;
}