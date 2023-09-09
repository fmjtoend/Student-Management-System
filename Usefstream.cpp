//#ifdef USEFSTREAM_H
//#define USEFSTREAM_H
//#endif // USEFSTREAM_H

#include "Usefstream.h"
#include"StudentScore.h"
#include"vectors.h"
#include<iostream>
#include<fstream>
using namespace std;

void Usefstream::addToFile(vectors* v, int choice) {
	ofstream ofs;
	switch (choice) {
	case 1:
		ofs.open("StuInforTXT.txt", ios::out);
		break;
	case 2:
		ofs.open("StuStatusTXT.txt", ios::out);
		break;
	case 3:
		ofs.open("StuAcadeTXT.txt", ios::out);
		break;
	case 4:
		ofs.open("StuScoreTXT.txt", ios::out); 
		break;
	case 5:
		ofs.open("StuDevelopTXT.txt", ios::out);
		break;
	default:
		break;
	}
	if (!ofs.is_open()) {
		cout << "文件打开失败！\n";
		return;
	}
	ofs.clear();
	switch (choice) {
	case 1:
		for (int i = 0; i < (v->stuinfor.size()); i++) {
			ofs << v->stuinfor[i]->showLine();
		}
		break;
	case 2:
		for (int i = 0; i < (v->stustatus.size()); i++) {
			ofs<<v->stustatus[i]->showLine();
		}
		break;
	case 3:
		for (int i = 0; i < (v->stuacade.size()); i++) {
			ofs << v->stuacade[i]->showLine();
		}
		break;
	case 4:
		for (int i = 0; i < (v->stuscores.size()); i++) {
			ofs << v->stuscores[i]->showLine();
		}
		break;
	case 5:
		for (int i = 0; i < (v->studevelop.size()); i++) {
			ofs<<v->studevelop[i]->showLine();
		}
		break;
	default:
		break;
	}
	ofs.close();
}

void Usefstream::readFile(vectors* v, int choice) {
	ifstream ifs;
	switch (choice) {
	case 1:
		ifs.open("StuInforTXT.txt", ios::in);
		break;
	case 2:
		ifs.open("StuStatusTXT.txt", ios::in);
		break;
	case 3:
		ifs.open("StuAcadeTXT.txt", ios::in);
		break;
	case 4:
		ifs.open("StuScoreTXT.txt", ios::in);
		break;
	case 5:
		ifs.open("StuDevelopTXT.txt", ios::in);
		break;
	default:
		break;
	}
	
	if (!ifs.is_open()) {
		cout << "文件打开失败！\n";
		return;
	}
	string buf;
	while (getline(ifs, buf)) {
		cout << buf << endl;
	}
	ifs.close();
	system("pause");

}

bool Usefstream::operator==(const Usefstream& other) const
{
	return false;
}

