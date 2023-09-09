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
		cout << "��������Ҫ¼���ѧ��Ժϵ������\n";
		cin >> num;
		cout << "����������ѧ�š�������ѧԺ��רҵ���༶����סַ���绰���롢���ᡢ��ѧʱ��\n";
		for (int i = 0; i < num; i++) {
			string stuid, name, acade, major, schoolclass, address, phonenum, birthplace, entrytime;
			cin >> stuid >> name >> acade >> major >> schoolclass >> address >> phonenum >> birthplace >> entrytime;
			//string stuID, string name, string academy, string major, string schoolClass, string address, string phoneNum, string birthPlace, string intakeTime
			StudentAcade* temp = new StudentAcade(stuid, name, acade, major, schoolclass, address, phonenum, birthplace, entrytime);
			v->stuacade.push_back(temp);
		}
		cout << "�Ƿ�������루1 �� 0 �񣩣�\n";
		cin >> flag;
	}
	Usefstream usefs;
	usefs.addToFile(v, 3);
}

void UseAcade::Alter(vectors* v) {
	Usefstream usefs;
	int ret = 0, flag = 1;
	while (flag == 1) {
		cout << "��������Ҫ�޸ĵ�ѧ��ѧ��\n";
		string stuid;
		cin >> stuid;
		for (StudentAcade* c : v->stuacade) {
			if (c->getStuID().compare(stuid) == 0) {
				cout << "���ҵ�����Ϊ��" << c->getName() << " ��ѧ����Ϣ\n";
				cout << "�������޸���Ϣ��ѧԺ��רҵ���༶����סַ��\n";
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
			cout << "δ�ҵ���ѧ����������ȷ��������Ϣ\n";
		}
		cout << "�Ƿ�����޸ģ�1 �� 0 �񣩣�\n";
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