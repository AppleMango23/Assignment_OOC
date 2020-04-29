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
	string name,boatName,boatType;
	int boatLength,boatDraft, duration, moneyToPay;

	//For delete mode
	int deleteNum;

	cout << "=======Welcome to Marina Bay=======" << endl;
	boatlistNew=boatlistNew->readFile();

	while(decision != 5)
	{
		cout << "What you want to do: " << endl;
		cout << "1. Record a new booking" << endl;
		cout << "2. Delete a record" << endl;
		cout << "3. Display all record (Available marina space)" << endl;
		cout << "4. Simulator" << endl;
		cout << "5. Exit the program" << endl << endl;
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
					cout<<"I am so sorry the Marina is full"<<endl;
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
								cout << "Please enter your boat type(Sailing, Narrow, Motor): ";
								cin >> boatType;

								if (boatlistNew->listAllNames("return") + boatLength > 150) {
									cout << "I am so sorry the Marina is full" << endl;
								}
								else
								{
									boatlistNew->addBoatAtEnd(name, boatName, boatLength, boatDraft, duration, moneyToPay, boatType);
									cout << "Congratulations you added 1!" << endl <<endl;
								}
							}
							else
							{
								cout << "Order rejected." << endl << endl;
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
				boatlistNew = boatlistNew->removeBoat(deleteNum);
				break;
			}

			case 3:
			{
				cout << endl << "DISPLAY MODE" << endl;
				cout << "No" << setw(14) << "Owner" << setw(20) << "Boat"
					<< setw(23) << "Length" << setw(14) << "Shallow"
					<< setw(14) << "Duration" << setw(14) << "Cost" 
					<< setw(14) << "Type"
					<< endl;
				boatlistNew->listAllNames("show");
				cout << "\nThe occupied space are: " << boatlistNew->listAllNames("return") << endl;
				cout <<"The available space are: "<<150-boatlistNew->listAllNames("return") << endl;
				break;
			}

			case 4:
			{
				cout << endl << "SIMULATOR MODE" << endl;

				int decision3 = 0;
				int nameRand, boatNameRand, boatTypeRand;

				while (decision3 != 3)
				{
					cout << "What you want to do: " << endl;
					cout << "1. Record a new booking" << endl;
					cout << "2. Delete a record" << endl;
					cout << "3. Exit" << endl;

					//Decision on 1 only selection 
					decision3 = (rand() % 3) + 1;
					cout << "decision: " << decision3 << endl;

					switch (decision3)
					{
						default:
							break;

						case 1:
						{
							cout << endl << "ADD CUSTOMER MODE" << endl;

							if (boatlistNew->listAllNames("return") >= 150) {
								cout << "I am so sorry the Marina is full" << endl << endl;
							}
							else
							{
								boatLength = (rand() % 16) + 1;
								cout << "Please type your boat length: "<< boatLength << endl;

								boatDraft = (rand() % 6) + 1;
								cout << "Please type your boat draft: " << boatDraft << endl;

								if (boatLength <= 15)
								{
									if (boatDraft <= 5)
									{
										duration = (rand() % 6) + 1;
										cout << "How long is the duration customer want to stay: " << duration <<endl;
										moneyToPay = (boatLength * 10) + (duration * 10);
										cout << "10 pounds per meter and per month" << endl;
										cout << "Price = " << moneyToPay << " pounds" << endl << endl;
										decision2 = (rand() % 2) + 1;
										cout << "(press 1 say yes, press 2 say no)" << endl;
										cout << decision2 << endl;
										if (decision2 == 1)
										{
											cout << "Okay you are in!" << endl << endl;
											nameRand = (rand() % 2) + 1;
											if (nameRand == 1)
											{
												name = "Noah";
											}
											else {
												if (nameRand == 2)
												{
													name = "John";
												}
												else
												{
													name = "Mandy";
												}
											}
											cout << "Please owner name: " << name << endl;

											boatNameRand = (rand() % 2) + 1;
											if (boatNameRand == 1)
											{
												boatName = "BabyCool";
											}
											else {
												if (boatNameRand == 2)
												{
													boatName = "Titanic";
												}
												else
												{
													boatName = "Jacaobo";
												}
											}
											cout << "Please type your boat name: " << boatName << endl;

											boatTypeRand = (rand() % 2) + 1;
											if (boatTypeRand == 1)
											{
												boatType = "Sailing";
											}
											else {
												if (boatTypeRand == 2)
												{
													boatType = "Narrow";
												}
												else
												{
													boatType = "Motor";
												}
											}
											cout << "Please enter your boat type(Sailing, Narrow, Motor): " << boatType << endl;

											if (boatlistNew->listAllNames("return") + boatLength > 150) {
												cout << "I am so sorry the Marina is full" << endl << endl;
											}
											else
											{
												boatlistNew->addBoatAtEnd(name, boatName, boatLength, boatDraft, duration, moneyToPay, boatType);
												cout << "Congratulations you added 1!" << endl << endl;
											}
										}
										else
										{
											cout << "Order rejected." << endl << endl;
										}
									}
									else
									{
										cout << "Sorry your shallow exceeded the maximum." << endl <<endl;
									}
								}
								else
								{
									cout << "Sorry your boat length exceeded the maximum length." << endl << endl;
								}
							}
							break;
						}

						case 2:
						{
							cout << endl << "DELETE MODE" << endl;
							deleteNum = (rand() % boatlistNew->listAllNames("quantity")) + 1;
							cout << "The order u want to delete is:" << deleteNum << endl;
							boatlistNew = boatlistNew->removeBoat(deleteNum);
							break;
						}
						cout << endl;
					}
				}
				//Saving parts
				boatlistNew->saveBoat();
				cout << "\n=============================================================" << endl;
				cout << "\t\tSimulator Application exited and saved" << endl << endl;
				break;
			}
		}
		cout << endl;
	}

	boatlistNew->saveBoat();
	cout << "\n=============================================================" << endl;
	cout << "\t\tApplication exited and saved" << endl << endl;
}