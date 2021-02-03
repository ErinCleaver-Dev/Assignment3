/*Assignment - 2
*Date - 1/31/21
*Name: Erin Cleaver, Sandra Khoury
*Purpose - For user to a pick a word from a fixed set of words
* Class Number: CIS227.6800.W21
*/


//include section
#include <iostream>
#include <string>
#include <iomanip> // to access setw()
#include "TermsArray.h"

//namespace declaration
using namespace std;

//function definition section
int valInput();
void displayMenu(TermsArray& termsArray);

int main(int argc, char* argv[]) {
	//inputs
	int iFirstValue;
	char cCtopApp = 'N', ans;
	TermsArray termsArray;//get class with array

	{
		cout << "The name used to start the program: " << argv[0]<< "\n";//display arguments
		for (int iN = 1; iN < argc; iN++)
			cout << setw(2) << " " << argv[iN] << '\n';
		
	}

	
	
	do {
		displayMenu(termsArray);//get the welcome message

		cout << "Do you wish to play? Enter y if yes.\n";
		cin >> ans;
		while (toupper(ans) == 'Y') {
			cout << "Please pick a word you would like to display:\n";
			cout << "Remember you can only pick numbers 1-12 from the list.\n";

			iFirstValue = valInput();//call function to validate number
			iFirstValue -= 1;// -1 to get index position of array

			cout << iFirstValue + 1 << ": "<< termsArray.getSelectedTerm(iFirstValue) << endl;//output the word selected
			break;
		}
		if (toupper(ans) == 'Y') { 
			cout << "Would you like to continue? Enter y for yes, anything else for no.\n";
			cin >> cCtopApp;
		}
	}while(toupper(cCtopApp) == 'Y');

	return 0;
}

int valInput() {// If cin fails or if number is not 1-12, force user to reinput

	int iValue;
	cin >> iValue;
	while (cin.fail() || iValue > 12 || iValue < 1) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Nice try... But please pick a number 1-12!\n";
		cin >> iValue;
	}
	return iValue;//return required value
}
void displayMenu(TermsArray &termsArray) {
	cout <<"~Welcome Human user~" << endl;

	//A for loop for displaying the terms
	for (int iCount = 0; iCount < termsArray.getArraySize(); iCount++) {
		int iDisplayNumber = iCount + 1;
		cout << iDisplayNumber << ". " << termsArray.getSelectedTerm(iCount) << endl; ;
	}
}
