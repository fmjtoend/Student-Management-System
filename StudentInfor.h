#pragma once
#include<iostream>
#include<string>
using namespace std;
class StudentInfor
{
public:
	StudentInfor() {
		this->NumID = "null";
		this->StuID = "null";
		this->Name = "null";
		this->Gender = "null";
		this->BirthDay = "null";
		Age = 0;
		Num = 0;
	}
	StudentInfor(string NumID, string StuID, string Name, string Gender, string BirthDay){
		this->NumID = NumID;
		this->StuID = StuID;
		this->Name = Name;
		this->Gender = Gender;
		this->BirthDay = BirthDay;
		Age = 0;
		Num = 0;
	}
	void setNumID(string NumID) {
		this->NumID = NumID;
	}
	void setStuID(string StuID) {
		this->StuID = StuID;
	}
	void setName(string Name) {
		this->Name = Name;
	}
	void setGender(string Gender) {
		this->Gender = Gender;
	}
	void setBirthDay(string BirthDay) {
		this->BirthDay = BirthDay;
	}
	string getNumID() {
		return NumID;
	}
	string getStuID() {
		return StuID;
	}
	string getName() {
		return Name;
	}
	string getGender() {
		return Gender;
	}
	string getBirthDay() {
		return BirthDay;
	}

	int getAge() {
		return Age;
	}

	void setAge(int age) {
		Age = age;
	}

	int getNum() {
		return Num;
	}

	void setNum(int num) {
		Num = num;
	}

	string showLine() {
		return ("���֤��" + NumID + ", ѧ�ţ�" + StuID + ", ������" + Name + ", �Ա�" + Gender + ", �������ڣ�" + BirthDay + "\n");
	}

private:
	string NumID;
	string StuID;
	string Name;
	string Gender;
	string BirthDay;
	int Age;//���ڼ����������
	int Num;//���ڼ������
};

