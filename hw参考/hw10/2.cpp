#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <sstream>
//#include <unistd.h>

using namespace std;

const int maxN = 1005;

int n;
string s[maxN];
stack <string> element;

string pop_back(string &x) {
    string ans = "";
//    cout << x << endl;
    while (*x.rbegin() == ' ' && !x.empty()) x.pop_back();
    for (auto i = x.rbegin(); i != x.rend(); ++i) {
        auto ch = *i;
        x.pop_back();

        if (ch == ' ') break;
        ans += ch;
        // cout << "ans=" << ans << endl;
        // sleep(1);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int is_operate(string x) {
    if (x == "copy") return 0;
    if (x == "add") return 1;
    if (x == "find") return 2;
    if (x == "rfind") return 3;
    if (x == "insert") return 4;
    if (x == "reset") return 5;
    if (x == "print") return 6;
    if (x == "printall") return 7;
    if (x == "over") return 8;
    return -1;
}

string get_element() {
    string ans = element.top();
    element.pop();
    return ans;
}

string copy() {
    int N = stoi(get_element());
    int X = stoi(get_element());
    int L = stoi(get_element());
    return s[N].substr(X, L);
}


bool isdigit(string x) {
    int number = 0;
    for (auto i = x.begin(); i != x.end(); ++i) {
        if (*i < '0' || *i > '9') return false;
        number = number * 10 + *i - '0';
    }
    return 0 <= number && number <= 99999;
}

string add() {
    string S1 = get_element();
    string S2 = get_element();
//    cout << S1 << " " << S2 << endl;
    if (isdigit(S1) && isdigit(S2)) {
//        cout << "digit!" << endl;
        int s1 = stoi(S1), s2 = stoi(S2);
//        cout << s1 << " " << s2 << endl;
        return to_string(s1 + s2);
    }
    return S1 + S2;
}

string find() {
    string S = get_element();
    int N = stoi(get_element());
    auto pos = s[N].find(S);
    if (pos == string::npos)
        return to_string(s[N].size());
    return to_string(pos);
}

string rfind() {
    string S = get_element();
    int N = stoi(get_element());
    auto pos = s[N].rfind(S);
    if (pos == string::npos)
        return to_string(s[N].size());
    return to_string(pos);
}

string insert() {
    string S = get_element();
    int N = stoi(get_element());
    int X = stoi(get_element());
    s[N].insert(X, S);
    return "";
}

string reset() {
    string S = get_element();
    int N = stoi(get_element());
    s[N] = S;
    return "";
}

string print() {
    int N = stoi(get_element());
    cout << s[N] << endl;
    return "";
}

string printall() {
    for (int i = 1; i <= n; ++i)
        cout << s[i] << endl;
    return "";
}

string over() {
    return "";
}


string (*option[])() = {copy, add, find, rfind, insert, reset, print, printall, over};
vector <string> operate;
string line, word;

void work() {
    while (!operate.empty()) {
        string now = *operate.rbegin();
        operate.pop_back();
//        cout << "now=" << now << endl;
        int type = is_operate(now);
//        cout << type << endl;
        if (~type) {
            string value = option[type]();
//            cout << value << endl;
            if (!value.empty())
                element.push(value);
        } else {
            element.push(now);
        }
//        sleep(1);
    }
    operate.clear();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    while (getline(cin, line)) {
        istringstream input(line);
        while (input >> word)
            operate.push_back(word);
        work();
    }
    return 0;
}