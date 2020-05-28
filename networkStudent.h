#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <iostream>
#include <iomanip>
#include <string>

#include "student.h"

class NetworkStudent : public Student {

public:
	NetworkStudent();
	NetworkStudent(
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

	~NetworkStudent();
};

#endif