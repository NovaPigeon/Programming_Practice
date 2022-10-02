/*
09:积分图
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
对于一幅灰度的图像，积分图中的任意一点(x,y)的值是指从图像的左上角到这个点的所构成的矩形区域内所有的点的灰度值之和。
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class IntegralImage{
// 在此处补充你的代码
public:
    int H,W;
    int** image;
    int cnt;
    IntegralImage(int H_,int W_):H(H_),W(W_)
    {
        cnt=0;
        image=new int*[H+1];
        for(int i=0;i<=H;++i)
            image[i]=new int[W];
        for(int i=0;i<=H;++i)
            for(int j=0;j<W;++j)
                image[i][j]=0;
    }
    void operator()(int *wimg)
    {
        cnt++;
        for(int i=0;i<W;++i)
        {
            int sum=image[cnt-1][i];
            for(int j=0;j<=i;++j)
                sum+=wimg[j];
            image[cnt][i]=sum;
        }
    }
    int* operator[](int n)
    {
        return image[n+1];
    }
};
int main(){
    int H, W;
    cin >> H >> W;
    int ** image = new int*[H];
    for(int i=0;i<H;++i){
        image[i]=new int[W];
    }
    for(int i=0;i<H;++i)
    for(int j=0;j<W;++j)
        cin >> image[i][j];
    IntegralImage it(H,W);
    for_each(image, image+H, it);
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j)
            cout<<it[i][j]<<" ";
        cout<<endl;
    }
   
}
/*
输入
第一行两个整数，分别是图像的宽、高H, W
接下来H*W的矩阵，分别代表图像的每个像素值
输出
积分图中每个点的值, H*W的矩阵，每个像素之间用空格分开
样例输入
2 3
1 2 3
1 0 0
样例输出
1 3 6
2 4 7
*/