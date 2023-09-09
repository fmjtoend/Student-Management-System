#pragma once
#include<iostream>
#include<string>
using namespace std;
class StudentAcade
{
public:
    StudentAcade() {
    StuID = "null";
	Name = "null";
	Academy = "null";
	Major = "null";
	SchoolClass = "null";
	Address = "null";
	PhoneNum = "null";
	BirthPlace = "null";
	IntakeTime = "null";
    }

    StudentAcade(string stuID, string name, string academy, string major, string schoolClass, string address, string phoneNum, string birthPlace, string intakeTime) {
        StuID = stuID;
        Name = name;
        Academy = academy;
        Major = major;
        SchoolClass = schoolClass;
        Address = address;
        PhoneNum = phoneNum;
        BirthPlace = birthPlace;
        IntakeTime = intakeTime;
    }

    string getStuID() {
        return StuID;
    }

    void setStuID(string stuID) {
        StuID = stuID;
    }

    string getName() {
        return Name;
    }

    void setName(string name) {
        Name = name;
    }

    string getAcademy() {
        return Academy;
    }

    void setAcademy(string academy) {
        Academy = academy;
    }

    string getMajor() {
        return Major;
    }

    void setMajor(string major) {
        Major = major;
    }

    string getSchoolClass() {
        return SchoolClass;
    }

    void setSchoolClass(string schoolClass) {
        SchoolClass = schoolClass;
    }

    string getAddress() {
        return Address;
    }

    void setAddress(string address) {
        Address = address;
    }

    string getPhoneNum() {
        return PhoneNum;
    }

    void setPhoneNum(string phoneNum) {
        PhoneNum = phoneNum;
    }

    string getBirthPlace() {
        return BirthPlace;
    }

    void setBirthPlace(string birthPlace) {
        BirthPlace = birthPlace;
    }

    string getIntakeTime() {
        return IntakeTime;
    }

    void setIntakeTime(string intakeTime) {
        IntakeTime = intakeTime;
    }

    //string stuID, string name, string academy, string major, string schoolClass, string address, string phoneNum, string birthPlace, string intakeTime
    string showLine() {
        return ("ѧ�ţ�" + StuID + ", ������" + Name + ", ѧԺ��" + Academy + ", רҵ��" + Major + ", �༶��" + SchoolClass + ", ��סַ��" + Address + ", �ֻ����룺" + PhoneNum + ", ���᣺" + BirthPlace + ", ��ѧʱ�䣺" + IntakeTime + "\n");
    }

private:
	string StuID;
	string Name;
	string Academy;
	string Major;
	string SchoolClass;
	string Address;
	string PhoneNum;
	string BirthPlace;
	string IntakeTime;

};

