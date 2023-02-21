#include "headers/linked_list.hpp"

LinkedListStudent::LinkedListStudent()
{
    this->head = NULL;
}

void LinkedListStudent::add_athead(Student student)
{
    NodeStudent *newNode = new (std::nothrow) NodeStudent();

    if (newNode == NULL)
    {
        std::printf("Error: cannot allocate anymore\n");
        exit(EXIT_FAILURE);
    }
    newNode->s = student;
    newNode->nextNode = this->head;
    this->head = newNode;
}

void LinkedListStudent::print_list()
{
    NodeStudent *aux;

    if (this->head == NULL)
        return;
    aux = this->head;
    while (aux != NULL)
        std::cout << aux->s.str_rep() << std::endl, aux = aux->nextNode;
}

void LinkedListStudent::free_list()
{
    NodeStudent *temp;

    while (this->head != NULL)
    {
        temp = this->head->nextNode;
        delete this->head;
        this->head = temp;
    }
    this->head = NULL;
}

void LinkedListStudent::sort_by_name()
{
    this->sortedByName = NULL;
    NodeStudent* current = this->head;

    while (current != NULL) {
        NodeStudent* next = current->nextNode;
        sortedInsert(current);
        current = next;
    }
    this->head = sortedByName;
}

void LinkedListStudent::sortedInsert(NodeStudent* newnode)
{
    if (this->sortedByName == NULL || sortedByName->s.first_name.compare(newnode->s.first_name) >= 0) {
        newnode->nextNode = this->sortedByName;
        this->sortedByName = newnode;
    }
    else {
        NodeStudent* current = this->sortedByName;
        while (current->nextNode != NULL
                && current->nextNode->s.first_name.compare(newnode->s.first_name) < 0) {
            current = current->nextNode;
        }
        newnode->nextNode = current->nextNode;
        current->nextNode = newnode;
    }
}

Student* LinkedListStudent::search_by_id(string student_id)
{
    NodeStudent *aux;
    int found = 0;

    if (this->head == NULL)
    {
        std::printf("There are no students currently registered\n");
        return NULL;
    }
    aux = this->head;
    while (aux != NULL)
    {
        if (aux->s.student_id.compare(student_id) == 0)
        {
            std::cout << aux->s.str_rep() << std::endl;
            found = 1;
            return &aux->s;
        }
        aux = aux->nextNode;
    }
    if (found == 0)
        std::cout << "Error: no student can be found with student id '" << student_id << "'\n";
    return NULL;
}

