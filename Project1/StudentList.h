#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>
#include "Student.h"

class Node
{
private:
    Student student;
    Node* next;

public:
    Node(const Student& newStudent, Node* newNext)
        : student(newStudent), next(newNext)
    {
    }

    Student& getStudent() { return student; }
    Node* getNext() const { return next; }
    void setStudent(const Student& newStudent) { student = newStudent; }
    void setNext(Node* newNext) { next = newNext; }
};

class StudentList
{
private:
    Node* first;
    Node* last;
    int count;

public:
    StudentList() : first(nullptr), last(nullptr), count(0)
    {
    }

    void addStudent(const Student& student);
    int getNoOfStudents() const;
    void printStudentByID(int id, double tuitionRate) const;
    void printStudentByName(const std::string& lastName) const;
    void printStudentsByCourse(const std::string& coursePrefix, int courseNumber) const;
    void printAllStudents(double tuitionRate) const;
    void clearStudentList();
    ~StudentList();
};

#endif
