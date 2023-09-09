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
		cout << "��������Ҫ¼��������ƻ�������\n";
		cin >> num;
		//string courseID, string courseName, double credit, int openingCourseTime
		cout << "����������γ̱�š��γ����ơ�ѧ�֡�����ѧ��\n";
		for (int i = 0; i < num; i++) {
			string courseid, coursename;
			double credit;
			int openingtime;
			cin >> courseid >> coursename >> credit >> openingtime;
			StudentDevelop* temp = new StudentDevelop(courseid, coursename, credit, openingtime);
			v->studevelop.push_back(temp);
		}
		cout << "�Ƿ�������루1 �� 0 �񣩣�\n";
		cin >> flag;
	}
	Usefstream usefs;
	usefs.addToFile(v, 5);
}

void UseDevelop::Alter(vectors* v) {
	Usefstream usefs;
	int ret = 0, flag = 1;
	while (flag == 1) {
		cout << "��������Ҫ�޸ĵĿγ̱��\n";
		string courseid;
		cin >> courseid;
		for (StudentDevelop* c : v->studevelop) {
			if (c->getCourseID().compare(courseid) == 0) {
				cout << "���ҵ��ÿγ̵���Ϣ\n";
				cout << "��������Ҫ�޸ĵ���Ϣ���γ����ơ�ѧ�֡�����ѧ�ڣ�\n";
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
			cout << "δ�ҵ���ѧ����������ȷ��������Ϣ\n";
		}
		cout << "�Ƿ�����޸ģ�1 �� 0 �񣩣�\n";
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