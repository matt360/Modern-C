// Variables

// Int - integer - 4 bytes (Ultimatelly it's the compilers choice to tell you how big an integer is going to be)
// 1 byte - 8 bits of data
// 4 bytes - 32 bits of data

// int (signed) - 1 bit is for the sign, to know if the varaible is positive or negative. That leaves 31 bits for the number.
// Each bit can be eitehr 0 or 1. 2^31 = 2,147,483,648. 
// The maximum number we can store is 2,147,483,647 (minumum being -2,147,483,647) becasue we need to be able to store 0.

// unsigned int - now we have 32 bits to store the number which gives us - 2^32 = 4,294,967,296, 
// so the maximum number we can store is 4,294,967,295 (we need to be able to store 0)

// char - 1 byte of data (8 bits)
// short - 2 bytes of data (16 bits)
// int - 4 bytes of data (32 bits)
// long - 4 bytes of data (usually, depending on the compiler) (32 bits)
// long long - 8 bytes of data (64 bits)
// float - 4 bytes (32 bits)
// double - 8 bytes (64 bits)
// bool - 1 byte of memory (8 bits) - true or false - 0 means false, any other number means true. It does take up only 1 bit of memory but when we are addressing memory
// (we need to retrieve our bool from memory) we can only address bytes; we can't address a single bit.

//CODE

#include <iostream>

int main()
{
	int variable = 8; // -2b -> 2b

	float a = 5.5f;
	float b = 5.5; // that's a double

	std::cout << sizeof(bool) << std::endl;
	
	std::cin.get();
}