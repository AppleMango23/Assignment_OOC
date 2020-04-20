#include "Header.h"
#include <fstream>
#include <sstream>

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
	bName = NULL;	// default 
	next = NULL;	//initialise next
}

BoatNode::BoatNode(Boat* name)
{
	bName = name;	// store name
	next = NULL;                 // initialise next
}

void BoatNode::setNext(BoatNode* nextNode)
{
	next = nextNode;  // change next node
}

BoatNode* BoatNode::getNext()
{
	return next;
}

Boat* BoatNode::getName()
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
	BoatNode* current;
	Boat* boatOne = new Boat();

	boatOne->setName(name);
	boatOne->setBoatName(bName);
	boatOne->setLength(bLength);
	boatOne->setDraft(bDraft);

	 int wholeThing = ((char*)boatOne, sizeof(Boat));
	 //string newWholeThing = to_string(wholeThing);
	//Start
	if (end == NULL)       // if list is empty
	{
		current = new BoatNode(boatOne);  // allocate memory
		start = current;               // change start 
		end = current;				  // and end
	}	
	else
	{
		current = new BoatNode(boatOne);   // allocate memory
		end->setNext(current);          // change end's next
		end = current;                  // change end
	}

	
}

void BoatList::saveBoat()
{
	//This one is for the no linked list der output
	BoatNode* current;
	Boat* wordsOut = new Boat();
	ofstream outFile;  //For write

	outFile.open("saveFile.txt", ios::out | ios::app);

	if (!isEmpty())
	{
		cout << "\nStart Saving" << endl;
		current = start;
		while (current != NULL)
		{
			wordsOut = (current->getName());
			// Funny syntax here as we have to de-reference a pointer to a pointer
			outFile << wordsOut->getName() << endl;
			outFile << wordsOut->getBName() << endl;
			outFile << wordsOut->getLength() << endl;
			outFile << wordsOut->getDraft() << endl << endl;
			current = current->getNext();
		}
		cout << "End saving" << endl << endl;
	}
	else
		cout << "List empty" << endl << endl;


	outFile.close();
	
}

void BoatList::listAllNames()
{
	//This one is for the no linked list der output
	BoatNode* current;
	Boat* wordsOut = new Boat();
	ifstream inFile;  //For write
	string line2;


	inFile.open("saveFile.txt", ios::out | ios::app);
	
	while (getline(inFile, line2)) {
		istringstream iss(line2);
		cout << line2 << endl;
	}

	//if (!isEmpty())
	//{
	//	cout << "\nStart Saving" << endl;
	//	current = start;
	//	while (current != NULL)
	//	{
	//		wordsOut = (current->getName());
	//		// Funny syntax here as we have to de-reference a pointer to a pointer
	//		cout << wordsOut->getName() << endl;
	//		cout << wordsOut->getBName() << endl;
	//		cout << wordsOut->getLength() << endl;
	//		cout << wordsOut->getDraft() << endl << endl;
	//		current = current->getNext();
	//	}
	//	cout << "End saving" << endl << endl;
	//}
	//else
	//	cout << "List empty" << endl << endl;


	inFile.close();
	
	


}

