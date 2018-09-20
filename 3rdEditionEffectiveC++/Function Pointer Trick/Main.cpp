#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

// A normal function with an int parameter 
// and void return type 
void fun(int a)
{
	printf("Value of a is %d\n", a);
}

int main()
{
	// fun_ptr is a pointer to function fun()  
	void(*fun_ptr)(int) = &fun;

	/* The above line is equivalent of following two
	   void (*fun_ptr)(int);
	   fun_ptr = &fun;
	*/

	// Invoking fun() using fun_ptr 
	(*fun_ptr)(10);

	if (*fun_ptr == **fun_ptr)
	{
		std::cout << "bruh" << std::endl;
	}

	std::cin.get();
}
