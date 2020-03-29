#include "studentclass.h"
#include<iostream>
#include<string>
#include"student.h"
using namespace std;
int  studentclass::studentcount_ = 0;//��̬������studentcount_�ĳ�ʼ��
studentclass::studentclass(string code, student students[20] ) :code_(code)//���캯��
{
	for (int i = 0; i < maxstudents_; i++)
		if (students[i].Getid() != 19351001)
		{
			students_[i] = students[i];
			studentcount_++;
		}
	
}

studentclass::studentclass(const studentclass& s_)              //���ƺ�����ǳ���ƣ�
{
	code_ = s_.code_;
	for (int n = 0; n < studentcount_; n++)
	{
		students_[n] = s_.students_[n];
	}
}
void studentclass::showStudentCount()
{
	cout << studentcount_ << endl;
}
bool studentclass::AddStudent(const student students[])                //���ѧ��
{
	if (studentcount_ < maxstudents_)
	{
		students_[studentcount_] = students[studentcount_];
		studentcount_++;
	}
	if (studentcount_ <= maxstudents_)
		return true;
	else
		return false;
}
void studentclass::ShowStudent(int id)const                        //չʾ�ð�ѧ����Ϣ
{
	for (int k = 0; k < studentcount_; k++)
	{
		if ((students_[k].Getid() == id))
			cout << "the id:" << students_[k].Getid() << endl;
		cout << "the name:" << students_[k].Getname() <<endl;
		break;
	}
}
void studentclass::ShowStudentsByIdOrder(bool (*compare)(int a, int b))    //��˳����ѧ�����  
{
	int min;
	for (int i = 0; i <=studentcount_ - 1; i++)
	{
		min = i;
		for (int j = i + 1; j <= studentcount_ - 1; j++)
			if (!(*compare)(students_[min].Getid(), students_[j].Getid()))
			{
				min = j;
				swap(&students_[min], &students_[i]);
			}
	}
	for (int i = 0; i < studentcount_; i++)
	{
		if (students_[i].Getid() != 19351001)
		{
			cout << students_[i].Getid() << endl;
		}
	}
}
void swap(student* const element1, student* const element2)
{
	student hold = *element1;
	*element1 = *element2;
	*element2 = hold;
}

