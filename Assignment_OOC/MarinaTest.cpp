#include<iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
	int decision = 0;

	// Create object file pointer for reading
	ifstream inFile;   //For read
	ofstream outFile;  //For write

	// Define variable for data to be read from file
	string line;
	

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
				// Connect to file for reading
				outFile.open("saveFile.txt",ios::app);

				if (outFile.is_open() == false)
					cout << "Error opening file\n" << endl;
				else
				{
					cout << "Please type something to save something tq." << endl;
					cin.ignore();
					getline(cin, line);
					outFile << line << '\n';
				}

				outFile.close();

				break;
			}

			case 2:
			{
				cout << endl << "Case 2" << endl;
				break;
			}
		}
		cout << endl;
	}

	cout << "\n-----------------" << endl;
	cout << "Application exited" << endl << endl;
}