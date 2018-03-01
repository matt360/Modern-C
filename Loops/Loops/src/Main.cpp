#include <iostream>

int main()
{
	// for loop
	int i = 0;
	bool condition = true;
	for (; condition; )
	{
		std::cout << "Hello World!" << std::endl;
		i++;
		if (!(i < 5))
			condition = false;
	}

	std::cout << "======================" << std::endl;

	// while loop
	i = 0;
	while (i < 5)
	{
		std::cout << "Hello World!" << std::endl;
		i++;
	}

	std::cout << "======================" << std::endl;

	// do while
	condition = false;

	// will execute at least once
	do
	{
		std::cout << "Hello World!" << std::endl;
	} while (condition);

	std::cout << "======================" << std::endl;

	// while loop will not execute at all
	while (condition)
	{
		std::cout << "Hello World!" << std::endl;
	}
		
	std::cin.get();
}