#ifndef FILE_STORAGE_HPP
#define FILE_STORAGE_HPP

#include "main.hpp"
#include "student.hpp"
#include "linked_list.hpp"

class FileStorage {
public:
    LinkedListStudent students;
};

extern FileStorage storage;

#endif /* FILE_STORAGE_HPP */
