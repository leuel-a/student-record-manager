#include "headers/main.hpp"
#include "headers/student.hpp"
#include "headers/linked_list.hpp"
#include "headers/file_Storage.hpp"
#include "headers/linked_list_course.hpp"


void FileStorage::save_students()
{
    std::ofstream student_file;
    NodeStudent *aux = storage.students.head;

    student_file.open("student.txt", std::ios::trunc);
    while (aux != NULL)
    {
        student_file << aux->s.str_rep() << std::endl;
        aux = aux->nextNode;
    }
}

void reload()
{
    std::ifstream student_file, course_file, student_course_file;
    string line;

    student_file.open("student.txt");
    if (student_file.is_open())
    {
        while (std::getline(student_file, line))
        {
            Student newStu;
            std::vector<std::string> splittedString = splitString(line, ' ');
            newStu.init(splittedString[0], splittedString[1],splittedString[2], std::stoi(splittedString[3]), splittedString[4]);
            storage.students.add_athead(newStu);
        }
    }
    student_file.close();

    course_file.open("course.txt");
    if (course_file.is_open())
    {
        while (std::getline(course_file, line))
        {
            Course newCourse;
            std::vector<std::string> splittedString = splitString(line, ' ');
            newCourse.init(std::stoi(splittedString[0]), splittedString[1]);
            storage.courses.add_athead(newCourse);
        }
    }
    course_file.close();

    student_course_file.open("student_course.txt");
    if (student_course_file.is_open())
    {
        while (std::getline(student_course_file, line))
        {
            StudentCourse stuCourse;
            std::vector<std::string> splittedStr = splitString(line, ' ');
            stuCourse.init(std::stoi(splittedStr[0]), splittedStr[2], splittedStr[3], splittedStr[1]);
            add_grade(&stuCourse, splittedStr[4]);
            storage.studentCourses.add_athead(stuCourse);
        }
    }
    student_course_file.close();
}

void FileStorage::save_courses()
{
    std::ofstream course_file;
    NodeCourse *aux = storage.courses.head;

    course_file.open("course.txt", std::ios::trunc);
    while (aux != NULL)
    {
        course_file << aux->c.str_rep() << std::endl;
        aux = aux->nextNode;
    }
}

void FileStorage::deleteStudent(std::string student_id)
{
    NodeStudent *prev, *curr, *temp;
    int found = 0;

    prev = NULL, curr = storage.students.head;
    while (curr != NULL)
    {
        if (curr->s.student_id.compare(student_id) == 0)
        {
            found = 1;
            break;
        }
        prev = curr, curr = curr->nextNode;
    }
    if (found == 0)
    {
        std::cout << "Error: no student found with id '" << student_id << "'\n";
        return;
    }

    temp = curr->nextNode;
    delete curr;
    if (prev == NULL)
        storage.students.head = temp;
    else
        prev->nextNode = temp;
}

void FileStorage::deleteCourse(int cNo)
{
    NodeCourse *prev, *curr, *temp;
    int found = 0;

    prev = NULL, curr = storage.courses.head;
    while (curr != NULL)
    {
        if (curr->c.courseNo == cNo)
        {
            found = 1;
            break;
        }
        prev = curr, curr = curr->nextNode;
    }
    if (found == 0)
    {
        std::cout << "Error: no course found with courseNo '" << cNo << "'\n";
        return;
    }

    temp = curr->nextNode;
    delete curr;
    if (prev == NULL)
        storage.courses.head = temp;
    else
        prev->nextNode = temp;
}

void FileStorage::save_student_courses()
{
    std::ofstream course_file;
    NodeStuCourse *aux = storage.studentCourses.head;

    course_file.open("student_course.txt", std::ios::trunc);
    while (aux != NULL)
    {
        course_file << aux->stuCourse.str_rep() << std::endl;
        aux = aux->nextNode;
    }
}
