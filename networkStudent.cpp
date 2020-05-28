#include <iostream>
#include <iomanip>
#include <string>

#include "networkstudent.h"

NetworkStudent::NetworkStudent() :Student() {
	btype = DegreeType::NETWORKING;
}

NetworkStudent::NetworkStudent(
	std::string studentID,
	std::string firstName,
	std::string lastName,
	std::string emailAddr,
	std::string age,
	double classNumDays[],
	DegreeType degreeType
) 
	:Student(
	studentID,
	firstName,
	lastName,
	emailAddr,
	age,
	classNumDays) {
	btype = DegreeType::NETWORKING;
}

DegreeType NetworkStudent::getDegreeType() {
	return DegreeType::NETWORKING;
}

void NetworkStudent::print() {
	this->Student::print();
	std::cout << "NETWORK" << std::endl;
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}