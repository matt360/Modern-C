// Created by Mateusz Zaremba

#include <iostream>
#include <string>

struct C
{
	C() {}
	C(int I = 0) : i(I) {}

	C& operator++(); // prefix
	C& operator++(int); // postfix
	//C const operator++(int); // postfix - use return value and const to prevent i++++ etc.


	int i;
};

C& C::operator++()
{
	this->i = this->i + 1;
	return *this;
}

C& C::operator++(int)
{
	this->i = this->i + 1;
	return *this;
}

C c(0);
int j = 0;

int main() 
{
	j++;
	std::cout << j;

	c++++;
	std::cout << c.i;

	std::cin.get();
}