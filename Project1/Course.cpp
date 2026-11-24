#include "Course.h"

void Course::setCourseInfo(std::string aCoursePrefix, int aCourseNumber, int aCourseUnits)
{
    coursePrefix = aCoursePrefix;
    courseNumber = aCourseNumber;
    courseUnits = aCourseUnits;
}

std::string Course::getCoursePrefix() const
{
    return coursePrefix;
}

int Course::getCourseNumber() const
{
    return courseNumber;
}

int Course::getCourseUnits() const
{
    return courseUnits;
}

bool Course::operator<(const Course& otherCourse) const
{
    if (coursePrefix != otherCourse.coursePrefix)
    {
        return coursePrefix < otherCourse.coursePrefix;
    }
    return courseNumber < otherCourse.courseNumber;
}
