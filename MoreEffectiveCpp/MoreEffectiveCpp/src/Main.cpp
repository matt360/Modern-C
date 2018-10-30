// Created by Mateusz Zaremba

#include <iostream>
#include <string>

struct C
{
	C& operator++(); // prefix
	C& operator++(int); // postfix


	int i = 0;
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

int main() 
{
	C c;
	c++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++;

	std::cout << c.i;

	std::cin.get();
}