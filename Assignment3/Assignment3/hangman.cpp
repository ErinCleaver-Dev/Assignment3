#include "hangman.h"


Hangman::Hangman()
{
}

void Hangman::startGame(TermsArray& termsArray, int& iPos)
{

	try {
		wordControler.setTerm(termsArray.getSelectedTerm(iPos));
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

			wordControler.getGuess(cValue);

			if (!wordControler.getbWordupdate()) {
				cout << "Letter not found" << endl;
			}


		} while (!wordControler.runHangman());

		wordControler.~WordControler();
	}
	catch (int e) {
		cout << "An exception has occured.  " << e << '\n';
	}
}
