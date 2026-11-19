#ifndef Course_h
#define Course_h

class Course
{
private:
	string coursePrefix;
	int courseNumber;
	int courseUnits;

public:
	void setCourseInfo(string aCoursePrefix, int aCourseNumber, int aCourseUnits) {}
	string getCoursePrefix() const {};
	int getCourseNumber() const {};
	int getCourseUnits() const {};
	bool operator<(const Course& otherCourse) const {};
};

#endif
