#pragma once
#include "wordControler.h"
#include "TermsList.h"
#include "Hint.h"
#include "HighScore.h"
#include <iostream>

using namespace std;
class Hangman
{
private:  
	int incorrectLetterCount;  
	int pointcounter;
	WordControler wordControler;
	string sUserName = "";
	Hint hint;
	HighScore highscore;
public:
	// gets the map for the highscore
	Hangman(map<string, int>&);
	//starts up the game
	void startGame(TermsList&,int&);
	//used to display the highscore
	void displayHighScore();


};

