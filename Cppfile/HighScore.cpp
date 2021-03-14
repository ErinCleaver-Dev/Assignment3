#include "HighScore.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;


HighScore::HighScore() {
    this->iStoreScore = 0;
    this->fileAccessed = false;
    this->sfileName = "highScroe.txt";
}

void HighScore::createMap(map<string, int>& hMap) {
    this->siMapHighScore = hMap;
}

void HighScore::createUser(string& name) {
  
    if (this->siMapHighScore.find(name) == this->siMapHighScore.end()) {
        this->siMapHighScore.insert(make_pair(name, 0));
    }
    else {
        
        auto it = this->siMapHighScore.find(name);
        this->iStoreScore = it->second;
    }
  
}



void HighScore::displayHighScore() {
    map<string, int>::iterator siMapScoreIterator = siMapHighScore.begin();
    
    if (fileAccessed) {
        while (siMapScoreIterator != siMapHighScore.end())
        {
            cout << siMapScoreIterator->first << " :: " << siMapScoreIterator->second << endl;
            siMapScoreIterator++;

        }
    }
    else {
        cout << "No file found";
    }

}
void HighScore::accessHighScoreFile()
{
    
    fileAccessed = accessFile.fileExists(this->sfileName);

    cout << fileAccessed << endl;

    if (fileAccessed) {
        siMapHighScore = accessFile.AccessFile();
        cout << "test: FileExists" << endl;
    }
    else {
        accessFile.createFile(this->sfileName);
        fileAccessed = false;
    }

}
void HighScore::updateHighScore(string& name, int& iScore)
{
    iStoreScore = iScore + iStoreScore;

    map<string, int>::iterator siMapScoreIterator = siMapHighScore.find(name);
    cout << siMapScoreIterator->second << endl;
    siMapHighScore[name] = iStoreScore;
}

void HighScore::updateFile() {
    
    accessFile.updateFile(sfileName, siMapHighScore);

}