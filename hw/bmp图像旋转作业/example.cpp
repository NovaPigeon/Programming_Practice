#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

//位图文件头定义;
struct  Header{
    DWORD bfSize;//文件大小
    WORD bfReserved1;//保留字
    WORD bfReserved2;//保留字
    DWORD bfOffBits;//从文件头到实际位图数据的偏移字节数
};

//位图信息头定义
struct Info{
    DWORD biSize;//信息头大小
    DWORD biWidth;//图像宽度
    DWORD biHeight;//图像高度
    WORD biPlanes;//位平面数，必须为1
    WORD biBitCount;//每像素位数
    DWORD  biCompression; //压缩类型
    DWORD  biSizeImage; //压缩图像大小字节数
    DWORD  biXPelsPerMeter; //水平分辨率
    DWORD  biYPelsPerMeter; //垂直分辨率
    DWORD  biClrUsed; //位图实际用到的色彩数
    DWORD  biClrImportant; //本位图中重要的色彩数
};

//像素信息
struct DATA
{
    BYTE blue;
    BYTE green;
    BYTE red;
};

WORD bfType;//文件类型
Header srcHead;//原文件文件头
Info srcInfo;//原文件信息头
int h,w,size;//原图像的高度、宽度和尺寸

int getDiff(Info & info)
{
    int DataSizePerline = (info.biWidth * info.biBitCount+31) / 8;
    DataSizePerline -= DataSizePerline % 4;
    return DataSizePerline - info.biWidth * info.biBitCount / 8;
}

void rotation(const DATA* src){
    int newH = w;
    int newW = h;//图片旋转90度之后宽度、高度互换
    int newSize = newH * newW;

    FILE *p;
    p=fopen("dest.bmp","wb");
    Header newHead = srcHead;
    Info newInfo = srcInfo;


    //修改旋转后图片的尺寸、宽度和高度
    newHead.bfSize = (DWORD)(newHead.bfSize);
    newInfo.biHeight = (DWORD)newH;
    newInfo.biWidth = (DWORD)newW;
    int newdiff = getDiff(newInfo);
    newInfo.biSizeImage = (DWORD)((newInfo.biWidth * 3 + newdiff) * newInfo.biHeight);

    //将种类、文件头、信息头写入新bmp文件
    fwrite(&bfType,1,sizeof(WORD),p);
    fwrite(&newHead,1,sizeof(Header),p);
    fwrite(&newInfo,1,sizeof(Info),p);

    DATA* target = new DATA[newSize];
    for (int i=0; i<newH; i++){
        for (int j=0; j<newW; j++){
            *(target + i * newW + j) = *(src + j * w + newH - i - 1);
        }
    }

    for (int i=0; i<newH; i++){
        fwrite((char*)target + i * newW * 3, 3, newW, p);
        fseek(p, newdiff, SEEK_CUR);
    }

    fclose(p);
    delete []target;
}

int main(){
    FILE* p;
    p = fopen("24.bmp", "rb");
    if (p != NULL){
        //先读取文件类型
        fread(&bfType, 1, sizeof(WORD), p);
        //读取bmp文件的文件头和信息头
        fread(&srcHead,1, sizeof(Header), p);
        fread(&srcInfo,1, sizeof(Info), p);
        h=srcInfo.biHeight;
        w=srcInfo.biWidth;
        size = w * h;

        DATA *imgdata=new DATA[size];
        int diff = getDiff(srcInfo);

        //读取原图片像素信息
        for (int i=0;i<h;i++){
            fread((char*)imgdata + i * w * 3, 3, w, p);
            fseek(p, diff, SEEK_CUR);
        }
        fclose(p);
        rotation(imgdata);
        delete []imgdata;
    }
    else{
        cout<<"无法打开文件"<<endl;
    }
    return 0;
}
