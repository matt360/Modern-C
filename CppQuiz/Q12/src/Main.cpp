// Created by Mateusz Zaremba

#include <iostream>
#include <string>



int main() 
{
	static int a;
	std::cout << a;
	
	// output:
	// 0

	std::cin.get();
}