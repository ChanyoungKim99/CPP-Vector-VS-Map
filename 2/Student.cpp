#include "Student.h"
#include <iostream>

void Student::Print()
{
	std::cout << "(" << mNumber << ")" <<
		mName << " : " << mScore << std::endl;
}