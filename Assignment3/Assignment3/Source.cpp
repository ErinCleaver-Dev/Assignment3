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
#include <fstream>
#include "AccessFile.h"
#include "hangman.h"




//namespace declaration
using namespace std;

//function definition section
int valInput();
void displayMenu();
//vector<char> getWord(int, TermsArray &arr);
//vector<char> getUpdatedVector(char,vector<char>);


int main(int argc, char* argv[]) {
	//inputs
	int count = 0;
	int iFirstValue;
	char stopApp = 'N', ans;
	//string fileWord;
	//AccessFile file;//access textfile
	TermsArray termsArray;//get class with array
	TermsArray termsFromfile(12);
	//Hangman hangman;


	//file.readFile();
	//cin >> userGuess;
	//file.findWord(userGuess);

	
	do {
		displayMenu();//get the welcome message/ while switch
		cin >> ans;
		switch (ans)
		{
		case '0':
			cout << "Pleasse select a number between 1 to 12.\n";
			//A for loop for displaying the terms
			//iFirstValue = valInput() - 1;
			
			//hangman.startGame(termsArray, iFirstValue);

			break;

		case '1'://File
			cout << "Please pick a word from file below\n";
			iFirstValue = valInput() - 1;

			//file.readFile(termsFromfile);
			
			//hangman.startGame(termsFromfile, iFirstValue);
			break;
		case '2':
			stopApp = 'N';//stop the app
			break;

		default:
			cout << "Well...\n";//In case of user error
			break;
		}
		
		if (ans == '0' || ans == '1' || ans != '2') {
			cout << "Would you like to continue? Enter y for yes, anything else for no.\n";
			cin >> stopApp;
		}
		
	} while (toupper(stopApp) == 'Y');

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
void displayMenu() {
	cout << "~Welcome Human user~" << endl;
	cout << "Please select an option\n";
	cout << "0: Pick word from list\n";
	cout << "1: Pick word from file\n";
	cout << "2: Exit program\n";

	
}
/*vector<char> getWord(int a, TermsArray &arr) {
	string s= arr.getSelectedTerm(a);
	

	vector<char> v(s.begin(), s.end());

	//for (const char &c : v)
		//std::cout << c;
	//for (int i = 0; i < v.size(); i++) {
		//cout << v[i] << endl;

	//}
	return v;
}
*/

/*vector<char> getUpdatedVector(char s, vector<char> v){
	vector <char> k;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != s) {
			k.push_back(v[i]);
		}
	}

	return k;
}
*/

