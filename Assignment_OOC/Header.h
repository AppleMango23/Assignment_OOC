#include <iostream>

using namespace std;

//This is class where we are going to use to store the user's information
#ifndef boat_one
#define boat_one
//Boat class
class Boat
{
	//These are the private variables
	string name;
	string bName;
	string boatType;
	int bLength;
	int bDraft;
	int duration;
	int moneyToPay;

public:
	//This is the constructor
	Boat();

	//These is the set and get for all the classes
	//set and get for name
	void setName(string nameParam);
	string getName();

	//set and get for name
	void setBoatName(string bNameParam);
	string getBName();

	//set and get for length
	void setLength(int lengthParam);
	int getLength();

	//set and get for draft
	void setDraft(int draftParam);
	int getDraft();

	//set and get for duration
	void setDuration(int param);
	int getDuration();

	//set and get for money to pay
	void setMoneyToPay(int param);
	int getMoneyToPay();

	//set and get for boat type
	void setBoatType(string param);
	string getBoatType();
};

//Derived class for boat
class narrow : public Boat      	
{
	//Private variable for narrow class
	string boatType;    

public:

	//Constructor
	narrow();
};

class sailing : public Boat
{
	//Private variable for sailing
	string boatType;
public:
	//Constructor
	sailing();
};

class motor : public Boat
{
	//Private variable for motor
	string boatType;
public:
	//Constructor
	motor();
};
#endif

#ifndef LISTOFBOATS_H
#define LISTOFBOATS_H

//BoatNode class this will be working for the set next in linked list
class BoatNode
{
private:
	//private variable for boat node
	Boat* bName;          
	BoatNode* next;           
public:
	//Constructor for Boat Node
	BoatNode();               

	//Constructor with parameter for boat node
	BoatNode(Boat* name);

	//Set and get for boatnode
	void setNext(BoatNode* nextNode);	
	BoatNode* getNext();
	Boat* getName();
	
};

//Boat list class where we can list out the boat, add new order, remove order, save order and so on.
class BoatList
{
private:
	//private variable for Boat list
	BoatNode* start, * end;
	
public:
	//Constructor for Boat list
	BoatList();

	//Checking if it is in empty
	bool isEmpty();

	//Add boat at start of the linked list
	void addBoatAtStart(string name, string bName, int bLength, int bDraft, int duration, int moneyToPay, string boatType);

	//Add boat at start of the linked list
	void addBoatAtEnd(string name, string bName, int bLength, int bDraft, int duration, int moneyToPay, string boatType);

	//Save the linked list into text file
	void saveBoat();

	//Read the text file into linked list
	BoatList* readFile();

	//List out everything inside linked list
	int listAllNames(string param);

	//Remove 1 order in linked list
	BoatList* removeBoat(int position);
};
#endif


