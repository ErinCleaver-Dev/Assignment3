#pragma once
#include "wordControler.h"
#include "TermsArray.h"
#include <iostream>

using namespace std;
class Hangman
{
private:  

	WordControler wordControler;

public:
	
	Hangman();
	void startGame(TermsArray&,int&);



};

