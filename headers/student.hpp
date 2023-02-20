#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <string.h>
#include <iostream>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

using std::string;

class Student {
public:
    string student_id;
    string first_name;
    string father_name;
    string sex;
    int age;

    Student();
    void init(string student_id, string first_name, string father_name, int age, string sex);
    void display(void);
    string str_rep();
};

void create_student(std::vector<string> splittedStr);
char *my_strdup(const char *str);

#endif /* STUDENT_HPP */
