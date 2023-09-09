
#ifndef USEFUNC_H
#define USEFUNC_H
#endif
#include"UseFunc.h"
#include"Menu.h"
#include"vectors.h"
#include"UseInfor.h"
#include"UseScore.h"
#include"UseAcade.h"
#include "UseStatus.h"
#include"UseDevelop.h"
#include<iostream>
using namespace std;

UseInfor infors;//ʹ��ѧ����Ϣ�����Է���
UseStatus status;//ʹ��ѧ����Ϣ�����Է���
UseAcade acades;//ʹ��ѧ��Ժϵ�����Է���
UseScore scores;//ʹ��ѧ���ɼ������Է���
UseDevelop develops;//ʹ��ѧ�������ƻ������Է���

// ������¼��Ĺ��ܵ���
void UseFunc::UseInputMenu(vectors* v) {
	int choice = 0;
	cin >> choice;
	while (choice > 0 && choice < 7) {
		switch (choice) {
		case 1: {
			cout << "\t\t\t---------------1.ѧ����Ϣ¼��--------------\t\t\t\n";
			infors.Input(v);
			break;
		}
		case 2: {
			cout << "\t\t\t---------------2.ѧ����Ϣ¼��--------------\t\t\t\n";
			status.Input(v);
			break;
		}
		case 3: {
			cout << "\t\t\t---------------3.Ժϵ��Ϣ¼��--------------\t\t\t\n";
			acades.Input(v);
			break;
		}
		case 4: {
			cout << "\t\t\t---------------4.�ɼ���Ϣ¼��--------------\t\t\t\n";
			scores.Input(v);
			break;
		}
		case 5: {
			cout << "\t\t\t---------------5.�����ƻ���Ϣ¼��--------------\t\t\t\n";
			develops.Input(v);
			break;
		}
		case 6: {
			//cout << "\t\t\t---------------6.������һ���˵�--------------\t\t\t\n";
			UseFunc::UseMainMnue(v);
			break;
		}
		default: {
			break;
		}
		}
		Menu::inputMenu();
		cin >> choice;
	}
}

// �������޸ĵĹ��ܵ���
void UseFunc::UseAlterMenu(vectors* v) {
	int choice = 0;
	cin >> choice;
	while (choice > 0 && choice < 7) {
		switch (choice) {
		case 1: {
			cout << "\t\t\t---------------1.ѧ����Ϣ�޸�--------------\t\t\t\n";
			infors.Alter(v);
			break;
		}
		case 2: {
			cout << "\t\t\t---------------2.ѧ����Ϣ�޸�--------------\t\t\t\n";
			status.Alter(v);
			break;
		}
		case 3: {
			cout << "\t\t\t---------------3.Ժϵ��Ϣ�޸�--------------\t\t\t\n";
			acades.Alter(v);
			break;
		}
		case 4: {
			cout << "\t\t\t---------------4.�ɼ���Ϣ�޸�--------------\t\t\t\n";
			scores.Alter(v);
			break;
		}
		case 5: {
			cout << "\t\t\t---------------5.�����ƻ���Ϣ�޸�--------------\t\t\t\n";
			develops.Alter(v);
			break;
		}
		case 6: {
			//cout << "\t\t\t---------------6.������һ���˵�--------------\t\t\t\n";
			UseFunc::UseMainMnue(v);
			break;
		}
		default: {
			break;
		}
		}
		Menu::alterMenu();
		cin >> choice;
	}
}

// �����ݲ�ѯ�Ĺ��ܵ���
void UseFunc::UseCXMenu(vectors* v) {
	int choice = 0;
	cin >> choice;
	while (choice > 0 && choice < 7) {
		switch (choice) {
		case 1: {
			cout << "\t\t\t---------------1.ѧ����Ϣ��ѯ--------------\t\t\t\n";
			infors.CX(v);
			system("pause");
			break;
		}
		case 2: {
			cout << "\t\t\t---------------2.ѧ����Ϣ��ѯ--------------\t\t\t\n";
			status.CX(v);
			system("pause");
			break;
		}
		case 3: {
			cout << "\t\t\t---------------3.Ժϵ��Ϣ��ѯ--------------\t\t\t\n";
			acades.CX(v);
			system("pause");
			break;
		}
		case 4: {
			//cout << "\t\t\t---------------4.�ɼ���Ϣ��ѯ--------------\t\t\t\n";
			scores.CX(v);
			system("pause");
			break;
		}
		case 5: {
			cout << "\t\t\t---------------5.�����ƻ���Ϣ��ѯ--------------\t\t\t\n";
			develops.CX(v);
			system("pause");
			break;
		}
		case 6: {
			//cout << "\t\t\t---------------6.������һ���˵�--------------\t\t\t\n";
			UseFunc::UseMainMnue(v);
			break;
		}
		default: {
			break;
		}
		}
		Menu::cxMenu();
		cin >> choice;
	}
}

// �����ݷ����Ĺ��ܵ���
void UseFunc::UseAnaMenu(vectors* v) {
	int choice = 0;
	cin >> choice;
	while (choice > 0 && choice < 7) {
		switch (choice) {
		case 1: {
			cout << "\t\t\t---------------1.ѧ����Ϣ����--------------\t\t\t\n";
			infors.Analyse(v);
			break;
		}
		case 2: {
			cout << "\t\t\t---------------2.ѧ����Ϣ����--------------\t\t\t\n";
			status.Analyse(v);
			break;
		}
		case 3: {
			cout << "\t\t\t---------------3.�ɼ���Ϣ����--------------\t\t\t\n";
			scores.Analyse(v);
			system("pause");
			break;
		}
		case 4: {
			//cout << "\t\t\t---------------6.������һ���˵�--------------\t\t\t\n";
			UseFunc::UseMainMnue(v);
			break;
		}
		default: {
			break;
		}
		}
		Menu::AnaMenu();
		cin >> choice;
	}
}

//�����˵�����ѡ��ĵ���
void UseFunc::UseMainMnue(vectors* v) {
	Menu::mainMenu();
	int choice = 0;
	cin >> choice;
	while (choice > 0 && choice < 6) {
		switch (choice) {
		case 1: {
			Menu::inputMenu();// ��������¼��˵�
			UseFunc::UseInputMenu(v);
			break;
		}
		case 2: {
			Menu::alterMenu();// ���������޸Ĳ˵�
			UseFunc::UseAlterMenu(v);
			break;
		}
		case 3: {
			Menu::cxMenu();// �������ݲ�ѯ�˵�
			UseFunc::UseCXMenu(v);
			break;
		}
		case 4: {
			Menu::AnaMenu();// �������ݷ����˵�
			UseFunc::UseAnaMenu(v);
			break;
		}
		case 5: {
			Menu::OutMenu();// �˳�����
			break;
		}
		default: {
			break;
		}
		}
		Menu::mainMenu();
		cin >> choice;
	}
	return;
}
