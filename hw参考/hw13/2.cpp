#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 1e5 + 5;

bool isDir(string x) {
    return (x[0] == 'd' || x[0] == 'R');
}

bool isFile(string x) {
    return x[0] == 'f';
}

struct Computer {
    int nowLayer;
    vector<string> files[maxN];

    Computer() {
        nowLayer = -1;
    }

    void print(string x) {
        for (int i = 0; i < nowLayer; ++i)
            printf("|     ");
        cout << x << endl;
    }

    void insert(string x) {
        if (isDir(x)) {
            nowLayer += 1;
            print(x);
        } else if (isFile(x)) {
            files[nowLayer].push_back(x);
        } else if (x == "]") {
            sort(files[nowLayer].begin(), files[nowLayer].end());
            for (auto f: files[nowLayer])
                print(f);
            files[nowLayer].clear();
            nowLayer -= 1;
        } else {
            throw (string)("Input Error");
        }
    }
};

int index;
int main() {
    while (1) {
        string firstFile;
        cin >> firstFile;
        if (firstFile == "#") break;

        if (index) printf("\n");
        printf("DATA SET %d:\n", ++index);

        Computer computer;
        computer.insert("ROOT");
        computer.insert(firstFile);
        while (cin >> firstFile) {
            if (firstFile == "*") break;
            computer.insert(firstFile);
        }
        computer.insert("]");
    }
    return 0;
}