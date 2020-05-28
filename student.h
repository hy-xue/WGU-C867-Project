#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

#include "degree.h"

class Student {

public:
	const static int classNumDaysArraySize = 3;

protected:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddr;
	std::string age;
	double classNumDays[classNumDaysArraySize];
	DegreeType btype;

public:
	Student();
	Student(string ID, string firstName, string lastName, string emailAddr, string age, double classNumDays[]);

	std::string getStudentID();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmailAddr();
	std::string getAge();
	double* getClassNumDays();
	virtual DegreeType getDegreeType() = 0;

	void setStudentID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddr(string emailAddr);
	void setAge(string age);
	void setClassNumDays(double classNumDays[]);

	virtual void print() = 0;

	~Student();

};

#endif
