// Created by Mateusz Zaremba

#include <iostream>
#include <string>

typedef const T* Tcptr;
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

int main() 
{
	I ii;
	int i = ii.foo(1);

	std::cin.get();
}