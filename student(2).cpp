#include "student.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;                                   
//student类的实现
student::student()                       //默认构造函数
{
    id_ = 19351001;
    name_ = "xiaoma";
}
student::student(int id, string name) :id_(id)      //构造函数
{
    name_ = name;
    cout << "constructor" << endl;
}
student::student(const student& s)                   //复制函数
{
    id_ = s.id_;
    name_ = s.name_;
}

void student::Setyou(const int id, const string name)  //各个存取函数 
{
    id_ = id;
    name_ = name;
}

string student::Getname()const
{
    return name_;
}
int student::Getid()const
{
    return id_;
}
bool student::Addcourse(const string& coursename, double grade)  //添加个门课程分数
{
    for (int n = 0; n < maxcourses_; n++)
    {
        if (coursenames_[n] == coursename)
            grades_[n] = grade;
        continue;
    }
    int n = sizeof(coursenames_[maxcourses_]);
    if ((n <= maxcourses_) && (n > 0))
        return true;
    else
        return false;
}

void student::Setgrade(const string& coursename, double grade)//可修改分数，存取函数
{
    cout << "After change the data:";
    for (int n = 0; n < maxcourses_; n++)
    {
        if (coursenames_[n] == coursename)
            grades_[n] = grade;
        continue;
    }
}

double student::Getgrade(const std::string& coursenames)
{
    for (int n = 0; n < maxcourses_; n++)
    {
        if (coursenames_[n] == coursenames)
            return grades_[n];
    }
}
double student::Getaveragegrade()const                    //获得平均分
{
    double total = 0;
    for (int n = 0; n < maxcourses_; n++)
    {
        total += grades_[n];
    }
    return static_cast<double>(total) / maxcourses_;
}
void student::Showgrade()const                                   //输出信息
{
    cout << "welcome to the Gradebook!" << endl;
    cout << "name:" << left << setw(15) << Getname() << "the id:" << Getid() << endl;
    cout << "the course:";
    for (int n = 0; n < maxcourses_; n++)
    {
        cout << left << setw(20) << coursenames_[n];
    }
    cout << "\n" << "the grade:  ";
    for (int n = 0; n < maxcourses_; n++)
    {
        cout << left << setw(20) << grades_[n];
    }
    cout << "\n" << "the average score:" << Getaveragegrade() << "\n" << endl;
}