#pragma once
#include<iostream>
#include<string>

using namespace std;
class StudentScore
{
public:
	StudentScore() {
		this->StuID = "null";
		this->CourseID = "null";
		this->CourseName = "null";
		this->credit = 0;
		this->DailyGrade = 0;
		this->FinalGrade = 0;
		this->TotalGrade = 0;
		this->SchoolTerm = 0;
		this->GradePoint = 0;
        PassNum = 0;
        FailNum = 0;
	}
	StudentScore(string StuID, string CourseID, string CourseName, double credit, double DailyGrade, double FinalGrade,int SchoolTerm) {
		this->StuID = StuID;
		this->CourseID = CourseID;
		this->CourseName = CourseName;
		this->credit = credit;
		this->DailyGrade = DailyGrade;
		this->FinalGrade = FinalGrade;
		this->SchoolTerm = SchoolTerm;
        this->TotalGrade = (DailyGrade + FinalGrade) / 2;
        this->GradePoint = ((TotalGrade - 50) / 10);
        AllGradePoint = 0;
        PassNum = 0;
        FailNum = 0;
	}
    string getStuID() {
        return StuID;
    }

    void setStuID(string stuID) {
        StuID = stuID;
    }

    string getCourseID() {
        return CourseID;
    }

    void setCourseID(string courseID) {
        CourseID = courseID;
    }

    string getCourseName() {
        return CourseName;
    }

    void setCourseName(string courseName) {
        CourseName = courseName;
    }

    double getCredit() {
        return credit;
    }

    void setCredit(double credit) {
        this->credit = credit;
    }

    double getDailyGrade() {
        return DailyGrade;
    }

    void setDailyGrade(double dailyGrade) {
        DailyGrade = dailyGrade;
    }

    double getFinalGrade() {
        return FinalGrade;
    }

    void setFinalGrade(double finalGrade) {
        FinalGrade = finalGrade;
    }

    int getSchoolTerm() {
        return SchoolTerm;
    }

    void setSchoolTerm(int schoolTerm) {
        SchoolTerm = schoolTerm;
    }

    double getGradePoint() {
        return ((TotalGrade - 50) / 10);
    }

   double getTotalGrade() {
       return ((DailyGrade + FinalGrade) / 2);
   }

   double getAllGradePoint() {
       return AllGradePoint;
   }

   void setAllGradePoint(double d) {
       this->AllGradePoint = d;
   }

   int getPassNum() {
       return PassNum;
   }

   void setPassNum(int num) {
       PassNum = num;
   }

   int getFailNum() {
       return FailNum;
   }

   void setFailNum(int num) {
       FailNum = num;
   }

   double getPassRate() {
       double r = (double)PassNum / (PassNum + FailNum);
       return r;
   }

   void update() {
       TotalGrade = (DailyGrade + FinalGrade) / 2;
       GradePoint = (TotalGrade - 50) / 10;
   }

   bool is_Pass() {
       if (TotalGrade >= 60) {
           return true;
       }
       else {
           return false;
       }
   }

   void show() {
       cout <<"ѧ�ţ�" << StuID << ", �γ̱�ţ�" << CourseID << ", �γ����ƣ�" << CourseName << ", ѧ�֣�" << credit << ", ƽʱ�ɼ���" << DailyGrade << ", ��ĩ�ɼ���" << FinalGrade << ", ������" << TotalGrade << ", ѧ�ڣ�" << SchoolTerm << ", ���㣺" << GradePoint << endl;
   }

   string showLine() {
       //"ѧ�ţ�" + StuID + ", �γ̱�ţ�" + CourseID + ", �γ����ƣ�" + CourseName + ", ѧ�֣�" + credit + ", ƽʱ�ɼ���" + DailyGrade + ", ��ĩ�ɼ���" + FinalGrade + ", ������" + TotalGrade + ", ѧ�ڣ�" + SchoolTerm + ", ���㣺" + GradePoint);
       string cre = to_string(credit);
       string DG = to_string(DailyGrade);
       string FG = to_string(FinalGrade);
       string tot = to_string(TotalGrade);
       string term = to_string(SchoolTerm);
       string jidian = to_string(GradePoint);
       return ("ѧ�ţ�" + StuID + ", �γ̱�ţ�" + CourseID + ", �γ����ƣ�" + CourseName + ", ѧ�֣�" + cre + ", ƽʱ�ɼ���" + DG + ", ��ĩ�ɼ���" + FG + ", ������" + tot + ", ѧ�ڣ�" + term + ", ���㣺" + jidian + "\n");
   }


  

private:
	string StuID;
	string CourseID;
	string CourseName;
	double credit;
	double DailyGrade;
	double FinalGrade;
	double TotalGrade;
	int SchoolTerm;
	double GradePoint;
    double AllGradePoint;//���ڼ���ȫ����Ŀ���������ܼ��㣨����Ǵ洢��
    int PassNum, FailNum;//���ڼ��㼰���벻���������������Ǵ洢��
    double PassRate;//���ڼ��㼰����
};

