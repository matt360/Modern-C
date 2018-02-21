// Strings

/*
A string is a group a characters. By characters I mean: letters, numbers, symbols ect. it's basically text.

A string is an array of characters (char). An array being a set of elements, so we have a set of characters, which make up
a string of text.

std::string - template specialization of a basic string class with char as a template parameter

string literal - a series of characters inbetween two double qoutes ("text")
*/


// CODE

#include <iostream>
#include <string>

// read only funciton - pass by const reference; reference - won't get copied; const - no changes to the string will be made
void PrintString(const std::string& string)
{
	std::cout << string << std::endl;
}

int main()
{
	// string's can't be modified. To create a new string you have to delete the old one and create a new one.
	// The rule of thumb is: if you don't use the 'new' keyword, don't use 'delete' keyword
	//char* name = "Charno";
	const char* name = "Charno"; // double quotes (" ") makes it a const char pointer (const char*)
	const char name2[7] = { 'C', 'h', 'a', 'r', 'n', 'o', 0 }; // characters are defined by single quotes
	// same as above
	// const char name2[7] = { 'C', 'h', 'a', 'r', 'n', 'o', '\0' }; // characters are defined by single quotes

	std::cout << name2 << std::endl;

	// expanding strings
	std::string name3 = "Charno";
	name3 += " hello!";
	std::cout << name3 << std::endl;
	// same as above
	std::string name4 = std::string("Charno") + " hello!";
	std::cout << name4 << std::endl;

	// look in the string
	//                    find returns a position of the searched string
	bool contains = name4.find("no") != std::string::npos; // npos - illegal position
	std::cout << contains << std::endl;

	PrintString(name4);

	const char* s = "";
	strlen(s);
	name3.size();

	// String literals 


	std::cin.get();
}