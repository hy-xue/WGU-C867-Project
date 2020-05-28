#pragma once
#include <iostream>
using std::string;

enum class DegreeType {
	SECURITY, SOFTWARE, NETWORKING
};

static const std::string degreeTypeStrings[] = {
	"SECURITY",
	"SOFTWARE",
	"NETWORKING"
};