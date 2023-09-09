#pragma once
#include<iostream>
#include<string>
using namespace std;
class StudentDevelop
{
public:
	StudentDevelop() {
		CourseID = "null";
		CourseName = "null";
		Credit = 0;
		OpeningCourseTime = 0;
	}
	StudentDevelop(string courseID, string courseName, double credit, int openingCourseTime) {
		CourseID = courseID;
		CourseName = courseName;
		Credit = credit;
		OpeningCourseTime = openingCourseTime;
	}

	string getCourseID() {
		return CourseID;
	}

	void setCourseID(string courseID) {
		CourseID = courseID;
	}

	string getCourseName() {
		return CourseName;
	}

	void setCourseName(string courseName) {
		CourseName = courseName;
	}
	double getCredit() {
		return Credit;
	}

	void setCredit(double credit) {
		Credit = credit;
	}

	int getOpeningCourseTime() {
		return OpeningCourseTime;
	}

	void setOpeningCourseTime(int openingCourseTime) {
		OpeningCourseTime = openingCourseTime;
	}

	void show() {
		cout << "�γ̱�ţ�" << CourseID << ", �γ�����";
	}
	//(string courseID, string courseName, double credit, int openingCourseTime)
	string showLine() {
		string credit = to_string(Credit);
		string opingtime = to_string(OpeningCourseTime);
		return ("�γ̱�ţ�" + CourseID + ", �γ����ƣ�" + CourseName + ", ѧ�֣�" + credit + ", ����ѧ�ڣ�" + opingtime + "\n");
	}

private:
	string CourseID;
	string CourseName;
	double Credit;
	int OpeningCourseTime;
};

