#ifndef LIST_STUCOURSE_HPP
#define LIST_STUCOURSE_HPP

#include "studentCourse.hpp"

class NodeStuCourse {
public:
    StudentCourse stuCourse;
    NodeStuCourse *nextNode;
};

class LinkedListStuCourse {
public:
    NodeStuCourse *head;

    LinkedListStuCourse();
    void print_list();
    void add_athead(StudentCourse s);
    StudentCourse* search_student_by_course(string studentID, int cNo);
};

#endif /* LIST_STUCOURSE */
