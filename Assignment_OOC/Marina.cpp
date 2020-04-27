#include "Header.h"
#include <fstream>
#include <sstream>
#include <iomanip>

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

void Boat::setDuration(int param)
{
	duration = param;
}

int Boat::getDuration()
{
	return duration;
}

void Boat::setMoneyToPay(int param)
{
	moneyToPay = param;
}

int Boat::getMoneyToPay()
{
	return moneyToPay;
}

void Boat::setBoatType(string param)
{
	boatType = param;
}

string Boat::getBoatType()
{
	return boatType;
}
//--------------------------Inheritance-----------------------------

narrow::narrow() : Boat()
{

}

sailing::sailing() : Boat()
{

}

motor::motor() : Boat()
{

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

void BoatList::addBoatAtEnd(string name, string bName, int bLength , int bDraft, int duration, int moneyToPay, string boatType)
{
	BoatNode* current;
	Boat* boatOne = new Boat();
	
	boatOne->setName(name);
	boatOne->setBoatName(bName);
	boatOne->setLength(bLength);
	boatOne->setDraft(bDraft);
	boatOne->setDuration(duration);
	boatOne->setMoneyToPay(moneyToPay);
	boatOne->setBoatType(boatType);

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

BoatList* BoatList::removeBoat(int position)
{
	BoatNode* current;
	Boat* wordsOut = new Boat();
	int counterSet=1;
	BoatList* temptesting = new BoatList();
	ofstream outFile;  //For write

	//File clearing
	outFile.open("saveFile.txt", std::ofstream::out | std::ofstream::trunc);
	outFile.close();

	//For new save
	outFile.open("saveFile.txt", ios::out | ios::app);
	if (!isEmpty())
	{
		current = start;
		while (current != NULL)
		{	
			if (counterSet != position)
			{
				wordsOut = (current->getName());
				outFile << wordsOut->getName()
					<< "\n" << wordsOut->getBName()
					<< "\n" << wordsOut->getLength()
					<< "\n" << wordsOut->getDraft() 
					<< "\n" << wordsOut->getDuration()
					<< "\n" << wordsOut->getMoneyToPay()
					<< "\n" << wordsOut->getBoatType()
					<< endl << endl;
				temptesting->addBoatAtEnd(wordsOut->getName(), wordsOut->getBName(),
										wordsOut->getLength(), wordsOut->getDraft(),
										wordsOut->getDuration(),wordsOut->getMoneyToPay(),
										wordsOut->getBoatType());
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
	return temptesting;
}

//Not really useful can be delete
BoatList* BoatList::temp(BoatList* tempTesting,int deleteNum)
{
	return tempTesting->removeBoat(deleteNum);
}

void BoatList::saveBoat()
{
	//This one is for the no linked list der output
	BoatNode* current;
	Boat* wordsOut = new Boat();
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
			wordsOut = (current->getName());
			outFile << wordsOut->getName() 
				<< "\n" << wordsOut->getBName()
				<< "\n" << wordsOut->getLength() 
				<< "\n" << wordsOut->getDraft() 
				<< "\n" << wordsOut->getDuration()
				<< "\n" << wordsOut->getMoneyToPay()
				<< "\n" << wordsOut->getBoatType()
				<< endl << endl;
			current = current->getNext();
		}
		cout <<"<<<<<<=======customer saved=======>>>>>>" << endl;
	}
	outFile.close();
}

BoatList* BoatList::readFile()
{
	//This one is for the no linked list der output
	Boat* wordsOut = new Boat();
	ifstream inFile;  //For write
	string line2;
	int counter = 0;
	int number;
	BoatList* TempList = new BoatList();
	int totalLength = 0;

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
		}
		if (counter == 5) {
			wordsOut->setDuration(stoi(line2));
		}
		if (counter == 6) {
			wordsOut->setMoneyToPay(stoi(line2));
		}
		if (counter == 7) {
			wordsOut->setBoatType(line2);
			TempList->addBoatAtEnd(wordsOut->getName(), wordsOut->getBName(), 
								wordsOut->getLength(), wordsOut->getDraft(),
								wordsOut->getDuration(), wordsOut->getMoneyToPay(),
								wordsOut->getBoatType());
		}
		if (counter == 8) {
			counter = 0;
		}
	}
	inFile.close();
	return TempList;
}

int BoatList::listAllNames(string param)
{
	BoatNode* current;
	Boat* wordsOut = new Boat();
	int jumlah = 0;
	int x = 1;

	if (!isEmpty())
	{
		current = start;
		
		while (current != NULL)
		{
			wordsOut = (current->getName());
			if (param == "show") {
				cout << x << ". "<<setw(14)<<wordsOut->getName()
				<< setw(20)<< wordsOut->getBName()
				<< setw(20) << wordsOut->getLength()
				<< "m"
				<< setw(10) << wordsOut->getDraft()
				<< "m"
				<< setw(10) << wordsOut->getDuration()
				<< " months"
				<< setw(10) << wordsOut->getMoneyToPay() 
				<< " pounds"
				<< setw(13) << wordsOut->getBoatType()
				<< endl;

				x++;
			}
			current = current->getNext();
			jumlah += wordsOut->getLength();
		}
	}

	return jumlah;
}
