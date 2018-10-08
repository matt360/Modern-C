#include <iostream>
#include <typeinfo>

void takes_pointer(int* pointer) {
	if (typeid(pointer) == typeid(int[])) std::cout << 'a';
	if (typeid(pointer) == typeid(int*)) std::cout << 'p';
}

void takes_array(int array[]) {
	if (typeid(array) == typeid(int[])) std::cout << 'a';
	if (typeid(array) == typeid(int*)) std::cout << 'p';
}

int main()
{
	int* pointer = nullptr;
	int array[1];

	takes_pointer(array);
	takes_array(pointer);
	
	std::cout << (typeid(int*) == typeid(int[]));

	std::cin.get();

	// output:
	// pp0

	/*
	Functions taking pointers can also be called with arrays, and vice versa. So are arrays and pointers the same? No.

	If they aren't the same, why can both functions be called with both arguments?

	First let's look at takes_pointer(array);. What happens here is usually referred to as the array "decaying" to a pointer. To be a bit more precise, let's have a look at [conv.array]�7.2 in the C++ standard:

	"An lvalue or rvalue of type �array of N T� or �array of unknown bound of T� can be converted to a prvalue of type �pointer to T�."

	array is of type "array of 1 int", which converts to a prvalue (temporary) of type "pointer to int".

	So what happens with takes_array(pointer);, does the pointer convert to an array? No, it's actually the other way around. Let's look at [dcl.fct]�11.3.5�5 about function parameters:

	"After determining the type of each parameter, any parameter of type �array of T� (...) is adjusted to be �pointer to T�".

	So in void takes_array(int array[]), the type of array is adjusted to be pointer to int.
	*/
}
