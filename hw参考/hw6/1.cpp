#include <cstdio>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;

const int INF = 1e9;
const int maxN = 25;
const int maxWeapon = 10;
const int warriorsNumber = 5;

int redPre[] = {
    2, 3, 4, 1, 0
};

int bluePre[] = {
    3, 0, 1, 2, 4
};

char teamName[2][10] = {
    "red", "blue"
};

class Warrior;
class Weapon;
class Team;
class City;


int warriorLife[warriorsNumber] = {0};
int warriorAttack[warriorsNumber] = {0};
int N, M, T, K, tim;
City *city[maxN];


class Weapon {
public:
    int number;
    int times;
    char name;
    Warrior *owner;

    void printName();

    Weapon();
    Weapon(int n, int t, Warrior *o, char c);
    virtual ~Weapon() {}
    virtual int attack() = 0;
    virtual int rebound() {
        return 0;
    }
};

class Warrior {
public:
    static int Number[2];
    int number, life, attack, pointer;
    char name;
    Team *team;
    City *place;

    vector <Weapon*> weapon;

    Warrior();
    Warrior(int l, int a, char c, Team *t);
    void goStep();
    void prepare();
    void printName();
    void report();
    void capture(Warrior *enemy);
    bool canfight();
    bool live();
    Weapon *useWeapon();

    virtual ~Warrior() {
        for (int i = 0; i < weapon.size(); ++i)
            delete weapon[i];
    }
    virtual void getRebound(int x) {
        life -= x;
    }

    virtual bool runaway() {
        return false;
    }

    virtual void yell(City *c) {}
    virtual void bleed() {}
    virtual void hijack(Warrior *enemy, City* c) {}
};

class Team {
public:
    int life, next, cantBuild, pointer, number;
    City *iniPlace;
    vector <Warrior*> warriors;
    int *presatation;

    Team();
    Team(int l, int n, City *c, int *p);
    ~Team();
    void buildWarrior();
    void prepare();
    void report();
};

class City {
public:
    int number;
    vector <Warrior*> warriors;
    void hijack();
    void fight();
    bool hasWarrior(int x, int on);

    City();
    City(int n);
    ~City();
};




Weapon::Weapon() {}
Weapon::Weapon(int n, int t, Warrior *o, char c): number(n), times(t), owner(o), name(c) {}

void Weapon::printName() {
    if (name == 's') printf("sword");
    if (name == 'b') printf("bomb");
    if (name == 'a') printf("arrow");
}


class Sword: public Weapon {
public:
    Sword(): Weapon() {}
    Sword(Warrior *o): Weapon(0, INF, o, 's') {}

    int attack() {
        return owner->attack * 2 / 10;
    }
};

class Bomb: public Weapon {
public:
    Bomb(): Weapon() {}
    Bomb(Warrior *o): Weapon(1, 1, o, 'b') {}

    int attack() {
        return owner->attack * 4 / 10;
    }

    int rebound() {
        return owner->attack * 4 / 10 / 2;
    }
};

class Arrow: public Weapon {
public:
    Arrow(): Weapon() {}
    Arrow(Warrior *o): Weapon(2, 2, o, 'a') {}

    int attack() {
        return owner->attack * 3 / 10;
    }
};

bool compare_attack(Weapon *a, Weapon *b) {
    if (a->number != b->number) return a->number < b->number;
    return a->times < b->times;
}

bool compare_hijack(Weapon *a, Weapon *b) {
    if (a->number != b->number) return a->number > b->number;
    return a->times < b->times;
}

Weapon* getWeapon(int x, Warrior *o) {
    if (x == 0) return new Sword(o);
    if (x == 1) return new Bomb(o);
    if (x == 2) return new Arrow(o);
    return NULL;
}

void remove(vector <Weapon*> &a, Weapon* p) {
    vector <Weapon*>:: iterator it;
    for (it = a.begin(); it != a.end(); ++it) {
        if (*(it) == p) {
            a.erase(it);
            break;
        }
    }

}

void remove(vector <Warrior*> &a, Warrior* p) {
    vector <Warrior*>:: iterator it;
    for (it = a.begin(); it != a.end(); ++it) {
        if (*(it) == p) {
            a.erase(it);
            break;
        }
    }

}



void died(Warrior *x) {
    remove(x->team->warriors, x);
    remove(x->place->warriors, x);
    delete x;
}

int Warrior::Number[2] = {0, 0};
Warrior::Warrior() {}
Warrior::Warrior(int l, int a, char c, Team *t): life(l), attack(a), name(c), team(t) {
    number = ++Number[team->number];
    place = t->iniPlace;
    place->warriors.push_back(this);
}

bool Warrior::canfight() {
    if (weapon.empty()) return false;
    if (life <= 0) return false;

    for (int i = 0; i < weapon.size(); ++i)
        if (weapon[i]->name != 's') return true;
    if (attack * 2 / 10 > 0) return true;
    return false;
}

bool Warrior::live() {
    return life > 0;
}


void Warrior::printName() {
    if (name == 'd') printf("dragon");
    if (name == 'n') printf("ninja");
    if (name == 'i') printf("iceman");
    if (name == 'l') printf("lion");
    if (name == 'w') printf("wolf");
}

void Warrior::goStep() {
    int nextcity = place->number + team->next;

    remove(place->warriors, this);
    place = city[nextcity];
    place->warriors.push_back(this);
    bleed();

    if (tim * 60 + 10 <= T) {
        if (nextcity != 0 && nextcity != N + 1) {
            printf("%03d:10 %s ", tim, teamName[team->number]);
            printName();
            printf(" %d marched to city %d", number, nextcity);
            printf(" with %d elements and force %d\n", life, attack);
        } else {
            if (nextcity == 0) city[0]->hasWarrior(1, 1);
            if (nextcity == N + 1) city[N + 1]->hasWarrior(0, 1);
        }
    }
}

void Warrior::prepare() {
    pointer = 0;
    sort(weapon.begin(), weapon.end(), compare_attack);
}

void Warrior::report() {
    vector <Weapon*> newWeapon;
    int cs = 0, cb = 0, ca = 0;
    for (int i = 0; i < weapon.size(); ++i) {
        if (!weapon[i]->times) continue;
        newWeapon.push_back(weapon[i]);
        if (weapon[i]->name == 's') ++cs;
        if (weapon[i]->name == 'b') ++cb;
        if (weapon[i]->name == 'a') ++ca;
    }

    weapon = newWeapon;
    if (tim * 60 + 55 <= T) {
        printf("%03d:55 %s ", tim, teamName[team->number]);
        printName();
        printf(" %d has %d sword %d bomb %d arrow and %d elements\n", number, cs, cb, ca, life);
    }
}

Weapon* Warrior::useWeapon() {
    while (!weapon.empty()) {
        Weapon *w = weapon[pointer];
        if (!w->times) {
            remove(weapon, w);
            delete w;
            if (!weapon.empty())
                pointer %= (int)weapon.size();
        } else {
            w->times -= 1;
            (pointer += 1) %= (int)weapon.size();
            return w;
        }
    }
    return NULL;
}

void Warrior::capture(Warrior *enemy) {
    sort(enemy->weapon.begin(), enemy->weapon.end(), compare_hijack);
    while (!enemy->weapon.empty() && weapon.size() < maxWeapon) {
        Weapon *w = enemy->weapon[enemy->weapon.size() - 1];
        w->owner = this;
        weapon.push_back(w);
        enemy->weapon.pop_back();
    }
}



class Dragon: public Warrior {
public:
    Dragon(): Warrior() {}
    Dragon(int l, int a, Team *t): Warrior(l, a, 'd', t) {
        weapon.push_back(getWeapon(number % 3, this));
        printf("%03d:00 %s dragon %d born\n", tim, teamName[t->number], number);
    }

    void yell(City *c) {
        printf("%03d:40 %s dragon %d yelled in city %d\n", tim, teamName[team->number], number, c->number);
    }
};

class Ninja: public Warrior {
public:
    Ninja(): Warrior() {}
    Ninja(int l, int a, Team *t): Warrior(l, a, 'n', t) {
        weapon.push_back(getWeapon(number % 3, this));
        weapon.push_back(getWeapon((number + 1) % 3, this));
        printf("%03d:00 %s ninja %d born\n", tim, teamName[t->number], number);
    }

    void getRebound(int x) {}
};

class Iceman: public Warrior {
public:
    Iceman(): Warrior() {}
    Iceman(int l, int a, Team *t): Warrior(l, a, 'i', t) {
        weapon.push_back(getWeapon(number % 3, this));
        printf("%03d:00 %s iceman %d born\n", tim, teamName[t->number], number);
    }

    void bleed() {
        life -= life / 10;
    }
};

class Lion: public Warrior {
    int loyalty;
public:
    Lion(): Warrior() {}
    Lion(int l, int a, Team *t): Warrior(l, a, 'l', t) {
        weapon.push_back(getWeapon(number % 3, this));
        loyalty = t->life;
        printf("%03d:00 %s lion %d born\n", tim, teamName[t->number], number);
        printf("Its loyalty is %d\n", loyalty);
    }

    void bleed() {
        loyalty -= K;
    }

    bool runaway() {
        if (loyalty <= 0) {
            if (tim * 60 + 5 <= T)
                printf("%03d:05 %s lion %d ran away\n", tim, teamName[team->number], number);
            return true;
        }
        return false;
    }
};

class Wolf: public Warrior {
public:
    Wolf(): Warrior() {}
    Wolf(int l, int a, Team *t): Warrior(l, a, 'w', t) {
        if (tim * 60 <= T)
            printf("%03d:00 %s wolf %d born\n", tim, teamName[t->number], number);
    }

    void hijack(Warrior *enemy, City *c) {
        if (enemy->name == 'w') return;
        if (weapon.size() >= maxWeapon || enemy->weapon.empty()) return;

        sort(enemy->weapon.begin(), enemy->weapon.end(), compare_hijack);

        int counter = 0;
        Weapon *i = enemy->weapon[enemy->weapon.size() - 1];
        while (weapon.size() < maxWeapon && !enemy->weapon.empty()) {
            Weapon *w = enemy->weapon[enemy->weapon.size() - 1];
            if (w->name != i->name) break;
            if (w->times) {
                ++counter;
                w->owner = this;
                weapon.push_back(w);
            } else
                delete w;
            enemy->weapon.pop_back();
        }

        if (tim * 60 + 35 <= T) {
            printf("%03d:35 %s", tim, teamName[team->number]);
            printf(" wolf %d took %d ", number, counter);
            i->printName();
            printf(" from %s ", teamName[team->number ^ 1]);
            enemy->printName();
            printf(" %d in city %d\n", enemy->number, c->number);
        }
    }
};

Warrior* getWarrior(int x, Team *t) {
    if (x == 0) return new Dragon(warriorLife[x], warriorAttack[x], t);
    if (x == 1) return new Ninja(warriorLife[x], warriorAttack[x], t);
    if (x == 2) return new Iceman(warriorLife[x], warriorAttack[x], t);
    if (x == 3) return new Lion(warriorLife[x], warriorAttack[x], t);
    if (x == 4) return new Wolf(warriorLife[x], warriorAttack[x], t);
    return NULL;
}




Team::Team(int l, int n, City *c, int *p): life(l), number(n), iniPlace(c), presatation(p) {
    pointer = cantBuild = 0;
    if (n) next = -1;
    else next = 1;
}

Team::~Team() {
    for (int i = 0; i < (int)warriors.size(); ++i)
        delete warriors[i];
}

void Team::buildWarrior() {
    if (cantBuild) return;
    int x = presatation[pointer];
    if (life >= warriorLife[x]) {
        life -= warriorLife[x];
        Warrior *w = getWarrior(x, this);
        if (!w->runaway())
            warriors.push_back(w);
        else
            died(w);
        (pointer += 1) %= warriorsNumber;
    } else
        cantBuild = 1;
}


bool compare_place(Warrior *a, Warrior *b) {
    return a->place->number < b->place->number;
}

bool compare_new_place(Warrior *a, Warrior *b) {
    return a->place->number + a->team->next < b->place->number + b->team->next;
}

void Team::report() {
    sort(warriors.begin(), warriors.end(), compare_place);
    for (int i = 0; i < warriors.size(); ++i)
        warriors[i]->report();
}


void fightRound(Warrior *a, Warrior *b) {
    Weapon *wp = a->useWeapon();
    if (!wp) return;

    b->life -= wp->attack();
    a->getRebound(wp->rebound());
}

void defeat(Warrior *a, Warrior *b, City *c) {
    if (tim * 60 + 40 <= T) {
        printf("%03d:40 %s ", tim, teamName[a->team->number]);
        a->printName();
        printf(" %d killed %s ", a->number, teamName[b->team->number]);
        b->printName();
        printf(" %d in city %d remaining %d elements\n", b->number, c->number, a->life);
    }

    a->capture(b);
    died(b);
}



City::City(int n): number(n) {}
City::~City() {}

bool City::hasWarrior(int x, int on) {
    for (int i = 0; i < (int)warriors.size(); ++i)
        if (warriors[i]->team->number == x) {
            Warrior *w = warriors[i];
            if (tim * 60 + 10 <= T && on) {
                printf("%03d:10 %s ", tim, teamName[x]);
                w->printName();
                printf(" %d reached %s headquarter with %d elements and force %d\n", w->number, teamName[x ^ 1], w->life, w->attack);
                printf("%03d:10 %s headquarter was taken\n", tim, teamName[x ^ 1]);
            }
            return true;
        }
    return false;
}

void City::hijack() {
    if (warriors.size() > 1) {
        assert(warriors.size() == 2);
        Warrior *w1 = warriors[0], *w2 = warriors[1];
        assert(w1->team != w2->team);
        if (number % 2 != w2->team->number) swap(w1, w2);
        w1->hijack(w2, this);
        w2->hijack(w1, this);
    }
}


void City::fight() {
    if (warriors.size() > 1) {
        assert(warriors.size() == 2);
        Warrior *w1 = warriors[0], *w2 = warriors[1];
        assert(w1->team != w2->team);
        if (number % 2 != w2->team->number) swap(w1, w2);

        w1->prepare();
        w2->prepare();
        while (w1->canfight() || w2->canfight()) {
            if (!w1->live() || !w2->live()) break;
            fightRound(w1, w2);
            if (!w1->live() || !w2->live()) break;
            fightRound(w2, w1);
        }

        if (w1->team->number != 0) swap(w1, w2);
        if (w1->live() && w2->live()) {
            if (tim * 60 + 40 <= T) {
                printf("%03d:40 both red ", tim);
                w1->printName();
                printf(" %d and blue ", w1->number);
                w2->printName();
                printf(" %d were alive in city %d\n", w2->number, number);
            }
        }
        if (!w1->live() && !w2->live()) {
            if (tim * 60 + 40 <= T) {
                printf("%03d:40 both red ", tim);
                w1->printName();
                printf(" %d and blue ", w1->number);
                w2->printName();
                printf(" %d died in city %d\n", w2->number, number);
            }
            died(w1);
            died(w2);
        }

        if (w1->live() && !w2->live()) defeat(w1, w2, this);
        if (w2->live() && !w1->live()) defeat(w2, w1, this);
        if (w1->live()) w1->yell(this);
        if (w2->live()) w2->yell(this);
    }
}


void marchAll(vector <Warrior*> &a, vector <Warrior*> b) {
    vector <Warrior*> now, na, nb;
    for (int i = 0; i < a.size(); ++i) now.push_back(a[i]);
    for (int i = 0; i < b.size(); ++i) now.push_back(b[i]);

    sort(now.begin(), now.end(), compare_new_place);
    for (int i = 0; i < now.size(); ++i) {
        Warrior *w = now[i];
        if (!w->runaway()) {
            if (w->team->number) nb.push_back(w);
            else na.push_back(w);
            w->goStep();
        } else {
            died(w);
        }
    }
    a = na;
    b = nb;
}

void reportAll(vector <Warrior*> &a, vector <Warrior*> b) {
    vector <Warrior*> now;
    for (int i = 0; i < a.size(); ++i) now.push_back(a[i]);
    for (int i = 0; i < b.size(); ++i) now.push_back(b[i]);

    sort(now.begin(), now.end(), compare_place);
    for (int i = 0; i < now.size(); ++i) now[i]->report();
}

int cas;
int main() {
    scanf("%d", &cas);
    for (int c = 1; c <= cas; ++c) {
        printf("Case %d:\n", c);

        scanf("%d%d%d%d", &M, &N, &K, &T);
        for (int i = 0; i < warriorsNumber; ++i)
            scanf("%d", warriorLife + i);
        for (int i = 0; i < warriorsNumber; ++i)
            scanf("%d", warriorAttack + i);
        for (int i = 0; i <= N + 1; ++i)
            city[i] = new City(i);

        Team *red = new Team(M, 0, city[0], redPre);
        Team *blue = new Team(M, 1, city[N + 1], bluePre);

        for (tim = 0; 60 * tim <= T; ++tim) {
            red->buildWarrior();
            blue->buildWarrior();
//            red->prepare();
//            blue->prepare();
            marchAll(red->warriors, blue->warriors);
            if (city[0]->hasWarrior(1, 0)) break;
            if (city[N + 1]->hasWarrior(0, 0)) break;
            for (int i = 1; i <= N; ++i) city[i]->hijack();
            for (int i = 1; i <= N; ++i) city[i]->fight();

            if (tim * 60 + 50 <= T) {
                printf("%03d:50 %d elements in red headquarter\n", tim, red->life);
                printf("%03d:50 %d elements in blue headquarter\n", tim, blue->life);
            }
            reportAll(red->warriors, blue->warriors);
        }

        delete red;
        delete blue;
        Warrior::Number[0] = Warrior::Number[1] = tim = 0;
//        cerr << tim << endl;
    }
    return 0;
}