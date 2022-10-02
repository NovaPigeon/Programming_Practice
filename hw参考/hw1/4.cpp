#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {

    char name[30];
    int age, id, grade[4];
    double mean;

public:
    void input() {
        cin.getline(name, 30, ',');
        scanf("%d,%d,%d,%d,%d,%d", &age, &id, grade, grade + 1, grade + 2, grade + 3);
    }

    void calculate() {
        mean = 0;
        for (int i = 0; i < 4; ++i)
            mean += grade[i];
        mean /= 4.0;
    }

    void output() {
        cout << name << ",";
        cout << age << ",";
        cout << id << ",";
        cout << mean << endl;
    }




};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}