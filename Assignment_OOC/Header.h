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
	int* bName;          // town's name    
	BoatNode* next;            // link to next
public:
	BoatNode();                // no argument constructor
	BoatNode(int name);
	void setNext(BoatNode* nextNode);
	BoatNode* getNext();
	int* getName();
};


class BoatList
{
private:
	BoatNode* start, * end;

public:
	BoatList();
	bool isEmpty();
	void addBoatAtEnd(string name, string bName, int bLength, int bDraft);
	void saveBoat();
	void listAllNames();
};
#endif


