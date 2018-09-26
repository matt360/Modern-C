// Created by Mateusz Zaremba

#include <iostream>
#include <string>

void f(int& a, const int& b)
{
	std::cout << b;
	a = 1;
	std::cout << b;
}

int main() 
{
	int x = 0;
	f(x, x);

	// output:
	// 01

	/*
	Both a and b refer to the same variable x.

	The fact that b is a const reference does not guarantee that b isn't modified from elsewhere, only that we can't modify it.
	*/

	std::cin.get();
}