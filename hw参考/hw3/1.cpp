#include <cstdio>
#include <cstring>
using namespace std;

const int n = 5;
int m, time;
int life[n];

const char name[n][10] = {
    "dragon", "ninja", "iceman", "lion", "wolf"
};

int red_permu[] = {
    2, 3, 4, 1, 0
};
int blue_permu[] = {
    3, 0, 1, 2, 4
};


void work(int &rest, int &flag, const int *permu) {
    for (int i = 0; i < n; ++i)
        if (life[i] <= rest) {
            rest -= life[i];
        }
}

class team {
public:
    int number[n], rest, allNumber, pointer;
    int *permu;
    char teamName[n];

    team() {}
    team(int color, int *p): allNumber(0), rest(m), pointer(0), flag(0) {
        permu = p;
        if (color) {
            memcpy(teamName, "red", sizeof("red"));
        } else {
            memcpy(teamName, "blue", sizeof("blue"));
        }
        memset(number, 0, sizeof(number));
    }

    bool flag;
    void work() {
        if (flag) return;
        for (int i = 0; i < n; ++i, (++pointer) %= n) {
            int x = permu[pointer];
            if (rest >= life[x]) {
                rest -= life[x];
                printf("%03d %s %s %d born with strength %d,", time, teamName, name[x], ++allNumber, life[x]);
                printf("%d %s in %s headquarter\n", ++number[x], name[x], teamName);
                (++pointer) %= n;
                return;
            }
        }

        printf("%03d %s headquarter stops making warriors\n", time, teamName);
        flag = 1;
    }
};


int cas;
int main() {
    scanf("%d", &cas);

    for (int j = 1; j <= cas; ++j) {
        printf("Case:%d\n", j);
        time = 0;

        scanf("%d", &m);

        team red(1, red_permu), blue(0, blue_permu);

        for (int i = 0; i < n; ++i)
            scanf("%d", life + i);

        while (!red.flag || !blue.flag) {
            red.work();
            blue.work();
            time += 1;
        }
    }
    return 0;
}
