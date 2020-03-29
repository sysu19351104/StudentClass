#pragma once
#include<string>
class student                             //student�������
{
private:
	friend class studentclass;            //��Ԫstudentclass��
	static const int maxcourses_ = 3;       //����̬����maxcourses_
	int id_;
	std::string name_;
	std::string coursenames_[maxcourses_] = { "Robtics","c++","Math" };
	double grades_[maxcourses_];
public:
	student();                                 //���ຯ������
	student(int id, std::string name);
	student(const student& s);
	void Setyou(int id, std::string name);
	std::string Getname()const;
	int Getid()const;
	bool Addcourse(const std::string& coursename, double grade);
	void Setgrade(const std::string& coursename, double grade);
	double Getgrade(const std::string& coursenames);
	double Getaveragegrade()const;
	void Showgrade()const;
};