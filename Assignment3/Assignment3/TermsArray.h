/*Assignment - 2
*Date - 1/31/21
*Name: Erin Cleaver, Sandra Khoury
*Purpose - For user to a pick a word from a fixed set of words
* Class Number: CIS227.6800.W21
*/

#pragma once
#include <string>
using namespace std;
class TermsArray
{
private:

	string sTermsArray[12];

public:

	// constructors 
	TermsArray();
	// Destructors
	~TermsArray();

	// Selects the current term
	string getSelectedTerm(int&);

	// Gets the Size of the Array.  
	int getArraySize();

};


