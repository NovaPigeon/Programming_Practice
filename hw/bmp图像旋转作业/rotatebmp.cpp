
    

#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
using namespace std;
#pragma pack(1)
//对齐边界1字节
typedef unsigned short WORD;//2
typedef unsigned int DWORD;//4
typedef unsigned char BYTE;//1
//文件头
struct HEADER
{
    WORD bfType; // 位图文件的类型，必须为“BM”
    DWORD bfSize; // 位图文件的大小，以字节为单位
    WORD bfReserved1; // 位图文件保留字，必须为0
    WORD bfReserved2; // 位图文件保留字，必须为0
    DWORD bfOffBits; // 位图数据的起始位置，以相对于位图文件头的偏移量表示，以字节为单位,4
};//该结构占据14个字节。
//信息头
struct INFO
{
    DWORD biSize; // 本结构所占用字节数
    DWORD biWidth; // 位图的宽度，以像素为单位
    DWORD biHeight; // 位图的高度，以像素为单位
    WORD biPlanes; // 目标设备的平面数不清，必须为1
    WORD biBitCount;// 每个像素所需的位数，必须是1(双色), 4(16色)，8(256色)或24(真彩色)之一
    DWORD biCompression; // 位图压缩类型，必须是 0(不压缩),1(BI_RLE8压缩类型)或2(BI_RLE4压缩类型)之一
    DWORD biSizeImage; // 位图的大小，以字节为单位
    DWORD biXPelsPerMeter; // 位图水平分辨率，每米像素数
    DWORD biYPelsPerMeter; // 位图垂直分辨率，每米像素数
    DWORD biClrUsed;// 位图实际使用的颜色表中的颜色数
    DWORD biClrImportant;// 位图显示过程中重要的颜色数
};//40字节    
//24/32位全彩，无颜色表
struct DATA_32
{
    BYTE blue;
    BYTE green;
    BYTE red;
    BYTE alpha;//透明度
};
struct DATA_24
{
    BYTE blue;
    BYTE green;
    BYTE red;
};
//bmp中数据倒着读取，故结构顺序为bgr与bgra
HEADER srcheader;
INFO srcinfo;
int main(int argc,char*argv[])
{
    ifstream fin(argv[1],ios::in|ios::binary);//argv用于命令行调用
    if(!fin)
    {
        cout<<"Sorce File Open Error!"<<endl;
        return 0;
    }
    ofstream fout(argv[2],ios::out|ios::binary);
    if(!fout)
    {
        cout<<"Target File Creat Error!"<<endl;
        return 0;
    }
    fin.read((char*)&srcheader,sizeof(HEADER));
    fin.read((char*)&srcinfo,sizeof(INFO));
    fout.write((char*)&srcheader,sizeof(HEADER));
    INFO newinfo=srcinfo;
    swap(newinfo.biHeight,newinfo.biWidth);
    swap(newinfo.biXPelsPerMeter,newinfo.biYPelsPerMeter);
    int pixel=srcinfo.biBitCount/8;
    int DataSizePerLine=(srcinfo.biWidth* srcinfo.biBitCount+31)/32*4;
    int Diff=(DataSizePerLine-srcinfo.biWidth*srcinfo.biBitCount/8)%4;
    int newDataSizePerLine=(newinfo.biWidth* newinfo.biBitCount+31)/32*4;
    int newDiff=(newDataSizePerLine-newinfo.biWidth*srcinfo.biBitCount/8)%4; 
    newinfo.biSizeImage=newDataSizePerLine*newinfo.biHeight;
    fout.write((char*)&newinfo,sizeof(INFO));
    int h=srcinfo.biHeight,w=srcinfo.biWidth;
    if(pixel==3)
    { /* 
        DATA_24* srcdata=new DATA_24[h*w];
        for (int i = 0;i<h; i++)
        {
            fin.read((char*)srcdata + i*w*3, w*3);
            fin.seekg(Diff, ios::cur);
        }
        for(int i=newinfo.biHeight-1;i>=0;--i)
        {
            for(int j=0;j<newinfo.biWidth;++j)
            {
                fout.write((char*)&srcdata[j*w+i],sizeof(DATA_24));
            }
            for(int i=0;i<newDiff;i++)
                fout.write((char*)0,sizeof(BYTE));
        }
        fin.close();
        fout.close();
        delete[] srcdata;
        */
        DATA_24** srcdata=new DATA_24*[srcinfo.biHeight];
        for(int i=0;i<srcinfo.biHeight;i++)
            srcdata[i]=new DATA_24[srcinfo.biWidth];
        DATA_24** newdata=new DATA_24*[newinfo.biHeight];
        for(int i=0;i<newinfo.biHeight;i++)
            newdata[i]=new DATA_24[newinfo.biWidth];
        for(int i=0;i<srcinfo.biHeight;++i)
        {
            for(int j=0;j<srcinfo.biWidth;++j)
            {
                fin.read((char*)&srcdata[i][j],sizeof(DATA_24));
                newdata[j][i]=srcdata[i][j];
            }
            fin.seekg(Diff,ios::cur);
        }
        //旋转
        for(int i=0;i<newinfo.biHeight;++i)
        {
            for(int j=0;j<newinfo.biWidth;++j)
                fout.write((char*)&newdata[i][j],sizeof(DATA_24));
            for(int j=0;j<newDiff;++j)
                fout.write((char*)0,sizeof(BYTE));
        }
        fin.close();
        fout.close();
        for(int i=0;i<newinfo.biHeight;i++)
            delete []newdata[i];
        for(int i=0;i<srcinfo.biHeight;i++)
            delete []srcdata[i];
    }
    else if(pixel==4)
    {
        BYTE Blank[85];//32位bmp文件头后有85个字节的信息（可能用来调色？）拷贝下来写在新文件里就好啦！
        for(int i=0;i<85;i++)
        {
            fin.read((char*)&Blank[i],sizeof(BYTE));
            fout.write((char*)&Blank[i],sizeof(BYTE));
        }
        DATA_32** srcdata=new DATA_32*[srcinfo.biHeight];
        for(int i=0;i<srcinfo.biHeight;i++)
            srcdata[i]=new DATA_32[srcinfo.biWidth];
        DATA_32** newdata=new DATA_32*[newinfo.biHeight];
        for(int i=0;i<newinfo.biHeight;i++)
            newdata[i]=new DATA_32[newinfo.biWidth];
        for(int i=0;i<srcinfo.biHeight;++i)
        {
            for(int j=0;j<srcinfo.biWidth;++j)
            {
                fin.read((char*)&srcdata[i][j],sizeof(DATA_32));
                newdata[j][i]=srcdata[i][j];
            }
            fin.seekg(Diff,ios::cur);
        }
        for(int i=0;i<newinfo.biHeight;++i)
        {
            for(int j=0;j<newinfo.biWidth;++j)
                fout.write((char*)&newdata[i][j],sizeof(DATA_32));
            for(int j=0;j<newDiff;++j)
                fout.write((char*)0,sizeof(BYTE));
        }
        fin.close();
        fout.close();
        for(int i=0;i<newinfo.biHeight;i++)
            delete []newdata[i];
        for(int i=0;i<srcinfo.biHeight;i++)
            delete []srcdata[i];
    }
    return 0;
}
