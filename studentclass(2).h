#pragma once
#include<string>
#include"student.h"

class studentclass                           //studentclass类函数的声明
{
private:                                        //私有数据
	static const int maxstudents_ = 20;
	static int  studentcount_;
	std::string code_;
	student students_[maxstudents_];
public:                                       //各类函数
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
void swap(student* const element1, student* const element2);   //交换函数