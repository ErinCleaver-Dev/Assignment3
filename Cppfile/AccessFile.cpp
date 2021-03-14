#include "AccessFile.h"

FileMangement::FileMangement()
{
	this->sFileName;
}



FileMangement::FileMangement(std::string& sFileName)
{
	this->sFileName = sFileName;
}

int FileMangement::countWords()
{
	openFile();
	int iValue = 0;

	if (this->fsOpenFile.is_open()) {

		while (std::getline(fsOpenFile, sCurrentTerm)) {
			
			iValue++;

		}



	}

	this->fsOpenFile.close();

	return iValue;
}



void FileMangement::readFile(TermsList& termsArray)
{
	
	openFile();
	
	int iValue = 0;

	if (bFileOpen) {

		while (std::getline(fsOpenFile, sCurrentTerm)) {
			
			termsArray.setTerms(iValue, sCurrentTerm);
			iValue ++;
		}



	}

	this->fsOpenFile.close();

}

void FileMangement::openFile(std::string& fileName)
{
	this->bFileOpen = false;

	this->sFileName = fileName;
	this->fsOpenFile.open(sFileName);
	if (this->fsOpenFile.is_open()) {
		this->bFileOpen = true;
	}

}



void FileMangement::openFile()
{
	this->sFileName = "termsfile.txt";
	this->fsOpenFile.open(sFileName);
}

void FileMangement::createFile(std::string& createFile)
{
	openFile(createFile);
	if (!bFileOpen) {
		fsOpenFile.open(createFile, std::ios::out | std::ios::app);
		fsOpenFile.close();
	}
}

void FileMangement::updateFile(std::string& openFile, map<std::string, int>& mValue)
{
	ofstream newFile(openFile);
	if (newFile.good()) {
		for (map<string, int>::iterator mFile = mValue.begin(); mFile != mValue.end(); ++mFile) {
			cout << mFile->first << ":" << mFile->second << "\n";
			newFile << mFile->first << ":" << mFile->second << "\n";
		}
	}
	newFile.close();
}

bool FileMangement::fileExists(std::string& sFilename)
{
	openFile(sFileName);
	return bFileOpen;
}



map<std::string, int> FileMangement::AccessFile()
{
	openFile();
	map<std::string, int> mFile;
	std::string sKey;
	int iValue;
	if (bFileOpen){

		while (fsOpenFile >> sKey >> iValue) {
			mFile[sKey] = iValue;
		}
	}
	fsOpenFile.close();

	for (map<string, int>::iterator mIT = mFile.begin(); mIT != mFile.end(); ++mIT)
	{
		cout << mIT->first << " : " << mIT->second << endl;
	}

	return mFile;
}



