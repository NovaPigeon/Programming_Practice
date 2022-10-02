#include <cstdio>
#include <cstring>
using namespace std;

const int n = 5;
const int maxN = 10005;
int m, tim;
int lifes[n];

const char Wname[3][10] = {
    "sword", "bomb", "arrow"
};

int red_permu[] = {
    2, 3, 4, 1, 0
};
int blue_permu[] = {
    3, 0, 1, 2, 4
};
const char Tname[2][10] = {
    "blue", "red"
};

class Warrior {
    static int all_number[2];
public:
    int life, ID, color;

    Warrior(int l, int c): life(l), color(c) {
        ID = ++all_number[c];
    }

    virtual ~Warrior() {
        all_number[color] -= 1;
    }

    virtual void print() = 0;
};

class Dragon: public Warrior {
    static int number[2];
public:
    static const int kind = 0;
    int weapon;
    double morale;

    Dragon(int l, int c, int r): Warrior(l, c) {
        number[c] += 1;
        weapon = ID % 3;
        morale = 1.0 * r / l;
    }

    ~Dragon() {
        number[color] -= 1;
    }

    void print() {
        printf("%03d %s dragon %d born with strength %d,", tim, Tname[color], ID, lifes[kind]);
        printf("%d dragon in %s headquarter\n", number[color], Tname[color]);
        printf("It has a %s,and it's morale is %.2f\n", Wname[weapon], morale);
    }
};

class Ninja: public Warrior {
    static int number[2];
public:
    static const int kind = 1;
    int weapon[2];

    Ninja(int l, int c): Warrior(l, c) {
        number[c] += 1;
        weapon[0] = ID % 3;
        weapon[1] = (ID + 1) % 3;
    }

    ~Ninja() {
        number[color] -= 1;
    }

    void print() {
        printf("%03d %s ninja %d born with strength %d,", tim, Tname[color], ID, lifes[kind]);
        printf("%d ninja in %s headquarter\n", number[color], Tname[color]);
        printf("It has a %s and a %s\n", Wname[weapon[0]], Wname[weapon[1]]);
    }
};

class Iceman: public Warrior {
    static int number[2];
public:
    static const int kind = 2;
    int weapon;

    Iceman(int l, int c): Warrior(l, c) {
        number[c] += 1;
        weapon = ID % 3;
    }

    ~Iceman() {
        number[color] -= 1;
    }

    void print() {
        printf("%03d %s iceman %d born with strength %d,", tim, Tname[color], ID, lifes[kind]);
        printf("%d iceman in %s headquarter\n", number[color], Tname[color]);
        printf("It has a %s\n", Wname[weapon]);
    }
};

class Lion: public Warrior {
    static int number[2];
public:
    static const int kind = 3;
    int loyalty;

    Lion(int l, int c, int r): Warrior(l, c) {
        number[c] += 1;
        loyalty = r;
    }

    ~Lion() {
        number[color] -= 1;
    }

    void print() {
        printf("%03d %s lion %d born with strength %d,", tim, Tname[color], ID, lifes[kind]);
        printf("%d lion in %s headquarter\n", number[color], Tname[color]);
        printf("It's loyalty is %d\n", loyalty);
    }
};

class Wolf: public Warrior {
    static int number[2];
public:
    static const int kind = 4;

    Wolf(int l, int c): Warrior(l, c) {
        number[c] += 1;
    }

    ~Wolf() {
        number[color] -= 1;
    }

    void print() {
        printf("%03d %s wolf %d born with strength %d,", tim, Tname[color], ID, lifes[kind]);
        printf("%d wolf in %s headquarter\n", number[color], Tname[color]);
    }
};


int Warrior::all_number[2];
int Dragon::number[2];
int Ninja::number[2];
int Iceman::number[2];
int Lion::number[2];
int Wolf::number[2];



class Team {
public:
    int rest, pointer;
    int *permu;
    int color;

    Team() {}
    Team(int c, int *p): rest(m), pointer(0), flag(0), number(0) {
        color = c, permu = p;
    }

    int number;
    Warrior *warriors[maxN];

    void build_warrior(int t) {
        Warrior *&w = warriors[number++];
        if (t == 0) w = new Dragon(lifes[t], color, rest);
        if (t == 1) w = new Ninja(lifes[t], color);
        if (t == 2) w = new Iceman(lifes[t], color);
        if (t == 3) w = new Lion(lifes[t], color, rest);
        if (t == 4) w = new Wolf(lifes[t], color);
        w->print();
    }

    bool flag;
    void work() {
        if (flag) return;
        for (int i = 0; i < n; ++i, (++pointer) %= n) {
            int x = permu[pointer];
            if (rest >= lifes[x]) {
                rest -= lifes[x];
                (++pointer) %= n;
                build_warrior(x);
                return;
            }
        }

        printf("%03d %s headquarter stops making warriors\n", tim, Tname[color]);
        flag = 1;
    }

    ~Team() {
        for (int i = 0; i < number; ++i) {
            delete warriors[i];
        }
        number = 0;
    }
};

int cas;
int main() {
    scanf("%d", &cas);

    for (int j = 1; j <= cas; ++j) {
        printf("Case:%d\n", j);
        tim = 0;

        scanf("%d", &m);

        Team *red = new Team(1, red_permu);
        Team *blue = new Team(0, blue_permu);

        for (int i = 0; i < n; ++i)
            scanf("%d", lifes + i);

        while (!red->flag || !blue->flag) {
            red->work();
            blue->work();
            tim += 1;
        }

        delete red;
        delete blue;
    }
    return 0;
}


