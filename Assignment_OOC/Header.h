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
	string bName;
	int bLength;
	int bDraft;

	int popn;

public:
	Boat();
	void setName(string nameParam);
	string getName();

	void setBoatName(string bNameParam);
	string getBName();

	void setLength(int lengthParam);
	int getLength();

	void setDraft(int draftParam);
	int getDraft();
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
	void listAllNames();
};
#endif


