#include "headers/linked_list_course.hpp"

LinkedListCourse::LinkedListCourse()
{
    this->head = NULL;
}

void LinkedListCourse::add_athead(Course course)
{
    NodeCourse *newNode = new (std::nothrow) NodeCourse();

    if (newNode == NULL)
    {
        std::printf("Error: cannot allocate anymore\n");
        exit(EXIT_FAILURE);
    }
    newNode->c = course;
    newNode->nextNode = this->head;
    this->head = newNode;
}

void LinkedListCourse::print_list()
{
    NodeCourse *aux;

    if (this->head == NULL)
        return;
    aux = this->head;
    while (aux != NULL)
        std::cout << aux->c.str_rep() << std::endl, aux = aux->nextNode;
}

Course* LinkedListCourse::search_by_cNo(int cNo)
{
    NodeCourse *aux;
    int found = 0;

    if (this->head == NULL)
    {
        std::printf("There are no courses currently registered\n");
        return NULL;
    }
    aux = this->head;
    while (aux != NULL)
    {
        if (aux->c.courseNo == cNo)
        {
            std::cout << aux->c.str_rep() << std::endl;
            found = 1;
            return &aux->c;
        }
        aux = aux->nextNode;
    }
    if (found == 0)
        std::printf("Error: no course can be found with course number '%d'\n", cNo);
    return NULL;
}
