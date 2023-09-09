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
       cout <<"学号：" << StuID << ", 课程编号：" << CourseID << ", 课程名称：" << CourseName << ", 学分：" << credit << ", 平时成绩：" << DailyGrade << ", 期末成绩：" << FinalGrade << ", 总评：" << TotalGrade << ", 学期：" << SchoolTerm << ", 绩点：" << GradePoint << endl;
   }

   string showLine() {
       //"学号：" + StuID + ", 课程编号：" + CourseID + ", 课程名称：" + CourseName + ", 学分：" + credit + ", 平时成绩：" + DailyGrade + ", 期末成绩：" + FinalGrade + ", 总评：" + TotalGrade + ", 学期：" + SchoolTerm + ", 绩点：" + GradePoint);
       string cre = to_string(credit);
       string DG = to_string(DailyGrade);
       string FG = to_string(FinalGrade);
       string tot = to_string(TotalGrade);
       string term = to_string(SchoolTerm);
       string jidian = to_string(GradePoint);
       return ("学号：" + StuID + ", 课程编号：" + CourseID + ", 课程名称：" + CourseName + ", 学分：" + cre + ", 平时成绩：" + DG + ", 期末成绩：" + FG + ", 总评：" + tot + ", 学期：" + term + ", 绩点：" + jidian + "\n");
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
    double AllGradePoint;//用于计算全部科目加起来的总绩点（计算非存储）
    int PassNum, FailNum;//用于计算及格与不及格的人数（计算非存储）
    double PassRate;//用于计算及格率
};

