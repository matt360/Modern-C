/*
Refernces are just pointers in disguise.
It's just syntax sugar on top of poitners to make it a little bit easier to read and a little bit easier to follow.

A reference is essentaily exactly what it sounds like - it's a way for us to reference an exisitng variable.

Unlike a pointer, where you could create a new pointer variable and then set it equal to nullptr or 0 or NULL,
you can't do this with references.

References are not new variables, they have to reference an already existing variable.

References don't reallt occupy memory, they don't really have storage, like a typicall variable, becasue what they are, 
instead is a reference to a variable.

If you can use a reference instead of a poitner do it.
*/


// CODE
#include <iostream>

#define LOG(x) std::cout << x << std::endl

//void Increment(int* value)
//{
//	// this vould increment the pointer first and then dereference
//	//*value++;
//
//	// dereference first and then increment the value
//	(*value)++;
//}

void Increment(int& value)
{
	// this vould increment the pointer first and then dereference
	//*value++;

	// dereference first and then increment the value
	value++;
}

int main()
{
	int a = 5;
	int& ref = a; // reference (alias)
	ref = 2; // we can use 'ref' as if it was 'a'

	Increment(a);

	LOG(a);

	std::cin.get();
}