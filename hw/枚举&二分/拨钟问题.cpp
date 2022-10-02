/*
A:拨钟问题
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有9个时钟，排成一个3*3的矩阵。

|-------|    |-------|    |-------|
|       |    |       |    |   |   |
|---O   |    |---O   |    |   O   |
|       |    |       |    |       |
|-------|    |-------|    |-------|
    A            B            C    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O   |    |   O   |
|   |   |    |   |   |    |   |   |
|-------|    |-------|    |-------|
    D            E            F    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O---|    |   O   |
|   |   |    |       |    |   |   |
|-------|    |-------|    |-------|
    G            H            I    
(图 1)
现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。
移动    影响的时钟
 
 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI    
输入
9个整数，表示各时钟指针的起始位置，相邻两个整数之间用单个空格隔开。其中，0=12点、1=3点、2=6点、3=9点。
输出
输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号从小到大输出结果。相邻两个整数之间用单个空格隔开。
样例输入
3 3 0 
2 2 2 
2 1 2 
样例输出
4 5 8 9 
*/
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
int change_matrix[9][9]={
    {1,1,0,1,1,0,0,0,0},
    {1,1,1,0,0,0,0,0,0},
    {0,1,1,0,1,1,0,0,0},
    {1,0,0,1,0,0,1,0,0},
    {0,1,0,1,1,1,0,1,0},
    {0,0,1,0,0,1,0,0,1},
    {0,0,0,1,1,0,1,1,0},
    {0,0,0,0,0,0,1,1,1},
    {0,0,0,0,1,1,0,1,1}
};
int puzzle[9]={0};
void change(int* map,int id,int n)
{
    for(int i=0;i<9;++i)
    {
        map[i]=(map[i]+change_matrix[id-1][i]*n)%4;
    }
}
bool judge(int* map)
{
    for(int i=0;i<9;++i)
    {
        if(map[i]!=0)
            return false;
    }
    return true;
}
bool cmp(int* a,int* b)
{
    for(int i=0;i<9;++i)
    {
        if(a[i]>b[i])
            return 1;
        if(a[i]<b[i])
            return 0;    
    }
    return 0;
}
int min_change_num=INT_MAX;
int res[9]={0};
int try_res[9];
int main()
{
    for(int i=0;i<9;++i)
        cin>>puzzle[i];
    //先枚举前三种情况，后面的几种变化就可以决定了
    for(try_res[0]=0;try_res[0]<4;++try_res[0])
        for(try_res[1]=0;try_res[1]<4;++try_res[1])
            for(try_res[2]=0;try_res[2]<4;++try_res[2])
            {
                int temp_map[9];
                for(int i=0;i<9;++i)
                    temp_map[i]=puzzle[i];
                change(temp_map,1,try_res[0]);
                change(temp_map,2,try_res[1]);
                change(temp_map,3,try_res[2]);
                try_res[3]=(4-temp_map[0])%4;
                change(temp_map,4,try_res[3]);
                try_res[4]=(4-temp_map[1])%4;
                change(temp_map,5,try_res[4]);
                try_res[5]=(4-temp_map[2])%4;
                change(temp_map,6,try_res[5]);
                try_res[6]=(4-temp_map[3])%4;
                change(temp_map,7,try_res[6]);
                try_res[7]=(4-temp_map[6])%4;
                change(temp_map,8,try_res[7]);
                try_res[8]=(4-temp_map[4])%4;
                change(temp_map,9,try_res[8]);
                if(judge(temp_map))
                {
                    int temp_num=0;
                    for(int i=0;i<9;++i)
                        temp_num+=try_res[i];
                    if(temp_num<min_change_num||(temp_num==min_change_num&&cmp(try_res,res)))
                    {
                        min_change_num=temp_num;
                        memcpy(res,try_res,sizeof(try_res));
                    }
                }
            }
    for(int i=1;i<=9;++i)
        for(int j=0;j<res[i-1];++j)
            cout<<i<<" ";
    return 0;
}