//
//  main.cpp
//  学生信息处理程序
//
//  Created by 寿晨宸 on 2022/2/25.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student
{
private:
    double sc1,sc2,sc3,sc4,ave;
    int age,id;
    char name[50]={'\0'};
    char ch;
public:
    void input()
    {
        cin.get(name,50,',');
        cin>>ch>>age>>ch>>id>>ch>>sc1>>ch>>sc2>>ch>>sc3>>ch>>sc4;
    }
    void calculate()
    {
        ave=(sc1+sc2+sc3+sc4)/4;
    }
    void output()
    {
        cout<<name<<","<<age<<","<<id<<","<<ave;
    }
        
    
};

int main()
{
    Student student;        // 定义类的对象
    student.input();        // 输入数据
    student.calculate();    // 计算平均成绩
    student.output();       // 输出数据
}
