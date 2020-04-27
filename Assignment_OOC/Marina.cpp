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

void BoatNode::setPre(BoatNode* preNode)
{
	pre = preNode;  // change next node
}

BoatNode* BoatNode::getPre()
{
	return pre;
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
	
	//Start
	if (end == NULL)       // if list is empty
	{
		current = new BoatNode(boatOne);  // allocate memory
		start = current;               // change start 
		end = current;				  // and end
	}	
	//end
	else
	{
		//Single linked list
		current = new BoatNode(boatOne);   // allocate memory
		end->setNext(current);          // change end's 
		end = current;                  // change end
	}
}

void BoatList::removeBoat(int position)
{
	BoatNode* current;
	Boat* wordsOut = new Boat();
	BoatList* tempTesting = new BoatList();
	int counterSet=1;
	ofstream outFile;  //For write


	//File clearing
	outFile.open("saveFile.txt", std::ofstream::out | std::ofstream::trunc);
	outFile.close();

	outFile.open("saveFile.txt", ios::out | ios::app);

	if (!isEmpty())
	{
		current = start;
		while (current != NULL)
		{	
			if (counterSet != position)
			{
				wordsOut = (current->getName());
				cout << "Position: " << position << endl << "CounterSet: " << counterSet << endl;
				outFile << wordsOut->getName()
					<< "\n" << wordsOut->getBName()
					<< "\n" << wordsOut->getLength()
					<< "\n" << wordsOut->getDraft() << endl << endl;
				current = current->getNext();
			}
			else {
				//Make it call next
				current = current->getNext();
			}
			counterSet++;
		}
		
	}

	outFile.close();

	

	
}

void BoatList::temp(BoatList* tempTesting,int deleteNum)
{
	tempTesting->removeBoat(deleteNum);
}

void BoatList::saveBoat()
{
	//This one is for the no linked list der output
	BoatNode* current;
	Boat* wordsOut = new Boat();
	ofstream outFile;  //For write
	int x = 0;

	//File clearing
	outFile.open("saveFile.txt", std::ofstream::out | std::ofstream::trunc);
	outFile.close();

	outFile.open("saveFile.txt", ios::out | ios::app);

	cout << "save part below" << endl;
	if (!isEmpty())
	{
		current = start;
		
		while (current != NULL)
		{
			wordsOut = (current->getName());
			cout << wordsOut->getName() 
				<< "\n" << wordsOut->getBName()
				<< "\n" << wordsOut->getLength() 
				<< "\n" << wordsOut->getDraft() << endl << endl;
			current = current->getNext();
			x++;
		}
		cout <<"======="<< x << " customer saved=======" << endl;
	}
	outFile.close();
}

BoatList* BoatList::listAllNames()
{
	//This one is for the no linked list der output
	Boat* wordsOut = new Boat();
	ifstream inFile;  //For write
	string line2;
	int counter = 0;
	int number;
	BoatList* Temptest = new BoatList();

	inFile.open("saveFile.txt", ios::out | ios::app);
	while (getline(inFile, line2)) {
		counter++;
		if(counter == 1){
			wordsOut->setName(line2);
		} 
		if (counter == 2) {
			wordsOut->setBoatName(line2);
		}
		if (counter == 3) {			
			wordsOut->setLength(stoi(line2));
		}
		if (counter == 4) {
			wordsOut->setDraft(stoi(line2));
			Temptest->addBoatAtEnd(wordsOut->getName(), wordsOut->getBName(), wordsOut->getDraft(), wordsOut->getLength());
		}
		if (counter == 5) {
			counter = 0;
		}
	}
	inFile.close();

	return Temptest;
}

