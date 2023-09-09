#ifndef USEINFOR_H
#define USEINFOR_H
#endif // !USEINFOR_H

#include "UseInfor.h"
#include"Usefstream.h"
#include"vectors.h"
#include"Date.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void setAllAge(vectors* v) {
	for (StudentInfor* s : v->stuinfor) {
		Date date(s->getBirthDay());
		s->setAge(date.calculateAge());
	}
}

bool is_right_numID(vectors* v) {
	string idNumber = "";
	cout << "请输入Ta的学号：\n";
	string str;
	cin >> str;
	int ret = 0;
	for (StudentInfor* s : v->stuinfor) {
		if (s->getStuID().compare(str) == 0) {
			idNumber = s->getNumID();
			break;
		}
		else ret++;
	}
	if (ret == v->stuinfor.size()) {
		cout << "\t\t未找到该学生，请重新确认您的信息！\n";
	}

	// 验证字符串长度是否符合要求
	if (idNumber.length() != 18) {
		return false;
	}

	// 验证前17个字符是否都是数字，最后一个字符是否是数字或者是大写字母X
	for (int i = 0; i < 17; i++) {
		if (!isdigit(idNumber[i])) {
			return false;
		}
	}
	if (!isdigit(idNumber[17]) && idNumber[17] != 'X') {
		return false;
	}

	// 计算校验码
	int weight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	int sum = 0;
	for (int i = 0; i < 17; i++) {
		sum += (idNumber[i] - '0') * weight[i];
	}
	int remainder = sum % 11;
	char checkCode = (remainder == 2) ? 'X' : "10X98765432"[remainder];

	// 检查校验码是否匹配
	if (idNumber[17] != checkCode) {
		return false;
	}

	return true;
}

void UseInfor::Input(vectors* v) {
	int flag = 1;
	system("cls");
	cout << "========================================\n";
	cout << "请输入您要录入的学生信息个数：\n";
	int num;
	cin >> num;
	cout << "请依次输入身份证、学号、姓名、性别、出生日期\n";
	while (flag == 1) {
		for (int i = 0; i < num; i++) {
			string numid, stuid, name, gender, birthday;
			cin >> numid >> stuid >> name >> gender >> birthday;
			//string NumID, string StuID, string Name, string Gender, string BirthDay
			StudentInfor* temp = new StudentInfor(numid, stuid, name, gender, birthday);
			v->stuinfor.push_back(temp);
		}
		cout << "是否继续输入（1 是 0 否）？\n";
		cin >> flag;
	}
	setAllAge(v);//把各个学生的年龄计算出来
	Usefstream usefs;
	usefs.addToFile(v, 1);
}

void UseInfor::Alter(vectors* v) {
	Usefstream usefs;
	int ret = 0, flag = 1;
	while (flag == 1) {
		cout << "请输入您要修改的学生学号\n";
		string stuid;
		cin >> stuid;
		for (StudentInfor* c : v->stuinfor) {
			if (c->getStuID().compare(stuid) == 0) {
				cout << "已找到名字为：" << c->getName() << "性别为：" << c->getGender() << "的学生信息\n";
				cout << "是否修改该学生信息（1 是 0 否）？\n";
				cin >> ret;
				if (ret == 1) {
					cout << "请输入该学生身份证、出生日期\n";
					string numid, birthday;
					cin >> numid >> birthday;
					c->setNumID(numid);
					c->setBirthDay(birthday);
					ret = 0;
				}
				ret++;
			}
		}
		if (ret == 0) {
			cout << "未找到该学生\n";
		}
		cout << "是否继续修改（1 是 0 否）？\n";
		cin >> flag;
	}
	setAllAge(v);
	usefs.addToFile(v, 1);
}

void getAge(vectors* v) {
	cout << "请输入您要要查询的学生学号：\n";
	string stuid;
	cin >> stuid;
	int ret = 0;
	StudentInfor* valStu = NULL;
	for (StudentInfor* s : v->stuinfor) {
		if (stuid.compare(s->getStuID()) == 0) {
			cout << "\t\t已找到该学生，该学生年龄为：";
			valStu = s;
			break;
		}
		else ret++;
	}
	if (ret == v->stuinfor.size()) {
		cout << "\t\t未找到该学生，请重新确认您输入的信息\n";
	}
	cout << valStu->getAge() << endl;
}

void UseInfor::CX(vectors* v) {
	system("cls");
	cout << "\t\t\t===========================================\t\t\t\n";
	cout << "\t\t\t*        1.查询Ta的所有信息               *\t\t\t\n";
	cout << "\t\t\t*        2.获取Ta的年龄                   *\t\t\t\n";
	cout << "\t\t\t*        3.判断Ta身份证的有效性           *\t\t\t\n";
	cout << "\t\t\t*        4.返回上一级                     *\t\t\t\n";
	cout << "\t\t\t===========================================\t\t\t\n";
	while (true) {
		cout << "\n请输入您的选择：\n";
		int choice;
		cin >> choice;
		if (choice == 1) {
			cout << "请输入Ta的学号：\n";
			string str;
			cin >> str;
			int ret = 0;
			for (StudentInfor* s : v->stuinfor) {
				if (s->getStuID().compare(str) == 0) {
					cout << "该学生的信息是：\n" << "\t\t" << s->showLine() << endl;
					break;
				}
				else ret++;
			}
			if (ret == v->stuinfor.size()) {
				cout << "\t\t未找到该学生，请重新确认您的信息！\n";
			}
		}
		else if (choice == 2) {
			getAge(v);
		}
		else if (choice == 3) {
			if (is_right_numID(v)) {
				cout << "\t\tTa的身份证是有效的！\n";
			}else {
				cout << "Ta的身份证无效！\n";
			}
		}
		else if (choice == 4) {
			break;
		}
		else {
			cout << "\t\t您输入的信息有误，请重新输入\n";
		}
	}
}

void getAdult(vectors* v) {
	vector<StudentInfor*> Adult;
	vector<StudentInfor*> Juveniles;
	int adult = 0, juveniles = 0;
	for (StudentInfor* s : v->stuinfor) {
		if (s->getAge() >= 18) {
			Adult.push_back(s);
			adult++;
		}
		else {
			Juveniles.push_back(s);
			juveniles++;
		}
	}
	cout << "\n======================================================\n";
	cout << "成年学生数共有 " << adult << " 个，分别是：" << endl;
	for (StudentInfor* s : Adult) {
		cout << "\t\t\t" << s->getName() << " --> " << s->getAge() << " 岁\n";
	}
	cout << "未成年学生数共有 " << juveniles << " 个，分别是：" << endl;
	for (StudentInfor* s : Juveniles) {
		cout << "\t\t\t" << s->getName() << " --> " << s->getAge() << " 岁\n";
	}
	cout << "\n======================================================\n";
}

void getGenderRate(vectors* v) {
	vector<StudentInfor*> Man;
	vector<StudentInfor*> Female;
	int man = 0, female = 0;
	for (StudentInfor* s : v->stuinfor) {
		if (s->getGender().compare("男") == 0) {
			Man.push_back(s);
			man++;
		}
		else {
			Female.push_back(s);
			female++;
		}
	}
	cout << "\n======================================================\n";
	cout << "男生有 " << man << " 个，占比为：" << ((double)man / (man + female)) << "分别是：" << endl;
	for (StudentInfor* s : Man) {
		cout << "\t\t\t" << s->getName() << " --> " << s->getStuID() << endl;
	}
	cout << "女生有 " << female << " 个，占比为：" << ((double)female / (man + female)) << "分别是：" << endl;
	for (StudentInfor* s : Female) {
		cout << "\t\t\t" << s->getName() << " --> " << s->getStuID() << endl;
	}
	cout << "\n======================================================\n";
}




void UseInfor::Analyse(vectors* v) {
	system("cls");
	cout << "\t\t\t===================================\t\t\t\n";
	cout << "\t\t\t*       1.成年学生与未成年学生    *\t\t\t\n";
	cout << "\t\t\t*       2.男女占比                *\t\t\t\n";
	cout << "\t\t\t*       3.返回上一级              *\t\t\t\n";
	cout << "\t\t\t===================================\t\t\t\n";
	while (true) {
		cout << "\n请输入您的选择：\n";
		int choice;
		cin >> choice;
		if (choice == 1) {
			getAdult(v);
		}
		else if (choice == 2) {
			getGenderRate(v);
		}
		else if (choice == 3) {
			break;
		}
		else {
			cout << "您的输入有误，请重新输入！\n";
		}
	}


}