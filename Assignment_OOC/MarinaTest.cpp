#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h";
#include <iomanip>

using namespace std;

int main() {
	//Decision that make by user
	int decision = 0, decision2, boatLength, boatDraft, duration, moneyToPay, deleteNum;
	BoatList* boatlistNew = new BoatList();
	string name, boatName, boatType;

	//Output marina name
	cout << "=======Welcome to Marina Bay=======" << endl;

	//This will call the "readFile() function to read the file and show it out"
	boatlistNew = boatlistNew->readFile();

	//If it is not 5 then keep running again and again means if it is 5 it will exit
	while (decision != 5)
	{
		//Output what options you have
		cout << "What you want to do: " << endl;
		cout << "1. Record a new booking" << endl;
		cout << "2. Delete a record" << endl;
		cout << "3. Display all record (Available marina space)" << endl;
		cout << "4. Simulator" << endl;
		cout << "5. Exit the program" << endl << endl;
		cout << "Decision: ";
		
		//Decision on the option that we can choose
		cin >> decision;

		//Switch case on the decision
		switch (decision)
		{
			default:
				break;

			//If we choose number 1 decision
			case 1:
			{
				cout << endl << "ADD CUSTOMER MODE" << endl;

				//By doing this we are able to get the specific return by sending the specific parameter
				if (boatlistNew->listAllNames("return") >= 150) {
					//In this condition it is verifying the marina is full or not
					cout << "I am so sorry the Marina is full" << endl;
				}
				else
				{
					//Input length and draft
					cout << "Please type your boat length: ";
					cin >> boatLength;
					cout << "Please type your boat draft: ";
					cin >> boatDraft;

					//2 if statement to check is it exceeded the limit
					if (boatLength <= 15)
					{
						if (boatDraft <= 5)
						{
							cout << "How long is the duration customer want to stay: ";
							cin >> duration;

							//Formula to calculate the payment
							moneyToPay = (boatLength * 10) + (duration * 10);

							cout << "10 pounds per meter and per month" << endl;
							cout << "Price = " << moneyToPay << " pounds" << endl << endl;
							cout << "(press 1 say yes, press 2 say no)" << endl;
							//Asking the user's decision
							cin >> decision2;

							//If the user decided to accept the price
							if (decision2 == 1)
							{
								cout << "Okay you are in!" << endl << endl;

								//User's information
								cout << "Please owner name: ";
								cin >> name;
								cout << "Please type your boat name: ";
								cin >> boatName;
								cout << "Please enter your boat type(Sailing, Narrow, Motor): ";
								cin >> boatType;

								//Checking is the marina full or not
								if (boatlistNew->listAllNames("return") + boatLength > 150) {
									cout << "I am so sorry the Marina is full" << endl;
								}
								else
								{
									//At the boat to end
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

			//If we choose number 2 decision
			case 2:
			{
				//In this is running the delete function
				cout << endl << "DELETE MODE" << endl;
				boatlistNew->listAllNames("show");
				cout << "The order u want to delete is:";
				cin >> deleteNum;
				boatlistNew = boatlistNew->removeBoat(deleteNum);
				break;
			}

			//If we choose number 3 decision
			case 3:
			{
				//In this is running the display function
				cout << endl << "DISPLAY MODE" << endl;
				
				//Table form for display the information
				cout << "No" << setw(14) << "Owner" << setw(20) << "Boat"
					<< setw(23) << "Length" << setw(14) << "Shallow"
					<< setw(14) << "Duration" << setw(14) << "Cost"
					<< setw(14) << "Type"
					<< endl;
				boatlistNew->listAllNames("show");
				cout << "\nThe occupied space are: " << boatlistNew->listAllNames("return") << endl;
				cout << "The available space are: " << 150 - boatlistNew->listAllNames("return") << endl;
				break;
			}

			//If we choose number 4 decision
			case 4:
			{
				//declaring
				int decision3 = 0;
				int nameRand, boatNameRand, boatTypeRand;

				//This is running the simulator mode
				cout << endl << "SIMULATOR MODE" << endl;

				//In this is running another while loop and it will act same as the case1,case2 and case3
				//All the decision that should be make by user are running random number mode which will decide what to do randomly
				//Other than the random number implementation all the parts are same as case1,2,3.
				while (decision3 != 3)
				{
					//The option only have 3 because if it is simulating no need to show and display
					cout << "What you want to do: " << endl;
					cout << "1. Record a new booking" << endl;
					cout << "2. Delete a record" << endl;
					cout << "3. Exit" << endl;

					//Random number to decide decision
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
							cout << "Please type your boat length: " << boatLength << endl;

							boatDraft = (rand() % 6) + 1;
							cout << "Please type your boat draft: " << boatDraft << endl;

							if (boatLength <= 15)
							{
								if (boatDraft <= 5)
								{
									duration = (rand() % 6) + 1;
									cout << "How long is the duration customer want to stay: " << duration << endl;
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
									cout << "Sorry your shallow exceeded the maximum." << endl << endl;
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
				//Saving parts when we exited simulator mode
				boatlistNew->saveBoat();
				cout << "\n=============================================================" << endl;
				cout << "\t\tSimulator Application exited and saved" << endl << endl;
				break;
			}
			}
			cout << endl;
		}

		//Saving parts when we exited everything
		boatlistNew->saveBoat();
		cout << "\n=============================================================" << endl;
		cout << "\t\tApplication exited and saved" << endl << endl;
}