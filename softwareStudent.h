#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <iostream>
#include <iomanip>
#include <string>

#include "student.h"

class SoftwareStudent : public Student {

public:
	SoftwareStudent();
	SoftwareStudent(
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

	~SoftwareStudent();
};

#endif