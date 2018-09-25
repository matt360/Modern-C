// Created by Mateusz Zaremba

#include <iostream>
#include <string>

struct X
{
	X() { std::cout << "a"; }

	X(const X& x) { std::cout << "b"; }

	const X& operator=(const X& x)
	{
		std::cout << "c";
		return *this;
	}
};

int main() 
{
	X x;
	X y(x);
	X z = y;
	z = x;

	// output:
	// abbc

	/*
	The first line in main(), X x; is straightforward, it calls the default constructor.

	The next two lines is the heart of the question: The difference between X y(x) and X z = y is not that the first calls the copy constructor, and the second calls the copy assignment operator. The difference is that the first is direct initialization ([dcl.init]�11.6�16 in the standard) and the second is copy initialization ([dcl.init]�11.6�15).

	[dcl.init]�11.6�17 says: "If the initialization is direct-initialization, or if it is copy-initialization where the (...) source type is the same class as (...) the class of the destination, constructors are considered." So both our cases use the copy constructor.

	Not until z = x; do we have an actual assignment that uses the assignment operator.

	See http://stackoverflow.com/questions/1051379/is-there-a-difference-in-c-between-copy-initialization-and-direct-initializati/1051468#1051468 for a more detailed discussion of direct vs. copy initialization.
	*/

	std::cin.get();
}