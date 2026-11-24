#include <iostream>
#include "CourseList.h"

void CourseList::addCourse(const Course& course)
{
    courses.insert(course); 
}

void CourseList::printCourses() const
{
    std::cout << "Courses in student records:" << std::endl;

    for (const Course& c : courses)
    {
        std::cout << c.getCoursePrefix() << " " << c.getCourseNumber() << std::endl;
    }
}