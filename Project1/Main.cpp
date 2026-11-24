/*
	Morales, Barezi

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/

#include "CourseList.h"
#include "StudentList.h"

// Added for test cases
#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int main()
{
	/*******************************************************
	*             DO NOT REMOVE THE COMMENTS               *
	********************************************************/

	cout << boolalpha << fixed << setprecision(2);

	// ===== COURSE =====

	// Create at least three Course objects.
	// Use the same prefix with different numbers for two courses,
	// and a different prefix for the third course.
	// Call setCourseInfo() to initialize each object.
	Course c1, c2, c3;

	cout << "Testing Course::setCourseInfo()" << endl;
	c1.setCourseInfo("CS", 250, 4);
	c2.setCourseInfo("CS", 155, 3);
	c3.setCourseInfo("MATH", 180, 5);
	cout << "Created c1 = CS 250 (4 units)" << endl;
	cout << "Created c2 = CS 155 (3 units)" << endl;
	cout << "Created c3 = MATH 180 (5 units)" << endl;
	cout << endl;


	// Test getCoursePrefix(), getCourseNumber(), and getCourseUnits().
	// Display the expected and actual values.
	cout << "Testing Course::getCoursePrefix()" << endl;
	cout << "Expected: CS" << endl;
	cout << "Actual:   " << c1.getCoursePrefix() << endl;
	cout << "Expected: CS" << endl;
	cout << "Actual:   " << c2.getCoursePrefix() << endl;
	cout << "Expected: MATH" << endl;
	cout << "Actual:   " << c3.getCoursePrefix() << endl;
	cout << endl;

	cout << "Testing Course::getCourseNumber()" << endl;
	cout << "Expected: 250" << endl;
	cout << "Actual:   " << c1.getCourseNumber() << endl;
	cout << "Expected: 155" << endl;
	cout << "Actual:   " << c2.getCourseNumber() << endl;
	cout << "Expected: 180" << endl;
	cout << "Actual:   " << c3.getCourseNumber() << endl;
	cout << endl;

	cout << "Testing Course::getCourseUnits()" << endl;
	cout << "Expected: 4" << endl;
	cout << "Actual:   " << c1.getCourseUnits() << endl;
	cout << "Expected: 3" << endl;
	cout << "Actual:   " << c2.getCourseUnits() << endl;
	cout << "Expected: 5" << endl;
	cout << "Actual:   " << c3.getCourseUnits() << endl;
	cout << endl;


	// Test setCourseInfo() again by changing an existing course.
	// Verify that all three member variables were updated.
	cout << "Testing Course::setCourseInfo() on an existing course" << endl;
	c3.setCourseInfo("ENGL", 100, 3);
	cout << "Changed c3 to ENGL 100 (3 units)" << endl;
	cout << "Expected prefix: ENGL" << endl;
	cout << "Actual prefix:   " << c3.getCoursePrefix() << endl;
	cout << "Expected number: 100" << endl;
	cout << "Actual number:   " << c3.getCourseNumber() << endl;
	cout << "Expected units:  3" << endl;
	cout << "Actual units:    " << c3.getCourseUnits() << endl;
	cout << endl;


	// Test operator<() with different course prefixes.
	cout << "Testing Course::operator<() with different prefixes" << endl;
	cout << "CS 250 < ENGL 100" << endl;
	cout << "Expected: true" << endl;
	cout << "Actual:   " << (c1 < c3) << endl;
	cout << "ENGL 100 < CS 250" << endl;
	cout << "Expected: false" << endl;
	cout << "Actual:   " << (c3 < c1) << endl;
	cout << endl;


	// Test operator<() with matching prefixes and different numbers.
	cout << "Testing Course::operator<() with matching prefixes, different numbers" << endl;
	cout << "CS 155 < CS 250" << endl;
	cout << "Expected: true" << endl;
	cout << "Actual:   " << (c2 < c1) << endl;
	cout << "CS 250 < CS 155" << endl;
	cout << "Expected: false" << endl;
	cout << "Actual:   " << (c1 < c2) << endl;
	cout << endl;


	// Test operator<() with matching prefixes and numbers.
	// Verify that neither course is less than the other,
	// even when their units differ.
	Course sameA, sameB;
	sameA.setCourseInfo("CS", 250, 4);
	sameB.setCourseInfo("CS", 250, 2);

	cout << "Testing Course::operator<() with matching prefixes and numbers" << endl;
	cout << "CS 250 (4 units) < CS 250 (2 units)" << endl;
	cout << "Expected: false" << endl;
	cout << "Actual:   " << (sameA < sameB) << endl;
	cout << "CS 250 (2 units) < CS 250 (4 units)" << endl;
	cout << "Expected: false" << endl;
	cout << "Actual:   " << (sameB < sameA) << endl;
	cout << endl;


	// ===== COURSELIST =====

	// Create an empty CourseList object and test printCourses().
	CourseList courseList;

	cout << "Testing CourseList::printCourses() on an empty list" << endl;
	cout << "Expected: heading only, no courses" << endl;
	cout << "Actual:" << endl;
	courseList.printCourses();
	cout << endl;


	// Test addCourse() by adding courses in an unsorted order.
	Course temp;

	cout << "Testing CourseList::addCourse()" << endl;
	cout << "Adding MATH 180, CS 250, ENGL 100, CS 155" << endl;
	temp.setCourseInfo("MATH", 180, 5);
	courseList.addCourse(temp);
	temp.setCourseInfo("CS", 250, 4);
	courseList.addCourse(temp);
	temp.setCourseInfo("ENGL", 100, 3);
	courseList.addCourse(temp);
	temp.setCourseInfo("CS", 155, 3);
	courseList.addCourse(temp);
	cout << endl;


	// Add a duplicate course with the same prefix and number.
	cout << "Testing CourseList::addCourse() with a duplicate" << endl;
	cout << "Adding CS 250 again (different units)" << endl;
	temp.setCourseInfo("CS", 250, 2);
	courseList.addCourse(temp);
	cout << endl;


	// Test printCourses() again.
	// Verify that courses appear in sorted order without duplicates.
	cout << "Testing CourseList::printCourses()" << endl;
	cout << "Expected: CS 155, CS 250, ENGL 100, MATH 180" << endl;
	cout << "Actual:" << endl;
	courseList.printCourses();
	cout << endl;


	// ===== STUDENT =====

	// Create a multimap<Course, char> containing several courses
	// and grades. Use courses with different unit values.
	Course cs250, cs155, math180, engl100;
	cs250.setCourseInfo("CS", 250, 4);
	cs155.setCourseInfo("CS", 155, 3);
	math180.setCourseInfo("MATH", 180, 5);
	engl100.setCourseInfo("ENGL", 100, 3);

	multimap<Course, char> grades1;
	grades1.insert(make_pair(cs250, 'A'));
	grades1.insert(make_pair(cs155, 'B'));
	grades1.insert(make_pair(math180, 'C'));
	grades1.insert(make_pair(engl100, 'F'));


	// Create a Student object with paid tuition using the
	// parameterized constructor and the populated multimap.
	Student paidStudent(1001, "Ana", "Lopez", true, grades1);


	// Create another Student object with unpaid tuition.
	multimap<Course, char> grades2;
	grades2.insert(make_pair(cs250, 'B'));
	grades2.insert(make_pair(math180, 'A'));

	Student unpaidStudent(1002, "Mark", "Chen", false, grades2);


	// Create a Student object with an empty course multimap.
	multimap<Course, char> noCourses;

	Student noCourseStudent(1003, "Sam", "Rivera", true, noCourses);


	// Test getID(), getFirstName(), and getLastName().
	// Display the expected and actual values.
	cout << "Testing Student::getID()" << endl;
	cout << "Expected: 1001" << endl;
	cout << "Actual:   " << paidStudent.getID() << endl;
	cout << "Expected: 1002" << endl;
	cout << "Actual:   " << unpaidStudent.getID() << endl;
	cout << endl;

	cout << "Testing Student::getFirstName()" << endl;
	cout << "Expected: Ana" << endl;
	cout << "Actual:   " << paidStudent.getFirstName() << endl;
	cout << "Expected: Mark" << endl;
	cout << "Actual:   " << unpaidStudent.getFirstName() << endl;
	cout << endl;

	cout << "Testing Student::getLastName()" << endl;
	cout << "Expected: Lopez" << endl;
	cout << "Actual:   " << paidStudent.getLastName() << endl;
	cout << "Expected: Chen" << endl;
	cout << "Actual:   " << unpaidStudent.getLastName() << endl;
	cout << endl;


	// Test getName() using two string variables.
	// Display both variables after the function call.
	string firstName, lastName;
	paidStudent.getName(firstName, lastName);

	cout << "Testing Student::getName()" << endl;
	cout << "Expected first name: Ana" << endl;
	cout << "Actual first name:   " << firstName << endl;
	cout << "Expected last name:  Lopez" << endl;
	cout << "Actual last name:    " << lastName << endl;
	cout << endl;


	// Test getNumberOfCourses() for students with and without courses.
	cout << "Testing Student::getNumberOfCourses()" << endl;
	cout << "Student with 4 courses" << endl;
	cout << "Expected: 4" << endl;
	cout << "Actual:   " << paidStudent.getNumberOfCourses() << endl;
	cout << "Student with 2 courses" << endl;
	cout << "Expected: 2" << endl;
	cout << "Actual:   " << unpaidStudent.getNumberOfCourses() << endl;
	cout << "Student with no courses" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << noCourseStudent.getNumberOfCourses() << endl;
	cout << endl;


	// Test getCoursesCompleted().
	// Store the returned multimap and display its courses and grades.
	multimap<Course, char> returnedCourses = paidStudent.getCoursesCompleted();

	cout << "Testing Student::getCoursesCompleted()" << endl;
	cout << "Expected: CS 155 B, CS 250 A, ENGL 100 F, MATH 180 C" << endl;
	cout << "Actual:" << endl;
	for (const auto& entry : returnedCourses)
	{
		cout << entry.first.getCoursePrefix() << " "
			<< entry.first.getCourseNumber() << " "
			<< entry.second << endl;
	}
	cout << endl;


	// Modify the returned multimap.
	// Verify that the Student object's courses remain unchanged.
	returnedCourses.clear();

	cout << "Testing Student::getCoursesCompleted() returns a copy" << endl;
	cout << "Cleared the returned multimap" << endl;
	cout << "Expected number of courses in student: 4" << endl;
	cout << "Actual:                                "
		<< paidStudent.getCoursesCompleted().size() << endl;
	cout << endl;


	// Test isTuitionPaid() for paid and unpaid tuition.
	cout << "Testing Student::isTuitionPaid()" << endl;
	cout << "Paid student" << endl;
	cout << "Expected: true" << endl;
	cout << "Actual:   " << paidStudent.isTuitionPaid() << endl;
	cout << "Unpaid student" << endl;
	cout << "Expected: false" << endl;
	cout << "Actual:   " << unpaidStudent.isTuitionPaid() << endl;
	cout << endl;


	// Test getUnitsCompleted() for students with and without courses.
	cout << "Testing Student::getUnitsCompleted()" << endl;
	cout << "Student with courses (4 + 3 + 5 + 3)" << endl;
	cout << "Expected: 15" << endl;
	cout << "Actual:   " << paidStudent.getUnitsCompleted() << endl;
	cout << "Student with courses (4 + 5)" << endl;
	cout << "Expected: 9" << endl;
	cout << "Actual:   " << unpaidStudent.getUnitsCompleted() << endl;
	cout << "Student with no courses" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << noCourseStudent.getUnitsCompleted() << endl;
	cout << endl;


	// Test isCourseCompleted() with a matching prefix and number.
	cout << "Testing Student::isCourseCompleted() with a matching course" << endl;
	cout << "CS 250" << endl;
	cout << "Expected: true" << endl;
	cout << "Actual:   " << paidStudent.isCourseCompleted("CS", 250) << endl;
	cout << "MATH 180" << endl;
	cout << "Expected: true" << endl;
	cout << "Actual:   " << paidStudent.isCourseCompleted("MATH", 180) << endl;
	cout << endl;


	// Test isCourseCompleted() with a matching prefix but a
	// different number, and with a matching number but a
	// different prefix. Both searches should return false.
	cout << "Testing Student::isCourseCompleted() with no match" << endl;
	cout << "CS 999 (matching prefix, different number)" << endl;
	cout << "Expected: false" << endl;
	cout << "Actual:   " << paidStudent.isCourseCompleted("CS", 999) << endl;
	cout << "MATH 250 (matching number, different prefix)" << endl;
	cout << "Expected: false" << endl;
	cout << "Actual:   " << paidStudent.isCourseCompleted("MATH", 250) << endl;
	cout << endl;


	// Test isCourseCompleted() for a student with no courses.
	cout << "Testing Student::isCourseCompleted() for a student with no courses" << endl;
	cout << "CS 250" << endl;
	cout << "Expected: false" << endl;
	cout << "Actual:   " << noCourseStudent.isCourseCompleted("CS", 250) << endl;
	cout << endl;


	// Test calculateGPA() using a GPA calculated independently.
	// Include an F grade in at least one test.
	// Paid student (includes an F):
	//   (4 * 4) + (3 * 3) + (5 * 2) + (3 * 0) = 35 points / 15 units = 2.33
	// Unpaid student:
	//   (4 * 3) + (5 * 4) = 32 points / 9 units = 3.56
	cout << "Testing Student::calculateGPA()" << endl;
	cout << "Student with an F grade: 35 points / 15 units" << endl;
	cout << "Expected: 2.33" << endl;
	cout << "Actual:   " << paidStudent.calculateGPA() << endl;
	cout << "Student without an F grade: 32 points / 9 units" << endl;
	cout << "Expected: 3.56" << endl;
	cout << "Actual:   " << unpaidStudent.calculateGPA() << endl;
	cout << endl;


	// Test calculateGPA() for a student with no courses.
	// The expected result is 0.0.
	cout << "Testing Student::calculateGPA() for a student with no courses" << endl;
	cout << "Expected: 0.00" << endl;
	cout << "Actual:   " << noCourseStudent.calculateGPA() << endl;
	cout << endl;


	// Test billingAmount() using a chosen tuition rate.
	// Verify that the calculation uses the number of courses.
	double tuitionRate = 150.00;

	cout << "Testing Student::billingAmount() with a rate of 150.00" << endl;
	cout << "4 courses x 150.00" << endl;
	cout << "Expected: 600.00" << endl;
	cout << "Actual:   " << paidStudent.billingAmount(tuitionRate) << endl;
	cout << "2 courses x 150.00" << endl;
	cout << "Expected: 300.00" << endl;
	cout << "Actual:   " << unpaidStudent.billingAmount(tuitionRate) << endl;
	cout << "0 courses x 150.00" << endl;
	cout << "Expected: 0.00" << endl;
	cout << "Actual:   " << noCourseStudent.billingAmount(tuitionRate) << endl;
	cout << endl;


	// Test setStudent() by copying one Student object's
	// information into another existing Student object.
	// Verify that all information was copied.
	Student target(2000, "Temp", "Person", false, noCourses);

	target.setStudent(paidStudent);

	cout << "Testing Student::setStudent()" << endl;
	cout << "Copied the student with ID 1001 into a student with ID 2000" << endl;
	cout << "Expected ID: 1001" << endl;
	cout << "Actual ID:   " << target.getID() << endl;
	cout << "Expected first name: Ana" << endl;
	cout << "Actual first name:   " << target.getFirstName() << endl;
	cout << "Expected last name: Lopez" << endl;
	cout << "Actual last name:   " << target.getLastName() << endl;
	cout << "Expected tuition paid: true" << endl;
	cout << "Actual tuition paid:   " << target.isTuitionPaid() << endl;
	cout << "Expected number of courses: 4" << endl;
	cout << "Actual number of courses:   " << target.getNumberOfCourses() << endl;
	cout << "Expected courses in multimap: 4" << endl;
	cout << "Actual courses in multimap:   "
		<< target.getCoursesCompleted().size() << endl;
	cout << endl;


	// Test printStudent().
	cout << "Testing Student::printStudent()" << endl;
	cout << "Expected: ID 1001, last name Lopez, first name Ana" << endl;
	cout << "Actual:" << endl;
	paidStudent.printStudent();
	cout << endl;


	// Test printStudentInfo() for paid tuition.
	// Verify that grades and GPA are displayed.
	cout << "Testing Student::printStudentInfo() with paid tuition" << endl;
	cout << "Expected: grades A, B, C, F; total units 15; GPA 2.33" << endl;
	cout << "Actual:" << endl;
	paidStudent.printStudentInfo(tuitionRate);
	cout << endl;


	// Test printStudentInfo() for unpaid tuition.
	// Verify that grades are replaced with ***, GPA is hidden,
	// and the hold message and amount due are displayed.
	cout << "Testing Student::printStudentInfo() with unpaid tuition" << endl;
	cout << "Expected: grades shown as ***, no GPA, hold message, amount due 300.00" << endl;
	cout << "Actual:" << endl;
	unpaidStudent.printStudentInfo(tuitionRate);
	cout << endl;


	// Test printStudentInfo() for a student with no courses.
	cout << "Testing Student::printStudentInfo() with no courses" << endl;
	cout << "Expected: 0 courses, total units 0, GPA 0.00" << endl;
	cout << "Actual:" << endl;
	noCourseStudent.printStudentInfo(tuitionRate);
	cout << endl;


	// ===== NODE =====

	// Create two dynamic Node objects using existing Student objects.
	// Use nullptr as the next pointer when appropriate.
	cout << "Testing Node::Node()" << endl;
	Node* node1 = new Node(paidStudent, nullptr);
	Node* node2 = new Node(unpaidStudent, nullptr);
	cout << "Created node1 with student 1001 and node2 with student 1002" << endl;
	cout << endl;


	// Test getStudent() by displaying the stored student's information.
	cout << "Testing Node::getStudent()" << endl;
	cout << "Expected: ID 1001, last name Lopez, first name Ana" << endl;
	cout << "Actual:" << endl;
	node1->getStudent().printStudent();
	cout << "Expected: ID 1002, last name Chen, first name Mark" << endl;
	cout << "Actual:" << endl;
	node2->getStudent().printStudent();
	cout << endl;


	// Test setStudent() and verify that the stored student changed.
	node1->setStudent(noCourseStudent);

	cout << "Testing Node::setStudent()" << endl;
	cout << "Replaced node1's student with student 1003" << endl;
	cout << "Expected ID: 1003" << endl;
	cout << "Actual ID:   " << node1->getStudent().getID() << endl;
	cout << "Expected last name: Rivera" << endl;
	cout << "Actual last name:   " << node1->getStudent().getLastName() << endl;
	cout << endl;


	// Test setNext() by linking the first node to the second node.
	cout << "Testing Node::setNext()" << endl;
	node1->setNext(node2);
	cout << "Linked node1 to node2" << endl;
	cout << endl;


	// Test getNext() and verify that it returns the expected pointer.
	cout << "Testing Node::getNext()" << endl;
	cout << "node1->getNext() == node2" << endl;
	cout << "Expected: true" << endl;
	cout << "Actual:   " << (node1->getNext() == node2) << endl;
	cout << "ID of the student in the next node" << endl;
	cout << "Expected: 1002" << endl;
	cout << "Actual:   " << node1->getNext()->getStudent().getID() << endl;
	cout << endl;


	// Set the first node's next pointer to nullptr and verify it.
	node1->setNext(nullptr);

	cout << "Testing Node::setNext() with nullptr" << endl;
	cout << "node1->getNext() == nullptr" << endl;
	cout << "Expected: true" << endl;
	cout << "Actual:   " << (node1->getNext() == nullptr) << endl;
	cout << endl;

	delete node1;
	delete node2;
	node1 = nullptr;
	node2 = nullptr;


	// ===== STUDENTLIST =====

	// Create an empty StudentList object.
	StudentList studentList;


	// Test getNoOfStudents(). The expected result is 0.
	cout << "Testing StudentList::getNoOfStudents() on an empty list" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << studentList.getNoOfStudents() << endl;
	cout << endl;


	// Test all four printing functions on the empty list:
	// printStudentByID(), printStudentByName(),
	// printStudentsByCourse(), and printAllStudents().
	cout << "Testing StudentList::printStudentByID() on an empty list" << endl;
	cout << "Expected: message that no student was found with ID 1001" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentByID(1001, tuitionRate);
	cout << endl;

	cout << "Testing StudentList::printStudentByName() on an empty list" << endl;
	cout << "Expected: message that no student was found with last name Lopez" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentByName("Lopez");
	cout << endl;

	cout << "Testing StudentList::printStudentsByCourse() on an empty list" << endl;
	cout << "Expected: message that no students completed CS 250" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentsByCourse("CS", 250);
	cout << endl;

	cout << "Testing StudentList::printAllStudents() on an empty list" << endl;
	cout << "Expected: no output" << endl;
	cout << "Actual:" << endl;
	studentList.printAllStudents(tuitionRate);
	cout << endl;


	// Test clearStudentList() on the empty list.
	studentList.clearStudentList();

	cout << "Testing StudentList::clearStudentList() on an empty list" << endl;
	cout << "Expected number of students: 0" << endl;
	cout << "Actual:                      " << studentList.getNoOfStudents() << endl;
	cout << endl;


	// Test addStudent() by adding the first student.
	// Verify that getNoOfStudents() returns 1.
	studentList.addStudent(paidStudent);

	cout << "Testing StudentList::addStudent() with the first student" << endl;
	cout << "Expected number of students: 1" << endl;
	cout << "Actual:                      " << studentList.getNoOfStudents() << endl;
	cout << endl;


	// Add more students, including paid and unpaid students.
	// Include two students with the same last name and
	// two students who share a course.
	// 1001 Lopez (paid) and 1002 Chen (unpaid) share CS 250 and MATH 180.
	// 1001 Lopez and 1004 Lopez share a last name and CS 155.
	multimap<Course, char> grades3;
	grades3.insert(make_pair(cs155, 'A'));
	grades3.insert(make_pair(engl100, 'B'));
	Student sameLastName(1004, "Maria", "Lopez", true, grades3);

	studentList.addStudent(unpaidStudent);
	studentList.addStudent(noCourseStudent);
	studentList.addStudent(sameLastName);


	// Test getNoOfStudents() again.
	// Verify that it matches the number of students added.
	cout << "Testing StudentList::getNoOfStudents() after adding 4 students" << endl;
	cout << "Expected: 4" << endl;
	cout << "Actual:   " << studentList.getNoOfStudents() << endl;
	cout << endl;


	// Test printStudentByID() for students at the beginning,
	// middle, and end of the list.
	cout << "Testing StudentList::printStudentByID() for the first student (1001)" << endl;
	cout << "Expected: full information for Lopez, Ana" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentByID(1001, tuitionRate);
	cout << endl;

	cout << "Testing StudentList::printStudentByID() for a middle student (1003)" << endl;
	cout << "Expected: full information for Rivera, Sam" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentByID(1003, tuitionRate);
	cout << endl;

	cout << "Testing StudentList::printStudentByID() for the last student (1004)" << endl;
	cout << "Expected: full information for Lopez, Maria" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentByID(1004, tuitionRate);
	cout << endl;


	// Test printStudentByID() with an ID that is not in the list.
	cout << "Testing StudentList::printStudentByID() with an ID not in the list" << endl;
	cout << "Expected: message that no student was found with ID 9999" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentByID(9999, tuitionRate);
	cout << endl;


	// Test printStudentByName() with a shared last name.
	// Verify that every matching student is displayed.
	cout << "Testing StudentList::printStudentByName() with a shared last name" << endl;
	cout << "Expected: students 1001 and 1004 (both Lopez)" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentByName("Lopez");
	cout << endl;


	// Test printStudentByName() with a last name not in the list.
	cout << "Testing StudentList::printStudentByName() with a last name not in the list" << endl;
	cout << "Expected: message that no student was found with last name Nguyen" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentByName("Nguyen");
	cout << endl;


	// Test printStudentsByCourse() with a shared course.
	// Verify that every matching student is displayed.
	cout << "Testing StudentList::printStudentsByCourse() with a shared course (CS 250)" << endl;
	cout << "Expected: students 1001 and 1002" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentsByCourse("CS", 250);
	cout << endl;

	cout << "Testing StudentList::printStudentsByCourse() with a shared course (CS 155)" << endl;
	cout << "Expected: students 1001 and 1004" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentsByCourse("CS", 155);
	cout << endl;


	// Test printStudentsByCourse() with a course that no
	// student has completed.
	cout << "Testing StudentList::printStudentsByCourse() with a course no student completed" << endl;
	cout << "Expected: message that no students completed PHYS 101" << endl;
	cout << "Actual:" << endl;
	studentList.printStudentsByCourse("PHYS", 101);
	cout << endl;


	// Test printAllStudents().
	// Verify that every student's information is displayed.
	cout << "Testing StudentList::printAllStudents()" << endl;
	cout << "Expected: full information for students 1001, 1002, 1003, 1004" << endl;
	cout << "Actual:" << endl;
	studentList.printAllStudents(tuitionRate);
	cout << endl;


	// Test clearStudentList() on the populated list.
	// Verify that getNoOfStudents() returns 0.
	studentList.clearStudentList();

	cout << "Testing StudentList::clearStudentList() on a populated list" << endl;
	cout << "Expected number of students: 0" << endl;
	cout << "Actual:                      " << studentList.getNoOfStudents() << endl;
	cout << endl;


	// Add a student after clearing the list.
	// Verify that insertion and printing still work correctly.
	studentList.addStudent(sameLastName);

	cout << "Testing StudentList::addStudent() after clearing the list" << endl;
	cout << "Expected number of students: 1" << endl;
	cout << "Actual:                      " << studentList.getNoOfStudents() << endl;
	cout << "Expected: full information for Lopez, Maria (1004)" << endl;
	cout << "Actual:" << endl;
	studentList.printAllStudents(tuitionRate);
	cout << endl;


	// Clear the list again, then clear the already empty list.
	cout << "Testing StudentList::clearStudentList() twice in a row" << endl;
	studentList.clearStudentList();
	cout << "Expected number of students after first clear: 0" << endl;
	cout << "Actual:                                        " << studentList.getNoOfStudents() << endl;
	studentList.clearStudentList();
	cout << "Expected number of students after second clear: 0" << endl;
	cout << "Actual:                                         " << studentList.getNoOfStudents() << endl;
	cout << endl;


	// Test the StudentList destructor by creating a local
	// StudentList inside a separate block, adding students,
	// and allowing the object to go out of scope without
	// explicitly calling clearStudentList().
	cout << "Testing StudentList::~StudentList()" << endl;
	{
		StudentList localList;
		localList.addStudent(paidStudent);
		localList.addStudent(unpaidStudent);
		localList.addStudent(noCourseStudent);
		cout << "Expected number of students in local list: 3" << endl;
		cout << "Actual:                                    " << localList.getNoOfStudents() << endl;
		cout << "Leaving the block; the destructor runs now" << endl;
	}
	cout << "Expected: program continues with no errors" << endl;
	cout << "Actual:   the local list went out of scope and the program continues" << endl;

	cout << "working" << endl;

	cout << endl;
	system("Pause");
	return 0;
}