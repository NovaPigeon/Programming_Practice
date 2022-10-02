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

double get_number() {
    double x = number.top();
    number.pop();
    return x;
}

double L, R;
double add() {
    R = get_number();
    L = get_number();
    return L + R;
}

double sub() {
    R = get_number();
    L = get_number();
    return L - R;
}

double mul() {
    R = get_number();
    L = get_number();
    return L * R;
}

double div() {
    R = get_number();
    L = get_number();
    return L / R;
}

double pow() {
    R = get_number();
    L = get_number();
    return pow(L, R);
}

void work() {
    double ans;
    for (int i = 0; i < (int)operate.size(); ++i) {
        string x = operate[i];
//        cout <<"x="<< x << endl;

        if (x == "+") ans = add();
        else if (x == "-") ans = sub();
        else if (x == "*") ans = mul();
        else if (x == "/") ans = div();
        else if (x == "^") ans = pow();
        else if (x == "=") break;
        else ans = stod(x);
        number.push(ans);

        //        cout << "ans=" << ans << endl;
    }

    if (!number.empty()) {
        ans = number.top();
        printf("%e\n", ans);

        s.erase(s.begin());
        s.insert(ans);
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
        string option;
        istringstream input(line);
//        cout << line << endl;
        while (input >> option)
            operate.push_back(option);
//        cout << operate.size() << endl;
        work();
    }
    printf("\n");

    int total = 0;
    for (auto i = s.begin(); i != s.end(); ++i) {
        printf("%e ", *i);
        total += 1;
        if (total % 10 == 0) printf("\n");
    }
}