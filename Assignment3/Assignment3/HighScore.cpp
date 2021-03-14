#include "HighScore.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

//assigns values to the variables 
HighScore::HighScore() {
    this->iStoreScore = 0;
    this->fileAccessed = false;
    this->sfileName = "highScroe.txt";
}

// Creates the map
void HighScore::createMap(map<string, int>& hMap) {
    this->siMapHighScore = hMap;
}

//Used to add the key if it dose not already exist 
void HighScore::createUser(string& name) {

    if (this->siMapHighScore.find(name) == this->siMapHighScore.end()) {
        this->siMapHighScore.insert(make_pair(name, 0));
        this->iStoreScore = 0;
    }
    else {

        auto it = this->siMapHighScore.find(name);
        this->iStoreScore = it->second;
    }

}

// Used to display the high score.  Gets the information from accessfile
void HighScore::displayHighScore() {
   
    map<string, int> highScore = accessFile.AccessFile(sfileName);

    // Then goes's through the for loop for the map
    for (map<string, int>::iterator mIT = highScore.begin(); mIT != highScore.end(); ++mIT)
    {
        cout << mIT->first << " :: " << mIT->second << endl;
    }
}

// used to get the information that is curretnly in the file and put it in the map
void HighScore::accessHighScoreFile()
{
    
    fileAccessed = accessFile.fileExists(sfileName);


    if (fileAccessed) {
        siMapHighScore = accessFile.AccessFile(sfileName);

        fileAccessed = true;
    }
    else {
        accessFile.createFile(this->sfileName);
        fileAccessed = false;
    }

}

//used to update the score of the user
void HighScore::updateHighScore(string& name, int& iScore)
{
    iStoreScore = iScore + iStoreScore;
    siMapHighScore.find(name)->second = iStoreScore;

}

//used to update the file information.
void HighScore::updateFile() {
    
    accessFile.updateFile(sfileName, siMapHighScore);

}