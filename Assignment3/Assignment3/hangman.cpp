#include "hangman.h"


Hangman::Hangman(map<string, int>& gMap)
{
	this->incorrectLetterCount = 0;
	this->pointcounter = 0;
	highscore.createMap(gMap);
	highscore.accessHighScoreFile();

}


void Hangman::startGame(TermsList& termsList, int& iPos)
{
	// access's the high score file
	highscore.accessHighScoreFile();

	// Asks the user to give a username
	cout << "Please provided your name: " << endl;
	cin >> sUserName;
	//creates the user if they don't already exist.
	highscore.createUser(sUserName);
	try {

		// used to control the words within the hangman app and gets a terms list.
		wordControler.setTerm(termsList.getSelectedTerm(iPos));
		do {
			cout << wordControler.displayKnowLetters() << endl;

			cout << "Guess a letter for the word" << endl;
			// verifiys that the user provided a char
			char cValue;
			cin >> cValue;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please provide a character\n";
				cin >> cValue;
			}
			cValue = tolower(cValue);
			//gets the guest from the user.
			wordControler.getGuess(cValue);

			//checks to see how many times the user has guested the word
			if (!wordControler.getbWordupdate() && incorrectLetterCount <= 10) {
				cout << "Letter not found" << endl;
				incorrectLetterCount++;
				if (incorrectLetterCount % 3 == 0) {
					cout << hint.giveHint(iPos) << endl;
				}
			}
			else {
				pointcounter++;
			}

		} while (!wordControler.runHangman() && incorrectLetterCount != 10);

		// displays the currently know letters
		cout << wordControler.displayKnowLetters() << endl;
		//checks if the value was equal to or greater then 10
		if (incorrectLetterCount >= 10) {
			cout << "You lose!" << endl;
			//updates the high score
			highscore.updateHighScore(sUserName, pointcounter);
		}
		else {
			cout << "You Win!" << endl;
			pointcounter+= 10;

			//updates the high score
			highscore.updateHighScore(sUserName, pointcounter);
		}
	}
	catch (int e) {
		cout << "An exception has occured.  " << e << '\n';
	}

	//updates the high score file
	highscore.updateFile();
	//clears out word controler
	wordControler.clearOutWord();
	pointcounter = 0;
	incorrectLetterCount = 0;
	

}

// displays the high score to the user.  
void Hangman::displayHighScore()
{
	highscore.accessHighScoreFile();
	highscore.displayHighScore();
}

