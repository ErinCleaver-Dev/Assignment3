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
	
	Hangman(map<string, int>& hMap);
	void startGame(TermsList&,int&);
	void displayHighScore();


};

