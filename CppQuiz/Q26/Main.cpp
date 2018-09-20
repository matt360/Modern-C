#include <iostream>
#include <string>
#include <vector>



int main()
{
	int i = 42;
	int j = 1;
	std::cout << i / --j; // undefined behaviour - j is decreased before the division, resulting in division by zero
	std::cout << i / j--; // okay - j is decreased after the division

	std::cin.get();
}