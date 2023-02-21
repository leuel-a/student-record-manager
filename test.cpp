#include "headers/course.hpp"
#include "headers/linked_list_course.hpp"


int main(void)
{
    LinkedListCourse head;
    Course c;

    c.init(224, "Data Structure");
    head.add_athead(c);

    c.init(215, "Discrete Mathematic");
    head.add_athead(c);

    c.init(156, "Object Oriented Programming");
    head.add_athead(c);

    head.print_list();

    std::putchar('\n');
    head.search_by_cNo(215);
    return 0;
}
