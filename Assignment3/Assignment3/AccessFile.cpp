#include "AccessFile.h"

//A override that assigns the name of the file.
FileMangement::FileMangement()
{
	this->sFileName;
}


//A override that assigns the name of the file.
FileMangement::FileMangement(std::string& sFileName)
{
	this->sFileName = sFileName;
}

//counts number of words in the file
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


// Reads the Array of terms 
void FileMangement::readFile(TermsList& termsArray)
{
	
	openFile();
	
	int iValue = 0;

	if (this->fsOpenFile.is_open()) {

		while (std::getline(fsOpenFile, sCurrentTerm)) {
			termsArray.setTerms(iValue, sCurrentTerm);
			iValue ++;
		}

	}

	this->fsOpenFile.close();

}

//Use to open files in gernal 
void FileMangement::openFile(std::string& fileName)
{
	this->bFileOpen = false;

	this->sFileName = fileName;
	this->fsOpenFile.open(sFileName);
	if (this->fsOpenFile.is_open()) {
		this->bFileOpen = true;
	}

}


//Use to open files in gernal 
void FileMangement::openFile()
{
	this->sFileName = "termsfile.txt";
	this->bFileOpen = true;
	this->fsOpenFile.open(sFileName);
}

//Use to create files
void FileMangement::createFile(std::string& createFile)
{
	openFile(createFile);
	// Verifiys that the file was not already created and then creates the file
	if (!bFileOpen) {
		fsOpenFile.open(createFile, std::ios::out | std::ios::app);
		fsOpenFile.close();
	}
}

//Used to modifiy existing files by getting the map for high score and the the file name.
void FileMangement::updateFile(std::string& openFile, map<std::string, int>& mValue)
{
	newFile.open(openFile, ios::app);
	//checks to make sure hte file is open
	if (newFile.good()) {
		//getts the information from the map and places it in the file.
		for (map<string, int>::iterator mFile = mValue.begin(); mFile != mValue.end(); ++mFile) {
			newFile << mFile->first << "\n" << mFile->second << "\n";
		}
	}

	newFile.close();
}

//used to check to see if the file exists 
bool FileMangement::fileExists(std::string& sFilename)
{
	this->fsOpenFile.open(sFileName);
	if (this->fsOpenFile.is_open()) {
		bFileOpen = true;
	}
	fsOpenFile.close();
	return bFileOpen;
}

//access the file and feeds the information into high score.
map<std::string, int> FileMangement::AccessFile(string sFilename)
{
	openFile(sFileName);

	
	map<std::string, int> mFile;
	std::string sline;
	std::string sKey;
	int iValue;
	if (bFileOpen){
		//gets the information from the file
		while (getline(fsOpenFile, sline)) {
			sKey = sline;
			getline(fsOpenFile, sline);
			iValue = stoi(sline);
			mFile.insert(make_pair(sKey, iValue));
		}
		fsOpenFile.close();
		openFile(sFileName);
		//make sure that the map only has the highscores from the file
		while (getline(fsOpenFile, sline)) {
			sKey = sline;
			getline(fsOpenFile, sline);
			iValue = stoi(sline);
			if (mFile.find(sKey)->second < iValue) {
				mFile.find(sKey)->second = iValue;
			}
		}
	}
	fsOpenFile.close();

	return mFile;
}



