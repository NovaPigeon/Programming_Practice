#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned char byte;

const int maxM = 1e6 + 5;
const int maxN = 3000;

int W, H, wl, hl;
char tmp[maxM];
char w[maxN], h[maxN];
int type;

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
    printf("Your picture's size is %d times %d.\n", W, H);

    i2o(ip, op, 4);
    type = (int)tmp[2];

    if (type == 32) i2o(ip, op, 72);
    else if (type == 24) i2o(ip, op, 20);
    else {
        printf("Your picture's file format is invalid.\n");
        exit(0);
    }
    printf("Your picture is based on %d bit format.\n", type);
}

char picture[maxN][maxN][4];
void picture_data_32(ifstream &ip, ofstream &op) {
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

void picture_data_24(ifstream &ip, ofstream &op) {
    for (int i = H - 1; ~i; --i) {
        for (int j = 0; j < W; ++j) {
            int nx = j;
            int ny = H - i - 1;
            ip.read(picture[nx][ny], 3);
        }
        if (W * 3 % 4) {
            int pad = 4 - W * 3 % 4;
            ip.read(tmp, pad);
        }
    }

    memset(tmp, 0, sizeof(tmp));
    for (int i = W - 1; ~i; --i) {
        for (int j = 0; j < H; ++j) {
            op.write(picture[i][j], 3);
        }
        if (H * 3 % 4) {
            int pad = 4 - H * 3 % 4;
            op.write(tmp, pad);
        }
    }
}



int main(int argc, char **argv) {
    ifstream pic(argv[1], ios::in | ios::binary);
    ofstream newPic(argv[2], ios::out | ios::binary);

    head_data(pic, newPic);
    if (type == 32) picture_data_32(pic, newPic);
    if (type == 24) picture_data_24(pic, newPic);
    return 0;
}