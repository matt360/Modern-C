/*
A variable declared inline has the same semantics as a function declared inline: 
it can be defined, identically, in multiple translation units, must be defined in every translation unit in which it is used, 
and the behavior of the program is as if there was exactly one variable.
*/

#include <iostream>

struct MyStruct
{
	// C++ 17
	inline static const int x = 77;
};

struct MySuperStruct
{
	inline static const int x = 88;
};

int main()
{
	std::cout << "MyStruct: " << MyStruct::x << std::endl;
	std::cout << "MySuperStruct: " << MySuperStruct::x << std::endl;

	std::cin.get();
}