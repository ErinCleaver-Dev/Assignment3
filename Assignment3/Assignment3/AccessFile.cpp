#include "AccessFile.h"

AccessFile::AccessFile()
{
	this->sFileName = "termsfile.txt";
}

AccessFile::AccessFile(std::string& sFileName)
{
	this->sFileName = sFileName;
}

void AccessFile::readFile(TermsArray& termsArray)
{
	
	this->fsOpenFile.open("text.txt");
	

	if (this->fsOpenFile.is_open()) {

		while (std::getline(fsOpenFile, sCurrentTerm)) {
			int iValue = 0;

			termsArray.setTerms(iValue, sCurrentTerm);
			
		}



	}

	this->fsOpenFile.close();

}
