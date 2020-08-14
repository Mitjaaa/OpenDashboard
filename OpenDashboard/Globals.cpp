#include "Globals.h"
#include <vector>

std::string removeLetters(std::string text)
{
	char* tochars = new char[text.length() + 1];
	strcpy(tochars, text.c_str());

	std::string newtext = "";

	for (unsigned int i = 0; i < text.length(); i++) {
		if (isdigit(tochars[i])) {
			newtext += tochars[i];
		}
	}

	return newtext;
}

bool isStrDigit(std::string text)
{
	char* tochars = new char[text.length() + 1];
	strcpy(tochars, text.c_str());

	for (unsigned int i = 0; i < text.length(); i++) {
		if (!isdigit(tochars[i]) && tochars[i] != '.') {
			return false;
		}
	}

	return true;
}

std::vector<std::string> split(std::string stringToBeSplitted, std::string delimeter)
{
	std::vector<std::string> splittedString;
	unsigned int startIndex = 0;
	unsigned int endIndex = 0;
	while ((endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size())
	{
		std::string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
		splittedString.push_back(val);
		startIndex = endIndex + delimeter.size();
	}
	if (startIndex < stringToBeSplitted.size())
	{
		std::string val = stringToBeSplitted.substr(startIndex);
		splittedString.push_back(val);
	}
	return splittedString;
}