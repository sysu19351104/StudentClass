#include "student.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;                                   
//student���ʵ��
student::student()                       //Ĭ�Ϲ��캯��
{
    id_ = 19351001;
    name_ = "xiaoma";
}
student::student(int id, string name) :id_(id)      //���캯��
{
    name_ = name;
    cout << "constructor" << endl;
}
student::student(const student& s)                   //���ƺ���
{
    id_ = s.id_;
    name_ = s.name_;
}

void student::Setyou(const int id, const string name)  //������ȡ���� 
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
bool student::Addcourse(const string& coursename, double grade)  //��Ӹ��ſγ̷���
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

void student::Setgrade(const string& coursename, double grade)//���޸ķ�������ȡ����
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
double student::Getaveragegrade()const                    //���ƽ����
{
    double total = 0;
    for (int n = 0; n < maxcourses_; n++)
    {
        total += grades_[n];
    }
    return static_cast<double>(total) / maxcourses_;
}
void student::Showgrade()const                                   //�����Ϣ
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