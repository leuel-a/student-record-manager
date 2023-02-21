#ifndef FILE_STORAGE_HPP
#define FILE_STORAGE_HPP

#include "main.hpp"
#include "student.hpp"
#include "linked_list.hpp"
#include "linked_listStuCour.hpp"
#include "linked_list_course.hpp"

#include <fstream>

class FileStorage {
public:
    LinkedListStudent students;
    LinkedListCourse courses;
    LinkedListStuCourse studentCourses;

    void save_students();
    void save_courses();
    void save_student_courses();
    void deleteStudent(std::string student_id);
    void deleteCourse(int cNo);
};

extern FileStorage storage;
void reload();

#endif /* FILE_STORAGE_HPP */
