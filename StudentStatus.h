#pragma once
#include<iostream>
#include<string>
using namespace std;
class StudentStatus
{
public:
    StudentStatus() {
		StuID = "null";
		Name = "null";
		Academy = "null";
		Major = "null";
		SchoolClass = "null";
		Address = "null";
		Gender = "null";
		PhoneNum = "null";
		Home = "null";;
		PostCode = "null";
		BirthPlace = "null";
		Num = 0;
    }

    StudentStatus(string stuID, string name, string academy, string major, string schoolClass, string address, string gender, string phoneNum, string home, string postCode, string birthPlace) {
        StuID = stuID;
        Name = name;
        Academy = academy;
        Major = major;
        SchoolClass = schoolClass;
        Address = address;
        Gender = gender;
        PhoneNum = phoneNum;
        Home = home;
        PostCode = postCode;
        BirthPlace = birthPlace;
        Num = 0;
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

    string getGender() {
        return Gender;
    }

    void setGender(string gender) {
        Gender = gender;
    }

    string getPhoneNum() {
        return PhoneNum;
    }

    void setPhoneNum(string phoneNum) {
        PhoneNum = phoneNum;
    }

    string getHome() {
        return Home;
    }

    void setHome(string home) {
        Home = home;
    }

    string getPostCode() {
        return PostCode;
    }

    void setPostCode(string postCode) {
        PostCode = postCode;
    }

    string getBirthPlace() {
        return BirthPlace;
    }

    void setBirthPlace(string birthPlace) {
        BirthPlace = birthPlace;
    }

    int getNum() {
        return Num;
    }

    void setNum(int n) {
        Num = n;
    }

    string showLine() {
        //string stuID, string name, string academy, string major, string schoolClass, string address, string gender, string phoneNum, string home, string postCode, string birthPlace
        return ("ѧ�ţ�" + StuID + ", ������" + Name + ", ѧԺ��" + Academy + ", רҵ��" + Major + ", �༶��" + SchoolClass + ", ��סַ��" + Address + ", �Ա�" + Gender + ", �ֻ����룺" + PhoneNum + ", ��ͥסַ��" + Home + ", �������룺" + PostCode + ", ���᣺" + BirthPlace + "\n");
    }

private:
	string StuID;
	string Name;
	string Academy;
	string Major;
	string SchoolClass;
	string Address;
	string Gender;
	string PhoneNum;
	string Home;
	string PostCode;
	string BirthPlace;
    int Num;//���ڼ����������ռ��
};

