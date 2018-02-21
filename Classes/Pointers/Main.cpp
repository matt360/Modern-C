/*
A pointer is an iteger, a number, which stores a memory address.

A pointer is just an address.
It is an integer that holds a memory address.

(Types are just some kind of fiction, that we've created to make our lives easier)
A pointer, for all types, is just an integer that holds that memory address.
That's all that it is.
*/

// CODE

#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
	// typeless pointer - a pointer is just an integer in the memory so it doesn't need a type,
	// if we give a pointer a type we're just saying that the data at that address is presumed to be the type that we give it -
	// it doesn't mean anything apart from that. It's just something that we can write to make our lives easier syntatically,
	// in the actual source code, to make our lives easier, we can use types with pointers.
	// The type does not change what a pointer is. A pointer is just a memory address, it's just an integer.

	//int var = 8;
	//void* ptr = &var;
	//void* ptr = nullptr; // zero is not a valid memory address
	//double* ptr = (double*)&var;

	int var = 8;
	int* ptr = &var;
	*ptr = 10;
	LOG(var);
	/*
	types can be useful for manipulation of the memory, so if I want to read and write to the memory, types can help us out,
	because the compiler will now that the integer is 4 bytes, so when I try to set the value there, it will set 4 bytes of memory.
	*/

	std::cin.get();
}