#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;

const int maxN = 25;

char team_name[2][10] = {
    "red", "blue"
};

char warrior_name[5][10] = {
    "dragon", "ninja", "iceman", "lion", "wolf"
};

int permu[2][5] = {
    {2, 3, 4, 1, 0},
    {3, 0, 1, 2, 4}
};

int warrior_life[5], warrior_attack[5];


int K, R, M, N, T;

int HOURS;
void print_time(int x) {
    printf("%03d:%02d ", HOURS, x);
}

#define check_tim(x) if (HOURS * 60 + x > T) break


class Weapon;
class Warrior;
class City;
class Team;


class Weapon {
public:
    int type;
    int attack;
    int use_times;
    Warrior *owner;
    virtual void use();
    virtual void remove();

    Weapon() {}
    Weapon(int t, Warrior *o): type(t), owner(o) {}
};

class Warrior {
public:
    Weapon *weapon[3];
    Team *team;
    City *city;

    int number;
    int attack;
    int life;
    int get_hurt;
    int type;
    void report_name();
    void report_weapon();
    void remove();

    void fight_attack(Warrior *enemy);
    virtual void fight_back(Warrior *enemy);
    virtual void capture(Warrior *enemy) {}
    virtual void dead_gift(Warrior *enemy) {}
    void die();
    bool is_dead();
    void go_ahead();
    void get_weapon(int x);
    bool will_die(Warrior *enemy, int first);
    void life_update();

    virtual void update_gift() {}
    virtual void win_award() {}
    virtual void lose_award() {}
    virtual void step_update() {}
    virtual void run_away() {}
    virtual void yell() {}

    Warrior();
    Warrior(Team *te, int nu, int at, int li, int ty);
};

class Team {
public:
    int name_number;
    int life;
    int warrior_number;

    City *headquarter;
    void get_warrior(Warrior* &w, int x);
    void build_warrior();
    void report();
    void reward(Warrior *w);

    Team(int t, int l): name_number(t), life(l) {
        warrior_number = 0;
    }
};

class City {
public:
    Warrior *warrior[2];
    City *next[2];
    int win[2], flag[2];

    int life;
    int number;
    int taken, is_headquarter;
    int just_win;
    int intown;

    void gain_life();
    void transmit_life(int d);
    void transmit_without_fight();
    void report_name();
    void fight();
    void shot();
    bool explode();
    void defeat(int d);
    void march(int d);

    City(int x): number(x) {
        memset(warrior, 0, sizeof(warrior));
        memset(win, 0, sizeof(win));
        memset(flag, 0, sizeof(flag));
        life = taken = is_headquarter = just_win = 0;
    }
};

void Weapon::use() {}
void Weapon::remove() {
    owner->weapon[type] = 0;
}

class Sword: public Weapon {
public:
    Sword() {}
    Sword(int t, Warrior *o): Weapon(t, o) {
        attack = floor(owner->attack * 0.2);
    }

    void use() {
        attack = floor(attack * 0.8);
        if (!attack) remove();
    }
};

class Bomb: public Weapon {
public:
    Bomb() {}
    Bomb(int t, Warrior *o): Weapon(t, o) {}
    void use() {
        remove();
    }
};

class Arrow: public Weapon {
public:
    Arrow() {}
    Arrow(int t, Warrior *o): Weapon(t, o) {
        use_times = 3;
    }

    void use() {
        use_times -= 1;
        if (!use_times) remove();
    }
};



Warrior::Warrior() {}
Warrior::Warrior(Team *te, int nu, int at, int li, int ty): team(te), number(nu), attack(at), life(li), type(ty) {
    city = team->headquarter;
    get_hurt = 0;
    memset(weapon, 0, sizeof(weapon));

    print_time(0);
    report_name();
    printf(" born\n");
}

void Warrior::report_name() {
    cout << team_name[team->name_number] << " ";
    cout << warrior_name[type] << " ";
    cout << number;
}

void Warrior::report_weapon() {
    print_time(55);
    report_name();
    printf(" has ");

    int has_weapon = 0;
    if (weapon[2]) {
        has_weapon = 1;
        printf("arrow(%d)", weapon[2]->use_times);
    }
    if (weapon[1]) {
        if (has_weapon) printf(",");
        has_weapon = 1;
        cout << "bomb";
    }
    if (weapon[0]) {
        if (has_weapon) printf(",");
        has_weapon = 1;
        printf("sword(%d)", weapon[0]->attack);
    }
    if (!has_weapon) {
        printf("no weapon");
    }
    printf("\n");
}

void Warrior::fight_attack(Warrior *enemy) {
    print_time(40);
    report_name();
    printf(" attacked ");
    enemy->report_name();
    printf(" in ");
    city->report_name();
    printf(" with %d elements and force %d\n", life, attack);

    int hurt = attack;
    if (weapon[0]) {
        hurt += weapon[0]->attack;
        weapon[0]->use();
    }
    enemy->get_hurt += hurt;
}

void Warrior::fight_back(Warrior *enemy) {
    print_time(40);
    report_name();
    printf(" fought back against ");
    enemy->report_name();
    printf(" in ");
    city->report_name();
    printf("\n");

    int hurt = floor(attack / 2);
    if (weapon[0]) {
        hurt += weapon[0]->attack;
        weapon[0]->use();
    }
    enemy->get_hurt += hurt;
}

void Warrior::die() {
    print_time(40);
    report_name();
    printf(" was killed in ");
    city->report_name();
    printf("\n");
    remove();
}

bool Warrior::will_die(Warrior *enemy, int first) {
    life_update();
    enemy->life_update();
    if (first) {
        int hurt = attack;
        if (weapon[0]) hurt += weapon[0]->attack;
        if (hurt >= enemy->life) return 0;
        if (enemy->type == 1) return 0;
        hurt = enemy->attack / 2;
        if (enemy->weapon[0]) hurt += enemy->weapon[0]->attack;
        return hurt >= life;
    } else {
        int hurt = enemy->attack;
        if (enemy->weapon[0]) hurt += enemy->weapon[0]->attack;
        return hurt >= life;
    }
}

bool Warrior::is_dead() {
    return life - get_hurt <= 0;
}

void Warrior::go_ahead() {
    step_update();
    print_time(10);
    report_name();
    printf(" marched to ");
    city->report_name();
    printf(" with %d elements and force %d\n", life, attack);
}

void Warrior::get_weapon(int x) {
    if (x == 0) {
        weapon[x] = new Sword(x, this);
        if (!weapon[x]->attack) weapon[x]->remove();
    }
    if (x == 1) weapon[x] = new Bomb(x, this);
    if (x == 2) weapon[x] = new Arrow(x, this);
}


void Warrior::remove() {
    city->warrior[team->name_number] = 0;
}

void Warrior::life_update() {
    life -= get_hurt;
    get_hurt = 0;
}


class Dragon: public Warrior {
    double morale;
public:
    Dragon() {}
    Dragon(Team *te, int nu, int at, int li): Warrior(te, nu, at, li, 0) {
        get_weapon(number % 3);
        morale = 1.0 * team->life / life;
        printf("Its morale is %.2lf\n", morale);
    }

    void yell() {
        if (morale > 0.8) {
            print_time(40);
            report_name();
            printf(" yelled in ");
            city->report_name();
            printf("\n");
        }
    }

    void win_award() {
        morale += 0.2;
    }

    void lose_award() {
        morale -= 0.2;
    }
};

class Ninja: public Warrior {
public:
    Ninja() {}
    Ninja(Team *te, int nu, int at, int li): Warrior(te, nu, at, li, 1) {
        get_weapon(number % 3);
        get_weapon((number + 1) % 3);
    }

    void fight_back(Warrior *enemy) {}
};

class Iceman: public Warrior {
    int steps;
public:
    Iceman() {}
    Iceman(Team *te, int nu, int at, int li): Warrior(te, nu, at, li, 2) {
        get_weapon(number % 3);
    }

    void step_update() {
        steps += 1;
        if (!(steps % 2)) {
            if (life > 9) life -= 9;
            else life = 1;
            attack += 20;
        }
    }
};

class Lion: public Warrior {
    int loyalty, prelife;
public:
    Lion() {}
    Lion(Team *te, int nu, int at, int li): Warrior(te, nu, at, li, 3) {
        loyalty = team->life;
        printf("Its loyalty is %d\n", loyalty);
    }

    void run_away() {
        if (loyalty <= 0) {
            remove();

            print_time(5);
            report_name();
            printf(" ran away\n");
        }
    }

    void lose_award() {
        loyalty -= K;
    }

    void update_gift() {
        prelife = life;
    }

    void dead_gift(Warrior *enemy) {
        enemy->life += prelife;
    }
};

class Wolf: public Warrior {
public:
    Wolf() {}
    Wolf(Team *te, int nu, int at, int li): Warrior(te, nu, at, li, 4) {}

    void capture(Warrior *enemy) {
        for (int i = 0; i < 3; ++i)
            if (!weapon[i] && enemy->weapon[i])
                weapon[i] = enemy->weapon[i], weapon[i]->owner = this;
    }
};

void City::report_name() {
    printf("city %d", number);
}

void City::shot() {
    for (int d = 0; d < 2; ++d) if (next[d] && !next[d]->is_headquarter) {
        if (warrior[d] && warrior[d]->weapon[2] && next[d]->warrior[d ^ 1]) {
            next[d]->warrior[d ^ 1]->get_hurt += R;
            warrior[d]->weapon[2]->use();
            print_time(35);

            warrior[d]->report_name();
            printf(" shot");

            if (next[d]->warrior[d ^ 1]->is_dead()) {
                printf(" and killed ");
                next[d]->warrior[d ^ 1]->report_name();
            }
            printf("\n");
        }
    }
}


void City::defeat(int d) {

    if (!win[d]) win[d] = 1, win[d ^ 1] = 0;
    else if (win[d]) {
        if (!flag[d]) {
            print_time(40);
            cout << team_name[d] << " flag raised in ";
            report_name();
            printf("\n");
            flag[d] = 1;
            flag[d ^ 1] = 0;
        }
    }
}

void City::gain_life() {
    life += 10;
}

void City::transmit_life(int d) {
    print_time(40);
    warrior[d]->report_name();
    printf(" earned %d elements for his headquarter\n", life);
    warrior[d]->team->life += life;
    life = 0;
}

void City::transmit_without_fight() {
    int d = -1;
    if (warrior[0] && !warrior[1]) d = 0;
    if (warrior[1] && !warrior[0]) d = 1;
    if (d >= 0) {
        print_time(30);
        warrior[d]->report_name();
        printf(" earned %d elements for his headquarter\n", life);
        warrior[d]->team->life += life;
        life = 0;
    }
}

void City::fight() {
    just_win = -1;
    if (warrior[0] && warrior[1]) {
        int first = 0;
        if (flag[0] || (!flag[1] && (number & 1))) first = 0;
        if (flag[1] || (!flag[0] && !(number & 1))) first = 1;

        int d = -1;
        if (!warrior[0]->is_dead() && !warrior[1]->is_dead()) {
            warrior[0]->life_update();
            warrior[1]->life_update();
            warrior[0]->update_gift();
            warrior[1]->update_gift();

            warrior[first]->fight_attack(warrior[first ^ 1]);
            if (!warrior[first ^ 1]->is_dead()) {
                warrior[first ^ 1]->fight_back(warrior[first]);
            }

            if (warrior[0]->is_dead()) d = 1;
            if (warrior[1]->is_dead()) d = 0;

            if (d >= 0) {
                warrior[d]->capture(warrior[d ^ 1]);
                warrior[d ^ 1]->dead_gift(warrior[d]);
                warrior[d ^ 1]->die();
            }
        } else {
            if (warrior[0]->is_dead() && !warrior[1]->is_dead()) d = 1;
            if (warrior[1]->is_dead() && !warrior[0]->is_dead()) d = 0;
            if (d >= 0) warrior[d]->capture(warrior[d ^ 1]);
//        warrior[d ^ 1]->dead_gift(warrior[d]);
        }

        for (int i = 0; i < 2; ++i)
            if (d != i && warrior[i]) warrior[i]->lose_award();

        if (warrior[first] && !warrior[first]->is_dead()) warrior[first]->yell();
        if (d >= 0) {
            just_win = d;
            warrior[d]->win_award();
            transmit_life(d);
            defeat(d);
        } else if (!warrior[0]->is_dead()) {
            win[0] = win[1] = 0;
        }
    }

    if (warrior[0]) {
        warrior[0]->life_update();
        if (warrior[0]->is_dead()) warrior[0]->remove();
    }

    if (warrior[1]) {
        warrior[1]->life_update();
        if (warrior[1]->is_dead()) warrior[1]->remove();
    }
}

bool City::explode() {
    if (!warrior[0] || !warrior[1]) return 0;
    if (warrior[0]->is_dead() || warrior[1]->is_dead()) return 0;

    int first = 0;
    if (flag[0] || (!flag[1] && (number & 1))) first = 0;
    if (flag[1] || (!flag[0] && !(number & 1))) first = 1;

    int d = -1;
    if (warrior[0]->weapon[1] && warrior[0]->will_die(warrior[1], first == 0)) d = 0;
    if (warrior[1]->weapon[1] && warrior[1]->will_die(warrior[0], first == 1)) d = 1;
    if (d >= 0) {
        print_time(38);
        warrior[d]->report_name();
        printf(" used a bomb and killed ");
        warrior[d ^ 1]->report_name();
        printf("\n");
        warrior[0]->remove();
        warrior[1]->remove();
        return 1;
    }
    return 0;
}

void City::march(int d) {
    if (warrior[d]) {
        if (!next[d]->warrior[d]) {
            next[d]->intown = 1;
            next[d]->warrior[d] = warrior[d];
            warrior[d]->city = next[d];
            warrior[d] = 0;
        } else {
            assert(next[d]->is_headquarter);
            next[d]->intown = 1;
            next[d]->taken = 1;
            next[d]->warrior[d] = warrior[d];
            warrior[d]->city = next[d];
            warrior[d] = 0;
        }
    }
}

void Team::get_warrior(Warrior* &w, int x) {
    if (x == 0) w = new Dragon(this, warrior_number, warrior_attack[x], warrior_life[x]);
    if (x == 1) w = new Ninja(this, warrior_number, warrior_attack[x], warrior_life[x]);
    if (x == 2) w = new Iceman(this, warrior_number, warrior_attack[x], warrior_life[x]);
    if (x == 3) w = new Lion(this, warrior_number, warrior_attack[x], warrior_life[x]);
    if (x == 4) w = new Wolf(this, warrior_number, warrior_attack[x], warrior_life[x]);
}

void Team::build_warrior() {
    int target = permu[name_number][warrior_number % 5];
    if (life >= warrior_life[target]) {
        life -= warrior_life[target];
        warrior_number += 1;
        get_warrior(headquarter->warrior[name_number], target);
    }
}

void Team::report() {
    print_time(50);
    printf("%d elements in ", life);
    cout << team_name[name_number];
    printf(" headquarter\n");
}

void Team::reward(Warrior *w) {
    if (life >= 8) {
        w->life += 8;
        life -= 8;
    }
}


City *c[maxN];
void work(int ca) {
    printf("Case %d:\n", ca);

    Team *red = new Team(0, M), *blue = new Team(1, M);
    for (int i = 0; i <= N + 1; ++i)
        c[i] = new City(i);
    for (int i = 0; i <= N; ++i)
        c[i]->next[0] = c[i + 1];
    for (int i = 1; i <= N + 1; ++i)
        c[i]->next[1] = c[i - 1];

    c[0]->next[1] = 0;
    c[N + 1]->next[0] = 0;
    c[0]->is_headquarter = c[N + 1]->is_headquarter = 1;
    red->headquarter = c[0];
    blue->headquarter = c[N + 1];


    while (true) {
        check_tim(0);
        red->build_warrior();
        blue->build_warrior();

        check_tim(5);
        for (int i = 0; i <= N + 1; ++i)
            for (int d = 0; d < 2; ++d)
                if (c[i]->warrior[d]) c[i]->warrior[d]->run_away();

        check_tim(10);
        for (int i = 0; i <= N + 1; ++i)
            c[i]->intown = 0;
        for (int i = N; i >= 0; --i) c[i]->march(0);
        for (int i = 1; i <= N + 1; ++i) c[i]->march(1);

        if (c[0]->intown) {
            Warrior *w = c[0]->warrior[1];
            w->step_update();
            print_time(10);
            w->report_name();
            printf(" reached red headquarter with %d elements and force %d\n", w->life, w->attack);
            if (c[0]->taken) {
                print_time(10);
                printf("red headquarter was taken\n");
            }
        }
        for (int i = 1; i <= N; ++i)
            for (int d = 0; d < 2; ++d)
                if (c[i]->warrior[d]) c[i]->warrior[d]->go_ahead();
        if (c[N + 1]->intown) {
            Warrior *w = c[N + 1]->warrior[0];
            w->step_update();
            print_time(10);
            w->report_name();
            printf(" reached blue headquarter with %d elements and force %d\n", w->life, w->attack);
            if (c[N + 1]->taken) {
                print_time(10);
                printf("blue headquarter was taken\n");
            }
        }

        if (c[0]->taken || c[N + 1]->taken) break;



        check_tim(20);
        for (int i = 1; i <= N; ++i)
            c[i]->life += 10;

        check_tim(30);
        for (int i = 1; i <= N; ++i)
            c[i]->transmit_without_fight();

        check_tim(35);
        for (int i = 0; i <= N + 1; ++i)
            c[i]->shot();

        check_tim(38);
        for (int i = 1; i <= N; ++i)
            c[i]->explode();

        check_tim(40);
        for (int i = 1; i <= N; ++i)
            c[i]->fight();
        for (int i = 1; i <= N; ++i)
            if (c[i]->just_win == 0) red->reward(c[i]->warrior[0]);
        for (int i = N; i >= 1; --i)
            if (c[i]->just_win == 1) blue->reward(c[i]->warrior[1]);

        check_tim(50);
        red->report();
        blue->report();

        check_tim(55);
        for (int d = 0; d < 2; ++d)
            for (int i = 0; i <= N + 1; ++i)
                if (c[i]->warrior[d]) c[i]->warrior[d]->report_weapon();
        HOURS += 1;

    }
}

int cas;
int main() {
    freopen("Warcraft.in", "r", stdin);

    cin >> cas;
    for (int j = 1; j <= cas; ++j) {
        HOURS = 0;
        cin >> M >> N >> R >> K >> T;
        for (int i = 0; i < 5; ++i) cin >> warrior_life[i];
        for (int i = 0; i < 5; ++i) cin >> warrior_attack[i];
        work(j);
//        cout << j << " " << cas << endl;
    }
    return 0;
}

