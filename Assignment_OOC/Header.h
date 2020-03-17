// Example C++ Arrays of students
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;


#ifndef boat_one
#define boat_one
class Boat
{
	string name;
	int popn;

public:
	Boat();
	void setName(string nameParam);
	string getName();
};
#endif

#ifndef LISTOFBOATS_H
#define LISTOFBOATS_H

using namespace std;

class BoatNode
{
private:
	string* boatName;          // town's name    
	BoatNode* next;            // link to next
public:
	BoatNode();                // no argument constructor
	BoatNode(string name);
	void setNext(BoatNode* nextNode);
	BoatNode* getNext();
	string* getName();
};


class BoatList
{
private:
	BoatNode* start, * end;

public:
	BoatList();
	bool isEmpty();
	void addFirstBoat(string name);
	void addBoatAtEnd(string name);
	//void addBoatAtStart(string name);
	void listAllNames();
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