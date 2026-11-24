#ifndef Course_h
#define Course_h

#include <string>

class Course
{
private:
	std::string coursePrefix;
	int courseNumber;
	int courseUnits;

public:
	void setCourseInfo(std::string aCoursePrefix, int aCourseNumber, int aCourseUnits);
	std::string getCoursePrefix() const;
	int getCourseNumber() const;
	int getCourseUnits() const;
	bool operator<(const Course& otherCourse) const;
};

#endif
