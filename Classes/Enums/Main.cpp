/*
ENUMS

enum - short for enumeration; it's a set of values.
All that enum is, is a way to give a name to a value, so interad of having a bunch of intergers called A, B, C, we can have an enum which has the values A, B, C which corespond to integers.
Helps define a set of values: insted of having an integer as a type, you limit which values can be assignet to what.

At the end of a day an enum is just an integer.
*/


#include <iostream>

// you can specify what type of integer you want it to be by going, e.g.: enum Name : unsigned char
enum Example : unsigned char
{
	A, B, C
	// if you start A with 5, B will be equal to 6 and C will be equal to 7
	// A = 5, B, C
};

int a = 0;
int b = 1;
int c = 2;

int main()
{
	/* Will pop an error because Example enum must be 0, 1 or 2.
	Example value = 5;
	*/

	if (value == B)
	{
		// Do something
	}

	std::cin.get();
}