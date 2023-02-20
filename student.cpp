#include "headers/main.hpp"
#include "headers/student.hpp"
#include "headers/file_Storage.hpp"

/**
 * Student - default constructor for student
 *
 * Return: Always nothing
*/
Student::Student () {}

/**
 * init - initializer for Student object
 * @student_id: id of the student
 * @first_name: first name of the student
 * @father_name: father name of the student
 * @age: age of the student
 * @sex: sex of the student
 *
 * Return: Always nothing
*/
void Student::init(string student_id, string first_name, string father_name, int age, string sex)
{
    this->student_id = student_id;
    this->first_name = first_name;
    this->father_name = father_name;
    this->age = age;
    this->sex = sex;
}

void Student::display(void) {
    std::cout << student_id << "\t" << first_name << "\t" << father_name << "\t" << age << "\t" << sex << std::endl;
}

void create_student(std::vector<string> splittedStr)
{
    Student newStu;

    if (splittedStr.size() != 7)
    {
        std::printf("Usage: create Student <student id> <first name> <father name> <age> <sex>\n");
        return;
    }
    newStu.init(splittedStr[2], splittedStr[3], splittedStr[4], std::stoi(splittedStr[5]), splittedStr[6]);
    std::cout << newStu.str_rep() << std::endl;
    storage.students.add_athead(newStu);
}

string Student::str_rep()
{
    string student_str = "";

    student_str = this->student_id + " " + this->first_name + " " + this->father_name + " " + std::to_string(this->age) + " " + this->sex;
    return student_str;
}

char *my_strdup(const char *str) {
    size_t len = strlen(str);
    char *x = (char *)malloc(len + 1);
    if(!x)
        return NULL;
    memcpy(x, str, len + 1);
    return x;
}
