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
	std::cout << "continue" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			continue;
		std::cout << "Hello World!" << std::endl;
		std::cout << i << std::endl;
	}

	std::cout << "======================" << std::endl;

	std::cout << "continue" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (i > 2) // will stop incrementing 'i' when 'i' is bigger than 2 so it's going to print out 0, 1, 2 (if (2 > 2) is false)
			continue;
		std::cout << "Hello World!" << std::endl;
		std::cout << i << std::endl;
	}

	std::cout << "======================" << std::endl;

	// break
	std::cout << "break" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if ((i + 1) % 2 == 0) //
			break;
		std::cout << "Hello World!" << std::endl;
		std::cout << i << std::endl;
	}

	std::cout << "======================" << std::endl;

	// return
	std::cout << "return" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if ((i + 1) % 2 == 0) //
			return 0;
		std::cout << "Hello World!" << std::endl;
		std::cout << i << std::endl;
	}

	std::cin.get();
}