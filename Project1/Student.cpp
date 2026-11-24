#include <iostream>
#include "Student.h"

void Student::setStudent(const Student& otherStudent)
{
    studentID = otherStudent.studentID;
    firstName = otherStudent.firstName;
    lastName = otherStudent.lastName;
    numberOfCourses = otherStudent.numberOfCourses;
    tuitionWasPaid = otherStudent.tuitionWasPaid;
    coursesCompleted = otherStudent.coursesCompleted;
}

int Student::getID() const
{
    return studentID;
}

std::string Student::getFirstName() const
{
    return firstName;
}

std::string Student::getLastName() const
{
    return lastName;
}

void Student::getName(std::string& first, std::string& last) const
{
    first = firstName;
    last = lastName;
}

int Student::getNumberOfCourses() const
{
    return numberOfCourses;
}

int Student::getUnitsCompleted() const
{
    int totalUnits = 0;

    for (const auto& entry : coursesCompleted)
    {
        totalUnits += entry.first.getCourseUnits();
    }

    return totalUnits;
}

std::multimap<Course, char> Student::getCoursesCompleted() const
{
    return coursesCompleted;
}

bool Student::isTuitionPaid() const
{
    return tuitionWasPaid;
}

bool Student::isCourseCompleted(const std::string& coursePrefix, int courseNumber) const
{
    if (coursesCompleted.empty())
    {
        return false;
    }
    else
    {
        for (const auto& entry : coursesCompleted)
        {
            if (entry.first.getCoursePrefix() == coursePrefix &&
                entry.first.getCourseNumber() == courseNumber)
            {
                return true;
            }
        }
        return false;
    }
}

double Student::calculateGPA() const
{
    int totalUnits = getUnitsCompleted();

    if (totalUnits == 0)
    {
        return 0.0;
    }

    double totalPoints = 0.0;

    for (const auto& entry : coursesCompleted)
    {
        int gradePoints = 0;

        switch (entry.second)
        {
        case 'A': gradePoints = 4; break;
        case 'B': gradePoints = 3; break;
        case 'C': gradePoints = 2; break;
        case 'D': gradePoints = 1; break;
        case 'F': gradePoints = 0; break;
        }

        totalPoints += entry.first.getCourseUnits() * gradePoints;
    }

    return totalPoints / totalUnits;
}

double Student::billingAmount(double tuitionRate) const
{
    return numberOfCourses * tuitionRate;
}

void Student::printStudent() const
{
    std::cout << "ID: " << studentID << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "First name: " << firstName << std::endl;
}

void Student::printStudentInfo(double tuitionRate) const
{
    std::cout << "Student: " << getLastName() << ", " << getFirstName() << std::endl;
    std::cout << "Student ID: " << getID() << std::endl;
    std::cout << "Number of courses: " << getNumberOfCourses() << std::endl;

    for (const auto& entry : coursesCompleted)
    {
        std::cout << entry.first.getCoursePrefix() << " "
            << entry.first.getCourseNumber() << "  "
            << entry.first.getCourseUnits() << " units  ";

        if (isTuitionPaid())
        {
            std::cout << "Grade: " << entry.second;
        }
        else
        {
            std::cout << "Grade: ***";
        }
        std::cout << std::endl;
    }

    std::cout << "Total units: " << getUnitsCompleted() << std::endl;

    if (isTuitionPaid())
    {
        std::cout << "GPA: " << calculateGPA() << std::endl;
    }
    else
    {
        std::cout << "Grades are being held because tuition was not paid." << std::endl;
        std::cout << "Amount due: $" << billingAmount(tuitionRate) << std::endl;
    }
}