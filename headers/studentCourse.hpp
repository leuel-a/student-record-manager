#ifndef STUDENT_COURSE_HPP
#define STUDENT_COURSE_HPP

#include <string>

#include "main.hpp"

using std::string;

class StudentCourse {
public:
    int courseNo;
    string studentID;
    string studentName;
    string courseTitle;
    string grade;

    StudentCourse();
    void init(int cNo, string stuID, string stuName, string cTitle);
    string str_rep();
};

void add_grade(StudentCourse *stuC, string grade);

#endif /* STUDENT_COURSE_HPP */
