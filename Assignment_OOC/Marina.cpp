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
	////This one is for the no linked list der output
	//BoatNode* current;
	//Boat* dustbin = new Boat();
	//
	//ofstream outFile;  //For write
	//
	//int x = 0;

	////For saving
	//outFile.open("saveFile.txt", ios::out | ios::app);

	//cout << dustbin->getBName();
	//
	//outFile.close();

	//Experiment
	//This one is for the no linked list der output
	BoatNode* current;
	Boat* wordsOut = new Boat();
	Boat* wordsOut2 = new Boat();
	BoatList* tempTest = new BoatList();
	ifstream inFile;  //For write
	string line2;
	int counter = 0;
	int counterSet = 0;

	inFile.open("saveFile.txt", ios::out | ios::app);
	while (getline(inFile, line2)) {
		counter++;
		if (counter == 1) {
			wordsOut->setName(line2);
		}
		if (counter == 2) {
			wordsOut->setBoatName(line2);
		}
		if (counter == 3) {
			wordsOut->setLength(std::stoi(line2));
		}
		if (counter == 4) {
			wordsOut->setDraft(std::stoi(line2));
			counterSet++;
			if (counterSet != position) {
				//Start
				if (end == NULL)       // if list is empty
				{
					current = new BoatNode(wordsOut);  // allocate memory
					start = current;               // change start 
					end = current;				  // and end
					tempTest->temp(wordsOut);
				}
				//end
				else
				{
					current = new BoatNode(wordsOut);   // allocate memory
					start->setNext(current);          // change end's 
					//end->setPre(current);
					end = current;                  // change end
					tempTest->temp(wordsOut);
				}
			}
			else {

			}
			
		}
		if (counter == 5)
		{
			counter = 0;
		}


	}

	inFile.close();



	

	
}

void BoatList::temp(Boat* wordsOut)
{
	//This one is working can see this
	//cout<<"HERE"<<wordsOut->getName();
	//int delNum = 1;
	//BoatNode* current1=start;

	//Should be listing out
	/*if (!isEmpty())
	{
		current1 = start;
		while (current1 != NULL)
		{
			delNum = delNum + 1;*/
			//if (delNum == position)
			//{
			//	wordsOut = (current->getName());

			//	//output
			//	wordsOut2->setName(wordsOut->getName());
			//	wordsOut2->setBoatName(wordsOut->getBName());
			//	wordsOut2->setLength(wordsOut->getLength());
			//	wordsOut2->setDraft(wordsOut->getDraft());

			//	current = current->getNext();
			//}
			//else
			//{
			//wordsOut = (current1->getName());
			cout << wordsOut->getName()
				<< "\t" << wordsOut->getBName()
				<< "\t" << wordsOut->getLength()
				<< "\t" << wordsOut->getDraft() << endl;
			//current1 = current1->getNext();
			/*}*/
		/*}
	}*/

}

void BoatList::saveBoat()
{
	//This one is for the no linked list der output
	BoatNode* current;
	Boat* wordsOut = new Boat();
	ofstream outFile;  //For write
	int x = 0;

	outFile.open("saveFile.txt", ios::out | ios::app);

	if (!isEmpty())
	{
		current = start;
		while (current != NULL)
		{
			wordsOut = (current->getName());
			outFile << wordsOut->getName() 
				<< "\t" << wordsOut->getBName()
				<< "\t" << wordsOut->getLength() 
				<< "\t" << wordsOut->getDraft() << "\n" << endl;
			current = current->getNext();
			x++;
		}
		cout <<"======="<< x << " customer saved=======" << endl;
	}
	outFile.close();
}

void BoatList::searchInfo(string line2)
{
	//Out of topic i think, delete need to be delete due to the linked list

	ifstream inFile;
	int lineNumber=0;
	string searchName,FoundLine;

	cout << "\nSearch name owner: ";
	cin >> searchName;

	while (getline(inFile, line2)) {
		istringstream iss(line2);
		if (line2.find(searchName) != std::string::npos) {
			lineNumber+=1;
			cout << "\nStatus: Found!" << '\n';
			FoundLine = line2;
			break;
		}
		else {
				
			lineNumber +=1;
		}
	}
	if (FoundLine == "")
	{
		cout << "Cant Find the name" << endl;
	}
	else {
		cout << "Line number: " << lineNumber << endl;
		cout << "Found line: " << FoundLine << endl;
	}	
}

void BoatList::listAllNames()
{
	//This one is for the no linked list der output
	BoatNode* current;
	Boat* wordsOut = new Boat();
	ifstream inFile;  //For write
	string line2;
	int counter = 0;

	inFile.open("saveFile.txt", ios::out | ios::app);
	while (getline(inFile, line2)) {
		counter++;
		if(counter == 1){
			wordsOut->setName(line2);
			cout << wordsOut->getName();
		}
		if (counter == 2) {
			wordsOut->setBoatName(line2);
			cout << wordsOut->getBName();
		}
		if (counter == 3) {
			wordsOut->setLength(std::stoi(line2));
			cout << wordsOut->getLength();
		}
		if (counter == 4) {
			wordsOut->setDraft(std::stoi(line2));
			cout << wordsOut->getDraft();

			//Start
			if (end == NULL)       // if list is empty
			{
				current = new BoatNode(wordsOut);  // allocate memory
				start = current;               // change start 
				end = current;				  // and end
				cout << endl;
			}
			//end
			else
			{
				current = new BoatNode(wordsOut);   // allocate memory
				end->setNext(current);          // change end's 
				end = current;                  // change end
				cout << endl;
			}
		}
		if(counter == 5) 
		{
			counter = 0;
		}


	}
		
	inFile.close();

}

