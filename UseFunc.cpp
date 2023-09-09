
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

UseInfor infors;//使用学生信息功能性方法
UseStatus status;//使用学籍信息功能性方法
UseAcade acades;//使用学生院系功能性方法
UseScore scores;//使用学生成绩功能性方法
UseDevelop develops;//使用学生培养计划功能性方法

// 对数据录入的功能调用
void UseFunc::UseInputMenu(vectors* v) {
	int choice = 0;
	cin >> choice;
	while (choice > 0 && choice < 7) {
		switch (choice) {
		case 1: {
			cout << "\t\t\t---------------1.学生信息录入--------------\t\t\t\n";
			infors.Input(v);
			break;
		}
		case 2: {
			cout << "\t\t\t---------------2.学籍信息录入--------------\t\t\t\n";
			status.Input(v);
			break;
		}
		case 3: {
			cout << "\t\t\t---------------3.院系信息录入--------------\t\t\t\n";
			acades.Input(v);
			break;
		}
		case 4: {
			cout << "\t\t\t---------------4.成绩信息录入--------------\t\t\t\n";
			scores.Input(v);
			break;
		}
		case 5: {
			cout << "\t\t\t---------------5.培养计划信息录入--------------\t\t\t\n";
			develops.Input(v);
			break;
		}
		case 6: {
			//cout << "\t\t\t---------------6.返回上一级菜单--------------\t\t\t\n";
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

// 对数据修改的功能调用
void UseFunc::UseAlterMenu(vectors* v) {
	int choice = 0;
	cin >> choice;
	while (choice > 0 && choice < 7) {
		switch (choice) {
		case 1: {
			cout << "\t\t\t---------------1.学生信息修改--------------\t\t\t\n";
			infors.Alter(v);
			break;
		}
		case 2: {
			cout << "\t\t\t---------------2.学籍信息修改--------------\t\t\t\n";
			status.Alter(v);
			break;
		}
		case 3: {
			cout << "\t\t\t---------------3.院系信息修改--------------\t\t\t\n";
			acades.Alter(v);
			break;
		}
		case 4: {
			cout << "\t\t\t---------------4.成绩信息修改--------------\t\t\t\n";
			scores.Alter(v);
			break;
		}
		case 5: {
			cout << "\t\t\t---------------5.培养计划信息修改--------------\t\t\t\n";
			develops.Alter(v);
			break;
		}
		case 6: {
			//cout << "\t\t\t---------------6.返回上一级菜单--------------\t\t\t\n";
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

// 对数据查询的功能调用
void UseFunc::UseCXMenu(vectors* v) {
	int choice = 0;
	cin >> choice;
	while (choice > 0 && choice < 7) {
		switch (choice) {
		case 1: {
			cout << "\t\t\t---------------1.学生信息查询--------------\t\t\t\n";
			infors.CX(v);
			system("pause");
			break;
		}
		case 2: {
			cout << "\t\t\t---------------2.学籍信息查询--------------\t\t\t\n";
			status.CX(v);
			system("pause");
			break;
		}
		case 3: {
			cout << "\t\t\t---------------3.院系信息查询--------------\t\t\t\n";
			acades.CX(v);
			system("pause");
			break;
		}
		case 4: {
			//cout << "\t\t\t---------------4.成绩信息查询--------------\t\t\t\n";
			scores.CX(v);
			system("pause");
			break;
		}
		case 5: {
			cout << "\t\t\t---------------5.培养计划信息查询--------------\t\t\t\n";
			develops.CX(v);
			system("pause");
			break;
		}
		case 6: {
			//cout << "\t\t\t---------------6.返回上一级菜单--------------\t\t\t\n";
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

// 对数据分析的功能调用
void UseFunc::UseAnaMenu(vectors* v) {
	int choice = 0;
	cin >> choice;
	while (choice > 0 && choice < 7) {
		switch (choice) {
		case 1: {
			cout << "\t\t\t---------------1.学生信息分析--------------\t\t\t\n";
			infors.Analyse(v);
			break;
		}
		case 2: {
			cout << "\t\t\t---------------2.学籍信息分析--------------\t\t\t\n";
			status.Analyse(v);
			break;
		}
		case 3: {
			cout << "\t\t\t---------------3.成绩信息分析--------------\t\t\t\n";
			scores.Analyse(v);
			system("pause");
			break;
		}
		case 4: {
			//cout << "\t\t\t---------------6.返回上一级菜单--------------\t\t\t\n";
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

//对主菜单功能选择的调用
void UseFunc::UseMainMnue(vectors* v) {
	Menu::mainMenu();
	int choice = 0;
	cin >> choice;
	while (choice > 0 && choice < 6) {
		switch (choice) {
		case 1: {
			Menu::inputMenu();// 调用数据录入菜单
			UseFunc::UseInputMenu(v);
			break;
		}
		case 2: {
			Menu::alterMenu();// 调用数据修改菜单
			UseFunc::UseAlterMenu(v);
			break;
		}
		case 3: {
			Menu::cxMenu();// 调用数据查询菜单
			UseFunc::UseCXMenu(v);
			break;
		}
		case 4: {
			Menu::AnaMenu();// 调用数据分析菜单
			UseFunc::UseAnaMenu(v);
			break;
		}
		case 5: {
			Menu::OutMenu();// 退出程序
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
