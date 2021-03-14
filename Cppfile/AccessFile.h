#pragma once
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include "TermsList.h"

using namespace std;
class FileMangement
{
private: 

	fstream fsOpenFile;
	
	
	string sFileName;
	string sCurrentTerm;
	bool bFileOpen;
	
	void openFile(std::string&);
	void openFile();


public:
	//A override that assigns the name of the file.

	FileMangement();

	//A override that gets the name of the file.
	FileMangement(std::string&);
	

	int countWords();

	// Reads the Array of terms 
	void readFile(TermsList&);
	
	void createFile(std::string& createFile);
	void updateFile(std::string&, map<string, int>&);
	bool fileExists(std::string& sFilename);

	map<std::string, int> AccessFile();

};

