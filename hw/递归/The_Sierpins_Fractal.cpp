/*
C:The Sierpinski Fractal
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Consider a regular triangular area, divide it into four equal triangles of half height and remove the one in the middle. Apply the same operation recursively to each of the three remaining triangles. If we repeated this procedure infinite times, we'd obtain something with an area of zero. The fractal that evolves this way is called the Sierpinski Triangle. Although its topological dimension is 2, its Hausdorff-Besicovitch dimension is log(3)/log(2)~1.58, a fractional value (that's why it is called a fractal). By the way, the Hausdorff-Besicovitch dimension of the Norwegian coast is approximately 1.52, its topological dimension being 1.

For this problem, you are to outline the Sierpinski Triangle up to a certain recursion depth, using just ASCII characters. Since the drawing resolution is thus fixed, you'll need to grow the picture appropriately. Draw the smallest triangle (that is not divided any further) with two slashes, to backslashes and two underscores like this:

 /\
/__\
To see how to draw larger triangles, take a look at the sample output.

输入
The input contains several testcases. Each is specified by an integer n. Input is terminated by n=0. Otherwise 1<=n<=10 indicates the recursion depth.
输出
For each test case draw an outline of the Sierpinski Triangle with a side's total length of 2n characters. Align your output to the left, that is, print the bottom leftmost slash into the first column. The output must not contain any trailing blanks. Print an empty line after each test case.
样例输入

样例输出
       /\
      /__\
     /\  /\
    /__\/__\
   /\      /\
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\

   /\
  /__\
 /\  /\
/__\/__\

 /\
/__\
提示

The Sierpinski-Triangle up to recursion depth 7
来源
Ulm Local 2002
*/
#include<iostream>
#include<cstring>
using namespace std;
char picture[2000][2000]={' '};
int pow_(int base,int k)
{
    int ans=1;
    for(int i=0;i<k;++i)
        ans*=base;
    return ans;
}
void draw_triangular(int i,int j,int n);
int main()
{
    freopen("2.txt", "w", stdout);
    int N;
    int cnt=0;
    while(1)
    {
        cin>>N;
        if(N==0)
            break;
        if(cnt!=0)
            cout<<endl<<endl;
        cnt++;
        
        for(int i=0;i<2000;++i)
            for(int j=0;j<2000;++j)
                picture[i][j]=' ';
        draw_triangular(0,pow_(2,N)-1,N);
        int size_w=pow_(2,N+1);
        int size_h=pow_(2,N);
        for(int i=0;i<size_h;++i)
        {
            int j=size_w;
            while(j>=0)
            {
                if(picture[i][j]!=' ')
                    break;
                j--;
            }
            for(int k=0;k<=j;++k)
                cout<<picture[i][k];
            if(i!=size_h-1)
                cout<<endl;
        }
    }
    return 0;
}
void draw_triangular(int i,int j,int n)
{
    if(n==1)
    {
        picture[i][j]='/';
        picture[i][j+1]='\\';
        picture[i+1][j-1]='/';
        picture[i+1][j]='_';
        picture[i+1][j+1]='_';
        picture[i+1][j+2]='\\';
    }
    else
    {
        int size=pow_(2,n-1);
        draw_triangular(i,j,n-1);
        draw_triangular(i+size,j-size,n-1);
        draw_triangular(i+size,j+size,n-1);
    }
    system("touch a.txt");
}