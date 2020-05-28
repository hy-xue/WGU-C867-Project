#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>

#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

class Roster {

private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;

public:
	Roster();
	Roster(int capacity);

	Student* getStudentAt(int index);
	void parseThenAdd(std::string row);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddr, std::string age, DegreeType degreeType);
	void printAvgClassNumDays(std::string studentID);
	void print_All();
	void remove(std::string studentID);
	void printInvalidEmails();
	void printByDegreeType(DegreeType degreeType);

	~Roster();
};

#endif