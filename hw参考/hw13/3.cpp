#include <cstdio>
#include <iostream>
using namespace std;

const int maxN = 11;
const int maxM = 1 << maxN;

int pow[maxN];
string layers[maxM];

void printBlank(int x, int y) {
    while(x--) layers[y] += " ";
}

void print(int layer, int size) {
    if (size == 1) {

        printBlank(1, layer);
        layers[layer] += "/\\";
        printBlank(1, layer);
        layers[layer + 1] += "/__\\";

        return;
    }

    for (int i = 0; i < pow[size - 1]; ++i)
        printBlank(pow[size - 1], layer + i);
    print(layer, size - 1);
    for (int i = 0; i < pow[size - 1]; ++i)
        printBlank(pow[size - 1], layer + i);

    print(layer + pow[size - 1], size - 1);
    print(layer + pow[size - 1], size - 1);
}

int n;
int main() {
    pow[0] = 1;
    for (int i = 1; i < maxN; ++i)
        pow[i] = pow[i - 1] << 1;

    while (cin >> n) {
        if (!n) break;
        print(0, n);

        for (int i = 0; i < (1 << n); ++i) {
            while (layers[i].back() == ' ') layers[i].pop_back();
            cout << layers[i] << endl;
            layers[i].clear();
        }
        printf("\n");
    }
    return 0;
}