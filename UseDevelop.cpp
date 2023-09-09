#ifndef USEDEVELOP_H
#define  USEDEVELOP_H
#endif // ! USEDEVELOP_H

#include "UseDevelop.h"
#include"Usefstream.h"
#include"vectors.h"
#include<iostream>
#include<string>
using namespace std;

void UseDevelop::Input(vectors* v) {
	int flag = 1;
	while (flag == 1) {
		int num;
		cout << "请输入您要录入的培养计划个数：\n";
		cin >> num;
		//string courseID, string courseName, double credit, int openingCourseTime
		cout << "请依次输入课程编号、课程名称、学分、开课学期\n";
		for (int i = 0; i < num; i++) {
			string courseid, coursename;
			double credit;
			int openingtime;
			cin >> courseid >> coursename >> credit >> openingtime;
			StudentDevelop* temp = new StudentDevelop(courseid, coursename, credit, openingtime);
			v->studevelop.push_back(temp);
		}
		cout << "是否继续输入（1 是 0 否）？\n";
		cin >> flag;
	}
	Usefstream usefs;
	usefs.addToFile(v, 5);
}

void UseDevelop::Alter(vectors* v) {
	Usefstream usefs;
	int ret = 0, flag = 1;
	while (flag == 1) {
		cout << "请输入您要修改的课程编号\n";
		string courseid;
		cin >> courseid;
		for (StudentDevelop* c : v->studevelop) {
			if (c->getCourseID().compare(courseid) == 0) {
				cout << "已找到该课程的信息\n";
				cout << "请输入您要修改的信息（课程名称、学分、开课学期）\n";
				string coursename;
				double credit;
				int openingtime;
				cin >> coursename >> credit >> openingtime;
				c->setCourseName(coursename);
				c->setCredit(credit);
				c->setOpeningCourseTime(openingtime);
				ret++;
			}
		}
		if (ret == 0) {
			cout << "未找到该学生，请重新确认您的信息\n";
		}
		cout << "是否继续修改（1 是 0 否）？\n";
		cin >> flag;
	}
	usefs.addToFile(v, 5);
}

void UseDevelop::CX(vectors* v) {
	Usefstream usefs;
	usefs.readFile(v, 5);
}

void UseDevelop::Analyse() {

}