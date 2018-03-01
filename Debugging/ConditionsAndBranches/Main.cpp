// Conditions and Branches

// A lot of if statements will slow down our code. A well optimized code tries to avoid them.
// == is an overloaded operator to take, e.g. two integers and compare them, which means take their places in memory
// and compare those places bite by bite to see if their the same.

#include <iostream>

int main()
{
	int x = 5;
	// save the result of comparison in 'comparison result'
	// if x is equal to 5 set 'comparisonResult' to true, else set it to false.
	// if statemnet check if the value is 0, if it's not 0, then execute the code below it
	bool comparisonResult = x == 5;
	if (comparisonResult)
	{
		std::cout << "comparsionResult" << std::endl;
	}

	const char* ptr = "Hello";

	if (ptr)
		std::cout << ptr << std::endl;
	// 'else if' is going to be executed only if the first 'if' statement fails
	else if (ptr == "Hello")
		std::cout << ptr << std::endl;
	else
		std::cout << "ptr is NULL" << std::endl;
	// what 'else if' actually is
	if (ptr)
		std::cout << ptr << std::endl;
	// 'else if' is going to be executed only if the first 'if' statement fails
	else
	{
		if (ptr == "Hello")
			std::cout << ptr << std::endl;
	}

	if (ptr)
		std::cout << ptr << std::endl;
	// 'if' after another 'if' is always going to be executed
	if (ptr == "Hello")
		std::cout << ptr << std::endl;
	else
		std::cout << "ptr is NULL" << std::endl;

	std::cin.get();
}