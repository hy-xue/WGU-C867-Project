#include <iostream>
#include <iomanip>
#include <string>

#include "securitystudent.h"

SecurityStudent::SecurityStudent() :Student() {
	btype = DegreeType::SECURITY;
}

SecurityStudent::SecurityStudent(
	std::string studentID,
	std::string firstName,
	std::string lastName,
	std::string emailAddr,
	std::string age,
	double classNumDays[],
	DegreeType degreeType
)
	: Student(
		studentID,
		firstName,
		lastName,
		emailAddr,
		age,
		classNumDays) {
	btype = DegreeType::SECURITY;
}

DegreeType SecurityStudent::getDegreeType() {
	return DegreeType::SECURITY;
}

void SecurityStudent::print() {
	this->Student::print();
	std::cout << "SECURITY" << std::endl;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}