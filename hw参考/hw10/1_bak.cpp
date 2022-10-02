#include <cstdio>
#include <stack>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int n;
multiset <double> s;
vector <string> operate;
string line;
stack <double> number;
stack <string> option;

double get_number() {
    double x = number.top();
    number.pop();
    return x;
}

double L, R;

double add() {
    return L + R;
}

double sub() {
    return L - R;
}

double mul() {
    return L * R;
}

double div() {
    return L / R;
}

double pow() {
    return pow(L, R);
}

double calc(string x) {
    R = get_number();
    L = get_number();
    if (x == "+") return add();
    if (x == "-") return sub();
    if (x == "*") return mul();
    if (x == "/") return div();
    if (x == "^") return pow();
    return 0;
}

int value(string x) {
    if (x == "^") return 2;
    if (x == "*" || x == "/") return 1;
    if (x == "+" || x == "-") return 0;
}



bool is_option(string x) {
    return x == "+" || x == "-" || x == "*" || x == "/" || x == "^";
}

void work() {
    double ans;
    for (int i = 0; i < (int)operate.size(); ++i) {
        string x = operate[i];
        if (x == "=") break;
        if (is_option(x)) {
            if (option.empty() || value(option.top()) < value(x))
                option.push(x);
            else {
                number.push(calc(option.top()));
                option.pop();
                option.push(x);
            }
        } else {
            number.push(stod(x));
        }
    }
    while (!option.empty())
        number.push(calc(option.top())), option.pop();

    if (!number.empty()) {
        ans = number.top();
        printf("%e\n", ans);

        if (ans > *s.begin()) {
            s.erase(s.begin());
            s.insert(ans);
        }
    }
    operate.clear();
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        double x;
        scanf("%lf", &x);
//        cout << x << endl;
        s.insert(x);
    }

    while (getline(cin, line)) {
        string element;
        istringstream input(line);
//        cout << line << endl;
        while (input >> element)
            operate.push_back(element);
//        cout << operate.size() << endl;
        work();
    }
    printf("\n");

    int total = 0;
    for (auto i = s.begin(); i != s.end(); ++i) {
        total += 1;
        if (total % 10) printf("%e ", *i);
        else printf("%e\n", *i);
    }
}