#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h";
#include <iomanip>

using namespace std;

int main() {
	//Decision that make by user
	int decision=0,decision2;
	BoatList* boatlistNew = new BoatList();

	// Define variable for data to be read from file
	string name,boatName;
	int boatLength,boatDraft, duration, moneyToPay;

	//For delete mode
	int deleteNum;

	cout << "=======Welcome to Marina Bay=======" << endl;
	boatlistNew=boatlistNew->readFile();

	while(decision != 4)
	{
		cout << "What you want to do: " << endl;
		cout << "1. Record a new booking" << endl;
		cout << "2. Delete a record" << endl;
		cout << "3. Display all record (Available marina space)" << endl;
		cout << "4. Exit the program" << endl << endl;
		cout << "Decision: ";
		cin >> decision;

		switch (decision)
		{
			default:
				break;

			case 1:
			{
				cout << endl << "ADD CUSTOMER MODE" << endl;

				if (boatlistNew->listAllNames("return") >= 150) {
					cout<<"Marina is full"<<endl;
				}
				else
				{
					cout << "Please type your boat length: ";
					cin >> boatLength;
					cout << "Please type your boat draft: ";
					cin >> boatDraft;

					if (boatLength <= 15)
					{
						if (boatDraft <= 5)
						{
							cout << "How long is the duration customer want to stay: ";
							cin >> duration;
							moneyToPay = (boatLength * 10) + (duration * 10);

							cout << "10 pounds per meter and per month" << endl;
							cout << "Price = " << moneyToPay << " pounds" << endl << endl;
							cout << "(press 1 say yes, press 2 say no)" << endl;
							cin >> decision2;

							if (decision2 == 1)
							{
								cout<<"Okay you are in!"<< endl << endl;
								cout << "Please owner name: ";
								cin >> name;
								cout << "Please type your boat name: ";
								cin >> boatName;


								if (boatlistNew->listAllNames("return") + boatLength > 150) {
									cout << "The marina is full" << endl;
								}
								else
								{
									boatlistNew->addBoatAtEnd(name, boatName, boatLength, boatDraft, duration, moneyToPay);
									cout << "Congratulations you added 1!" << endl;
								}
							}
						}
						else
						{
							cout << "Sorry your shallow exceeded the maximum." << endl;
						}
					}
					else
					{
						cout << "Sorry your boat length exceeded the maximum length." << endl;
					}
				}
				break;
			}

			case 2:
			{
				cout << endl << "DELETE MODE" << endl;
				cout << "The order u want to delete is:";
				cin >> deleteNum;
				boatlistNew = boatlistNew->temp(boatlistNew, deleteNum);
				break;
			}

			case 3:
			{
				cout << endl << "DISPLAY MODE" << endl;
				cout << "No" << setw(14) << "Owner" << setw(20) << "Boat"
					<< setw(23) << "Length" << setw(14) << "Shallow"
					<< setw(14) << "Duration" << setw(14) << "Cost" << endl;
				boatlistNew->listAllNames("show");
				cout << "\nThe occupied space are: " << boatlistNew->listAllNames("return") << endl;
				cout <<"The available space are: "<<150-boatlistNew->listAllNames("return") << endl;
				break;
			}
		}
		cout << endl;
	}

	boatlistNew->saveBoat();
	cout << "\n=============================================================" << endl;
	cout << "\t\tApplication exited and saved" << endl << endl;
}