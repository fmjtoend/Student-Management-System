#ifndef USESCORE_H
#define USESCORE_H
#endif // !USESCORE_H

#include "UseScore.h"
#include"Usefstream.h"
#include"vectors.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

void UseScore::Input(vectors* v) {
	int flag = 1;
	
	while (flag == 1) {
		int num;
		cout << "��������Ҫ¼������ݸ�����\n";
		cin >> num;
		cout << "����������ѧ�š��γ̱�š��γ����ơ�ѧ�֡�ƽʱ�ɼ�����ĩ�ɼ���ѧ�� \n";
		for (int i = 0; i < num; i++) {
			string stuid, keid, kename;
			double xuefen, pingshi, qimo;
			int xueqi;
			cin >> stuid >> keid >> kename >> xuefen >> pingshi >> qimo >> xueqi;

			//string StuID, string CourseID, string CourseName, double credit, double DailyGrade, double FinalGrade,int SchoolTerm
			StudentScore* temp = new StudentScore(stuid, keid, kename, xuefen, pingshi, qimo, xueqi);
			v->stuscores.push_back(temp);
		}
		cout << "�Ƿ�������루1 ��  0 �񣿣�\n";
		cin >> flag;
	}
	Usefstream usefs;
	usefs.addToFile(v, 4);
}


void UseScore::Alter(vectors* v) {
	Usefstream usefs;
	int flag = 1;
	while (flag == 1) {
		cout << "��������Ҫ�޸ĵ�ѧ��ѧ�š��γ̱��롢����ѧ��\n";
		string num, courseid;
		int term, ret = 0;
		cin >> num >> courseid >> term;
		for (StudentScore* c : v->stuscores) {
			if ((c->getStuID().compare(num) == 0) && (c->getCourseID().compare(courseid) == 0) && (c->getSchoolTerm() == term)) {
				cout << "���ҵ���ѧ��" << endl;
				cout << "������ƽʱ�ɼ�����ĩ�ɼ�\n";
				double dailySc = 0, finalSc = 0;
				cin >> dailySc >> finalSc;
				c->setDailyGrade(dailySc);
				c->setFinalGrade(finalSc);
				c->update();
				ret++;
			}
		}
		if (ret == 0) {
			cout << "δ�ҵ���ѧ������ȷ��������Ϣ�Ƿ�����\n";
		}
		cout << "�Ƿ�����޸ģ�1 �� 0 �񣩣�\n";
		cin >> flag;
	}
	usefs.addToFile(v, 4);
}

void UseScore::CX(vectors* v) {
	//v ����洢��ѧ����Ϣ�����ᡢԺϵ���ɼ��������ƻ�ȫ����Ϣ
	//v->stuscores ����洢����ȫ��ѧ����ȫ���ɼ���Ϣ
	if (v->stuscores.empty()) {
		cout << "û���κ�ѧ���ɼ���Ϣ�������Ƚ���¼�������лл��\n";
		return;
	}
	system("cls");
	int flag = 1;
	while (flag == 1) {
		vector<StudentScore*> vt;
		cout << "\n---------------------------------------------------\n";
		cout << "��������Ҫ��ѯ��ѧ��ѧ�ţ�\n";
		string stuid;
		cin >> stuid;
		//����ǿforѭ������ѧ����ȫ����Ϣ���ӵ���ʱ����vt��
		for (StudentScore* s : v->stuscores) {
			if (stuid.compare(s->getStuID()) == 0) {
				vt.push_back(s);
			}
		}
		cout << "ѧ��Ϊ��" << stuid << " ��ѧ�����������ɼ����£�\n";
		for (StudentScore* s : vt) {
			cout << "\t\t" << s->getCourseID() << " -> " << s->getCourseName() << " -> " << s->getTotalGrade() << "\n";
		}
		cout << "---------------------------------------------------\n";
		cout << "\n�Ƿ������ѯ��1 �� 0 �񣩣�\n";
		cin >> flag;
	}
}

bool cmp1(StudentScore* a, StudentScore* b) {
	if (a->getTotalGrade() == b->getTotalGrade()) {
		return a->getFinalGrade() > b->getFinalGrade();
	}
	return a->getTotalGrade() > b->getTotalGrade();
}

bool cmp2(StudentScore* a, StudentScore* b) {
	if (a->getAllGradePoint() == b->getAllGradePoint()) {
		return a->getStuID() < b->getStuID();
	}
	return a->getAllGradePoint() > b->getAllGradePoint();
}

bool cmp3(StudentScore* a, StudentScore* b) {
	if (a->getPassRate() == b->getPassRate()) {
		return a->getCourseID() < b->getCourseID();
	}
	return a->getPassRate() > b->getPassRate();
}

void UseScore::sortTotalGrade(vectors* v) {
	sort(v->stuscores.begin(), v->stuscores.end(), cmp1);
}

void passStudent(vectors* v) {
	double num = 0;
	vector<StudentScore*> temp;
	for (StudentScore* s : v->stuscores) {
		if (s->getTotalGrade() >= 60) { //�ܳɼ�����60��Ϊ�ҿ�
			temp.push_back(s);
			num++;
		}
	}
	cout << "��������Ϊ��" << num << ", ������Ϊ��" << (num / v->stuscores.size()) << endl;
	cout << "ѧ�ŷֱ��ǣ�";
	for (StudentScore* s : temp) {
		cout << s->getStuID() << " ";
	}
	cout << endl;
}

void static failStudent(vectors* v) {

	int num = 0;
	vector<StudentScore*> temp;
	for (StudentScore* s : v->stuscores) {
		if (s->getTotalGrade() >= 60) { //�ܳɼ�����60��Ϊ�ҿ�
			temp.push_back(s);
			num++;
		}
	}
	cout << "����������Ϊ��" << num << ", ������Ϊ��" << (num / v->stuscores.size()) << endl;
	cout << "ѧ�ŷֱ��ǣ�";
	for (StudentScore* s : temp) {
		cout << s->getStuID() << " ";
	}
	cout << endl;
}

struct CustomCompare {
	bool operator()(StudentScore* a, StudentScore* b) const {
		return a->getGradePoint() < b->getGradePoint();
	}
};

void personalScore(vectors* v) {
	vector<StudentScore*> vt;
	for (int i = 0; i < v->stuscores.size(); i++) {
		if (i == 0) {
			vt.push_back(v->stuscores[i]);
			vt[i]->setAllGradePoint(v->stuscores[i]->getGradePoint());//�õ�һ�����ܼ�������¼�������
			i++;
		}
		//ret : ���ret��ֵ��vt.size()��ȣ�˵����һ���µ�ѧ�ţ���push_back() 
		//flag : �������ͬ�ģ��Ǿͼ�¼��ʱvt���±�flag ��Ȼ������ѭ��
		int n = vt.size(), ret = 0, flag = -1;
		for (int j = 0; j < n; j++) {
			if (v->stuscores[i]->getStuID().compare(vt[j]->getStuID()) == 0) {
				flag = j;
				break;
			}
			else 
				ret++;
		}
		if (flag != -1) {
			double t = vt[flag]->getAllGradePoint() + v->stuscores[i]->getGradePoint();
			vt[flag]->setAllGradePoint(t);//��ͬ�ĵ����Լ��ļ����µļ���
		}
		if (ret == vt.size()) {
			vt.push_back(v->stuscores[i]);//����ͬ�ͼӽ��µ����������ܼ���Ҫ�����¼�������
			vt[vt.size() - 1]->setAllGradePoint(v->stuscores[i]->getGradePoint());
		}
	}
	int i = 1;
	sort(vt.begin(), vt.end(), cmp2);
	cout << "\n\n----------------------------------------\n";
	for (StudentScore* s : vt) {
		cout << "�� " << i << " ����ѧ��ѧ��Ϊ" << s->getStuID() << ", �ܼ���Ϊ��" << s->getAllGradePoint() << endl;
		i++;
	}
	cout << "----------------------------------------\n";
}

void SubjectPassRate(vectors* v) {
	vector<StudentScore*> vt;//���ڴ洢���Ƶ����ݣ���γ̱�š�����
	//��Ҫһ���洢�ÿƼ��������벻��������������
	vector<int> pass;
	vector<int> fail;
	for (int i = 0; i < v->stuscores.size(); i++) {
		if (i == 0) {
			vt.push_back(v->stuscores[i]);
			if (vt[i]->is_Pass()) 
				vt[i]->setPassNum(1);
			else
				vt[i]->setFailNum(1);
			i++;
		}
		int n = vt.size(), ret = 0, flag = -1;
		for (int j = 0; j < n; j++) {
			if (v->stuscores[i]->getCourseID().compare(vt[j]->getCourseID()) == 0) {
				flag = j;//��¼��v->stuscores[i]��ͬ�ģ���vt���±�
				break;
			}
			else
				ret++;
		}
		if (flag != -1) {//˵�����v[i] ��ǰ���vt[flag] ��getCourseID()��ͬ���Ǿͼӽ�ȥ
			if (v->stuscores[i]->is_Pass()) {
				int n = vt[flag]->getPassNum() + 1;
				vt[flag]->setPassNum(n);
			}
			else {
				int n = vt[flag]->getFailNum() + 1;
				vt[flag]->setFailNum(n);
			}
		}
		if (ret == vt.size()) {
			vt.push_back(v->stuscores[i]);
			if (vt[vt.size() - 1]->is_Pass()) {
				int n = vt[vt.size() - 1]->getPassNum() + 1;
				vt[vt.size() - 1]->setPassNum(n + 1);
			}
			else {
				int n = vt[vt.size() - 1]->getFailNum() + 1;
				vt[vt.size() - 1]->setFailNum(n);
			}
		}
	}
	int i = 1;
	sort(vt.begin(), vt.end(), cmp3);
	cout << "\n\n----------------------------------\n";
	for (StudentScore* s : vt) {
		cout << "�� " << i << " ���Ŀγ̱���ǣ�" << s->getCourseID() << ", �γ������ǣ�" << s->getCourseName() << ", ������Ϊ��" << s->getPassRate() << endl;
		i++;
	}
	cout << "\n----------------------------------\n";
}

void UseScore::Analyse(vectors* v) {
	//����Ҫ�ģ�1.���ݼ����ɸߵ����� 2.�õ����Ƽ����ʼ�������
	system("cls");
	cout << "\t\t\t===========================================================\t\t\t\n";
	cout << "\t\t\t*      1.����ѧ���ܳɼ��������ɼ��������ɸߵ�������     *\t\t\t\n";
	cout << "\t\t\t*      2.�������Ƶļ����ʼ�������                         *\t\t\t\n";
	cout << "\t\t\t===========================================================\t\t\t\n";
	int flag = 0;
	cin >> flag;
	if (flag == 1) {
		personalScore(v);
	}
	else if (flag == 2) {
		SubjectPassRate(v);
	}
}