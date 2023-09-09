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
	cout << "������Ta��ѧ�ţ�\n";
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
		cout << "\t\tδ�ҵ���ѧ����������ȷ��������Ϣ��\n";
	}

	// ��֤�ַ��������Ƿ����Ҫ��
	if (idNumber.length() != 18) {
		return false;
	}

	// ��֤ǰ17���ַ��Ƿ������֣����һ���ַ��Ƿ������ֻ����Ǵ�д��ĸX
	for (int i = 0; i < 17; i++) {
		if (!isdigit(idNumber[i])) {
			return false;
		}
	}
	if (!isdigit(idNumber[17]) && idNumber[17] != 'X') {
		return false;
	}

	// ����У����
	int weight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	int sum = 0;
	for (int i = 0; i < 17; i++) {
		sum += (idNumber[i] - '0') * weight[i];
	}
	int remainder = sum % 11;
	char checkCode = (remainder == 2) ? 'X' : "10X98765432"[remainder];

	// ���У�����Ƿ�ƥ��
	if (idNumber[17] != checkCode) {
		return false;
	}

	return true;
}

void UseInfor::Input(vectors* v) {
	int flag = 1;
	system("cls");
	cout << "========================================\n";
	cout << "��������Ҫ¼���ѧ����Ϣ������\n";
	int num;
	cin >> num;
	cout << "�������������֤��ѧ�š��������Ա𡢳�������\n";
	while (flag == 1) {
		for (int i = 0; i < num; i++) {
			string numid, stuid, name, gender, birthday;
			cin >> numid >> stuid >> name >> gender >> birthday;
			//string NumID, string StuID, string Name, string Gender, string BirthDay
			StudentInfor* temp = new StudentInfor(numid, stuid, name, gender, birthday);
			v->stuinfor.push_back(temp);
		}
		cout << "�Ƿ�������루1 �� 0 �񣩣�\n";
		cin >> flag;
	}
	setAllAge(v);//�Ѹ���ѧ��������������
	Usefstream usefs;
	usefs.addToFile(v, 1);
}

void UseInfor::Alter(vectors* v) {
	Usefstream usefs;
	int ret = 0, flag = 1;
	while (flag == 1) {
		cout << "��������Ҫ�޸ĵ�ѧ��ѧ��\n";
		string stuid;
		cin >> stuid;
		for (StudentInfor* c : v->stuinfor) {
			if (c->getStuID().compare(stuid) == 0) {
				cout << "���ҵ�����Ϊ��" << c->getName() << "�Ա�Ϊ��" << c->getGender() << "��ѧ����Ϣ\n";
				cout << "�Ƿ��޸ĸ�ѧ����Ϣ��1 �� 0 �񣩣�\n";
				cin >> ret;
				if (ret == 1) {
					cout << "�������ѧ�����֤����������\n";
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
			cout << "δ�ҵ���ѧ��\n";
		}
		cout << "�Ƿ�����޸ģ�1 �� 0 �񣩣�\n";
		cin >> flag;
	}
	setAllAge(v);
	usefs.addToFile(v, 1);
}

void getAge(vectors* v) {
	cout << "��������ҪҪ��ѯ��ѧ��ѧ�ţ�\n";
	string stuid;
	cin >> stuid;
	int ret = 0;
	StudentInfor* valStu = NULL;
	for (StudentInfor* s : v->stuinfor) {
		if (stuid.compare(s->getStuID()) == 0) {
			cout << "\t\t���ҵ���ѧ������ѧ������Ϊ��";
			valStu = s;
			break;
		}
		else ret++;
	}
	if (ret == v->stuinfor.size()) {
		cout << "\t\tδ�ҵ���ѧ����������ȷ�����������Ϣ\n";
	}
	cout << valStu->getAge() << endl;
}

void UseInfor::CX(vectors* v) {
	system("cls");
	cout << "\t\t\t===========================================\t\t\t\n";
	cout << "\t\t\t*        1.��ѯTa��������Ϣ               *\t\t\t\n";
	cout << "\t\t\t*        2.��ȡTa������                   *\t\t\t\n";
	cout << "\t\t\t*        3.�ж�Ta���֤����Ч��           *\t\t\t\n";
	cout << "\t\t\t*        4.������һ��                     *\t\t\t\n";
	cout << "\t\t\t===========================================\t\t\t\n";
	while (true) {
		cout << "\n����������ѡ��\n";
		int choice;
		cin >> choice;
		if (choice == 1) {
			cout << "������Ta��ѧ�ţ�\n";
			string str;
			cin >> str;
			int ret = 0;
			for (StudentInfor* s : v->stuinfor) {
				if (s->getStuID().compare(str) == 0) {
					cout << "��ѧ������Ϣ�ǣ�\n" << "\t\t" << s->showLine() << endl;
					break;
				}
				else ret++;
			}
			if (ret == v->stuinfor.size()) {
				cout << "\t\tδ�ҵ���ѧ����������ȷ��������Ϣ��\n";
			}
		}
		else if (choice == 2) {
			getAge(v);
		}
		else if (choice == 3) {
			if (is_right_numID(v)) {
				cout << "\t\tTa�����֤����Ч�ģ�\n";
			}else {
				cout << "Ta�����֤��Ч��\n";
			}
		}
		else if (choice == 4) {
			break;
		}
		else {
			cout << "\t\t���������Ϣ��������������\n";
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
	cout << "����ѧ�������� " << adult << " �����ֱ��ǣ�" << endl;
	for (StudentInfor* s : Adult) {
		cout << "\t\t\t" << s->getName() << " --> " << s->getAge() << " ��\n";
	}
	cout << "δ����ѧ�������� " << juveniles << " �����ֱ��ǣ�" << endl;
	for (StudentInfor* s : Juveniles) {
		cout << "\t\t\t" << s->getName() << " --> " << s->getAge() << " ��\n";
	}
	cout << "\n======================================================\n";
}

void getGenderRate(vectors* v) {
	vector<StudentInfor*> Man;
	vector<StudentInfor*> Female;
	int man = 0, female = 0;
	for (StudentInfor* s : v->stuinfor) {
		if (s->getGender().compare("��") == 0) {
			Man.push_back(s);
			man++;
		}
		else {
			Female.push_back(s);
			female++;
		}
	}
	cout << "\n======================================================\n";
	cout << "������ " << man << " ����ռ��Ϊ��" << ((double)man / (man + female)) << "�ֱ��ǣ�" << endl;
	for (StudentInfor* s : Man) {
		cout << "\t\t\t" << s->getName() << " --> " << s->getStuID() << endl;
	}
	cout << "Ů���� " << female << " ����ռ��Ϊ��" << ((double)female / (man + female)) << "�ֱ��ǣ�" << endl;
	for (StudentInfor* s : Female) {
		cout << "\t\t\t" << s->getName() << " --> " << s->getStuID() << endl;
	}
	cout << "\n======================================================\n";
}




void UseInfor::Analyse(vectors* v) {
	system("cls");
	cout << "\t\t\t===================================\t\t\t\n";
	cout << "\t\t\t*       1.����ѧ����δ����ѧ��    *\t\t\t\n";
	cout << "\t\t\t*       2.��Ůռ��                *\t\t\t\n";
	cout << "\t\t\t*       3.������һ��              *\t\t\t\n";
	cout << "\t\t\t===================================\t\t\t\n";
	while (true) {
		cout << "\n����������ѡ��\n";
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
			cout << "���������������������룡\n";
		}
	}


}