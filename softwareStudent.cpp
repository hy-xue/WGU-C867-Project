#include <iostream>
#include <iomanip>
#include <string>

#include "softwarestudent.h"

SoftwareStudent::SoftwareStudent() :Student() {
	btype = DegreeType::SOFTWARE;
}

SoftwareStudent::SoftwareStudent(
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
	btype = DegreeType::SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeType() {
	return DegreeType::SOFTWARE;
}

void SoftwareStudent::print() {
	this->Student::print();
	std::cout << "SOFTWARE" << std::endl;
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}