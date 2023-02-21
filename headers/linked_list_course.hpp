#ifndef LINKED_COURSE
#define LINKED_COURSE

#include "course.hpp"

class NodeCourse {
public:
    Course c;
    NodeCourse *nextNode;
};

class LinkedListCourse {
public:
    NodeCourse *head;

    LinkedListCourse();
    void add_athead(Course c);
    void print_list();
    Course* search_by_cNo(int cNo);
};

#endif /* LINKED_COURSE */
