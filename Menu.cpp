#include "Menu.h"
#include"UseFunc.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

//主菜单功能选择界面
void Menu::mainMenu() {
	system("cls");
	cout << "\t\t\t==============================================\t\t\t\n";
	cout << "\t\t\t*                1.数据录入菜单              *\t\t\t\n";
	cout << "\t\t\t*                2.数据修改菜单              *\t\t\t\n";
	cout << "\t\t\t*                3.数据查询菜单              *\t\t\t\n";
	cout << "\t\t\t*                4.统计分析菜单              *\t\t\t\n";
	cout << "\t\t\t*                5.退出系统                  *\t\t\t\n";
	cout << "\t\t\t==============================================\t\t\t\n";
}

//数据录入功能选择界面
void Menu::inputMenu() {
	system("cls");
	cout << "\t\t\t==============================================\t\t\t\n";
	cout << "\t\t\t*            1.学生信息录入                  *\t\t\t\n";
	cout << "\t\t\t*            2.学籍信息录入                  *\t\t\t\n";
	cout << "\t\t\t*            3.院系信息录入                  *\t\t\t\n";
	cout << "\t\t\t*            4.成绩信息录入                  *\t\t\t\n";
	cout << "\t\t\t*            5.培养计划信息录入              *\t\t\t\n";
	cout << "\t\t\t*            6.返回上一级                    *\t\t\t\n";
	cout << "\t\t\t==============================================\t\t\t\n";
}

//数据修改功能选择界面
void Menu::alterMenu() {
	system("cls");
	cout << "\t\t\t==============================================\t\t\t\n";
	cout << "\t\t\t*             1.学生信息修改                 *\t\t\t\n";
	cout << "\t\t\t*             2.学籍信息修改                 *\t\t\t\n";
	cout << "\t\t\t*             3.院系信息修改                 *\t\t\t\n";
	cout << "\t\t\t*             4.成绩信息修改                 *\t\t\t\n";
	cout << "\t\t\t*             5.培养计划信息修改             *\t\t\t\n";
	cout << "\t\t\t*             6.返回上一级                   *\t\t\t\n";
	cout << "\t\t\t==============================================\t\t\t\n";
}

//数据查询功能选择界面
void Menu::cxMenu() {
	system("cls");
	cout << "\t\t\t==============================================\t\t\t\n";
	cout << "\t\t\t*            1.学生信息查询                  *\t\t\t\n";
	cout << "\t\t\t*            2.学籍信息查询                  *\t\t\t\n";
	cout << "\t\t\t*            3.院系信息查询                  *\t\t\t\n";
	cout << "\t\t\t*            4.成绩信息查询                  *\t\t\t\n";
	cout << "\t\t\t*            5.培养计划信息查询              *\t\t\t\n";
	cout << "\t\t\t*            6.返回上一级                    *\t\t\t\n";
	cout << "\t\t\t==============================================\t\t\t\n";
}

//数据分析功能选择界面
void Menu::AnaMenu() {
	system("cls");
	cout << "\t\t\t==============================================\t\t\t\n";
	cout << "\t\t\t*            1.学生信息分析                  *\t\t\t\n";
	cout << "\t\t\t*            2.学籍信息分析                  *\t\t\t\n";
	cout << "\t\t\t*            3.成绩信息分析                  *\t\t\t\n";
	cout << "\t\t\t*            4.返回上一级                    *\t\t\t\n";
	cout << "\t\t\t==============================================\t\t\t\n";
}

//退出程序
void Menu::OutMenu() {
	cout << "\t\t\t------------感谢您的使用，谢谢！------------\t\t\t\n";
	exit(0);
}





