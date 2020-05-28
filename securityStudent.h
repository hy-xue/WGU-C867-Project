#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <iostream>
#include <iomanip>
#include <string>

#include "student.h"

class SecurityStudent : public Student {

public:
	SecurityStudent();
	SecurityStudent(
		std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddr,
		std::string age,
		double classNumDays[],
		DegreeType degreeType
	);

	DegreeType getDegreeType();

	virtual void print();

	~SecurityStudent();
};

#endif