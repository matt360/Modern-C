// Created by Mateusz Zaremba

#include <iostream>
#include <string>



int main() 
{
	for (int i = 0; i < 3; i++)
		std::cout << i;
	for (int i = 0; i < 3; ++i)
		std::cout << i;

	std::cin.get();
}