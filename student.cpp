#include <iostream>
#include <iomanip>

#include "student.h"
#include "degree.h"

Student::Student() {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddr = emailAddr;
	this->age = age;
	for (int i = 0; i < classNumDaysArraySize; i++) this->classNumDays[i] = 0;
}

Student::Student(string ID, string firstName, string lastName, string emailAddr, string age, double classNumDays[]) {
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddr = emailAddr;
	this->age = age;
	for (int i = 0; i < classNumDaysArraySize; i++) this->classNumDays[i] = classNumDays[i];
}

std::string Student::getStudentID() {
	return studentID;
}

void Student::setStudentID(string studentID) {
	studentID = studentID;
}

std::string Student::getFirstName() {
	return firstName;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

std::string Student::getLastName() {
	return lastName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

std::string Student::getEmailAddr() {
	return emailAddr;
}

void Student::setEmailAddr(string emailAddr) {
	this->emailAddr = emailAddr;
}

std::string Student::getAge() {
	return age;
}

void Student::setAge(string age) {
	this->age = age;
}

double * Student::getClassNumDays() {
	return classNumDays;
}

void Student::setClassNumDays(double classNumDays[]) {
	for (int i = 0; i < classNumDaysArraySize; i++)
		this->classNumDays[i] = classNumDays[i];
}

void Student::print() {
	std::cout << std::left << getStudentID() << "\t";
	std::cout << std::setw(14) << getFirstName() << "\t";
	std::cout << std::setw(8) << getLastName() << "\t";
	std::cout << std::setw(25) << getEmailAddr() << "\t";
	std::cout << std::left << getAge() << "\t";
	std::cout << std::left << getClassNumDays()[0] << "\t";
	std::cout << std::left << getClassNumDays()[1] << "\t";
	std::cout << std::left << getClassNumDays()[2] << "\t";
}

Student::~Student() {
}