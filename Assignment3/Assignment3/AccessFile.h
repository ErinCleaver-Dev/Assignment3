#pragma once
#include <fstream>
#include <string>
#include "TermsArray.h"

using namespace std;
class AccessFile
{
private: 

	fstream fsOpenFile;
	string sFileName;
	string sCurrentTerm;
public:
	//A override that assigns the name of the file.

	AccessFile();

	//A override that gets the name of the file.
	AccessFile(std::string&);
	
	int countWords();

	// Reads the Array of terms 
	void readFile(TermsArray&);
	


};

