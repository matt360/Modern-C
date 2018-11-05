#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

/*
	source: http://www.techiedelight.com/remove-whitespaces-string-cpp/
	1. space ' '
	2. line feed '\n'
	3. carriage return '\r'
	4. horizontal tab '\t'
	5. form feed '\f'
	6. vertical tab '\v'

	The standard solution is to use std::remove_if algorithm to remove whitespace characters from std::string using Erase-remove idiom technique.
	Since std::remove_if algorithm does not actually remove chracters from the string but move all non-whitespace characters to the front 
	and returs an iterator pointing to where the end should be. The whitespace characters can be then deleted with a call to std::erase.

	std::remove_if expects a predicate which determines which characters to remove from the string. 
	There are many ways to specify the predicate that removes whitespace characters.

*/

struct isSpace
{
	bool operator()(unsigned c)
	{
		return (c == ' ' ||
			c == '\t'|| c== '\n');
	}
};
// remove a specific white-space from a string using operator overloading
//input.erase(std::remove_if(input.begin(), input.end(), isSpace()), input.end());

int main()
{
	std::string input = R"(Ro;

m"	a' 'n)";

	//for (auto& i : input)
	//{
	//	if (i == '\'')
	//	{
	//		input.erase(std::remove(input.begin(), input.end(), '\''), input.end());
	//	}
	//	else if (i == '\"')
	//	{
	//		input.erase(std::remove(input.begin(), input.end(), '\"'), input.end());
	//	}
	//	else if (i == ';')
	//	{
	//		input.erase(std::remove(input.begin(), input.end(), ';'), input.end());
	//	}
	//}
	
	// remove all white-spaces from a string
	input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
	// remove all punctuation sign from a string
	input.erase(std::remove_if(input.begin(), input.end(), ::ispunct), input.end());

	// remove a specific white-space from a string using a lambda expression
	input.erase(
		std::remove_if(
			input.begin(), 
			input.end(),
			[](char c) 
			{
				return (c == ' ');
			}),
		input.end());

	// remove more than one specific white-space from a string using a lambda expression
	/*input.erase(
		std::remove_if(
			input.begin(), 
			input.end(),
			[](char c) 
			{
				return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f');
			}),
		input.end());*/

	// remove all white-spaces from a string using regualr expression
	/*std::regex r("\\s+");
	input = std::regex_replace(input, r, "");*/

	std::cout << input << std::endl;

	std::cin.get();
}



