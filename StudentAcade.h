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
        return ("学号：" + StuID + ", 姓名：" + Name + ", 学院：" + Academy + ", 专业：" + Major + ", 班级：" + SchoolClass + ", 现住址：" + Address + ", 手机号码：" + PhoneNum + ", 籍贯：" + BirthPlace + ", 入学时间：" + IntakeTime + "\n");
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

