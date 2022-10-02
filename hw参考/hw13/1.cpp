#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

stack<char> operators;
stack<int> value;

int priority(char ch) {
    if (ch == '(') return 0;
    if (ch == '|') return 1;
    if (ch == '&') return 2;
    if (ch == '!') return 3;
    if (ch == ')') return 4;
    return -1;
}

bool isoperator(char ch) {
    return ~priority(ch);
}

bool isvalue(char ch) {
    return ch == 'V' || ch == 'F';
}

void work() {
    char ch = operators.top();
    if (ch == '!') {
        value.top() ^= 1;
    } else if (ch == '|' || ch == '&') {
        int x = value.top(); value.pop();
        int y = value.top(); value.pop();
        if (ch == '&') value.push(x & y);
        else value.push(x | y);
    }
    operators.pop();
}

int main() {
    freopen("1.in", "r", stdin);

    string expression;
    int index = 0;
    while (getline(cin, expression)) {
        while (!value.empty()) value.pop();
        while (!operators.empty()) operators.pop();

        for (auto x: expression) {
            if (isoperator(x)) {
                if (x == ')') {
                    while (operators.top() != '(') work();
                    operators.pop();
                } else if (x == '(') {
                    operators.push(x);
                } else {
                    while (!operators.empty() &&
                           priority(operators.top()) > priority(x)) {
                        work();
                    }
                    operators.push(x);
                }
            } else if (isvalue(x)) {
                value.push(x == 'V');
            }
        }
        while (!operators.empty()) work();
        cout << "Expression " << ++index << ": ";
        cout << (value.top() ? "V" : "F") << endl;
    }
}