#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

class People {
public:
    int id, force;
    People() {}
    People(int i, int f): id(i), force(f) {}
};

bool operator <(People x, People y) {
    if (x.force == y.force) {
        return x.id < y.id;
    }
    return x.force < y.force;
}

int n;
set <People> s;


int main() {
    scanf("%d", &n);
    s.insert(People(1, 1000000000));
    for (int i = 1, x, y; i <= n; ++i) {
        scanf("%d%d", &x, &y);
        auto it1 = s.upper_bound(People(x, y));
        if (it1 == s.begin()) printf("%d %d\n", x, it1->id);
        else {
            auto it3 = it1;
            auto it2 = --it3;
            it2 = s.upper_bound(People(0, it2->force));

            int a1 = abs(it1->force - y);
            int a2 = abs(it2->force - y);
            if (a1 > a2 || a1 == a2 && it2->id < it1->id) it1 = it2;
            printf("%d %d\n", x, it1->id);
        }
        s.insert(People(x, y));
    }
    return 0;
}