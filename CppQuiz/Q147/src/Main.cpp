// Created by Mateusz Zaremba

#include <iostream>
#include <string>



int main() 
{
	int x = 0; //What is wrong here??/
	x = 1;
	std::cout << x;

	// output:
	// 1

	/*
	??/ is a trigraph which doesn't exist anymore in C++17, and as it is in a comment, it is ignored (as anything else).
	So the output is 1.
	*/

	std::cin.get();
}