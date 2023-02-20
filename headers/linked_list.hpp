#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "student.hpp"

class NodeStudent {
public:
    Student s;
    NodeStudent *nextNode;
};

class LinkedListStudent {
public:
    NodeStudent *head;
    NodeStudent *sortedByName;

    LinkedListStudent();
    void add_athead(Student s);
    void free_list();
    void print_list();
    void sort_by_name();
    void sortedInsert(NodeStudent* newnode);
    void search_by_id(string student_id);
};

#endif /* LINKED_LIST_HPP */
