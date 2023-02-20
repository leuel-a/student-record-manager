#ifndef FILE_STORAGE_HPP
#define FILE_STORAGE_HPP

#include "main.hpp"
#include "student.hpp"
#include "linked_list.hpp"

#include <fstream>

class FileStorage {
public:
    LinkedListStudent students;

    void save_students();
};

extern FileStorage storage;
void reload_students();

#endif /* FILE_STORAGE_HPP */
