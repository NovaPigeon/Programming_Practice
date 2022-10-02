#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned char byte;

const int maxM = 1e6 + 5;
const int maxN = 3000;

int W, H, wl, hl;
char tmp[maxM];
char w[maxN], h[maxN];

void i2o(ifstream &ip, ofstream &op, int size) {
    ip.read(tmp, size);
    op.write(tmp, size);
}

void wh(ifstream &ip, ofstream &op) {
    ip.read(w, 4), ip.read(h, 4);
    op.write(h, 4), op.write(w, 4);
}

void head_data(ifstream &ip, ofstream &op) {
    i2o(ip, op, 18);
    wh(ip, op);

    for (int i = 3; ~i; --i) W = W * 256 + (unsigned char)w[i];
    for (int i = 3; ~i; --i) H = H * 256 + (unsigned char)h[i];
    cout << W << " " << H << endl;

    i2o(ip, op, 76);
}

char picture[maxN][maxN][4];
void picture_data(ifstream &ip, ofstream &op) {
    for (int i = H - 1; ~i; --i)
        for (int j = 0; j < W; ++j) {
            int nx = j;
            int ny = H - i - 1;
            ip.read(picture[nx][ny], 4);
        }

    for (int i = W - 1; ~i; --i)
        for (int j = 0; j < H; ++j){
            op.write(picture[i][j], 4);
        }
}



int main() {
    ifstream pic("picture.bmp", ios::in | ios::binary);
    ofstream newPic("picture2.bmp", ios::out | ios::binary);

    head_data(pic, newPic);
    picture_data(pic, newPic);
    return 0;
}