#pragma once
#include<string>
#include"student.h"

class studentclass                           //studentclass�ຯ��������
{
private:                                        //˽������
	static const int maxstudents_ = 20;
	static int  studentcount_;
	std::string code_;
	student students_[maxstudents_];
public:                                       //���ຯ��
	studentclass() {};
	studentclass(std::string code, student students[20]);
	studentclass(const studentclass& s);
	~studentclass() {
		studentcount_--;
	}
	bool AddStudent(const student students[]);
	void ShowStudent(int id) const;
	void ShowStudentsByIdOrder(bool (*compare)(int a, int b));
	static void showStudentCount();
};
void swap(student* const element1, student* const element2);   //��������