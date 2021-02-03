/*Assignment - 2
*Date - 1/31/21
*Name: Erin Cleaver, Sandra Khoury
*Purpose - For user to a pick a word from a fixed set of words
* Class Number: CIS227.6800.W21
*/


using namespace std;
#include "TermsArray.h"

// A constructor for the termsArry class.  It assigns values to ther terms array.  
TermsArray::TermsArray()
{
	this->sTermsArray[0] = "home";
	this->sTermsArray[1] = "Apples";
	this->sTermsArray[2] = "Accurate";
	this->sTermsArray[3] = "trouble";
	this->sTermsArray[4] = "random";
	this->sTermsArray[5] = "tiger";
	this->sTermsArray[6] = "ant";
	this->sTermsArray[7] = "puzzle";
	this->sTermsArray[8] = "apple";
	this->sTermsArray[9] = "blueberries";
	this->sTermsArray[10] = "cookies";
	this->sTermsArray[11] = "pineapple";

}

// Destructors
TermsArray::~TermsArray()
{
}

// Selects the current term
string TermsArray::getSelectedTerm(int &iPos)
{

	return sTermsArray[iPos];

}

// Gets the Size of the Array.  
int TermsArray::getArraySize()
{
	
	return  size(sTermsArray);
}


