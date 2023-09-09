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
		cout << "请输入您要录入的数据个数：\n";
		cin >> num;
		cout << "请依次输入学号、课程编号、课程名称、学分、平时成绩、期末成绩、学期 \n";
		for (int i = 0; i < num; i++) {
			string stuid, keid, kename;
			double xuefen, pingshi, qimo;
			int xueqi;
			cin >> stuid >> keid >> kename >> xuefen >> pingshi >> qimo >> xueqi;

			//string StuID, string CourseID, string CourseName, double credit, double DailyGrade, double FinalGrade,int SchoolTerm
			StudentScore* temp = new StudentScore(stuid, keid, kename, xuefen, pingshi, qimo, xueqi);
			v->stuscores.push_back(temp);
		}
		cout << "是否继续输入（1 是  0 否？）\n";
		cin >> flag;
	}
	Usefstream usefs;
	usefs.addToFile(v, 4);
}


void UseScore::Alter(vectors* v) {
	Usefstream usefs;
	int flag = 1;
	while (flag == 1) {
		cout << "请输入您要修改的学生学号、课程编码、开课学期\n";
		string num, courseid;
		int term, ret = 0;
		cin >> num >> courseid >> term;
		for (StudentScore* c : v->stuscores) {
			if ((c->getStuID().compare(num) == 0) && (c->getCourseID().compare(courseid) == 0) && (c->getSchoolTerm() == term)) {
				cout << "已找到该学生" << endl;
				cout << "请输入平时成绩、期末成绩\n";
				double dailySc = 0, finalSc = 0;
				cin >> dailySc >> finalSc;
				c->setDailyGrade(dailySc);
				c->setFinalGrade(finalSc);
				c->update();
				ret++;
			}
		}
		if (ret == 0) {
			cout << "未找到该学生，请确认您的信息是否有误\n";
		}
		cout << "是否继续修改（1 是 0 否）？\n";
		cin >> flag;
	}
	usefs.addToFile(v, 4);
}

void UseScore::CX(vectors* v) {
	//v 里面存储着学生信息、籍贯、院系、成绩、培养计划全部信息
	//v->stuscores 里面存储的是全部学生的全部成绩信息
	if (v->stuscores.empty()) {
		cout << "没有任何学生成绩信息，请您先进行录入操作，谢谢！\n";
		return;
	}
	system("cls");
	int flag = 1;
	while (flag == 1) {
		vector<StudentScore*> vt;
		cout << "\n---------------------------------------------------\n";
		cout << "请输入您要查询的学生学号：\n";
		string stuid;
		cin >> stuid;
		//用增强for循环将该学生的全部信息增加到临时变量vt中
		for (StudentScore* s : v->stuscores) {
			if (stuid.compare(s->getStuID()) == 0) {
				vt.push_back(s);
			}
		}
		cout << "学号为：" << stuid << " 的学生各科总评成绩如下：\n";
		for (StudentScore* s : vt) {
			cout << "\t\t" << s->getCourseID() << " -> " << s->getCourseName() << " -> " << s->getTotalGrade() << "\n";
		}
		cout << "---------------------------------------------------\n";
		cout << "\n是否继续查询（1 是 0 否）？\n";
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
		if (s->getTotalGrade() >= 60) { //总成绩低于60分为挂科
			temp.push_back(s);
			num++;
		}
	}
	cout << "及格人数为：" << num << ", 及格率为：" << (num / v->stuscores.size()) << endl;
	cout << "学号分别是：";
	for (StudentScore* s : temp) {
		cout << s->getStuID() << " ";
	}
	cout << endl;
}

void static failStudent(vectors* v) {

	int num = 0;
	vector<StudentScore*> temp;
	for (StudentScore* s : v->stuscores) {
		if (s->getTotalGrade() >= 60) { //总成绩低于60分为挂科
			temp.push_back(s);
			num++;
		}
	}
	cout << "不及格人数为：" << num << ", 及格率为：" << (num / v->stuscores.size()) << endl;
	cout << "学号分别是：";
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
			vt[i]->setAllGradePoint(v->stuscores[i]->getGradePoint());//让第一个的总绩点等于新加上来的
			i++;
		}
		//ret : 如果ret的值与vt.size()相等，说明是一个新的学号，用push_back() 
		//flag : 如果有相同的，那就记录此时vt的下标flag ，然后跳出循环
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
			vt[flag]->setAllGradePoint(t);//相同的等于自己的加上新的绩点
		}
		if (ret == vt.size()) {
			vt.push_back(v->stuscores[i]);//不相同就加进新的容器并且总绩点要等于新加上来的
			vt[vt.size() - 1]->setAllGradePoint(v->stuscores[i]->getGradePoint());
		}
	}
	int i = 1;
	sort(vt.begin(), vt.end(), cmp2);
	cout << "\n\n----------------------------------------\n";
	for (StudentScore* s : vt) {
		cout << "第 " << i << " 名的学生学号为" << s->getStuID() << ", 总绩点为：" << s->getAllGradePoint() << endl;
		i++;
	}
	cout << "----------------------------------------\n";
}

void SubjectPassRate(vectors* v) {
	vector<StudentScore*> vt;//用于存储各科的数据，如课程编号、名称
	//需要一个存储该科及格人数与不及格人数的容器
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
				flag = j;//记录与v->stuscores[i]相同的，在vt的下标
				break;
			}
			else
				ret++;
		}
		if (flag != -1) {//说明这个v[i] 与前面的vt[flag] 的getCourseID()相同，那就加进去
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
		cout << "第 " << i << " 名的课程编号是：" << s->getCourseID() << ", 课程名称是：" << s->getCourseName() << ", 及格率为：" << s->getPassRate() << endl;
		i++;
	}
	cout << "\n----------------------------------\n";
}

void UseScore::Analyse(vectors* v) {
	//分析要改：1.根据绩点由高到低排 2.得到各科及格率及其排名
	system("cls");
	cout << "\t\t\t===========================================================\t\t\t\n";
	cout << "\t\t\t*      1.分析学生总成绩排名（成绩按总评由高到低排序）     *\t\t\t\n";
	cout << "\t\t\t*      2.分析各科的及格率及其排名                         *\t\t\t\n";
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