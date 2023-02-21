#include "headers/main.hpp"
#include "headers/student.hpp"
#include "headers/course.hpp"
#include "headers/file_Storage.hpp"

/**
 * readline_gets - reads a line from the console
 *
 * Return: On success, it returns a pointer to the string
 * read from the console.
*/
char *readline_gets(void)
{
    char *line_read = NULL;

    line_read = readline ("$ ");
    if (line_read && *line_read)
        add_history (line_read);
    return (line_read);
}

/**
 *
*/
int get_function(char *input)
{
    string str(input);
    std::vector<std::string> splittedStr;

    if (str.compare("") == 0)
        return 0;

    splittedStr = splitString(str, ' ');
    if (splittedStr[0].compare("exit") == 0)
    {
        storage.save_students();
        storage.save_courses();
        return -1;
    }

    if (splittedStr[0].compare("create") == 0)
    {
        if (splittedStr.size() == 1)
        {
            std::printf("Usage: create <class name> <attributes>\n");
            return 1;
        } else if (splittedStr[1].compare("Student") == 0)
            create_student(splittedStr);
        else if (splittedStr[1].compare("Course") == 0)
            create_course(splittedStr);
    } else if (splittedStr[0].compare("clear") == 0)
        std::system("clear");
    else if (splittedStr[0].compare("all") == 0)
    {
        if (splittedStr.size() == 1)
        {
            std::printf("Usage: all <class name>\n");
            return 1;
        }
        if (splittedStr[1].compare("Student") == 0)
        {
            if (splittedStr.size() == 3)
            {
                if (splittedStr[2].compare("byName") == 0)
                    storage.students.sort_by_name();
                else
                {
                    std::printf("Improper Syntax. Usage: all Student byName");
                    return 1;
                }
            }
            storage.students.print_list();
        } else if (splittedStr[1].compare("Course") == 0)
            storage.courses.print_list();
        else
        {
            std::cout << "Error: class '" << splittedStr[1] << "' not found\n";
            return 1;
        }
    } else if (splittedStr[0].compare("delete") == 0)
    {
        if (splittedStr.size() == 1)
        {
            std::printf("Usage: delete <class name> <parameter>\n");
            return 1;
        }

        if (splittedStr[1].compare("Student") == 0)
        {
            if (splittedStr.size() == 2)
            {
                std::printf("Usage: delete Student <student id>\n");
                return 1;
            }
            storage.deleteStudent(splittedStr[2]);
        } else if (splittedStr[1].compare("Course") == 0)
        {
            if (splittedStr.size() == 2)
            {
                std::printf("Usage: delete Course <course number>\n");
                return 1;
            }
            storage.deleteCourse(std::stoi(splittedStr[2]));
        }
    } else if (splittedStr[0].compare("search") == 0)
    {
        if (splittedStr.size() == 1)
        {
            std::printf("Usage: search <class name> <parameter>\n");
            return 1;
        }

        if (splittedStr[1].compare("Student") == 0)
        {
            if (splittedStr.size() == 2)
            {
                std::printf("Usage: searcg Student <student id>\n");
                return 1;
            }
            storage.students.search_by_id(splittedStr[2]);
        } else if (splittedStr[1].compare("Course") == 0)
        {
            if (splittedStr.size() == 2)
            {
                std::printf("Usage: search Course <course number>\n");
                return 1;
            }
            storage.courses.search_by_cNo(std::stoi(splittedStr[2]));
        }
    }
    return 0;
}

std::vector<std::string> splitString(std::string str, char splitter)
{
    std::vector<std::string> result;
    std::string current = "";
    for(int i = 0; i < str.size(); i++){
        if(str[i] == splitter){
            if(current != ""){
                result.push_back(current);
                current = "";
            }
            continue;
        }
        current += str[i];
    }
    if(current.size() != 0)
        result.push_back(current);
    return result;
}
