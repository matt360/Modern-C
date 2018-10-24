#include <iostream>

std::size_t numDigits(int number)
{
	std::size_t digitsSoFar = 1;

	while ((number /= 10) != 0) ++digitsSoFar;
	return digitsSoFar;
}

unsigned GetNumberOfDigits(unsigned i)
{
	if (i > 0)
	{
		return (int)log10((double)i) + 1;
	}
	else
	{
		return 1;
	}
}

int main()
{
	std::size_t x = numDigits(123123);

	std::cout << x;

	std::cin.get();
}

