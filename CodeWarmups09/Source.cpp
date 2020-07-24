#include <iostream>
#include <string>
using namespace std;


bool isValidHexCode(string str) 
{
	if (str.length() != 7)
		return false;

	if (str[0] != '#')
		return false;

	bool hasLower = false;
	bool hasUpper = false;

	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') {}
		else if (str[i] >= 'A' && str[i] <= 'F')
			hasUpper = true;
		else if (str[i] >= 'a' && str[i] <= 'f')
			hasLower = true;
		else
			return false;
		if (hasUpper & hasLower)
			return false;
	}
	return true;
}


int main()
{
	isValidHexCode("#CD5C5C"); // True
	isValidHexCode("#EAECEE"); // True
	isValidHexCode("#eaecee"); // True
	isValidHexCode("#CD5C58C"); // False
	isValidHexCode("#CD5C5Z"); // false not alphabetical... due to lookup 
	isValidHexCode("#CD5C&C"); // false unacceptable letter
	isValidHexCode("CD5C5C"); // False

	return 0;
}