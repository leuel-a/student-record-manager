#include "headers/main.hpp"
#include "headers/student.hpp"
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
        return -1;

    if (splittedStr[0].compare("create") == 0)
    {
        if (splittedStr.size() == 1)
        {
            std::printf("Usage: create <class name> <attributes>\n");
            return 1;
        } else if (splittedStr[1].compare("Student") == 0)
            create_student(splittedStr);
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
            storage.students.print_list();
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
