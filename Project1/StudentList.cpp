#include <iostream>
#include "StudentList.h"

void StudentList::addStudent(const Student& student)
{
    Node* newNode = new Node(student, nullptr);

    if (first == nullptr)          // empty list
    {
        first = newNode;
        last = newNode;
    }
    else                           // nonempty list
    {
        last->setNext(newNode);
        last = newNode;
    }

    count++;
}

int StudentList::getNoOfStudents() const
{
    return count;
}

void StudentList::printStudentByID(int id, double tuitionRate) const
{
    Node* current = first;
    bool found = false;

    while (current != nullptr && !found)
    {
        if (current->getStudent().getID() == id)
        {
            current->getStudent().printStudentInfo(tuitionRate);
            found = true;          // stops the search
        }
        else
        {
            current = current->getNext();
        }
    }

    if (!found)
    {
        std::cout << "No student found with ID " << id << std::endl;
    }
}

void StudentList::printStudentByName(const std::string& lastName) const
{
    Node* current = first;
    bool found = false;

    while (current != nullptr)     // do not stop after the first match
    {
        if (current->getStudent().getLastName() == lastName)
        {
            current->getStudent().printStudent();
            found = true;
        }
        current = current->getNext();
    }

    if (!found)
    {
        std::cout << "No student found with last name " << lastName << std::endl;
    }
}

void StudentList::printStudentsByCourse(const std::string& coursePrefix, int courseNumber) const
{
    Node* current = first;
    bool found = false;

    while (current != nullptr)
    {
        if (current->getStudent().isCourseCompleted(coursePrefix, courseNumber))
        {
            current->getStudent().printStudent();
            found = true;
        }
        current = current->getNext();
    }

    if (!found)
    {
        std::cout << "No students found who completed "
            << coursePrefix << " " << courseNumber << std::endl;
    }
}

void StudentList::printAllStudents(double tuitionRate) const
{
    Node* current = first;

    while (current != nullptr)
    {
        current->getStudent().printStudentInfo(tuitionRate);
        std::cout << std::endl;    // blank line between students
        current = current->getNext();
    }
}

void StudentList::clearStudentList()
{
    Node* current = first;

    while (current != nullptr)
    {
        Node* toDelete = current;
        current = current->getNext();   // save next before deleting
        delete toDelete;
    }

    first = nullptr;
    last = nullptr;
    count = 0;
}

StudentList::~StudentList()
{
    if (first != nullptr)
    {
        clearStudentList();
    }
}