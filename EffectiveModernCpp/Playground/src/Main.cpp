// Created by Mateusz Zaremba

#include <iostream>
#include <string>

class I
{
public:

	const int bar()
	{
		int i = j + 1;
		return i;
	}
	const int& foo(const int& i)
	{
		const int k = bar();
		return j + 1;
	}

	int j = 0;
};

struct C
{
	C& operator++(); // prefix
	const C operator++(int); // postfix

private: 
	int i;
};

int main() 
{
	I ii;
	int i = ii.foo(1);
	int j = 0;
	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++j;
	std::cout << j << std::endl;

	std::cin.get();
}