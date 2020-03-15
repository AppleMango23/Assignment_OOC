// Example C++ Arrays of students
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


#ifndef boat_one
#define boat_one
class boat
{
	string name;
	int popn;

public:
	boat();
	void setName();
	string getName();
};
#endif

//#ifndef StudentList_two
//#define StudentList_two
//class StudentList
//{
//	Student* group[10];  // space for 10 students
//
//public:
//
//	StudentList();            // populate list - better from file
//	Student* findStudent(char*);
//
//};
//#endif