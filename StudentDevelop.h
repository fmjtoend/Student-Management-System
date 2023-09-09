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
		cout << "课程编号：" << CourseID << ", 课程名称";
	}
	//(string courseID, string courseName, double credit, int openingCourseTime)
	string showLine() {
		string credit = to_string(Credit);
		string opingtime = to_string(OpeningCourseTime);
		return ("课程编号：" + CourseID + ", 课程名称：" + CourseName + ", 学分：" + credit + ", 开课学期：" + opingtime + "\n");
	}

private:
	string CourseID;
	string CourseName;
	double Credit;
	int OpeningCourseTime;
};

