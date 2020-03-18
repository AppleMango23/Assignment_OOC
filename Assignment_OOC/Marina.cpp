#include "Header.h"
#include <fstream>

using namespace std;

Boat::Boat()
{
	
}

void Boat::setName(string nameParam)
{
	name = nameParam;
}

string Boat::getName()
{
	return name;
}

void Boat::setBoatName(string bNameParam)
{
	bName = bNameParam;
}

string Boat::getBName()
{
	return bName;
}

void Boat::setLength(int lengthParam)
{
	bLength = lengthParam;
}

int Boat::getLength()
{
	return bLength;
}

void Boat::setDraft(int draftParam)
{
	bDraft = draftParam;
}

int Boat::getDraft()
{
	return bDraft;
}

//---------------------------Link list-------------------------------
BoatNode::BoatNode()
{
	bName = NULL;  // default 
	next = NULL;		 // initialise next
}

BoatNode::BoatNode(string name)
{
	bName = new string(name);  // store name
	next = NULL;                  // initialise next
}

void BoatNode::setNext(BoatNode* nextNode)
{
	next = nextNode;  // change next node
}

BoatNode* BoatNode::getNext()
{
	return next;
}

string* BoatNode::getName()
{
	return bName;
}

BoatList::BoatList()
{
	start = NULL;   // both set to NULL
	end = NULL;
}

bool BoatList::isEmpty()
{
	return start == NULL;
}

void BoatList::addBoatAtEnd(string name, string bName, int bLength , int bDraft)
{
	//adding 4 instead of one Param

	BoatNode* current;
	Boat* boatOne = new Boat();
	boatOne->setName(name);
	boatOne->setBoatName(bName);
	boatOne->setLength(bLength);
	boatOne->setDraft(bDraft);

	 int wholeThing = ((char*)boatOne, sizeof(Boat));
	 string newWholeThing = to_string(wholeThing);

	//Start
	if (end == NULL)       // if list is empty
	{
		current = new BoatNode(newWholeThing);  // allocate memory
		start = current;               // change start 
		end = current;				  // and end
	}
		
	else
	{
		current = new BoatNode(newWholeThing);   // allocate memory
		end->setNext(current);          // change end's next
		end = current;                  // change end
	}

	
	ofstream outFile;  //For write
	outFile.open("saveFile.txt", ios::out | ios::binary | ios::app);
	outFile.write((char*)boatOne, sizeof(Boat));
	outFile.close();

	Boat* boatTwo = new Boat();

	ifstream inFile;   //For read
	inFile.open("saveFile.txt", ios::in | ios::binary | ios::app);
	inFile.read((char*)boatTwo, sizeof(Boat));
	cout << "Getname => " << boatOne->getName() << endl;
	cout << "GetBname => " << boatOne->getBName() << endl;
	cout << "GetDraft => " << boatOne->getDraft() << endl;
	cout << "GetLength => " << boatOne->getLength() << endl;
	inFile.close();


	
}

void BoatList::listAllNames()
{
	BoatNode* current;

	if (!isEmpty())
	{
		cout << "Start of List" << endl;
		current = start;
		while (current != NULL)
		{
			// Funny syntax here as we have to de-reference a pointer to a pointer
			cout << "Next town is: " << *(current->getName()) << endl;
			current = current->getNext();
		}
		cout << "End of List" << endl << endl;
	}
	else
		cout << "List empty" << endl << endl;
}

