// Control Flow Statements: continue, break, return

/*
continue can only be used inside a loop and it says go to the next interation of this loop, otherwise it will just end the loop

break - primarly used in loops however also	in switch statements - get out of the loop

return - will get out of the function entirely
*/

#include <iostream>

int main()
{
	// for loop
	int i = 0;
	bool condition = true;

	// continue
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			continue;
		std::cout << "Hello World!" << std::endl;
		std::cout << i << std::endl;
	}

	std::cout << "======================" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		if (i > 2) // will stop incrementing 'i' when 'i' is bigger than 2 so it's going to print out 0, 1, 2 (if (2 > 2) is false)
			continue;
		std::cout << "Hello World!" << std::endl;
		std::cout << i << std::endl;
	}

	std::cout << "======================" << std::endl;

	// break
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			continue;
		std::cout << "Hello World!" << std::endl;
		std::cout << i << std::endl;
	}

	std::cout << "======================" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		if (i > 2) // will stop incrementing 'i' when 'i' is bigger than 2 so it's going to print out 0, 1, 2 (if (2 > 2) is false)
			continue;
		std::cout << "Hello World!" << std::endl;
		std::cout << i << std::endl;
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