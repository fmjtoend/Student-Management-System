#ifndef USEACADE_H
#define USEACADE_H
#endif // !USEACADE_H

#include "UseAcade.h"
#include"Usefstream.h"
#include"vectors.h"
#include<iostream>
#include<string>
using namespace std;

void UseAcade::Input(vectors* v) {
	int flag = 1;
	while (flag == 1) {
		int num;
		cout << "请输入您要录入的学生院系个数：\n";
		cin >> num;
		cout << "请依次输入学号、姓名、学院、专业、班级、现住址、电话号码、籍贯、入学时间\n";
		for (int i = 0; i < num; i++) {
			string stuid, name, acade, major, schoolclass, address, phonenum, birthplace, entrytime;
			cin >> stuid >> name >> acade >> major >> schoolclass >> address >> phonenum >> birthplace >> entrytime;
			//string stuID, string name, string academy, string major, string schoolClass, string address, string phoneNum, string birthPlace, string intakeTime
			StudentAcade* temp = new StudentAcade(stuid, name, acade, major, schoolclass, address, phonenum, birthplace, entrytime);
			v->stuacade.push_back(temp);
		}
		cout << "是否继续输入（1 是 0 否）？\n";
		cin >> flag;
	}
	Usefstream usefs;
	usefs.addToFile(v, 3);
}

void UseAcade::Alter(vectors* v) {
	Usefstream usefs;
	int ret = 0, flag = 1;
	while (flag == 1) {
		cout << "请输入您要修改的学生学号\n";
		string stuid;
		cin >> stuid;
		for (StudentAcade* c : v->stuacade) {
			if (c->getStuID().compare(stuid) == 0) {
				cout << "已找到名字为：" << c->getName() << " 的学生信息\n";
				cout << "请输入修改信息（学院、专业、班级、现住址）\n";
				string acade, major, schoolclass, address;
				cin >> acade >> major >> schoolclass >> address;
				c->setAcademy(acade);
				c->setMajor(major);
				c->setSchoolClass(schoolclass);
				c->setAddress(address);
				ret++;
			}
		}
		if (ret == 0) {
			cout << "未找到该学生，请重新确认您的信息\n";
		}
		cout << "是否继续修改（1 是 0 否）？\n";
		cin >> flag;
	}
	usefs.addToFile(v, 3);
}

void UseAcade::CX(vectors* v) {
	Usefstream usefs;
	usefs.readFile(v, 3);
}

void UseAcade::Analyse() {

}