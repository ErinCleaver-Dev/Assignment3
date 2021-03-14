#include "hangman.h"


Hangman::Hangman(map<string, int>& hMap)
{
	this->incorrectLetterCount = 0;
	this->pointcounter = 0;
	this->highscore.createMap(hMap);
}


void Hangman::startGame(TermsList& termsList, int& iPos)
{
	
	cout << "Please provided your name: " << endl;
	cin >> sUserName;
	highscore.accessHighScoreFile();
	highscore.createUser(sUserName);
	
	try {
		wordControler.setTerm(termsList.getSelectedTerm(iPos));
		do {
			cout << wordControler.displayKnowLetters() << endl;

			cout << "Guess a letter for the word" << endl;
			char cValue;
			cin >> cValue;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please provide a character\n";
				cin >> cValue;
			}
			cValue = tolower(cValue);
			wordControler.getGuess(cValue);

			if (!wordControler.getbWordupdate() && incorrectLetterCount <= 10) {
				cout << "Letter not found" << endl;
				incorrectLetterCount++;
				if (incorrectLetterCount % 3) {
					cout << hint.giveHint(iPos) << endl;
				}
			}
			else {
				pointcounter++;
			}

		} while (!wordControler.runHangman() && incorrectLetterCount != 10);
		cout << wordControler.displayKnowLetters() << endl;
		if (incorrectLetterCount >= 10) {
			cout << "You lose!" << endl;
			highscore.updateHighScore(sUserName, pointcounter);
			highscore.updateFile();
			wordControler.clearOutWord();
			pointcounter = 0;
			incorrectLetterCount = 0;
		}
		else {
			cout << "You Win!" << endl;
			pointcounter+= 10;
			highscore.updateHighScore(sUserName, pointcounter);
			highscore.updateFile();
			wordControler.clearOutWord();
			pointcounter = 0;
			incorrectLetterCount = 0;
		}

	}
	catch (int e) {
		cout << "An exception has occured.  " << e << '\n';
	}

}

void Hangman::displayHighScore()
{
	highscore.accessHighScoreFile();
	highscore.displayHighScore();
}

