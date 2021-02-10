#include "AccessFile.h"

AccessFile::AccessFile()
{
	this->sFileName = "termsfile.txt";
}



AccessFile::AccessFile(std::string& sFileName)
{
	this->sFileName = sFileName;
}

int AccessFile::countWords()
{
	this->fsOpenFile.open("text.txt");
	int iValue = 1;

	if (this->fsOpenFile.is_open()) {

		while (std::getline(fsOpenFile, sCurrentTerm)) {
			
			iValue++;

		}



	}

	this->fsOpenFile.close();

	return 0;
}



void AccessFile::readFile(TermsArray& termsArray)
{
	
	this->fsOpenFile.open("text.txt");
	
	int iValue = 0;

	if (this->fsOpenFile.is_open()) {

		while (std::getline(fsOpenFile, sCurrentTerm)) {
			
			termsArray.setTerms(iValue, sCurrentTerm);
			iValue ++;
		}



	}

	this->fsOpenFile.close();

}
