#include "Header.h"

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

//Link list
BoatNode::BoatNode()
{
	boatName = NULL;  // default 
	next = NULL;		 // initialise next
}

BoatNode::BoatNode(string name)
{
	boatName = new string(name);  // store name
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
	return boatName;
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

void BoatList::addFirstBoat(string name)
{
	cout << "Adding town " << name << " at start" << endl << endl;
	BoatNode* current;
	current = new BoatNode(name);  // allocate memory
	start = current;               // change start 
	end = current;				  // and end
}

void BoatList::addBoatAtEnd(string name)
{
	cout << "Adding town " << name << " at end" << endl << endl;

	BoatNode* current;

	if (end == NULL)       // if list is empty
		addFirstBoat(name);
	else
	{
		current = new BoatNode(name);   // allocate memory
		end->setNext(current);          // change end's next
		end = current;                  // change end
	}
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

