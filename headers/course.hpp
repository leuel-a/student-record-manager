#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

#include "main.hpp"
class Course {
public:
    int courseNo;
    std::string courseTitle;

    Course();
    void init(int cNo, std::string cTitle);
    std::string str_rep();
};

void create_course(std::vector<std::string> splittedStr);

#endif /* COURSE_HPP */
