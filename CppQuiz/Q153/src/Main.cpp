// Created by Mateusz Zaremba

#include <iostream>
#include <string>



int main() 
{
	// illegal - source https://dev.krzaq.cc/post/stop-assigning-string-literals-to-char-star-already/
	char* str = "X";
	std::cout << str;

	// also illegal
	const int qux = 42;
	int* quux = &qux;

	std::cin.get();
}