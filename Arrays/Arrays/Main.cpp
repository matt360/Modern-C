// Arrays
/*
An array is a colleciton of elements, a bunch of things in a particular order.
In C++ an array is a way to represent a collection of variables.
A bunch of variables, usually of the same type, in a row.

The reason why it's so important is that many times we will want to represent a whole collection of data, 
and it just doesn't make sense to create a whole bunch of variables that really should be grouped together in one data set.

Variables need to be created manually, we need to actually go to the code, specify varaibles and give them names.
Where sometimes we want to be able to store 50 integers, that represent some sort of data. We don't want to go int 1, int 2 ect.
This is unreasonable.

An array is like having multiple variables in a single variable. We give an array a single name a through that we can refere to 
as many variables as we created the array with.

*/


// CODE

#include <iostream>
#include <array>

// stack array
/*
class Entity
{
public:
	int example[5];
	int count = sizeof(example) / sizeof(int); // this will give you 5

	Entity()
	{
		for (int i = 0; i < 5; i++)
			example[i] = 2;
	}
};
*/

class Entity
{
public:
	static constexpr int exampleSize = 5;
	int example[exampleSize];

	std::array<int, 5> another

	Entity()
	{
		for (int i = 0; i < exampleSize; i++)
			example[i] = 2;

		for (int i = 0; i < another.size(); i++)
			example[i] = 2;
	}
};

// heap array
class Entity
{
public:
	int* example = new int[5];
	//          sizeof(int*) / sizeof(int)     // this will give you 0      
	// int count = sizeof(example) / sizeof(int); // this doesn't work with heap allocated arrays

	Entity()
	{
		for (int i = 0; i < 5; i++)
			example[i] = 2;
	}
};

int main()
{

	int example[5]; // the lifetime of this array created on the stack is until the end of scope, in this case the end of the main function
	int* ptr = example;

	for (int i = 0; i < 5; i++)
		example[i] = 2;

	/*
	example[0] = 2;
	example[4] = 4;
	*/

	int a = example[0];

	// accessing element number 2 and setting it to 5 will result in us basically writing to an offset of 8 bytes from pointer. ->
	example[2] = 5; 
	// -> this is equivalent to:
	*(ptr + 2) = 6; // pointer arithmetic - adding 2 is adding 8 bytes because the number of bytes depends on the pointer type (integer) 
	// if I want to deal with bytes I'd have to cast the pointer to 'char' and then add 8 bytes and because we're assigning and integer
	// I'd have to cast it back to an integer pointer and then derefference it to get my integer so I can set it to '6';
	*(int*)((char*)ptr + 8) = 6;

	// this will print out the integer at the 0 place in the array
	std::cout << example[2] << std::endl;
	// this will print out the memory address of the array
	std::cout << example << std::endl;

	// Arrays on the heap
	int* another = new int[5]; // the lifetime of this array created on the heap is until the end of the programme or until we delete it
	delete[] another;

	std::cin.get();
}