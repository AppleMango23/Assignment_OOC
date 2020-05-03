#include "Header.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

//Constructor for Boat
Boat::Boat()
{
	
}

//--------------------------Set and get-----------------------------
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
	next = NULL;    // initialise next
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

//--------------------------Features in system-----------------------------
//In this function it will be adding order ( at end )into the list
void BoatList::addBoatAtEnd(string name, string bName, int bLength , int bDraft, int duration, int moneyToPay, string boatType)
{
	//Declaring some variable and object for usage
	BoatNode* current;
	Boat* boatOne = new Boat();

	//Set all the variable into the class
	boatOne->setName(name);
	boatOne->setBoatName(bName);
	boatOne->setLength(bLength);
	boatOne->setDraft(bDraft);
	boatOne->setDuration(duration);
	boatOne->setMoneyToPay(moneyToPay);
	boatOne->setBoatType(boatType);

	//Allocate memory in start
	if (end == NULL)       // if list is empty
	{
		current = new BoatNode(boatOne);  // allocate memory
		start = current;               // change start 
		end = current;				  // and end
	}
	//Allocate memory in end
	else
	{
		current = new BoatNode(boatOne);   // allocate memory
		end->setNext(current);          // change end's 
		end = current;                  // change end
	}
}

//In this function it will be adding order ( at start )into the list
void BoatList::addBoatAtStart(string name, string bName, int bLength, int bDraft, int duration, int moneyToPay, string boatType)
{
	//Declaring variable
	BoatNode* current;
	Boat* boatOne = new Boat();

	//Set the variable into to class
	boatOne->setName(name);
	boatOne->setBoatName(bName);
	boatOne->setLength(bLength);
	boatOne->setDraft(bDraft);
	boatOne->setDuration(duration);
	boatOne->setMoneyToPay(moneyToPay);
	boatOne->setBoatType(boatType);

	//By doing this the linked list will add at start
	current = new BoatNode(boatOne);   // allocate memory		
	current->setNext(start);          // change end's next
	start = current;                  // change end
}

//This function will take the position given by user and delete it
BoatList* BoatList::removeBoat(int position)
{
	//Declaring
	BoatNode* current;
	Boat* wordsOut = new Boat();
	int counterSet=1;
	BoatList* temptesting = new BoatList(); 
	BoatList* temptesting1 = new BoatList();
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
			wordsOut = (current->getName());

			//This is for the start at front linked list adding
			temptesting1->addBoatAtStart(wordsOut->getName(), wordsOut->getBName(),
				wordsOut->getLength(), wordsOut->getDraft(),
				wordsOut->getDuration(), wordsOut->getMoneyToPay(),
				wordsOut->getBoatType());

			if (counterSet != position)
			{
				//This is to save the new data into the text file
				outFile << wordsOut->getName()
					<< "\n" << wordsOut->getBName()
					<< "\n" << wordsOut->getLength()
					<< "\n" << wordsOut->getDraft() 
					<< "\n" << wordsOut->getDuration()
					<< "\n" << wordsOut->getMoneyToPay()
					<< "\n" << wordsOut->getBoatType()
					<< endl << endl;

				//This is for the start at front linked list adding
				temptesting->addBoatAtEnd(wordsOut->getName(), wordsOut->getBName(),
										wordsOut->getLength(), wordsOut->getDraft(),
										wordsOut->getDuration(),wordsOut->getMoneyToPay(),
										wordsOut->getBoatType());
				
				//Change the indicator to next one
				current = current->getNext();
			}
			else {
				//Make it call next
				current = current->getNext();
			}
			//counter counting
			counterSet++;
		}
	}
	outFile.close();
	cout << endl;
	cout << "These boat had move to holding bay" << endl;
	
	//The given position will be listing based on holding bay
	temptesting1->listAllNames(to_string(position));
	cout << "\nAfter the holding bay boat move back to marina" << endl;

	//The given position will be listing based on marina bay after removed
	temptesting->listAllNames("show");
	cout << "Order number "<< position << " successfully removed. And the boat moved infront to fill the empty space." << endl<<endl;
	return temptesting;
}

//Saving boat function
void BoatList::saveBoat()
{
	//Declaring
	BoatNode* current;
	Boat* wordsOut = new Boat();
	ofstream outFile;  //For write

	//File clearing
	outFile.open("saveFile.txt", std::ofstream::out | std::ofstream::trunc);
	outFile.close();

	//Declaring which file to save
	outFile.open("saveFile.txt", ios::out | ios::app);
	
	//If it is empty then do something
	if (!isEmpty())
	{
		//Set it to the starting point
		current = start;

		//And list out everything
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
		cout <<"<<<<<<<<<<<<<<<<<<<<<< customer saved >>>>>>>>>>>>>>>>>>>>>>" << endl;
	}
	outFile.close();
}

//Reading file function
BoatList* BoatList::readFile()
{
	//Declaring
	Boat* wordsOut = new Boat();
	ifstream inFile;  //For write
	string line2;
	int counter = 0;
	int number;
	BoatList* TempList = new BoatList();
	int totalLength = 0;

	//Setting it into the class from the text file
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

			//Add the boat into end
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

//Listing out all the information from the class
int BoatList::listAllNames(string param)
{
	//Declaring
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

			//To check it want to show or not
			if (param == "show") {
				//Output the information
				cout << setw(2) << x << ". " << setw(14) << wordsOut->getName()
					<< setw(20) << wordsOut->getBName()
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
			}
			x++;
			current = current->getNext();

			//Adding up all the length that used
			jumlah += wordsOut->getLength();

			//If it want quantity then assign the x to the jumlah
			if (param == "quantity") {
				jumlah = x;
			}
		}

		//Checking is it number or alphabet
		if (isalpha(param[0]))
		{
			//not doing anything
		}
		else
		{
			current = start;
			int y = x-1;
			int aa = 1;

			while (current != NULL)
			{
				wordsOut = (current->getName());

				//Output the information
				cout << setw(2) << y << ". " << setw(14) << wordsOut->getName()
				<< setw(20) << wordsOut->getBName()
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
				y--;
				current = current->getNext();

				//Use the position given by user and get out of the while loop if reached the same number
				int num1 = stoi(param);
				if (num1 == y)
				{
					break;
				}
			}

			
		}
	}

	//Returning variable for usage
	return jumlah;
}

