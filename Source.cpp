/*
This program takes all the unique characters of a string and places them into an unordered map.
Afterwards, a second string is inspected to see how many characters it possesses that are part of
the unique characters of the first string.
*/

#include <iostream>
#include <unordered_map>

int main()
{
	std::unordered_map<char, int> theMap;
	std::string firstString = "tipos";
	std::string secondString = "magicschoolbus";


	for (int count = 0; count < firstString.length(); count++)
	{
		if (theMap.find(firstString[count]) == theMap.end()) //If character not found in HashMap.
		{
			theMap.insert(std::make_pair<char, int>((char)firstString[count], 0));
		}
	}

	for (int count = 0; count < secondString.length(); count++)
	{
		std::unordered_map<char, int>::iterator searchResults = theMap.find(secondString[count]);

		if (searchResults != theMap.end()) //If character already exists in the HashMap.
		{
			++searchResults->second;
		}
	}


	for (auto count = theMap.begin(); count != theMap.end(); count++)
	{
		if (count->second > 0)
		{
			std::cout << "Letter: " << count->first << "\tFrequency: " << count->second << std::endl;
		}
	}

	return 0;
}