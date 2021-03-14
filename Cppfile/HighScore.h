#pragma once
#include <string>
#include <map>
#include <iostream>
#include "AccessFile.h"
using namespace std;


class HighScore
{
private:
	map<string, int> siMapHighScore;
	bool fileAccessed;
	FileMangement accessFile;
	int iStoreScore;
	string sfileName;
public:
	HighScore(map<string, int>& hMap);
	HighScore();
	void accessHighScoreFile();
	void createUser(string&);
	void displayHighScore();
	void updateHighScore(string&, int&);
	void updateFile();
	void createMap(map<string, int>& hMap);
};

