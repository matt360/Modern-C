// Created by Mateusz Zaremba

#include <iostream>
#include <string>

int foo()
{
	return 10;
}

struct foobar
{
	static int x;
	static int foo()
	{
		return 11;
	}
};

int foobar::x = foo();

int main() 
{
	std::cout << foobar::x;

	std::cin.get();
}