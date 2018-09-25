// Created by Mateusz Zaremba

#include <iostream>
#include <string>



int main() 
{
	unsigned int i = std::numeric_limits<unsigned int>::max();
	std::cout << ++i;

	// output:
	// 0

	/*
	Unsigned integers have well defined behaviour when they overflow. 
	When you go one above the largest representable unsigned int, you end up back at zero.

	According to [basic.fundamental]�6.9.1�4 in the C++ standard: 
	"Unsigned integers, declared unsigned, 
	shall obey the laws of arithmetic modulo 2^n where n is the number of bits in the value representation of that particular size of integer."
	*/

	std::cin.get();
}