#include "headers/course.hpp"
#include "headers/file_Storage.hpp"

Course::Course() {}

void Course::init(int cNo, std::string cTitle)
{
    this->courseNo = cNo;
    this->courseTitle = cTitle;
}

std::string Course::str_rep()
{
    std::string course_str = "";

    course_str = std::to_string(this->courseNo) + " " + this->courseTitle;
    return course_str;
}

void create_course(std::vector<string> splittedStr)
{
    Course newCourse;

    if (splittedStr.size() != 4)
    {
        std::printf("Usage: create Course <course number> <course title>\n");
        return;
    }
    newCourse.init(std::stoi(splittedStr[2]), splittedStr[3]);
    std::cout << newCourse.str_rep() << std::endl;
    storage.courses.add_athead(newCourse);
}
