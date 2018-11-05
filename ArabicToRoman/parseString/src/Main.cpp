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

	// if found "Ro" in the input strin
	if (size_t found_position = input.find("Ro"); found_position != std::string::npos)
	{
		// do something...
	}

	input.replace(input.find("Ro"), sizeof("Ro"), "Co");

	//// get characters into name
	//std::string name;
	//std::cout << "Please, enter your full name: ";
	//std::getline(std::cin, name);
	//std::cout << "Hello, " << name << "!\n";

	//// remove all semicolons
	//input.erase(std::remove(input.begin(), input.end(), ';'), input.end());
	//// remove all double quotes
	//input.erase(std::remove(input.begin(), input.end(), '\"'), input.end());
	//// remove all single quotes
	//input.erase(std::remove(input.begin(), input.end(), '\''), input.end());
	
	//// remove all white-spaces from a string
	//input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
	//// remove all punctuation sign from a string
	//input.erase(std::remove_if(input.begin(), input.end(), ::ispunct), input.end());

	//// remove a specific white-space from a string using a lambda expression
	//input.erase(
	//	std::remove_if(
	//		input.begin(), 
	//		input.end(),
	//		[](char c) 
	//		{
	//			return (c == ' ');
	//		}),
	//	input.end());

	// remove more than one specific white-space from a string using a lambda expression
	//input.erase(
	//	std::remove_if(
	//		input.begin(), 
	//		input.end(),
	//		[](char c) 
	//		{
	//			return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f');
	//		}),
	//	input.end());

	// remove all white-spaces from a string using regualr expression
	//std::regex r("\\s+");
	//input = std::regex_replace(input, r, "");

	std::cout << input << std::endl;

	std::string str;
	std::string str2 = R"(Writing )";
	std::string str3 = R"(print 10 and then 5 more)";

	// used in the same order as described above:
	str.append(str2);                       // "Writing "
	str.append(str3, 6, 3);                   // "10 "
	str.append("dots are cool", 5);          // "dots "
	str.append("here: ");                   // "here: "
	str.append(10u, '.');                    // ".........."
	str.append(str3.begin() + 8, str3.end());  // " and then 5 more"
	str.insert(2, "BOOM");
	////str.append<int>(5, 0x2E);                // "....."

	std::cout << str << '\n';

	std::cin.get();
}

// Don't use
// if you want to catch a character and replace it with another character
// or insert multiple signs into a string
//for (auto& i : input)
//{
//	if (i == '\'')
//	{
//		input.replace(i, sizeof(i), "firstSQ");
//	}
//	else if (i == '\"')
//	{
//	}
//	else if (i == ';')
//	{
//	}
//}

