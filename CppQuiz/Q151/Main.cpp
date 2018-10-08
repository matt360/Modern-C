#include <iostream>
#include <type_traits>

int main()
{
	std::cout << std::is_signed<char>::value;

	std::cin.get();

	// The program is unspecified/implementation defined

	/*
	[basic.fundamental]§6.9.1¶1

    It is implementation-defined whether a char object can hold negative values.
	*/
}

