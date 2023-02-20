#include "headers/main.hpp"
#include "headers/student.hpp"
#include "headers/linked_list.hpp"
#include "headers/file_Storage.hpp"


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

void reload_students()
{
    std::ifstream student_file;
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
}
