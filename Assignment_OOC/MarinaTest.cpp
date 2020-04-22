#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h";

using namespace std;

int main() {
	int decision = 0;
	BoatList* boatlistNew = new BoatList();

	// Create object file pointer for reading
	ifstream inFile;   //For read
	ofstream outFile;  //For write

	// Define variable for data to be read from file
	string name,boatName,line;
	int boatLength,boatDraft,x=1;
	string searchName;
	int lineNumber = 0;
	string line2;
	string FoundLine = "";
	

	cout << "=======Welcome to Marina Bay=======" << endl;
	while(decision != 4)
	{
		cout << "What you want to do: " << endl;
		cout << "1. Record a new booking" << endl;
		cout << "2. Delete a record" << endl;
		cout << "3. Display all record and available marina space" << endl;
		cout << "4. Exit the program" << endl << endl;
		cout << "Decision: ";
		cin >> decision;

		switch (decision)
		{
			default:
				break;

			case 1:
			{
				cout << endl << "Case 1" << endl;
				//--------------------Connect to file for reading---------------
				outFile.open("saveFile.txt",ios::out | ios::binary | ios::app);

				//Checking is it open correctly and is the file existed or not
				if (outFile.is_open() == false)
					cout << "Error opening file\n" << endl;
				else
				{
					//cin.ignore();
					//getline(cin, line);
					cout << "Please owner name: ";
					cin >> name;
					cout << "Please type your boat name: ";
					cin >> boatName;
					cout << "Please type your boat length: ";
					cin >> boatLength;
					cout << "Please type your boat draft: ";
					cin >> boatDraft;

					//Inserting the input into linked list
					boatlistNew->addBoatAtEnd(name, boatName,boatLength,boatDraft);

					
				}
				outFile.close();
				break;
			}

			case 2:
			{
				cout << endl << "Case 2" << endl;
				boatlistNew->removeBoat(2);

				break;
				
			}

			case 3:
			{
				boatlistNew->listAllNames();



				//FoundLine = "";
				//lineNumber = 0;


				//// Connect to file for reading
				//inFile.open("saveFile.txt");

				//if (inFile.is_open() == false)
				//	cout << "Error opening file\n" << endl;
				//else
				//{
				//	cout << "==================The list of the customer information==================" << endl;
				//	//cin.ignore();

				//	//This one will search the whole thing
				//	//getline(inFile, line, (char)inFile.eof());

				//	while (getline(inFile, line2)) {
				//		istringstream iss(line2);
				//		cout << line2 << endl;
				//	}
				//	inFile.clear();                 // clear fail and eof bits
				//	inFile.seekg(0, std::ios::beg); // back to the start!

				//	cout << "\nSearch name owner: ";
				//	cin >> searchName;

				//	while (getline(inFile, line2)) {
				//		istringstream iss(line2);
				//		if (line2.find(searchName) != std::string::npos) {
				//			lineNumber+=1;
				//			cout << "\nStatus: Found!" << '\n';
				//			FoundLine = line2;
				//			break;
				//		}
				//		else {
				//			
				//			lineNumber +=1;
				//		}
				//	}
				//	if (FoundLine == "")
				//	{
				//		cout << "Cant Find the name" << endl;
				//	}
				//	else {
				//		cout << "Line number: " << lineNumber << endl;
				//		cout << "Found line: " << FoundLine << endl;
				//	}	

				//	/*delete boatOne
				//	Boat* boatRead = new Boat();*/

				//	/*cout << "A city -> ";
				//	inFile.read((char*)boatOne, sizeof(Boat));
				//	cout << boatOne->getName() << endl;*/
				//}
				//inFile.close();
				break;
			}
		}
		cout << endl;
	}

	boatlistNew->saveBoat();
	cout << "\n=============================================================" << endl;
	cout << "\t\tApplication exited" << endl << endl;
}