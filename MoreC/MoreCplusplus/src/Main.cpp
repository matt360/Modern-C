#include <iostream>

int main()
{
	// infinite loop, i will reach zero and then rool back to 4294967295 and then conitinue to do so infinitely
	unsigned int i;
	for (i = 9; i >= 0; --i)
	{
		std::cout << "text" << std::endl;
	}

	// "text" will be printed 10 times
	int i;
	for (i = 9; i >= 0; --i)
	{
		std::cout << "text" << std::endl;
	}

	std::cin.get();
}