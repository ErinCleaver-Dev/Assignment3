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
#include "TermsList.h"
#include <fstream>
#include "AccessFile.h"
#include "hangman.h"
#include "HighScore.h"



//namespace declaration
using namespace std;

//function definition section
int valInput();
int valInput(int iCount);
void displayMenu();
bool test = true;
//vector<char> getWord(int, TermsArray &arr);
//vector<char> getUpdatedVector(char,vector<char>);


int main(int argc, char* argv[]) {
	//inputs
	int count = 0;
	int iFirstValue;
	char stopApp = 'N', ans;
	string fileWord;
	FileMangement file;//access textfile
	TermsList termsFromfile(file.countWords());
	TermsList termsArray;//get class with array
	map<string, int> siMapHighScore;
	Hangman hangman(siMapHighScore);


	do {
		displayMenu();//get the welcome message/ while switch
		cin >> ans;
		switch (ans)
		{
		case '0':
			cout << "Pleasse select a number between 1 to 12 to select a word to guess.\n";
			
			iFirstValue = valInput() - 1;
			
			hangman.startGame(termsArray, iFirstValue);

			break;

		case '1'://File
			cout << "Pleasse select a number between 1 to " << file.countWords() << " to select a word to guess.\n";
			iFirstValue = valInput(file.countWords()) - 1;

			file.readFile(termsFromfile);
			
			hangman.startGame(termsFromfile, iFirstValue);
			break;
		case '2': //Display highscore
			hangman.displayHighScore();
		case '3': //File
			stopApp = 'Y';//stop the app
			break;

		default:
			cout << "Well...\n";//In case of user error
			break;
		}
		
		if (ans == 'y' || ans == '1' || ans == '2' || ans != '3') {
			do {
				cout << "Would you like to continue? Enter y for yes, type n for exit.\n";

				cin >> stopApp;
				stopApp = toupper(stopApp);
				cout << stopApp << endl;
				if (stopApp == 'Y' || stopApp == 'N')
				{
					test = false;
				}


			} while (test);
		}
		
	} while (stopApp != 'N');

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

int valInput(int iCount) {// If cin fails or if number is not 1-12, force user to reinput

	int iValue;
	cin >> iValue;
	while (cin.fail() || iValue > iCount || iValue < 1) {
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
	cout << "2: Would you like to display the high score?\n";
	cout << "3: Exit program\n";

	
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

