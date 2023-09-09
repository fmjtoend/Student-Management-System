#ifndef USESTATUS_H
#define USESTATUS_H
#endif // !USESTATUS_H
#include "UseStatus.h"
#include"Usefstream.h"
#include"vectors.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void UseStatus::Input(vectors* v) {
	int flag = 1;
	while (flag == 1) {
		cout << "请输入您要录入的学生信息数量：\n";
		int num;
		cin >> num;
		cout << "请依次输入学号、姓名、学院、专业、班级、现住址、性别、手机号码、家庭住址、邮政编码、籍贯\n";
		for (int i = 0; i < num; i++) {
			string stuid, name, acade, major, schoolclass, address, gender, phonenum, home, postcode, birthplace;
			cin >> stuid >> name >> acade >> major >> schoolclass >> address >> gender >> phonenum >> home >> postcode >> birthplace;
			StudentStatus* temp = new StudentStatus(stuid, name, acade, major, schoolclass, address, gender, phonenum, home, postcode, birthplace);
			v->stustatus.push_back(temp);
		}
		cout << "是否继续输入（1 是 0 否）？\n";
		cin >> flag;
	}
	Usefstream usefs;
	usefs.addToFile(v, 2);
}

void UseStatus::Alter(vectors* v) {
	Usefstream usefs;
	int ret = 0, flag = 1;
	while (flag == 1) {
		cout << "请输入您要修改的学生学号\n";
		string stuid;
		cin >> stuid;
		for (StudentStatus* c : v->stustatus) {
			if (c->getStuID().compare(stuid) == 0) {
				cout << "已找到名字为：" << c->getName() << " 的学生信息\n";
				cout << "请输入修改信息（手机号码、家庭住址、邮政编码、籍贯）\n";
				string phonenum, home, postcode, birthplace;
				cin >> phonenum >> home >> postcode >> birthplace;
				c->setPhoneNum(phonenum);
				c->setHome(home);
				c->setPostCode(postcode);
				c->setBirthPlace(birthplace);
				ret++;
			}
		}
		if (ret == 0) {
			cout << "未找到该学生，请重新确认您的信息\n";
		}
		cout << "是否继续修改（1 是 0 否）？\n";
		cin >> flag;
	}
	usefs.addToFile(v, 2);
}

void UseStatus::CX(vectors* v) {
	int flag = 1;
	while (flag == 1) {
		cout << "请输入您要要查询的学生学号：\n";
		string stuid;
		cin >> stuid;
		int ret = 0;
		for (StudentStatus* s : v->stustatus) {
			if (stuid.compare(s->getStuID()) == 0) {
				cout << "\t\t已找到该学生，该学生的信息是：\n";
				cout << "\t\t" << s->showLine() << endl;
				break;
			}
			else ret++;
		}
		if (ret == v->stustatus.size()) {
			cout << "\t\t未找到该学生，请重新确认您输入的信息\n";
		}
		cout << "是否继续查询（1 是 0 否）？\n";
		cin >> flag;
	}
}


bool cmp1(StudentStatus* a, StudentStatus* b) {
	return a->getNum() > b->getNum();
}

void getBirthPlaceRate(vectors* v) {
	vector<StudentStatus*> vt;
	for (int i = 0; i < v->stustatus.size(); i++) {
		if (i == 0) {
			vt.push_back(v->stustatus[i]);
			vt[i]->setNum(1);
			i++;
		}
		int n = vt.size(), ret = 0, flag = -1;
		for (int j = 0; j < n; j++) {
			if (v->stustatus[i]->getBirthPlace().compare(vt[j]->getBirthPlace()) == 0) {
				flag = j;
				break;
			}
			else
				ret++;
		}
		if (flag != -1) {
			int n = vt[flag]->getNum() + 1;
			vt[flag]->setNum(n);
		}
		if (ret == vt.size()) {
			vt.push_back(v->stustatus[i]);
			vt[vt.size() - 1]->setNum(1);
		}
	}
	sort(vt.begin(), vt.end(), cmp1);
	cout << "----------------------------------------------\n";
	for (StudentStatus* s : vt) {
		cout << s->getBirthPlace() << " -> " << ((double)s->getNum() / v->stustatus.size()) << endl;
	}
	cout << "----------------------------------------------\n";
}

void getHomeRate(vectors* v) {
	vector<StudentStatus*> vt;
	for (int i = 0; i < v->stustatus.size(); i++) {
		if (i == 0) {
			vt.push_back(v->stustatus[i]);
			vt[i]->setNum(1);
			i++;
		}
		int n = vt.size(), ret = 0, flag = -1;
		for (int j = 0; j < n; j++) {
			if (v->stustatus[i]->getHome().compare(vt[j]->getHome()) == 0) {
				flag = j;
				break;
			}
			else
				ret++;
		}
		if (flag != -1) {
			int n = vt[flag]->getNum() + 1;
			vt[flag]->setNum(n);
		}
		if (ret == vt.size()) {
			vt.push_back(v->stustatus[i]);
			vt[vt.size() - 1]->setNum(1);
		}
	}
	sort(vt.begin(), vt.end(), cmp1);
	cout << "----------------------------------------------\n";
	for (StudentStatus* s : vt) {
		cout << s->getHome() << " -> " << ((double)s->getNum() / v->stustatus.size()) << endl;
	}
	cout << "----------------------------------------------\n";
}

void getAddressRate(vectors* v) {
	vector<StudentStatus*> vt;
	for (int i = 0; i < v->stustatus.size(); i++) {
		if (i == 0) {
			vt.push_back(v->stustatus[i]);
			vt[i]->setNum(1);
			i++;
		}
		int n = vt.size(), ret = 0, flag = -1;
		for (int j = 0; j < n; j++) {
			if (v->stustatus[i]->getAddress().compare(vt[j]->getAddress()) == 0) {
				flag = j;
				break;
			}
			else
				ret++;
		}
		if (flag != -1) {
			int n = vt[flag]->getNum() + 1;
			vt[flag]->setNum(n);
		}
		if (ret == vt.size()) {
			vt.push_back(v->stustatus[i]);
			vt[vt.size() - 1]->setNum(1);
		}
	}
	sort(vt.begin(), vt.end(), cmp1);
	cout << "----------------------------------------------\n";
	for (StudentStatus* s : vt) {
		cout << s->getAddress() << " -> " << ((double)s->getNum() / v->stustatus.size()) << endl;
	}
	cout << "----------------------------------------------\n";
}

void UseStatus::Analyse(vectors* v) {
	system("cls");
	cout << "\t\t\t========================================\t\t\t\n";
	cout << "\t\t\t*      1.籍贯各地区人数占比            *\t\t\t\n";
	cout << "\t\t\t*      2.家庭住址各地区人数占比        *\t\t\t\n";
	cout << "\t\t\t*      3.现住址各校区人数占比          *\t\t\t\n";
	cout << "\t\t\t*      4.返回上一级                    *\t\t\t\n";
	cout << "\t\t\t========================================\t\t\t\n";
	int choice;
	while (true) { 
		cout << "\n请输入您的选择：\n";
		cin >> choice;
		if (choice == 1) {
			getBirthPlaceRate(v);
		}
		else if (choice == 2) {
			getHomeRate(v);
		}
		else if (choice == 3) {
			getAddressRate(v);
		}
		else if (choice == 4) {
			break;
		}
		else {
			cout << "您的输入有误，请重新输入！\n";
		}
	}
	
}
