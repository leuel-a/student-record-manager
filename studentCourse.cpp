#include "headers/studentCourse.hpp"

StudentCourse::StudentCourse() {}

void StudentCourse::init(int cNo, string stuID, string stuName, string cTitle)
{
    this->courseNo = cNo;
    this->studentID = stuID;
    this->studentName = stuName;
    this->courseTitle = cTitle;
    this->grade = "Not_Submitted";
}

string StudentCourse::str_rep()
{
    string str_rep = "";

    str_rep = std::to_string(this->courseNo) + " " + this->courseTitle  + " " + this->studentID + " " + this->studentName + " " + this->grade;
    return str_rep;
}

void add_grade(StudentCourse *StudentCourse, string grade)
{
   StudentCourse->grade = grade;
}
