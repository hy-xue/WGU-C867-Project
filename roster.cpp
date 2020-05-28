#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "degree.h"

	Roster::Roster() {
		this->capacity = 0;
		this->lastIndex = -1;
		this->classRosterArray = nullptr;
	}

	Roster::Roster(int capacity) {
		this->capacity = capacity;
		this->lastIndex = -1;
		this->classRosterArray = new Student * [capacity];
	}

	Student* Roster::getStudentAt(int index) {
		return classRosterArray[index];
	}

	

	void Roster::parseThenAdd(std::string row) {
		if (lastIndex < capacity)
		{
			lastIndex++;
			DegreeType degreeType;
			if (row.back() == 'K')
				degreeType = DegreeType::NETWORKING;
			else if (row.back() == 'Y')
				degreeType = DegreeType::SECURITY;
			else if (row.back() == 'E')
				degreeType = DegreeType::SOFTWARE;
			else {
				std::cerr << "ERROR: INVALID STUDENT TYPE." << std::endl;
				std::cerr << "NOW EXITING." << std::endl;
				exit(-1);
			}

			int rhs = row.find(",");
			std::string studentID = row.substr(0, rhs);

			int lhs = rhs + 1;
			rhs = row.find(",", lhs);
			std::string firstName = row.substr(lhs, rhs - lhs);

			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			std::string lastName = row.substr(lhs, rhs - lhs);

			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			std::string emailAddr = row.substr(lhs, rhs - lhs);

			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			std::string age = row.substr(lhs, rhs - lhs);

			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			double classNumDays1 = std::stod(row.substr(lhs, rhs - lhs));

			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			double classNumDays2 = std::stod(row.substr(lhs, rhs - lhs));

			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			double classNumDays3 = std::stod(row.substr(lhs, rhs - lhs));


			double classNumDays[Student::classNumDaysArraySize];
			classNumDays[0] = classNumDays1;
			classNumDays[1] = classNumDays2;
			classNumDays[2] = classNumDays3;
			if (degreeType == DegreeType::NETWORKING)
				classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddr, age, classNumDays, degreeType);
			else if (degreeType == DegreeType::SECURITY)
				classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddr, age, classNumDays, degreeType);
			else
				classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddr, age, classNumDays, degreeType);
		}
	}

	void Roster::print_All() {
		for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
	}

	void Roster::remove(std::string studentID) {
		std::cout << "Removing Student: " << studentID << std::endl;
		bool found = false;
		for (int i = 0; i <= lastIndex; i++) {
			if (this->classRosterArray[i]->getStudentID() == studentID) {
				found = true;
				delete this->classRosterArray[i];
				this->classRosterArray[i] = this->classRosterArray[lastIndex];
				lastIndex--;
			}
		}
		if (!found) {
			std::cout << "ERROR: Student " << studentID << " not found." << std::endl;
		}
	}

	void Roster::printInvalidEmails() {
		for (int i = 0; i <= lastIndex; i++) {
			string em = classRosterArray[i]->getEmailAddr();
			if (em.find("@") == string::npos || em.find(" ") != string::npos || em.find(".") == string::npos) {
				std::cout << "ERROR INVALID STUDENT EMAIL: " << em << std::endl;
			}
		}
	}

	void Roster::printByDegreeType(DegreeType degreeType) {
		for (int i = 0; i <= lastIndex; i++) {
			if (this->classRosterArray[i]->getDegreeType() == degreeType) {
				this->classRosterArray[i]->print();
			}
		}
	}

	void Roster::printAvgClassNumDays(std::string studentID) {
		bool found = false;
		for (int i = 0; i <= lastIndex; i++) {
			if ((*classRosterArray[i]).getStudentID() == studentID) {
				found = true;
				int average = 0;
				average = (classRosterArray[i]->getClassNumDays()[0] + classRosterArray[i]->getClassNumDays()[1] + classRosterArray[i]->getClassNumDays()[2]) / 3.0;
				std::cout << "Average days it took student " << studentID << " to complete a course: " << average << " days" << std::endl;
			}
		}
		if (!found) std::cout << "Student not found." << std::endl;
	}

		Roster::~Roster() {
		};

		int main() {
			std::cout << std::left << std::setw(20) << "Course Title: " << "\t";
			std::cout << std::left << "C867 - Scripting and Programming Applications" << std::endl;
			std::cout << std::left << std::setw(20) << "Programming Language: " << "\t";
			std::cout << std::left << "C++" << std::endl;
			std::cout << std::left << std::setw(20) << "Student Name: " << "\t";
			std::cout << std::left << "Elizabeth Ha" << std::endl;
			std::cout << std::left << std::setw(20) << "Student ID #: " << "\t";
			std::cout << std::left << "001227045" << std::endl << std::endl << std::endl;

			int numStudents = 5;
			const std::string studentData[5] = {
				"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
				"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
				"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
				"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
				"A5,Elizabeth,Ha,eha2@wgu.edu,22,28,35,40,SOFTWARE"
			};

			Roster* rep = new Roster(numStudents);
			std::cout << "Status of parsing data and adding students: ";
			for (int i = 0; i < numStudents; i++) {
				rep->parseThenAdd(studentData[i]);
			}

			std::cout << "COMPLETE." << std::endl;
			std::cout << "NOW DISPLAYING ALL STUDENTS." << std::endl << std::endl;
			rep->print_All();

			std::cout << std::endl << std::endl;

			std::cout << "Checking Student's email address: " << std::endl;
			rep->printInvalidEmails();

			std::cout << std::endl << std::endl;

			std::cout << "Printing average days it takes each Student to complete a course: " << std::endl;
			for (int i = 0; i < numStudents; i++) {
				rep->printAvgClassNumDays(rep->getStudentAt(i)->getStudentID());
			}

			std::cout << std::endl << std::endl;

			std::cout << "Printing by Degree Progam: " << std::endl;
			rep->printByDegreeType(DegreeType::SOFTWARE);

			std::cout << std::endl << std::endl;

			rep->remove("A3");
			rep->print_All();

			std::cout << std::endl << std::endl;

			rep->remove("A3");
			rep->print_All();
			numStudents--;

			return 0;
		}