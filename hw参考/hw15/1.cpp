#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxN = 16;
const int maxM = 1 << maxN;

int cost[maxM], score[maxM];
vector<int> plan[maxM];

struct Course {
    string name;
    int ddl, tim;

    void input() {
        cin >> name >> ddl >> tim;
    }
} course[maxN];

int cas, n;

bool operator <(vector<int> a, vector<int> b) {
    int len = min(a.size(), b.size());
    for (int i = 0; i < len; ++i)
        if (a[i] != b[i]) return course[a[i]].name < course[b[i]].name;
    return a.size() < b.size();
}

int main() {
    cin >> cas;
    while (cas--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            course[i].input();

        memset(score, 63, sizeof(score));
        memset(cost, 0, sizeof(cost));

        score[0] = 0;
        plan[0].clear();

        for (int s = 1; s < (1 << n); ++s) {
            for (int i = 0; i < n; ++i)
                if (s & (1 << i)) {
                    int t = s ^ (1 << i);
                    int now_score = score[t];
                    vector<int> now_plan = plan[t];

                    cost[s] = cost[t] + course[i].tim;
                    now_plan.push_back(i);
                    if (cost[s] > course[i].ddl)
                        now_score += cost[s] - course[i].ddl;

                    if (now_score < score[s]) {
                        score[s] = now_score;
                        plan[s] = now_plan;
                    } else if (now_score == score[s] && now_plan < plan[s]) {
                        plan[s] = now_plan;
//                        cout << "8" << endl;
                    }
                }
        }

        int state = (1 << n) - 1;
        cout << score[state] << endl;
        for (auto x: plan[state])
            cout << course[x].name << endl;
    }
    return 0;
}