// Created by Mateusz Zaremba

#include <iostream>
#include <string>
#include <limits>


int main() 
{
	int i = std::numeric_limits<int>::max();
	std::cout << ++i;

	std::cin.get();

}