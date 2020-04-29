// Example C++ Arrays of students
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

//This is class
#ifndef boat_one
#define boat_one
class Boat
{
	string name;
	string bName;
	string boatType;
	int bLength;
	int bDraft;
	int duration;
	int moneyToPay;

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

	void setDuration(int param);
	int getDuration();

	void setMoneyToPay(int param);
	int getMoneyToPay();

	void setBoatType(string param);
	string getBoatType();
};

//Derived class for boat
class narrow : public Boat      	
{
	string boatType;            	
public:
	narrow();
};

class sailing : public Boat
{
	string boatType;
public:
	sailing();
};

class motor : public Boat
{
	string boatType;
public:
	motor();
};
#endif

#ifndef LISTOFBOATS_H
#define LISTOFBOATS_H

using namespace std;

class BoatNode
{
private:
	Boat* bName;          
	BoatNode* next;           
	BoatNode* pre;
public:
	BoatNode();               
	BoatNode(Boat* name);
	void setNext(BoatNode* nextNode);	
	BoatNode* getNext();
	void setPre(BoatNode* preNode);
	BoatNode* getPre();
	Boat* getName();
	
};


class BoatList
{
private:
	BoatNode* start, * end;
	
public:
	BoatList();
	bool isEmpty();
	void addBoatAtEnd(string name, string bName, int bLength, int bDraft, int duration, int moneyToPay, string boatType);
	void saveBoat();
	BoatList* readFile();
	int listAllNames(string param);
	BoatList* removeBoat(int position);
};
#endif


