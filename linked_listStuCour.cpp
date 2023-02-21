#include "headers/file_Storage.hpp"
#include "headers/linked_listStuCour.hpp"

LinkedListStuCourse::LinkedListStuCourse() {
    this->head = NULL;
}

void LinkedListStuCourse::add_athead(StudentCourse stuCourse)
{
    NodeStuCourse *newNode = new (std::nothrow) NodeStuCourse();

    if (newNode == NULL)
    {
        std::printf("Error: cannot allocate anymore\n");
        exit(EXIT_FAILURE);
    }
    newNode->stuCourse = stuCourse;
    newNode->nextNode = this->head;
    this->head = newNode;
}

void LinkedListStuCourse::print_list()
{
    NodeStuCourse *aux;

    if (this->head == NULL)
        return;
    aux = this->head;
    while (aux != NULL)
        std::cout << aux->stuCourse.str_rep() << std::endl, aux = aux->nextNode;
}

StudentCourse* LinkedListStuCourse::search_student_by_course(string studentId, int cNo)
{
    NodeStuCourse* aux = storage.studentCourses.head;

    while (aux != NULL)
    {
        if (aux->stuCourse.studentID.compare(studentId) == 0)
        {
            if (aux->stuCourse.courseNo == cNo)
                return &aux->stuCourse;
        }
    }
    return NULL;
}
