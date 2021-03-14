#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

#ifndef LOGGER_H_
#define LOGGER_H_

void fileLog(string);


void fileLog(string sMessage)
{

	ofstream LogFile;

	
	time_t now = time(0);
	
	tm* ltm = localtime(&now);

	string sFileName = "LogFile.log";

	LogFile.open(sFileName, ios::out | ios::app);

	if (LogFile.is_open())
	{

		LogFile << 1 + ltm->tm_mon << ltm->tm_mday << 1900 + ltm->tm_year << ltm->tm_hour << ltm->tm_min << sMessage << '\n';

	}
	else
	{

	}


	LogFile.close();



}


#endif /* LOGGER_H_ */

