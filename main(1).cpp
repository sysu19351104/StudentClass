#include<iostream>
#include"student.h"
#include"studentclass.h"
#include<string>
using namespace std;
int main()
{
	student s1(2, "Bob"), s2(1, "John"), s3(3, "Alice");            //三个学生初始化
	s1.Addcourse("c++", 90);                                        //添加各学生每门分数
	s1.Addcourse("Math", 85);
	s1.Addcourse("Robtics", 90);
	s2.Addcourse("c++", 90);
	s2.Addcourse("Math", 90);
	s2.Addcourse("Robtics", 90);
	s3.Addcourse("c++", 85);
	s3.Addcourse("Math", 85);
	s3.Addcourse("Robtics", 85);
	s3.Setgrade("Robtics", 80);                               //修改分数
	s1.Showgrade();                                          //展示学生情况
	s2.Showgrade();
	s3.Showgrade();
	student s4(5,"bobo");                               //添加学生
	student stu[20] = { s1,s2,s3,s4};
	studentclass class1("A", stu);                      //添加班级A
	cout << "show the student:";
	class1.ShowStudent(1);
	cout << "\n";
	bool ascending(int a, int b);
	bool descending(int a, int b);
	cout << "ascending:" << endl;
	class1.ShowStudentsByIdOrder(ascending);
	cout << "descending:" << endl;
	class1.ShowStudentsByIdOrder(descending);
	cout << "\n" << "studentcount_:";
	class1.showStudentCount();
	student s5(7, "KK"), s6(8, "MM");
	student stu2[20]={ s5,s6 };
	studentclass class2("B", stu2);                      //添加班级B
	cout << "show the student:";
	class2.ShowStudent(7);
	cout << "\n";
	cout << "ascending:" << endl;
	class2.ShowStudentsByIdOrder(ascending);
	cout << "descending:" << endl;
	class2.ShowStudentsByIdOrder(descending);
	cout << "\n" << "studentcount_:";
	class2.showStudentCount();
}
bool ascending(int a, int b)
{
	return a < b;
}
bool descending(int a, int b)
{
	return a > b;
}