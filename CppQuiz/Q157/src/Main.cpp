// Created by Mateusz Zaremba

#include <iostream>
#include <string>

struct A {};

int main() 
{
	{
		std::cout << (&typeid(A) == &typeid(A));
	}

	std::cin.get();
}