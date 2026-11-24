#ifndef CourseList_H
#define CourseList_H

#include <set>
#include "Course.h"

class CourseList
{
private:
	std::set<Course>  courses;
public:
	void addCourse(const Course& course);
	void printCourses() const;

};

#endif 